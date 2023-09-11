/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.0  (the "License"); you may not use this file
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

/*! \file PHY/LTE_TRANSPORT/initial_sync.c
* \brief Routines for initial UE synchronization procedure (PSS,SSS,PBCH and frame format detection)
* \author R. Knopp, F. Kaltenberger
* \date 2011
* \version 0.1
* \company Eurecom
* \email: knopp@eurecom.fr,kaltenberger@eurecom.fr
* \note
* \warning
*/
#include "PHY/types.h"
#include "PHY/defs_nr_UE.h"
#include "PHY/MODULATION/modulation_UE.h"
#include "nr_transport_proto_ue.h"
#include "PHY/NR_UE_ESTIMATION/nr_estimation.h"
#include "SCHED_NR_UE/defs.h"
#include "common/utils/LOG/vcd_signal_dumper.h"
#include "common/utils/nr/nr_common.h"

#include "common_lib.h"
#include <math.h>

#include "PHY/NR_REFSIG/pss_nr.h"
#include "PHY/NR_REFSIG/sss_nr.h"
#include "PHY/NR_REFSIG/refsig_defs_ue.h"
#include "executables/softmodem-common.h"
#include "openair1/PHY/defs_nr_sl_UE.h"

extern openair0_config_t openair0_cfg[];
//static  nfapi_nr_config_request_t config_t;
//static  nfapi_nr_config_request_t* config =&config_t;
int cnt=0;

#define DEBUG_INITIAL_SYNCH
#define DUMP_PBCH_CH_ESTIMATES 0

// create a new node of SSB structure
NR_UE_SSB* create_ssb_node(uint8_t  i, uint8_t  h) {

  NR_UE_SSB *new_node = (NR_UE_SSB*)malloc(sizeof(NR_UE_SSB));
  new_node->i_ssb = i;
  new_node->n_hf = h;
  new_node->c_re = 0;
  new_node->c_im = 0;
  new_node->metric = 0;
  new_node->next_ssb = NULL;

  return new_node;
}


// insertion of the structure in the ordered list (highest metric first)
NR_UE_SSB* insert_into_list(NR_UE_SSB *head, NR_UE_SSB *node) {

  if (node->metric > head->metric) {
    node->next_ssb = head;
    head = node;
    return head;
  }

  NR_UE_SSB *current = head;
  while (current->next_ssb !=NULL) {
    NR_UE_SSB *temp=current->next_ssb;
    if(node->metric > temp->metric) {
      node->next_ssb = temp;
      current->next_ssb = node;
      return head;
    }
    else
      current = temp;
  }
  current->next_ssb = node;

  return head;
}


void free_list(NR_UE_SSB *node) {
  if (node->next_ssb != NULL)
    free_list(node->next_ssb);
  free(node);
}


