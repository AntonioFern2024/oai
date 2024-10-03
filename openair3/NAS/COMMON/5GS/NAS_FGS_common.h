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

#ifndef NAS_FGS_COMMON_H
#define NAS_FGS_COMMON_H

#include <stdint.h>

/**
 * Security protected 5GS NAS message header (9.1.1 of 3GPP TS 24.501)
 * either 5GMM or 5GSM
 * Standard L3 message header (11.2.3.1 of 3GPP TS 24.007)
 */
typedef struct {
  // Extended Protocol Discriminator
  uint8_t protocol_discriminator;
  // Security Header Type
  uint8_t security_header_type;
  // Message Authentication Code
  uint32_t message_authentication_code;
  // Sequence Number
  uint8_t sequence_number;
} __attribute__((packed)) fgs_nas_message_security_header_t;

/// 5GMM - 5GS mobility management

/**
 * Header of a plain 5GMM NAS message (5GS)
 * Standard L3 message header (11.2.3.1 of 3GPP TS 24.007)
 */
typedef struct {
  uint8_t ex_protocol_discriminator;
  uint8_t security_header_type;
  uint8_t message_type;
} mm_msg_header_t;

typedef struct security_protected_plain_nas_5gs_msg_s {
  mm_msg_header_t header;
  uint8_t payload_type; /* Payload Container Type */
  uint16_t payload_len; /* Payload Container Length */
} fgs_nas_security_protected_plain_msg_t;

/// 5GSM - 5GS session management

/**
 * Header of a plain 5GSM NAS message (5GS)
 * Standard L3 message header (11.2.3.1 of 3GPP TS 24.007)
 */
typedef struct {
  uint8_t ex_protocol_discriminator;
  uint8_t pdu_session_id;
  uint8_t pti;
  uint8_t message_type;
} sm_msg_header_t;

typedef struct {
  uint8_t ex_protocol_discriminator;
  uint8_t pdu_session_id;
  uint8_t PTI;
  uint8_t message_type;
} fgs_sm_nas_msg_header_t;

typedef struct {
  mm_msg_header_t plain_nas_msg_header;
  uint8_t payload_container_type;
  uint16_t payload_container_length;
  fgs_sm_nas_msg_header_t sm_nas_msg_header;
} dl_nas_transport_t;

#endif // NAS_FGS_COMMON_H
