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
/*! \file nfapi/open-nFAPI/fapi/src/p7/nr_fapi_p7.c
 * \brief
 * \author Ruben S. Silva
 * \date 2024
 * \version 0.1
 * \company OpenAirInterface Software Alliance
 * \email: contact@openairinterface.org, rsilva@allbesmart.pt
 * \note
 * \warning
 */
#include "nr_fapi.h"
#include "nr_fapi_p7.h"
#include "nr_nfapi_p7.h"
#include "debug.h"

uint8_t fapi_nr_p7_message_body_pack(nfapi_p7_message_header_t *header,
                                     uint8_t **ppWritePackedMsg,
                                     uint8_t *end,
                                     nfapi_p7_codec_config_t *config)
{
  // look for the specific message
  uint8_t result = 0;
  switch (header->message_id) {
    case NFAPI_NR_PHY_MSG_TYPE_DL_TTI_REQUEST:
      result = pack_dl_tti_request(header, ppWritePackedMsg, end, config);
      break;
    case NFAPI_NR_PHY_MSG_TYPE_UL_TTI_REQUEST:
      result = pack_ul_tti_request(header, ppWritePackedMsg, end, config);
      break;
    case NFAPI_NR_PHY_MSG_TYPE_SLOT_INDICATION:
      result = pack_nr_slot_indication(header, ppWritePackedMsg, end, config);
      break;
    case NFAPI_NR_PHY_MSG_TYPE_UL_DCI_REQUEST:
      result = pack_ul_dci_request(header, ppWritePackedMsg, end, config);
      break;
      /*
          case NFAPI_NR_PHY_MSG_TYPE_TX_DATA_REQUEST:
            result = pack_tx_data_request(header, ppWritePackedMsg, end, config);
            break;

          case NFAPI_UE_RELEASE_REQUEST:
            result = pack_ue_release_request(header, ppWritePackedMsg, end, config);
            break;

          case NFAPI_UE_RELEASE_RESPONSE:
            result = pack_ue_release_response(header, ppWritePackedMsg, end, config);
            break;

          case NFAPI_NR_PHY_MSG_TYPE_RX_DATA_INDICATION:
            result = pack_nr_rx_data_indication(header, ppWritePackedMsg, end, config);
            break;

          case NFAPI_NR_PHY_MSG_TYPE_CRC_INDICATION:
            result = pack_nr_crc_indication(header, ppWritePackedMsg, end, config);
            break;

          case NFAPI_NR_PHY_MSG_TYPE_UCI_INDICATION:
            result = pack_nr_uci_indication(header, ppWritePackedMsg, end, config);
            break;

          case NFAPI_NR_PHY_MSG_TYPE_SRS_INDICATION:
            result = pack_nr_srs_indication(header, ppWritePackedMsg, end, config);
            break;

          case NFAPI_NR_PHY_MSG_TYPE_RACH_INDICATION:
            result = pack_nr_rach_indication(header, ppWritePackedMsg, end, config);
            break;

          case NFAPI_NR_PHY_MSG_TYPE_DL_NODE_SYNC:
            result = pack_nr_dl_node_sync(header, ppWritePackedMsg, end, config);
            break;

          case NFAPI_NR_PHY_MSG_TYPE_UL_NODE_SYNC:
            result = pack_nr_ul_node_sync(header, ppWritePackedMsg, end, config);
            break;

          case NFAPI_TIMING_INFO:
            result = pack_nr_timing_info(header, ppWritePackedMsg, end, config);
            break;

          case NFAPI_NR_PHY_MSG_TYPE_VENDOR_EXT_SLOT_RESPONSE:
            result = pack_nr_slot_indication(header, ppWritePackedMsg, end, config);
            break;

          default: {
            result = 0;
            if (header->message_id >= NFAPI_VENDOR_EXT_MSG_MIN && header->message_id <= NFAPI_VENDOR_EXT_MSG_MAX) {
              if (config && config->pack_p7_vendor_extension) {
                result = (config->pack_p7_vendor_extension)(header, ppWritePackedMsg, end, config);
              } else {
                NFAPI_TRACE(NFAPI_TRACE_ERROR, "%s VE NFAPI message ID %d. No ve decoder provided\n", __FUNCTION__,
         header->message_id);
              }
            } else {
              NFAPI_TRACE(NFAPI_TRACE_ERROR, "%s NFAPI Unknown message ID %d\n", __FUNCTION__, header->message_id);
            }
          } break;*/
  }

  if (result == 0) {
    NFAPI_TRACE(NFAPI_TRACE_ERROR, "P7 Pack failed to pack message\n");
    return -1;
  }
  return result;
}

int fapi_nr_p7_message_pack(void *pMessageBuf, void *pPackedBuf, uint32_t packedBufLen, nfapi_p7_codec_config_t *config)
{
  if (pMessageBuf == NULL || pPackedBuf == NULL) {
    NFAPI_TRACE(NFAPI_TRACE_ERROR, "P7 Pack supplied pointers are null\n");
    return -1;
  }

  nfapi_p7_message_header_t *pMessageHeader = pMessageBuf;
  uint8_t *pWritePackedMessage = pPackedBuf;
  uint8_t *pPackMessageEnd = pPackedBuf + packedBufLen;
  uint8_t *pPackedLengthField = &pWritePackedMessage[4];
  uint8_t *pPacketBodyField = &pWritePackedMessage[8];
  uint8_t *pPacketBodyFieldStart = &pWritePackedMessage[8];

  uint8_t result = fapi_nr_p7_message_body_pack(pMessageHeader, &pPacketBodyField, pPackMessageEnd, config);
  AssertFatal(result >= 0, "fapi_nr_p7_message_body_pack error packing message body %d\n", result);

  // PHY API message header
  // Number of messages [0]
  // Opaque handle [1]
  // PHY API Message structure
  // Message type ID [2,3]
  // Message Length [4,5,6,7]
  // Message Body [8,...]
  if (!(push8(1, &pWritePackedMessage, pPackMessageEnd) && push8(0, &pWritePackedMessage, pPackMessageEnd)
        && push16(pMessageHeader->message_id, &pWritePackedMessage, pPackMessageEnd))) {
    NFAPI_TRACE(NFAPI_TRACE_ERROR, "P7 Pack header failed\n");
    return -1;
  }

  // check for a valid message length
  uintptr_t msgHead = (uintptr_t)pPacketBodyFieldStart;
  uintptr_t msgEnd = (uintptr_t)pPacketBodyField;
  uint32_t packedMsgLen = msgEnd - msgHead;
  if (packedMsgLen > packedBufLen) {
    NFAPI_TRACE(NFAPI_TRACE_ERROR, "Packed message length error %d, buffer supplied %d\n", packedMsgLen, packedBufLen);
    return -1;
  }

  // Update the message length in the header
  pMessageHeader->message_length = packedMsgLen;

  // Update the message length in the header
  if (!push32(packedMsgLen, &pPackedLengthField, pPackMessageEnd))
    return -1;

  if (1) {
    // quick test
    if (pMessageHeader->message_length != packedMsgLen) {
      NFAPI_TRACE(NFAPI_TRACE_ERROR,
                  "nfapi packedMsgLen(%d) != message_length(%d) id %d\n",
                  packedMsgLen,
                  pMessageHeader->message_length,
                  pMessageHeader->message_id);
    }
  }

  return (packedMsgLen);
}

int fapi_nr_p7_message_unpack(void *pMessageBuf,
                              uint32_t messageBufLen,
                              void *pUnpackedBuf,
                              uint32_t unpackedBufLen,
                              nfapi_p7_codec_config_t *config)
{
  int result = 0;
  nfapi_p7_message_header_t *pMessageHeader = (nfapi_p7_message_header_t *)pUnpackedBuf;
  fapi_message_header_t fapi_hdr;
  uint8_t *pReadPackedMessage = pMessageBuf;

  AssertFatal(pMessageBuf != NULL && pUnpackedBuf != NULL, "P7 unpack supplied pointers are null");
  uint8_t *end = (uint8_t *)pMessageBuf + messageBufLen;
  AssertFatal(messageBufLen >= NFAPI_HEADER_LENGTH && unpackedBufLen >= sizeof(fapi_message_header_t),
              "P5 unpack supplied message buffer is too small %d, %d\n",
              messageBufLen,
              unpackedBufLen);

  // clean the supplied buffer for - tag value blanking
  (void)memset(pUnpackedBuf, 0, unpackedBufLen);
  if (fapi_nr_message_header_unpack(&pReadPackedMessage, NFAPI_HEADER_LENGTH, &fapi_hdr, sizeof(fapi_message_header_t), 0) < 0) {
    // failed to read the header
    return -1;
  }
  pMessageHeader->message_length = fapi_hdr.message_length;
  pMessageHeader->message_id = fapi_hdr.message_id;
  if ((uint8_t *)(pMessageBuf + pMessageHeader->message_length) > end) {
    NFAPI_TRACE(NFAPI_TRACE_ERROR, "P7 unpack message length is greater than the message buffer \n");
    return -1;
  }

  // look for the specific message
  switch (pMessageHeader->message_id) {
    case NFAPI_NR_PHY_MSG_TYPE_DL_TTI_REQUEST:
      if (check_nr_fapi_unpack_length(NFAPI_NR_PHY_MSG_TYPE_DL_TTI_REQUEST, unpackedBufLen))
        result = unpack_dl_tti_request(&pReadPackedMessage, end, pMessageHeader, config);
      break;
    case NFAPI_NR_PHY_MSG_TYPE_UL_TTI_REQUEST:
      if (check_nr_fapi_unpack_length(NFAPI_NR_PHY_MSG_TYPE_UL_TTI_REQUEST, unpackedBufLen))
        result = unpack_ul_tti_request(&pReadPackedMessage, end, pMessageHeader, config);
      break;
    case NFAPI_NR_PHY_MSG_TYPE_SLOT_INDICATION:
      if (check_nr_fapi_unpack_length(NFAPI_NR_PHY_MSG_TYPE_SLOT_INDICATION, unpackedBufLen)) {
        nfapi_nr_slot_indication_scf_t *msg = (nfapi_nr_slot_indication_scf_t *)pMessageHeader;
        result = unpack_nr_slot_indication(&pReadPackedMessage, end, msg, config);
      }
      break;
    case NFAPI_NR_PHY_MSG_TYPE_UL_DCI_REQUEST:
      if (check_nr_fapi_unpack_length(NFAPI_NR_PHY_MSG_TYPE_UL_DCI_REQUEST, unpackedBufLen))
        result = unpack_ul_dci_request(&pReadPackedMessage, end, pMessageHeader, config);
      break;
      /*
          case NFAPI_NR_PHY_MSG_TYPE_TX_DATA_REQUEST:
            if (check_nr_fapi_unpack_length(NFAPI_NR_PHY_MSG_TYPE_TX_DATA_REQUEST, unpackedBufLen))
              result = unpack_tx_data_request(&pReadPackedMessage, end, pMessageHeader, config);
            break;

          case NFAPI_NR_PHY_MSG_TYPE_RX_DATA_INDICATION:
            if (check_nr_fapi_unpack_length(NFAPI_NR_PHY_MSG_TYPE_RX_DATA_INDICATION, unpackedBufLen)) {
              nfapi_nr_rx_data_indication_t *msg = (nfapi_nr_rx_data_indication_t *)pMessageHeader;
              msg->pdu_list = (nfapi_nr_rx_data_pdu_t *)malloc(sizeof(nfapi_nr_rx_data_pdu_t));
              msg->pdu_list->pdu = (uint8_t *)malloc(sizeof(uint8_t));
              result = unpack_nr_rx_data_indication(&pReadPackedMessage, end, msg, config);
            }
            break;

          case NFAPI_NR_PHY_MSG_TYPE_CRC_INDICATION:
            if (check_nr_fapi_unpack_length(NFAPI_NR_PHY_MSG_TYPE_CRC_INDICATION, unpackedBufLen)) {
              nfapi_nr_crc_indication_t *msg = (nfapi_nr_crc_indication_t *)pMessageHeader;
              msg->crc_list = (nfapi_nr_crc_t *)malloc(sizeof(nfapi_nr_crc_t));
              result = unpack_nr_crc_indication(&pReadPackedMessage, end, msg, config);
            }
            break;

          case NFAPI_NR_PHY_MSG_TYPE_UCI_INDICATION:
            if (check_nr_fapi_unpack_length(NFAPI_NR_PHY_MSG_TYPE_UCI_INDICATION, unpackedBufLen)) {
              nfapi_nr_uci_indication_t *msg = (nfapi_nr_uci_indication_t *)pMessageHeader;
              msg->uci_list = (nfapi_nr_uci_t *)malloc(sizeof(nfapi_nr_uci_t));
              result = unpack_nr_uci_indication(&pReadPackedMessage, end, msg, config);
            }
            break;

          case NFAPI_NR_PHY_MSG_TYPE_SRS_INDICATION:
            if (check_nr_fapi_unpack_length(NFAPI_NR_PHY_MSG_TYPE_SRS_INDICATION, unpackedBufLen)) {
              nfapi_nr_srs_indication_t *msg = (nfapi_nr_srs_indication_t *)pMessageHeader;
              msg->pdu_list = (nfapi_nr_srs_indication_pdu_t *)malloc(sizeof(nfapi_nr_srs_indication_pdu_t));
              result = unpack_nr_srs_indication(&pReadPackedMessage, end, msg, config);
            }
            break;

          case NFAPI_NR_PHY_MSG_TYPE_RACH_INDICATION:
            if (check_nr_fapi_unpack_length(NFAPI_NR_PHY_MSG_TYPE_RACH_INDICATION, unpackedBufLen)) {
              nfapi_nr_rach_indication_t *msg = (nfapi_nr_rach_indication_t *)pMessageHeader;
              result = unpack_nr_rach_indication(&pReadPackedMessage, end, msg, config);
            }
            break;
          default:

            if (pMessageHeader->message_id >= NFAPI_VENDOR_EXT_MSG_MIN && pMessageHeader->message_id <= NFAPI_VENDOR_EXT_MSG_MAX) {
              if (config && config->unpack_p7_vendor_extension) {
                result = (config->unpack_p7_vendor_extension)(pMessageHeader, &pReadPackedMessage, end, config);
              } else {
                NFAPI_TRACE(NFAPI_TRACE_ERROR,
                            "%s VE NFAPI message ID %d. No ve decoder provided\n",
                            __FUNCTION__,
                            pMessageHeader->message_id);
              }
            } else {
              NFAPI_TRACE(NFAPI_TRACE_ERROR, "%s NFAPI Unknown message ID %d\n", __FUNCTION__, pMessageHeader->message_id);
            }
            break;*/
  }

  if (result == 0) {
    NFAPI_TRACE(NFAPI_TRACE_ERROR, "P7 Pack failed to unpack message\n");
    return -1;
  }
  return 0;
}

