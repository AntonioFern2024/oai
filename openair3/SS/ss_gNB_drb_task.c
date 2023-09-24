/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
*/

#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <netinet/sctp.h>

#include "assertions.h"
#include "common/utils/system.h"
#include "queue.h"
#include "sctp_common.h"

#include "intertask_interface.h"
#include "common/ran_context.h"

#include "acpNrDrb.h"
#include "ss_gNB_context.h"
#include "ss_gNB_vt_timer_task.h"
#include "ss_utils.h"

extern RAN_CONTEXT_t RC;
extern SSConfigContext_t SS_context;
static acpCtx_t ctx_drb_g = NULL;

static unsigned char *buffer = NULL;
static const size_t size = 16 * 1024;
static instance_t instance_g = 0;

static nr_drb_data_t _drb_data_type = DRB_data_type_qty;

enum MsgUserId
{
    // user defined IDs should be an int number >= 1
    MSG_NrDrbProcessFromSS_userId = 1,
    MSG_NrDrbProcessToSS_userId,
};

static void ss_send_drb_data(ss_drb_pdu_ind_t *pdu_ind)
{
    struct NR_DRB_COMMON_IND ind = {};

    LOG_A(GNB_APP, "[SS_DRB] Reported drb sdu_size:%d \t drb_id %d\n", pdu_ind->sdu_size, pdu_ind->drb_id);
    LOG_E(GNB_APP, "[SS_DRB] ss_send_drb_data ss_send_drb_data\n");
    for (uint32_t i = 0; i < pdu_ind->sdu_size; ++i) printf("%02x", pdu_ind->sdu[i]); printf("\n");

    DevAssert(pdu_ind != NULL);
    DevAssert(pdu_ind->sdu_size >= 0);
    DevAssert(pdu_ind->drb_id >= 0);

    memset(&ind, 0, sizeof(ind));

    /* ind.Common.CellId = SS_context.nr_cellId; */
    //TODO: Work Around till Sys port is implemented for 5G
    ind.Common.CellId = nr_Cell1;

    // Populated the Routing Info
    if(_drb_data_type == DRB_SdapSdu){
        ind.Common.RoutingInfo.d = NR_RoutingInfo_Type_QosFlow;
        ind.Common.RoutingInfo.v.QosFlow.PDU_SessionId = pdu_ind->pdu_sessionId;
        ind.Common.RoutingInfo.v.QosFlow.QFI = pdu_ind->qfi;
    } else {
        ind.Common.RoutingInfo.d = NR_RoutingInfo_Type_RadioBearerId;
        ind.Common.RoutingInfo.v.RadioBearerId.d = NR_RadioBearerId_Type_Drb;
        ind.Common.RoutingInfo.v.RadioBearerId.v.Drb = pdu_ind->drb_id;
    }

    // Populated the Timing Info
    ind.Common.TimingInfo.d = TimingInfo_Type_SubFrame;
    ind.Common.TimingInfo.v.SubFrame.SFN.d = SystemFrameNumberInfo_Type_Number;
    ind.Common.TimingInfo.v.SubFrame.SFN.v.Number = pdu_ind->frame;

    ind.Common.TimingInfo.v.SubFrame.Subframe.d = SubFrameInfo_Type_Number;
    ind.Common.TimingInfo.v.SubFrame.Subframe.v.Number = pdu_ind->subframe;

    ind.Common.TimingInfo.v.SubFrame.HSFN.d = SystemFrameNumberInfo_Type_Number;
    ind.Common.TimingInfo.v.SubFrame.HSFN.v.Number = 0;

    ind.Common.TimingInfo.v.SubFrame.Slot.d = SlotTimingInfo_Type_Any;
    ind.Common.TimingInfo.v.SubFrame.Slot.v.Any = true;

    ind.Common.Status.d = IndicationStatus_Type_Ok;
    ind.Common.Status.v.Ok = true;

    ind.Common.RlcBearerRouting.d = RlcBearerRouting_Type_NR;
    /* ind.Common.RlcBearerRouting.v.NR = SS_context.nr_cellId; */
    //TODO: Work Around till Sys port is implemented for 5G
    ind.Common.RlcBearerRouting.v.NR = nr_Cell1;

    switch(_drb_data_type) {
    case DRB_PdcpSdu:
    {
        if (pdu_ind->sdu_size < 4) break;
        LOG_A(GNB_APP, "[SS_DRB] PDCP SDU received in NR_DRB_COMMON_IND\n");
        // Populating the SDU
        ind.U_Plane.SlotData.NoOfTTIs = 1;
        ind.U_Plane.SlotData.PduSduList.d = NR_L2DataList_Type_PdcpSdu;
        ind.U_Plane.SlotData.PduSduList.v.PdcpSdu.d = 1;
        ind.U_Plane.SlotData.PduSduList.v.PdcpSdu.v = CALLOC(1, ind.U_Plane.SlotData.PduSduList.v.PdcpSdu.d * sizeof(NR_PDCP_SDU_Type));
        DevAssert(ind.U_Plane.SlotData.PduSduList.v.PdcpSdu.v != NULL);

        for (int i = 0; i < ind.U_Plane.SlotData.PduSduList.v.PdcpSdu.d; i++) {
            NR_PDCP_SDU_Type *pdcpSdu = &ind.U_Plane.SlotData.PduSduList.v.PdcpSdu.v[i];

            pdcpSdu->d = pdu_ind->sdu_size;
            pdcpSdu->v = CALLOC(1, pdcpSdu->d);
            DevAssert(pdcpSdu->v != NULL);
            memcpy(pdcpSdu->v, pdu_ind->sdu, pdcpSdu->d);
            printf("pdu_ind->sdu_size=%zu\n", pdu_ind->sdu_size);
            for (uint32_t i = 0; i < pdcpSdu->d; ++i) printf("%02x", pdcpSdu->v[i]); printf("\n");
        }
    }
    break;

    case DRB_RlcPdu:
    {
        LOG_A(GNB_APP, "[SS_DRB] RLC PDU received in NR_DRB_COMMON_IND\n");
        // Populating the PDU
        ind.U_Plane.SlotData.NoOfTTIs = 1;
        ind.U_Plane.SlotData.PduSduList.d = NR_L2DataList_Type_RlcPdu;
        ind.U_Plane.SlotData.PduSduList.v.RlcPdu.d = 1;
        ind.U_Plane.SlotData.PduSduList.v.RlcPdu.v = CALLOC(1, (ind.U_Plane.SlotData.PduSduList.v.RlcPdu.d) * (sizeof(struct NR_RLC_PDU_Type)));
        DevAssert(ind.U_Plane.SlotData.PduSduList.v.RlcPdu.v != NULL);
        for (int i = 0; i < ind.U_Plane.SlotData.PduSduList.v.RlcPdu.d; i++) {
            struct NR_RLC_PDU_Type* rlcPdu = &ind.U_Plane.SlotData.PduSduList.v.RlcPdu.v[i];

            rlcPdu->d = NR_RLC_PDU_Type_UMD;
            long *sn_FieldLength = NULL;
            NR_RLC_BearerConfig_t *rlcBearer = RC.NR_RB_Config[pdu_ind->physCellId][pdu_ind->drb_id+2].RlcBearer;
            if (rlcBearer && rlcBearer->rlc_Config && rlcBearer->rlc_Config->choice.um_Bi_Directional)
            {
                sn_FieldLength = rlcBearer->rlc_Config->choice.um_Bi_Directional->ul_UM_RLC.sn_FieldLength;
            }
            if ((pdu_ind->sdu[0] & 0xC0) == 0)
            {
                rlcPdu->v.UMD.d = NR_RLC_UMD_PDU_Type_NoSN;
            }
            else if (sn_FieldLength && *sn_FieldLength == SQN_NR_SN_FieldLengthUM_e_size6)
            {
                rlcPdu->v.UMD.d = NR_RLC_UMD_PDU_Type_SN6Bit;
            }
            else if (sn_FieldLength && *sn_FieldLength == SQN_NR_SN_FieldLengthUM_e_size12)
            {
                rlcPdu->v.UMD.d = NR_RLC_UMD_PDU_Type_SN12Bit;
            }

            if (rlcPdu->d == NR_RLC_PDU_Type_UMD && rlcPdu->v.UMD.d == NR_RLC_UMD_PDU_Type_NoSN)
            {
                struct NR_RLC_UMD_HeaderNoSN_Type *header = &rlcPdu->v.UMD.v.NoSN.Header;
                NR_RLC_UMD_Data_Type *data = &rlcPdu->v.UMD.v.NoSN.Data;
                int pdu_header_size = 1;
                bits_copy_to_array(header->SegmentationInfo, 0, pdu_ind->sdu, 2);
                bits_copy_to_array(header->Reserved, 2, pdu_ind->sdu, 6);
                data->d = pdu_ind->sdu_size - pdu_header_size;
                LOG_A(GNB_APP, "[SS_DRB] Length of RLC PDU received in NR_DRB_COMMON_IND: %d\n", pdu_ind->sdu_size);
                data->v = CALLOC(1, data->d);
                DevAssert(data->v != NULL);
                memcpy(data->v, pdu_ind->sdu + pdu_header_size, data->d);
            }
            else if (rlcPdu->d == NR_RLC_PDU_Type_UMD && rlcPdu->v.UMD.d == NR_RLC_UMD_PDU_Type_SN6Bit)
            {
                struct NR_RLC_UMD_HeaderSN6Bit_Type *header = &rlcPdu->v.UMD.v.SN6Bit.Header;
                NR_RLC_UMD_Data_Type *data = &rlcPdu->v.UMD.v.SN6Bit.Data;
                int pdu_header_size = 1;
                bits_copy_to_array(header->SegmentationInfo, 0, pdu_ind->sdu, 2);
                bits_copy_to_array(header->SequenceNumber, 2, pdu_ind->sdu, 6);
                if (pdu_ind->sdu[0] & 0x80)
                {
                    pdu_header_size += 2;
                    header->SegmentOffset.d = true;
                    bits_copy_to_array(header->SegmentOffset.v, 8, pdu_ind->sdu, 16);
                }
                data->d = pdu_ind->sdu_size - pdu_header_size;
                LOG_A(GNB_APP, "[SS_DRB] Length of RLC PDU received in NR_DRB_COMMON_IND: %d\n", pdu_ind->sdu_size);
                data->v = CALLOC(1, data->d);
                DevAssert(data->v != NULL);
                memcpy(data->v, pdu_ind->sdu + pdu_header_size, data->d);
            }
            else if (rlcPdu->d == NR_RLC_PDU_Type_UMD && rlcPdu->v.UMD.d == NR_RLC_UMD_PDU_Type_SN12Bit)
            {
                struct NR_RLC_UMD_HeaderSN12Bit_Type *header = &rlcPdu->v.UMD.v.SN12Bit.Header;
                NR_RLC_UMD_Data_Type *data = &rlcPdu->v.UMD.v.SN12Bit.Data;
                int pdu_header_size = 2;
                bits_copy_to_array(header->SegmentationInfo, 0, pdu_ind->sdu, 2);
                bits_copy_to_array(header->SequenceNumber, 4, pdu_ind->sdu, 12);
                if (pdu_ind->sdu[0] & 0x80)
                {
                    pdu_header_size += 2;
                    header->SegmentOffset.d = true;
                    bits_copy_to_array(header->SegmentOffset.v, 16, pdu_ind->sdu, 16);
                }
                data->d = pdu_ind->sdu_size - pdu_header_size;
                LOG_A(GNB_APP, "[SS_DRB] Length of RLC PDU received in NR_DRB_COMMON_IND: %lu\n", pdu_ind->sdu_size);
                data->v = CALLOC(1, data->d);
                DevAssert(data->v != NULL);
                memcpy(data->v, pdu_ind->sdu + pdu_header_size, data->d);
            }
            else
            {
                LOG_E(GNB_APP, "[SS_DRB] only UMD NoSN/SN6Bit/SN12Bit are handled in RLC PDU in NR_DRB_COMMON_IND\n");
            }
        }
    }
    break;

    case DRB_SdapSdu:
    {
        LOG_A(GNB_APP, "[SS_DRB] SDAP SDU received in NR_DRB_COMMON_IND\n");
        // Populating the SDU
        ind.U_Plane.SlotData.NoOfTTIs = 1;
        ind.U_Plane.SlotData.PduSduList.d = NR_L2DataList_Type_SdapSdu;
        ind.U_Plane.SlotData.PduSduList.v.SdapSdu.d = 1;
        ind.U_Plane.SlotData.PduSduList.v.SdapSdu.v = CALLOC(1, ind.U_Plane.SlotData.PduSduList.v.SdapSdu.d * sizeof(SDAP_SDU_Type));
        DevAssert(ind.U_Plane.SlotData.PduSduList.v.SdapSdu.v != NULL);

        for (int i = 0; i < ind.U_Plane.SlotData.PduSduList.v.SdapSdu.d; i++) {
            SDAP_SDU_Type *sdapSdu = &ind.U_Plane.SlotData.PduSduList.v.SdapSdu.v[i];
            sdapSdu->d = pdu_ind->sdu_size;
            sdapSdu->v = CALLOC(1, sdapSdu->d);
            DevAssert(sdapSdu->v != NULL);
            memcpy(sdapSdu->v, pdu_ind->sdu, sdapSdu->d);
        }
    }
    break;

    default:
        LOG_E(GNB_APP, "[SS_DRB] %s requested NR_L2DataList_Type %d that is not yet implemented\n", _drb_data_type);
    }
    // Encode Message
    size_t msgSize = size;
    if (acpNrDrbProcessToSSEncSrv(ctx_drb_g, buffer, &msgSize, &ind) != 0)
    {
        LOG_E(GNB_APP, "[SS_DRB] acpNrDrbProcessToSSEncSrv Failed\n");
        return;
    }
    LOG_A(GNB_APP, "[SS_DRB] NR_DRB_COMMON_IND buffer msgSize=%d to NRCell %d\n", (int)msgSize, SS_context.nr_cellId);

    printf("acpSendMsg: "); for (size_t i = 0; i < msgSize; i++) printf("%02x", (uint8_t)buffer[i]); printf("\n");

    // Send Message
    int send_res = acpSendMsg(ctx_drb_g, msgSize, buffer);
    if (send_res != 0)
    {
        LOG_E(GNB_APP, "[SS_DRB] NR_DRB_COMMON_IND acpSendMsg failed. Error : %d on fd: %d\n", send_res, acpGetSocketFd(ctx_drb_g));
    }
    else
    {
        LOG_A(GNB_APP, "[SS_DRB] NR_DRB_COMMON_IND acpSendMsg Success\n");
    }

    /* acpNrDrbProcessToSSFree0SrvClt(&ind); */
}

