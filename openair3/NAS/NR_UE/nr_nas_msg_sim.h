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

/*! \file nr_nas_msg_sim.h
 * \brief simulator for nr nas message
 * \author Yoshio INOUE, Masayuki HARADA
 * \email yoshio.inoue@fujitsu.com,masayuki.harada@fujitsu.com
 * \protocol 5GS (5GMM and 5GSM)
 * \date 2020
 * \version 0.1
 */

#ifndef __NR_NAS_MSG_SIM_H__
#define __NR_NAS_MSG_SIM_H__

#include <common/utils/assertions.h>
#include <openair3/UICC/usim_interface.h>
#include <stdbool.h>
#include <stdint.h>
#include "FGSAuthenticationResponse.h"
#include "FGSDeregistrationRequestUEOriginating.h"
#include "FGSIdentityResponse.h"
#include "FGSMobileIdentity.h"
#include "FGSNASSecurityModeComplete.h"
#include "FGSUplinkNasTransport.h"
#include "RegistrationComplete.h"
#include "RegistrationRequest.h"
#include "as_message.h"
#include "openair3/NAS/COMMON/5GS/NAS_FGS_common.h"
#include "secu_defs.h"

// clang-format off
#define PLAIN_5GS_MSG                                      0b0000
#define INTEGRITY_PROTECTED                                0b0001
#define INTEGRITY_PROTECTED_AND_CIPHERED                   0b0010
#define INTEGRITY_PROTECTED_WITH_NEW_SECU_CTX              0b0011          // only for SECURITY MODE COMMAND
#define INTEGRITY_PROTECTED_AND_CIPHERED_WITH_NEW_SECU_CTX 0b0100         // only for SECURITY MODE COMPLETE

// Message types for 5GS mobility management (Table 9.7.1 of 3GPP TS 24.501)
#define FGS_REGISTRATION_REQUEST                           0b01000001 /* 65 = 0x41 */
#define FGS_REGISTRATION_ACCEPT                            0b01000010 /* 66 = 0x42 */
#define FGS_REGISTRATION_COMPLETE                          0b01000011 /* 67 = 0x43 */
#define FGS_REGISTRATION_REJECT                            0b01000100 /* 68 = 0x44 */
#define FGS_DEREGISTRATION_REQUEST_UE_ORIGINATING          0b01000101 /* 69 = 0x45 */
#define FGS_DEREGISTRATION_ACCEPT_UE_ORIGINATING           0b01000110 /* 70 = 0x46 */
#define FGS_DEREGISTRATION_REQUEST_UE_TERMINATED           0b01000111 /* 71 = 0x47 */
#define FGS_DEREGISTRATION_ACCEPT_UE_TERMINATED            0b01001000 /* 72 = 0x48 */
#define FGS_SERVICE_REQUEST                                0b01001100 /* 76 = 0x4C */
#define FGS_SERVICE_REJECT                                 0b01001101 /* 77 = 0x4D */
#define FGS_SERVICE_ACCEPT                                 0b01001110 /* 78 = 0x4E */
#define FGS_CONTROL_PLANE_SERVICE_REQUEST                  0b01001111 /* 79 = 0x4F */
#define FGS_NSS_AUTHENTICATION_COMMAND                     0b01010000 /* 80 = 0x50 */
#define FGS_NSS_AUTHENTICATION_COMPLETE                    0b01010001 /* 81 = 0x51 */
#define FGS_NSS_AUTHENTICATION_RESULT                      0b01010010 /* 82 = 0x52 */
#define FGS_CONFIGURATION_UPDATE_COMMAND                   0b01010100 /* 84 = 0x54 */
#define FGS_CONFIGURATION_UPDATE_COMPLETE                  0b01010101 /* 85 = 0x55 */
#define FGS_AUTHENTICATION_REQUEST                         0b01010110 /* 86 = 0x56 */
#define FGS_AUTHENTICATION_RESPONSE                        0b01010111 /* 87 = 0x57 */
#define FGS_AUTHENTICATION_REJECT                          0b01011000 /* 88 = 0x58 */
#define FGS_AUTHENTICATION_FAILURE                         0b01011001 /* 89 = 0x59 */
#define FGS_AUTHENTICATION_RESULT                          0b01011010 /* 90 = 0x5A */
#define FGS_IDENTITY_REQUEST                               0b01011011 /* 91 = 0x5b */
#define FGS_IDENTITY_RESPONSE                              0b01011100 /* 92 = 0x5c */
#define FGS_SECURITY_MODE_COMMAND                          0b01011101 /* 93 = 0x5d */
#define FGS_SECURITY_MODE_COMPLETE                         0b01011110 /* 94 = 0x5e */
#define FGS_SECURITY_MODE_REJECT                           0b01011111 /* 95 = 0x5F */
#define FGS_5GMM_STATUS                                    0b01100100 /* 100 = 0x64 */
#define FGS_NOTIFICATION                                   0b01100101 /* 101 = 0x65 */
#define FGS_NOTIFICATION_RESPONSE                          0b01100110 /* 102 = 0x66 */
#define FGS_UPLINK_NAS_TRANSPORT                           0b01100111 /* 103 = 0x67 */
#define FGS_DOWNLINK_NAS_TRANSPORT                         0b01101000 /* 104 = 0x68 */