static uint8_t pack_dl_tti_csi_rs_pdu_rel15_value(void *tlv, uint8_t **ppWritePackedMsg, uint8_t *end)
{
  nfapi_nr_dl_tti_csi_rs_pdu_rel15_t *value = (nfapi_nr_dl_tti_csi_rs_pdu_rel15_t *)tlv;
  if (!(push16(value->bwp_size, ppWritePackedMsg, end) && push16(value->bwp_start, ppWritePackedMsg, end)
        && push8(value->subcarrier_spacing, ppWritePackedMsg, end) && push8(value->cyclic_prefix, ppWritePackedMsg, end)
        && push16(value->start_rb, ppWritePackedMsg, end) && push16(value->nr_of_rbs, ppWritePackedMsg, end)
        && push8(value->csi_type, ppWritePackedMsg, end) && push8(value->row, ppWritePackedMsg, end)
        && push16(value->freq_domain, ppWritePackedMsg, end) && push8(value->symb_l0, ppWritePackedMsg, end)
        && push8(value->symb_l1, ppWritePackedMsg, end) && push8(value->cdm_type, ppWritePackedMsg, end)
        && push8(value->freq_density, ppWritePackedMsg, end) && push16(value->scramb_id, ppWritePackedMsg, end)
        && push8(value->power_control_offset, ppWritePackedMsg, end)
        && push8(value->power_control_offset_ss, ppWritePackedMsg, end))) {
    return 0;
  }

  // Precoding and Beamforming
  if (!(push16(value->precodingAndBeamforming.num_prgs, ppWritePackedMsg, end)
        && push16(value->precodingAndBeamforming.prg_size, ppWritePackedMsg, end)
        && push8(value->precodingAndBeamforming.dig_bf_interfaces, ppWritePackedMsg, end))) {
    return 0;
  }
  for (int prg = 0; prg < value->precodingAndBeamforming.num_prgs; prg++) {
    if (!push16(value->precodingAndBeamforming.prgs_list[prg].pm_idx, ppWritePackedMsg, end)) {
      return 0;
    }
    for (int digInt = 0; digInt < value->precodingAndBeamforming.dig_bf_interfaces; digInt++) {
      if (!push16(value->precodingAndBeamforming.prgs_list[prg].dig_bf_interface_list[digInt].beam_idx, ppWritePackedMsg, end)) {
        return 0;
      }
    }
  }
  return 1;
}

static uint8_t pack_dl_tti_pdcch_pdu_rel15_value(void *tlv, uint8_t **ppWritePackedMsg, uint8_t *end)
{
  nfapi_nr_dl_tti_pdcch_pdu_rel15_t *value = (nfapi_nr_dl_tti_pdcch_pdu_rel15_t *)tlv;

  if (!(push16(value->BWPSize, ppWritePackedMsg, end) && push16(value->BWPStart, ppWritePackedMsg, end)
        && push8(value->SubcarrierSpacing, ppWritePackedMsg, end) && push8(value->CyclicPrefix, ppWritePackedMsg, end)
        && push8(value->StartSymbolIndex, ppWritePackedMsg, end) && push8(value->DurationSymbols, ppWritePackedMsg, end)
        && pusharray8(value->FreqDomainResource, 6, 6, ppWritePackedMsg, end)
        && push8(value->CceRegMappingType, ppWritePackedMsg, end) && push8(value->RegBundleSize, ppWritePackedMsg, end)
        && push8(value->InterleaverSize, ppWritePackedMsg, end) && push8(value->CoreSetType, ppWritePackedMsg, end)
        && push16(value->ShiftIndex, ppWritePackedMsg, end) && push8(value->precoderGranularity, ppWritePackedMsg, end)
        && push16(value->numDlDci, ppWritePackedMsg, end))) {
    return 0;
  }

  for (uint16_t i = 0; i < value->numDlDci; ++i) {
    if (!(push16(value->dci_pdu[i].RNTI, ppWritePackedMsg, end) && push16(value->dci_pdu[i].ScramblingId, ppWritePackedMsg, end)
          && push16(value->dci_pdu[i].ScramblingRNTI, ppWritePackedMsg, end)
          && push8(value->dci_pdu[i].CceIndex, ppWritePackedMsg, end)
          && push8(value->dci_pdu[i].AggregationLevel, ppWritePackedMsg, end))) {
      return 0;
    }
    // Precoding and beamforming
    if (!(push16(value->dci_pdu[i].precodingAndBeamforming.num_prgs, ppWritePackedMsg, end)
          && push16(value->dci_pdu[i].precodingAndBeamforming.prg_size, ppWritePackedMsg, end)
          && push8(value->dci_pdu[i].precodingAndBeamforming.dig_bf_interfaces, ppWritePackedMsg, end))) {
      return 0;
    }
    for (int prg = 0; prg < value->dci_pdu[i].precodingAndBeamforming.num_prgs; prg++) {
      if (!push16(value->dci_pdu[i].precodingAndBeamforming.prgs_list[prg].pm_idx, ppWritePackedMsg, end)) {
        return 0;
      }
      for (int digInt = 0; digInt < value->dci_pdu[i].precodingAndBeamforming.dig_bf_interfaces; digInt++) {
        if (!push16(value->dci_pdu[i].precodingAndBeamforming.prgs_list[prg].dig_bf_interface_list[digInt].beam_idx,
                    ppWritePackedMsg,
                    end)) {
          return 0;
        }
      }
    }
    // TX Power info
    if (!(push8(value->dci_pdu[i].beta_PDCCH_1_0, ppWritePackedMsg, end)
          && push8(value->dci_pdu[i].powerControlOffsetSS, ppWritePackedMsg, end) &&
          // DCI Payload fields
          push16(value->dci_pdu[i].PayloadSizeBits, ppWritePackedMsg, end) &&
          // Pack DCI Payload
          pack_dci_payload(value->dci_pdu[i].Payload, value->dci_pdu[i].PayloadSizeBits, ppWritePackedMsg, end))) {
      return 0;
    }
  }
  return 1;
}

static uint8_t pack_dl_tti_pdsch_pdu_rel15_value(void *tlv, uint8_t **ppWritePackedMsg, uint8_t *end)
{
  nfapi_nr_dl_tti_pdsch_pdu_rel15_t *value = (nfapi_nr_dl_tti_pdsch_pdu_rel15_t *)tlv;

  if (!(push16(value->pduBitmap, ppWritePackedMsg, end) && push16(value->rnti, ppWritePackedMsg, end)
        && push16(value->pduIndex, ppWritePackedMsg, end) && push16(value->BWPSize, ppWritePackedMsg, end)
        && push16(value->BWPStart, ppWritePackedMsg, end) && push8(value->SubcarrierSpacing, ppWritePackedMsg, end)
        && push8(value->CyclicPrefix, ppWritePackedMsg, end) && push8(value->NrOfCodewords, ppWritePackedMsg, end))) {
    return 0;
  }
  for (int i = 0; i < value->NrOfCodewords; ++i) {
    if (!(push16(value->targetCodeRate[i], ppWritePackedMsg, end) && push8(value->qamModOrder[i], ppWritePackedMsg, end)
          && push8(value->mcsIndex[i], ppWritePackedMsg, end) && push8(value->mcsTable[i], ppWritePackedMsg, end)
          && push8(value->rvIndex[i], ppWritePackedMsg, end) && push32(value->TBSize[i], ppWritePackedMsg, end))) {
      return 0;
    }
  }

  if (!(push16(value->dataScramblingId, ppWritePackedMsg, end) && push8(value->nrOfLayers, ppWritePackedMsg, end)
        && push8(value->transmissionScheme, ppWritePackedMsg, end) && push8(value->refPoint, ppWritePackedMsg, end)
        && push16(value->dlDmrsSymbPos, ppWritePackedMsg, end) && push8(value->dmrsConfigType, ppWritePackedMsg, end)
        && push16(value->dlDmrsScramblingId, ppWritePackedMsg, end) && push8(value->SCID, ppWritePackedMsg, end)
        && push8(value->numDmrsCdmGrpsNoData, ppWritePackedMsg, end) && push16(value->dmrsPorts, ppWritePackedMsg, end)
        && push8(value->resourceAlloc, ppWritePackedMsg, end) && (int)pusharray8(value->rbBitmap, 36, 36, ppWritePackedMsg, end)
        && push16(value->rbStart, ppWritePackedMsg, end) && push16(value->rbSize, ppWritePackedMsg, end)
        && push8(value->VRBtoPRBMapping, ppWritePackedMsg, end) && push8(value->StartSymbolIndex, ppWritePackedMsg, end)
        && push8(value->NrOfSymbols, ppWritePackedMsg, end))) {
    return 0;
  }

  // Check pduBitMap bit 0 to add or not PTRS parameters
  if (value->pduBitmap & 0b1) {
    if (!(push8(value->PTRSPortIndex, ppWritePackedMsg, end) && push8(value->PTRSTimeDensity, ppWritePackedMsg, end)
          && push8(value->PTRSFreqDensity, ppWritePackedMsg, end) && push8(value->PTRSReOffset, ppWritePackedMsg, end)
          && push8(value->nEpreRatioOfPDSCHToPTRS, ppWritePackedMsg, end))) {
      return 0;
    }
  }

  if (!(push16(value->precodingAndBeamforming.num_prgs, ppWritePackedMsg, end)
        && push16(value->precodingAndBeamforming.prg_size, ppWritePackedMsg, end)
        && push8(value->precodingAndBeamforming.dig_bf_interfaces, ppWritePackedMsg, end))) {
    return 0;
  }
  for (int i = 0; i < value->precodingAndBeamforming.num_prgs; ++i) {
    if (!push16(value->precodingAndBeamforming.prgs_list[i].pm_idx, ppWritePackedMsg, end)) {
      return 0;
    }
    for (int k = 0; k < value->precodingAndBeamforming.dig_bf_interfaces; ++k) {
      if (!push16(value->precodingAndBeamforming.prgs_list[i].dig_bf_interface_list[k].beam_idx, ppWritePackedMsg, end)) {
        return 0;
      }
    }
  }

  if (!(push8(value->powerControlOffset, ppWritePackedMsg, end) && push8(value->powerControlOffsetSS, ppWritePackedMsg, end))) {
    return 0;
  }

  // Check pduBitMap bit 1 to add or not CBG parameters
  if (value->pduBitmap & 0b10) {
    if (!(push8(value->isLastCbPresent, ppWritePackedMsg, end) && push8(value->isInlineTbCrc, ppWritePackedMsg, end)
          && push32(value->dlTbCrc, ppWritePackedMsg, end))) {
      return 0;
    }
  }

  if (!push8(value->maintenance_parms_v3.ldpcBaseGraph, ppWritePackedMsg, end)
      || !push32(value->maintenance_parms_v3.tbSizeLbrmBytes, ppWritePackedMsg, end))
    return 0;

  return 1;
}