int nr_pbch_detection(UE_nr_rxtx_proc_t * proc, PHY_VARS_NR_UE *ue, int pbch_initial_symbol, c16_t rxdataF[][ue->frame_parms.samples_per_slot_wCP])
{
  NR_DL_FRAME_PARMS *frame_parms=&ue->frame_parms;
  int ret =-1;

  NR_UE_SSB *best_ssb = NULL;
  NR_UE_SSB *current_ssb;

#ifdef DEBUG_INITIAL_SYNCH
  LOG_I(PHY,"[UE%d] Initial sync: starting PBCH detection (rx_offset %d)\n",ue->Mod_id,
        ue->rx_offset);
#endif

  uint8_t  N_L = (frame_parms->Lmax == 4)? 4:8;
  uint8_t  N_hf = (frame_parms->Lmax == 4)? 2:1;

  // loops over possible pbch dmrs cases to retrive best estimated i_ssb (and n_hf for Lmax=4) for multiple ssb detection
  for (int hf = 0; hf < N_hf; hf++) {
    for (int l = 0; l < N_L ; l++) {

      // initialization of structure
      current_ssb = create_ssb_node(l,hf);

      start_meas(&ue->dlsch_channel_estimation_stats);
      // computing correlation between received DMRS symbols and transmitted sequence for current i_ssb and n_hf
      for(int i=pbch_initial_symbol; i<pbch_initial_symbol+3;i++)
          nr_pbch_dmrs_correlation(ue,proc,i,i-pbch_initial_symbol,current_ssb,rxdataF);
      stop_meas(&ue->dlsch_channel_estimation_stats);
      
      current_ssb->metric = current_ssb->c_re*current_ssb->c_re + current_ssb->c_im*current_ssb->c_im;
      
      // generate a list of SSB structures
      if (best_ssb == NULL)
        best_ssb = current_ssb;
      else
        best_ssb = insert_into_list(best_ssb,current_ssb);

    }
  }

  NR_UE_SSB *temp_ptr=best_ssb;
  while (ret!=0 && temp_ptr != NULL) {

    start_meas(&ue->dlsch_channel_estimation_stats);
  // computing channel estimation for selected best ssb
    const int estimateSz = frame_parms->symbols_per_slot * frame_parms->ofdm_symbol_size;
    __attribute__ ((aligned(32))) struct complex16 dl_ch_estimates[frame_parms->nb_antennas_rx][estimateSz];
    __attribute__ ((aligned(32))) struct complex16 dl_ch_estimates_time[frame_parms->nb_antennas_rx][frame_parms->ofdm_symbol_size];

    for(int i=pbch_initial_symbol; i<pbch_initial_symbol+3;i++)
      nr_pbch_channel_estimation(ue,&ue->frame_parms, estimateSz, dl_ch_estimates, dl_ch_estimates_time, 
                                 proc,i,i-pbch_initial_symbol,temp_ptr->i_ssb,temp_ptr->n_hf,rxdataF,0);

    stop_meas(&ue->dlsch_channel_estimation_stats);
    fapiPbch_t result = {0};
    ret = nr_rx_pbch(ue,
                     proc,
                     estimateSz,
                     dl_ch_estimates,
                     frame_parms,
                     temp_ptr->i_ssb,
                     SISO,
                     &result,
                     rxdataF);

    if (DUMP_PBCH_CH_ESTIMATES && (ret == 0)) {
      write_output("pbch_ch_estimates.m", "pbch_ch_estimates", dl_ch_estimates, frame_parms->nb_antennas_rx*estimateSz, 1, 1);
      write_output("pbch_ch_estimates_time.m", "pbch_ch_estimates_time", dl_ch_estimates_time, frame_parms->nb_antennas_rx*frame_parms->ofdm_symbol_size, 1, 1);
    }

    temp_ptr=temp_ptr->next_ssb;
  }

  free_list(best_ssb);

  
  if (ret==0) {
    
    frame_parms->nb_antenna_ports_gNB = 1; //pbch_tx_ant;
    
    // set initial transmission mode to 1 or 2 depending on number of detected TX antennas
    //frame_parms->mode1_flag = (pbch_tx_ant==1);
    // openair_daq_vars.dlsch_transmission_mode = (pbch_tx_ant>1) ? 2 : 1;


#ifdef DEBUG_INITIAL_SYNCH
    LOG_I(PHY, "[UE%d] Initial sync: pbch decoded sucessfully, ssb index %d\n", ue->Mod_id, frame_parms->ssb_index);
#endif
    return(0);
  } else {
    return(-1);
  }

}

