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

#include <stdint.h>
#include <math.h>
#include "power_reference.h"

float calculate_average_rx_power(float rms, float rx_power_reference)
{
  const int16_t fullscale = INT16_MAX;
  const float rms_fullscale = 0.707 * fullscale * fullscale;
  return rx_power_reference + 10 * log10(rms / rms_fullscale);
}

int16_t calculate_tx_amplitude(float tx_power_reference, float requested_power_per_subcarrier, float target_amp_backoff_db)
{
  const int16_t fullscale = INT16_MAX;
  if (tx_power_reference < requested_power_per_subcarrier) {
    // In case current tx_power setting is too small, clip AMP to FULLSCALE
    return fullscale;
  } else {
    int16_t amp_backoff_db = tx_power_reference - requested_power_per_subcarrier;
    return (int16_t)(fullscale / pow(10.0, amp_backoff_db / 20.0));
  }
}

float adjusted_power_reference(float power_reference, int16_t amplitude)
{
  if (amplitude < TARGET_MINIMUM_AMPLITUDE) {
    return power_reference - 3;
  } else if (amplitude > TARGET_MAXIMUM_AMPLITUDE) {
    return power_reference + 3;
  }
  return power_reference;
}