static uint8_t pack_dl_tti_ssb_pdu_rel15_value(void *tlv, uint8_t **ppWritePackedMsg, uint8_t *end)
{
  NFAPI_TRACE(NFAPI_TRACE_DEBUG, "Packing ssb. \n");
  nfapi_nr_dl_tti_ssb_pdu_rel15_t *value = (nfapi_nr_dl_tti_ssb_pdu_rel15_t *)tlv;

  if (!(push16(value->PhysCellId, ppWritePackedMsg, end) && push8(value->BetaPss, ppWritePackedMsg, end)
        && push8(value->SsbBlockIndex, ppWritePackedMsg, end) && push8(value->SsbSubcarrierOffset, ppWritePackedMsg, end)
        && push16(value->ssbOffsetPointA, ppWritePackedMsg, end) && push8(value->bchPayloadFlag, ppWritePackedMsg, end)
        && push8((value->bchPayload >> 16) & 0xff, ppWritePackedMsg, end)
        && push8((value->bchPayload >> 8) & 0xff, ppWritePackedMsg, end) && push8(value->bchPayload & 0xff, ppWritePackedMsg, end)
        && push8(0, ppWritePackedMsg, end) && push16(value->precoding_and_beamforming.num_prgs, ppWritePackedMsg, end)
        && push16(value->precoding_and_beamforming.prg_size, ppWritePackedMsg, end)
        && push8(value->precoding_and_beamforming.dig_bf_interfaces, ppWritePackedMsg, end))) {
    return 0;
  }
  for (int i = 0; i < value->precoding_and_beamforming.num_prgs; ++i) {
    if (!push16(value->precoding_and_beamforming.prgs_list[i].pm_idx, ppWritePackedMsg, end)) {
      return 0;
    }
    for (int k = 0; k < value->precoding_and_beamforming.dig_bf_interfaces; ++k) {
      if (!push16(value->precoding_and_beamforming.prgs_list[i].dig_bf_interface_list[k].beam_idx, ppWritePackedMsg, end)) {
        return 0;
      }
    }
  }
  return 1;
}

static uint8_t pack_dl_tti_request_body_value(void *tlv, uint8_t **ppWritePackedMsg, uint8_t *end)
{
  nfapi_nr_dl_tti_request_pdu_t *value = (nfapi_nr_dl_tti_request_pdu_t *)tlv;
  uintptr_t msgHead = (uintptr_t)*ppWritePackedMsg;
  if (!push16(value->PDUType, ppWritePackedMsg, end))
    return 0;
  uint8_t *pPackedLengthField = *ppWritePackedMsg;
  if (!push16(value->PDUSize, ppWritePackedMsg, end))
    return 0;

  // first match the pdu type, then call the respective function
  switch (value->PDUType) {
    case NFAPI_NR_DL_TTI_PDCCH_PDU_TYPE: {
      if (!(pack_dl_tti_pdcch_pdu_rel15_value(&value->pdcch_pdu.pdcch_pdu_rel15, ppWritePackedMsg, end)))
        return 0;
    } break;

    case NFAPI_NR_DL_TTI_PDSCH_PDU_TYPE: {
      if (!(pack_dl_tti_pdsch_pdu_rel15_value(&value->pdsch_pdu.pdsch_pdu_rel15, ppWritePackedMsg, end)))
        return 0;
    } break;

    case NFAPI_NR_DL_TTI_CSI_RS_PDU_TYPE: {
      if (!(pack_dl_tti_csi_rs_pdu_rel15_value(&value->csi_rs_pdu.csi_rs_pdu_rel15, ppWritePackedMsg, end)))
        return 0;
    } break;

    case NFAPI_NR_DL_TTI_SSB_PDU_TYPE: {
      if (!(pack_dl_tti_ssb_pdu_rel15_value(&value->ssb_pdu.ssb_pdu_rel15, ppWritePackedMsg, end)))
        return 0;
    } break;

    default: {
      NFAPI_TRACE(NFAPI_TRACE_ERROR, "FIXME : Invalid DL_TTI pdu type %d \n", value->PDUType);
    } break;
  }
  // pack proper size
  uintptr_t msgEnd = (uintptr_t)*ppWritePackedMsg;
  uint16_t packedMsgLen = msgEnd - msgHead;
  value->PDUSize = packedMsgLen;
  return push16(value->PDUSize, &pPackedLengthField, end);
}

uint8_t pack_dl_tti_request(void *msg, uint8_t **ppWritePackedMsg, uint8_t *end, nfapi_p7_codec_config_t *config)
{
  nfapi_nr_dl_tti_request_t *pNfapiMsg = (nfapi_nr_dl_tti_request_t *)msg;

  if (!(push16(pNfapiMsg->SFN, ppWritePackedMsg, end) && push16(pNfapiMsg->Slot, ppWritePackedMsg, end)
        && push8(pNfapiMsg->dl_tti_request_body.nPDUs, ppWritePackedMsg, end)
        && push8(pNfapiMsg->dl_tti_request_body.nGroup, ppWritePackedMsg, end))) {
    return 0;
  }
  for (int i = 0; i < pNfapiMsg->dl_tti_request_body.nPDUs; i++) {
    if (!pack_dl_tti_request_body_value(&pNfapiMsg->dl_tti_request_body.dl_tti_pdu_list[i], ppWritePackedMsg, end)) {
      return 0;
    }
  }

  for (int i = 0; i < pNfapiMsg->dl_tti_request_body.nGroup; i++) {
    if (!push8(pNfapiMsg->dl_tti_request_body.nUe[i], ppWritePackedMsg, end))
      return 0;
    for (int j = 0; j < pNfapiMsg->dl_tti_request_body.nUe[i]; j++) {
      if (!(push32(pNfapiMsg->dl_tti_request_body.PduIdx[i][j], ppWritePackedMsg, end))) {
        return 0;
      }
    }
  }
  return 1;
}

static uint8_t unpack_dl_tti_pdcch_pdu_rel15_value(void *tlv, uint8_t **ppReadPackedMsg, uint8_t *end)
{
  nfapi_nr_dl_tti_pdcch_pdu_rel15_t *value = (nfapi_nr_dl_tti_pdcch_pdu_rel15_t *)tlv;

  if (!(pull16(ppReadPackedMsg, &value->BWPSize, end) && pull16(ppReadPackedMsg, &value->BWPStart, end)
        && pull8(ppReadPackedMsg, &value->SubcarrierSpacing, end) && pull8(ppReadPackedMsg, &value->CyclicPrefix, end)
        && pull8(ppReadPackedMsg, &value->StartSymbolIndex, end) && pull8(ppReadPackedMsg, &value->DurationSymbols, end)
        && pullarray8(ppReadPackedMsg, value->FreqDomainResource, 6, 6, end)
        && pull8(ppReadPackedMsg, &value->CceRegMappingType, end) && pull8(ppReadPackedMsg, &value->RegBundleSize, end)
        && pull8(ppReadPackedMsg, &value->InterleaverSize, end) && pull8(ppReadPackedMsg, &value->CoreSetType, end)
        && pull16(ppReadPackedMsg, &value->ShiftIndex, end) && pull8(ppReadPackedMsg, &value->precoderGranularity, end)
        && pull16(ppReadPackedMsg, &value->numDlDci, end))) {
    return 0;
  }

  for (uint16_t i = 0; i < value->numDlDci; ++i) {
    if (!(pull16(ppReadPackedMsg, &value->dci_pdu[i].RNTI, end) && pull16(ppReadPackedMsg, &value->dci_pdu[i].ScramblingId, end)
          && pull16(ppReadPackedMsg, &value->dci_pdu[i].ScramblingRNTI, end)
          && pull8(ppReadPackedMsg, &value->dci_pdu[i].CceIndex, end)
          && pull8(ppReadPackedMsg, &value->dci_pdu[i].AggregationLevel, end)
          && pull16(ppReadPackedMsg, &value->dci_pdu[i].precodingAndBeamforming.num_prgs, end)
          && pull16(ppReadPackedMsg, &value->dci_pdu[i].precodingAndBeamforming.prg_size, end)
          && pull8(ppReadPackedMsg, &value->dci_pdu[i].precodingAndBeamforming.dig_bf_interfaces, end))) {
      return 0;
    }
    for (int prg = 0; prg < value->dci_pdu[i].precodingAndBeamforming.num_prgs; prg++) {
      if (!pull16(ppReadPackedMsg, &value->dci_pdu[i].precodingAndBeamforming.prgs_list[prg].pm_idx, end)) {
        return 0;
      }
      for (int digInt = 0; digInt < value->dci_pdu[i].precodingAndBeamforming.dig_bf_interfaces; digInt++) {
        if (!pull16(ppReadPackedMsg,
                    &value->dci_pdu[i].precodingAndBeamforming.prgs_list[prg].dig_bf_interface_list[digInt].beam_idx,
                    end)) {
          return 0;
        }
      }
    }
    if (!(pull8(ppReadPackedMsg, &value->dci_pdu[i].beta_PDCCH_1_0, end)
          && pull8(ppReadPackedMsg, &value->dci_pdu[i].powerControlOffsetSS, end)
          && pull16(ppReadPackedMsg, &value->dci_pdu[i].PayloadSizeBits, end)
          && unpack_dci_payload(value->dci_pdu[i].Payload, value->dci_pdu[i].PayloadSizeBits, ppReadPackedMsg, end))) {
      return 0;
    }
  }
  return 1;
}

