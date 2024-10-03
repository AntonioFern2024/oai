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

#include "PduSessionEstablishmentAccept.h"
#include "common/utils/LOG/log.h"
#include "common/utils/tun_if.h"
#include "openair2/SDAP/nr_sdap/nr_sdap.h"

static uint16_t getShort(uint8_t *input)
{
  uint16_t tmp16;
  memcpy(&tmp16, input, sizeof(tmp16));
  return htons(tmp16);
}

static int capture_ipv4_addr(const uint8_t *addr, char *ip, size_t len)
{
  return snprintf(ip, len, "%d.%d.%d.%d", addr[0], addr[1], addr[2], addr[3]);
}

static int capture_ipv6_addr(const uint8_t *addr, char *ip, size_t len)
{
  // 24.501 Sec 9.11.4.10: "an interface identifier for the IPv6 link local
  // address": link local starts with fe80::, and only the last 64bits are
  // given (middle is zero)
  return snprintf(ip,
                  len,
                  "fe80::%02x%02x:%02x%02x:%02x%02x:%02x%02x",
                  addr[0],
                  addr[1],
                  addr[2],
                  addr[3],
                  addr[4],
                  addr[5],
                  addr[6],
                  addr[7]);
}

typedef struct {
  int iei;
  const char *description;
} iei_string_map_t;

iei_string_map_t iei_map[] = {{IEI_5GSM_CAUSE, "5GSM cause"},
                              {IEI_PDU_ADDRESS, "PDU address"},
                              {IEI_RQ_TIMER_VALUE, "GPRS timer"},
                              {IEI_SNSSAI, "S-NSSAI"},
                              {IEI_ALWAYSON_PDU, "Always-on PDU session indication"},
                              {IEI_MAPPED_EPS, "Mapped EPS bearer contexts"},
                              {IEI_EAP_MSG, "EAP message"},
                              {IEI_AUTH_QOS_DESC, "Authorized QoS flow descriptions"},
                              {IEI_EXT_CONF_OPT, "Extended protocol configuration options"},
                              {IEI_DNN, "DNN"}};

/**
 * @brief Lookup the IEI string for logging purposes
 */
static const char *get_iei_description(int iei)
{
  size_t map_size = sizeof(iei_map) / sizeof(iei_map[0]);
  for (size_t i = 0; i < map_size; i++) {
    if (iei_map[i].iei == iei) {
      return iei_map[i].description;
    }
  }
  return "Unknown IEI";
}

/**
 * @brief PDU session establishment accept (8.3.2 of 3GPP TS 24.501)
 *        network to UE
 */