// Message types for 5GS session management (Table 9.7.2 of 3GPP TS 24.501)
#define FGS_PDU_SESSION_ESTABLISHMENT_REQ                  0b11000001 /* 193= 0xc1 */
#define FGS_PDU_SESSION_ESTABLISHMENT_ACC                  0b11000010 /* 194= 0xc2 */
#define FGS_PDU_SESSION_ESTABLISHMENT_REJ                  0b11000011 /* 195= 0xc3 */
#define FGS_PDU_SESSION_AUTH_COMMAND                       0b11000101 /* 197= 0xc5 */
#define FGS_PDU_SESSION_AUTH_COMPLETE                      0b11000110 /* 198= 0xc6 */
#define FGS_PDU_SESSION_AUTH_RESULT                        0b11000111 /* 199= 0xc7 */
#define FGS_PDU_SESSION_MODIFICATION_REQ                   0b11001001 /* 201= 0xc9 */
#define FGS_PDU_SESSION_MODIFICATION_REJ                   0b11001010 /* 202= 0xca */
#define FGS_PDU_SESSION_MODIFICATION_COMMAND               0b11001011 /* 203= 0xcb */
#define FGS_PDU_SESSION_MODIFICATION_COMPLETE              0b11001100 /* 204= 0xcc */
#define FGS_PDU_SESSION_MODIFICATION_COMMAND_REJ           0b11001101 /* 205= 0xcd */
#define FGS_PDU_SESSION_RELEASE_REQ                        0b11010001 /* 209= 0xd1 */
#define FGS_PDU_SESSION_RELEASE_REJ                        0b11010010 /* 210= 0xd2 */
#define FGS_PDU_SESSION_RELEASE_COMMAND                    0b11010011 /* 211= 0xd3 */
#define FGS_PDU_SESSION_RELEASE_COMPLETE                   0b11010100 /* 212= 0xd4 */
#define FGS_5GSM_STATUS                                    0b11010110 /* 214= 0xd6 */

#define INITIAL_REGISTRATION                               0b001

#define PLAIN_5GS_NAS_MESSAGE_HEADER_LENGTH                3
#define SECURITY_PROTECTED_5GS_NAS_MESSAGE_HEADER_LENGTH   7
#define PAYLOAD_CONTAINER_LENGTH_MIN                       3
#define PAYLOAD_CONTAINER_LENGTH_MAX                       65537

// clang-format on

/* List of allowed NSSAI from NAS messaging. */
typedef struct {
  int sst;
  int hplmn_sst;
  int sd;
  int hplmn_sd;
} nr_nas_msg_snssai_t;

/* Security Key for SA UE */
typedef struct {
  uint8_t kausf[32];
  uint8_t kseaf[32];
  uint8_t kamf[32];
  uint8_t knas_int[16];
  uint8_t knas_enc[16];
  uint8_t res[16];
  uint8_t rand[16];
  uint8_t kgnb[32];
  uint32_t nas_count_ul;
  uint32_t nas_count_dl;
} ue_sa_security_key_t;

typedef struct {
  uicc_t *uicc;
  ue_sa_security_key_t security;
  stream_security_container_t *security_container;
  Guti5GSMobileIdentity_t *guti;
  bool termination_procedure;
  uint8_t  *registration_request_buf;
  uint32_t  registration_request_len;
  instance_t UE_id;
} nr_ue_nas_t;

typedef enum fgs_protocol_discriminator_e {
  /* Protocol discriminator identifier for 5GS Mobility Management */
  FGS_MOBILITY_MANAGEMENT_MESSAGE =   0x7E,

  /* Protocol discriminator identifier for 5GS Session Management */
  FGS_SESSION_MANAGEMENT_MESSAGE =    0x2E,
} fgs_protocol_discriminator_t;

typedef union {
  mm_msg_header_t                        header;
  registration_request_msg               registration_request;
  fgs_identiy_response_msg               fgs_identity_response;
  fgs_authentication_response_msg        fgs_auth_response;
  fgs_deregistration_request_ue_originating_msg fgs_deregistration_request_ue_originating;
  fgs_security_mode_complete_msg         fgs_security_mode_complete;
  registration_complete_msg              registration_complete;
  fgs_uplink_nas_transport_msg           uplink_nas_transport;
} MM_msg;

typedef struct {
  MM_msg mm_msg;    /* 5GS Mobility Management messages */
} fgs_nas_message_plain_t;

typedef struct {
  fgs_nas_message_security_header_t header;
  fgs_nas_message_plain_t plain;
} fgs_nas_message_security_protected_t;


typedef union {
  fgs_nas_message_security_header_t header;
  fgs_nas_message_security_protected_t security_protected;
  fgs_nas_message_plain_t plain;
} fgs_nas_message_t;

typedef struct {
  union {
    mm_msg_header_t plain_nas_msg_header;
    struct security_protected_nas_msg_header_s {
      uint8_t  ex_protocol_discriminator;
      uint8_t  security_header_type;
      uint16_t message_authentication_code1;
      uint16_t message_authentication_code2;
      uint8_t  sequence_number;
    } security_protected_nas_msg_header_t;
  } choice;
} nas_msg_header_t;

nr_ue_nas_t *get_ue_nas_info(module_id_t module_id);
void generateRegistrationRequest(as_nas_info_t *initialNasMsg, nr_ue_nas_t *nas);
void *nas_nrue_task(void *args_p);
void *nas_nrue(void *args_p);

#endif /* __NR_NAS_MSG_SIM_H__*/