static uint8_t unpack_dl_tti_pdsch_pdu_rel15_value(void *tlv, uint8_t **ppReadPackedMsg, uint8_t *end)
{
  nfapi_nr_dl_tti_pdsch_pdu_rel15_t *value = (nfapi_nr_dl_tti_pdsch_pdu_rel15_t *)tlv;

  if (!(pull16(ppReadPackedMsg, &value->pduBitmap, end) && pull16(ppReadPackedMsg, &value->rnti, end)
        && pull16(ppReadPackedMsg, &value->pduIndex, end) && pull16(ppReadPackedMsg, &value->BWPSize, end)
        && pull16(ppReadPackedMsg, &value->BWPStart, end) && pull8(ppReadPackedMsg, &value->SubcarrierSpacing, end)
        && pull8(ppReadPackedMsg, &value->CyclicPrefix, end) && pull8(ppReadPackedMsg, &value->NrOfCodewords, end))) {
    return 0;
  }
  for (int i = 0; i < value->NrOfCodewords; ++i) {
    if (!(pull16(ppReadPackedMsg, &value->targetCodeRate[i], end) && pull8(ppReadPackedMsg, &value->qamModOrder[i], end)
          && pull8(ppReadPackedMsg, &value->mcsIndex[i], end) && pull8(ppReadPackedMsg, &value->mcsTable[i], end)
          && pull8(ppReadPackedMsg, &value->rvIndex[i], end) && pull32(ppReadPackedMsg, &value->TBSize[i], end))) {
      return 0;
    }
  }

  if (!(pull16(ppReadPackedMsg, &value->dataScramblingId, end) && pull8(ppReadPackedMsg, &value->nrOfLayers, end)
        && pull8(ppReadPackedMsg, &value->transmissionScheme, end) && pull8(ppReadPackedMsg, &value->refPoint, end)
        && pull16(ppReadPackedMsg, &value->dlDmrsSymbPos, end) && pull8(ppReadPackedMsg, &value->dmrsConfigType, end)
        && pull16(ppReadPackedMsg, &value->dlDmrsScramblingId, end) && pull8(ppReadPackedMsg, &value->SCID, end)
        && pull8(ppReadPackedMsg, &value->numDmrsCdmGrpsNoData, end) && pull16(ppReadPackedMsg, &value->dmrsPorts, end)
        && pull8(ppReadPackedMsg, &value->resourceAlloc, end) && pullarray8(ppReadPackedMsg, &value->rbBitmap[0], 36, 36, end)
        && pull16(ppReadPackedMsg, &value->rbStart, end) && pull16(ppReadPackedMsg, &value->rbSize, end)
        && pull8(ppReadPackedMsg, &value->VRBtoPRBMapping, end) && pull8(ppReadPackedMsg, &value->StartSymbolIndex, end)
        && pull8(ppReadPackedMsg, &value->NrOfSymbols, end))) {
    return 0;
  }
  // Check pduBitMap bit 0 to pull PTRS parameters or not
  if (value->pduBitmap & 0b1) {
    if (!(pull8(ppReadPackedMsg, &value->PTRSPortIndex, end) && pull8(ppReadPackedMsg, &value->PTRSTimeDensity, end)
          && pull8(ppReadPackedMsg, &value->PTRSFreqDensity, end) && pull8(ppReadPackedMsg, &value->PTRSReOffset, end)
          && pull8(ppReadPackedMsg, &value->nEpreRatioOfPDSCHToPTRS, end))) {
      return 0;
    }
  }

  if (!(pull16(ppReadPackedMsg, &value->precodingAndBeamforming.num_prgs, end)
        && pull16(ppReadPackedMsg, &value->precodingAndBeamforming.prg_size, end)
        && pull8(ppReadPackedMsg, &value->precodingAndBeamforming.dig_bf_interfaces, end))) {
    return 0;
  }

  for (int i = 0; i < value->precodingAndBeamforming.num_prgs; ++i) {
    if (!pull16(ppReadPackedMsg, &value->precodingAndBeamforming.prgs_list[i].pm_idx, end)) {
      return 0;
    }
    for (int k = 0; k < value->precodingAndBeamforming.dig_bf_interfaces; ++k) {
      if (!pull16(ppReadPackedMsg, &value->precodingAndBeamforming.prgs_list[i].dig_bf_interface_list[k].beam_idx, end)) {
        return 0;
      }
    }
  }
  // Tx power info
  if (!(pull8(ppReadPackedMsg, &value->powerControlOffset, end) && pull8(ppReadPackedMsg, &value->powerControlOffsetSS, end))) {
    return 0;
  }

  // Check pduBitMap bit 1 to pull CBG parameters or not
  if (value->pduBitmap & 0b10) {
    if (!(pull8(ppReadPackedMsg, &value->isLastCbPresent, end) && pull8(ppReadPackedMsg, &value->isInlineTbCrc, end)
          && pull32(ppReadPackedMsg, &value->dlTbCrc, end))) {
      return 0;
    }
  }

  if (!pull8(ppReadPackedMsg, &value->maintenance_parms_v3.ldpcBaseGraph, end)
      || !pull32(ppReadPackedMsg, &value->maintenance_parms_v3.tbSizeLbrmBytes, end))
    return 0;

  return 1;
}

static uint8_t unpack_dl_tti_csi_rs_pdu_rel15_value(void *tlv, uint8_t **ppReadPackedMsg, uint8_t *end)
{
  nfapi_nr_dl_tti_csi_rs_pdu_rel15_t *value = (nfapi_nr_dl_tti_csi_rs_pdu_rel15_t *)tlv;
  if (!(pull16(ppReadPackedMsg, &value->bwp_size, end) && pull16(ppReadPackedMsg, &value->bwp_start, end)
        && pull8(ppReadPackedMsg, &value->subcarrier_spacing, end) && pull8(ppReadPackedMsg, &value->cyclic_prefix, end)
        && pull16(ppReadPackedMsg, &value->start_rb, end) && pull16(ppReadPackedMsg, &value->nr_of_rbs, end)
        && pull8(ppReadPackedMsg, &value->csi_type, end) && pull8(ppReadPackedMsg, &value->row, end)
        && pull16(ppReadPackedMsg, &value->freq_domain, end) && pull8(ppReadPackedMsg, &value->symb_l0, end)
        && pull8(ppReadPackedMsg, &value->symb_l1, end) && pull8(ppReadPackedMsg, &value->cdm_type, end)
        && pull8(ppReadPackedMsg, &value->freq_density, end) && pull16(ppReadPackedMsg, &value->scramb_id, end)
        && pull8(ppReadPackedMsg, &value->power_control_offset, end)
        && pull8(ppReadPackedMsg, &value->power_control_offset_ss, end))) {
    return 0;
  }
  if (!(pull16(ppReadPackedMsg, &value->precodingAndBeamforming.num_prgs, end)
        && pull16(ppReadPackedMsg, &value->precodingAndBeamforming.prg_size, end)
        && pull8(ppReadPackedMsg, &value->precodingAndBeamforming.dig_bf_interfaces, end))) {
    return 0;
  }

  for (int i = 0; i < value->precodingAndBeamforming.num_prgs; ++i) {
    if (!pull16(ppReadPackedMsg, &value->precodingAndBeamforming.prgs_list[i].pm_idx, end)) {
      return 0;
    }
    for (int k = 0; k < value->precodingAndBeamforming.dig_bf_interfaces; ++k) {
      if (!pull16(ppReadPackedMsg, &value->precodingAndBeamforming.prgs_list[i].dig_bf_interface_list[k].beam_idx, end)) {
        return 0;
      }
    }
  }
  return 1;
}

static uint8_t unpack_dl_tti_ssb_pdu_rel15_value(void *tlv, uint8_t **ppReadPackedMsg, uint8_t *end)
{
  NFAPI_TRACE(NFAPI_TRACE_DEBUG, "Unpacking ssb. \n");
  uint8_t byte3, byte2, byte1, byte0;
  nfapi_nr_dl_tti_ssb_pdu_rel15_t *value = (nfapi_nr_dl_tti_ssb_pdu_rel15_t *)tlv;

  if (!(pull16(ppReadPackedMsg, &value->PhysCellId, end) && pull8(ppReadPackedMsg, &value->BetaPss, end)
        && pull8(ppReadPackedMsg, &value->SsbBlockIndex, end) && pull8(ppReadPackedMsg, &value->SsbSubcarrierOffset, end)
        && pull16(ppReadPackedMsg, &value->ssbOffsetPointA, end) && pull8(ppReadPackedMsg, &value->bchPayloadFlag, end)
        && pull8(ppReadPackedMsg, &byte3, end) && pull8(ppReadPackedMsg, &byte2, end) && pull8(ppReadPackedMsg, &byte1, end)
        && pull8(ppReadPackedMsg, &byte0, end))) { // this should be always 0, bchpayload is 24 bits
    return 0;
  }
  // rebuild the bchPayload
  value->bchPayload = byte3 << 16 | byte2 << 8 | byte1;

  if (!(pull16(ppReadPackedMsg, &value->precoding_and_beamforming.num_prgs, end)
        && pull16(ppReadPackedMsg, &value->precoding_and_beamforming.prg_size, end)
        && pull8(ppReadPackedMsg, &value->precoding_and_beamforming.dig_bf_interfaces, end))) {
    return 0;
  }

  for (int i = 0; i < value->precoding_and_beamforming.num_prgs; ++i) {
    if (!pull16(ppReadPackedMsg, &value->precoding_and_beamforming.prgs_list[i].pm_idx, end)) {
      return 0;
    }
    for (int k = 0; k < value->precoding_and_beamforming.dig_bf_interfaces; ++k) {
      if (!pull16(ppReadPackedMsg, &value->precoding_and_beamforming.prgs_list[i].dig_bf_interface_list[k].beam_idx, end)) {
        return 0;
      }
    }
  }
  return 1;
}

static uint8_t unpack_dl_tti_request_body_value(uint8_t **ppReadPackedMsg, uint8_t *end, void *msg)
{
  nfapi_nr_dl_tti_request_pdu_t *value = (nfapi_nr_dl_tti_request_pdu_t *)msg;

  if (!(pull16(ppReadPackedMsg, &value->PDUType, end) && pull16(ppReadPackedMsg, (uint16_t *)&value->PDUSize, end)))
    return 0;

  // first match the pdu type, then call the respective function
  switch (value->PDUType) {
    case NFAPI_NR_DL_TTI_PDCCH_PDU_TYPE: {
      if (!(unpack_dl_tti_pdcch_pdu_rel15_value(&value->pdcch_pdu.pdcch_pdu_rel15, ppReadPackedMsg, end)))
        return 0;
    } break;

    case NFAPI_NR_DL_TTI_PDSCH_PDU_TYPE: {
      if (!(unpack_dl_tti_pdsch_pdu_rel15_value(&value->pdsch_pdu.pdsch_pdu_rel15, ppReadPackedMsg, end)))
        return 0;
    } break;

    case NFAPI_NR_DL_TTI_CSI_RS_PDU_TYPE: {
      if (!(unpack_dl_tti_csi_rs_pdu_rel15_value(&value->csi_rs_pdu.csi_rs_pdu_rel15, ppReadPackedMsg, end)))
        return 0;
    } break;

    case NFAPI_NR_DL_TTI_SSB_PDU_TYPE: {
      if (!(unpack_dl_tti_ssb_pdu_rel15_value(&value->ssb_pdu.ssb_pdu_rel15, ppReadPackedMsg, end)))
        return 0;
    } break;

    default: {
      NFAPI_TRACE(NFAPI_TRACE_ERROR, "FIXME : Invalid DL_TTI pdu type %d \n", value->PDUType);
    } break;
  }

  return 1;
}

uint8_t unpack_dl_tti_request(uint8_t **ppReadPackedMsg, uint8_t *end, void *msg, nfapi_p7_codec_config_t *config)
{
  nfapi_nr_dl_tti_request_t *pNfapiMsg = (nfapi_nr_dl_tti_request_t *)msg;

  if (!(pull16(ppReadPackedMsg, &pNfapiMsg->SFN, end) && pull16(ppReadPackedMsg, &pNfapiMsg->Slot, end)
        && pull8(ppReadPackedMsg, &pNfapiMsg->dl_tti_request_body.nPDUs, end)
        && pull8(ppReadPackedMsg, &pNfapiMsg->dl_tti_request_body.nGroup, end))) {
    return 0;
  }
  for (int i = 0; i < pNfapiMsg->dl_tti_request_body.nPDUs; i++) {
    if (!unpack_dl_tti_request_body_value(ppReadPackedMsg, end, &pNfapiMsg->dl_tti_request_body.dl_tti_pdu_list[i]))
      return 0;
  }

  for (int i = 0; i < pNfapiMsg->dl_tti_request_body.nGroup; i++) {
    if (!pull8(ppReadPackedMsg, &pNfapiMsg->dl_tti_request_body.nUe[i], end)) {
      return 0;
    }
    for (int j = 0; j < pNfapiMsg->dl_tti_request_body.nUe[i]; j++) {
      if (!pull8(ppReadPackedMsg, &pNfapiMsg->dl_tti_request_body.PduIdx[i][j], end)) {
        return 0;
      }
    }
  }

  return 1;
}

// Pack fns for ul_tti PDUS

static uint8_t pack_nr_rx_beamforming_pdu(const nfapi_nr_ul_beamforming_t *beamforming_pdu,
                                          uint8_t **ppWritePackedMsg,
                                          uint8_t *end)
{ // Pack RX Beamforming PDU
  if (!(push16((*beamforming_pdu).num_prgs, ppWritePackedMsg, end) && push16((*beamforming_pdu).prg_size, ppWritePackedMsg, end)
        && push8((*beamforming_pdu).dig_bf_interface, ppWritePackedMsg, end))) {
    return 0;
  }
  for (int prg = 0; prg < (*beamforming_pdu).num_prgs; prg++) {
    for (int digBFInterface = 0; digBFInterface < (*beamforming_pdu).dig_bf_interface; digBFInterface++) {
      if (!push16((*beamforming_pdu).prgs_list[prg].dig_bf_interface_list[digBFInterface].beam_idx, ppWritePackedMsg, end)) {
        return 0;
      }
    }
  }
  return 1;
}

static uint8_t pack_ul_tti_request_prach_pdu(nfapi_nr_prach_pdu_t *prach_pdu, uint8_t **ppWritePackedMsg, uint8_t *end)
{
  if (!(push16(prach_pdu->phys_cell_id, ppWritePackedMsg, end) && push8(prach_pdu->num_prach_ocas, ppWritePackedMsg, end)
        && push8(prach_pdu->prach_format, ppWritePackedMsg, end) && push8(prach_pdu->num_ra, ppWritePackedMsg, end)
        && push8(prach_pdu->prach_start_symbol, ppWritePackedMsg, end) && push16(prach_pdu->num_cs, ppWritePackedMsg, end))) {
    return 0;
  }

  return pack_nr_rx_beamforming_pdu(&prach_pdu->beamforming, ppWritePackedMsg, end);
}