static void ss_task_handle_drb_pdu_req(struct NR_DRB_COMMON_REQ *req)
{
    assert(req);
    MessageDef *message_p = NULL;
    task_id_t task_id = TASK_RRC_GNB;

    /* Populate the message and send to gNB */
    for (int i = 0; i < req->U_Plane.SlotDataList.d; i++)
    {
        if (req->U_Plane.SlotDataList.v[i].PduSduList.d == NR_L2DataList_Type_RlcPdu)
        {
            LOG_A(GNB_APP, "[SS_DRB] RLC PDU Received in NR_DRB_COMMON_REQ\n");
            _drb_data_type = DRB_RlcPdu;
            RC.nr_drb_data_type = DRB_RlcPdu;

            for (int j = 0; j < req->U_Plane.SlotDataList.v[i].PduSduList.v.RlcPdu.d; j++)
            {
                struct NR_RLC_PDU_Type *rlcPdu = &req->U_Plane.SlotDataList.v[i].PduSduList.v.RlcPdu.v[j];
                message_p = itti_alloc_new_message(task_id, 0, SS_DRB_PDU_REQ);
                assert(message_p);
                memset(SS_DRB_PDU_REQ(message_p).sdu, 0, SDU_SIZE);
                SS_DRB_PDU_REQ(message_p).data_type = (uint8_t)DRB_RlcPdu;
                if (rlcPdu->d == NR_RLC_PDU_Type_UMD && rlcPdu->v.UMD.d == NR_RLC_UMD_PDU_Type_NoSN)
                {
                    struct NR_RLC_UMD_HeaderNoSN_Type *header = &rlcPdu->v.UMD.v.NoSN.Header;
                    NR_RLC_UMD_Data_Type *data = &rlcPdu->v.UMD.v.NoSN.Data;
                    int pdu_header_size = 1;
                    bits_copy_from_array(SS_DRB_PDU_REQ(message_p).sdu, 0, header->SegmentationInfo, 2);
                    bits_copy_from_array(SS_DRB_PDU_REQ(message_p).sdu, 2, header->Reserved, 6);
                    SS_DRB_PDU_REQ(message_p).sdu_size = pdu_header_size + data->d;
                    LOG_A(GNB_APP, "[SS_DRB] Length of RLC PDU received in NR_DRB_COMMON_REQ: %lu\n", pdu_header_size + data->d);
                    memcpy(SS_DRB_PDU_REQ(message_p).sdu + pdu_header_size, data->v, data->d);
                }
                else if (rlcPdu->d == NR_RLC_PDU_Type_UMD && rlcPdu->v.UMD.d == NR_RLC_UMD_PDU_Type_SN6Bit)
                {
                    struct NR_RLC_UMD_HeaderSN6Bit_Type *header = &rlcPdu->v.UMD.v.SN6Bit.Header;
                    NR_RLC_UMD_Data_Type *data = &rlcPdu->v.UMD.v.SN6Bit.Data;
                    int pdu_header_size = 1;
                    bits_copy_from_array(SS_DRB_PDU_REQ(message_p).sdu, 0, header->SegmentationInfo, 2);
                    bits_copy_from_array(SS_DRB_PDU_REQ(message_p).sdu, 2, header->SequenceNumber, 6);
                    SS_DRB_PDU_REQ(message_p).data_type = (uint8_t)DRB_RlcPdu;
                    if (header->SegmentOffset.d)
                    {
                        pdu_header_size += 2;
                        bits_copy_from_array(SS_DRB_PDU_REQ(message_p).sdu, 8, header->SegmentOffset.v, 16);
                        //we consider only RLC payload is there meaning that RLC packet is segmented
                        RC.nr_drb_data_type = DRB_RlcSdu;
                        SS_DRB_PDU_REQ(message_p).data_type = (uint8_t)DRB_RlcSdu;
                    }
                    SS_DRB_PDU_REQ(message_p).sdu_size = pdu_header_size + data->d;
                    LOG_A(GNB_APP, "[SS_DRB] Length of RLC PDU received in NR_DRB_COMMON_REQ (SN6Bit): %lu\n", pdu_header_size + data->d);
                    memcpy(SS_DRB_PDU_REQ(message_p).sdu + pdu_header_size, data->v, data->d);
                }
                else if (rlcPdu->d == NR_RLC_PDU_Type_UMD && rlcPdu->v.UMD.d == NR_RLC_UMD_PDU_Type_SN12Bit)
                {
                    struct NR_RLC_UMD_HeaderSN12Bit_Type *header = &rlcPdu->v.UMD.v.SN12Bit.Header;
                    NR_RLC_UMD_Data_Type *data = &rlcPdu->v.UMD.v.SN12Bit.Data;
                    int pdu_header_size = 2;
                    bits_copy_from_array(SS_DRB_PDU_REQ(message_p).sdu, 0, header->SegmentationInfo, 2);
                    bits_copy_from_array(SS_DRB_PDU_REQ(message_p).sdu, 4, header->SequenceNumber, 12);
                    if (header->SegmentOffset.d)
                    {
                        pdu_header_size += 2;
                        bits_copy_from_array(SS_DRB_PDU_REQ(message_p).sdu, 16, header->SegmentOffset.v, 16);
                        //we consider only RLC payload is there meaning that RLC packet is segmented
                        RC.nr_drb_data_type = DRB_RlcSdu;
                        SS_DRB_PDU_REQ(message_p).data_type = (uint8_t)DRB_RlcSdu;
                    }
                    SS_DRB_PDU_REQ(message_p).sdu_size = pdu_header_size + data->d;
                    LOG_A(GNB_APP, "[SS_DRB] Length of RLC PDU received in NR_DRB_COMMON_REQ: %lu\n", pdu_header_size + data->d);
                    memcpy(SS_DRB_PDU_REQ(message_p).sdu + pdu_header_size, data->v, data->d);
                }
                else
                {
                    LOG_E(GNB_APP, "[SS_DRB] only UMD NoSN/SN6Bit/SN12Bit are handled in RLC PDU in NR_DRB_COMMON_REQ\n");
                }
                SS_DRB_PDU_REQ(message_p).drb_id = req->Common.RoutingInfo.v.RadioBearerId.v.Drb;
                SS_DRB_PDU_REQ(message_p).rnti = SS_context.ss_rnti_g;

                if (!nr_vt_timer_push_msg(&req->Common.TimingInfo, req->U_Plane.SlotDataList.v[i].SlotOffset, task_id, instance_g, message_p))
                {
                    int send_res = itti_send_msg_to_task(task_id, instance_g, message_p);
                    if (send_res < 0)
                    {
                        LOG_E(GNB_APP, "[SS_DRB] Error in itti_send_msg_to_task\n");
                    }
                    LOG_A(GNB_APP, "[SS_DRB] Send res: %d\n", send_res);
                }
            }
        }
        else if (req->U_Plane.SlotDataList.v[i].PduSduList.d == NR_L2DataList_Type_PdcpSdu)
        {
            LOG_A(GNB_APP, "[SS_DRB] PDCP SDU Received in NR_DRB_COMMON_REQ\n");
            _drb_data_type = DRB_PdcpSdu;
            RC.nr_drb_data_type = DRB_PdcpSdu;

            for (int j = 0; j < req->U_Plane.SlotDataList.v[i].PduSduList.v.PdcpSdu.d; j++)
            {
                message_p = itti_alloc_new_message(task_id, 0, SS_DRB_PDU_REQ);
                assert(message_p);
                memset(SS_DRB_PDU_REQ(message_p).sdu, 0, SDU_SIZE);

                NR_PDCP_SDU_Type *pdcpSdu = &req->U_Plane.SlotDataList.v[i].PduSduList.v.PdcpSdu.v[j];
                SS_DRB_PDU_REQ(message_p).sdu_size = pdcpSdu->d;
                memcpy(SS_DRB_PDU_REQ(message_p).sdu, pdcpSdu->v, pdcpSdu->d);
                LOG_A(GNB_APP, "[SS_DRB] Length of PDCP SDU received in NR_DRB_COMMON_REQ: %lu, SDU:\n", pdcpSdu->d);

                SS_DRB_PDU_REQ(message_p).drb_id = req->Common.RoutingInfo.v.RadioBearerId.v.Drb;
                SS_DRB_PDU_REQ(message_p).rnti = SS_context.ss_rnti_g;
                SS_DRB_PDU_REQ(message_p).data_type = (uint8_t)DRB_PdcpSdu;

                if (!nr_vt_timer_push_msg(&req->Common.TimingInfo, req->U_Plane.SlotDataList.v[i].SlotOffset, task_id, instance_g, message_p))
                {
                    int send_res = itti_send_msg_to_task(task_id, instance_g, message_p);
                    if (send_res < 0)
                    {
                        LOG_E(GNB_APP, "[SS_DRB] Error in itti_send_msg_to_task\n");
                    }
                    LOG_A(GNB_APP, "[SS_DRB] Send res: %d\n", send_res);
                }
            }
        }
        else if (req->U_Plane.SlotDataList.v[i].PduSduList.d == NR_L2DataList_Type_SdapSdu)
        {
            LOG_A(GNB_APP, "[SS_DRB] Sdap SDU Received in NR_DRB_COMMON_REQ\n");
            _drb_data_type = DRB_SdapSdu;
            RC.nr_drb_data_type = DRB_SdapSdu;

            for (int j = 0; j < req->U_Plane.SlotDataList.v[i].PduSduList.v.SdapSdu.d; j++)
            {
                message_p = itti_alloc_new_message(task_id, 0, SS_DRB_PDU_REQ);
                assert(message_p);
                memset(SS_DRB_PDU_REQ(message_p).sdu, 0, SDU_SIZE);

                SDAP_SDU_Type *sdapSdu = &req->U_Plane.SlotDataList.v[i].PduSduList.v.SdapSdu.v[j];
                SS_DRB_PDU_REQ(message_p).sdu_size = sdapSdu->d;
                memcpy(SS_DRB_PDU_REQ(message_p).sdu, sdapSdu->v, sdapSdu->d);
                LOG_A(GNB_APP, "[SS_DRB] Length of SDAP SDU received in NR_DRB_COMMON_REQ: %lu\n", sdapSdu->d);

                SS_DRB_PDU_REQ(message_p).drb_id = 1; /* This parameter is not actually used in SDAP entity */
                SS_DRB_PDU_REQ(message_p).rnti = SS_context.ss_rnti_g;
                SS_DRB_PDU_REQ(message_p).data_type = (uint8_t)DRB_SdapSdu;
                if(req->Common.RoutingInfo.d == NR_RoutingInfo_Type_QosFlow){
                    SS_DRB_PDU_REQ(message_p).pdu_sessionId = req->Common.RoutingInfo.v.QosFlow.PDU_SessionId;
                    SS_DRB_PDU_REQ(message_p).qfi = req->Common.RoutingInfo.v.QosFlow.QFI;
                }

                if (!nr_vt_timer_push_msg(&req->Common.TimingInfo, req->U_Plane.SlotDataList.v[i].SlotOffset, task_id, instance_g, message_p))
                {
                    int send_res = itti_send_msg_to_task(task_id, instance_g, message_p);
                    if (send_res < 0)
                    {
                        LOG_E(GNB_APP, "[SS_DRB] Error in itti_send_msg_to_task\n");
                    }
                    LOG_A(GNB_APP, "[SS_DRB] Send res: %d\n", send_res);
                }
            }
        }
        else
        {
            LOG_E(GNB_APP, "[SS_DRB] NR_DRB_COMMON_REQ requested NR_L2DataList_Type %d that is not yet implemented\n", req->U_Plane.SlotDataList.v[i].PduSduList.d);
        }
    }
}