static int nr_psbch_detection(UE_nr_rxtx_proc_t *proc, PHY_VARS_NR_UE *ue, int psbch_initial_symbol,
                              c16_t rxdataF[][ue->SL_UE_PHY_PARAMS.sl_frame_params.samples_per_slot_wCP])
{
  NR_DL_FRAME_PARMS *frame_parms = &ue->SL_UE_PHY_PARAMS.sl_frame_params;
  int ret = -1;
  NR_UE_SSB *best_ssb = NULL;
  NR_UE_SSB *current_ssb;
  uint8_t N_L = (frame_parms->Lmax == 4) ? 4 : 8;
  uint8_t N_hf = (frame_parms->Lmax == 4) ? 2 : 1;
  for (int l = 0; l < N_L; l++) {
    current_ssb = create_ssb_node(l, N_hf);
    start_meas(&ue->dlsch_channel_estimation_stats);
    // computing correlation between received DMRS symbols and transmitted sequence for current i_ssb and n_hf
    for (int i = psbch_initial_symbol; i < SL_NR_NUM_SYMBOLS_SSB_NORMAL_CP; i++) {
      if (i >= 1 && i <= 4)
        continue;
      nr_pbch_dmrs_correlation(ue, proc, i, i - psbch_initial_symbol, current_ssb, rxdataF);
    }
    stop_meas(&ue->dlsch_channel_estimation_stats);

    current_ssb->metric = current_ssb->c_re * current_ssb->c_re + current_ssb->c_im * current_ssb->c_im;

    // generate a list of SSB structures
    if (best_ssb == NULL)
      best_ssb = current_ssb;
    else
      best_ssb = insert_into_list(best_ssb, current_ssb);
  }
  NR_UE_SSB *temp_ptr = best_ssb;
  while (ret != 0 && temp_ptr != NULL) {
    start_meas(&ue->dlsch_channel_estimation_stats);
    const int estimateSz = frame_parms->symbols_per_slot * frame_parms->ofdm_symbol_size;
    __attribute__((aligned(32))) struct complex16 dl_ch_estimates[frame_parms->nb_antennas_rx][estimateSz];
    __attribute__((aligned(32))) struct complex16 dl_ch_estimates_time[frame_parms->nb_antennas_rx][frame_parms->ofdm_symbol_size];

    for (int i = psbch_initial_symbol; i < SL_NR_NUM_SYMBOLS_SSB_NORMAL_CP; i++) {
      if (i >= 1 && i <= 4)
        continue;
      nr_pbch_channel_estimation(ue, frame_parms, estimateSz, dl_ch_estimates, dl_ch_estimates_time,
                                 proc, i, i-psbch_initial_symbol, temp_ptr->i_ssb, temp_ptr->n_hf, rxdataF, get_softmodem_params()->sl_mode == 2);
    }
    stop_meas(&ue->dlsch_channel_estimation_stats);
    nr_sl_psbch_rsrp_measurements(&ue->SL_UE_PHY_PARAMS, frame_parms, rxdataF, false);
    uint8_t decoded_pdu;
    ret = nr_rx_psbch(ue,
                      proc,
                      estimateSz,
                      dl_ch_estimates,
                      frame_parms,
                      &decoded_pdu,
                      rxdataF,
                      ue->SL_UE_PHY_PARAMS.sl_config.sl_sync_source.rx_slss_id);
    temp_ptr = temp_ptr->next_ssb;
  }
  free_list(best_ssb);
  return ret;
}

char duplex_string[2][4] = {"FDD","TDD"};
char prefix_string[2][9] = {"NORMAL","EXTENDED"};