static uint8_t pack_ul_tti_request_pusch_pdu(nfapi_nr_pusch_pdu_t *pusch_pdu, uint8_t **ppWritePackedMsg, uint8_t *end)
{
  if (!(push16(pusch_pdu->pdu_bit_map, ppWritePackedMsg, end) && push16(pusch_pdu->rnti, ppWritePackedMsg, end)
        && push32(pusch_pdu->handle, ppWritePackedMsg, end) && push16(pusch_pdu->bwp_size, ppWritePackedMsg, end)
        && push16(pusch_pdu->bwp_start, ppWritePackedMsg, end) && push8(pusch_pdu->subcarrier_spacing, ppWritePackedMsg, end)
        && push8(pusch_pdu->cyclic_prefix, ppWritePackedMsg, end) && push16(pusch_pdu->target_code_rate, ppWritePackedMsg, end)
        && push8(pusch_pdu->qam_mod_order, ppWritePackedMsg, end) && push8(pusch_pdu->mcs_index, ppWritePackedMsg, end)
        && push8(pusch_pdu->mcs_table, ppWritePackedMsg, end) && push8(pusch_pdu->transform_precoding, ppWritePackedMsg, end)
        && push16(pusch_pdu->data_scrambling_id, ppWritePackedMsg, end) && push8(pusch_pdu->nrOfLayers, ppWritePackedMsg, end)
        && push16(pusch_pdu->ul_dmrs_symb_pos, ppWritePackedMsg, end) && push8(pusch_pdu->dmrs_config_type, ppWritePackedMsg, end)
        && push16(pusch_pdu->ul_dmrs_scrambling_id, ppWritePackedMsg, end)
        && push16(pusch_pdu->pusch_identity, ppWritePackedMsg, end) && push8(pusch_pdu->scid, ppWritePackedMsg, end)
        && push8(pusch_pdu->num_dmrs_cdm_grps_no_data, ppWritePackedMsg, end)
        && push16(pusch_pdu->dmrs_ports, ppWritePackedMsg, end) && push8(pusch_pdu->resource_alloc, ppWritePackedMsg, end)
        && pusharray8(pusch_pdu->rb_bitmap, 36, 36, ppWritePackedMsg, end) && push16(pusch_pdu->rb_start, ppWritePackedMsg, end)
        && push16(pusch_pdu->rb_size, ppWritePackedMsg, end) && push8(pusch_pdu->vrb_to_prb_mapping, ppWritePackedMsg, end)
        && push8(pusch_pdu->frequency_hopping, ppWritePackedMsg, end)
        && push16(pusch_pdu->tx_direct_current_location, ppWritePackedMsg, end)
        && push8(pusch_pdu->uplink_frequency_shift_7p5khz, ppWritePackedMsg, end)
        && push8(pusch_pdu->start_symbol_index, ppWritePackedMsg, end) && push8(pusch_pdu->nr_of_symbols, ppWritePackedMsg, end))) {
    return 0;
  }

  // Pack Optional Data only included if indicated in pduBitmap
  // Check if PUSCH_PDU_BITMAP_PUSCH_DATA bit is set
  if (pusch_pdu->pdu_bit_map & PUSCH_PDU_BITMAP_PUSCH_DATA) {
    // pack optional TLVs
    if (!(push8(pusch_pdu->pusch_data.rv_index, ppWritePackedMsg, end)
          && push8(pusch_pdu->pusch_data.harq_process_id, ppWritePackedMsg, end)
          && push8(pusch_pdu->pusch_data.new_data_indicator, ppWritePackedMsg, end)
          && push32(pusch_pdu->pusch_data.tb_size, ppWritePackedMsg, end)
          && push16(pusch_pdu->pusch_data.num_cb, ppWritePackedMsg, end)
          && pusharray8(pusch_pdu->pusch_data.cb_present_and_position,
                        (pusch_pdu->pusch_data.num_cb + 7) / 8,
                        (pusch_pdu->pusch_data.num_cb + 7) / 8,
                        ppWritePackedMsg,
                        end))) {
      return 0;
    }
  }

  // Check if PUSCH_PDU_BITMAP_PUSCH_UCI bit is set
  if (pusch_pdu->pdu_bit_map & PUSCH_PDU_BITMAP_PUSCH_UCI) {
    if (!(push16(pusch_pdu->pusch_uci.harq_ack_bit_length, ppWritePackedMsg, end)
          && push16(pusch_pdu->pusch_uci.csi_part1_bit_length, ppWritePackedMsg, end)
          && push16(pusch_pdu->pusch_uci.csi_part2_bit_length, ppWritePackedMsg, end)
          && push8(pusch_pdu->pusch_uci.alpha_scaling, ppWritePackedMsg, end)
          && push8(pusch_pdu->pusch_uci.beta_offset_harq_ack, ppWritePackedMsg, end)
          && push8(pusch_pdu->pusch_uci.beta_offset_csi1, ppWritePackedMsg, end)
          && push8(pusch_pdu->pusch_uci.beta_offset_csi2, ppWritePackedMsg, end))) {
      return 0;
    }
  }

  // Check if PUSCH_PDU_BITMAP_PUSCH_PTRS bit is set
  if (pusch_pdu->pdu_bit_map & PUSCH_PDU_BITMAP_PUSCH_PTRS) {
    if (!push8(pusch_pdu->pusch_ptrs.num_ptrs_ports, ppWritePackedMsg, end)) {
      return 0;
    }
    for (int i = 0; i < pusch_pdu->pusch_ptrs.num_ptrs_ports; ++i) {
      if (!(push16(pusch_pdu->pusch_ptrs.ptrs_ports_list[i].ptrs_port_index, ppWritePackedMsg, end)
            && push8(pusch_pdu->pusch_ptrs.ptrs_ports_list[i].ptrs_dmrs_port, ppWritePackedMsg, end)
            && push8(pusch_pdu->pusch_ptrs.ptrs_ports_list[i].ptrs_re_offset, ppWritePackedMsg, end))) {
        return 0;
      }
    }

    if (!(push8(pusch_pdu->pusch_ptrs.ptrs_time_density, ppWritePackedMsg, end)
          && push8(pusch_pdu->pusch_ptrs.ptrs_freq_density, ppWritePackedMsg, end)
          && push8(pusch_pdu->pusch_ptrs.ul_ptrs_power, ppWritePackedMsg, end))) {
      return 0;
    }
  }

  // Check if PUSCH_PDU_BITMAP_DFTS_OFDM bit is set
  if (pusch_pdu->pdu_bit_map & PUSCH_PDU_BITMAP_DFTS_OFDM) {
    if (!(push8(pusch_pdu->dfts_ofdm.low_papr_group_number, ppWritePackedMsg, end)
          && push16(pusch_pdu->dfts_ofdm.low_papr_sequence_number, ppWritePackedMsg, end)
          && push8(pusch_pdu->dfts_ofdm.ul_ptrs_sample_density, ppWritePackedMsg, end)
          && push8(pusch_pdu->dfts_ofdm.ul_ptrs_time_density_transform_precoding, ppWritePackedMsg, end))) {
      return 0;
    }
  }

  // Pack RX Beamforming PDU
  if (!(pack_nr_rx_beamforming_pdu(&pusch_pdu->beamforming, ppWritePackedMsg, end))) {
    return 0;
  }
  if (!(push8(pusch_pdu->maintenance_parms_v3.ldpcBaseGraph, ppWritePackedMsg, end)
        && push32(pusch_pdu->maintenance_parms_v3.tbSizeLbrmBytes, ppWritePackedMsg, end)))
    return 0;
  return 1;
}

static uint8_t pack_ul_tti_request_pucch_pdu(nfapi_nr_pucch_pdu_t *pucch_pdu, uint8_t **ppWritePackedMsg, uint8_t *end)
{
  if (!(push16(pucch_pdu->rnti, ppWritePackedMsg, end) && push32(pucch_pdu->handle, ppWritePackedMsg, end)
        && push16(pucch_pdu->bwp_size, ppWritePackedMsg, end) && push16(pucch_pdu->bwp_start, ppWritePackedMsg, end)
        && push8(pucch_pdu->subcarrier_spacing, ppWritePackedMsg, end) && push8(pucch_pdu->cyclic_prefix, ppWritePackedMsg, end)
        && push8(pucch_pdu->format_type, ppWritePackedMsg, end) && push8(pucch_pdu->multi_slot_tx_indicator, ppWritePackedMsg, end)
        && push8(pucch_pdu->pi_2bpsk, ppWritePackedMsg, end) && push16(pucch_pdu->prb_start, ppWritePackedMsg, end)
        && push16(pucch_pdu->prb_size, ppWritePackedMsg, end) && push8(pucch_pdu->start_symbol_index, ppWritePackedMsg, end)
        && push8(pucch_pdu->nr_of_symbols, ppWritePackedMsg, end) && push8(pucch_pdu->freq_hop_flag, ppWritePackedMsg, end)
        && push16(pucch_pdu->second_hop_prb, ppWritePackedMsg, end) && push8(pucch_pdu->group_hop_flag, ppWritePackedMsg, end)
        && push8(pucch_pdu->sequence_hop_flag, ppWritePackedMsg, end) && push16(pucch_pdu->hopping_id, ppWritePackedMsg, end)
        && push16(pucch_pdu->initial_cyclic_shift, ppWritePackedMsg, end)
        && push16(pucch_pdu->data_scrambling_id, ppWritePackedMsg, end)
        && push8(pucch_pdu->time_domain_occ_idx, ppWritePackedMsg, end) && push8(pucch_pdu->pre_dft_occ_idx, ppWritePackedMsg, end)
        && push8(pucch_pdu->pre_dft_occ_len, ppWritePackedMsg, end) && push8(pucch_pdu->add_dmrs_flag, ppWritePackedMsg, end)
        && push16(pucch_pdu->dmrs_scrambling_id, ppWritePackedMsg, end)
        && push8(pucch_pdu->dmrs_cyclic_shift, ppWritePackedMsg, end) && push8(pucch_pdu->sr_flag, ppWritePackedMsg, end)
        && push16(pucch_pdu->bit_len_harq, ppWritePackedMsg, end) && push16(pucch_pdu->bit_len_csi_part1, ppWritePackedMsg, end)
        && push16(pucch_pdu->bit_len_csi_part2, ppWritePackedMsg, end))) {
    return 0;
  }

  return pack_nr_rx_beamforming_pdu(&pucch_pdu->beamforming, ppWritePackedMsg, end);
}

static uint8_t pack_ul_tti_request_srs_pdu(nfapi_nr_srs_pdu_t *srs_pdu, uint8_t **ppWritePackedMsg, uint8_t *end)
{
  if (!(push16(srs_pdu->rnti, ppWritePackedMsg, end) && push32(srs_pdu->handle, ppWritePackedMsg, end)
        && push16(srs_pdu->bwp_size, ppWritePackedMsg, end) && push16(srs_pdu->bwp_start, ppWritePackedMsg, end)
        && push8(srs_pdu->subcarrier_spacing, ppWritePackedMsg, end) && push8(srs_pdu->cyclic_prefix, ppWritePackedMsg, end)
        && push8(srs_pdu->num_ant_ports, ppWritePackedMsg, end) && push8(srs_pdu->num_symbols, ppWritePackedMsg, end)
        && push8(srs_pdu->num_repetitions, ppWritePackedMsg, end) && push8(srs_pdu->time_start_position, ppWritePackedMsg, end)
        && push8(srs_pdu->config_index, ppWritePackedMsg, end) && push16(srs_pdu->sequence_id, ppWritePackedMsg, end)
        && push8(srs_pdu->bandwidth_index, ppWritePackedMsg, end) && push8(srs_pdu->comb_size, ppWritePackedMsg, end)
        && push8(srs_pdu->comb_offset, ppWritePackedMsg, end) && push8(srs_pdu->cyclic_shift, ppWritePackedMsg, end)
        && push8(srs_pdu->frequency_position, ppWritePackedMsg, end) && push16(srs_pdu->frequency_shift, ppWritePackedMsg, end)
        && push8(srs_pdu->frequency_hopping, ppWritePackedMsg, end)
        && push8(srs_pdu->group_or_sequence_hopping, ppWritePackedMsg, end) && push8(srs_pdu->resource_type, ppWritePackedMsg, end)
        && push16(srs_pdu->t_srs, ppWritePackedMsg, end) && push16(srs_pdu->t_offset, ppWritePackedMsg, end))) {
    return 0;
  }
  return pack_nr_rx_beamforming_pdu(&srs_pdu->beamforming, ppWritePackedMsg, end);
}