void capture_pdu_session_establishment_accept_msg(uint8_t *buffer, uint32_t msg_length)
{
  fgs_nas_message_security_header_t sec_nas_hdr;
  fgs_nas_security_protected_plain_msg_t sec_nas_msg;
  pdu_session_establishment_accept_msg_t psea_msg;
  uint8_t *curPtr = buffer;
  // Security protected NAS header (7 bytes)
  sec_nas_hdr.protocol_discriminator = *curPtr++;
  sec_nas_hdr.security_header_type = *curPtr++;
  uint32_t tmp;
  memcpy(&tmp, buffer, sizeof(tmp));
  sec_nas_hdr.message_authentication_code = htonl(tmp);
  curPtr += sizeof(sec_nas_hdr.message_authentication_code);
  sec_nas_hdr.sequence_number = *curPtr++;
  // Security protected plain NAS message
  mm_msg_header_t *header = &sec_nas_msg.header;
  header->ex_protocol_discriminator = *curPtr++;
  header->security_header_type = *curPtr++;
  header->message_type = *curPtr++;
  sec_nas_msg.payload_type = *curPtr++;
  sec_nas_msg.payload_len = getShort(curPtr);
  curPtr += sizeof(sec_nas_msg.payload_len);
  /* Mandatory Presence IEs */
  sm_msg_header_t *sm_header = &psea_msg.header;
  sm_header->ex_protocol_discriminator = *curPtr++;
  sm_header->pdu_session_id = *curPtr++;
  sm_header->pti = *curPtr++;
  sm_header->message_type = *curPtr++;
  psea_msg.pdu_type = *curPtr & 0x0f;
  psea_msg.ssc_mode = (*curPtr++ & 0xf0) >> 4;
  psea_msg.qos_rules.length = getShort(curPtr);
  curPtr += sizeof(psea_msg.qos_rules.length);
  /* Supports the capture of only one QoS Rule, it should be changed for multiple QoS Rules */
  qos_rule_t qos_rule;
  qos_rule.id = *curPtr++;
  qos_rule.length = getShort(curPtr);
  curPtr += sizeof(qos_rule.length);
  qos_rule.oc = (*(curPtr)&0xE0) >> 5;
  qos_rule.dqr = (*(curPtr)&0x10) >> 4;
  qos_rule.nb_pf = *curPtr++ & 0x0F;

  if (qos_rule.nb_pf) {
    packet_filter_t pf;

    if (qos_rule.oc == ROC_CREATE_NEW_QOS_RULE || qos_rule.oc == ROC_MODIFY_QOS_RULE_ADD_PF
        || qos_rule.oc == ROC_MODIFY_QOS_RULE_REPLACE_PF) {
      pf.pf_type.type_1.pf_dir = (*curPtr & 0x30) >> 4;
      pf.pf_type.type_1.pf_id = *curPtr++ & 0x0F;
      pf.pf_type.type_1.length = *curPtr++;
      curPtr += (qos_rule.nb_pf * pf.pf_type.type_1.length); /* Ommit the Packet filter List */
    } else if (qos_rule.oc == ROC_MODIFY_QOS_RULE_DELETE_PF) {
      curPtr += qos_rule.nb_pf;
    }
  }

  qos_rule.prcd = *curPtr++;
  qos_rule.qfi = *curPtr++;
  psea_msg.sess_ambr.length = *curPtr++;
  curPtr += psea_msg.sess_ambr.length; /* Ommit the Seassion-AMBR */

  /* Optional Presence IEs */
  while (curPtr < buffer + msg_length) {
    uint8_t psea_iei = *curPtr++;
    LOG_T(NAS, "PDU SESSION ESTABLISHMENT ACCEPT - Received %s IEI\n", get_iei_description(psea_iei));
    switch (psea_iei) {
      case IEI_5GSM_CAUSE: /* Ommited */
        curPtr++;
        break;

      case IEI_PDU_ADDRESS:
        psea_msg.pdu_addr_ie.pdu_length = *curPtr++;
        /* PDU type */
        psea_msg.pdu_addr_ie.pdu_type = *curPtr & 0x07;
        // SMF's IPv6 link local address
        uint8_t si6lla = (*curPtr >> 3) & 0x01;
        if (si6lla)
          LOG_E(NAS, "SMF's IPv6 link local address is not handled\n");
        curPtr++;
        /* PDU Address */
        uint8_t *addr = psea_msg.pdu_addr_ie.pdu_addr_oct;
        if (psea_msg.pdu_addr_ie.pdu_type == PDU_SESSION_TYPE_IPV4) {
          for (int i = 0; i < IPv4_ADDRESS_LENGTH; ++i)
            addr[i] = *curPtr++;
          char ip[20];
          capture_ipv4_addr(&addr[0], ip, sizeof(ip));
          tun_config(1, ip, NULL, "oaitun_ue");
          setup_ue_ipv4_route(1, ip, "oaitun_ue");
          LOG_I(NAS, "Received PDU Session Establishment Accept, UE IP: %u.%u.%u.%u\n", addr[0], addr[1], addr[2], addr[3]);
        } else if (psea_msg.pdu_addr_ie.pdu_type == PDU_SESSION_TYPE_IPV6) {
          for (int i = 0; i < IPv6_INTERFACE_ID_LENGTH; ++i)
            addr[i] = *curPtr++;
          char ipv6[40];
          capture_ipv6_addr(addr, ipv6, sizeof(ipv6));
          tun_config(1, NULL, ipv6, "oaitun_ue");
        } else if (psea_msg.pdu_addr_ie.pdu_type == PDU_SESSION_TYPE_IPV4V6) {
          // 24.501 Sec 9.11.4.10: "If the PDU session type value indicates
          // IPv4v6, the PDU address information in octet 4 to octet 11
          // contains an interface identifier for the IPv6 link local address
          // and in octet 12 to octet 15 contains an IPv4 address."
          for (int i = 0; i < IPv4_ADDRESS_LENGTH + IPv6_INTERFACE_ID_LENGTH; ++i)
            addr[i] = *curPtr++;
          char ipv6[40];
          capture_ipv6_addr(addr, ipv6, sizeof(ipv6));
          char ipv4[20];
          capture_ipv4_addr(&addr[IPv6_INTERFACE_ID_LENGTH], ipv4, sizeof(ipv4));
          tun_config(1, ipv4, ipv6, "oaitun_ue");
          setup_ue_ipv4_route(1, ipv4, "oaitun_ue");
        } else {
          LOG_E(NAS, "unknown/unhandled PDU session establishment accept PDU type %d\n", psea_msg.pdu_addr_ie.pdu_type);
          curPtr += psea_msg.pdu_addr_ie.pdu_length;
        }
        break;

      case IEI_RQ_TIMER_VALUE: /* Ommited */
        curPtr++; /* TS 24.008 10.5.7.3 */
        break;

      case IEI_SNSSAI: {
        uint8_t snssai_length = *curPtr;
        curPtr += (snssai_length + sizeof(snssai_length));
        break;
      }

      case IEI_ALWAYSON_PDU: /* Ommited */
        curPtr++;
        break;

      case IEI_MAPPED_EPS: {
        uint16_t mapped_eps_length = getShort(curPtr);
        curPtr += mapped_eps_length;
        break;
      }

      case IEI_EAP_MSG: {
        uint16_t eap_length = getShort(curPtr);
        curPtr += (eap_length + sizeof(eap_length));
        break;
      }

      case IEI_AUTH_QOS_DESC: {
        psea_msg.qos_fd_ie.length = getShort(curPtr);
        curPtr += (psea_msg.qos_fd_ie.length + sizeof(psea_msg.qos_fd_ie.length));
        break;
      }

      case IEI_EXT_CONF_OPT: {
        psea_msg.ext_pp_ie.length = getShort(curPtr);
        curPtr += (psea_msg.ext_pp_ie.length + sizeof(psea_msg.ext_pp_ie.length));
        break;
      }

      case IEI_DNN: {
        psea_msg.dnn_ie.dnn_length = *curPtr++;
        char apn[APN_MAX_LEN];

        if (psea_msg.dnn_ie.dnn_length <= APN_MAX_LEN && psea_msg.dnn_ie.dnn_length >= APN_MIN_LEN) {
          memcpy(apn, curPtr, psea_msg.dnn_ie.dnn_length);
          LOG_T(NAS, "PDU SESSION ESTABLISHMENT ACCEPT - APN: %s\n", apn);
        } else
          LOG_E(NAS, "PDU SESSION ESTABLISHMENT ACCEPT - DNN IE has invalid length\n");

        curPtr = buffer + msg_length; // we force stop processing
        break;
      }

      default:
        curPtr = buffer + msg_length; // we force stop processing
        break;
    }
  }

  set_qfi_pduid(qos_rule.qfi, psea_msg.header.pdu_session_id);
  return;
}