int nr_sl_initial_sync(UE_nr_rxtx_proc_t *proc, PHY_VARS_NR_UE *ue, int n_frames)
{
  /*   Initial synchronisation
   *
   *     -----------------------------------------------------------------------------
   *     |                                 Received UE data buffer                    |
   *     ----------------------------------------------------------------------------
   *     <-------------->-------------------------------------------------
   *         ssb_start   | psbch | spss | spss | ssss | ssss | psbch |....
   *                     -------------------------------------------------
   *     <---------------------->
   *             sync_pos            SL S-SSB/PSBCH block
   */
  VCD_SIGNAL_DUMPER_DUMP_FUNCTION_BY_NAME(VCD_SIGNAL_DUMPER_FUNCTIONS_NR_INITIAL_UE_SYNC, VCD_FUNCTION_IN);
  NR_DL_FRAME_PARMS *fp = &ue->SL_UE_PHY_PARAMS.sl_frame_params;
  LOG_D(NR_PHY, "nr_initial SL sync ue RB_SL %d\n", fp->N_RB_SL);
  int ret = -1;
  int32_t sync_pos = 0, sync_pos_frame;
  for (int is = 0; is < n_frames; is++) {
    sync_pos = pss_synchro_nr(ue, is, NO_RATE_CHANGE);
    /* In 5G SL, the first SSB symbol is the PSBCH, so we need adjust the SSB
        offset accordingly (psbch_plus_prefix_size). Additionally, there are 2
        PSS symbols.
        However, if we correlated on the second PSS, we do not need to include an offset
        the size of the first PSS0, becasue the correlation occurs on each individual PSS.
        The sync_pos will ALWAYS point at the start of the first PSS (PSS0) becasue
        it is find the peak position. However, the correlation will be higher between
        one of the PSS's, and this is how the Nid2 is set.
        PSBCH PREFIX | PSBCH 0 | PSS 0 PREFIX | PSS 0 | PSS 1 PREFIX | PSS 1 |
            176     |  2048   |      144     | 2048  |      144     | 2048  |
            176     |  2048   |      144     |   -   |      -       |   X   | SSB Start = X - (176 + 2048 + 144)
            176     |  2048   |      144     |   X   |      144     | 2048  | SSB Start = X - (176 + 2048 + 144) */
    uint32_t psbch_plus_prefix_size = fp->ofdm_symbol_size + fp->nb_prefix_samples0;
    uint32_t pss_plus_prefix_size = fp->nb_prefix_samples;
    LOG_I(NR_PHY, "This is pss_plus_prefix_size %d, psbch_plus_prefix_size %d, sync_pos %d, Nid2 %d\n",
          pss_plus_prefix_size, psbch_plus_prefix_size, sync_pos, ue->common_vars.nid2_sl);
    if (sync_pos >= psbch_plus_prefix_size + pss_plus_prefix_size) {
      ue->ssb_offset = sync_pos - (pss_plus_prefix_size + psbch_plus_prefix_size);
    } else {
      ue->ssb_offset = sync_pos + fp->samples_per_frame - (pss_plus_prefix_size + psbch_plus_prefix_size);
    }
    LOG_I(NR_PHY, "[UE%d] Initial SL sync : n_frames %d Estimated PSS position %d, Nid2 %d  ssb_offset %d\n",
          ue->Mod_id, n_frames, sync_pos, ue->common_vars.nid2_sl, ue->ssb_offset);
    if (sync_pos < (NR_NUMBER_OF_SUBFRAMES_PER_FRAME * fp->samples_per_subframe - (SL_NR_NUM_SYMBOLS_SSB_NORMAL_CP * fp->ofdm_symbol_size))) {
      uint8_t phase_tdd_ncp;
      int32_t metric_tdd_ncp = 0;
      const uint32_t rxdataF_sz = ue->SL_UE_PHY_PARAMS.sl_frame_params.samples_per_slot_wCP;
      __attribute__((aligned(32))) c16_t rxdataF[ue->SL_UE_PHY_PARAMS.sl_frame_params.nb_antennas_rx][rxdataF_sz];
      for (int i = 0; i < SL_NR_NUM_SYMBOLS_SSB_NORMAL_CP; i++)
        nr_slot_fep_init_sync(ue, proc, i, is * fp->samples_per_frame + ue->ssb_offset, false, rxdataF, link_type_sl);
      LOG_I(NR_PHY, "Calling sss detection (normal CP)\n");
      int freq_offset_sss = 0;
      ret = rx_sss_sl_nr(ue, proc, &metric_tdd_ncp, &phase_tdd_ncp, &freq_offset_sss, rxdataF);
      if (ue->UE_fo_compensation) {
        double sampling_time = 1 / (1.0e3 * fp->samples_per_subframe);
        double off_angle = -2 * M_PI * sampling_time * freq_offset_sss;
        int start = is * fp->samples_per_frame + ue->ssb_offset;
        int end = start + SL_NR_NUM_SYMBOLS_SSB_NORMAL_CP * (fp->ofdm_symbol_size + fp->nb_prefix_samples);
        for (int n = start; n < end; n++) {
          for (int ar = 0; ar < fp->nb_antennas_rx; ar++) {
            double re = ((double)(((short *)ue->common_vars.rxdata[ar]))[2 * n]);
            double im = ((double)(((short *)ue->common_vars.rxdata[ar]))[2 * n + 1]);
            ((short *)ue->common_vars.rxdata[ar])[2 * n] = (short)(round(re * cos(n * off_angle) - im * sin(n * off_angle)));
            ((short *)ue->common_vars.rxdata[ar])[2 * n + 1] = (short)(round(re * sin(n * off_angle) + im * cos(n * off_angle)));
          }
        }
        ue->common_vars.freq_offset += freq_offset_sss;
      }
      if (ret == 0) {
        ret = nr_psbch_detection(proc, ue, 0, rxdataF);
      }
      if (ret == 0) {
        // sync at symbol ue->symbol_offset
        // computing the offset wrt the beginning of the frame
        int mu = fp->numerology_index;
        int n_symb_prefix0 = (ue->symbol_offset / (7 * (1 << mu))) + 1;
        sync_pos_frame = n_symb_prefix0 * (fp->ofdm_symbol_size + fp->nb_prefix_samples0)
                         + (ue->symbol_offset - n_symb_prefix0) * (fp->ofdm_symbol_size + fp->nb_prefix_samples);
        ue->init_sync_frame = n_frames - 1 - is;
        if (ue->ssb_offset < sync_pos_frame) {
          ue->rx_offset = fp->samples_per_frame - sync_pos_frame + ue->ssb_offset;
          ue->init_sync_frame += 1;
        } else {
          ue->rx_offset = ue->ssb_offset - sync_pos_frame;
        }
      }
      LOG_I(NR_PHY, "TDD Normal prefix: CellId %d metric %d, phase %d, psbch %d\n",
            fp->Nid_cell, metric_tdd_ncp, phase_tdd_ncp, ret);
    } else {
      LOG_I(NR_PHY, "TDD Normal prefix: SSS error condition: sync_pos %d\n", sync_pos);
    }
    if (ret == 0)
      break;
  }
  if (ret == 0) {
    LOG_I(NR_PHY,
          "[UE %d] rx_offset %d Measured Carrier Frequency %.0f Hz (offset %d Hz)\n",
          ue->Mod_id,
          ue->rx_offset,
          openair0_cfg[0].rx_freq[0] + ue->common_vars.freq_offset,
          ue->common_vars.freq_offset);
  } else {
    LOG_I(NR_PHY,
          "[UE%d] Initial sync :  PSBCH not ok. Estimated PSS position %d, Nid1 %d, Nid2 %d, Frame_type %d\n",
          ue->Mod_id,
          sync_pos,
          GET_NID1_SL(fp->Nid_cell),
          GET_NID2_SL(fp->Nid_cell),
          fp->frame_type);
  }

  VCD_SIGNAL_DUMPER_DUMP_FUNCTION_BY_NAME(VCD_SIGNAL_DUMPER_FUNCTIONS_NR_INITIAL_UE_SYNC, VCD_FUNCTION_OUT);
  return ret;
}