static uint8_t pack_ul_tti_pdu_list_value(void *tlv, uint8_t **ppWritePackedMsg, uint8_t *end)
{
  nfapi_nr_ul_tti_request_number_of_pdus_t *value = (nfapi_nr_ul_tti_request_number_of_pdus_t *)tlv;
  uintptr_t msgHead = (uintptr_t)*ppWritePackedMsg;
  if (!push16(value->pdu_type, ppWritePackedMsg, end)) {
    return 0;
  }
  uint8_t *pPackedLengthField = *ppWritePackedMsg;

  if (!push16(value->pdu_size, ppWritePackedMsg, end))
    return 0;
  // pack PDUs
  //  first match the pdu type, then call the respective function
  switch (value->pdu_type) {
    case NFAPI_NR_UL_CONFIG_PRACH_PDU_TYPE: {
      if (!pack_ul_tti_request_prach_pdu(&value->prach_pdu, ppWritePackedMsg, end))
        return 0;
    } break;

    case NFAPI_NR_UL_CONFIG_PUSCH_PDU_TYPE: {
      if (!pack_ul_tti_request_pusch_pdu(&value->pusch_pdu, ppWritePackedMsg, end))
        return 0;
    } break;

    case NFAPI_NR_UL_CONFIG_PUCCH_PDU_TYPE: {
      if (!pack_ul_tti_request_pucch_pdu(&value->pucch_pdu, ppWritePackedMsg, end))
        return 0;
    } break;

    case NFAPI_NR_UL_CONFIG_SRS_PDU_TYPE: {
      if (!pack_ul_tti_request_srs_pdu(&value->srs_pdu, ppWritePackedMsg, end))
        return 0;
    } break;

    default: {
      NFAPI_TRACE(NFAPI_TRACE_ERROR, "FIXME : Invalid UL_TTI pdu type %d \n", value->pdu_type);
    } break;
  }

  // pack proper size
  uintptr_t msgEnd = (uintptr_t)*ppWritePackedMsg;
  uint16_t packedMsgLen = msgEnd - msgHead;
  value->pdu_size = packedMsgLen;
  return push16(value->pdu_size, &pPackedLengthField, end);
}

static uint8_t pack_ul_tti_groups_list_value(void *tlv, uint8_t **ppWritePackedMsg, uint8_t *end)
{
  nfapi_nr_ul_tti_request_number_of_groups_t *value = (nfapi_nr_ul_tti_request_number_of_groups_t *)tlv;

  if (!push8(value->n_ue, ppWritePackedMsg, end))
    return 0;

  for (int i = 0; i < value->n_ue; i++) {
    if (!push8(value->ue_list[i].pdu_idx, ppWritePackedMsg, end))
      return 0;
  }

  return 1;
}

uint8_t pack_ul_tti_request(void *msg, uint8_t **ppWritePackedMsg, uint8_t *end, nfapi_p7_codec_config_t *config)
{
  nfapi_nr_ul_tti_request_t *pNfapiMsg = (nfapi_nr_ul_tti_request_t *)msg;
  pNfapiMsg->n_ulcch = 0;
  pNfapiMsg->n_ulsch = 0;
  for (int i = 0; i < pNfapiMsg->n_pdus; i++) {
    switch ((&pNfapiMsg->pdus_list[i])->pdu_type) {
      case NFAPI_NR_UL_CONFIG_PUCCH_PDU_TYPE: {
        pNfapiMsg->n_ulcch++;
      } break;
      case NFAPI_NR_UL_CONFIG_PUSCH_PDU_TYPE: {
        pNfapiMsg->n_ulsch++;
      } break;
      default:
        break;
    }
  }
  if (!push16(pNfapiMsg->SFN, ppWritePackedMsg, end))
    return 0;
  if (!push16(pNfapiMsg->Slot, ppWritePackedMsg, end))
    return 0;
  if (!push8(pNfapiMsg->n_pdus, ppWritePackedMsg, end))
    return 0;
  if (!push8(pNfapiMsg->rach_present, ppWritePackedMsg, end))
    return 0;
  if (!push8(pNfapiMsg->n_ulsch, ppWritePackedMsg, end))
    return 0;
  if (!push8(pNfapiMsg->n_ulcch, ppWritePackedMsg, end))
    return 0;
  if (!push8(pNfapiMsg->n_group, ppWritePackedMsg, end))
    return 0;

  for (int i = 0; i < pNfapiMsg->n_pdus; i++) {
    if (!pack_ul_tti_pdu_list_value(&pNfapiMsg->pdus_list[i], ppWritePackedMsg, end))
      return 0;
  }

  for (int i = 0; i < pNfapiMsg->n_group; i++) {
    if (!pack_ul_tti_groups_list_value(&pNfapiMsg->groups_list[i], ppWritePackedMsg, end))
      return 0;
  }

  return 1;
}

static uint8_t unpack_nr_rx_beamforming_pdu(nfapi_nr_ul_beamforming_t *beamforming_pdu, uint8_t **ppReadPackedMsg, uint8_t *end)
{ // Unpack RX Beamforming PDU
  if (!(pull16(ppReadPackedMsg, &beamforming_pdu->num_prgs, end) && pull16(ppReadPackedMsg, &beamforming_pdu->prg_size, end)
        && pull8(ppReadPackedMsg, &beamforming_pdu->dig_bf_interface, end))) {
    return 0;
  }

  if (beamforming_pdu->num_prgs > 0 && beamforming_pdu->dig_bf_interface > 0) {
    beamforming_pdu->prgs_list = calloc(beamforming_pdu->num_prgs, sizeof(*beamforming_pdu->prgs_list));
    if (!beamforming_pdu->prgs_list) {
      return 0; // Handle memory allocation failure
    }

    for (int prg_idx = 0; prg_idx < beamforming_pdu->num_prgs; prg_idx++) {
      beamforming_pdu->prgs_list[prg_idx].dig_bf_interface_list =
          calloc(beamforming_pdu->dig_bf_interface, sizeof(*beamforming_pdu->prgs_list[0].dig_bf_interface_list));
      if (!beamforming_pdu->prgs_list[prg_idx].dig_bf_interface_list) {
        // Free previously allocated memory
        for (int i = 0; i < prg_idx; i++) {
          free(beamforming_pdu->prgs_list[i].dig_bf_interface_list);
        }
        free(beamforming_pdu->prgs_list);
        return 0;
      }
    }
  }

  for (int prg = 0; prg < beamforming_pdu->num_prgs; prg++) {
    for (int digBFInterface = 0; digBFInterface < beamforming_pdu->dig_bf_interface; digBFInterface++) {
      if (!pull16(ppReadPackedMsg, &beamforming_pdu->prgs_list[prg].dig_bf_interface_list[digBFInterface].beam_idx, end)) {
        return 0;
      }
    }
  }
  return 1;
}

static uint8_t unpack_ul_tti_request_prach_pdu(nfapi_nr_prach_pdu_t *prach_pdu, uint8_t **ppReadPackedMsg, uint8_t *end)
{
  if (!(pull16(ppReadPackedMsg, &prach_pdu->phys_cell_id, end) && pull8(ppReadPackedMsg, &prach_pdu->num_prach_ocas, end)
        && pull8(ppReadPackedMsg, &prach_pdu->prach_format, end) && pull8(ppReadPackedMsg, &prach_pdu->num_ra, end)
        && pull8(ppReadPackedMsg, &prach_pdu->prach_start_symbol, end) && pull16(ppReadPackedMsg, &prach_pdu->num_cs, end))) {
    return 0;
  }

  return unpack_nr_rx_beamforming_pdu(&prach_pdu->beamforming, ppReadPackedMsg, end);
}

static uint8_t unpack_ul_tti_request_pusch_pdu(nfapi_nr_pusch_pdu_t *pusch_pdu, uint8_t **ppReadPackedMsg, uint8_t *end)
{
  if (!(pull16(ppReadPackedMsg, &pusch_pdu->pdu_bit_map, end) && pull16(ppReadPackedMsg, &pusch_pdu->rnti, end)
        && pull32(ppReadPackedMsg, &pusch_pdu->handle, end) && pull16(ppReadPackedMsg, &pusch_pdu->bwp_size, end)
        && pull16(ppReadPackedMsg, &pusch_pdu->bwp_start, end) && pull8(ppReadPackedMsg, &pusch_pdu->subcarrier_spacing, end)
        && pull8(ppReadPackedMsg, &pusch_pdu->cyclic_prefix, end) && pull16(ppReadPackedMsg, &pusch_pdu->target_code_rate, end)
        && pull8(ppReadPackedMsg, &pusch_pdu->qam_mod_order, end) && pull8(ppReadPackedMsg, &pusch_pdu->mcs_index, end)
        && pull8(ppReadPackedMsg, &pusch_pdu->mcs_table, end) && pull8(ppReadPackedMsg, &pusch_pdu->transform_precoding, end)
        && pull16(ppReadPackedMsg, &pusch_pdu->data_scrambling_id, end) && pull8(ppReadPackedMsg, &pusch_pdu->nrOfLayers, end)
        && pull16(ppReadPackedMsg, &pusch_pdu->ul_dmrs_symb_pos, end) && pull8(ppReadPackedMsg, &pusch_pdu->dmrs_config_type, end)
        && pull16(ppReadPackedMsg, &pusch_pdu->ul_dmrs_scrambling_id, end)
        && pull16(ppReadPackedMsg, &pusch_pdu->pusch_identity, end) && pull8(ppReadPackedMsg, &pusch_pdu->scid, end)
        && pull8(ppReadPackedMsg, &pusch_pdu->num_dmrs_cdm_grps_no_data, end)
        && pull16(ppReadPackedMsg, &pusch_pdu->dmrs_ports, end) && pull8(ppReadPackedMsg, &pusch_pdu->resource_alloc, end)
        && pullarray8(ppReadPackedMsg, pusch_pdu->rb_bitmap, 36, 36, end) && pull16(ppReadPackedMsg, &pusch_pdu->rb_start, end)
        && pull16(ppReadPackedMsg, &pusch_pdu->rb_size, end) && pull8(ppReadPackedMsg, &pusch_pdu->vrb_to_prb_mapping, end)
        && pull8(ppReadPackedMsg, &pusch_pdu->frequency_hopping, end)
        && pull16(ppReadPackedMsg, &pusch_pdu->tx_direct_current_location, end)
        && pull8(ppReadPackedMsg, &pusch_pdu->uplink_frequency_shift_7p5khz, end)
        && pull8(ppReadPackedMsg, &pusch_pdu->start_symbol_index, end) && pull8(ppReadPackedMsg, &pusch_pdu->nr_of_symbols, end)))
    return 0;

  // Unpack Optional Data only included if indicated in pduBitmap
  // Check if PUSCH_PDU_BITMAP_PUSCH_DATA bit is set
  if (pusch_pdu->pdu_bit_map & PUSCH_PDU_BITMAP_PUSCH_DATA) {
    // pack optional TLVs
    if (!(pull8(ppReadPackedMsg, &pusch_pdu->pusch_data.rv_index, end)
          && pull8(ppReadPackedMsg, &pusch_pdu->pusch_data.harq_process_id, end)
          && pull8(ppReadPackedMsg, &pusch_pdu->pusch_data.new_data_indicator, end)
          && pull32(ppReadPackedMsg, &pusch_pdu->pusch_data.tb_size, end)
          && pull16(ppReadPackedMsg, &pusch_pdu->pusch_data.num_cb, end)
          && pullarray8(ppReadPackedMsg,
                        pusch_pdu->pusch_data.cb_present_and_position,
                        (pusch_pdu->pusch_data.num_cb + 7) / 8,
                        (pusch_pdu->pusch_data.num_cb + 7) / 8,
                        end))) {
      return 0;
    }
  }
  // Check if PUSCH_PDU_BITMAP_PUSCH_UCI bit is set
  if (pusch_pdu->pdu_bit_map & PUSCH_PDU_BITMAP_PUSCH_UCI) {
    if (!(pull16(ppReadPackedMsg, &pusch_pdu->pusch_uci.harq_ack_bit_length, end)
          && pull16(ppReadPackedMsg, &pusch_pdu->pusch_uci.csi_part1_bit_length, end)
          && pull16(ppReadPackedMsg, &pusch_pdu->pusch_uci.csi_part2_bit_length, end)
          && pull8(ppReadPackedMsg, &pusch_pdu->pusch_uci.alpha_scaling, end)
          && pull8(ppReadPackedMsg, &pusch_pdu->pusch_uci.beta_offset_harq_ack, end)
          && pull8(ppReadPackedMsg, &pusch_pdu->pusch_uci.beta_offset_csi1, end)
          && pull8(ppReadPackedMsg, &pusch_pdu->pusch_uci.beta_offset_csi2, end))) {
      return 0;
    }
  }

  // Check if PUSCH_PDU_BITMAP_PUSCH_PTRS bit is set
  if (pusch_pdu->pdu_bit_map & PUSCH_PDU_BITMAP_PUSCH_PTRS) {
    if (!(pull8(ppReadPackedMsg, &pusch_pdu->pusch_ptrs.num_ptrs_ports, end))) {
      return 0;
    }
    pusch_pdu->pusch_ptrs.ptrs_ports_list = calloc(pusch_pdu->pusch_ptrs.num_ptrs_ports, sizeof(nfapi_nr_ptrs_ports_t));
    for (int ptrs_port = 0; ptrs_port < pusch_pdu->pusch_ptrs.num_ptrs_ports; ++ptrs_port) {
      if (!(pull16(ppReadPackedMsg, &pusch_pdu->pusch_ptrs.ptrs_ports_list[ptrs_port].ptrs_port_index, end)
            && pull8(ppReadPackedMsg, &pusch_pdu->pusch_ptrs.ptrs_ports_list[ptrs_port].ptrs_dmrs_port, end)
            && pull8(ppReadPackedMsg, &pusch_pdu->pusch_ptrs.ptrs_ports_list[ptrs_port].ptrs_re_offset, end))) {
        return 0;
      }
    }
    if (!(pull8(ppReadPackedMsg, &pusch_pdu->pusch_ptrs.ptrs_time_density, end)
          && pull8(ppReadPackedMsg, &pusch_pdu->pusch_ptrs.ptrs_freq_density, end)
          && pull8(ppReadPackedMsg, &pusch_pdu->pusch_ptrs.ul_ptrs_power, end))) {
      return 0;
    }
  }

  // Check if PUSCH_PDU_BITMAP_DFTS_OFDM bit is set
  if (pusch_pdu->pdu_bit_map & PUSCH_PDU_BITMAP_DFTS_OFDM) {
    if (!(pull8(ppReadPackedMsg, &pusch_pdu->dfts_ofdm.low_papr_group_number, end)
          && pull16(ppReadPackedMsg, &pusch_pdu->dfts_ofdm.low_papr_sequence_number, end)
          && pull8(ppReadPackedMsg, &pusch_pdu->dfts_ofdm.ul_ptrs_sample_density, end)
          && pull8(ppReadPackedMsg, &pusch_pdu->dfts_ofdm.ul_ptrs_time_density_transform_precoding, end))) {
      return 0;
    }
  }

  if (!(unpack_nr_rx_beamforming_pdu(&pusch_pdu->beamforming, ppReadPackedMsg, end))) {
    return 0;
  }

  if (!(pull8(ppReadPackedMsg, &pusch_pdu->maintenance_parms_v3.ldpcBaseGraph, end)
        && pull32(ppReadPackedMsg, &pusch_pdu->maintenance_parms_v3.tbSizeLbrmBytes, end)))
    return 0;

  return 1;
}