static void ss_gNB_read_from_drb_socket(acpCtx_t ctx)
{
    while (1)
    {
        size_t msgSize = size;
        int userId = acpRecvMsg(ctx, &msgSize, buffer);

        // Error handling
        if (userId < 0)
        {

            if (userId == -ACP_ERR_SERVICE_NOT_MAPPED)
            {
                // Message not mapped to user id,
                // this error should not appear on server side for the messages received from clients
            }
            else if (userId == -ACP_ERR_SIDL_FAILURE)
            {
                // Server returned service error,
                // this error should not appear on server side for the messages received from clients
                SidlStatus sidlStatus = -1;
                acpGetMsgSidlStatus(msgSize, buffer, &sidlStatus);
            }
            else if (userId == -ACP_PEER_DISCONNECTED)
            {
                LOG_A(GNB_APP, "[SS_DRB] Peer ordered shutdown\n");
            }
            else if (userId == -ACP_PEER_CONNECTED)
            {
                LOG_A(GNB_APP, "[SS_DRB] Peer connection established\n");
            }
            else
            {
                LOG_E(GNB_APP, "[SS_DRB] Invalid userId: %d\n", userId);
                break;
            }
        }

        if (userId == 0)
        {
            // No message (timeout on socket)
            break;
        }
        else if (MSG_NrDrbProcessFromSS_userId == userId)
        {
            struct NR_DRB_COMMON_REQ *req = NULL;
            LOG_A(GNB_APP, "[SS_DRB] NR_DRB_COMMON_REQ Received\n");

            if (acpNrDrbProcessFromSSDecSrv(ctx, buffer, msgSize, &req) != 0)
            {
                LOG_E(GNB_APP, "[SS_DRB] acpNrDrbProcessFromSSDecSrv Failed\n");
                break;
            }
            if (SS_context.State >= SS_STATE_CELL_ACTIVE)
            {
                LOG_A(GNB_APP, "[SS_DRB] NR_DRB_COMMON_REQ received in CELL_ACTIVE\n");
                ss_task_handle_drb_pdu_req(req);
            }
            else
            {
                LOG_W(GNB_APP, "[SS_DRB] NR_DRB_COMMON_REQ received in SS state %d \n", SS_context.State);
            }

            acpNrDrbProcessFromSSFreeSrv(req);

            break;
        }
        else if (MSG_NrDrbProcessToSS_userId == userId)
        {
            LOG_A(GNB_APP, "[SS_DRB] NR_DRB_COMMON_IND Received; ignoring\n");
            break;
        }
    }
}