int nr_initial_sync(UE_nr_rxtx_proc_t *proc,
                    PHY_VARS_NR_UE *ue,
                    int n_frames, int sa)
{

  int32_t sync_pos, sync_pos_frame; // k_ssb, N_ssb_crb, sync_pos2,
  int32_t metric_tdd_ncp=0;
  uint8_t phase_tdd_ncp;
  int frame_id;

  NR_DL_FRAME_PARMS *fp = &ue->frame_parms;
  int ret=-1;
  int rx_power=0; //aarx,
  
  VCD_SIGNAL_DUMPER_DUMP_FUNCTION_BY_NAME(VCD_SIGNAL_DUMPER_FUNCTIONS_NR_INITIAL_UE_SYNC, VCD_FUNCTION_IN);


  LOG_D(PHY,"nr_initial sync ue RB_DL %d\n", fp->N_RB_DL);

  /*   Initial synchronisation
   *
  *                                 1 radio frame = 10 ms
  *     <--------------------------------------------------------------------------->
  *     -----------------------------------------------------------------------------
  *     |                                 Received UE data buffer                    |
  *     ----------------------------------------------------------------------------
  *                     --------------------------
  *     <-------------->| pss | pbch | sss | pbch |
  *                     --------------------------
  *          sync_pos            SS/PBCH block
  */

  const uint32_t rxdataF_sz = ue->frame_parms.samples_per_slot_wCP;
  __attribute__ ((aligned(32))) c16_t rxdataF[ue->frame_parms.nb_antennas_rx][rxdataF_sz];
  cnt++;
  if (1){ // (cnt>100)
   cnt =0;

   // initial sync performed on two successive frames, if pbch passes on first frame, no need to process second frame 
   // only one frame is used for symulation tools
   for (frame_id = 0; frame_id < n_frames; frame_id++) {
     /* process pss search on received buffer */
     sync_pos = pss_synchro_nr(ue, frame_id, NO_RATE_CHANGE);
     if (sync_pos < fp->nb_prefix_samples)
       continue;

     ue->ssb_offset = sync_pos - fp->nb_prefix_samples;

#ifdef DEBUG_INITIAL_SYNCH
    LOG_I(PHY, "[UE%d] Initial sync : Estimated PSS position %d, Nid2 %d\n", ue->Mod_id, sync_pos, ue->common_vars.nid2);
    LOG_I(PHY,"sync_pos %d ssb_offset %d \n",sync_pos,ue->ssb_offset);
#endif

    /* check that SSS/PBCH block is continuous inside the received buffer */
    if (ue->ssb_offset + NR_N_SYMBOLS_SSB * (fp->ofdm_symbol_size + fp->nb_prefix_samples) < fp->samples_per_frame) {

      // digital compensation of FFO for SSB symbols
      if (ue->UE_fo_compensation){
        double s_time = 1/(1.0e3*fp->samples_per_subframe);  // sampling time
        double off_angle = -2*M_PI*s_time*(ue->common_vars.freq_offset);  // offset rotation angle compensation per sample

        // In SA we need to perform frequency offset correction until the end of buffer because we need to decode SIB1
        // and we do not know yet in which slot it goes.

        for (int n = frame_id * fp->samples_per_frame; n < (frame_id + 1) * fp->samples_per_frame; n++) {
          for (int ar=0; ar<fp->nb_antennas_rx; ar++) {
            const double re = ue->common_vars.rxdata[ar][n].r;
            const double im = ue->common_vars.rxdata[ar][n].i;
            ue->common_vars.rxdata[ar][n].r = (short)(round(re * cos(n * off_angle) - im * sin(n * off_angle)));
            ue->common_vars.rxdata[ar][n].i = (short)(round(re * sin(n * off_angle) + im * cos(n * off_angle)));
          }
        }
      }

      /* slot_fep function works for lte and takes into account begining of frame with prefix for subframe 0 */
      /* for NR this is not the case but slot_fep is still used for computing FFT of samples */
      /* in order to achieve correct processing for NR prefix samples is forced to 0 and then restored after function call */
      /* symbol number are from beginning of SS/PBCH blocks as below:  */
      /*    Signal            PSS  PBCH  SSS  PBCH                     */
      /*    symbol number      0     1    2    3                       */
      /* time samples in buffer rxdata are used as input of FFT -> FFT results are stored in the frequency buffer rxdataF */
      /* rxdataF stores SS/PBCH from beginning of buffers in the same symbol order as in time domain */

      for (int i = 0; i < NR_N_SYMBOLS_SSB; i++)
        nr_slot_fep_init_sync(ue, proc, i, frame_id * fp->samples_per_frame + ue->ssb_offset, false, rxdataF, link_type_dl);

#ifdef DEBUG_INITIAL_SYNCH
      LOG_I(PHY,"Calling sss detection (normal CP)\n");
#endif

      int freq_offset_sss = 0;
      bool ret_sss = rx_sss_nr(ue, proc, &metric_tdd_ncp, &phase_tdd_ncp, &freq_offset_sss, rxdataF);
      ret = !ret_sss;
      // digital compensation of FFO for SSB symbols
      if (ue->UE_fo_compensation){
        double s_time = 1/(1.0e3*fp->samples_per_subframe);  // sampling time
        double off_angle = -2*M_PI*s_time*freq_offset_sss;   // offset rotation angle compensation per sample

        // In SA we need to perform frequency offset correction until the end of buffer because we need to decode SIB1
        // and we do not know yet in which slot it goes.
        for (int n = frame_id * fp->samples_per_frame; n < (frame_id + 1) * fp->samples_per_frame; n++) {
          for (int ar=0; ar<fp->nb_antennas_rx; ar++) {
            const double re = ue->common_vars.rxdata[ar][n].r;
            const double im = ue->common_vars.rxdata[ar][n].i;
            ue->common_vars.rxdata[ar][n].r = (short)(round(re * cos(n * off_angle) - im * sin(n * off_angle)));
            ue->common_vars.rxdata[ar][n].i = (short)(round(re * sin(n * off_angle) + im * cos(n * off_angle)));
          }
        }

        ue->common_vars.freq_offset += freq_offset_sss;
      }

      if (ret==0) { //we got sss channel
        nr_gold_pbch(ue);
        ret = nr_pbch_detection(proc, ue, 1, rxdataF);  // start pbch detection at first symbol after pss
      }

      if (ret == 0) {

        // sync at symbol ue->symbol_offset
        // computing the offset wrt the beginning of the frame
        int mu = fp->numerology_index;
        // number of symbols with different prefix length
        // every 7*(1<<mu) symbols there is a different prefix length (38.211 5.3.1)
        int n_symb_prefix0 = (ue->symbol_offset/(7*(1<<mu)))+1;
        sync_pos_frame = n_symb_prefix0*(fp->ofdm_symbol_size + fp->nb_prefix_samples0)+(ue->symbol_offset-n_symb_prefix0)*(fp->ofdm_symbol_size + fp->nb_prefix_samples);
        // for a correct computation of frame number to sync with the one decoded at MIB we need to take into account in which of the n_frames we got sync
        ue->init_sync_frame = n_frames - 1 - frame_id;

        // compute the scramblingID_pdcch and the gold pdcch
        ue->scramblingID_pdcch = fp->Nid_cell;
        nr_gold_pdcch(ue,fp->Nid_cell);

        // compute the scrambling IDs for PDSCH DMRS
        for (int i=0; i<NR_NB_NSCID; i++) {
          ue->scramblingID_dlsch[i]=fp->Nid_cell;
          nr_gold_pdsch(ue, i, ue->scramblingID_dlsch[i]);
        }

        nr_init_csi_rs(fp, ue->nr_csi_info->nr_gold_csi_rs, fp->Nid_cell);

        // initialize the pusch dmrs
        for (int i=0; i<NR_NB_NSCID; i++) {
          ue->scramblingID_ulsch[i]=fp->Nid_cell;
          nr_init_pusch_dmrs(ue, ue->scramblingID_ulsch[i], i);
        }


        // we also need to take into account the shift by samples_per_frame in case the if is true
        if (ue->ssb_offset < sync_pos_frame){
          ue->rx_offset = fp->samples_per_frame - sync_pos_frame + ue->ssb_offset;
          ue->init_sync_frame += 1;
        }
        else
          ue->rx_offset = ue->ssb_offset - sync_pos_frame;
      }   

    /*
    int nb_prefix_samples0 = fp->nb_prefix_samples0;
    fp->nb_prefix_samples0 = fp->nb_prefix_samples;
	  
    nr_slot_fep(ue, proc, 0, 0, ue->ssb_offset, 0, NR_PDCCH_EST);
    nr_slot_fep(ue, proc, 1, 0, ue->ssb_offset, 0, NR_PDCCH_EST);
    fp->nb_prefix_samples0 = nb_prefix_samples0;	

    LOG_I(PHY,"[UE  %d] AUTOTEST Cell Sync : frame = %d, rx_offset %d, freq_offset %d \n",
              ue->Mod_id,
              ue->proc.proc_rxtx[0].frame_rx,
              ue->rx_offset,
              ue->common_vars.freq_offset );
    */


#ifdef DEBUG_INITIAL_SYNCH
      LOG_I(PHY,"TDD Normal prefix: CellId %d metric %d, phase %d, pbch %d\n",
            fp->Nid_cell,metric_tdd_ncp,phase_tdd_ncp,ret);
#endif

      }
      else {
#ifdef DEBUG_INITIAL_SYNCH
       LOG_I(PHY,"TDD Normal prefix: SSS error condition: sync_pos %d\n", sync_pos);
#endif
      }
      if (ret == 0) break;
   }
  }
  else {
    ret = -1;
  }

  /* Consider this is a false detection if the offset is > 1000 Hz 
     Not to be used now that offest estimation is in place
  if( (abs(ue->common_vars.freq_offset) > 150) && (ret == 0) )
  {
	  ret=-1;
	  LOG_E(HW, "Ignore MIB with high freq offset [%d Hz] estimation \n",ue->common_vars.freq_offset);
  }*/

  if (ret==0) {  // PBCH found so indicate sync to higher layers and configure frame parameters

    //#ifdef DEBUG_INITIAL_SYNCH

    LOG_I(PHY, "[UE%d] In synch, rx_offset %d samples\n",ue->Mod_id, ue->rx_offset);

    //#endif

    if (ue->UE_scan_carrier == 0) {

    #if UE_AUTOTEST_TRACE
      LOG_I(PHY,"[UE  %d] AUTOTEST Cell Sync : rx_offset %d, freq_offset %d \n",
              ue->Mod_id,
              ue->rx_offset,
              ue->common_vars.freq_offset );
    #endif

// send sync status to higher layers later when timing offset converge to target timing

    }

    LOG_I(PHY,
          "[UE %d] Measured Carrier Frequency %.0f Hz (offset %d Hz)\n",
          ue->Mod_id,
          openair0_cfg[0].rx_freq[0] + ue->common_vars.freq_offset,
          ue->common_vars.freq_offset);
  } else {
#ifdef DEBUG_INITIAL_SYNC
    LOG_I(PHY,"[UE%d] Initial sync : PBCH not ok\n",ue->Mod_id);
    LOG_I(PHY, "[UE%d] Initial sync : Estimated PSS position %d, Nid2 %d\n", ue->Mod_id, sync_pos, ue->common_vars.nid2);
    LOG_I(PHY,"[UE%d] Initial sync : Estimated Nid_cell %d, Frame_type %d\n",ue->Mod_id,
          frame_parms->Nid_cell,frame_parms->frame_type);
#endif

  }

  // gain control
  if (ret!=0) { //we are not synched, so we cannot use rssi measurement (which is based on channel estimates)
    rx_power = 0;

    // do a measurement on the best guess of the PSS
    //for (aarx=0; aarx<frame_parms->nb_antennas_rx; aarx++)
    //  rx_power += signal_energy(&ue->common_vars.rxdata[aarx][sync_pos2],
	//			frame_parms->ofdm_symbol_size+frame_parms->nb_prefix_samples);

    /*
    // do a measurement on the full frame
    for (aarx=0; aarx<frame_parms->nb_antennas_rx; aarx++)
      rx_power += signal_energy(&ue->common_vars.rxdata[aarx][0],
				frame_parms->samples_per_subframe*10);
    */

    // we might add a low-pass filter here later
    ue->measurements.rx_power_avg[0] = rx_power/fp->nb_antennas_rx;

    ue->measurements.rx_power_avg_dB[0] = dB_fixed(ue->measurements.rx_power_avg[0]);

#ifdef DEBUG_INITIAL_SYNCH
  LOG_I(PHY,"[UE%d] Initial sync : Estimated power: %d dB\n",ue->Mod_id,ue->measurements.rx_power_avg_dB[0] );
#endif

  }
  //  exit_fun("debug exit");
  VCD_SIGNAL_DUMPER_DUMP_FUNCTION_BY_NAME(VCD_SIGNAL_DUMPER_FUNCTIONS_NR_INITIAL_UE_SYNC, VCD_FUNCTION_OUT);
  return ret;
}