static uint8_t unpack_ul_tti_request_pucch_pdu(nfapi_nr_pucch_pdu_t *pucch_pdu, uint8_t **ppReadPackedMsg, uint8_t *end)
{
  if (!(pull16(ppReadPackedMsg, &pucch_pdu->rnti, end) && pull32(ppReadPackedMsg, &pucch_pdu->handle, end)
        && pull16(ppReadPackedMsg, &pucch_pdu->bwp_size, end) && pull16(ppReadPackedMsg, &pucch_pdu->bwp_start, end)
        && pull8(ppReadPackedMsg, &pucch_pdu->subcarrier_spacing, end) && pull8(ppReadPackedMsg, &pucch_pdu->cyclic_prefix, end)
        && pull8(ppReadPackedMsg, &pucch_pdu->format_type, end) && pull8(ppReadPackedMsg, &pucch_pdu->multi_slot_tx_indicator, end)
        && pull8(ppReadPackedMsg, &pucch_pdu->pi_2bpsk, end) && pull16(ppReadPackedMsg, &pucch_pdu->prb_start, end)
        && pull16(ppReadPackedMsg, &pucch_pdu->prb_size, end) && pull8(ppReadPackedMsg, &pucch_pdu->start_symbol_index, end)
        && pull8(ppReadPackedMsg, &pucch_pdu->nr_of_symbols, end) && pull8(ppReadPackedMsg, &pucch_pdu->freq_hop_flag, end)
        && pull16(ppReadPackedMsg, &pucch_pdu->second_hop_prb, end) && pull8(ppReadPackedMsg, &pucch_pdu->group_hop_flag, end)
        && pull8(ppReadPackedMsg, &pucch_pdu->sequence_hop_flag, end) && pull16(ppReadPackedMsg, &pucch_pdu->hopping_id, end)
        && pull16(ppReadPackedMsg, &pucch_pdu->initial_cyclic_shift, end)
        && pull16(ppReadPackedMsg, &pucch_pdu->data_scrambling_id, end)
        && pull8(ppReadPackedMsg, &pucch_pdu->time_domain_occ_idx, end) && pull8(ppReadPackedMsg, &pucch_pdu->pre_dft_occ_idx, end)
        && pull8(ppReadPackedMsg, &pucch_pdu->pre_dft_occ_len, end) && pull8(ppReadPackedMsg, &pucch_pdu->add_dmrs_flag, end)
        && pull16(ppReadPackedMsg, &pucch_pdu->dmrs_scrambling_id, end)
        && pull8(ppReadPackedMsg, &pucch_pdu->dmrs_cyclic_shift, end) && pull8(ppReadPackedMsg, &pucch_pdu->sr_flag, end)
        && pull16(ppReadPackedMsg, &pucch_pdu->bit_len_harq, end) && pull16(ppReadPackedMsg, &pucch_pdu->bit_len_csi_part1, end)
        && pull16(ppReadPackedMsg, &pucch_pdu->bit_len_csi_part2, end))) {
    return 0;
  }
  return unpack_nr_rx_beamforming_pdu(&pucch_pdu->beamforming, ppReadPackedMsg, end);
}

static uint8_t unpack_ul_tti_request_srs_pdu(nfapi_nr_srs_pdu_t *srs_pdu, uint8_t **ppReadPackedMsg, uint8_t *end)
{
  if (!(pull16(ppReadPackedMsg, &srs_pdu->rnti, end) && pull32(ppReadPackedMsg, &srs_pdu->handle, end)
        && pull16(ppReadPackedMsg, &srs_pdu->bwp_size, end) && pull16(ppReadPackedMsg, &srs_pdu->bwp_start, end)
        && pull8(ppReadPackedMsg, &srs_pdu->subcarrier_spacing, end) && pull8(ppReadPackedMsg, &srs_pdu->cyclic_prefix, end)
        && pull8(ppReadPackedMsg, &srs_pdu->num_ant_ports, end) && pull8(ppReadPackedMsg, &srs_pdu->num_symbols, end)
        && pull8(ppReadPackedMsg, &srs_pdu->num_repetitions, end) && pull8(ppReadPackedMsg, &srs_pdu->time_start_position, end)
        && pull8(ppReadPackedMsg, &srs_pdu->config_index, end) && pull16(ppReadPackedMsg, &srs_pdu->sequence_id, end)
        && pull8(ppReadPackedMsg, &srs_pdu->bandwidth_index, end) && pull8(ppReadPackedMsg, &srs_pdu->comb_size, end)
        && pull8(ppReadPackedMsg, &srs_pdu->comb_offset, end) && pull8(ppReadPackedMsg, &srs_pdu->cyclic_shift, end)
        && pull8(ppReadPackedMsg, &srs_pdu->frequency_position, end) && pull16(ppReadPackedMsg, &srs_pdu->frequency_shift, end)
        && pull8(ppReadPackedMsg, &srs_pdu->frequency_hopping, end)
        && pull8(ppReadPackedMsg, &srs_pdu->group_or_sequence_hopping, end) && pull8(ppReadPackedMsg, &srs_pdu->resource_type, end)
        && pull16(ppReadPackedMsg, &srs_pdu->t_srs, end) && pull16(ppReadPackedMsg, &srs_pdu->t_offset, end))) {
    return 0;
  }
  return unpack_nr_rx_beamforming_pdu(&srs_pdu->beamforming, ppReadPackedMsg, end);
}

static uint8_t unpack_ul_tti_pdu_list_value(uint8_t **ppReadPackedMsg, uint8_t *end, void *msg)
{
  nfapi_nr_ul_tti_request_number_of_pdus_t *pNfapiMsg = (nfapi_nr_ul_tti_request_number_of_pdus_t *)msg;

  if (!(pull16(ppReadPackedMsg, &pNfapiMsg->pdu_type, end) && pull16(ppReadPackedMsg, &pNfapiMsg->pdu_size, end)))
    return 0;

  // first natch the pdu type, then call the respective function
  switch (pNfapiMsg->pdu_type) {
    case NFAPI_NR_UL_CONFIG_PRACH_PDU_TYPE: {
      if (!unpack_ul_tti_request_prach_pdu(&pNfapiMsg->prach_pdu, ppReadPackedMsg, end))
        return 0;
    } break;

    case NFAPI_NR_UL_CONFIG_PUSCH_PDU_TYPE: {
      if (!unpack_ul_tti_request_pusch_pdu(&pNfapiMsg->pusch_pdu, ppReadPackedMsg, end))
        return 0;
    } break;

    case NFAPI_NR_UL_CONFIG_PUCCH_PDU_TYPE: {
      if (!unpack_ul_tti_request_pucch_pdu(&pNfapiMsg->pucch_pdu, ppReadPackedMsg, end))
        return 0;
    } break;

    case NFAPI_NR_UL_CONFIG_SRS_PDU_TYPE: {
      if (!unpack_ul_tti_request_srs_pdu(&pNfapiMsg->srs_pdu, ppReadPackedMsg, end))
        return 0;
    } break;

    default: {
      NFAPI_TRACE(NFAPI_TRACE_ERROR, "FIXME : Invalid UL_TTI pdu type %d \n", pNfapiMsg->pdu_type);
    } break;
  }

  return 1;
}

static uint8_t unpack_ul_tti_groups_list_value(uint8_t **ppReadPackedMsg, uint8_t *end, void *msg)
{
  nfapi_nr_ul_tti_request_number_of_groups_t *pNfapiMsg = (nfapi_nr_ul_tti_request_number_of_groups_t *)msg;

  if (!pull8(ppReadPackedMsg, &pNfapiMsg->n_ue, end))
    return 0;

  for (int i = 0; i < pNfapiMsg->n_ue; i++) {
    if (!pull8(ppReadPackedMsg, &pNfapiMsg->ue_list[i].pdu_idx, end))
      return 0;
  }

  return 1;
}

uint8_t unpack_ul_tti_request(uint8_t **ppReadPackedMsg, uint8_t *end, void *msg, nfapi_p7_codec_config_t *config)
{
  nfapi_nr_ul_tti_request_t *pNfapiMsg = (nfapi_nr_ul_tti_request_t *)msg;

  if (!pull16(ppReadPackedMsg, &pNfapiMsg->SFN, end))
    return 0;
  if (!pull16(ppReadPackedMsg, &pNfapiMsg->Slot, end))
    return 0;
  if (!pull8(ppReadPackedMsg, &pNfapiMsg->n_pdus, end))
    return 0;
  if (!pull8(ppReadPackedMsg, &pNfapiMsg->rach_present, end))
    return 0;
  if (!pull8(ppReadPackedMsg, &pNfapiMsg->n_ulsch, end))
    return 0;
  if (!pull8(ppReadPackedMsg, &pNfapiMsg->n_ulcch, end))
    return 0;
  if (!pull8(ppReadPackedMsg, &pNfapiMsg->n_group, end))
    return 0;
  for (int i = 0; i < pNfapiMsg->n_pdus; i++) {
    if (!unpack_ul_tti_pdu_list_value(ppReadPackedMsg, end, &pNfapiMsg->pdus_list[i]))
      return 0;
  }

  for (int i = 0; i < pNfapiMsg->n_group; i++) {
    if (!unpack_ul_tti_groups_list_value(ppReadPackedMsg, end, &pNfapiMsg->groups_list[i]))
      return 0;
  }

  return 1;
}