void *ss_gNB_drb_process_itti_msg(void *notUsed)
{
    MessageDef *received_msg = NULL;
    int result = 0;

    itti_poll_msg(TASK_SS_DRB, &received_msg);

    /* Check if there is a packet to handle */
    if (received_msg != NULL)
    {
        switch (ITTI_MSG_ID(received_msg))
        {
            case SS_DRB_PDU_IND:
                {
                    task_id_t origin_task = ITTI_MSG_ORIGIN_ID(received_msg);

                    if (origin_task == TASK_SS_PORTMAN)
                    {
                        LOG_D(GNB_APP, "[SS_DRB] DUMMY WAKEUP recevied from PORTMAN state %d\n", SS_context.State);
                    }
                    else
                    {
                        LOG_A(GNB_APP, "[SS_DRB] Received SS_DRB_PDU_IND from PDCP\n");
                        if (SS_context.State >= SS_STATE_CELL_ACTIVE)
                        {
                            LOG_A(GNB_APP, "[SS_DRB] NR_DRB_COMMON_IND received in CELL_ACTIVE\n");
                            instance_g = ITTI_MSG_DESTINATION_INSTANCE(received_msg);
                            ss_send_drb_data(&received_msg->ittiMsg.ss_drb_pdu_ind);
                        }
                        else
                        {
                            LOG_W(GNB_APP, "[SS_DRB] NR_DRB_COMMON_IND received in SS state %d\n", SS_context.State);
                        }
                    }
                };
                break;

            case TERMINATE_MESSAGE:
                LOG_A(GNB_APP, "[SS_DRB] Received TERMINATE_MESSAGE\n");
                itti_exit_task();
                break;

            default:
                LOG_W(GNB_APP, "[SS_DRB] Received unhandled message %d:%s\n",
                        ITTI_MSG_ID(received_msg), ITTI_MSG_NAME(received_msg));
                break;
        }

        result = itti_free(ITTI_MSG_ORIGIN_ID(received_msg), received_msg);
        AssertFatal(result == EXIT_SUCCESS, "Failed to free memory (%d)!\n", result);
    }

    ss_gNB_read_from_drb_socket(ctx_drb_g);

    return NULL;
}

