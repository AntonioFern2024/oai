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

#ifndef POWER_REFERENCE_H
#define POWER_REFERENCE_H
#include <stdint.h>

#define TARGET_MINIMUM_AMPLITUDE (1 << 9)
#define TARGET_MAXIMUM_AMPLITUDE (1 << 12)

/// @brief Calculate received power based on rms and rx_power reference
///        This is acheived by comparing a full scale sine wave RMS^2 with
//         RMS^2 of the signal.
//
/// @param rms RMS^2 of the signal (Sum(I^2 + Q^2)/N)
/// @param rx_power_reference power of a 0dBFS single carrier sine wave
///
/// @return received power in dBm
float calculate_average_rx_power(float rms, float rx_power_reference);

/// @brief Calculates amplitude that has to be used in order to reach requested_power_per_subcarrier
///        TX power if tx_power_reference is set. Clips amplitude to int16_t max if necessary.
///
/// @param tx_power_reference transmission power of a 0dBFS single carrier sine wave [dBm]
/// @param requested_power_per_subcarrier requested power / subcarrier for a transmission [dBm]
/// @param target_amp_backoff_db target amplitude power backoff [dB]
///
/// @return amplitude value
int16_t calculate_tx_amplitude(float tx_power_reference, float requested_power_per_subcarrier, float target_amp_backoff_db);

/// @brief Suggests new power reference for RX or TX. The goal of the function is to keep
///        the amplitude between TARGET_MINIMUM_AMPLITUDE and TARGET_MAXIMUM_AMPLITUDE
/// @param power_reference transmission power of a 0dBFS single carrier sine wave [dBm]
/// @param amplitude the calculated amplitude of the signal
///
/// @return updated power reference
float adjusted_power_reference(float power_reference, int16_t amplitude);

#endif