uint8_t pack_nr_slot_indication(void *msg, uint8_t **ppWritePackedMsg, uint8_t *end, nfapi_p7_codec_config_t *config)
{
  nfapi_nr_slot_indication_scf_t *pNfapiMsg = (nfapi_nr_slot_indication_scf_t *)msg;

  if (!(push16(pNfapiMsg->sfn, ppWritePackedMsg, end) && push16(pNfapiMsg->slot, ppWritePackedMsg, end)))
    return 0;

  return 1;
}

uint8_t unpack_nr_slot_indication(uint8_t **ppReadPackedMsg,
                                  uint8_t *end,
                                  nfapi_nr_slot_indication_scf_t *msg,
                                  nfapi_p7_codec_config_t *config)
{
  nfapi_nr_slot_indication_scf_t *pNfapiMsg = (nfapi_nr_slot_indication_scf_t *)msg;

  if (!(pull16(ppReadPackedMsg, &pNfapiMsg->sfn, end) && pull16(ppReadPackedMsg, &pNfapiMsg->slot, end)))
    return 0;

  return 1;
}

static uint8_t pack_ul_dci_pdu_list_value(void *tlv, uint8_t **ppWritePackedMsg, uint8_t *end)
{
  nfapi_nr_ul_dci_request_pdus_t *value = (nfapi_nr_ul_dci_request_pdus_t *)tlv;
  uintptr_t msgHead = (uintptr_t)*ppWritePackedMsg;
  if (!push16(value->PDUType, ppWritePackedMsg, end)) {
    return 0;
  }
  uint8_t *pPackedLengthField = *ppWritePackedMsg;
  if (!(push16(value->PDUSize, ppWritePackedMsg, end) && push16(value->pdcch_pdu.pdcch_pdu_rel15.BWPSize, ppWritePackedMsg, end)
        && push16(value->pdcch_pdu.pdcch_pdu_rel15.BWPStart, ppWritePackedMsg, end)
        && push8(value->pdcch_pdu.pdcch_pdu_rel15.SubcarrierSpacing, ppWritePackedMsg, end)
        && push8(value->pdcch_pdu.pdcch_pdu_rel15.CyclicPrefix, ppWritePackedMsg, end)
        && push8(value->pdcch_pdu.pdcch_pdu_rel15.StartSymbolIndex, ppWritePackedMsg, end)
        && push8(value->pdcch_pdu.pdcch_pdu_rel15.DurationSymbols, ppWritePackedMsg, end)
        && pusharray8(value->pdcch_pdu.pdcch_pdu_rel15.FreqDomainResource, 6, 6, ppWritePackedMsg, end)
        && push8(value->pdcch_pdu.pdcch_pdu_rel15.CceRegMappingType, ppWritePackedMsg, end)
        && push8(value->pdcch_pdu.pdcch_pdu_rel15.RegBundleSize, ppWritePackedMsg, end)
        && push8(value->pdcch_pdu.pdcch_pdu_rel15.InterleaverSize, ppWritePackedMsg, end)
        && push8(value->pdcch_pdu.pdcch_pdu_rel15.CoreSetType, ppWritePackedMsg, end)
        && push16(value->pdcch_pdu.pdcch_pdu_rel15.ShiftIndex, ppWritePackedMsg, end)
        && push8(value->pdcch_pdu.pdcch_pdu_rel15.precoderGranularity, ppWritePackedMsg, end)
        && push16(value->pdcch_pdu.pdcch_pdu_rel15.numDlDci, ppWritePackedMsg, end))) {
    return 0;
  }
  for (int i = 0; i < value->pdcch_pdu.pdcch_pdu_rel15.numDlDci; ++i) {
    nfapi_nr_dl_dci_pdu_t *dci_pdu = &value->pdcch_pdu.pdcch_pdu_rel15.dci_pdu[i];
    if (!(push16(dci_pdu->RNTI, ppWritePackedMsg, end) && push16(dci_pdu->ScramblingId, ppWritePackedMsg, end)
          && push16(dci_pdu->ScramblingRNTI, ppWritePackedMsg, end) && push8(dci_pdu->CceIndex, ppWritePackedMsg, end)
          && push8(dci_pdu->AggregationLevel, ppWritePackedMsg, end))) {
      return 0;
    }
    // Precoding and Beamforming
    nfapi_nr_tx_precoding_and_beamforming_t *beamforming = &dci_pdu->precodingAndBeamforming;
    if (!(push16(beamforming->num_prgs, ppWritePackedMsg, end) && push16(beamforming->prg_size, ppWritePackedMsg, end)
          && push8(beamforming->dig_bf_interfaces, ppWritePackedMsg, end))) {
      return 0;
    }
    for (int prg = 0; prg < beamforming->num_prgs; prg++) {
      if (!push16(beamforming->prgs_list[prg].pm_idx, ppWritePackedMsg, end)) {
        return 0;
      }
      for (int digInt = 0; digInt < beamforming->dig_bf_interfaces; digInt++) {
        if (!push16(beamforming->prgs_list[prg].dig_bf_interface_list[digInt].beam_idx, ppWritePackedMsg, end)) {
          return 0;
        }
      }
    }
    if (!(push8(dci_pdu->beta_PDCCH_1_0, ppWritePackedMsg, end) && push8(dci_pdu->powerControlOffsetSS, ppWritePackedMsg, end) &&
          // DCI Payload fields
          push16(dci_pdu->PayloadSizeBits, ppWritePackedMsg, end) &&
          // Pack DCI Payload
          pack_dci_payload(dci_pdu->Payload, dci_pdu->PayloadSizeBits, ppWritePackedMsg, end))) {
      return 0;
    }
  }

  // pack proper size
  uintptr_t msgEnd = (uintptr_t)*ppWritePackedMsg;
  uint16_t packedMsgLen = msgEnd - msgHead;
  value->PDUSize = packedMsgLen;
  return push16(value->PDUSize, &pPackedLengthField, end);
}

uint8_t pack_ul_dci_request(void *msg, uint8_t **ppWritePackedMsg, uint8_t *end, nfapi_p7_codec_config_t *config)
{
  nfapi_nr_ul_dci_request_t *pNfapiMsg = (nfapi_nr_ul_dci_request_t *)msg;

  if (!(push16(pNfapiMsg->SFN, ppWritePackedMsg, end) && push16(pNfapiMsg->Slot, ppWritePackedMsg, end)
        && push8(pNfapiMsg->numPdus, ppWritePackedMsg, end)))
    return 0;

  for (int i = 0; i < pNfapiMsg->numPdus; i++) {
    if (!pack_ul_dci_pdu_list_value(&pNfapiMsg->ul_dci_pdu_list[i], ppWritePackedMsg, end))
      return 0;
  }

  return 1;
}

static uint8_t unpack_ul_dci_pdu_list_value(uint8_t **ppReadPackedMsg, uint8_t *end, void *msg)
{
  nfapi_nr_ul_dci_request_pdus_t *value = (nfapi_nr_ul_dci_request_pdus_t *)msg;

  if (!(pull16(ppReadPackedMsg, &value->PDUType, end) && pull16(ppReadPackedMsg, &value->PDUSize, end)
        && pull16(ppReadPackedMsg, &value->pdcch_pdu.pdcch_pdu_rel15.BWPSize, end)
        && pull16(ppReadPackedMsg, &value->pdcch_pdu.pdcch_pdu_rel15.BWPStart, end)
        && pull8(ppReadPackedMsg, &value->pdcch_pdu.pdcch_pdu_rel15.SubcarrierSpacing, end)
        && pull8(ppReadPackedMsg, &value->pdcch_pdu.pdcch_pdu_rel15.CyclicPrefix, end)
        && pull8(ppReadPackedMsg, &value->pdcch_pdu.pdcch_pdu_rel15.StartSymbolIndex, end)
        && pull8(ppReadPackedMsg, &value->pdcch_pdu.pdcch_pdu_rel15.DurationSymbols, end)
        && pullarray8(ppReadPackedMsg, value->pdcch_pdu.pdcch_pdu_rel15.FreqDomainResource, 6, 6, end)
        && pull8(ppReadPackedMsg, &value->pdcch_pdu.pdcch_pdu_rel15.CceRegMappingType, end)
        && pull8(ppReadPackedMsg, &value->pdcch_pdu.pdcch_pdu_rel15.RegBundleSize, end)
        && pull8(ppReadPackedMsg, &value->pdcch_pdu.pdcch_pdu_rel15.InterleaverSize, end)
        && pull8(ppReadPackedMsg, &value->pdcch_pdu.pdcch_pdu_rel15.CoreSetType, end)
        && pull16(ppReadPackedMsg, &value->pdcch_pdu.pdcch_pdu_rel15.ShiftIndex, end)
        && pull8(ppReadPackedMsg, &value->pdcch_pdu.pdcch_pdu_rel15.precoderGranularity, end)
        && pull16(ppReadPackedMsg, &value->pdcch_pdu.pdcch_pdu_rel15.numDlDci, end))) {
    return 0;
  }

  for (uint16_t i = 0; i < value->pdcch_pdu.pdcch_pdu_rel15.numDlDci; ++i) {
    nfapi_nr_dl_dci_pdu_t *dci_pdu = &value->pdcch_pdu.pdcch_pdu_rel15.dci_pdu[i];
    if (!(pull16(ppReadPackedMsg, &dci_pdu->RNTI, end) && pull16(ppReadPackedMsg, &dci_pdu->ScramblingId, end)
          && pull16(ppReadPackedMsg, &dci_pdu->ScramblingRNTI, end) && pull8(ppReadPackedMsg, &dci_pdu->CceIndex, end)
          && pull8(ppReadPackedMsg, &dci_pdu->AggregationLevel, end))) {
      return 0;
    }
    // Precoding and Beamforming
    nfapi_nr_tx_precoding_and_beamforming_t *beamforming = &dci_pdu->precodingAndBeamforming;
    if (!(pull16(ppReadPackedMsg, &beamforming->num_prgs, end) && pull16(ppReadPackedMsg, &beamforming->prg_size, end)
          && pull8(ppReadPackedMsg, &beamforming->dig_bf_interfaces, end))) {
      return 0;
    }

    for (int prg = 0; prg < beamforming->num_prgs; prg++) {
      if (!pull16(ppReadPackedMsg, &beamforming->prgs_list[prg].pm_idx, end)) {
        return 0;
      }
      for (int digInt = 0; digInt < beamforming->dig_bf_interfaces; digInt++) {
        if (!pull16(ppReadPackedMsg, &beamforming->prgs_list[prg].dig_bf_interface_list[digInt].beam_idx, end)) {
          return 0;
        }
      }
    }
    if (!(pull8(ppReadPackedMsg, &dci_pdu->beta_PDCCH_1_0, end) && pull8(ppReadPackedMsg, &dci_pdu->powerControlOffsetSS, end)
          && pull16(ppReadPackedMsg, &dci_pdu->PayloadSizeBits, end)
          && unpack_dci_payload(dci_pdu->Payload, dci_pdu->PayloadSizeBits, ppReadPackedMsg, end))) {
      return 0;
    }
  }
  return 1;
}

uint8_t unpack_ul_dci_request(uint8_t **ppReadPackedMsg, uint8_t *end, void *msg, nfapi_p7_codec_config_t *config)
{
  nfapi_nr_ul_dci_request_t *pNfapiMsg = (nfapi_nr_ul_dci_request_t *)msg;

  if (!(pull16(ppReadPackedMsg, &pNfapiMsg->SFN, end) && pull16(ppReadPackedMsg, &pNfapiMsg->Slot, end)
        && pull8(ppReadPackedMsg, &pNfapiMsg->numPdus, end)))
    return 0;

  for (int i = 0; i < pNfapiMsg->numPdus; i++) {
    if (!unpack_ul_dci_pdu_list_value(ppReadPackedMsg, end, &pNfapiMsg->ul_dci_pdu_list[i]))
      return 0;
  }

  return 1;
}