void ss_gNB_drb_init(void)
{
    LOG_A(GNB_APP, "[SS_DRB] Starting System Simulator DRB Thread\n");
    char* host = (char*)RC.ss.DrbHost;

    if (host == NULL) {
        host = (char*)RC.ss.hostIp;
    }

    // Port number
    int port = RC.ss.Drbport;
    const struct acpMsgTable msgTable[] = {
        {"NrDrbProcessFromSS", MSG_NrDrbProcessFromSS_userId},
        {"NrDrbProcessToSS", MSG_NrDrbProcessToSS_userId},
        // The last element should be NULL
        {NULL, 0}};

    // Arena size to decode received message
    const size_t aSize = 32 * 1024;

    // Start listening server and get ACP context,
    // after the connection is performed, we can use all services
    int ret = acpServerInitWithCtx(host, port, msgTable, aSize, &ctx_drb_g);
    if (ret < 0)
    {
        LOG_A(GNB_APP, "[SS_DRB] Connection failure err=%d\n", ret);
        return;
    }
    int fd1 = acpGetSocketFd(ctx_drb_g);
    LOG_A(GNB_APP, "[SS_DRB] Connection performed : %d\n", fd1);

    buffer = (unsigned char *)acpMalloc(size);
    assert(buffer);

    itti_subscribe_event_fd(TASK_SS_DRB, fd1);

    itti_mark_task_ready(TASK_SS_DRB);
}

void *ss_gNB_drb_task(void *arg)
{
    ss_gNB_drb_init();

    while (1)
    {
        (void)ss_gNB_drb_process_itti_msg(NULL);
    }
    acpFree(buffer);

    return NULL;
}
