/*
 * Copyright 2022 Sequans Communications.
 *
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
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

#pragma once

#include "SidlCompiler.h"
#include "SidlASN1Base.h"
#include "SidlBase.h"

SIDL_BEGIN_C_INTERFACE

typedef BIT_STRING_ELEMENT B1[1];

typedef BIT_STRING_ELEMENT B2[2];

typedef BIT_STRING_ELEMENT B3[3];

typedef BIT_STRING_ELEMENT B4[4];

typedef BIT_STRING_ELEMENT B5[5];

typedef BIT_STRING_ELEMENT B6[6];

typedef BIT_STRING_ELEMENT B7[7];

typedef BIT_STRING_ELEMENT B8[8];

typedef BIT_STRING_ELEMENT B10[10];

typedef BIT_STRING_ELEMENT B12[12];

typedef BIT_STRING_ELEMENT B14[14];

typedef BIT_STRING_ELEMENT B16[16];

typedef BIT_STRING_ELEMENT B18[18];

typedef BIT_STRING_ELEMENT B20[20];

typedef BIT_STRING_ELEMENT B24[24];

typedef BIT_STRING_ELEMENT B28[28];

typedef BIT_STRING_ELEMENT B32[32];

typedef BIT_STRING_ELEMENT B36[36];

typedef BIT_STRING_ELEMENT B40[40];

typedef BIT_STRING_ELEMENT B44[44];

typedef BIT_STRING_ELEMENT B45[45];

typedef BIT_STRING_ELEMENT B48[48];

typedef BIT_STRING_ELEMENT B64[64];

typedef BIT_STRING_ELEMENT B275[275];

typedef OCTET_STRING_ELEMENT O1[1];

typedef OCTET_STRING_ELEMENT O2[2];

typedef uint32_t SQN_NR_ARFCN_ValueNR;

enum SQN_NR_MIB_subCarrierSpacingCommon_e {
	SQN_NR_MIB_subCarrierSpacingCommon_e_scs15or60 = 0,
	SQN_NR_MIB_subCarrierSpacingCommon_e_scs30or120 = 1,
};

typedef enum SQN_NR_MIB_subCarrierSpacingCommon_e SQN_NR_MIB_subCarrierSpacingCommon_e;

enum SQN_NR_MIB_dmrs_TypeA_Position_e {
	SQN_NR_MIB_dmrs_TypeA_Position_e_pos2 = 0,
	SQN_NR_MIB_dmrs_TypeA_Position_e_pos3 = 1,
};

typedef enum SQN_NR_MIB_dmrs_TypeA_Position_e SQN_NR_MIB_dmrs_TypeA_Position_e;

typedef uint8_t SQN_NR_ControlResourceSetZero;

typedef uint8_t SQN_NR_SearchSpaceZero;

struct SQN_NR_PDCCH_ConfigSIB1 {
	SQN_NR_ControlResourceSetZero controlResourceSetZero;
	SQN_NR_SearchSpaceZero searchSpaceZero;
};

enum SQN_NR_MIB_cellBarred_e {
	SQN_NR_MIB_cellBarred_e_barred = 0,
	SQN_NR_MIB_cellBarred_e_notBarred = 1,
};

typedef enum SQN_NR_MIB_cellBarred_e SQN_NR_MIB_cellBarred_e;

enum SQN_NR_MIB_intraFreqReselection_e {
	SQN_NR_MIB_intraFreqReselection_e_allowed = 0,
	SQN_NR_MIB_intraFreqReselection_e_notAllowed = 1,
};

typedef enum SQN_NR_MIB_intraFreqReselection_e SQN_NR_MIB_intraFreqReselection_e;

struct SQN_NR_MIB {
	B6 systemFrameNumber;
	SQN_NR_MIB_subCarrierSpacingCommon_e subCarrierSpacingCommon;
	uint8_t ssb_SubcarrierOffset;
	SQN_NR_MIB_dmrs_TypeA_Position_e dmrs_TypeA_Position;
	struct SQN_NR_PDCCH_ConfigSIB1 pdcch_ConfigSIB1;
	SQN_NR_MIB_cellBarred_e cellBarred;
	SQN_NR_MIB_intraFreqReselection_e intraFreqReselection;
	B1 spare;
};

struct SQN_NR_BCCH_BCH_MessageType_messageClassExtension {
};

enum SQN_NR_BCCH_BCH_MessageType_Sel {
	SQN_NR_BCCH_BCH_MessageType_UNBOUND_VALUE = 0,
	SQN_NR_BCCH_BCH_MessageType_mib = 1,
	SQN_NR_BCCH_BCH_MessageType_messageClassExtension = 2,
};

union SQN_NR_BCCH_BCH_MessageType_Value {
	struct SQN_NR_MIB mib;
	struct SQN_NR_BCCH_BCH_MessageType_messageClassExtension messageClassExtension;
};

struct SQN_NR_BCCH_BCH_MessageType {
	enum SQN_NR_BCCH_BCH_MessageType_Sel d;
	union SQN_NR_BCCH_BCH_MessageType_Value v;
};

struct SQN_NR_BCCH_BCH_Message {
	struct SQN_NR_BCCH_BCH_MessageType message;
};

typedef uint8_t SQN_NR_RSRP_Range;

typedef uint8_t SQN_NR_RSRQ_Range;

typedef uint8_t SQN_NR_SINR_Range;

struct SQN_NR_RSRP_Range_SQN_NR_ThresholdNR_thresholdRSRP_Optional {
	bool d;
	SQN_NR_RSRP_Range v;
};

struct SQN_NR_RSRQ_Range_SQN_NR_ThresholdNR_thresholdRSRQ_Optional {
	bool d;
	SQN_NR_RSRQ_Range v;
};

struct SQN_NR_SINR_Range_SQN_NR_ThresholdNR_thresholdSINR_Optional {
	bool d;
	SQN_NR_SINR_Range v;
};

struct SQN_NR_ThresholdNR {
	struct SQN_NR_RSRP_Range_SQN_NR_ThresholdNR_thresholdRSRP_Optional thresholdRSRP;
	struct SQN_NR_RSRQ_Range_SQN_NR_ThresholdNR_thresholdRSRQ_Optional thresholdRSRQ;
	struct SQN_NR_SINR_Range_SQN_NR_ThresholdNR_thresholdSINR_Optional thresholdSINR;
};

enum SQN_NR_Q_OffsetRange_e {
	SQN_NR_Q_OffsetRange_e_dB_24 = 0,
	SQN_NR_Q_OffsetRange_e_dB_22 = 1,
	SQN_NR_Q_OffsetRange_e_dB_20 = 2,
	SQN_NR_Q_OffsetRange_e_dB_18 = 3,
	SQN_NR_Q_OffsetRange_e_dB_16 = 4,
	SQN_NR_Q_OffsetRange_e_dB_14 = 5,
	SQN_NR_Q_OffsetRange_e_dB_12 = 6,
	SQN_NR_Q_OffsetRange_e_dB_10 = 7,
	SQN_NR_Q_OffsetRange_e_dB_8 = 8,
	SQN_NR_Q_OffsetRange_e_dB_6 = 9,
	SQN_NR_Q_OffsetRange_e_dB_5 = 10,
	SQN_NR_Q_OffsetRange_e_dB_4 = 11,
	SQN_NR_Q_OffsetRange_e_dB_3 = 12,
	SQN_NR_Q_OffsetRange_e_dB_2 = 13,
	SQN_NR_Q_OffsetRange_e_dB_1 = 14,
	SQN_NR_Q_OffsetRange_e_dB0 = 15,
	SQN_NR_Q_OffsetRange_e_dB1 = 16,
	SQN_NR_Q_OffsetRange_e_dB2 = 17,
	SQN_NR_Q_OffsetRange_e_dB3 = 18,
	SQN_NR_Q_OffsetRange_e_dB4 = 19,
	SQN_NR_Q_OffsetRange_e_dB5 = 20,
	SQN_NR_Q_OffsetRange_e_dB6 = 21,
	SQN_NR_Q_OffsetRange_e_dB8 = 22,
	SQN_NR_Q_OffsetRange_e_dB10 = 23,
	SQN_NR_Q_OffsetRange_e_dB12 = 24,
	SQN_NR_Q_OffsetRange_e_dB14 = 25,
	SQN_NR_Q_OffsetRange_e_dB16 = 26,
	SQN_NR_Q_OffsetRange_e_dB18 = 27,
	SQN_NR_Q_OffsetRange_e_dB20 = 28,
	SQN_NR_Q_OffsetRange_e_dB22 = 29,
	SQN_NR_Q_OffsetRange_e_dB24 = 30,
};

typedef enum SQN_NR_Q_OffsetRange_e SQN_NR_Q_OffsetRange_e;

enum SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e {
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB0 = 0,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB1 = 1,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB2 = 2,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB3 = 3,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB4 = 4,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB5 = 5,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB6 = 6,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB8 = 7,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB10 = 8,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB12 = 9,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB14 = 10,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB16 = 11,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB18 = 12,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB20 = 13,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB22 = 14,
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e_dB24 = 15,
};

typedef enum SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e;

enum SQN_NR_MobilityStateParameters_t_Evaluation_e {
	SQN_NR_MobilityStateParameters_t_Evaluation_e_s30 = 0,
	SQN_NR_MobilityStateParameters_t_Evaluation_e_s60 = 1,
	SQN_NR_MobilityStateParameters_t_Evaluation_e_s120 = 2,
	SQN_NR_MobilityStateParameters_t_Evaluation_e_s180 = 3,
	SQN_NR_MobilityStateParameters_t_Evaluation_e_s240 = 4,
	SQN_NR_MobilityStateParameters_t_Evaluation_e_spare3 = 5,
	SQN_NR_MobilityStateParameters_t_Evaluation_e_spare2 = 6,
	SQN_NR_MobilityStateParameters_t_Evaluation_e_spare1 = 7,
};

typedef enum SQN_NR_MobilityStateParameters_t_Evaluation_e SQN_NR_MobilityStateParameters_t_Evaluation_e;

enum SQN_NR_MobilityStateParameters_t_HystNormal_e {
	SQN_NR_MobilityStateParameters_t_HystNormal_e_s30 = 0,
	SQN_NR_MobilityStateParameters_t_HystNormal_e_s60 = 1,
	SQN_NR_MobilityStateParameters_t_HystNormal_e_s120 = 2,
	SQN_NR_MobilityStateParameters_t_HystNormal_e_s180 = 3,
	SQN_NR_MobilityStateParameters_t_HystNormal_e_s240 = 4,
	SQN_NR_MobilityStateParameters_t_HystNormal_e_spare3 = 5,
	SQN_NR_MobilityStateParameters_t_HystNormal_e_spare2 = 6,
	SQN_NR_MobilityStateParameters_t_HystNormal_e_spare1 = 7,
};

typedef enum SQN_NR_MobilityStateParameters_t_HystNormal_e SQN_NR_MobilityStateParameters_t_HystNormal_e;

struct SQN_NR_MobilityStateParameters {
	SQN_NR_MobilityStateParameters_t_Evaluation_e t_Evaluation;
	SQN_NR_MobilityStateParameters_t_HystNormal_e t_HystNormal;
	uint8_t n_CellChangeMedium;
	uint8_t n_CellChangeHigh;
};

enum SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_Medium_e {
	SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_Medium_e_dB_6 = 0,
	SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_Medium_e_dB_4 = 1,
	SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_Medium_e_dB_2 = 2,
	SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_Medium_e_dB0 = 3,
};

typedef enum SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_Medium_e SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_Medium_e;

enum SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_High_e {
	SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_High_e_dB_6 = 0,
	SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_High_e_dB_4 = 1,
	SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_High_e_dB_2 = 2,
	SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_High_e_dB0 = 3,
};

typedef enum SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_High_e SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_High_e;

struct SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSF {
	SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_Medium_e sf_Medium;
	SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSFsf_High_e sf_High;
};

struct SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars {
	struct SQN_NR_MobilityStateParameters mobilityStateParameters;
	struct SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_q_HystSF q_HystSF;
};

struct uint8_t_SQN_NR_SIB2_cellReselectionInfoCommon_nrofSS_BlocksToAverage_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_ThresholdNR_SQN_NR_SIB2_cellReselectionInfoCommon_absThreshSS_BlocksConsolidation_Optional {
	bool d;
	struct SQN_NR_ThresholdNR v;
};

struct SQN_NR_Q_OffsetRange_e_SQN_NR_SIB2_cellReselectionInfoCommon_rangeToBestCell_Optional {
	bool d;
	SQN_NR_Q_OffsetRange_e v;
};

struct SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_speedStateReselectionPars_Optional {
	bool d;
	struct SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars v;
};

struct SQN_NR_SIB2_cellReselectionInfoCommon {
	struct uint8_t_SQN_NR_SIB2_cellReselectionInfoCommon_nrofSS_BlocksToAverage_Optional nrofSS_BlocksToAverage;
	struct SQN_NR_ThresholdNR_SQN_NR_SIB2_cellReselectionInfoCommon_absThreshSS_BlocksConsolidation_Optional absThreshSS_BlocksConsolidation;
	struct SQN_NR_Q_OffsetRange_e_SQN_NR_SIB2_cellReselectionInfoCommon_rangeToBestCell_Optional rangeToBestCell;
	SQN_NR_SIB2_cellReselectionInfoCommon_q_Hyst_e q_Hyst;
	struct SQN_NR_SIB2_cellReselectionInfoCommon_speedStateReselectionPars_speedStateReselectionPars_Optional speedStateReselectionPars;
};

typedef uint8_t SQN_NR_ReselectionThreshold;

typedef uint8_t SQN_NR_ReselectionThresholdQ;

typedef uint8_t SQN_NR_CellReselectionPriority;

enum SQN_NR_CellReselectionSubPriority_e {
	SQN_NR_CellReselectionSubPriority_e_oDot2 = 0,
	SQN_NR_CellReselectionSubPriority_e_oDot4 = 1,
	SQN_NR_CellReselectionSubPriority_e_oDot6 = 2,
	SQN_NR_CellReselectionSubPriority_e_oDot8 = 3,
};

typedef enum SQN_NR_CellReselectionSubPriority_e SQN_NR_CellReselectionSubPriority_e;

struct SQN_NR_ReselectionThreshold_SQN_NR_SIB2_cellReselectionServingFreqInfo_s_NonIntraSearchP_Optional {
	bool d;
	SQN_NR_ReselectionThreshold v;
};

struct SQN_NR_ReselectionThresholdQ_SQN_NR_SIB2_cellReselectionServingFreqInfo_s_NonIntraSearchQ_Optional {
	bool d;
	SQN_NR_ReselectionThresholdQ v;
};

struct SQN_NR_ReselectionThresholdQ_SQN_NR_SIB2_cellReselectionServingFreqInfo_threshServingLowQ_Optional {
	bool d;
	SQN_NR_ReselectionThresholdQ v;
};

struct SQN_NR_CellReselectionSubPriority_e_SQN_NR_SIB2_cellReselectionServingFreqInfo_cellReselectionSubPriority_Optional {
	bool d;
	SQN_NR_CellReselectionSubPriority_e v;
};

struct SQN_NR_SIB2_cellReselectionServingFreqInfo {
	struct SQN_NR_ReselectionThreshold_SQN_NR_SIB2_cellReselectionServingFreqInfo_s_NonIntraSearchP_Optional s_NonIntraSearchP;
	struct SQN_NR_ReselectionThresholdQ_SQN_NR_SIB2_cellReselectionServingFreqInfo_s_NonIntraSearchQ_Optional s_NonIntraSearchQ;
	SQN_NR_ReselectionThreshold threshServingLowP;
	struct SQN_NR_ReselectionThresholdQ_SQN_NR_SIB2_cellReselectionServingFreqInfo_threshServingLowQ_Optional threshServingLowQ;
	SQN_NR_CellReselectionPriority cellReselectionPriority;
	struct SQN_NR_CellReselectionSubPriority_e_SQN_NR_SIB2_cellReselectionServingFreqInfo_cellReselectionSubPriority_Optional cellReselectionSubPriority;
};

typedef int8_t SQN_NR_Q_RxLevMin;

typedef int8_t SQN_NR_Q_QualMin;

typedef uint8_t SQN_NR_T_Reselection;

typedef uint16_t SQN_NR_FreqBandIndicatorNR;

typedef int8_t SQN_NR_P_Max;

typedef uint8_t SQN_NR_AdditionalSpectrumEmission;

struct SQN_NR_P_Max_SQN_NR_NR_NS_PmaxValue_additionalPmax_Optional {
	bool d;
	SQN_NR_P_Max v;
};

struct SQN_NR_NR_NS_PmaxValue {
	struct SQN_NR_P_Max_SQN_NR_NR_NS_PmaxValue_additionalPmax_Optional additionalPmax;
	SQN_NR_AdditionalSpectrumEmission additionalSpectrumEmission;
};

struct SQN_NR_NR_NS_PmaxValue_SQN_NR_NR_NS_PmaxList_Dynamic {
	size_t d;
	struct SQN_NR_NR_NS_PmaxValue* v;
};

typedef struct SQN_NR_NR_NS_PmaxValue_SQN_NR_NR_NS_PmaxList_Dynamic SQN_NR_NR_NS_PmaxList;

struct SQN_NR_FreqBandIndicatorNR_SQN_NR_NR_MultiBandInfo_freqBandIndicatorNR_Optional {
	bool d;
	SQN_NR_FreqBandIndicatorNR v;
};

struct SQN_NR_NR_NS_PmaxList_SQN_NR_NR_MultiBandInfo_nr_NS_PmaxList_Optional {
	bool d;
	SQN_NR_NR_NS_PmaxList v;
};

struct SQN_NR_NR_MultiBandInfo {
	struct SQN_NR_FreqBandIndicatorNR_SQN_NR_NR_MultiBandInfo_freqBandIndicatorNR_Optional freqBandIndicatorNR;
	struct SQN_NR_NR_NS_PmaxList_SQN_NR_NR_MultiBandInfo_nr_NS_PmaxList_Optional nr_NS_PmaxList;
};

struct SQN_NR_NR_MultiBandInfo_SQN_NR_MultiFrequencyBandListNR_SIB_Dynamic {
	size_t d;
	struct SQN_NR_NR_MultiBandInfo* v;
};

typedef struct SQN_NR_NR_MultiBandInfo_SQN_NR_MultiFrequencyBandListNR_SIB_Dynamic SQN_NR_MultiFrequencyBandListNR_SIB;

enum SQN_NR_SSB_MTC_periodicityAndOffset_Sel {
	SQN_NR_SSB_MTC_periodicityAndOffset_UNBOUND_VALUE = 0,
	SQN_NR_SSB_MTC_periodicityAndOffset_sf5 = 1,
	SQN_NR_SSB_MTC_periodicityAndOffset_sf10 = 2,
	SQN_NR_SSB_MTC_periodicityAndOffset_sf20 = 3,
	SQN_NR_SSB_MTC_periodicityAndOffset_sf40 = 4,
	SQN_NR_SSB_MTC_periodicityAndOffset_sf80 = 5,
	SQN_NR_SSB_MTC_periodicityAndOffset_sf160 = 6,
};

union SQN_NR_SSB_MTC_periodicityAndOffset_Value {
	uint8_t sf5;
	uint8_t sf10;
	uint8_t sf20;
	uint8_t sf40;
	uint8_t sf80;
	uint8_t sf160;
};

struct SQN_NR_SSB_MTC_periodicityAndOffset {
	enum SQN_NR_SSB_MTC_periodicityAndOffset_Sel d;
	union SQN_NR_SSB_MTC_periodicityAndOffset_Value v;
};

enum SQN_NR_SSB_MTC_duration_e {
	SQN_NR_SSB_MTC_duration_e_sf1 = 0,
	SQN_NR_SSB_MTC_duration_e_sf2 = 1,
	SQN_NR_SSB_MTC_duration_e_sf3 = 2,
	SQN_NR_SSB_MTC_duration_e_sf4 = 3,
	SQN_NR_SSB_MTC_duration_e_sf5 = 4,
};

typedef enum SQN_NR_SSB_MTC_duration_e SQN_NR_SSB_MTC_duration_e;

struct SQN_NR_SSB_MTC {
	struct SQN_NR_SSB_MTC_periodicityAndOffset periodicityAndOffset;
	SQN_NR_SSB_MTC_duration_e duration;
};

struct SQN_NR_SS_RSSI_Measurement {
	BIT_STRING measurementSlots;
	uint8_t endSymbol;
};

enum SQN_NR_SSB_ToMeasure_Sel {
	SQN_NR_SSB_ToMeasure_UNBOUND_VALUE = 0,
	SQN_NR_SSB_ToMeasure_shortBitmap = 1,
	SQN_NR_SSB_ToMeasure_mediumBitmap = 2,
	SQN_NR_SSB_ToMeasure_longBitmap = 3,
};

union SQN_NR_SSB_ToMeasure_Value {
	B4 shortBitmap;
	B8 mediumBitmap;
	B64 longBitmap;
};

struct SQN_NR_SSB_ToMeasure {
	enum SQN_NR_SSB_ToMeasure_Sel d;
	union SQN_NR_SSB_ToMeasure_Value v;
};

enum SQN_NR_SpeedStateScaleFactors_sf_Medium_e {
	SQN_NR_SpeedStateScaleFactors_sf_Medium_e_oDot25 = 0,
	SQN_NR_SpeedStateScaleFactors_sf_Medium_e_oDot5 = 1,
	SQN_NR_SpeedStateScaleFactors_sf_Medium_e_oDot75 = 2,
	SQN_NR_SpeedStateScaleFactors_sf_Medium_e_lDot0 = 3,
};

typedef enum SQN_NR_SpeedStateScaleFactors_sf_Medium_e SQN_NR_SpeedStateScaleFactors_sf_Medium_e;

enum SQN_NR_SpeedStateScaleFactors_sf_High_e {
	SQN_NR_SpeedStateScaleFactors_sf_High_e_oDot25 = 0,
	SQN_NR_SpeedStateScaleFactors_sf_High_e_oDot5 = 1,
	SQN_NR_SpeedStateScaleFactors_sf_High_e_oDot75 = 2,
	SQN_NR_SpeedStateScaleFactors_sf_High_e_lDot0 = 3,
};

typedef enum SQN_NR_SpeedStateScaleFactors_sf_High_e SQN_NR_SpeedStateScaleFactors_sf_High_e;

struct SQN_NR_SpeedStateScaleFactors {
	SQN_NR_SpeedStateScaleFactors_sf_Medium_e sf_Medium;
	SQN_NR_SpeedStateScaleFactors_sf_High_e sf_High;
};

typedef uint16_t SQN_NR_PhysCellId;

enum SQN_NR_SSB_MTC2_LP_r16_periodicity_e {
	SQN_NR_SSB_MTC2_LP_r16_periodicity_e_sf10 = 0,
	SQN_NR_SSB_MTC2_LP_r16_periodicity_e_sf20 = 1,
	SQN_NR_SSB_MTC2_LP_r16_periodicity_e_sf40 = 2,
	SQN_NR_SSB_MTC2_LP_r16_periodicity_e_sf80 = 3,
	SQN_NR_SSB_MTC2_LP_r16_periodicity_e_sf160 = 4,
	SQN_NR_SSB_MTC2_LP_r16_periodicity_e_spare3 = 5,
	SQN_NR_SSB_MTC2_LP_r16_periodicity_e_spare2 = 6,
	SQN_NR_SSB_MTC2_LP_r16_periodicity_e_spare1 = 7,
};

typedef enum SQN_NR_SSB_MTC2_LP_r16_periodicity_e SQN_NR_SSB_MTC2_LP_r16_periodicity_e;

struct SQN_NR_PhysCellId_SQN_NR_SSB_MTC2_LP_r16_pci_List_Dynamic {
	size_t d;
	SQN_NR_PhysCellId* v;
};

struct SQN_NR_PhysCellId_SQN_NR_SSB_MTC2_LP_r16_pci_List_DynamicOptional {
	bool d;
	struct SQN_NR_PhysCellId_SQN_NR_SSB_MTC2_LP_r16_pci_List_Dynamic v;
};

struct SQN_NR_SSB_MTC2_LP_r16 {
	struct SQN_NR_PhysCellId_SQN_NR_SSB_MTC2_LP_r16_pci_List_DynamicOptional pci_List;
	SQN_NR_SSB_MTC2_LP_r16_periodicity_e periodicity;
};

enum SQN_NR_SSB_PositionQCL_Relation_r16_e {
	SQN_NR_SSB_PositionQCL_Relation_r16_e_n1 = 0,
	SQN_NR_SSB_PositionQCL_Relation_r16_e_n2 = 1,
	SQN_NR_SSB_PositionQCL_Relation_r16_e_n4 = 2,
	SQN_NR_SSB_PositionQCL_Relation_r16_e_n8 = 3,
};

typedef enum SQN_NR_SSB_PositionQCL_Relation_r16_e SQN_NR_SSB_PositionQCL_Relation_r16_e;

struct SQN_NR_Q_RxLevMin_SQN_NR_SIB2_intraFreqCellReselectionInfo_q_RxLevMinSUL_Optional {
	bool d;
	SQN_NR_Q_RxLevMin v;
};

struct SQN_NR_Q_QualMin_SQN_NR_SIB2_intraFreqCellReselectionInfo_q_QualMin_Optional {
	bool d;
	SQN_NR_Q_QualMin v;
};

struct SQN_NR_ReselectionThresholdQ_SQN_NR_SIB2_intraFreqCellReselectionInfo_s_IntraSearchQ_Optional {
	bool d;
	SQN_NR_ReselectionThresholdQ v;
};

struct SQN_NR_MultiFrequencyBandListNR_SIB_SQN_NR_SIB2_intraFreqCellReselectionInfo_frequencyBandList_Optional {
	bool d;
	SQN_NR_MultiFrequencyBandListNR_SIB v;
};

struct SQN_NR_MultiFrequencyBandListNR_SIB_SQN_NR_SIB2_intraFreqCellReselectionInfo_frequencyBandListSUL_Optional {
	bool d;
	SQN_NR_MultiFrequencyBandListNR_SIB v;
};

struct SQN_NR_P_Max_SQN_NR_SIB2_intraFreqCellReselectionInfo_p_Max_Optional {
	bool d;
	SQN_NR_P_Max v;
};

struct SQN_NR_SSB_MTC_SQN_NR_SIB2_intraFreqCellReselectionInfo_smtc_Optional {
	bool d;
	struct SQN_NR_SSB_MTC v;
};

struct SQN_NR_SS_RSSI_Measurement_SQN_NR_SIB2_intraFreqCellReselectionInfo_ss_RSSI_Measurement_Optional {
	bool d;
	struct SQN_NR_SS_RSSI_Measurement v;
};

struct SQN_NR_SSB_ToMeasure_SQN_NR_SIB2_intraFreqCellReselectionInfo_ssb_ToMeasure_Optional {
	bool d;
	struct SQN_NR_SSB_ToMeasure v;
};

struct SQN_NR_SpeedStateScaleFactors_SQN_NR_SIB2_intraFreqCellReselectionInfo_t_ReselectionNR_SF_Optional {
	bool d;
	struct SQN_NR_SpeedStateScaleFactors v;
};

struct SQN_NR_SSB_MTC2_LP_r16_SQN_NR_SIB2_intraFreqCellReselectionInfo_smtc2_LP_r16_Optional {
	bool d;
	struct SQN_NR_SSB_MTC2_LP_r16 v;
};

struct SQN_NR_SSB_PositionQCL_Relation_r16_e_SQN_NR_SIB2_intraFreqCellReselectionInfo_ssb_PositionQCL_Common_r16_Optional {
	bool d;
	SQN_NR_SSB_PositionQCL_Relation_r16_e v;
};

struct SQN_NR_SIB2_intraFreqCellReselectionInfo {
	SQN_NR_Q_RxLevMin q_RxLevMin;
	struct SQN_NR_Q_RxLevMin_SQN_NR_SIB2_intraFreqCellReselectionInfo_q_RxLevMinSUL_Optional q_RxLevMinSUL;
	struct SQN_NR_Q_QualMin_SQN_NR_SIB2_intraFreqCellReselectionInfo_q_QualMin_Optional q_QualMin;
	SQN_NR_ReselectionThreshold s_IntraSearchP;
	struct SQN_NR_ReselectionThresholdQ_SQN_NR_SIB2_intraFreqCellReselectionInfo_s_IntraSearchQ_Optional s_IntraSearchQ;
	SQN_NR_T_Reselection t_ReselectionNR;
	struct SQN_NR_MultiFrequencyBandListNR_SIB_SQN_NR_SIB2_intraFreqCellReselectionInfo_frequencyBandList_Optional frequencyBandList;
	struct SQN_NR_MultiFrequencyBandListNR_SIB_SQN_NR_SIB2_intraFreqCellReselectionInfo_frequencyBandListSUL_Optional frequencyBandListSUL;
	struct SQN_NR_P_Max_SQN_NR_SIB2_intraFreqCellReselectionInfo_p_Max_Optional p_Max;
	struct SQN_NR_SSB_MTC_SQN_NR_SIB2_intraFreqCellReselectionInfo_smtc_Optional smtc;
	struct SQN_NR_SS_RSSI_Measurement_SQN_NR_SIB2_intraFreqCellReselectionInfo_ss_RSSI_Measurement_Optional ss_RSSI_Measurement;
	struct SQN_NR_SSB_ToMeasure_SQN_NR_SIB2_intraFreqCellReselectionInfo_ssb_ToMeasure_Optional ssb_ToMeasure;
	bool deriveSSB_IndexFromCell;
	struct SQN_NR_SpeedStateScaleFactors_SQN_NR_SIB2_intraFreqCellReselectionInfo_t_ReselectionNR_SF_Optional t_ReselectionNR_SF;
	struct SQN_NR_SSB_MTC2_LP_r16_SQN_NR_SIB2_intraFreqCellReselectionInfo_smtc2_LP_r16_Optional smtc2_LP_r16;
	struct SQN_NR_SSB_PositionQCL_Relation_r16_e_SQN_NR_SIB2_intraFreqCellReselectionInfo_ssb_PositionQCL_Common_r16_Optional ssb_PositionQCL_Common_r16;
};

enum SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_s_SearchDeltaP_r16_e {
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_s_SearchDeltaP_r16_e_dB3 = 0,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_s_SearchDeltaP_r16_e_dB6 = 1,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_s_SearchDeltaP_r16_e_dB9 = 2,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_s_SearchDeltaP_r16_e_dB12 = 3,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_s_SearchDeltaP_r16_e_dB15 = 4,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_s_SearchDeltaP_r16_e_spare3 = 5,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_s_SearchDeltaP_r16_e_spare2 = 6,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_s_SearchDeltaP_r16_e_spare1 = 7,
};

typedef enum SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_s_SearchDeltaP_r16_e SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_s_SearchDeltaP_r16_e;

enum SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e {
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_s5 = 0,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_s10 = 1,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_s20 = 2,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_s30 = 3,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_s60 = 4,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_s120 = 5,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_s180 = 6,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_s240 = 7,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_s300 = 8,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_spare7 = 9,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_spare6 = 10,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_spare5 = 11,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_spare4 = 12,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_spare3 = 13,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_spare2 = 14,
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e_spare1 = 15,
};

typedef enum SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e;

struct SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16 {
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_s_SearchDeltaP_r16_e s_SearchDeltaP_r16;
	SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_t_SearchDeltaP_r16_e t_SearchDeltaP_r16;
};

struct SQN_NR_ReselectionThresholdQ_SQN_NR_SIB2_relaxedMeasurement_r16_cellEdgeEvaluation_r16_s_SearchThresholdQ_r16_Optional {
	bool d;
	SQN_NR_ReselectionThresholdQ v;
};

struct SQN_NR_SIB2_relaxedMeasurement_r16_cellEdgeEvaluation_r16 {
	SQN_NR_ReselectionThreshold s_SearchThresholdP_r16;
	struct SQN_NR_ReselectionThresholdQ_SQN_NR_SIB2_relaxedMeasurement_r16_cellEdgeEvaluation_r16_s_SearchThresholdQ_r16_Optional s_SearchThresholdQ_r16;
};

enum SQN_NR_SIB2_relaxedMeasurement_r16_combineRelaxedMeasCondition_r16_e {
	SQN_NR_SIB2_relaxedMeasurement_r16_combineRelaxedMeasCondition_r16_e_true = 0,
};

typedef enum SQN_NR_SIB2_relaxedMeasurement_r16_combineRelaxedMeasCondition_r16_e SQN_NR_SIB2_relaxedMeasurement_r16_combineRelaxedMeasCondition_r16_e;

enum SQN_NR_SIB2_relaxedMeasurement_r16_highPriorityMeasRelax_r16_e {
	SQN_NR_SIB2_relaxedMeasurement_r16_highPriorityMeasRelax_r16_e_true = 0,
};

typedef enum SQN_NR_SIB2_relaxedMeasurement_r16_highPriorityMeasRelax_r16_e SQN_NR_SIB2_relaxedMeasurement_r16_highPriorityMeasRelax_r16_e;

struct SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_lowMobilityEvaluation_r16_Optional {
	bool d;
	struct SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16 v;
};

struct SQN_NR_SIB2_relaxedMeasurement_r16_cellEdgeEvaluation_r16_cellEdgeEvaluation_r16_Optional {
	bool d;
	struct SQN_NR_SIB2_relaxedMeasurement_r16_cellEdgeEvaluation_r16 v;
};

struct SQN_NR_SIB2_relaxedMeasurement_r16_combineRelaxedMeasCondition_r16_e_combineRelaxedMeasCondition_r16_Optional {
	bool d;
	SQN_NR_SIB2_relaxedMeasurement_r16_combineRelaxedMeasCondition_r16_e v;
};

struct SQN_NR_SIB2_relaxedMeasurement_r16_highPriorityMeasRelax_r16_e_highPriorityMeasRelax_r16_Optional {
	bool d;
	SQN_NR_SIB2_relaxedMeasurement_r16_highPriorityMeasRelax_r16_e v;
};

struct SQN_NR_SIB2_relaxedMeasurement_r16 {
	struct SQN_NR_SIB2_relaxedMeasurement_r16_lowMobilityEvaluation_r16_lowMobilityEvaluation_r16_Optional lowMobilityEvaluation_r16;
	struct SQN_NR_SIB2_relaxedMeasurement_r16_cellEdgeEvaluation_r16_cellEdgeEvaluation_r16_Optional cellEdgeEvaluation_r16;
	struct SQN_NR_SIB2_relaxedMeasurement_r16_combineRelaxedMeasCondition_r16_e_combineRelaxedMeasCondition_r16_Optional combineRelaxedMeasCondition_r16;
	struct SQN_NR_SIB2_relaxedMeasurement_r16_highPriorityMeasRelax_r16_e_highPriorityMeasRelax_r16_Optional highPriorityMeasRelax_r16;
};

struct SQN_NR_SIB2_relaxedMeasurement_r16_relaxedMeasurement_r16_Optional {
	bool d;
	struct SQN_NR_SIB2_relaxedMeasurement_r16 v;
};

struct SQN_NR_SIB2 {
	struct SQN_NR_SIB2_cellReselectionInfoCommon cellReselectionInfoCommon;
	struct SQN_NR_SIB2_cellReselectionServingFreqInfo cellReselectionServingFreqInfo;
	struct SQN_NR_SIB2_intraFreqCellReselectionInfo intraFreqCellReselectionInfo;
	struct SQN_NR_SIB2_relaxedMeasurement_r16_relaxedMeasurement_r16_Optional relaxedMeasurement_r16;
};

struct uint8_t_SQN_NR_IntraFreqNeighCellInfo_q_RxLevMinOffsetCell_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_IntraFreqNeighCellInfo_q_RxLevMinOffsetCellSUL_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_IntraFreqNeighCellInfo_q_QualMinOffsetCell_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_IntraFreqNeighCellInfo {
	SQN_NR_PhysCellId physCellId;
	SQN_NR_Q_OffsetRange_e q_OffsetCell;
	struct uint8_t_SQN_NR_IntraFreqNeighCellInfo_q_RxLevMinOffsetCell_Optional q_RxLevMinOffsetCell;
	struct uint8_t_SQN_NR_IntraFreqNeighCellInfo_q_RxLevMinOffsetCellSUL_Optional q_RxLevMinOffsetCellSUL;
	struct uint8_t_SQN_NR_IntraFreqNeighCellInfo_q_QualMinOffsetCell_Optional q_QualMinOffsetCell;
};

struct SQN_NR_IntraFreqNeighCellInfo_SQN_NR_IntraFreqNeighCellList_Dynamic {
	size_t d;
	struct SQN_NR_IntraFreqNeighCellInfo* v;
};

typedef struct SQN_NR_IntraFreqNeighCellInfo_SQN_NR_IntraFreqNeighCellList_Dynamic SQN_NR_IntraFreqNeighCellList;

enum SQN_NR_PCI_Range_range_e {
	SQN_NR_PCI_Range_range_e_n4 = 0,
	SQN_NR_PCI_Range_range_e_n8 = 1,
	SQN_NR_PCI_Range_range_e_n12 = 2,
	SQN_NR_PCI_Range_range_e_n16 = 3,
	SQN_NR_PCI_Range_range_e_n24 = 4,
	SQN_NR_PCI_Range_range_e_n32 = 5,
	SQN_NR_PCI_Range_range_e_n48 = 6,
	SQN_NR_PCI_Range_range_e_n64 = 7,
	SQN_NR_PCI_Range_range_e_n84 = 8,
	SQN_NR_PCI_Range_range_e_n96 = 9,
	SQN_NR_PCI_Range_range_e_n128 = 10,
	SQN_NR_PCI_Range_range_e_n168 = 11,
	SQN_NR_PCI_Range_range_e_n252 = 12,
	SQN_NR_PCI_Range_range_e_n504 = 13,
	SQN_NR_PCI_Range_range_e_n1008 = 14,
	SQN_NR_PCI_Range_range_e_spare1 = 15,
};

typedef enum SQN_NR_PCI_Range_range_e SQN_NR_PCI_Range_range_e;

struct SQN_NR_PCI_Range_range_e_range_Optional {
	bool d;
	SQN_NR_PCI_Range_range_e v;
};

struct SQN_NR_PCI_Range {
	SQN_NR_PhysCellId start;
	struct SQN_NR_PCI_Range_range_e_range_Optional range;
};

struct SQN_NR_PCI_Range_SQN_NR_IntraFreqBlackCellList_Dynamic {
	size_t d;
	struct SQN_NR_PCI_Range* v;
};

typedef struct SQN_NR_PCI_Range_SQN_NR_IntraFreqBlackCellList_Dynamic SQN_NR_IntraFreqBlackCellList;

struct SQN_NR_SSB_PositionQCL_Relation_r16_e_SQN_NR_IntraFreqNeighCellInfo_v1610_ssb_PositionQCL_r16_Optional {
	bool d;
	SQN_NR_SSB_PositionQCL_Relation_r16_e v;
};

struct SQN_NR_IntraFreqNeighCellInfo_v1610 {
	struct SQN_NR_SSB_PositionQCL_Relation_r16_e_SQN_NR_IntraFreqNeighCellInfo_v1610_ssb_PositionQCL_r16_Optional ssb_PositionQCL_r16;
};

struct SQN_NR_IntraFreqNeighCellInfo_v1610_SQN_NR_IntraFreqNeighCellList_v1610_Dynamic {
	size_t d;
	struct SQN_NR_IntraFreqNeighCellInfo_v1610* v;
};

typedef struct SQN_NR_IntraFreqNeighCellInfo_v1610_SQN_NR_IntraFreqNeighCellList_v1610_Dynamic SQN_NR_IntraFreqNeighCellList_v1610;

struct SQN_NR_PCI_Range_SQN_NR_IntraFreqWhiteCellList_r16_Dynamic {
	size_t d;
	struct SQN_NR_PCI_Range* v;
};

typedef struct SQN_NR_PCI_Range_SQN_NR_IntraFreqWhiteCellList_r16_Dynamic SQN_NR_IntraFreqWhiteCellList_r16;

struct SQN_NR_PCI_Range_SQN_NR_IntraFreqCAG_CellListPerPLMN_r16_cag_CellList_r16_Dynamic {
	size_t d;
	struct SQN_NR_PCI_Range* v;
};

struct SQN_NR_IntraFreqCAG_CellListPerPLMN_r16 {
	uint8_t plmn_IdentityIndex_r16;
	struct SQN_NR_PCI_Range_SQN_NR_IntraFreqCAG_CellListPerPLMN_r16_cag_CellList_r16_Dynamic cag_CellList_r16;
};

struct SQN_NR_IntraFreqNeighCellList_SQN_NR_SIB3_intraFreqNeighCellList_Optional {
	bool d;
	SQN_NR_IntraFreqNeighCellList v;
};

struct SQN_NR_IntraFreqBlackCellList_SQN_NR_SIB3_intraFreqBlackCellList_Optional {
	bool d;
	SQN_NR_IntraFreqBlackCellList v;
};

struct OCTET_STRING_SQN_NR_SIB3_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_IntraFreqNeighCellList_v1610_SQN_NR_SIB3_intraFreqNeighCellList_v1610_Optional {
	bool d;
	SQN_NR_IntraFreqNeighCellList_v1610 v;
};

struct SQN_NR_IntraFreqWhiteCellList_r16_SQN_NR_SIB3_intraFreqWhiteCellList_r16_Optional {
	bool d;
	SQN_NR_IntraFreqWhiteCellList_r16 v;
};

struct SQN_NR_SIB3_SQN_NR_IntraFreqCAG_CellListPerPLMN_r16_intraFreqCAG_CellList_r16_Dynamic {
	size_t d;
	struct SQN_NR_IntraFreqCAG_CellListPerPLMN_r16* v;
};

struct SQN_NR_IntraFreqCAG_CellListPerPLMN_r16_SQN_NR_SIB3_intraFreqCAG_CellList_r16_DynamicOptional {
	bool d;
	struct SQN_NR_SIB3_SQN_NR_IntraFreqCAG_CellListPerPLMN_r16_intraFreqCAG_CellList_r16_Dynamic v;
};

struct SQN_NR_SIB3 {
	struct SQN_NR_IntraFreqNeighCellList_SQN_NR_SIB3_intraFreqNeighCellList_Optional intraFreqNeighCellList;
	struct SQN_NR_IntraFreqBlackCellList_SQN_NR_SIB3_intraFreqBlackCellList_Optional intraFreqBlackCellList;
	struct OCTET_STRING_SQN_NR_SIB3_lateNonCriticalExtension_Optional lateNonCriticalExtension;
	struct SQN_NR_IntraFreqNeighCellList_v1610_SQN_NR_SIB3_intraFreqNeighCellList_v1610_Optional intraFreqNeighCellList_v1610;
	struct SQN_NR_IntraFreqWhiteCellList_r16_SQN_NR_SIB3_intraFreqWhiteCellList_r16_Optional intraFreqWhiteCellList_r16;
	struct SQN_NR_IntraFreqCAG_CellListPerPLMN_r16_SQN_NR_SIB3_intraFreqCAG_CellList_r16_DynamicOptional intraFreqCAG_CellList_r16;
};

enum SQN_NR_SubcarrierSpacing_e {
	SQN_NR_SubcarrierSpacing_e_kHz15 = 0,
	SQN_NR_SubcarrierSpacing_e_kHz30 = 1,
	SQN_NR_SubcarrierSpacing_e_kHz60 = 2,
	SQN_NR_SubcarrierSpacing_e_kHz120 = 3,
	SQN_NR_SubcarrierSpacing_e_kHz240 = 4,
	SQN_NR_SubcarrierSpacing_e_spare3 = 5,
	SQN_NR_SubcarrierSpacing_e_spare2 = 6,
	SQN_NR_SubcarrierSpacing_e_spare1 = 7,
};

typedef enum SQN_NR_SubcarrierSpacing_e SQN_NR_SubcarrierSpacing_e;

struct SQN_NR_InterFreqCarrierFreqInfo_threshX_Q {
	SQN_NR_ReselectionThresholdQ threshX_HighQ;
	SQN_NR_ReselectionThresholdQ threshX_LowQ;
};

struct uint8_t_SQN_NR_InterFreqNeighCellInfo_q_RxLevMinOffsetCell_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_InterFreqNeighCellInfo_q_RxLevMinOffsetCellSUL_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_InterFreqNeighCellInfo_q_QualMinOffsetCell_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_InterFreqNeighCellInfo {
	SQN_NR_PhysCellId physCellId;
	SQN_NR_Q_OffsetRange_e q_OffsetCell;
	struct uint8_t_SQN_NR_InterFreqNeighCellInfo_q_RxLevMinOffsetCell_Optional q_RxLevMinOffsetCell;
	struct uint8_t_SQN_NR_InterFreqNeighCellInfo_q_RxLevMinOffsetCellSUL_Optional q_RxLevMinOffsetCellSUL;
	struct uint8_t_SQN_NR_InterFreqNeighCellInfo_q_QualMinOffsetCell_Optional q_QualMinOffsetCell;
};

struct SQN_NR_InterFreqNeighCellInfo_SQN_NR_InterFreqNeighCellList_Dynamic {
	size_t d;
	struct SQN_NR_InterFreqNeighCellInfo* v;
};

typedef struct SQN_NR_InterFreqNeighCellInfo_SQN_NR_InterFreqNeighCellList_Dynamic SQN_NR_InterFreqNeighCellList;

struct SQN_NR_PCI_Range_SQN_NR_InterFreqBlackCellList_Dynamic {
	size_t d;
	struct SQN_NR_PCI_Range* v;
};

typedef struct SQN_NR_PCI_Range_SQN_NR_InterFreqBlackCellList_Dynamic SQN_NR_InterFreqBlackCellList;

struct SQN_NR_MultiFrequencyBandListNR_SIB_SQN_NR_InterFreqCarrierFreqInfo_frequencyBandList_Optional {
	bool d;
	SQN_NR_MultiFrequencyBandListNR_SIB v;
};

struct SQN_NR_MultiFrequencyBandListNR_SIB_SQN_NR_InterFreqCarrierFreqInfo_frequencyBandListSUL_Optional {
	bool d;
	SQN_NR_MultiFrequencyBandListNR_SIB v;
};

struct uint8_t_SQN_NR_InterFreqCarrierFreqInfo_nrofSS_BlocksToAverage_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_ThresholdNR_SQN_NR_InterFreqCarrierFreqInfo_absThreshSS_BlocksConsolidation_Optional {
	bool d;
	struct SQN_NR_ThresholdNR v;
};

struct SQN_NR_SSB_MTC_SQN_NR_InterFreqCarrierFreqInfo_smtc_Optional {
	bool d;
	struct SQN_NR_SSB_MTC v;
};

struct SQN_NR_SSB_ToMeasure_SQN_NR_InterFreqCarrierFreqInfo_ssb_ToMeasure_Optional {
	bool d;
	struct SQN_NR_SSB_ToMeasure v;
};

struct SQN_NR_SS_RSSI_Measurement_SQN_NR_InterFreqCarrierFreqInfo_ss_RSSI_Measurement_Optional {
	bool d;
	struct SQN_NR_SS_RSSI_Measurement v;
};

struct SQN_NR_Q_RxLevMin_SQN_NR_InterFreqCarrierFreqInfo_q_RxLevMinSUL_Optional {
	bool d;
	SQN_NR_Q_RxLevMin v;
};

struct SQN_NR_Q_QualMin_SQN_NR_InterFreqCarrierFreqInfo_q_QualMin_Optional {
	bool d;
	SQN_NR_Q_QualMin v;
};

struct SQN_NR_P_Max_SQN_NR_InterFreqCarrierFreqInfo_p_Max_Optional {
	bool d;
	SQN_NR_P_Max v;
};

struct SQN_NR_SpeedStateScaleFactors_SQN_NR_InterFreqCarrierFreqInfo_t_ReselectionNR_SF_Optional {
	bool d;
	struct SQN_NR_SpeedStateScaleFactors v;
};

struct SQN_NR_InterFreqCarrierFreqInfo_threshX_Q_threshX_Q_Optional {
	bool d;
	struct SQN_NR_InterFreqCarrierFreqInfo_threshX_Q v;
};

struct SQN_NR_CellReselectionPriority_SQN_NR_InterFreqCarrierFreqInfo_cellReselectionPriority_Optional {
	bool d;
	SQN_NR_CellReselectionPriority v;
};

struct SQN_NR_CellReselectionSubPriority_e_SQN_NR_InterFreqCarrierFreqInfo_cellReselectionSubPriority_Optional {
	bool d;
	SQN_NR_CellReselectionSubPriority_e v;
};

struct SQN_NR_Q_OffsetRange_e_SQN_NR_InterFreqCarrierFreqInfo_q_OffsetFreq_Optional {
	bool d;
	SQN_NR_Q_OffsetRange_e v;
};

struct SQN_NR_InterFreqNeighCellList_SQN_NR_InterFreqCarrierFreqInfo_interFreqNeighCellList_Optional {
	bool d;
	SQN_NR_InterFreqNeighCellList v;
};

struct SQN_NR_InterFreqBlackCellList_SQN_NR_InterFreqCarrierFreqInfo_interFreqBlackCellList_Optional {
	bool d;
	SQN_NR_InterFreqBlackCellList v;
};

struct SQN_NR_InterFreqCarrierFreqInfo {
	SQN_NR_ARFCN_ValueNR dl_CarrierFreq;
	struct SQN_NR_MultiFrequencyBandListNR_SIB_SQN_NR_InterFreqCarrierFreqInfo_frequencyBandList_Optional frequencyBandList;
	struct SQN_NR_MultiFrequencyBandListNR_SIB_SQN_NR_InterFreqCarrierFreqInfo_frequencyBandListSUL_Optional frequencyBandListSUL;
	struct uint8_t_SQN_NR_InterFreqCarrierFreqInfo_nrofSS_BlocksToAverage_Optional nrofSS_BlocksToAverage;
	struct SQN_NR_ThresholdNR_SQN_NR_InterFreqCarrierFreqInfo_absThreshSS_BlocksConsolidation_Optional absThreshSS_BlocksConsolidation;
	struct SQN_NR_SSB_MTC_SQN_NR_InterFreqCarrierFreqInfo_smtc_Optional smtc;
	SQN_NR_SubcarrierSpacing_e ssbSubcarrierSpacing;
	struct SQN_NR_SSB_ToMeasure_SQN_NR_InterFreqCarrierFreqInfo_ssb_ToMeasure_Optional ssb_ToMeasure;
	bool deriveSSB_IndexFromCell;
	struct SQN_NR_SS_RSSI_Measurement_SQN_NR_InterFreqCarrierFreqInfo_ss_RSSI_Measurement_Optional ss_RSSI_Measurement;
	SQN_NR_Q_RxLevMin q_RxLevMin;
	struct SQN_NR_Q_RxLevMin_SQN_NR_InterFreqCarrierFreqInfo_q_RxLevMinSUL_Optional q_RxLevMinSUL;
	struct SQN_NR_Q_QualMin_SQN_NR_InterFreqCarrierFreqInfo_q_QualMin_Optional q_QualMin;
	struct SQN_NR_P_Max_SQN_NR_InterFreqCarrierFreqInfo_p_Max_Optional p_Max;
	SQN_NR_T_Reselection t_ReselectionNR;
	struct SQN_NR_SpeedStateScaleFactors_SQN_NR_InterFreqCarrierFreqInfo_t_ReselectionNR_SF_Optional t_ReselectionNR_SF;
	SQN_NR_ReselectionThreshold threshX_HighP;
	SQN_NR_ReselectionThreshold threshX_LowP;
	struct SQN_NR_InterFreqCarrierFreqInfo_threshX_Q_threshX_Q_Optional threshX_Q;
	struct SQN_NR_CellReselectionPriority_SQN_NR_InterFreqCarrierFreqInfo_cellReselectionPriority_Optional cellReselectionPriority;
	struct SQN_NR_CellReselectionSubPriority_e_SQN_NR_InterFreqCarrierFreqInfo_cellReselectionSubPriority_Optional cellReselectionSubPriority;
	struct SQN_NR_Q_OffsetRange_e_SQN_NR_InterFreqCarrierFreqInfo_q_OffsetFreq_Optional q_OffsetFreq;
	struct SQN_NR_InterFreqNeighCellList_SQN_NR_InterFreqCarrierFreqInfo_interFreqNeighCellList_Optional interFreqNeighCellList;
	struct SQN_NR_InterFreqBlackCellList_SQN_NR_InterFreqCarrierFreqInfo_interFreqBlackCellList_Optional interFreqBlackCellList;
};

struct SQN_NR_InterFreqCarrierFreqInfo_SQN_NR_InterFreqCarrierFreqList_Dynamic {
	size_t d;
	struct SQN_NR_InterFreqCarrierFreqInfo* v;
};

typedef struct SQN_NR_InterFreqCarrierFreqInfo_SQN_NR_InterFreqCarrierFreqList_Dynamic SQN_NR_InterFreqCarrierFreqList;

struct SQN_NR_SSB_PositionQCL_Relation_r16_e_SQN_NR_InterFreqNeighCellInfo_v1610_ssb_PositionQCL_r16_Optional {
	bool d;
	SQN_NR_SSB_PositionQCL_Relation_r16_e v;
};

struct SQN_NR_InterFreqNeighCellInfo_v1610 {
	struct SQN_NR_SSB_PositionQCL_Relation_r16_e_SQN_NR_InterFreqNeighCellInfo_v1610_ssb_PositionQCL_r16_Optional ssb_PositionQCL_r16;
};

struct SQN_NR_InterFreqNeighCellInfo_v1610_SQN_NR_InterFreqNeighCellList_v1610_Dynamic {
	size_t d;
	struct SQN_NR_InterFreqNeighCellInfo_v1610* v;
};

typedef struct SQN_NR_InterFreqNeighCellInfo_v1610_SQN_NR_InterFreqNeighCellList_v1610_Dynamic SQN_NR_InterFreqNeighCellList_v1610;

struct SQN_NR_PCI_Range_SQN_NR_InterFreqWhiteCellList_r16_Dynamic {
	size_t d;
	struct SQN_NR_PCI_Range* v;
};

typedef struct SQN_NR_PCI_Range_SQN_NR_InterFreqWhiteCellList_r16_Dynamic SQN_NR_InterFreqWhiteCellList_r16;

struct SQN_NR_PCI_Range_SQN_NR_InterFreqCAG_CellListPerPLMN_r16_cag_CellList_r16_Dynamic {
	size_t d;
	struct SQN_NR_PCI_Range* v;
};

struct SQN_NR_InterFreqCAG_CellListPerPLMN_r16 {
	uint8_t plmn_IdentityIndex_r16;
	struct SQN_NR_PCI_Range_SQN_NR_InterFreqCAG_CellListPerPLMN_r16_cag_CellList_r16_Dynamic cag_CellList_r16;
};

struct SQN_NR_InterFreqNeighCellList_v1610_SQN_NR_InterFreqCarrierFreqInfo_v1610_interFreqNeighCellList_v1610_Optional {
	bool d;
	SQN_NR_InterFreqNeighCellList_v1610 v;
};

struct SQN_NR_SSB_MTC2_LP_r16_SQN_NR_InterFreqCarrierFreqInfo_v1610_smtc2_LP_r16_Optional {
	bool d;
	struct SQN_NR_SSB_MTC2_LP_r16 v;
};

struct SQN_NR_InterFreqWhiteCellList_r16_SQN_NR_InterFreqCarrierFreqInfo_v1610_interFreqWhiteCellList_r16_Optional {
	bool d;
	SQN_NR_InterFreqWhiteCellList_r16 v;
};

struct SQN_NR_SSB_PositionQCL_Relation_r16_e_SQN_NR_InterFreqCarrierFreqInfo_v1610_ssb_PositionQCL_Common_r16_Optional {
	bool d;
	SQN_NR_SSB_PositionQCL_Relation_r16_e v;
};

struct SQN_NR_InterFreqCarrierFreqInfo_v1610_SQN_NR_InterFreqCAG_CellListPerPLMN_r16_interFreqCAG_CellList_r16_Dynamic {
	size_t d;
	struct SQN_NR_InterFreqCAG_CellListPerPLMN_r16* v;
};

struct SQN_NR_InterFreqCAG_CellListPerPLMN_r16_SQN_NR_InterFreqCarrierFreqInfo_v1610_interFreqCAG_CellList_r16_DynamicOptional {
	bool d;
	struct SQN_NR_InterFreqCarrierFreqInfo_v1610_SQN_NR_InterFreqCAG_CellListPerPLMN_r16_interFreqCAG_CellList_r16_Dynamic v;
};

struct SQN_NR_InterFreqCarrierFreqInfo_v1610 {
	struct SQN_NR_InterFreqNeighCellList_v1610_SQN_NR_InterFreqCarrierFreqInfo_v1610_interFreqNeighCellList_v1610_Optional interFreqNeighCellList_v1610;
	struct SQN_NR_SSB_MTC2_LP_r16_SQN_NR_InterFreqCarrierFreqInfo_v1610_smtc2_LP_r16_Optional smtc2_LP_r16;
	struct SQN_NR_InterFreqWhiteCellList_r16_SQN_NR_InterFreqCarrierFreqInfo_v1610_interFreqWhiteCellList_r16_Optional interFreqWhiteCellList_r16;
	struct SQN_NR_SSB_PositionQCL_Relation_r16_e_SQN_NR_InterFreqCarrierFreqInfo_v1610_ssb_PositionQCL_Common_r16_Optional ssb_PositionQCL_Common_r16;
	struct SQN_NR_InterFreqCAG_CellListPerPLMN_r16_SQN_NR_InterFreqCarrierFreqInfo_v1610_interFreqCAG_CellList_r16_DynamicOptional interFreqCAG_CellList_r16;
};

struct SQN_NR_InterFreqCarrierFreqInfo_v1610_SQN_NR_InterFreqCarrierFreqList_v1610_Dynamic {
	size_t d;
	struct SQN_NR_InterFreqCarrierFreqInfo_v1610* v;
};

typedef struct SQN_NR_InterFreqCarrierFreqInfo_v1610_SQN_NR_InterFreqCarrierFreqList_v1610_Dynamic SQN_NR_InterFreqCarrierFreqList_v1610;

struct OCTET_STRING_SQN_NR_SIB4_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_InterFreqCarrierFreqList_v1610_SQN_NR_SIB4_interFreqCarrierFreqList_v1610_Optional {
	bool d;
	SQN_NR_InterFreqCarrierFreqList_v1610 v;
};

struct SQN_NR_SIB4 {
	SQN_NR_InterFreqCarrierFreqList interFreqCarrierFreqList;
	struct OCTET_STRING_SQN_NR_SIB4_lateNonCriticalExtension_Optional lateNonCriticalExtension;
	struct SQN_NR_InterFreqCarrierFreqList_v1610_SQN_NR_SIB4_interFreqCarrierFreqList_v1610_Optional interFreqCarrierFreqList_v1610;
};

typedef uint32_t SQN_NR_ARFCN_ValueEUTRA;

typedef uint16_t SQN_NR_FreqBandIndicatorEUTRA;

struct int8_t_SQN_NR_EUTRA_NS_PmaxValue_additionalPmax_Optional {
	bool d;
	int8_t v;
};

struct uint16_t_SQN_NR_EUTRA_NS_PmaxValue_additionalSpectrumEmission_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_EUTRA_NS_PmaxValue {
	struct int8_t_SQN_NR_EUTRA_NS_PmaxValue_additionalPmax_Optional additionalPmax;
	struct uint16_t_SQN_NR_EUTRA_NS_PmaxValue_additionalSpectrumEmission_Optional additionalSpectrumEmission;
};

struct SQN_NR_EUTRA_NS_PmaxValue_SQN_NR_EUTRA_NS_PmaxList_Dynamic {
	size_t d;
	struct SQN_NR_EUTRA_NS_PmaxValue* v;
};

typedef struct SQN_NR_EUTRA_NS_PmaxValue_SQN_NR_EUTRA_NS_PmaxList_Dynamic SQN_NR_EUTRA_NS_PmaxList;

struct SQN_NR_EUTRA_NS_PmaxList_SQN_NR_EUTRA_MultiBandInfo_eutra_NS_PmaxList_Optional {
	bool d;
	SQN_NR_EUTRA_NS_PmaxList v;
};

struct SQN_NR_EUTRA_MultiBandInfo {
	SQN_NR_FreqBandIndicatorEUTRA eutra_FreqBandIndicator;
	struct SQN_NR_EUTRA_NS_PmaxList_SQN_NR_EUTRA_MultiBandInfo_eutra_NS_PmaxList_Optional eutra_NS_PmaxList;
};

struct SQN_NR_EUTRA_MultiBandInfo_SQN_NR_EUTRA_MultiBandInfoList_Dynamic {
	size_t d;
	struct SQN_NR_EUTRA_MultiBandInfo* v;
};

typedef struct SQN_NR_EUTRA_MultiBandInfo_SQN_NR_EUTRA_MultiBandInfoList_Dynamic SQN_NR_EUTRA_MultiBandInfoList;

typedef uint16_t SQN_NR_EUTRA_PhysCellId;

enum SQN_NR_EUTRA_Q_OffsetRange_e {
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_24 = 0,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_22 = 1,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_20 = 2,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_18 = 3,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_16 = 4,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_14 = 5,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_12 = 6,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_10 = 7,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_8 = 8,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_6 = 9,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_5 = 10,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_4 = 11,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_3 = 12,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_2 = 13,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB_1 = 14,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB0 = 15,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB1 = 16,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB2 = 17,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB3 = 18,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB4 = 19,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB5 = 20,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB6 = 21,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB8 = 22,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB10 = 23,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB12 = 24,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB14 = 25,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB16 = 26,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB18 = 27,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB20 = 28,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB22 = 29,
	SQN_NR_EUTRA_Q_OffsetRange_e_dB24 = 30,
};

typedef enum SQN_NR_EUTRA_Q_OffsetRange_e SQN_NR_EUTRA_Q_OffsetRange_e;

struct uint8_t_SQN_NR_EUTRA_FreqNeighCellInfo_q_RxLevMinOffsetCell_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_EUTRA_FreqNeighCellInfo_q_QualMinOffsetCell_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_EUTRA_FreqNeighCellInfo {
	SQN_NR_EUTRA_PhysCellId physCellId;
	SQN_NR_EUTRA_Q_OffsetRange_e dummy;
	struct uint8_t_SQN_NR_EUTRA_FreqNeighCellInfo_q_RxLevMinOffsetCell_Optional q_RxLevMinOffsetCell;
	struct uint8_t_SQN_NR_EUTRA_FreqNeighCellInfo_q_QualMinOffsetCell_Optional q_QualMinOffsetCell;
};

struct SQN_NR_EUTRA_FreqNeighCellInfo_SQN_NR_EUTRA_FreqNeighCellList_Dynamic {
	size_t d;
	struct SQN_NR_EUTRA_FreqNeighCellInfo* v;
};

typedef struct SQN_NR_EUTRA_FreqNeighCellInfo_SQN_NR_EUTRA_FreqNeighCellList_Dynamic SQN_NR_EUTRA_FreqNeighCellList;

enum SQN_NR_EUTRA_PhysCellIdRange_range_e {
	SQN_NR_EUTRA_PhysCellIdRange_range_e_n4 = 0,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_n8 = 1,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_n12 = 2,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_n16 = 3,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_n24 = 4,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_n32 = 5,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_n48 = 6,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_n64 = 7,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_n84 = 8,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_n96 = 9,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_n128 = 10,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_n168 = 11,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_n252 = 12,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_n504 = 13,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_spare2 = 14,
	SQN_NR_EUTRA_PhysCellIdRange_range_e_spare1 = 15,
};

typedef enum SQN_NR_EUTRA_PhysCellIdRange_range_e SQN_NR_EUTRA_PhysCellIdRange_range_e;

struct SQN_NR_EUTRA_PhysCellIdRange_range_e_range_Optional {
	bool d;
	SQN_NR_EUTRA_PhysCellIdRange_range_e v;
};

struct SQN_NR_EUTRA_PhysCellIdRange {
	SQN_NR_EUTRA_PhysCellId start;
	struct SQN_NR_EUTRA_PhysCellIdRange_range_e_range_Optional range;
};

struct SQN_NR_EUTRA_PhysCellIdRange_SQN_NR_EUTRA_FreqBlackCellList_Dynamic {
	size_t d;
	struct SQN_NR_EUTRA_PhysCellIdRange* v;
};

typedef struct SQN_NR_EUTRA_PhysCellIdRange_SQN_NR_EUTRA_FreqBlackCellList_Dynamic SQN_NR_EUTRA_FreqBlackCellList;

enum SQN_NR_EUTRA_AllowedMeasBandwidth_e {
	SQN_NR_EUTRA_AllowedMeasBandwidth_e_mbw6 = 0,
	SQN_NR_EUTRA_AllowedMeasBandwidth_e_mbw15 = 1,
	SQN_NR_EUTRA_AllowedMeasBandwidth_e_mbw25 = 2,
	SQN_NR_EUTRA_AllowedMeasBandwidth_e_mbw50 = 3,
	SQN_NR_EUTRA_AllowedMeasBandwidth_e_mbw75 = 4,
	SQN_NR_EUTRA_AllowedMeasBandwidth_e_mbw100 = 5,
};

typedef enum SQN_NR_EUTRA_AllowedMeasBandwidth_e SQN_NR_EUTRA_AllowedMeasBandwidth_e;

typedef bool SQN_NR_EUTRA_PresenceAntennaPort1;

struct SQN_NR_CarrierFreqEUTRA_threshX_Q {
	SQN_NR_ReselectionThresholdQ threshX_HighQ;
	SQN_NR_ReselectionThresholdQ threshX_LowQ;
};

struct SQN_NR_EUTRA_MultiBandInfoList_SQN_NR_CarrierFreqEUTRA_eutra_multiBandInfoList_Optional {
	bool d;
	SQN_NR_EUTRA_MultiBandInfoList v;
};

struct SQN_NR_EUTRA_FreqNeighCellList_SQN_NR_CarrierFreqEUTRA_eutra_FreqNeighCellList_Optional {
	bool d;
	SQN_NR_EUTRA_FreqNeighCellList v;
};

struct SQN_NR_EUTRA_FreqBlackCellList_SQN_NR_CarrierFreqEUTRA_eutra_BlackCellList_Optional {
	bool d;
	SQN_NR_EUTRA_FreqBlackCellList v;
};

struct SQN_NR_CellReselectionPriority_SQN_NR_CarrierFreqEUTRA_cellReselectionPriority_Optional {
	bool d;
	SQN_NR_CellReselectionPriority v;
};

struct SQN_NR_CellReselectionSubPriority_e_SQN_NR_CarrierFreqEUTRA_cellReselectionSubPriority_Optional {
	bool d;
	SQN_NR_CellReselectionSubPriority_e v;
};

struct SQN_NR_CarrierFreqEUTRA_threshX_Q_threshX_Q_Optional {
	bool d;
	struct SQN_NR_CarrierFreqEUTRA_threshX_Q v;
};

struct SQN_NR_CarrierFreqEUTRA {
	SQN_NR_ARFCN_ValueEUTRA carrierFreq;
	struct SQN_NR_EUTRA_MultiBandInfoList_SQN_NR_CarrierFreqEUTRA_eutra_multiBandInfoList_Optional eutra_multiBandInfoList;
	struct SQN_NR_EUTRA_FreqNeighCellList_SQN_NR_CarrierFreqEUTRA_eutra_FreqNeighCellList_Optional eutra_FreqNeighCellList;
	struct SQN_NR_EUTRA_FreqBlackCellList_SQN_NR_CarrierFreqEUTRA_eutra_BlackCellList_Optional eutra_BlackCellList;
	SQN_NR_EUTRA_AllowedMeasBandwidth_e allowedMeasBandwidth;
	SQN_NR_EUTRA_PresenceAntennaPort1 presenceAntennaPort1;
	struct SQN_NR_CellReselectionPriority_SQN_NR_CarrierFreqEUTRA_cellReselectionPriority_Optional cellReselectionPriority;
	struct SQN_NR_CellReselectionSubPriority_e_SQN_NR_CarrierFreqEUTRA_cellReselectionSubPriority_Optional cellReselectionSubPriority;
	SQN_NR_ReselectionThreshold threshX_High;
	SQN_NR_ReselectionThreshold threshX_Low;
	int8_t q_RxLevMin;
	int8_t q_QualMin;
	int8_t p_MaxEUTRA;
	struct SQN_NR_CarrierFreqEUTRA_threshX_Q_threshX_Q_Optional threshX_Q;
};

struct SQN_NR_CarrierFreqEUTRA_SQN_NR_CarrierFreqListEUTRA_Dynamic {
	size_t d;
	struct SQN_NR_CarrierFreqEUTRA* v;
};

typedef struct SQN_NR_CarrierFreqEUTRA_SQN_NR_CarrierFreqListEUTRA_Dynamic SQN_NR_CarrierFreqListEUTRA;

enum SQN_NR_CarrierFreqEUTRA_v1610_highSpeedEUTRACarrier_r16_e {
	SQN_NR_CarrierFreqEUTRA_v1610_highSpeedEUTRACarrier_r16_e_true = 0,
};

typedef enum SQN_NR_CarrierFreqEUTRA_v1610_highSpeedEUTRACarrier_r16_e SQN_NR_CarrierFreqEUTRA_v1610_highSpeedEUTRACarrier_r16_e;

struct SQN_NR_CarrierFreqEUTRA_v1610_highSpeedEUTRACarrier_r16_e_highSpeedEUTRACarrier_r16_Optional {
	bool d;
	SQN_NR_CarrierFreqEUTRA_v1610_highSpeedEUTRACarrier_r16_e v;
};

struct SQN_NR_CarrierFreqEUTRA_v1610 {
	struct SQN_NR_CarrierFreqEUTRA_v1610_highSpeedEUTRACarrier_r16_e_highSpeedEUTRACarrier_r16_Optional highSpeedEUTRACarrier_r16;
};

struct SQN_NR_CarrierFreqEUTRA_v1610_SQN_NR_CarrierFreqListEUTRA_v1610_Dynamic {
	size_t d;
	struct SQN_NR_CarrierFreqEUTRA_v1610* v;
};

typedef struct SQN_NR_CarrierFreqEUTRA_v1610_SQN_NR_CarrierFreqListEUTRA_v1610_Dynamic SQN_NR_CarrierFreqListEUTRA_v1610;

struct SQN_NR_CarrierFreqListEUTRA_SQN_NR_SIB5_carrierFreqListEUTRA_Optional {
	bool d;
	SQN_NR_CarrierFreqListEUTRA v;
};

struct SQN_NR_SpeedStateScaleFactors_SQN_NR_SIB5_t_ReselectionEUTRA_SF_Optional {
	bool d;
	struct SQN_NR_SpeedStateScaleFactors v;
};

struct OCTET_STRING_SQN_NR_SIB5_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_CarrierFreqListEUTRA_v1610_SQN_NR_SIB5_carrierFreqListEUTRA_v1610_Optional {
	bool d;
	SQN_NR_CarrierFreqListEUTRA_v1610 v;
};

struct SQN_NR_SIB5 {
	struct SQN_NR_CarrierFreqListEUTRA_SQN_NR_SIB5_carrierFreqListEUTRA_Optional carrierFreqListEUTRA;
	SQN_NR_T_Reselection t_ReselectionEUTRA;
	struct SQN_NR_SpeedStateScaleFactors_SQN_NR_SIB5_t_ReselectionEUTRA_SF_Optional t_ReselectionEUTRA_SF;
	struct OCTET_STRING_SQN_NR_SIB5_lateNonCriticalExtension_Optional lateNonCriticalExtension;
	struct SQN_NR_CarrierFreqListEUTRA_v1610_SQN_NR_SIB5_carrierFreqListEUTRA_v1610_Optional carrierFreqListEUTRA_v1610;
};

struct OCTET_STRING_SQN_NR_SIB6_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_SIB6 {
	B16 messageIdentifier;
	B16 serialNumber;
	O2 warningType;
	struct OCTET_STRING_SQN_NR_SIB6_lateNonCriticalExtension_Optional lateNonCriticalExtension;
};

enum SQN_NR_SIB7_warningMessageSegmentType_e {
	SQN_NR_SIB7_warningMessageSegmentType_e_notLastSegment = 0,
	SQN_NR_SIB7_warningMessageSegmentType_e_lastSegment = 1,
};

typedef enum SQN_NR_SIB7_warningMessageSegmentType_e SQN_NR_SIB7_warningMessageSegmentType_e;

struct O1_SQN_NR_SIB7_dataCodingScheme_Optional {
	bool d;
	O1 v;
};

struct OCTET_STRING_SQN_NR_SIB7_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_SIB7 {
	B16 messageIdentifier;
	B16 serialNumber;
	SQN_NR_SIB7_warningMessageSegmentType_e warningMessageSegmentType;
	uint8_t warningMessageSegmentNumber;
	OCTET_STRING warningMessageSegment;
	struct O1_SQN_NR_SIB7_dataCodingScheme_Optional dataCodingScheme;
	struct OCTET_STRING_SQN_NR_SIB7_lateNonCriticalExtension_Optional lateNonCriticalExtension;
};

enum SQN_NR_SIB8_warningMessageSegmentType_e {
	SQN_NR_SIB8_warningMessageSegmentType_e_notLastSegment = 0,
	SQN_NR_SIB8_warningMessageSegmentType_e_lastSegment = 1,
};

typedef enum SQN_NR_SIB8_warningMessageSegmentType_e SQN_NR_SIB8_warningMessageSegmentType_e;

struct O1_SQN_NR_SIB8_dataCodingScheme_Optional {
	bool d;
	O1 v;
};

struct OCTET_STRING_SQN_NR_SIB8_warningAreaCoordinatesSegment_Optional {
	bool d;
	OCTET_STRING v;
};

struct OCTET_STRING_SQN_NR_SIB8_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_SIB8 {
	B16 messageIdentifier;
	B16 serialNumber;
	SQN_NR_SIB8_warningMessageSegmentType_e warningMessageSegmentType;
	uint8_t warningMessageSegmentNumber;
	OCTET_STRING warningMessageSegment;
	struct O1_SQN_NR_SIB8_dataCodingScheme_Optional dataCodingScheme;
	struct OCTET_STRING_SQN_NR_SIB8_warningAreaCoordinatesSegment_Optional warningAreaCoordinatesSegment;
	struct OCTET_STRING_SQN_NR_SIB8_lateNonCriticalExtension_Optional lateNonCriticalExtension;
};

struct B2_SQN_NR_SIB9_timeInfo_dayLightSavingTime_Optional {
	bool d;
	B2 v;
};

struct int16_t_SQN_NR_SIB9_timeInfo_leapSeconds_Optional {
	bool d;
	int16_t v;
};

struct int8_t_SQN_NR_SIB9_timeInfo_localTimeOffset_Optional {
	bool d;
	int8_t v;
};

struct SQN_NR_SIB9_timeInfo {
	uint64_t timeInfoUTC;
	struct B2_SQN_NR_SIB9_timeInfo_dayLightSavingTime_Optional dayLightSavingTime;
	struct int16_t_SQN_NR_SIB9_timeInfo_leapSeconds_Optional leapSeconds;
	struct int8_t_SQN_NR_SIB9_timeInfo_localTimeOffset_Optional localTimeOffset;
};

struct SQN_NR_ReferenceTime_r16 {
	uint32_t refDays_r16;
	uint32_t refSeconds_r16;
	uint16_t refMilliSeconds_r16;
	uint32_t refTenNanoSeconds_r16;
};

enum SQN_NR_ReferenceTimeInfo_r16_timeInfoType_r16_e {
	SQN_NR_ReferenceTimeInfo_r16_timeInfoType_r16_e_localClock = 0,
};

typedef enum SQN_NR_ReferenceTimeInfo_r16_timeInfoType_r16_e SQN_NR_ReferenceTimeInfo_r16_timeInfoType_r16_e;

struct uint16_t_SQN_NR_ReferenceTimeInfo_r16_uncertainty_r16_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_ReferenceTimeInfo_r16_timeInfoType_r16_e_timeInfoType_r16_Optional {
	bool d;
	SQN_NR_ReferenceTimeInfo_r16_timeInfoType_r16_e v;
};

struct uint16_t_SQN_NR_ReferenceTimeInfo_r16_referenceSFN_r16_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_ReferenceTimeInfo_r16 {
	struct SQN_NR_ReferenceTime_r16 time_r16;
	struct uint16_t_SQN_NR_ReferenceTimeInfo_r16_uncertainty_r16_Optional uncertainty_r16;
	struct SQN_NR_ReferenceTimeInfo_r16_timeInfoType_r16_e_timeInfoType_r16_Optional timeInfoType_r16;
	struct uint16_t_SQN_NR_ReferenceTimeInfo_r16_referenceSFN_r16_Optional referenceSFN_r16;
};

struct SQN_NR_SIB9_timeInfo_timeInfo_Optional {
	bool d;
	struct SQN_NR_SIB9_timeInfo v;
};

struct OCTET_STRING_SQN_NR_SIB9_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_ReferenceTimeInfo_r16_SQN_NR_SIB9_referenceTimeInfo_r16_Optional {
	bool d;
	struct SQN_NR_ReferenceTimeInfo_r16 v;
};

struct SQN_NR_SIB9 {
	struct SQN_NR_SIB9_timeInfo_timeInfo_Optional timeInfo;
	struct OCTET_STRING_SQN_NR_SIB9_lateNonCriticalExtension_Optional lateNonCriticalExtension;
	struct SQN_NR_ReferenceTimeInfo_r16_SQN_NR_SIB9_referenceTimeInfo_r16_Optional referenceTimeInfo_r16;
};

struct OCTET_STRING_SQN_NR_HRNN_r16_hrnn_r16_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_HRNN_r16 {
	struct OCTET_STRING_SQN_NR_HRNN_r16_hrnn_r16_Optional hrnn_r16;
};

struct SQN_NR_HRNN_r16_SQN_NR_HRNN_List_r16_Dynamic {
	size_t d;
	struct SQN_NR_HRNN_r16* v;
};

typedef struct SQN_NR_HRNN_r16_SQN_NR_HRNN_List_r16_Dynamic SQN_NR_HRNN_List_r16;

struct SQN_NR_HRNN_List_r16_SQN_NR_SIB10_r16_hrnn_List_r16_Optional {
	bool d;
	SQN_NR_HRNN_List_r16 v;
};

struct OCTET_STRING_SQN_NR_SIB10_r16_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_SIB10_r16 {
	struct SQN_NR_HRNN_List_r16_SQN_NR_SIB10_r16_hrnn_List_r16_Optional hrnn_List_r16;
	struct OCTET_STRING_SQN_NR_SIB10_r16_lateNonCriticalExtension_Optional lateNonCriticalExtension;
};

struct SQN_NR_FreqBandIndicatorNR_SQN_NR_MultiFrequencyBandListNR_Dynamic {
	size_t d;
	SQN_NR_FreqBandIndicatorNR* v;
};

typedef struct SQN_NR_FreqBandIndicatorNR_SQN_NR_MultiFrequencyBandListNR_Dynamic SQN_NR_MultiFrequencyBandListNR;

struct SQN_NR_PCI_Range_SQN_NR_CellListNR_r16_Dynamic {
	size_t d;
	struct SQN_NR_PCI_Range* v;
};

typedef struct SQN_NR_PCI_Range_SQN_NR_CellListNR_r16_Dynamic SQN_NR_CellListNR_r16;

enum SQN_NR_MeasIdleCarrierNR_r16_reportQuantities_r16_e {
	SQN_NR_MeasIdleCarrierNR_r16_reportQuantities_r16_e_rsrp = 0,
	SQN_NR_MeasIdleCarrierNR_r16_reportQuantities_r16_e_rsrq = 1,
	SQN_NR_MeasIdleCarrierNR_r16_reportQuantities_r16_e_both = 2,
};

typedef enum SQN_NR_MeasIdleCarrierNR_r16_reportQuantities_r16_e SQN_NR_MeasIdleCarrierNR_r16_reportQuantities_r16_e;

struct SQN_NR_RSRP_Range_SQN_NR_MeasIdleCarrierNR_r16_qualityThreshold_r16_idleRSRP_Threshold_NR_r16_Optional {
	bool d;
	SQN_NR_RSRP_Range v;
};

struct SQN_NR_RSRQ_Range_SQN_NR_MeasIdleCarrierNR_r16_qualityThreshold_r16_idleRSRQ_Threshold_NR_r16_Optional {
	bool d;
	SQN_NR_RSRQ_Range v;
};

struct SQN_NR_MeasIdleCarrierNR_r16_qualityThreshold_r16 {
	struct SQN_NR_RSRP_Range_SQN_NR_MeasIdleCarrierNR_r16_qualityThreshold_r16_idleRSRP_Threshold_NR_r16_Optional idleRSRP_Threshold_NR_r16;
	struct SQN_NR_RSRQ_Range_SQN_NR_MeasIdleCarrierNR_r16_qualityThreshold_r16_idleRSRQ_Threshold_NR_r16_Optional idleRSRQ_Threshold_NR_r16;
};

struct uint8_t_SQN_NR_MeasIdleCarrierNR_r16_ssb_MeasConfig_r16_nrofSS_BlocksToAverage_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_ThresholdNR_SQN_NR_MeasIdleCarrierNR_r16_ssb_MeasConfig_r16_absThreshSS_BlocksConsolidation_r16_Optional {
	bool d;
	struct SQN_NR_ThresholdNR v;
};

struct SQN_NR_SSB_MTC_SQN_NR_MeasIdleCarrierNR_r16_ssb_MeasConfig_r16_smtc_r16_Optional {
	bool d;
	struct SQN_NR_SSB_MTC v;
};

struct SQN_NR_SSB_ToMeasure_SQN_NR_MeasIdleCarrierNR_r16_ssb_MeasConfig_r16_ssb_ToMeasure_r16_Optional {
	bool d;
	struct SQN_NR_SSB_ToMeasure v;
};

struct SQN_NR_SS_RSSI_Measurement_SQN_NR_MeasIdleCarrierNR_r16_ssb_MeasConfig_r16_ss_RSSI_Measurement_r16_Optional {
	bool d;
	struct SQN_NR_SS_RSSI_Measurement v;
};

struct SQN_NR_MeasIdleCarrierNR_r16_ssb_MeasConfig_r16 {
	struct uint8_t_SQN_NR_MeasIdleCarrierNR_r16_ssb_MeasConfig_r16_nrofSS_BlocksToAverage_r16_Optional nrofSS_BlocksToAverage_r16;
	struct SQN_NR_ThresholdNR_SQN_NR_MeasIdleCarrierNR_r16_ssb_MeasConfig_r16_absThreshSS_BlocksConsolidation_r16_Optional absThreshSS_BlocksConsolidation_r16;
	struct SQN_NR_SSB_MTC_SQN_NR_MeasIdleCarrierNR_r16_ssb_MeasConfig_r16_smtc_r16_Optional smtc_r16;
	struct SQN_NR_SSB_ToMeasure_SQN_NR_MeasIdleCarrierNR_r16_ssb_MeasConfig_r16_ssb_ToMeasure_r16_Optional ssb_ToMeasure_r16;
	bool deriveSSB_IndexFromCell_r16;
	struct SQN_NR_SS_RSSI_Measurement_SQN_NR_MeasIdleCarrierNR_r16_ssb_MeasConfig_r16_ss_RSSI_Measurement_r16_Optional ss_RSSI_Measurement_r16;
};

enum SQN_NR_BeamMeasConfigIdle_NR_r16_reportQuantityRS_Indexes_r16_e {
	SQN_NR_BeamMeasConfigIdle_NR_r16_reportQuantityRS_Indexes_r16_e_rsrp = 0,
	SQN_NR_BeamMeasConfigIdle_NR_r16_reportQuantityRS_Indexes_r16_e_rsrq = 1,
	SQN_NR_BeamMeasConfigIdle_NR_r16_reportQuantityRS_Indexes_r16_e_both = 2,
};

typedef enum SQN_NR_BeamMeasConfigIdle_NR_r16_reportQuantityRS_Indexes_r16_e SQN_NR_BeamMeasConfigIdle_NR_r16_reportQuantityRS_Indexes_r16_e;

struct SQN_NR_BeamMeasConfigIdle_NR_r16 {
	SQN_NR_BeamMeasConfigIdle_NR_r16_reportQuantityRS_Indexes_r16_e reportQuantityRS_Indexes_r16;
	uint8_t maxNrofRS_IndexesToReport_r16;
	bool includeBeamMeasurements_r16;
};

struct SQN_NR_MultiFrequencyBandListNR_SQN_NR_MeasIdleCarrierNR_r16_frequencyBandList_Optional {
	bool d;
	SQN_NR_MultiFrequencyBandListNR v;
};

struct SQN_NR_CellListNR_r16_SQN_NR_MeasIdleCarrierNR_r16_measCellListNR_r16_Optional {
	bool d;
	SQN_NR_CellListNR_r16 v;
};

struct SQN_NR_MeasIdleCarrierNR_r16_qualityThreshold_r16_qualityThreshold_r16_Optional {
	bool d;
	struct SQN_NR_MeasIdleCarrierNR_r16_qualityThreshold_r16 v;
};

struct SQN_NR_MeasIdleCarrierNR_r16_ssb_MeasConfig_r16_ssb_MeasConfig_r16_Optional {
	bool d;
	struct SQN_NR_MeasIdleCarrierNR_r16_ssb_MeasConfig_r16 v;
};

struct SQN_NR_BeamMeasConfigIdle_NR_r16_SQN_NR_MeasIdleCarrierNR_r16_beamMeasConfigIdle_r16_Optional {
	bool d;
	struct SQN_NR_BeamMeasConfigIdle_NR_r16 v;
};

struct SQN_NR_MeasIdleCarrierNR_r16 {
	SQN_NR_ARFCN_ValueNR carrierFreq_r16;
	SQN_NR_SubcarrierSpacing_e ssbSubcarrierSpacing_r16;
	struct SQN_NR_MultiFrequencyBandListNR_SQN_NR_MeasIdleCarrierNR_r16_frequencyBandList_Optional frequencyBandList;
	struct SQN_NR_CellListNR_r16_SQN_NR_MeasIdleCarrierNR_r16_measCellListNR_r16_Optional measCellListNR_r16;
	SQN_NR_MeasIdleCarrierNR_r16_reportQuantities_r16_e reportQuantities_r16;
	struct SQN_NR_MeasIdleCarrierNR_r16_qualityThreshold_r16_qualityThreshold_r16_Optional qualityThreshold_r16;
	struct SQN_NR_MeasIdleCarrierNR_r16_ssb_MeasConfig_r16_ssb_MeasConfig_r16_Optional ssb_MeasConfig_r16;
	struct SQN_NR_BeamMeasConfigIdle_NR_r16_SQN_NR_MeasIdleCarrierNR_r16_beamMeasConfigIdle_r16_Optional beamMeasConfigIdle_r16;
};

struct SQN_NR_EUTRA_PhysCellIdRange_SQN_NR_CellListEUTRA_r16_Dynamic {
	size_t d;
	struct SQN_NR_EUTRA_PhysCellIdRange* v;
};

typedef struct SQN_NR_EUTRA_PhysCellIdRange_SQN_NR_CellListEUTRA_r16_Dynamic SQN_NR_CellListEUTRA_r16;

enum SQN_NR_MeasIdleCarrierEUTRA_r16_reportQuantitiesEUTRA_r16_e {
	SQN_NR_MeasIdleCarrierEUTRA_r16_reportQuantitiesEUTRA_r16_e_rsrp = 0,
	SQN_NR_MeasIdleCarrierEUTRA_r16_reportQuantitiesEUTRA_r16_e_rsrq = 1,
	SQN_NR_MeasIdleCarrierEUTRA_r16_reportQuantitiesEUTRA_r16_e_both = 2,
};

typedef enum SQN_NR_MeasIdleCarrierEUTRA_r16_reportQuantitiesEUTRA_r16_e SQN_NR_MeasIdleCarrierEUTRA_r16_reportQuantitiesEUTRA_r16_e;

typedef uint8_t SQN_NR_RSRP_RangeEUTRA;

typedef int8_t SQN_NR_RSRQ_RangeEUTRA_r16;

struct SQN_NR_RSRP_RangeEUTRA_SQN_NR_MeasIdleCarrierEUTRA_r16_qualityThresholdEUTRA_r16_idleRSRP_Threshold_EUTRA_r16_Optional {
	bool d;
	SQN_NR_RSRP_RangeEUTRA v;
};

struct SQN_NR_RSRQ_RangeEUTRA_r16_SQN_NR_MeasIdleCarrierEUTRA_r16_qualityThresholdEUTRA_r16_idleRSRQ_Threshold_EUTRA_r16_Optional {
	bool d;
	SQN_NR_RSRQ_RangeEUTRA_r16 v;
};

struct SQN_NR_MeasIdleCarrierEUTRA_r16_qualityThresholdEUTRA_r16 {
	struct SQN_NR_RSRP_RangeEUTRA_SQN_NR_MeasIdleCarrierEUTRA_r16_qualityThresholdEUTRA_r16_idleRSRP_Threshold_EUTRA_r16_Optional idleRSRP_Threshold_EUTRA_r16;
	struct SQN_NR_RSRQ_RangeEUTRA_r16_SQN_NR_MeasIdleCarrierEUTRA_r16_qualityThresholdEUTRA_r16_idleRSRQ_Threshold_EUTRA_r16_Optional idleRSRQ_Threshold_EUTRA_r16;
};

struct SQN_NR_CellListEUTRA_r16_SQN_NR_MeasIdleCarrierEUTRA_r16_measCellListEUTRA_r16_Optional {
	bool d;
	SQN_NR_CellListEUTRA_r16 v;
};

struct SQN_NR_MeasIdleCarrierEUTRA_r16_qualityThresholdEUTRA_r16_qualityThresholdEUTRA_r16_Optional {
	bool d;
	struct SQN_NR_MeasIdleCarrierEUTRA_r16_qualityThresholdEUTRA_r16 v;
};

struct SQN_NR_MeasIdleCarrierEUTRA_r16 {
	SQN_NR_ARFCN_ValueEUTRA carrierFreqEUTRA_r16;
	SQN_NR_EUTRA_AllowedMeasBandwidth_e allowedMeasBandwidth_r16;
	struct SQN_NR_CellListEUTRA_r16_SQN_NR_MeasIdleCarrierEUTRA_r16_measCellListEUTRA_r16_Optional measCellListEUTRA_r16;
	SQN_NR_MeasIdleCarrierEUTRA_r16_reportQuantitiesEUTRA_r16_e reportQuantitiesEUTRA_r16;
	struct SQN_NR_MeasIdleCarrierEUTRA_r16_qualityThresholdEUTRA_r16_qualityThresholdEUTRA_r16_Optional qualityThresholdEUTRA_r16;
};

struct SQN_NR_MeasIdleConfigSIB_r16_SQN_NR_MeasIdleCarrierNR_r16_measIdleCarrierListNR_r16_Dynamic {
	size_t d;
	struct SQN_NR_MeasIdleCarrierNR_r16* v;
};

struct SQN_NR_MeasIdleCarrierNR_r16_SQN_NR_MeasIdleConfigSIB_r16_measIdleCarrierListNR_r16_DynamicOptional {
	bool d;
	struct SQN_NR_MeasIdleConfigSIB_r16_SQN_NR_MeasIdleCarrierNR_r16_measIdleCarrierListNR_r16_Dynamic v;
};

struct SQN_NR_MeasIdleConfigSIB_r16_SQN_NR_MeasIdleCarrierEUTRA_r16_measIdleCarrierListEUTRA_r16_Dynamic {
	size_t d;
	struct SQN_NR_MeasIdleCarrierEUTRA_r16* v;
};

struct SQN_NR_MeasIdleCarrierEUTRA_r16_SQN_NR_MeasIdleConfigSIB_r16_measIdleCarrierListEUTRA_r16_DynamicOptional {
	bool d;
	struct SQN_NR_MeasIdleConfigSIB_r16_SQN_NR_MeasIdleCarrierEUTRA_r16_measIdleCarrierListEUTRA_r16_Dynamic v;
};

struct SQN_NR_MeasIdleConfigSIB_r16 {
	struct SQN_NR_MeasIdleCarrierNR_r16_SQN_NR_MeasIdleConfigSIB_r16_measIdleCarrierListNR_r16_DynamicOptional measIdleCarrierListNR_r16;
	struct SQN_NR_MeasIdleCarrierEUTRA_r16_SQN_NR_MeasIdleConfigSIB_r16_measIdleCarrierListEUTRA_r16_DynamicOptional measIdleCarrierListEUTRA_r16;
};

struct SQN_NR_MeasIdleConfigSIB_r16_SQN_NR_SIB11_r16_measIdleConfigSIB_r16_Optional {
	bool d;
	struct SQN_NR_MeasIdleConfigSIB_r16 v;
};

struct OCTET_STRING_SQN_NR_SIB11_r16_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_SIB11_r16 {
	struct SQN_NR_MeasIdleConfigSIB_r16_SQN_NR_SIB11_r16_measIdleConfigSIB_r16_Optional measIdleConfigSIB_r16;
	struct OCTET_STRING_SQN_NR_SIB11_r16_lateNonCriticalExtension_Optional lateNonCriticalExtension;
};

enum SQN_NR_SIB12_r16_segmentType_r16_e {
	SQN_NR_SIB12_r16_segmentType_r16_e_notLastSegment = 0,
	SQN_NR_SIB12_r16_segmentType_r16_e_lastSegment = 1,
};

typedef enum SQN_NR_SIB12_r16_segmentType_r16_e SQN_NR_SIB12_r16_segmentType_r16_e;

struct SQN_NR_SIB12_r16 {
	uint8_t segmentNumber_r16;
	SQN_NR_SIB12_r16_segmentType_r16_e segmentType_r16;
	OCTET_STRING segmentContainer_r16;
};

struct OCTET_STRING_SQN_NR_SIB13_r16_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_SIB13_r16 {
	OCTET_STRING sl_V2X_ConfigCommon_r16;
	OCTET_STRING sl_Bandwidth_r16;
	OCTET_STRING tdd_Config_r16;
	struct OCTET_STRING_SQN_NR_SIB13_r16_lateNonCriticalExtension_Optional lateNonCriticalExtension;
};

struct OCTET_STRING_SQN_NR_SIB14_r16_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_SIB14_r16 {
	OCTET_STRING sl_V2X_ConfigCommonExt_r16;
	struct OCTET_STRING_SQN_NR_SIB14_r16_lateNonCriticalExtension_Optional lateNonCriticalExtension;
};

enum SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_Sel {
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_UNBOUND_VALUE = 0,
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_sib2 = 1,
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_sib3 = 2,
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_sib4 = 3,
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_sib5 = 4,
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_sib6 = 5,
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_sib7 = 6,
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_sib8 = 7,
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_sib9 = 8,
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_sib10_v1610 = 9,
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_sib11_v1610 = 10,
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_sib12_v1610 = 11,
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_sib13_v1610 = 12,
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_sib14_v1610 = 13,
};

union SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_Value {
	struct SQN_NR_SIB2 sib2;
	struct SQN_NR_SIB3 sib3;
	struct SQN_NR_SIB4 sib4;
	struct SQN_NR_SIB5 sib5;
	struct SQN_NR_SIB6 sib6;
	struct SQN_NR_SIB7 sib7;
	struct SQN_NR_SIB8 sib8;
	struct SQN_NR_SIB9 sib9;
	struct SQN_NR_SIB10_r16 sib10_v1610;
	struct SQN_NR_SIB11_r16 sib11_v1610;
	struct SQN_NR_SIB12_r16 sib12_v1610;
	struct SQN_NR_SIB13_r16 sib13_v1610;
	struct SQN_NR_SIB14_r16 sib14_v1610;
};

struct SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s {
	enum SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_Sel d;
	union SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_Value v;
};

struct SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_Dynamic {
	size_t d;
	struct SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s* v;
};

typedef struct SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_s_SQN_NR_SystemInformation_IEs_sib_TypeAndInfo_Dynamic SQN_NR_SystemInformation_IEs_sib_TypeAndInfo;

struct SQN_NR_SystemInformation_IEs_nonCriticalExtension {
};

struct OCTET_STRING_SQN_NR_SystemInformation_IEs_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_SystemInformation_IEs_nonCriticalExtension_nonCriticalExtension_Optional {
	bool d;
	struct SQN_NR_SystemInformation_IEs_nonCriticalExtension v;
};

struct SQN_NR_SystemInformation_IEs {
	SQN_NR_SystemInformation_IEs_sib_TypeAndInfo sib_TypeAndInfo;
	struct OCTET_STRING_SQN_NR_SystemInformation_IEs_lateNonCriticalExtension_Optional lateNonCriticalExtension;
	struct SQN_NR_SystemInformation_IEs_nonCriticalExtension_nonCriticalExtension_Optional nonCriticalExtension;
};

struct OCTET_STRING_SQN_NR_SIBpos_r16_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_SIBpos_r16 {
	OCTET_STRING assistanceDataSIB_Element_r16;
	struct OCTET_STRING_SQN_NR_SIBpos_r16_lateNonCriticalExtension_Optional lateNonCriticalExtension;
};

enum SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_Sel {
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_UNBOUND_VALUE = 0,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib1_1_r16 = 1,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib1_2_r16 = 2,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib1_3_r16 = 3,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib1_4_r16 = 4,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib1_5_r16 = 5,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib1_6_r16 = 6,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib1_7_r16 = 7,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib1_8_r16 = 8,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_1_r16 = 9,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_2_r16 = 10,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_3_r16 = 11,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_4_r16 = 12,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_5_r16 = 13,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_6_r16 = 14,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_7_r16 = 15,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_8_r16 = 16,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_9_r16 = 17,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_10_r16 = 18,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_11_r16 = 19,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_12_r16 = 20,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_13_r16 = 21,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_14_r16 = 22,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_15_r16 = 23,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_16_r16 = 24,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_17_r16 = 25,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_18_r16 = 26,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_19_r16 = 27,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_20_r16 = 28,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_21_r16 = 29,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_22_r16 = 30,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib2_23_r16 = 31,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib3_1_r16 = 32,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib4_1_r16 = 33,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib5_1_r16 = 34,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib6_1_r16 = 35,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib6_2_r16 = 36,
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_posSib6_3_r16 = 37,
};

union SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_Value {
	struct SQN_NR_SIBpos_r16 posSib1_1_r16;
	struct SQN_NR_SIBpos_r16 posSib1_2_r16;
	struct SQN_NR_SIBpos_r16 posSib1_3_r16;
	struct SQN_NR_SIBpos_r16 posSib1_4_r16;
	struct SQN_NR_SIBpos_r16 posSib1_5_r16;
	struct SQN_NR_SIBpos_r16 posSib1_6_r16;
	struct SQN_NR_SIBpos_r16 posSib1_7_r16;
	struct SQN_NR_SIBpos_r16 posSib1_8_r16;
	struct SQN_NR_SIBpos_r16 posSib2_1_r16;
	struct SQN_NR_SIBpos_r16 posSib2_2_r16;
	struct SQN_NR_SIBpos_r16 posSib2_3_r16;
	struct SQN_NR_SIBpos_r16 posSib2_4_r16;
	struct SQN_NR_SIBpos_r16 posSib2_5_r16;
	struct SQN_NR_SIBpos_r16 posSib2_6_r16;
	struct SQN_NR_SIBpos_r16 posSib2_7_r16;
	struct SQN_NR_SIBpos_r16 posSib2_8_r16;
	struct SQN_NR_SIBpos_r16 posSib2_9_r16;
	struct SQN_NR_SIBpos_r16 posSib2_10_r16;
	struct SQN_NR_SIBpos_r16 posSib2_11_r16;
	struct SQN_NR_SIBpos_r16 posSib2_12_r16;
	struct SQN_NR_SIBpos_r16 posSib2_13_r16;
	struct SQN_NR_SIBpos_r16 posSib2_14_r16;
	struct SQN_NR_SIBpos_r16 posSib2_15_r16;
	struct SQN_NR_SIBpos_r16 posSib2_16_r16;
	struct SQN_NR_SIBpos_r16 posSib2_17_r16;
	struct SQN_NR_SIBpos_r16 posSib2_18_r16;
	struct SQN_NR_SIBpos_r16 posSib2_19_r16;
	struct SQN_NR_SIBpos_r16 posSib2_20_r16;
	struct SQN_NR_SIBpos_r16 posSib2_21_r16;
	struct SQN_NR_SIBpos_r16 posSib2_22_r16;
	struct SQN_NR_SIBpos_r16 posSib2_23_r16;
	struct SQN_NR_SIBpos_r16 posSib3_1_r16;
	struct SQN_NR_SIBpos_r16 posSib4_1_r16;
	struct SQN_NR_SIBpos_r16 posSib5_1_r16;
	struct SQN_NR_SIBpos_r16 posSib6_1_r16;
	struct SQN_NR_SIBpos_r16 posSib6_2_r16;
	struct SQN_NR_SIBpos_r16 posSib6_3_r16;
};

struct SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s {
	enum SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_Sel d;
	union SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_Value v;
};

struct SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_Dynamic {
	size_t d;
	struct SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s* v;
};

typedef struct SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_s_SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16_Dynamic SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16;

struct SQN_NR_PosSystemInformation_r16_IEs_nonCriticalExtension {
};

struct OCTET_STRING_SQN_NR_PosSystemInformation_r16_IEs_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_PosSystemInformation_r16_IEs_nonCriticalExtension_nonCriticalExtension_Optional {
	bool d;
	struct SQN_NR_PosSystemInformation_r16_IEs_nonCriticalExtension v;
};

struct SQN_NR_PosSystemInformation_r16_IEs {
	SQN_NR_PosSystemInformation_r16_IEs_posSIB_TypeAndInfo_r16 posSIB_TypeAndInfo_r16;
	struct OCTET_STRING_SQN_NR_PosSystemInformation_r16_IEs_lateNonCriticalExtension_Optional lateNonCriticalExtension;
	struct SQN_NR_PosSystemInformation_r16_IEs_nonCriticalExtension_nonCriticalExtension_Optional nonCriticalExtension;
};

struct SQN_NR_SystemInformation_criticalExtensions_criticalExtensionsFuture_r16_criticalExtensionsFuture {
};

enum SQN_NR_SystemInformation_criticalExtensions_criticalExtensionsFuture_r16_Sel {
	SQN_NR_SystemInformation_criticalExtensions_criticalExtensionsFuture_r16_UNBOUND_VALUE = 0,
	SQN_NR_SystemInformation_criticalExtensions_criticalExtensionsFuture_r16_posSystemInformation_r16 = 1,
	SQN_NR_SystemInformation_criticalExtensions_criticalExtensionsFuture_r16_criticalExtensionsFuture = 2,
};

union SQN_NR_SystemInformation_criticalExtensions_criticalExtensionsFuture_r16_Value {
	struct SQN_NR_PosSystemInformation_r16_IEs posSystemInformation_r16;
	struct SQN_NR_SystemInformation_criticalExtensions_criticalExtensionsFuture_r16_criticalExtensionsFuture criticalExtensionsFuture;
};

struct SQN_NR_SystemInformation_criticalExtensions_criticalExtensionsFuture_r16 {
	enum SQN_NR_SystemInformation_criticalExtensions_criticalExtensionsFuture_r16_Sel d;
	union SQN_NR_SystemInformation_criticalExtensions_criticalExtensionsFuture_r16_Value v;
};

enum SQN_NR_SystemInformation_criticalExtensions_Sel {
	SQN_NR_SystemInformation_criticalExtensions_UNBOUND_VALUE = 0,
	SQN_NR_SystemInformation_criticalExtensions_systemInformation = 1,
	SQN_NR_SystemInformation_criticalExtensions_criticalExtensionsFuture_r16 = 2,
};

union SQN_NR_SystemInformation_criticalExtensions_Value {
	struct SQN_NR_SystemInformation_IEs systemInformation;
	struct SQN_NR_SystemInformation_criticalExtensions_criticalExtensionsFuture_r16 criticalExtensionsFuture_r16;
};

struct SQN_NR_SystemInformation_criticalExtensions {
	enum SQN_NR_SystemInformation_criticalExtensions_Sel d;
	union SQN_NR_SystemInformation_criticalExtensions_Value v;
};

struct SQN_NR_SystemInformation {
	struct SQN_NR_SystemInformation_criticalExtensions criticalExtensions;
};

struct uint8_t_SQN_NR_SIB1_cellSelectionInfo_q_RxLevMinOffset_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_Q_RxLevMin_SQN_NR_SIB1_cellSelectionInfo_q_RxLevMinSUL_Optional {
	bool d;
	SQN_NR_Q_RxLevMin v;
};

struct SQN_NR_Q_QualMin_SQN_NR_SIB1_cellSelectionInfo_q_QualMin_Optional {
	bool d;
	SQN_NR_Q_QualMin v;
};

struct uint8_t_SQN_NR_SIB1_cellSelectionInfo_q_QualMinOffset_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_SIB1_cellSelectionInfo {
	SQN_NR_Q_RxLevMin q_RxLevMin;
	struct uint8_t_SQN_NR_SIB1_cellSelectionInfo_q_RxLevMinOffset_Optional q_RxLevMinOffset;
	struct SQN_NR_Q_RxLevMin_SQN_NR_SIB1_cellSelectionInfo_q_RxLevMinSUL_Optional q_RxLevMinSUL;
	struct SQN_NR_Q_QualMin_SQN_NR_SIB1_cellSelectionInfo_q_QualMin_Optional q_QualMin;
	struct uint8_t_SQN_NR_SIB1_cellSelectionInfo_q_QualMinOffset_Optional q_QualMinOffset;
};

typedef uint8_t SQN_NR_MCC_MNC_Digit;

typedef SQN_NR_MCC_MNC_Digit SQN_NR_MCC[3];

struct SQN_NR_MCC_MNC_Digit_SQN_NR_MNC_Dynamic {
	size_t d;
	SQN_NR_MCC_MNC_Digit* v;
};

typedef struct SQN_NR_MCC_MNC_Digit_SQN_NR_MNC_Dynamic SQN_NR_MNC;

struct SQN_NR_MCC_SQN_NR_PLMN_Identity_mcc_Optional {
	bool d;
	SQN_NR_MCC v;
};

struct SQN_NR_PLMN_Identity {
	struct SQN_NR_MCC_SQN_NR_PLMN_Identity_mcc_Optional mcc;
	SQN_NR_MNC mnc;
};

typedef B24 SQN_NR_TrackingAreaCode;

typedef uint8_t SQN_NR_RAN_AreaCode;

typedef B36 SQN_NR_CellIdentity;

enum SQN_NR_PLMN_IdentityInfo_cellReservedForOperatorUse_e {
	SQN_NR_PLMN_IdentityInfo_cellReservedForOperatorUse_e_reserved = 0,
	SQN_NR_PLMN_IdentityInfo_cellReservedForOperatorUse_e_notReserved = 1,
};

typedef enum SQN_NR_PLMN_IdentityInfo_cellReservedForOperatorUse_e SQN_NR_PLMN_IdentityInfo_cellReservedForOperatorUse_e;

enum SQN_NR_PLMN_IdentityInfo_iab_Support_r16_e {
	SQN_NR_PLMN_IdentityInfo_iab_Support_r16_e_true = 0,
};

typedef enum SQN_NR_PLMN_IdentityInfo_iab_Support_r16_e SQN_NR_PLMN_IdentityInfo_iab_Support_r16_e;

struct SQN_NR_PLMN_Identity_SQN_NR_PLMN_IdentityInfo_plmn_IdentityList_Dynamic {
	size_t d;
	struct SQN_NR_PLMN_Identity* v;
};

struct SQN_NR_TrackingAreaCode_SQN_NR_PLMN_IdentityInfo_trackingAreaCode_Optional {
	bool d;
	SQN_NR_TrackingAreaCode v;
};

struct SQN_NR_RAN_AreaCode_SQN_NR_PLMN_IdentityInfo_ranac_Optional {
	bool d;
	SQN_NR_RAN_AreaCode v;
};

struct SQN_NR_PLMN_IdentityInfo_iab_Support_r16_e_iab_Support_r16_Optional {
	bool d;
	SQN_NR_PLMN_IdentityInfo_iab_Support_r16_e v;
};

struct SQN_NR_PLMN_IdentityInfo {
	struct SQN_NR_PLMN_Identity_SQN_NR_PLMN_IdentityInfo_plmn_IdentityList_Dynamic plmn_IdentityList;
	struct SQN_NR_TrackingAreaCode_SQN_NR_PLMN_IdentityInfo_trackingAreaCode_Optional trackingAreaCode;
	struct SQN_NR_RAN_AreaCode_SQN_NR_PLMN_IdentityInfo_ranac_Optional ranac;
	SQN_NR_CellIdentity cellIdentity;
	SQN_NR_PLMN_IdentityInfo_cellReservedForOperatorUse_e cellReservedForOperatorUse;
	struct SQN_NR_PLMN_IdentityInfo_iab_Support_r16_e_iab_Support_r16_Optional iab_Support_r16;
};

struct SQN_NR_PLMN_IdentityInfo_SQN_NR_PLMN_IdentityInfoList_Dynamic {
	size_t d;
	struct SQN_NR_PLMN_IdentityInfo* v;
};

typedef struct SQN_NR_PLMN_IdentityInfo_SQN_NR_PLMN_IdentityInfoList_Dynamic SQN_NR_PLMN_IdentityInfoList;

enum SQN_NR_CellAccessRelatedInfo_cellReservedForOtherUse_e {
	SQN_NR_CellAccessRelatedInfo_cellReservedForOtherUse_e_true = 0,
};

typedef enum SQN_NR_CellAccessRelatedInfo_cellReservedForOtherUse_e SQN_NR_CellAccessRelatedInfo_cellReservedForOtherUse_e;

enum SQN_NR_CellAccessRelatedInfo_cellReservedForFutureUse_r16_e {
	SQN_NR_CellAccessRelatedInfo_cellReservedForFutureUse_r16_e_true = 0,
};

typedef enum SQN_NR_CellAccessRelatedInfo_cellReservedForFutureUse_r16_e SQN_NR_CellAccessRelatedInfo_cellReservedForFutureUse_r16_e;

enum SQN_NR_CAG_IdentityInfo_r16_manualCAGselectionAllowed_r16_e {
	SQN_NR_CAG_IdentityInfo_r16_manualCAGselectionAllowed_r16_e_true = 0,
};

typedef enum SQN_NR_CAG_IdentityInfo_r16_manualCAGselectionAllowed_r16_e SQN_NR_CAG_IdentityInfo_r16_manualCAGselectionAllowed_r16_e;

struct SQN_NR_CAG_IdentityInfo_r16_manualCAGselectionAllowed_r16_e_manualCAGselectionAllowed_r16_Optional {
	bool d;
	SQN_NR_CAG_IdentityInfo_r16_manualCAGselectionAllowed_r16_e v;
};

struct SQN_NR_CAG_IdentityInfo_r16 {
	B32 cag_Identity_r16;
	struct SQN_NR_CAG_IdentityInfo_r16_manualCAGselectionAllowed_r16_e_manualCAGselectionAllowed_r16_Optional manualCAGselectionAllowed_r16;
};

struct SQN_NR_CAG_IdentityInfo_r16_SQN_NR_NPN_Identity_r16_pni_npn_r16_cag_IdentityList_r16_Dynamic {
	size_t d;
	struct SQN_NR_CAG_IdentityInfo_r16* v;
};

struct SQN_NR_NPN_Identity_r16_pni_npn_r16 {
	struct SQN_NR_PLMN_Identity plmn_Identity_r16;
	struct SQN_NR_CAG_IdentityInfo_r16_SQN_NR_NPN_Identity_r16_pni_npn_r16_cag_IdentityList_r16_Dynamic cag_IdentityList_r16;
};

typedef B44 SQN_NR_NID_r16;

struct SQN_NR_NID_r16_nid_List_r16_Dynamic {
	size_t d;
	SQN_NR_NID_r16* v;
};

struct SQN_NR_NPN_Identity_r16_snpn_r16 {
	struct SQN_NR_PLMN_Identity plmn_Identity;
	struct SQN_NR_NID_r16_nid_List_r16_Dynamic nid_List_r16;
};

enum SQN_NR_NPN_Identity_r16_Sel {
	SQN_NR_NPN_Identity_r16_UNBOUND_VALUE = 0,
	SQN_NR_NPN_Identity_r16_pni_npn_r16 = 1,
	SQN_NR_NPN_Identity_r16_snpn_r16 = 2,
};

union SQN_NR_NPN_Identity_r16_Value {
	struct SQN_NR_NPN_Identity_r16_pni_npn_r16 pni_npn_r16;
	struct SQN_NR_NPN_Identity_r16_snpn_r16 snpn_r16;
};

struct SQN_NR_NPN_Identity_r16 {
	enum SQN_NR_NPN_Identity_r16_Sel d;
	union SQN_NR_NPN_Identity_r16_Value v;
};

enum SQN_NR_NPN_IdentityInfo_r16_cellReservedForOperatorUse_r16_e {
	SQN_NR_NPN_IdentityInfo_r16_cellReservedForOperatorUse_r16_e_reserved = 0,
	SQN_NR_NPN_IdentityInfo_r16_cellReservedForOperatorUse_r16_e_notReserved = 1,
};

typedef enum SQN_NR_NPN_IdentityInfo_r16_cellReservedForOperatorUse_r16_e SQN_NR_NPN_IdentityInfo_r16_cellReservedForOperatorUse_r16_e;

enum SQN_NR_NPN_IdentityInfo_r16_iab_Support_r16_e {
	SQN_NR_NPN_IdentityInfo_r16_iab_Support_r16_e_true = 0,
};

typedef enum SQN_NR_NPN_IdentityInfo_r16_iab_Support_r16_e SQN_NR_NPN_IdentityInfo_r16_iab_Support_r16_e;

struct SQN_NR_NPN_Identity_r16_SQN_NR_NPN_IdentityInfo_r16_npn_IdentityList_r16_Dynamic {
	size_t d;
	struct SQN_NR_NPN_Identity_r16* v;
};

struct SQN_NR_RAN_AreaCode_SQN_NR_NPN_IdentityInfo_r16_ranac_r16_Optional {
	bool d;
	SQN_NR_RAN_AreaCode v;
};

struct SQN_NR_NPN_IdentityInfo_r16_iab_Support_r16_e_iab_Support_r16_Optional {
	bool d;
	SQN_NR_NPN_IdentityInfo_r16_iab_Support_r16_e v;
};

struct SQN_NR_NPN_IdentityInfo_r16 {
	struct SQN_NR_NPN_Identity_r16_SQN_NR_NPN_IdentityInfo_r16_npn_IdentityList_r16_Dynamic npn_IdentityList_r16;
	SQN_NR_TrackingAreaCode trackingAreaCode_r16;
	struct SQN_NR_RAN_AreaCode_SQN_NR_NPN_IdentityInfo_r16_ranac_r16_Optional ranac_r16;
	SQN_NR_CellIdentity cellIdentity_r16;
	SQN_NR_NPN_IdentityInfo_r16_cellReservedForOperatorUse_r16_e cellReservedForOperatorUse_r16;
	struct SQN_NR_NPN_IdentityInfo_r16_iab_Support_r16_e_iab_Support_r16_Optional iab_Support_r16;
};

struct SQN_NR_NPN_IdentityInfo_r16_SQN_NR_NPN_IdentityInfoList_r16_Dynamic {
	size_t d;
	struct SQN_NR_NPN_IdentityInfo_r16* v;
};

typedef struct SQN_NR_NPN_IdentityInfo_r16_SQN_NR_NPN_IdentityInfoList_r16_Dynamic SQN_NR_NPN_IdentityInfoList_r16;

struct SQN_NR_CellAccessRelatedInfo_cellReservedForOtherUse_e_cellReservedForOtherUse_Optional {
	bool d;
	SQN_NR_CellAccessRelatedInfo_cellReservedForOtherUse_e v;
};

struct SQN_NR_CellAccessRelatedInfo_cellReservedForFutureUse_r16_e_cellReservedForFutureUse_r16_Optional {
	bool d;
	SQN_NR_CellAccessRelatedInfo_cellReservedForFutureUse_r16_e v;
};

struct SQN_NR_NPN_IdentityInfoList_r16_SQN_NR_CellAccessRelatedInfo_npn_IdentityInfoList_r16_Optional {
	bool d;
	SQN_NR_NPN_IdentityInfoList_r16 v;
};

struct SQN_NR_CellAccessRelatedInfo {
	SQN_NR_PLMN_IdentityInfoList plmn_IdentityList;
	struct SQN_NR_CellAccessRelatedInfo_cellReservedForOtherUse_e_cellReservedForOtherUse_Optional cellReservedForOtherUse;
	struct SQN_NR_CellAccessRelatedInfo_cellReservedForFutureUse_r16_e_cellReservedForFutureUse_r16_Optional cellReservedForFutureUse_r16;
	struct SQN_NR_NPN_IdentityInfoList_r16_SQN_NR_CellAccessRelatedInfo_npn_IdentityInfoList_r16_Optional npn_IdentityInfoList_r16;
};

enum SQN_NR_ConnEstFailureControl_connEstFailCount_e {
	SQN_NR_ConnEstFailureControl_connEstFailCount_e_n1 = 0,
	SQN_NR_ConnEstFailureControl_connEstFailCount_e_n2 = 1,
	SQN_NR_ConnEstFailureControl_connEstFailCount_e_n3 = 2,
	SQN_NR_ConnEstFailureControl_connEstFailCount_e_n4 = 3,
};

typedef enum SQN_NR_ConnEstFailureControl_connEstFailCount_e SQN_NR_ConnEstFailureControl_connEstFailCount_e;

enum SQN_NR_ConnEstFailureControl_connEstFailOffsetValidity_e {
	SQN_NR_ConnEstFailureControl_connEstFailOffsetValidity_e_s30 = 0,
	SQN_NR_ConnEstFailureControl_connEstFailOffsetValidity_e_s60 = 1,
	SQN_NR_ConnEstFailureControl_connEstFailOffsetValidity_e_s120 = 2,
	SQN_NR_ConnEstFailureControl_connEstFailOffsetValidity_e_s240 = 3,
	SQN_NR_ConnEstFailureControl_connEstFailOffsetValidity_e_s300 = 4,
	SQN_NR_ConnEstFailureControl_connEstFailOffsetValidity_e_s420 = 5,
	SQN_NR_ConnEstFailureControl_connEstFailOffsetValidity_e_s600 = 6,
	SQN_NR_ConnEstFailureControl_connEstFailOffsetValidity_e_s900 = 7,
};

typedef enum SQN_NR_ConnEstFailureControl_connEstFailOffsetValidity_e SQN_NR_ConnEstFailureControl_connEstFailOffsetValidity_e;

struct uint8_t_SQN_NR_ConnEstFailureControl_connEstFailOffset_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_ConnEstFailureControl {
	SQN_NR_ConnEstFailureControl_connEstFailCount_e connEstFailCount;
	SQN_NR_ConnEstFailureControl_connEstFailOffsetValidity_e connEstFailOffsetValidity;
	struct uint8_t_SQN_NR_ConnEstFailureControl_connEstFailOffset_Optional connEstFailOffset;
};

enum SQN_NR_SchedulingInfo_si_BroadcastStatus_e {
	SQN_NR_SchedulingInfo_si_BroadcastStatus_e_broadcasting = 0,
	SQN_NR_SchedulingInfo_si_BroadcastStatus_e_notBroadcasting = 1,
};

typedef enum SQN_NR_SchedulingInfo_si_BroadcastStatus_e SQN_NR_SchedulingInfo_si_BroadcastStatus_e;

enum SQN_NR_SchedulingInfo_si_Periodicity_e {
	SQN_NR_SchedulingInfo_si_Periodicity_e_rf8 = 0,
	SQN_NR_SchedulingInfo_si_Periodicity_e_rf16 = 1,
	SQN_NR_SchedulingInfo_si_Periodicity_e_rf32 = 2,
	SQN_NR_SchedulingInfo_si_Periodicity_e_rf64 = 3,
	SQN_NR_SchedulingInfo_si_Periodicity_e_rf128 = 4,
	SQN_NR_SchedulingInfo_si_Periodicity_e_rf256 = 5,
	SQN_NR_SchedulingInfo_si_Periodicity_e_rf512 = 6,
};

typedef enum SQN_NR_SchedulingInfo_si_Periodicity_e SQN_NR_SchedulingInfo_si_Periodicity_e;

enum SQN_NR_SIB_TypeInfo_type_e {
	SQN_NR_SIB_TypeInfo_type_e_sibType2 = 0,
	SQN_NR_SIB_TypeInfo_type_e_sibType3 = 1,
	SQN_NR_SIB_TypeInfo_type_e_sibType4 = 2,
	SQN_NR_SIB_TypeInfo_type_e_sibType5 = 3,
	SQN_NR_SIB_TypeInfo_type_e_sibType6 = 4,
	SQN_NR_SIB_TypeInfo_type_e_sibType7 = 5,
	SQN_NR_SIB_TypeInfo_type_e_sibType8 = 6,
	SQN_NR_SIB_TypeInfo_type_e_sibType9 = 7,
	SQN_NR_SIB_TypeInfo_type_e_sibType10_v1610 = 8,
	SQN_NR_SIB_TypeInfo_type_e_sibType11_v1610 = 9,
	SQN_NR_SIB_TypeInfo_type_e_sibType12_v1610 = 10,
	SQN_NR_SIB_TypeInfo_type_e_sibType13_v1610 = 11,
	SQN_NR_SIB_TypeInfo_type_e_sibType14_v1610 = 12,
	SQN_NR_SIB_TypeInfo_type_e_spare3 = 13,
	SQN_NR_SIB_TypeInfo_type_e_spare2 = 14,
	SQN_NR_SIB_TypeInfo_type_e_spare1 = 15,
};

typedef enum SQN_NR_SIB_TypeInfo_type_e SQN_NR_SIB_TypeInfo_type_e;

enum SQN_NR_SIB_TypeInfo_areaScope_e {
	SQN_NR_SIB_TypeInfo_areaScope_e_true = 0,
};

typedef enum SQN_NR_SIB_TypeInfo_areaScope_e SQN_NR_SIB_TypeInfo_areaScope_e;

struct uint8_t_SQN_NR_SIB_TypeInfo_valueTag_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_SIB_TypeInfo_areaScope_e_areaScope_Optional {
	bool d;
	SQN_NR_SIB_TypeInfo_areaScope_e v;
};

struct SQN_NR_SIB_TypeInfo {
	SQN_NR_SIB_TypeInfo_type_e type;
	struct uint8_t_SQN_NR_SIB_TypeInfo_valueTag_Optional valueTag;
	struct SQN_NR_SIB_TypeInfo_areaScope_e_areaScope_Optional areaScope;
};

struct SQN_NR_SIB_TypeInfo_SQN_NR_SIB_Mapping_Dynamic {
	size_t d;
	struct SQN_NR_SIB_TypeInfo* v;
};

typedef struct SQN_NR_SIB_TypeInfo_SQN_NR_SIB_Mapping_Dynamic SQN_NR_SIB_Mapping;

struct SQN_NR_SchedulingInfo {
	SQN_NR_SchedulingInfo_si_BroadcastStatus_e si_BroadcastStatus;
	SQN_NR_SchedulingInfo_si_Periodicity_e si_Periodicity;
	SQN_NR_SIB_Mapping sib_MappingInfo;
};

enum SQN_NR_SI_SchedulingInfo_si_WindowLength_e {
	SQN_NR_SI_SchedulingInfo_si_WindowLength_e_s5 = 0,
	SQN_NR_SI_SchedulingInfo_si_WindowLength_e_s10 = 1,
	SQN_NR_SI_SchedulingInfo_si_WindowLength_e_s20 = 2,
	SQN_NR_SI_SchedulingInfo_si_WindowLength_e_s40 = 3,
	SQN_NR_SI_SchedulingInfo_si_WindowLength_e_s80 = 4,
	SQN_NR_SI_SchedulingInfo_si_WindowLength_e_s160 = 5,
	SQN_NR_SI_SchedulingInfo_si_WindowLength_e_s320 = 6,
	SQN_NR_SI_SchedulingInfo_si_WindowLength_e_s640 = 7,
	SQN_NR_SI_SchedulingInfo_si_WindowLength_e_s1280 = 8,
};

typedef enum SQN_NR_SI_SchedulingInfo_si_WindowLength_e SQN_NR_SI_SchedulingInfo_si_WindowLength_e;

enum SQN_NR_RACH_ConfigGeneric_msg1_FDM_e {
	SQN_NR_RACH_ConfigGeneric_msg1_FDM_e_one = 0,
	SQN_NR_RACH_ConfigGeneric_msg1_FDM_e_two = 1,
	SQN_NR_RACH_ConfigGeneric_msg1_FDM_e_four = 2,
	SQN_NR_RACH_ConfigGeneric_msg1_FDM_e_eight = 3,
};

typedef enum SQN_NR_RACH_ConfigGeneric_msg1_FDM_e SQN_NR_RACH_ConfigGeneric_msg1_FDM_e;

enum SQN_NR_RACH_ConfigGeneric_preambleTransMax_e {
	SQN_NR_RACH_ConfigGeneric_preambleTransMax_e_n3 = 0,
	SQN_NR_RACH_ConfigGeneric_preambleTransMax_e_n4 = 1,
	SQN_NR_RACH_ConfigGeneric_preambleTransMax_e_n5 = 2,
	SQN_NR_RACH_ConfigGeneric_preambleTransMax_e_n6 = 3,
	SQN_NR_RACH_ConfigGeneric_preambleTransMax_e_n7 = 4,
	SQN_NR_RACH_ConfigGeneric_preambleTransMax_e_n8 = 5,
	SQN_NR_RACH_ConfigGeneric_preambleTransMax_e_n10 = 6,
	SQN_NR_RACH_ConfigGeneric_preambleTransMax_e_n20 = 7,
	SQN_NR_RACH_ConfigGeneric_preambleTransMax_e_n50 = 8,
	SQN_NR_RACH_ConfigGeneric_preambleTransMax_e_n100 = 9,
	SQN_NR_RACH_ConfigGeneric_preambleTransMax_e_n200 = 10,
};

typedef enum SQN_NR_RACH_ConfigGeneric_preambleTransMax_e SQN_NR_RACH_ConfigGeneric_preambleTransMax_e;

enum SQN_NR_RACH_ConfigGeneric_powerRampingStep_e {
	SQN_NR_RACH_ConfigGeneric_powerRampingStep_e_dB0 = 0,
	SQN_NR_RACH_ConfigGeneric_powerRampingStep_e_dB2 = 1,
	SQN_NR_RACH_ConfigGeneric_powerRampingStep_e_dB4 = 2,
	SQN_NR_RACH_ConfigGeneric_powerRampingStep_e_dB6 = 3,
};

typedef enum SQN_NR_RACH_ConfigGeneric_powerRampingStep_e SQN_NR_RACH_ConfigGeneric_powerRampingStep_e;

enum SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_e {
	SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_e_sl1 = 0,
	SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_e_sl2 = 1,
	SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_e_sl4 = 2,
	SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_e_sl8 = 3,
	SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_e_sl10 = 4,
	SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_e_sl20 = 5,
	SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_e_sl40 = 6,
	SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_e_sl80 = 7,
};

typedef enum SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_e SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_e;

enum SQN_NR_RACH_ConfigGeneric_prach_ConfigurationPeriodScaling_IAB_r16_e {
	SQN_NR_RACH_ConfigGeneric_prach_ConfigurationPeriodScaling_IAB_r16_e_scf1 = 0,
	SQN_NR_RACH_ConfigGeneric_prach_ConfigurationPeriodScaling_IAB_r16_e_scf2 = 1,
	SQN_NR_RACH_ConfigGeneric_prach_ConfigurationPeriodScaling_IAB_r16_e_scf4 = 2,
	SQN_NR_RACH_ConfigGeneric_prach_ConfigurationPeriodScaling_IAB_r16_e_scf8 = 3,
	SQN_NR_RACH_ConfigGeneric_prach_ConfigurationPeriodScaling_IAB_r16_e_scf16 = 4,
	SQN_NR_RACH_ConfigGeneric_prach_ConfigurationPeriodScaling_IAB_r16_e_scf32 = 5,
	SQN_NR_RACH_ConfigGeneric_prach_ConfigurationPeriodScaling_IAB_r16_e_scf64 = 6,
};

typedef enum SQN_NR_RACH_ConfigGeneric_prach_ConfigurationPeriodScaling_IAB_r16_e SQN_NR_RACH_ConfigGeneric_prach_ConfigurationPeriodScaling_IAB_r16_e;

enum SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_v1610_e {
	SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_v1610_e_sl60 = 0,
	SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_v1610_e_sl160 = 1,
};

typedef enum SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_v1610_e SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_v1610_e;

struct SQN_NR_RACH_ConfigGeneric_prach_ConfigurationPeriodScaling_IAB_r16_e_prach_ConfigurationPeriodScaling_IAB_r16_Optional {
	bool d;
	SQN_NR_RACH_ConfigGeneric_prach_ConfigurationPeriodScaling_IAB_r16_e v;
};

struct uint8_t_SQN_NR_RACH_ConfigGeneric_prach_ConfigurationFrameOffset_IAB_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_RACH_ConfigGeneric_prach_ConfigurationSOffset_IAB_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_v1610_e_ra_ResponseWindow_v1610_Optional {
	bool d;
	SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_v1610_e v;
};

struct uint16_t_SQN_NR_RACH_ConfigGeneric_prach_ConfigurationIndex_v1610_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_RACH_ConfigGeneric {
	uint8_t prach_ConfigurationIndex;
	SQN_NR_RACH_ConfigGeneric_msg1_FDM_e msg1_FDM;
	uint16_t msg1_FrequencyStart;
	uint8_t zeroCorrelationZoneConfig;
	int16_t preambleReceivedTargetPower;
	SQN_NR_RACH_ConfigGeneric_preambleTransMax_e preambleTransMax;
	SQN_NR_RACH_ConfigGeneric_powerRampingStep_e powerRampingStep;
	SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_e ra_ResponseWindow;
	struct SQN_NR_RACH_ConfigGeneric_prach_ConfigurationPeriodScaling_IAB_r16_e_prach_ConfigurationPeriodScaling_IAB_r16_Optional prach_ConfigurationPeriodScaling_IAB_r16;
	struct uint8_t_SQN_NR_RACH_ConfigGeneric_prach_ConfigurationFrameOffset_IAB_r16_Optional prach_ConfigurationFrameOffset_IAB_r16;
	struct uint8_t_SQN_NR_RACH_ConfigGeneric_prach_ConfigurationSOffset_IAB_r16_Optional prach_ConfigurationSOffset_IAB_r16;
	struct SQN_NR_RACH_ConfigGeneric_ra_ResponseWindow_v1610_e_ra_ResponseWindow_v1610_Optional ra_ResponseWindow_v1610;
	struct uint16_t_SQN_NR_RACH_ConfigGeneric_prach_ConfigurationIndex_v1610_Optional prach_ConfigurationIndex_v1610;
};

enum SQN_NR_SI_RequestConfig_rach_OccasionsSI_ssb_perRACH_Occasion_e {
	SQN_NR_SI_RequestConfig_rach_OccasionsSI_ssb_perRACH_Occasion_e_oneEighth = 0,
	SQN_NR_SI_RequestConfig_rach_OccasionsSI_ssb_perRACH_Occasion_e_oneFourth = 1,
	SQN_NR_SI_RequestConfig_rach_OccasionsSI_ssb_perRACH_Occasion_e_oneHalf = 2,
	SQN_NR_SI_RequestConfig_rach_OccasionsSI_ssb_perRACH_Occasion_e_one = 3,
	SQN_NR_SI_RequestConfig_rach_OccasionsSI_ssb_perRACH_Occasion_e_two = 4,
	SQN_NR_SI_RequestConfig_rach_OccasionsSI_ssb_perRACH_Occasion_e_four = 5,
	SQN_NR_SI_RequestConfig_rach_OccasionsSI_ssb_perRACH_Occasion_e_eight = 6,
	SQN_NR_SI_RequestConfig_rach_OccasionsSI_ssb_perRACH_Occasion_e_sixteen = 7,
};

typedef enum SQN_NR_SI_RequestConfig_rach_OccasionsSI_ssb_perRACH_Occasion_e SQN_NR_SI_RequestConfig_rach_OccasionsSI_ssb_perRACH_Occasion_e;

struct SQN_NR_SI_RequestConfig_rach_OccasionsSI {
	struct SQN_NR_RACH_ConfigGeneric rach_ConfigSI;
	SQN_NR_SI_RequestConfig_rach_OccasionsSI_ssb_perRACH_Occasion_e ssb_perRACH_Occasion;
};

enum SQN_NR_SI_RequestConfig_si_RequestPeriod_e {
	SQN_NR_SI_RequestConfig_si_RequestPeriod_e_one = 0,
	SQN_NR_SI_RequestConfig_si_RequestPeriod_e_two = 1,
	SQN_NR_SI_RequestConfig_si_RequestPeriod_e_four = 2,
	SQN_NR_SI_RequestConfig_si_RequestPeriod_e_six = 3,
	SQN_NR_SI_RequestConfig_si_RequestPeriod_e_eight = 4,
	SQN_NR_SI_RequestConfig_si_RequestPeriod_e_ten = 5,
	SQN_NR_SI_RequestConfig_si_RequestPeriod_e_twelve = 6,
	SQN_NR_SI_RequestConfig_si_RequestPeriod_e_sixteen = 7,
};

typedef enum SQN_NR_SI_RequestConfig_si_RequestPeriod_e SQN_NR_SI_RequestConfig_si_RequestPeriod_e;

struct uint8_t_SQN_NR_SI_RequestResources_ra_AssociationPeriodIndex_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_SI_RequestResources_ra_ssb_OccasionMaskIndex_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_SI_RequestResources {
	uint8_t ra_PreambleStartIndex;
	struct uint8_t_SQN_NR_SI_RequestResources_ra_AssociationPeriodIndex_Optional ra_AssociationPeriodIndex;
	struct uint8_t_SQN_NR_SI_RequestResources_ra_ssb_OccasionMaskIndex_Optional ra_ssb_OccasionMaskIndex;
};

struct SQN_NR_SI_RequestConfig_rach_OccasionsSI_rach_OccasionsSI_Optional {
	bool d;
	struct SQN_NR_SI_RequestConfig_rach_OccasionsSI v;
};

struct SQN_NR_SI_RequestConfig_si_RequestPeriod_e_si_RequestPeriod_Optional {
	bool d;
	SQN_NR_SI_RequestConfig_si_RequestPeriod_e v;
};

struct SQN_NR_SI_RequestResources_SQN_NR_SI_RequestConfig_si_RequestResources_Dynamic {
	size_t d;
	struct SQN_NR_SI_RequestResources* v;
};

struct SQN_NR_SI_RequestConfig {
	struct SQN_NR_SI_RequestConfig_rach_OccasionsSI_rach_OccasionsSI_Optional rach_OccasionsSI;
	struct SQN_NR_SI_RequestConfig_si_RequestPeriod_e_si_RequestPeriod_Optional si_RequestPeriod;
	struct SQN_NR_SI_RequestResources_SQN_NR_SI_RequestConfig_si_RequestResources_Dynamic si_RequestResources;
};

struct SQN_NR_SchedulingInfo_SQN_NR_SI_SchedulingInfo_schedulingInfoList_Dynamic {
	size_t d;
	struct SQN_NR_SchedulingInfo* v;
};

struct SQN_NR_SI_RequestConfig_SQN_NR_SI_SchedulingInfo_si_RequestConfig_Optional {
	bool d;
	struct SQN_NR_SI_RequestConfig v;
};

struct SQN_NR_SI_RequestConfig_SQN_NR_SI_SchedulingInfo_si_RequestConfigSUL_Optional {
	bool d;
	struct SQN_NR_SI_RequestConfig v;
};

struct B24_SQN_NR_SI_SchedulingInfo_systemInformationAreaID_Optional {
	bool d;
	B24 v;
};

struct SQN_NR_SI_SchedulingInfo {
	struct SQN_NR_SchedulingInfo_SQN_NR_SI_SchedulingInfo_schedulingInfoList_Dynamic schedulingInfoList;
	SQN_NR_SI_SchedulingInfo_si_WindowLength_e si_WindowLength;
	struct SQN_NR_SI_RequestConfig_SQN_NR_SI_SchedulingInfo_si_RequestConfig_Optional si_RequestConfig;
	struct SQN_NR_SI_RequestConfig_SQN_NR_SI_SchedulingInfo_si_RequestConfigSUL_Optional si_RequestConfigSUL;
	struct B24_SQN_NR_SI_SchedulingInfo_systemInformationAreaID_Optional systemInformationAreaID;
};

struct uint16_t_SQN_NR_SCS_SpecificCarrier_txDirectCurrentLocation_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_SCS_SpecificCarrier {
	uint16_t offsetToCarrier;
	SQN_NR_SubcarrierSpacing_e subcarrierSpacing;
	uint16_t carrierBandwidth;
	struct uint16_t_SQN_NR_SCS_SpecificCarrier_txDirectCurrentLocation_Optional txDirectCurrentLocation;
};

struct SQN_NR_SCS_SpecificCarrier_SQN_NR_FrequencyInfoDL_SIB_scs_SpecificCarrierList_Dynamic {
	size_t d;
	struct SQN_NR_SCS_SpecificCarrier* v;
};

struct SQN_NR_FrequencyInfoDL_SIB {
	SQN_NR_MultiFrequencyBandListNR_SIB frequencyBandList;
	uint16_t offsetToPointA;
	struct SQN_NR_SCS_SpecificCarrier_SQN_NR_FrequencyInfoDL_SIB_scs_SpecificCarrierList_Dynamic scs_SpecificCarrierList;
};

enum SQN_NR_BWP_cyclicPrefix_e {
	SQN_NR_BWP_cyclicPrefix_e_extended = 0,
};

typedef enum SQN_NR_BWP_cyclicPrefix_e SQN_NR_BWP_cyclicPrefix_e;

struct SQN_NR_BWP_cyclicPrefix_e_cyclicPrefix_Optional {
	bool d;
	SQN_NR_BWP_cyclicPrefix_e v;
};

struct SQN_NR_BWP {
	uint16_t locationAndBandwidth;
	SQN_NR_SubcarrierSpacing_e subcarrierSpacing;
	struct SQN_NR_BWP_cyclicPrefix_e_cyclicPrefix_Optional cyclicPrefix;
};

typedef uint8_t SQN_NR_ControlResourceSetId;

enum SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_reg_BundleSize_e {
	SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_reg_BundleSize_e_n2 = 0,
	SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_reg_BundleSize_e_n3 = 1,
	SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_reg_BundleSize_e_n6 = 2,
};

typedef enum SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_reg_BundleSize_e SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_reg_BundleSize_e;

enum SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_interleaverSize_e {
	SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_interleaverSize_e_n2 = 0,
	SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_interleaverSize_e_n3 = 1,
	SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_interleaverSize_e_n6 = 2,
};

typedef enum SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_interleaverSize_e SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_interleaverSize_e;

struct uint16_t_SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_shiftIndex_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved {
	SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_reg_BundleSize_e reg_BundleSize;
	SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_interleaverSize_e interleaverSize;
	struct uint16_t_SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved_shiftIndex_Optional shiftIndex;
};

enum SQN_NR_ControlResourceSet_cce_REG_MappingType_Sel {
	SQN_NR_ControlResourceSet_cce_REG_MappingType_UNBOUND_VALUE = 0,
	SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved = 1,
	SQN_NR_ControlResourceSet_cce_REG_MappingType_nonInterleaved = 2,
};

union SQN_NR_ControlResourceSet_cce_REG_MappingType_Value {
	struct SQN_NR_ControlResourceSet_cce_REG_MappingType_interleaved interleaved;
	Null nonInterleaved;
};

struct SQN_NR_ControlResourceSet_cce_REG_MappingType {
	enum SQN_NR_ControlResourceSet_cce_REG_MappingType_Sel d;
	union SQN_NR_ControlResourceSet_cce_REG_MappingType_Value v;
};

enum SQN_NR_ControlResourceSet_precoderGranularity_e {
	SQN_NR_ControlResourceSet_precoderGranularity_e_sameAsREG_bundle = 0,
	SQN_NR_ControlResourceSet_precoderGranularity_e_allContiguousRBs = 1,
};

typedef enum SQN_NR_ControlResourceSet_precoderGranularity_e SQN_NR_ControlResourceSet_precoderGranularity_e;

typedef uint8_t SQN_NR_TCI_StateId;

enum SQN_NR_ControlResourceSet_tci_PresentInDCI_e {
	SQN_NR_ControlResourceSet_tci_PresentInDCI_e_enabled = 0,
};

typedef enum SQN_NR_ControlResourceSet_tci_PresentInDCI_e SQN_NR_ControlResourceSet_tci_PresentInDCI_e;

typedef uint8_t SQN_NR_ControlResourceSetId_v1610;

struct SQN_NR_TCI_StateId_SQN_NR_ControlResourceSet_tci_StatesPDCCH_ToAddList_Dynamic {
	size_t d;
	SQN_NR_TCI_StateId* v;
};

struct SQN_NR_TCI_StateId_SQN_NR_ControlResourceSet_tci_StatesPDCCH_ToAddList_DynamicOptional {
	bool d;
	struct SQN_NR_TCI_StateId_SQN_NR_ControlResourceSet_tci_StatesPDCCH_ToAddList_Dynamic v;
};

struct SQN_NR_TCI_StateId_SQN_NR_ControlResourceSet_tci_StatesPDCCH_ToReleaseList_Dynamic {
	size_t d;
	SQN_NR_TCI_StateId* v;
};

struct SQN_NR_TCI_StateId_SQN_NR_ControlResourceSet_tci_StatesPDCCH_ToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_TCI_StateId_SQN_NR_ControlResourceSet_tci_StatesPDCCH_ToReleaseList_Dynamic v;
};

struct SQN_NR_ControlResourceSet_tci_PresentInDCI_e_tci_PresentInDCI_Optional {
	bool d;
	SQN_NR_ControlResourceSet_tci_PresentInDCI_e v;
};

struct uint16_t_SQN_NR_ControlResourceSet_pdcch_DMRS_ScramblingID_Optional {
	bool d;
	uint16_t v;
};

struct uint8_t_SQN_NR_ControlResourceSet_rb_Offset_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_ControlResourceSet_tci_PresentDCI_1_2_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_ControlResourceSet_coresetPoolIndex_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_ControlResourceSetId_v1610_SQN_NR_ControlResourceSet_controlResourceSetId_v1610_Optional {
	bool d;
	SQN_NR_ControlResourceSetId_v1610 v;
};

struct SQN_NR_ControlResourceSet {
	SQN_NR_ControlResourceSetId controlResourceSetId;
	B45 frequencyDomainResources;
	uint8_t duration;
	struct SQN_NR_ControlResourceSet_cce_REG_MappingType cce_REG_MappingType;
	SQN_NR_ControlResourceSet_precoderGranularity_e precoderGranularity;
	struct SQN_NR_TCI_StateId_SQN_NR_ControlResourceSet_tci_StatesPDCCH_ToAddList_DynamicOptional tci_StatesPDCCH_ToAddList;
	struct SQN_NR_TCI_StateId_SQN_NR_ControlResourceSet_tci_StatesPDCCH_ToReleaseList_DynamicOptional tci_StatesPDCCH_ToReleaseList;
	struct SQN_NR_ControlResourceSet_tci_PresentInDCI_e_tci_PresentInDCI_Optional tci_PresentInDCI;
	struct uint16_t_SQN_NR_ControlResourceSet_pdcch_DMRS_ScramblingID_Optional pdcch_DMRS_ScramblingID;
	struct uint8_t_SQN_NR_ControlResourceSet_rb_Offset_r16_Optional rb_Offset_r16;
	struct uint8_t_SQN_NR_ControlResourceSet_tci_PresentDCI_1_2_r16_Optional tci_PresentDCI_1_2_r16;
	struct uint8_t_SQN_NR_ControlResourceSet_coresetPoolIndex_r16_Optional coresetPoolIndex_r16;
	struct SQN_NR_ControlResourceSetId_v1610_SQN_NR_ControlResourceSet_controlResourceSetId_v1610_Optional controlResourceSetId_v1610;
};

typedef uint8_t SQN_NR_SearchSpaceId;

enum SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_Sel {
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_UNBOUND_VALUE = 0,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl1 = 1,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl2 = 2,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl4 = 3,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl5 = 4,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl8 = 5,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl10 = 6,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl16 = 7,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl20 = 8,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl40 = 9,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl80 = 10,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl160 = 11,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl320 = 12,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl640 = 13,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl1280 = 14,
	SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_sl2560 = 15,
};

union SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_Value {
	Null sl1;
	uint8_t sl2;
	uint8_t sl4;
	uint8_t sl5;
	uint8_t sl8;
	uint8_t sl10;
	uint8_t sl16;
	uint8_t sl20;
	uint8_t sl40;
	uint8_t sl80;
	uint8_t sl160;
	uint16_t sl320;
	uint16_t sl640;
	uint16_t sl1280;
	uint16_t sl2560;
};

struct SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset {
	enum SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_Sel d;
	union SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_Value v;
};

enum SQN_NR_SearchSpace_nrofCandidates_aggregationLevel1_e {
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel1_e_n0 = 0,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel1_e_n1 = 1,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel1_e_n2 = 2,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel1_e_n3 = 3,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel1_e_n4 = 4,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel1_e_n5 = 5,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel1_e_n6 = 6,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel1_e_n8 = 7,
};

typedef enum SQN_NR_SearchSpace_nrofCandidates_aggregationLevel1_e SQN_NR_SearchSpace_nrofCandidates_aggregationLevel1_e;

enum SQN_NR_SearchSpace_nrofCandidates_aggregationLevel2_e {
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel2_e_n0 = 0,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel2_e_n1 = 1,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel2_e_n2 = 2,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel2_e_n3 = 3,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel2_e_n4 = 4,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel2_e_n5 = 5,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel2_e_n6 = 6,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel2_e_n8 = 7,
};

typedef enum SQN_NR_SearchSpace_nrofCandidates_aggregationLevel2_e SQN_NR_SearchSpace_nrofCandidates_aggregationLevel2_e;

enum SQN_NR_SearchSpace_nrofCandidates_aggregationLevel4_e {
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel4_e_n0 = 0,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel4_e_n1 = 1,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel4_e_n2 = 2,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel4_e_n3 = 3,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel4_e_n4 = 4,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel4_e_n5 = 5,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel4_e_n6 = 6,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel4_e_n8 = 7,
};

typedef enum SQN_NR_SearchSpace_nrofCandidates_aggregationLevel4_e SQN_NR_SearchSpace_nrofCandidates_aggregationLevel4_e;

enum SQN_NR_SearchSpace_nrofCandidates_aggregationLevel8_e {
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel8_e_n0 = 0,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel8_e_n1 = 1,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel8_e_n2 = 2,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel8_e_n3 = 3,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel8_e_n4 = 4,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel8_e_n5 = 5,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel8_e_n6 = 6,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel8_e_n8 = 7,
};

typedef enum SQN_NR_SearchSpace_nrofCandidates_aggregationLevel8_e SQN_NR_SearchSpace_nrofCandidates_aggregationLevel8_e;

enum SQN_NR_SearchSpace_nrofCandidates_aggregationLevel16_e {
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel16_e_n0 = 0,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel16_e_n1 = 1,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel16_e_n2 = 2,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel16_e_n3 = 3,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel16_e_n4 = 4,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel16_e_n5 = 5,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel16_e_n6 = 6,
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel16_e_n8 = 7,
};

typedef enum SQN_NR_SearchSpace_nrofCandidates_aggregationLevel16_e SQN_NR_SearchSpace_nrofCandidates_aggregationLevel16_e;

struct SQN_NR_SearchSpace_nrofCandidates {
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel1_e aggregationLevel1;
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel2_e aggregationLevel2;
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel4_e aggregationLevel4;
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel8_e aggregationLevel8;
	SQN_NR_SearchSpace_nrofCandidates_aggregationLevel16_e aggregationLevel16;
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format0_0_AndFormat1_0 {
};

enum SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel1_e {
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel1_e_n1 = 0,
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel1_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel1_e SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel1_e;

enum SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel2_e {
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel2_e_n1 = 0,
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel2_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel2_e SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel2_e;

enum SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel4_e {
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel4_e_n1 = 0,
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel4_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel4_e SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel4_e;

enum SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel8_e {
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel8_e_n1 = 0,
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel8_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel8_e SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel8_e;

enum SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel16_e {
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel16_e_n1 = 0,
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel16_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel16_e SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel16_e;

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel1_e_aggregationLevel1_Optional {
	bool d;
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel1_e v;
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel2_e_aggregationLevel2_Optional {
	bool d;
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel2_e v;
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel4_e_aggregationLevel4_Optional {
	bool d;
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel4_e v;
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel8_e_aggregationLevel8_Optional {
	bool d;
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel8_e v;
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel16_e_aggregationLevel16_Optional {
	bool d;
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel16_e v;
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFI {
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel1_e_aggregationLevel1_Optional aggregationLevel1;
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel2_e_aggregationLevel2_Optional aggregationLevel2;
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel4_e_aggregationLevel4_Optional aggregationLevel4;
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel8_e_aggregationLevel8_Optional aggregationLevel8;
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFIaggregationLevel16_e_aggregationLevel16_Optional aggregationLevel16;
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0 {
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0nrofCandidates_SFI nrofCandidates_SFI;
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_1 {
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_2 {
};

enum SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy1_e {
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy1_e_sl1 = 0,
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy1_e_sl2 = 1,
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy1_e_sl4 = 2,
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy1_e_sl5 = 3,
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy1_e_sl8 = 4,
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy1_e_sl10 = 5,
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy1_e_sl16 = 6,
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy1_e_sl20 = 7,
};

typedef enum SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy1_e SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy1_e;

enum SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy2_e {
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy2_e_n1 = 0,
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy2_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy2_e SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy2_e;

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy1_e_dummy1_Optional {
	bool d;
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy1_e v;
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3 {
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy1_e_dummy1_Optional dummy1;
	SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3dummy2_e dummy2;
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format0_0_AndFormat1_0_dci_Format0_0_AndFormat1_0_Optional {
	bool d;
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format0_0_AndFormat1_0 v;
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0_dci_Format2_0_Optional {
	bool d;
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0 v;
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_1_dci_Format2_1_Optional {
	bool d;
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_1 v;
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_2_dci_Format2_2_Optional {
	bool d;
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_2 v;
};

struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3_dci_Format2_3_Optional {
	bool d;
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3 v;
};

struct SQN_NR_SearchSpace_searchSpaceType_common {
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format0_0_AndFormat1_0_dci_Format0_0_AndFormat1_0_Optional dci_Format0_0_AndFormat1_0;
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_0_dci_Format2_0_Optional dci_Format2_0;
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_1_dci_Format2_1_Optional dci_Format2_1;
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_2_dci_Format2_2_Optional dci_Format2_2;
	struct SQN_NR_SearchSpace_searchSpaceType_common_dci_Format2_3_dci_Format2_3_Optional dci_Format2_3;
};

enum SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_Formats_e {
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_Formats_e_formats0_0_And_1_0 = 0,
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_Formats_e_formats0_1_And_1_1 = 1,
};

typedef enum SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_Formats_e SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_Formats_e;

enum SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_Formats_MT_r16_e {
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_Formats_MT_r16_e_formats2_5 = 0,
};

typedef enum SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_Formats_MT_r16_e SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_Formats_MT_r16_e;

enum SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsSL_r16_e {
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsSL_r16_e_formats0_0_And_1_0 = 0,
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsSL_r16_e_formats0_1_And_1_1 = 1,
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsSL_r16_e_formats3_0 = 2,
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsSL_r16_e_formats3_1 = 3,
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsSL_r16_e_formats3_0_And_3_1 = 4,
};

typedef enum SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsSL_r16_e SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsSL_r16_e;

enum SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsExt_r16_e {
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsExt_r16_e_formats0_2_And_1_2 = 0,
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsExt_r16_e_formats0_1_And_1_1And_0_2_And_1_2 = 1,
};

typedef enum SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsExt_r16_e SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsExt_r16_e;

struct SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_Formats_MT_r16_e_dci_Formats_MT_r16_Optional {
	bool d;
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_Formats_MT_r16_e v;
};

struct SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsSL_r16_e_dci_FormatsSL_r16_Optional {
	bool d;
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsSL_r16_e v;
};

struct SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsExt_r16_e_dci_FormatsExt_r16_Optional {
	bool d;
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsExt_r16_e v;
};

struct SQN_NR_SearchSpace_searchSpaceType_ue_Specific {
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_Formats_e dci_Formats;
	struct SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_Formats_MT_r16_e_dci_Formats_MT_r16_Optional dci_Formats_MT_r16;
	struct SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsSL_r16_e_dci_FormatsSL_r16_Optional dci_FormatsSL_r16;
	struct SQN_NR_SearchSpace_searchSpaceType_ue_Specific_dci_FormatsExt_r16_e_dci_FormatsExt_r16_Optional dci_FormatsExt_r16;
};

enum SQN_NR_SearchSpace_searchSpaceType_Sel {
	SQN_NR_SearchSpace_searchSpaceType_UNBOUND_VALUE = 0,
	SQN_NR_SearchSpace_searchSpaceType_common = 1,
	SQN_NR_SearchSpace_searchSpaceType_ue_Specific = 2,
};

union SQN_NR_SearchSpace_searchSpaceType_Value {
	struct SQN_NR_SearchSpace_searchSpaceType_common common;
	struct SQN_NR_SearchSpace_searchSpaceType_ue_Specific ue_Specific;
};

struct SQN_NR_SearchSpace_searchSpaceType {
	enum SQN_NR_SearchSpace_searchSpaceType_Sel d;
	union SQN_NR_SearchSpace_searchSpaceType_Value v;
};

struct SQN_NR_ControlResourceSetId_SQN_NR_SearchSpace_controlResourceSetId_Optional {
	bool d;
	SQN_NR_ControlResourceSetId v;
};

struct SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_monitoringSlotPeriodicityAndOffset_Optional {
	bool d;
	struct SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset v;
};

struct uint16_t_SQN_NR_SearchSpace_duration_Optional {
	bool d;
	uint16_t v;
};

struct B14_SQN_NR_SearchSpace_monitoringSymbolsWithinSlot_Optional {
	bool d;
	B14 v;
};

struct SQN_NR_SearchSpace_nrofCandidates_nrofCandidates_Optional {
	bool d;
	struct SQN_NR_SearchSpace_nrofCandidates v;
};

struct SQN_NR_SearchSpace_searchSpaceType_searchSpaceType_Optional {
	bool d;
	struct SQN_NR_SearchSpace_searchSpaceType v;
};

struct SQN_NR_SearchSpace {
	SQN_NR_SearchSpaceId searchSpaceId;
	struct SQN_NR_ControlResourceSetId_SQN_NR_SearchSpace_controlResourceSetId_Optional controlResourceSetId;
	struct SQN_NR_SearchSpace_monitoringSlotPeriodicityAndOffset_monitoringSlotPeriodicityAndOffset_Optional monitoringSlotPeriodicityAndOffset;
	struct uint16_t_SQN_NR_SearchSpace_duration_Optional duration;
	struct B14_SQN_NR_SearchSpace_monitoringSymbolsWithinSlot_Optional monitoringSymbolsWithinSlot;
	struct SQN_NR_SearchSpace_nrofCandidates_nrofCandidates_Optional nrofCandidates;
	struct SQN_NR_SearchSpace_searchSpaceType_searchSpaceType_Optional searchSpaceType;
};

enum SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_Sel {
	SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_UNBOUND_VALUE = 0,
	SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS15KHZoneT = 1,
	SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS30KHZoneT_SCS15KHZhalfT = 2,
	SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS60KHZoneT_SCS30KHZhalfT_SCS15KHZquarterT = 3,
	SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneT_SCS60KHZhalfT_SCS30KHZquarterT_SCS15KHZoneEighthT = 4,
	SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZhalfT_SCS60KHZquarterT_SCS30KHZoneEighthT_SCS15KHZoneSixteenthT = 5,
	SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZquarterT_SCS60KHZoneEighthT_SCS30KHZoneSixteenthT = 6,
	SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneEighthT_SCS60KHZoneSixteenthT = 7,
	SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneSixteenthT = 8,
};

struct uint8_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS15KHZoneT_Dynamic {
	size_t d;
	uint8_t* v;
};

struct uint16_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS30KHZoneT_SCS15KHZhalfT_Dynamic {
	size_t d;
	uint16_t* v;
};

struct uint16_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS60KHZoneT_SCS30KHZhalfT_SCS15KHZquarterT_Dynamic {
	size_t d;
	uint16_t* v;
};

struct uint16_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneT_SCS60KHZhalfT_SCS30KHZquarterT_SCS15KHZoneEighthT_Dynamic {
	size_t d;
	uint16_t* v;
};

struct uint16_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZhalfT_SCS60KHZquarterT_SCS30KHZoneEighthT_SCS15KHZoneSixteenthT_Dynamic {
	size_t d;
	uint16_t* v;
};

struct uint16_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZquarterT_SCS60KHZoneEighthT_SCS30KHZoneSixteenthT_Dynamic {
	size_t d;
	uint16_t* v;
};

struct uint16_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneEighthT_SCS60KHZoneSixteenthT_Dynamic {
	size_t d;
	uint16_t* v;
};

struct uint16_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneSixteenthT_Dynamic {
	size_t d;
	uint16_t* v;
};

union SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_Value {
	struct uint8_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS15KHZoneT_Dynamic sCS15KHZoneT;
	struct uint16_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS30KHZoneT_SCS15KHZhalfT_Dynamic sCS30KHZoneT_SCS15KHZhalfT;
	struct uint16_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS60KHZoneT_SCS30KHZhalfT_SCS15KHZquarterT_Dynamic sCS60KHZoneT_SCS30KHZhalfT_SCS15KHZquarterT;
	struct uint16_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneT_SCS60KHZhalfT_SCS30KHZquarterT_SCS15KHZoneEighthT_Dynamic sCS120KHZoneT_SCS60KHZhalfT_SCS30KHZquarterT_SCS15KHZoneEighthT;
	struct uint16_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZhalfT_SCS60KHZquarterT_SCS30KHZoneEighthT_SCS15KHZoneSixteenthT_Dynamic sCS120KHZhalfT_SCS60KHZquarterT_SCS30KHZoneEighthT_SCS15KHZoneSixteenthT;
	struct uint16_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZquarterT_SCS60KHZoneEighthT_SCS30KHZoneSixteenthT_Dynamic sCS120KHZquarterT_SCS60KHZoneEighthT_SCS30KHZoneSixteenthT;
	struct uint16_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneEighthT_SCS60KHZoneSixteenthT_Dynamic sCS120KHZoneEighthT_SCS60KHZoneSixteenthT;
	struct uint16_t_SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneSixteenthT_Dynamic sCS120KHZoneSixteenthT;
};

struct SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO {
	enum SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_Sel d;
	union SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_Value v;
};

typedef uint8_t SQN_NR_ControlResourceSetId_r16;

enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel1_r16_e {
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel1_r16_e_n1 = 0,
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel1_r16_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel1_r16_e SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel1_r16_e;

enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel2_r16_e {
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel2_r16_e_n1 = 0,
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel2_r16_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel2_r16_e SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel2_r16_e;

enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel4_r16_e {
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel4_r16_e_n1 = 0,
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel4_r16_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel4_r16_e SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel4_r16_e;

enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel8_r16_e {
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel8_r16_e_n1 = 0,
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel8_r16_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel8_r16_e SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel8_r16_e;

enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel16_r16_e {
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel16_r16_e_n1 = 0,
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel16_r16_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel16_r16_e SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel16_r16_e;

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel1_r16_e_aggregationLevel1_r16_Optional {
	bool d;
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel1_r16_e v;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel2_r16_e_aggregationLevel2_r16_Optional {
	bool d;
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel2_r16_e v;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel4_r16_e_aggregationLevel4_r16_Optional {
	bool d;
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel4_r16_e v;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel8_r16_e_aggregationLevel8_r16_Optional {
	bool d;
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel8_r16_e v;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel16_r16_e_aggregationLevel16_r16_Optional {
	bool d;
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel16_r16_e v;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16 {
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel1_r16_e_aggregationLevel1_r16_Optional aggregationLevel1_r16;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel2_r16_e_aggregationLevel2_r16_Optional aggregationLevel2_r16;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel4_r16_e_aggregationLevel4_r16_Optional aggregationLevel4_r16;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel8_r16_e_aggregationLevel8_r16_Optional aggregationLevel8_r16;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16aggregationLevel16_r16_e_aggregationLevel16_r16_Optional aggregationLevel16_r16;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16 {
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16nrofCandidates_CI_r16 nrofCandidates_CI_r16;
};

enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel1_r16_e {
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel1_r16_e_n1 = 0,
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel1_r16_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel1_r16_e SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel1_r16_e;

enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel2_r16_e {
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel2_r16_e_n1 = 0,
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel2_r16_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel2_r16_e SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel2_r16_e;

enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel4_r16_e {
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel4_r16_e_n1 = 0,
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel4_r16_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel4_r16_e SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel4_r16_e;

enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel8_r16_e {
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel8_r16_e_n1 = 0,
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel8_r16_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel8_r16_e SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel8_r16_e;

enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel16_r16_e {
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel16_r16_e_n1 = 0,
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel16_r16_e_n2 = 1,
};

typedef enum SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel16_r16_e SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel16_r16_e;

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel1_r16_e_aggregationLevel1_r16_Optional {
	bool d;
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel1_r16_e v;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel2_r16_e_aggregationLevel2_r16_Optional {
	bool d;
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel2_r16_e v;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel4_r16_e_aggregationLevel4_r16_Optional {
	bool d;
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel4_r16_e v;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel8_r16_e_aggregationLevel8_r16_Optional {
	bool d;
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel8_r16_e v;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel16_r16_e_aggregationLevel16_r16_Optional {
	bool d;
	SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel16_r16_e v;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16 {
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel1_r16_e_aggregationLevel1_r16_Optional aggregationLevel1_r16;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel2_r16_e_aggregationLevel2_r16_Optional aggregationLevel2_r16;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel4_r16_e_aggregationLevel4_r16_Optional aggregationLevel4_r16;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel8_r16_e_aggregationLevel8_r16_Optional aggregationLevel8_r16;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16aggregationLevel16_r16_e_aggregationLevel16_r16_Optional aggregationLevel16_r16;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16 {
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16nrofCandidates_IAB_r16 nrofCandidates_IAB_r16;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_6_r16 {
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16_dci_Format2_4_r16_Optional {
	bool d;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16 v;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16_dci_Format2_5_r16_Optional {
	bool d;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16 v;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_6_r16_dci_Format2_6_r16_Optional {
	bool d;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_6_r16 v;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16 {
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_4_r16_dci_Format2_4_r16_Optional dci_Format2_4_r16;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_5_r16_dci_Format2_5_r16_Optional dci_Format2_5_r16;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16_dci_Format2_6_r16_dci_Format2_6_r16_Optional dci_Format2_6_r16;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16 {
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_common_r16 common_r16;
};

struct SQN_NR_ControlResourceSetId_r16_SQN_NR_SearchSpaceExt_r16_controlResourceSetId_r16_Optional {
	bool d;
	SQN_NR_ControlResourceSetId_r16 v;
};

struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_searchSpaceType_r16_Optional {
	bool d;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16 v;
};

struct uint8_t_SQN_NR_SearchSpaceExt_r16_searchSpaceGroupIdList_r16_Dynamic {
	size_t d;
	uint8_t* v;
};

struct uint8_t_SQN_NR_SearchSpaceExt_r16_searchSpaceGroupIdList_r16_DynamicOptional {
	bool d;
	struct uint8_t_SQN_NR_SearchSpaceExt_r16_searchSpaceGroupIdList_r16_Dynamic v;
};

struct B5_SQN_NR_SearchSpaceExt_r16_freqMonitorLocations_r16_Optional {
	bool d;
	B5 v;
};

struct SQN_NR_SearchSpaceExt_r16 {
	struct SQN_NR_ControlResourceSetId_r16_SQN_NR_SearchSpaceExt_r16_controlResourceSetId_r16_Optional controlResourceSetId_r16;
	struct SQN_NR_SearchSpaceExt_r16_searchSpaceType_r16_searchSpaceType_r16_Optional searchSpaceType_r16;
	struct uint8_t_SQN_NR_SearchSpaceExt_r16_searchSpaceGroupIdList_r16_DynamicOptional searchSpaceGroupIdList_r16;
	struct B5_SQN_NR_SearchSpaceExt_r16_freqMonitorLocations_r16_Optional freqMonitorLocations_r16;
};

struct SQN_NR_ControlResourceSetZero_SQN_NR_PDCCH_ConfigCommon_controlResourceSetZero_Optional {
	bool d;
	SQN_NR_ControlResourceSetZero v;
};

struct SQN_NR_ControlResourceSet_SQN_NR_PDCCH_ConfigCommon_commonControlResourceSet_Optional {
	bool d;
	struct SQN_NR_ControlResourceSet v;
};

struct SQN_NR_SearchSpaceZero_SQN_NR_PDCCH_ConfigCommon_searchSpaceZero_Optional {
	bool d;
	SQN_NR_SearchSpaceZero v;
};

struct SQN_NR_PDCCH_ConfigCommon_SQN_NR_SearchSpace_commonSearchSpaceList_Dynamic {
	size_t d;
	struct SQN_NR_SearchSpace* v;
};

struct SQN_NR_SearchSpace_SQN_NR_PDCCH_ConfigCommon_commonSearchSpaceList_DynamicOptional {
	bool d;
	struct SQN_NR_PDCCH_ConfigCommon_SQN_NR_SearchSpace_commonSearchSpaceList_Dynamic v;
};

struct SQN_NR_SearchSpaceId_SQN_NR_PDCCH_ConfigCommon_searchSpaceSIB1_Optional {
	bool d;
	SQN_NR_SearchSpaceId v;
};

struct SQN_NR_SearchSpaceId_SQN_NR_PDCCH_ConfigCommon_searchSpaceOtherSystemInformation_Optional {
	bool d;
	SQN_NR_SearchSpaceId v;
};

struct SQN_NR_SearchSpaceId_SQN_NR_PDCCH_ConfigCommon_pagingSearchSpace_Optional {
	bool d;
	SQN_NR_SearchSpaceId v;
};

struct SQN_NR_SearchSpaceId_SQN_NR_PDCCH_ConfigCommon_ra_SearchSpace_Optional {
	bool d;
	SQN_NR_SearchSpaceId v;
};

struct SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_firstPDCCH_MonitoringOccasionOfPO_Optional {
	bool d;
	struct SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO v;
};

struct SQN_NR_PDCCH_ConfigCommon_SQN_NR_SearchSpaceExt_r16_commonSearchSpaceListExt_r16_Dynamic {
	size_t d;
	struct SQN_NR_SearchSpaceExt_r16* v;
};

struct SQN_NR_SearchSpaceExt_r16_SQN_NR_PDCCH_ConfigCommon_commonSearchSpaceListExt_r16_DynamicOptional {
	bool d;
	struct SQN_NR_PDCCH_ConfigCommon_SQN_NR_SearchSpaceExt_r16_commonSearchSpaceListExt_r16_Dynamic v;
};

struct SQN_NR_PDCCH_ConfigCommon {
	struct SQN_NR_ControlResourceSetZero_SQN_NR_PDCCH_ConfigCommon_controlResourceSetZero_Optional controlResourceSetZero;
	struct SQN_NR_ControlResourceSet_SQN_NR_PDCCH_ConfigCommon_commonControlResourceSet_Optional commonControlResourceSet;
	struct SQN_NR_SearchSpaceZero_SQN_NR_PDCCH_ConfigCommon_searchSpaceZero_Optional searchSpaceZero;
	struct SQN_NR_SearchSpace_SQN_NR_PDCCH_ConfigCommon_commonSearchSpaceList_DynamicOptional commonSearchSpaceList;
	struct SQN_NR_SearchSpaceId_SQN_NR_PDCCH_ConfigCommon_searchSpaceSIB1_Optional searchSpaceSIB1;
	struct SQN_NR_SearchSpaceId_SQN_NR_PDCCH_ConfigCommon_searchSpaceOtherSystemInformation_Optional searchSpaceOtherSystemInformation;
	struct SQN_NR_SearchSpaceId_SQN_NR_PDCCH_ConfigCommon_pagingSearchSpace_Optional pagingSearchSpace;
	struct SQN_NR_SearchSpaceId_SQN_NR_PDCCH_ConfigCommon_ra_SearchSpace_Optional ra_SearchSpace;
	struct SQN_NR_PDCCH_ConfigCommon_firstPDCCH_MonitoringOccasionOfPO_firstPDCCH_MonitoringOccasionOfPO_Optional firstPDCCH_MonitoringOccasionOfPO;
	struct SQN_NR_SearchSpaceExt_r16_SQN_NR_PDCCH_ConfigCommon_commonSearchSpaceListExt_r16_DynamicOptional commonSearchSpaceListExt_r16;
};

enum SQN_NR_SetupRelease_BWP_DownlinkCommon_pdcch_ConfigCommon_Sel {
	SQN_NR_SetupRelease_BWP_DownlinkCommon_pdcch_ConfigCommon_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_DownlinkCommon_pdcch_ConfigCommon_release = 1,
	SQN_NR_SetupRelease_BWP_DownlinkCommon_pdcch_ConfigCommon_setup = 2,
};

union SQN_NR_SetupRelease_BWP_DownlinkCommon_pdcch_ConfigCommon_Value {
	Null release;
	struct SQN_NR_PDCCH_ConfigCommon setup;
};

struct SQN_NR_SetupRelease_BWP_DownlinkCommon_pdcch_ConfigCommon {
	enum SQN_NR_SetupRelease_BWP_DownlinkCommon_pdcch_ConfigCommon_Sel d;
	union SQN_NR_SetupRelease_BWP_DownlinkCommon_pdcch_ConfigCommon_Value v;
};

enum SQN_NR_PDSCH_TimeDomainResourceAllocation_mappingType_e {
	SQN_NR_PDSCH_TimeDomainResourceAllocation_mappingType_e_typeA = 0,
	SQN_NR_PDSCH_TimeDomainResourceAllocation_mappingType_e_typeB = 1,
};

typedef enum SQN_NR_PDSCH_TimeDomainResourceAllocation_mappingType_e SQN_NR_PDSCH_TimeDomainResourceAllocation_mappingType_e;

struct uint8_t_SQN_NR_PDSCH_TimeDomainResourceAllocation_k0_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PDSCH_TimeDomainResourceAllocation {
	struct uint8_t_SQN_NR_PDSCH_TimeDomainResourceAllocation_k0_Optional k0;
	SQN_NR_PDSCH_TimeDomainResourceAllocation_mappingType_e mappingType;
	uint8_t startSymbolAndLength;
};

struct SQN_NR_PDSCH_TimeDomainResourceAllocation_SQN_NR_PDSCH_TimeDomainResourceAllocationList_Dynamic {
	size_t d;
	struct SQN_NR_PDSCH_TimeDomainResourceAllocation* v;
};

typedef struct SQN_NR_PDSCH_TimeDomainResourceAllocation_SQN_NR_PDSCH_TimeDomainResourceAllocationList_Dynamic SQN_NR_PDSCH_TimeDomainResourceAllocationList;

struct SQN_NR_PDSCH_TimeDomainResourceAllocationList_SQN_NR_PDSCH_ConfigCommon_pdsch_TimeDomainAllocationList_Optional {
	bool d;
	SQN_NR_PDSCH_TimeDomainResourceAllocationList v;
};

struct SQN_NR_PDSCH_ConfigCommon {
	struct SQN_NR_PDSCH_TimeDomainResourceAllocationList_SQN_NR_PDSCH_ConfigCommon_pdsch_TimeDomainAllocationList_Optional pdsch_TimeDomainAllocationList;
};

enum SQN_NR_SetupRelease_BWP_DownlinkCommon_pdsch_ConfigCommon_Sel {
	SQN_NR_SetupRelease_BWP_DownlinkCommon_pdsch_ConfigCommon_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_DownlinkCommon_pdsch_ConfigCommon_release = 1,
	SQN_NR_SetupRelease_BWP_DownlinkCommon_pdsch_ConfigCommon_setup = 2,
};

union SQN_NR_SetupRelease_BWP_DownlinkCommon_pdsch_ConfigCommon_Value {
	Null release;
	struct SQN_NR_PDSCH_ConfigCommon setup;
};

struct SQN_NR_SetupRelease_BWP_DownlinkCommon_pdsch_ConfigCommon {
	enum SQN_NR_SetupRelease_BWP_DownlinkCommon_pdsch_ConfigCommon_Sel d;
	union SQN_NR_SetupRelease_BWP_DownlinkCommon_pdsch_ConfigCommon_Value v;
};

struct SQN_NR_SetupRelease_BWP_DownlinkCommon_pdcch_ConfigCommon_SQN_NR_BWP_DownlinkCommon_pdcch_ConfigCommon_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_DownlinkCommon_pdcch_ConfigCommon v;
};

struct SQN_NR_SetupRelease_BWP_DownlinkCommon_pdsch_ConfigCommon_SQN_NR_BWP_DownlinkCommon_pdsch_ConfigCommon_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_DownlinkCommon_pdsch_ConfigCommon v;
};

struct SQN_NR_BWP_DownlinkCommon {
	struct SQN_NR_BWP genericParameters;
	struct SQN_NR_SetupRelease_BWP_DownlinkCommon_pdcch_ConfigCommon_SQN_NR_BWP_DownlinkCommon_pdcch_ConfigCommon_Optional pdcch_ConfigCommon;
	struct SQN_NR_SetupRelease_BWP_DownlinkCommon_pdsch_ConfigCommon_SQN_NR_BWP_DownlinkCommon_pdsch_ConfigCommon_Optional pdsch_ConfigCommon;
};

enum SQN_NR_BCCH_Config_modificationPeriodCoeff_e {
	SQN_NR_BCCH_Config_modificationPeriodCoeff_e_n2 = 0,
	SQN_NR_BCCH_Config_modificationPeriodCoeff_e_n4 = 1,
	SQN_NR_BCCH_Config_modificationPeriodCoeff_e_n8 = 2,
	SQN_NR_BCCH_Config_modificationPeriodCoeff_e_n16 = 3,
};

typedef enum SQN_NR_BCCH_Config_modificationPeriodCoeff_e SQN_NR_BCCH_Config_modificationPeriodCoeff_e;

struct SQN_NR_BCCH_Config {
	SQN_NR_BCCH_Config_modificationPeriodCoeff_e modificationPeriodCoeff;
};

enum SQN_NR_PagingCycle_e {
	SQN_NR_PagingCycle_e_rf32 = 0,
	SQN_NR_PagingCycle_e_rf64 = 1,
	SQN_NR_PagingCycle_e_rf128 = 2,
	SQN_NR_PagingCycle_e_rf256 = 3,
};

typedef enum SQN_NR_PagingCycle_e SQN_NR_PagingCycle_e;

enum SQN_NR_PCCH_Config_nAndPagingFrameOffset_Sel {
	SQN_NR_PCCH_Config_nAndPagingFrameOffset_UNBOUND_VALUE = 0,
	SQN_NR_PCCH_Config_nAndPagingFrameOffset_oneT = 1,
	SQN_NR_PCCH_Config_nAndPagingFrameOffset_halfT = 2,
	SQN_NR_PCCH_Config_nAndPagingFrameOffset_quarterT = 3,
	SQN_NR_PCCH_Config_nAndPagingFrameOffset_oneEighthT = 4,
	SQN_NR_PCCH_Config_nAndPagingFrameOffset_oneSixteenthT = 5,
};

union SQN_NR_PCCH_Config_nAndPagingFrameOffset_Value {
	Null oneT;
	uint8_t halfT;
	uint8_t quarterT;
	uint8_t oneEighthT;
	uint8_t oneSixteenthT;
};

struct SQN_NR_PCCH_Config_nAndPagingFrameOffset {
	enum SQN_NR_PCCH_Config_nAndPagingFrameOffset_Sel d;
	union SQN_NR_PCCH_Config_nAndPagingFrameOffset_Value v;
};

enum SQN_NR_PCCH_Config_ns_e {
	SQN_NR_PCCH_Config_ns_e_four = 0,
	SQN_NR_PCCH_Config_ns_e_two = 1,
	SQN_NR_PCCH_Config_ns_e_one = 2,
};

typedef enum SQN_NR_PCCH_Config_ns_e SQN_NR_PCCH_Config_ns_e;

enum SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_Sel {
	SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_UNBOUND_VALUE = 0,
	SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS15KHZoneT = 1,
	SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS30KHZoneT_SCS15KHZhalfT = 2,
	SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS60KHZoneT_SCS30KHZhalfT_SCS15KHZquarterT = 3,
	SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneT_SCS60KHZhalfT_SCS30KHZquarterT_SCS15KHZoneEighthT = 4,
	SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZhalfT_SCS60KHZquarterT_SCS30KHZoneEighthT_SCS15KHZoneSixteenthT = 5,
	SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZquarterT_SCS60KHZoneEighthT_SCS30KHZoneSixteenthT = 6,
	SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneEighthT_SCS60KHZoneSixteenthT = 7,
	SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneSixteenthT = 8,
};

struct uint8_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS15KHZoneT_Dynamic {
	size_t d;
	uint8_t* v;
};

struct uint16_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS30KHZoneT_SCS15KHZhalfT_Dynamic {
	size_t d;
	uint16_t* v;
};

struct uint16_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS60KHZoneT_SCS30KHZhalfT_SCS15KHZquarterT_Dynamic {
	size_t d;
	uint16_t* v;
};

struct uint16_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneT_SCS60KHZhalfT_SCS30KHZquarterT_SCS15KHZoneEighthT_Dynamic {
	size_t d;
	uint16_t* v;
};

struct uint16_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZhalfT_SCS60KHZquarterT_SCS30KHZoneEighthT_SCS15KHZoneSixteenthT_Dynamic {
	size_t d;
	uint16_t* v;
};

struct uint16_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZquarterT_SCS60KHZoneEighthT_SCS30KHZoneSixteenthT_Dynamic {
	size_t d;
	uint16_t* v;
};

struct uint16_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneEighthT_SCS60KHZoneSixteenthT_Dynamic {
	size_t d;
	uint16_t* v;
};

struct uint16_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneSixteenthT_Dynamic {
	size_t d;
	uint16_t* v;
};

union SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_Value {
	struct uint8_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS15KHZoneT_Dynamic sCS15KHZoneT;
	struct uint16_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS30KHZoneT_SCS15KHZhalfT_Dynamic sCS30KHZoneT_SCS15KHZhalfT;
	struct uint16_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS60KHZoneT_SCS30KHZhalfT_SCS15KHZquarterT_Dynamic sCS60KHZoneT_SCS30KHZhalfT_SCS15KHZquarterT;
	struct uint16_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneT_SCS60KHZhalfT_SCS30KHZquarterT_SCS15KHZoneEighthT_Dynamic sCS120KHZoneT_SCS60KHZhalfT_SCS30KHZquarterT_SCS15KHZoneEighthT;
	struct uint16_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZhalfT_SCS60KHZquarterT_SCS30KHZoneEighthT_SCS15KHZoneSixteenthT_Dynamic sCS120KHZhalfT_SCS60KHZquarterT_SCS30KHZoneEighthT_SCS15KHZoneSixteenthT;
	struct uint16_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZquarterT_SCS60KHZoneEighthT_SCS30KHZoneSixteenthT_Dynamic sCS120KHZquarterT_SCS60KHZoneEighthT_SCS30KHZoneSixteenthT;
	struct uint16_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneEighthT_SCS60KHZoneSixteenthT_Dynamic sCS120KHZoneEighthT_SCS60KHZoneSixteenthT;
	struct uint16_t_SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_sCS120KHZoneSixteenthT_Dynamic sCS120KHZoneSixteenthT;
};

struct SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO {
	enum SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_Sel d;
	union SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_Value v;
};

struct SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_firstPDCCH_MonitoringOccasionOfPO_Optional {
	bool d;
	struct SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO v;
};

struct uint8_t_SQN_NR_PCCH_Config_nrofPDCCH_MonitoringOccasionPerSSB_InPO_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PCCH_Config {
	SQN_NR_PagingCycle_e defaultPagingCycle;
	struct SQN_NR_PCCH_Config_nAndPagingFrameOffset nAndPagingFrameOffset;
	SQN_NR_PCCH_Config_ns_e ns;
	struct SQN_NR_PCCH_Config_firstPDCCH_MonitoringOccasionOfPO_firstPDCCH_MonitoringOccasionOfPO_Optional firstPDCCH_MonitoringOccasionOfPO;
	struct uint8_t_SQN_NR_PCCH_Config_nrofPDCCH_MonitoringOccasionPerSSB_InPO_r16_Optional nrofPDCCH_MonitoringOccasionPerSSB_InPO_r16;
};

struct SQN_NR_DownlinkConfigCommonSIB {
	struct SQN_NR_FrequencyInfoDL_SIB frequencyInfoDL;
	struct SQN_NR_BWP_DownlinkCommon initialDownlinkBWP;
	struct SQN_NR_BCCH_Config bcch_Config;
	struct SQN_NR_PCCH_Config pcch_Config;
};

enum SQN_NR_FrequencyInfoUL_SIB_frequencyShift7p5khz_e {
	SQN_NR_FrequencyInfoUL_SIB_frequencyShift7p5khz_e_true = 0,
};

typedef enum SQN_NR_FrequencyInfoUL_SIB_frequencyShift7p5khz_e SQN_NR_FrequencyInfoUL_SIB_frequencyShift7p5khz_e;

struct SQN_NR_MultiFrequencyBandListNR_SIB_SQN_NR_FrequencyInfoUL_SIB_frequencyBandList_Optional {
	bool d;
	SQN_NR_MultiFrequencyBandListNR_SIB v;
};

struct SQN_NR_ARFCN_ValueNR_SQN_NR_FrequencyInfoUL_SIB_absoluteFrequencyPointA_Optional {
	bool d;
	SQN_NR_ARFCN_ValueNR v;
};

struct SQN_NR_SCS_SpecificCarrier_SQN_NR_FrequencyInfoUL_SIB_scs_SpecificCarrierList_Dynamic {
	size_t d;
	struct SQN_NR_SCS_SpecificCarrier* v;
};

struct SQN_NR_P_Max_SQN_NR_FrequencyInfoUL_SIB_p_Max_Optional {
	bool d;
	SQN_NR_P_Max v;
};

struct SQN_NR_FrequencyInfoUL_SIB_frequencyShift7p5khz_e_frequencyShift7p5khz_Optional {
	bool d;
	SQN_NR_FrequencyInfoUL_SIB_frequencyShift7p5khz_e v;
};

struct SQN_NR_FrequencyInfoUL_SIB {
	struct SQN_NR_MultiFrequencyBandListNR_SIB_SQN_NR_FrequencyInfoUL_SIB_frequencyBandList_Optional frequencyBandList;
	struct SQN_NR_ARFCN_ValueNR_SQN_NR_FrequencyInfoUL_SIB_absoluteFrequencyPointA_Optional absoluteFrequencyPointA;
	struct SQN_NR_SCS_SpecificCarrier_SQN_NR_FrequencyInfoUL_SIB_scs_SpecificCarrierList_Dynamic scs_SpecificCarrierList;
	struct SQN_NR_P_Max_SQN_NR_FrequencyInfoUL_SIB_p_Max_Optional p_Max;
	struct SQN_NR_FrequencyInfoUL_SIB_frequencyShift7p5khz_e_frequencyShift7p5khz_Optional frequencyShift7p5khz;
};

enum SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e {
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n4 = 0,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n8 = 1,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n12 = 2,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n16 = 3,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n20 = 4,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n24 = 5,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n28 = 6,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n32 = 7,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n36 = 8,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n40 = 9,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n44 = 10,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n48 = 11,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n52 = 12,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n56 = 13,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n60 = 14,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e_n64 = 15,
};

typedef enum SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e;

enum SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e {
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n4 = 0,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n8 = 1,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n12 = 2,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n16 = 3,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n20 = 4,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n24 = 5,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n28 = 6,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n32 = 7,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n36 = 8,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n40 = 9,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n44 = 10,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n48 = 11,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n52 = 12,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n56 = 13,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n60 = 14,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e_n64 = 15,
};

typedef enum SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e;

enum SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e {
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n4 = 0,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n8 = 1,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n12 = 2,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n16 = 3,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n20 = 4,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n24 = 5,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n28 = 6,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n32 = 7,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n36 = 8,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n40 = 9,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n44 = 10,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n48 = 11,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n52 = 12,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n56 = 13,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n60 = 14,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e_n64 = 15,
};

typedef enum SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e;

enum SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e {
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n4 = 0,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n8 = 1,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n12 = 2,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n16 = 3,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n20 = 4,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n24 = 5,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n28 = 6,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n32 = 7,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n36 = 8,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n40 = 9,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n44 = 10,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n48 = 11,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n52 = 12,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n56 = 13,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n60 = 14,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e_n64 = 15,
};

typedef enum SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e;

enum SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_two_e {
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_two_e_n4 = 0,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_two_e_n8 = 1,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_two_e_n12 = 2,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_two_e_n16 = 3,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_two_e_n20 = 4,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_two_e_n24 = 5,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_two_e_n28 = 6,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_two_e_n32 = 7,
};

typedef enum SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_two_e SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_two_e;

enum SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_Sel {
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_UNBOUND_VALUE = 0,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth = 1,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth = 2,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf = 3,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one = 4,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_two = 5,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_four = 6,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_eight = 7,
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_sixteen = 8,
};

union SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_Value {
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneEighth_e oneEighth;
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneFourth_e oneFourth;
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_oneHalf_e oneHalf;
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_one_e one;
	SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_two_e two;
	uint8_t four;
	uint8_t eight;
	uint8_t sixteen;
};

struct SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB {
	enum SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_Sel d;
	union SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_Value v;
};

enum SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e {
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_b56 = 0,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_b144 = 1,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_b208 = 2,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_b256 = 3,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_b282 = 4,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_b480 = 5,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_b640 = 6,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_b800 = 7,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_b1000 = 8,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_b72 = 9,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_spare6 = 10,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_spare5 = 11,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_spare4 = 12,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_spare3 = 13,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_spare2 = 14,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e_spare1 = 15,
};

typedef enum SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e;

enum SQN_NR_RACH_ConfigCommon_groupBconfigured_messagePowerOffsetGroupB_e {
	SQN_NR_RACH_ConfigCommon_groupBconfigured_messagePowerOffsetGroupB_e_minusinfinity = 0,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_messagePowerOffsetGroupB_e_dB0 = 1,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_messagePowerOffsetGroupB_e_dB5 = 2,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_messagePowerOffsetGroupB_e_dB8 = 3,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_messagePowerOffsetGroupB_e_dB10 = 4,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_messagePowerOffsetGroupB_e_dB12 = 5,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_messagePowerOffsetGroupB_e_dB15 = 6,
	SQN_NR_RACH_ConfigCommon_groupBconfigured_messagePowerOffsetGroupB_e_dB18 = 7,
};

typedef enum SQN_NR_RACH_ConfigCommon_groupBconfigured_messagePowerOffsetGroupB_e SQN_NR_RACH_ConfigCommon_groupBconfigured_messagePowerOffsetGroupB_e;

struct SQN_NR_RACH_ConfigCommon_groupBconfigured {
	SQN_NR_RACH_ConfigCommon_groupBconfigured_ra_Msg3SizeGroupA_e ra_Msg3SizeGroupA;
	SQN_NR_RACH_ConfigCommon_groupBconfigured_messagePowerOffsetGroupB_e messagePowerOffsetGroupB;
	uint8_t numberOfRA_PreamblesGroupA;
};

enum SQN_NR_RACH_ConfigCommon_ra_ContentionResolutionTimer_e {
	SQN_NR_RACH_ConfigCommon_ra_ContentionResolutionTimer_e_sf8 = 0,
	SQN_NR_RACH_ConfigCommon_ra_ContentionResolutionTimer_e_sf16 = 1,
	SQN_NR_RACH_ConfigCommon_ra_ContentionResolutionTimer_e_sf24 = 2,
	SQN_NR_RACH_ConfigCommon_ra_ContentionResolutionTimer_e_sf32 = 3,
	SQN_NR_RACH_ConfigCommon_ra_ContentionResolutionTimer_e_sf40 = 4,
	SQN_NR_RACH_ConfigCommon_ra_ContentionResolutionTimer_e_sf48 = 5,
	SQN_NR_RACH_ConfigCommon_ra_ContentionResolutionTimer_e_sf56 = 6,
	SQN_NR_RACH_ConfigCommon_ra_ContentionResolutionTimer_e_sf64 = 7,
};

typedef enum SQN_NR_RACH_ConfigCommon_ra_ContentionResolutionTimer_e SQN_NR_RACH_ConfigCommon_ra_ContentionResolutionTimer_e;

enum SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_Sel {
	SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_UNBOUND_VALUE = 0,
	SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_l839 = 1,
	SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_l139 = 2,
};

union SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_Value {
	uint16_t l839;
	uint8_t l139;
};

struct SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex {
	enum SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_Sel d;
	union SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_Value v;
};

enum SQN_NR_RACH_ConfigCommon_restrictedSetConfig_e {
	SQN_NR_RACH_ConfigCommon_restrictedSetConfig_e_unrestrictedSet = 0,
	SQN_NR_RACH_ConfigCommon_restrictedSetConfig_e_restrictedSetTypeA = 1,
	SQN_NR_RACH_ConfigCommon_restrictedSetConfig_e_restrictedSetTypeB = 2,
};

typedef enum SQN_NR_RACH_ConfigCommon_restrictedSetConfig_e SQN_NR_RACH_ConfigCommon_restrictedSetConfig_e;

enum SQN_NR_RACH_ConfigCommon_msg3_transformPrecoder_e {
	SQN_NR_RACH_ConfigCommon_msg3_transformPrecoder_e_enabled = 0,
};

typedef enum SQN_NR_RACH_ConfigCommon_msg3_transformPrecoder_e SQN_NR_RACH_ConfigCommon_msg3_transformPrecoder_e;

enum SQN_NR_RA_Prioritization_powerRampingStepHighPriority_e {
	SQN_NR_RA_Prioritization_powerRampingStepHighPriority_e_dB0 = 0,
	SQN_NR_RA_Prioritization_powerRampingStepHighPriority_e_dB2 = 1,
	SQN_NR_RA_Prioritization_powerRampingStepHighPriority_e_dB4 = 2,
	SQN_NR_RA_Prioritization_powerRampingStepHighPriority_e_dB6 = 3,
};

typedef enum SQN_NR_RA_Prioritization_powerRampingStepHighPriority_e SQN_NR_RA_Prioritization_powerRampingStepHighPriority_e;

enum SQN_NR_RA_Prioritization_scalingFactorBI_e {
	SQN_NR_RA_Prioritization_scalingFactorBI_e_zero = 0,
	SQN_NR_RA_Prioritization_scalingFactorBI_e_dot25 = 1,
	SQN_NR_RA_Prioritization_scalingFactorBI_e_dot5 = 2,
	SQN_NR_RA_Prioritization_scalingFactorBI_e_dot75 = 3,
};

typedef enum SQN_NR_RA_Prioritization_scalingFactorBI_e SQN_NR_RA_Prioritization_scalingFactorBI_e;

struct SQN_NR_RA_Prioritization_scalingFactorBI_e_scalingFactorBI_Optional {
	bool d;
	SQN_NR_RA_Prioritization_scalingFactorBI_e v;
};

struct SQN_NR_RA_Prioritization {
	SQN_NR_RA_Prioritization_powerRampingStepHighPriority_e powerRampingStepHighPriority;
	struct SQN_NR_RA_Prioritization_scalingFactorBI_e_scalingFactorBI_Optional scalingFactorBI;
};

struct SQN_NR_RACH_ConfigCommon_ra_PrioritizationForAccessIdentity_r16 {
	struct SQN_NR_RA_Prioritization ra_Prioritization_r16;
	B2 ra_PrioritizationForAI_r16;
};

enum SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_r16_Sel {
	SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_r16_UNBOUND_VALUE = 0,
	SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_r16_l571 = 1,
	SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_r16_l1151 = 2,
};

union SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_r16_Value {
	uint16_t l571;
	uint16_t l1151;
};

struct SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_r16 {
	enum SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_r16_Sel d;
	union SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_r16_Value v;
};

struct uint8_t_SQN_NR_RACH_ConfigCommon_totalNumberOfRA_Preambles_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_Optional {
	bool d;
	struct SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB v;
};

struct SQN_NR_RACH_ConfigCommon_groupBconfigured_groupBconfigured_Optional {
	bool d;
	struct SQN_NR_RACH_ConfigCommon_groupBconfigured v;
};

struct SQN_NR_RSRP_Range_SQN_NR_RACH_ConfigCommon_rsrp_ThresholdSSB_Optional {
	bool d;
	SQN_NR_RSRP_Range v;
};

struct SQN_NR_RSRP_Range_SQN_NR_RACH_ConfigCommon_rsrp_ThresholdSSB_SUL_Optional {
	bool d;
	SQN_NR_RSRP_Range v;
};

struct SQN_NR_SubcarrierSpacing_e_SQN_NR_RACH_ConfigCommon_msg1_SubcarrierSpacing_Optional {
	bool d;
	SQN_NR_SubcarrierSpacing_e v;
};

struct SQN_NR_RACH_ConfigCommon_msg3_transformPrecoder_e_msg3_transformPrecoder_Optional {
	bool d;
	SQN_NR_RACH_ConfigCommon_msg3_transformPrecoder_e v;
};

struct SQN_NR_RACH_ConfigCommon_ra_PrioritizationForAccessIdentity_r16_ra_PrioritizationForAccessIdentity_r16_Optional {
	bool d;
	struct SQN_NR_RACH_ConfigCommon_ra_PrioritizationForAccessIdentity_r16 v;
};

struct SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_r16_prach_RootSequenceIndex_r16_Optional {
	bool d;
	struct SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_r16 v;
};

struct SQN_NR_RACH_ConfigCommon {
	struct SQN_NR_RACH_ConfigGeneric rach_ConfigGeneric;
	struct uint8_t_SQN_NR_RACH_ConfigCommon_totalNumberOfRA_Preambles_Optional totalNumberOfRA_Preambles;
	struct SQN_NR_RACH_ConfigCommon_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_ssb_perRACH_OccasionAndCB_PreamblesPerSSB_Optional ssb_perRACH_OccasionAndCB_PreamblesPerSSB;
	struct SQN_NR_RACH_ConfigCommon_groupBconfigured_groupBconfigured_Optional groupBconfigured;
	SQN_NR_RACH_ConfigCommon_ra_ContentionResolutionTimer_e ra_ContentionResolutionTimer;
	struct SQN_NR_RSRP_Range_SQN_NR_RACH_ConfigCommon_rsrp_ThresholdSSB_Optional rsrp_ThresholdSSB;
	struct SQN_NR_RSRP_Range_SQN_NR_RACH_ConfigCommon_rsrp_ThresholdSSB_SUL_Optional rsrp_ThresholdSSB_SUL;
	struct SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex prach_RootSequenceIndex;
	struct SQN_NR_SubcarrierSpacing_e_SQN_NR_RACH_ConfigCommon_msg1_SubcarrierSpacing_Optional msg1_SubcarrierSpacing;
	SQN_NR_RACH_ConfigCommon_restrictedSetConfig_e restrictedSetConfig;
	struct SQN_NR_RACH_ConfigCommon_msg3_transformPrecoder_e_msg3_transformPrecoder_Optional msg3_transformPrecoder;
	struct SQN_NR_RACH_ConfigCommon_ra_PrioritizationForAccessIdentity_r16_ra_PrioritizationForAccessIdentity_r16_Optional ra_PrioritizationForAccessIdentity_r16;
	struct SQN_NR_RACH_ConfigCommon_prach_RootSequenceIndex_r16_prach_RootSequenceIndex_r16_Optional prach_RootSequenceIndex_r16;
};

enum SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommon_Sel {
	SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommon_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommon_release = 1,
	SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommon_setup = 2,
};

union SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommon_Value {
	Null release;
	struct SQN_NR_RACH_ConfigCommon setup;
};

struct SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommon {
	enum SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommon_Sel d;
	union SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommon_Value v;
};

enum SQN_NR_PUSCH_ConfigCommon_groupHoppingEnabledTransformPrecoding_e {
	SQN_NR_PUSCH_ConfigCommon_groupHoppingEnabledTransformPrecoding_e_enabled = 0,
};

typedef enum SQN_NR_PUSCH_ConfigCommon_groupHoppingEnabledTransformPrecoding_e SQN_NR_PUSCH_ConfigCommon_groupHoppingEnabledTransformPrecoding_e;

enum SQN_NR_PUSCH_TimeDomainResourceAllocation_mappingType_e {
	SQN_NR_PUSCH_TimeDomainResourceAllocation_mappingType_e_typeA = 0,
	SQN_NR_PUSCH_TimeDomainResourceAllocation_mappingType_e_typeB = 1,
};

typedef enum SQN_NR_PUSCH_TimeDomainResourceAllocation_mappingType_e SQN_NR_PUSCH_TimeDomainResourceAllocation_mappingType_e;

struct uint8_t_SQN_NR_PUSCH_TimeDomainResourceAllocation_k2_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PUSCH_TimeDomainResourceAllocation {
	struct uint8_t_SQN_NR_PUSCH_TimeDomainResourceAllocation_k2_Optional k2;
	SQN_NR_PUSCH_TimeDomainResourceAllocation_mappingType_e mappingType;
	uint8_t startSymbolAndLength;
};

struct SQN_NR_PUSCH_TimeDomainResourceAllocation_SQN_NR_PUSCH_TimeDomainResourceAllocationList_Dynamic {
	size_t d;
	struct SQN_NR_PUSCH_TimeDomainResourceAllocation* v;
};

typedef struct SQN_NR_PUSCH_TimeDomainResourceAllocation_SQN_NR_PUSCH_TimeDomainResourceAllocationList_Dynamic SQN_NR_PUSCH_TimeDomainResourceAllocationList;

struct SQN_NR_PUSCH_ConfigCommon_groupHoppingEnabledTransformPrecoding_e_groupHoppingEnabledTransformPrecoding_Optional {
	bool d;
	SQN_NR_PUSCH_ConfigCommon_groupHoppingEnabledTransformPrecoding_e v;
};

struct SQN_NR_PUSCH_TimeDomainResourceAllocationList_SQN_NR_PUSCH_ConfigCommon_pusch_TimeDomainAllocationList_Optional {
	bool d;
	SQN_NR_PUSCH_TimeDomainResourceAllocationList v;
};

struct int8_t_SQN_NR_PUSCH_ConfigCommon_msg3_DeltaPreamble_Optional {
	bool d;
	int8_t v;
};

struct int16_t_SQN_NR_PUSCH_ConfigCommon_p0_NominalWithGrant_Optional {
	bool d;
	int16_t v;
};

struct SQN_NR_PUSCH_ConfigCommon {
	struct SQN_NR_PUSCH_ConfigCommon_groupHoppingEnabledTransformPrecoding_e_groupHoppingEnabledTransformPrecoding_Optional groupHoppingEnabledTransformPrecoding;
	struct SQN_NR_PUSCH_TimeDomainResourceAllocationList_SQN_NR_PUSCH_ConfigCommon_pusch_TimeDomainAllocationList_Optional pusch_TimeDomainAllocationList;
	struct int8_t_SQN_NR_PUSCH_ConfigCommon_msg3_DeltaPreamble_Optional msg3_DeltaPreamble;
	struct int16_t_SQN_NR_PUSCH_ConfigCommon_p0_NominalWithGrant_Optional p0_NominalWithGrant;
};

enum SQN_NR_SetupRelease_BWP_UplinkCommon_pusch_ConfigCommon_Sel {
	SQN_NR_SetupRelease_BWP_UplinkCommon_pusch_ConfigCommon_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_UplinkCommon_pusch_ConfigCommon_release = 1,
	SQN_NR_SetupRelease_BWP_UplinkCommon_pusch_ConfigCommon_setup = 2,
};

union SQN_NR_SetupRelease_BWP_UplinkCommon_pusch_ConfigCommon_Value {
	Null release;
	struct SQN_NR_PUSCH_ConfigCommon setup;
};

struct SQN_NR_SetupRelease_BWP_UplinkCommon_pusch_ConfigCommon {
	enum SQN_NR_SetupRelease_BWP_UplinkCommon_pusch_ConfigCommon_Sel d;
	union SQN_NR_SetupRelease_BWP_UplinkCommon_pusch_ConfigCommon_Value v;
};

enum SQN_NR_PUCCH_ConfigCommon_pucch_GroupHopping_e {
	SQN_NR_PUCCH_ConfigCommon_pucch_GroupHopping_e_neither = 0,
	SQN_NR_PUCCH_ConfigCommon_pucch_GroupHopping_e_enable = 1,
	SQN_NR_PUCCH_ConfigCommon_pucch_GroupHopping_e_disable = 2,
};

typedef enum SQN_NR_PUCCH_ConfigCommon_pucch_GroupHopping_e SQN_NR_PUCCH_ConfigCommon_pucch_GroupHopping_e;

struct uint8_t_SQN_NR_PUCCH_ConfigCommon_pucch_ResourceCommon_Optional {
	bool d;
	uint8_t v;
};

struct uint16_t_SQN_NR_PUCCH_ConfigCommon_hoppingId_Optional {
	bool d;
	uint16_t v;
};

struct int16_t_SQN_NR_PUCCH_ConfigCommon_p0_nominal_Optional {
	bool d;
	int16_t v;
};

struct SQN_NR_PUCCH_ConfigCommon {
	struct uint8_t_SQN_NR_PUCCH_ConfigCommon_pucch_ResourceCommon_Optional pucch_ResourceCommon;
	SQN_NR_PUCCH_ConfigCommon_pucch_GroupHopping_e pucch_GroupHopping;
	struct uint16_t_SQN_NR_PUCCH_ConfigCommon_hoppingId_Optional hoppingId;
	struct int16_t_SQN_NR_PUCCH_ConfigCommon_p0_nominal_Optional p0_nominal;
};

enum SQN_NR_SetupRelease_BWP_UplinkCommon_pucch_ConfigCommon_Sel {
	SQN_NR_SetupRelease_BWP_UplinkCommon_pucch_ConfigCommon_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_UplinkCommon_pucch_ConfigCommon_release = 1,
	SQN_NR_SetupRelease_BWP_UplinkCommon_pucch_ConfigCommon_setup = 2,
};

union SQN_NR_SetupRelease_BWP_UplinkCommon_pucch_ConfigCommon_Value {
	Null release;
	struct SQN_NR_PUCCH_ConfigCommon setup;
};

struct SQN_NR_SetupRelease_BWP_UplinkCommon_pucch_ConfigCommon {
	enum SQN_NR_SetupRelease_BWP_UplinkCommon_pucch_ConfigCommon_Sel d;
	union SQN_NR_SetupRelease_BWP_UplinkCommon_pucch_ConfigCommon_Value v;
};

enum SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommonIAB_r16_Sel {
	SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommonIAB_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommonIAB_r16_release = 1,
	SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommonIAB_r16_setup = 2,
};

union SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommonIAB_r16_Value {
	Null release;
	struct SQN_NR_RACH_ConfigCommon setup;
};

struct SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommonIAB_r16 {
	enum SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommonIAB_r16_Sel d;
	union SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommonIAB_r16_Value v;
};

enum SQN_NR_BWP_UplinkCommon_useInterlacePUCCH_PUSCH_r16_e {
	SQN_NR_BWP_UplinkCommon_useInterlacePUCCH_PUSCH_r16_e_enabled = 0,
};

typedef enum SQN_NR_BWP_UplinkCommon_useInterlacePUCCH_PUSCH_r16_e SQN_NR_BWP_UplinkCommon_useInterlacePUCCH_PUSCH_r16_e;

enum SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_RO_FDM_r16_e {
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_RO_FDM_r16_e_one = 0,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_RO_FDM_r16_e_two = 1,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_RO_FDM_r16_e_four = 2,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_RO_FDM_r16_e_eight = 3,
};

typedef enum SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_RO_FDM_r16_e SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_RO_FDM_r16_e;

enum SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_PreamblePowerRampingStep_r16_e {
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_PreamblePowerRampingStep_r16_e_dB0 = 0,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_PreamblePowerRampingStep_r16_e_dB2 = 1,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_PreamblePowerRampingStep_r16_e_dB4 = 2,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_PreamblePowerRampingStep_r16_e_dB6 = 3,
};

typedef enum SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_PreamblePowerRampingStep_r16_e SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_PreamblePowerRampingStep_r16_e;

enum SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e {
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e_sl1 = 0,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e_sl2 = 1,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e_sl4 = 2,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e_sl8 = 3,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e_sl10 = 4,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e_sl20 = 5,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e_sl40 = 6,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e_sl80 = 7,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e_sl160 = 8,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e_sl320 = 9,
};

typedef enum SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e;

enum SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e {
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e_n3 = 0,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e_n4 = 1,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e_n5 = 2,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e_n6 = 3,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e_n7 = 4,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e_n8 = 5,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e_n10 = 6,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e_n20 = 7,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e_n50 = 8,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e_n100 = 9,
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e_n200 = 10,
};

typedef enum SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e;

struct uint16_t_SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_PRACH_ConfigurationIndex_r16_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_RO_FDM_r16_e_msgA_RO_FDM_r16_Optional {
	bool d;
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_RO_FDM_r16_e v;
};

struct uint16_t_SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_RO_FrequencyStart_r16_Optional {
	bool d;
	uint16_t v;
};

struct uint8_t_SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_ZeroCorrelationZoneConfig_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_PreamblePowerRampingStep_r16_e_msgA_PreamblePowerRampingStep_r16_Optional {
	bool d;
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_PreamblePowerRampingStep_r16_e v;
};

struct int16_t_SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_PreambleReceivedTargetPower_r16_Optional {
	bool d;
	int16_t v;
};

struct SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e_msgB_ResponseWindow_r16_Optional {
	bool d;
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e v;
};

struct SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e_preambleTransMax_r16_Optional {
	bool d;
	SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e v;
};

struct SQN_NR_RACH_ConfigGenericTwoStepRA_r16 {
	struct uint16_t_SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_PRACH_ConfigurationIndex_r16_Optional msgA_PRACH_ConfigurationIndex_r16;
	struct SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_RO_FDM_r16_e_msgA_RO_FDM_r16_Optional msgA_RO_FDM_r16;
	struct uint16_t_SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_RO_FrequencyStart_r16_Optional msgA_RO_FrequencyStart_r16;
	struct uint8_t_SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_ZeroCorrelationZoneConfig_r16_Optional msgA_ZeroCorrelationZoneConfig_r16;
	struct SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_PreamblePowerRampingStep_r16_e_msgA_PreamblePowerRampingStep_r16_Optional msgA_PreamblePowerRampingStep_r16;
	struct int16_t_SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgA_PreambleReceivedTargetPower_r16_Optional msgA_PreambleReceivedTargetPower_r16;
	struct SQN_NR_RACH_ConfigGenericTwoStepRA_r16_msgB_ResponseWindow_r16_e_msgB_ResponseWindow_r16_Optional msgB_ResponseWindow_r16;
	struct SQN_NR_RACH_ConfigGenericTwoStepRA_r16_preambleTransMax_r16_e_preambleTransMax_r16_Optional preambleTransMax_r16;
};

enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e {
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n4 = 0,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n8 = 1,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n12 = 2,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n16 = 3,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n20 = 4,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n24 = 5,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n28 = 6,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n32 = 7,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n36 = 8,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n40 = 9,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n44 = 10,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n48 = 11,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n52 = 12,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n56 = 13,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n60 = 14,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e_n64 = 15,
};

typedef enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e;

enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e {
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n4 = 0,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n8 = 1,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n12 = 2,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n16 = 3,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n20 = 4,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n24 = 5,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n28 = 6,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n32 = 7,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n36 = 8,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n40 = 9,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n44 = 10,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n48 = 11,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n52 = 12,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n56 = 13,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n60 = 14,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e_n64 = 15,
};

typedef enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e;

enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e {
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n4 = 0,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n8 = 1,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n12 = 2,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n16 = 3,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n20 = 4,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n24 = 5,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n28 = 6,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n32 = 7,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n36 = 8,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n40 = 9,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n44 = 10,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n48 = 11,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n52 = 12,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n56 = 13,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n60 = 14,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e_n64 = 15,
};

typedef enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e;

enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e {
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n4 = 0,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n8 = 1,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n12 = 2,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n16 = 3,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n20 = 4,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n24 = 5,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n28 = 6,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n32 = 7,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n36 = 8,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n40 = 9,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n44 = 10,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n48 = 11,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n52 = 12,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n56 = 13,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n60 = 14,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e_n64 = 15,
};

typedef enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e;

enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_two_e {
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_two_e_n4 = 0,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_two_e_n8 = 1,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_two_e_n12 = 2,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_two_e_n16 = 3,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_two_e_n20 = 4,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_two_e_n24 = 5,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_two_e_n28 = 6,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_two_e_n32 = 7,
};

typedef enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_two_e SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_two_e;

enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_Sel {
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_UNBOUND_VALUE = 0,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth = 1,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth = 2,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf = 3,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one = 4,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_two = 5,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_four = 6,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_eight = 7,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_sixteen = 8,
};

union SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_Value {
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneEighth_e oneEighth;
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneFourth_e oneFourth;
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_oneHalf_e oneHalf;
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_one_e one;
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_two_e two;
	uint8_t four;
	uint8_t eight;
	uint8_t sixteen;
};

struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16 {
	enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_Sel d;
	union SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_Value v;
};

enum SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e {
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_b56 = 0,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_b144 = 1,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_b208 = 2,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_b256 = 3,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_b282 = 4,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_b480 = 5,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_b640 = 6,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_b800 = 7,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_b1000 = 8,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_b72 = 9,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_spare6 = 10,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_spare5 = 11,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_spare4 = 12,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_spare3 = 13,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_spare2 = 14,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e_spare1 = 15,
};

typedef enum SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e;

enum SQN_NR_GroupB_ConfiguredTwoStepRA_r16_messagePowerOffsetGroupB_e {
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_messagePowerOffsetGroupB_e_minusinfinity = 0,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_messagePowerOffsetGroupB_e_dB0 = 1,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_messagePowerOffsetGroupB_e_dB5 = 2,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_messagePowerOffsetGroupB_e_dB8 = 3,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_messagePowerOffsetGroupB_e_dB10 = 4,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_messagePowerOffsetGroupB_e_dB12 = 5,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_messagePowerOffsetGroupB_e_dB15 = 6,
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_messagePowerOffsetGroupB_e_dB18 = 7,
};

typedef enum SQN_NR_GroupB_ConfiguredTwoStepRA_r16_messagePowerOffsetGroupB_e SQN_NR_GroupB_ConfiguredTwoStepRA_r16_messagePowerOffsetGroupB_e;

struct SQN_NR_GroupB_ConfiguredTwoStepRA_r16 {
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_ra_MsgA_SizeGroupA_e ra_MsgA_SizeGroupA;
	SQN_NR_GroupB_ConfiguredTwoStepRA_r16_messagePowerOffsetGroupB_e messagePowerOffsetGroupB;
	uint8_t numberofRA_PreamblesGroupA;
};

enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_PRACH_RootSequenceIndex_r16_Sel {
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_PRACH_RootSequenceIndex_r16_UNBOUND_VALUE = 0,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_PRACH_RootSequenceIndex_r16_l839 = 1,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_PRACH_RootSequenceIndex_r16_l139 = 2,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_PRACH_RootSequenceIndex_r16_l571 = 3,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_PRACH_RootSequenceIndex_r16_l1151 = 4,
};

union SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_PRACH_RootSequenceIndex_r16_Value {
	uint16_t l839;
	uint8_t l139;
	uint16_t l571;
	uint16_t l1151;
};

struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_PRACH_RootSequenceIndex_r16 {
	enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_PRACH_RootSequenceIndex_r16_Sel d;
	union SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_PRACH_RootSequenceIndex_r16_Value v;
};

enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e {
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e_n1 = 0,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e_n2 = 1,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e_n4 = 2,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e_n6 = 3,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e_n8 = 4,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e_n10 = 5,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e_n20 = 6,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e_n50 = 7,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e_n100 = 8,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e_n200 = 9,
};

typedef enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e;

enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_RestrictedSetConfig_r16_e {
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_RestrictedSetConfig_r16_e_unrestrictedSet = 0,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_RestrictedSetConfig_r16_e_restrictedSetTypeA = 1,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_RestrictedSetConfig_r16_e_restrictedSetTypeB = 2,
};

typedef enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_RestrictedSetConfig_r16_e SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_RestrictedSetConfig_r16_e;

struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_PrioritizationForAccessIdentityTwoStep_r16 {
	struct SQN_NR_RA_Prioritization ra_Prioritization_r16;
	B2 ra_PrioritizationForAI_r16;
};

enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_ContentionResolutionTimer_r16_e {
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_ContentionResolutionTimer_r16_e_sf8 = 0,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_ContentionResolutionTimer_r16_e_sf16 = 1,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_ContentionResolutionTimer_r16_e_sf24 = 2,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_ContentionResolutionTimer_r16_e_sf32 = 3,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_ContentionResolutionTimer_r16_e_sf40 = 4,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_ContentionResolutionTimer_r16_e_sf48 = 5,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_ContentionResolutionTimer_r16_e_sf56 = 6,
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_ContentionResolutionTimer_r16_e_sf64 = 7,
};

typedef enum SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_ContentionResolutionTimer_r16_e SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_ContentionResolutionTimer_r16_e;

struct uint8_t_SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TotalNumberOfRA_Preambles_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_Optional {
	bool d;
	struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16 v;
};

struct uint8_t_SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_CB_PreamblesPerSSB_PerSharedRO_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_SharedRO_MaskIndex_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_GroupB_ConfiguredTwoStepRA_r16_SQN_NR_RACH_ConfigCommonTwoStepRA_r16_groupB_ConfiguredTwoStepRA_r16_Optional {
	bool d;
	struct SQN_NR_GroupB_ConfiguredTwoStepRA_r16 v;
};

struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_PRACH_RootSequenceIndex_r16_msgA_PRACH_RootSequenceIndex_r16_Optional {
	bool d;
	struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_PRACH_RootSequenceIndex_r16 v;
};

struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e_msgA_TransMax_r16_Optional {
	bool d;
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e v;
};

struct SQN_NR_RSRP_Range_SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_RSRP_Threshold_r16_Optional {
	bool d;
	SQN_NR_RSRP_Range v;
};

struct SQN_NR_RSRP_Range_SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_RSRP_ThresholdSSB_r16_Optional {
	bool d;
	SQN_NR_RSRP_Range v;
};

struct SQN_NR_SubcarrierSpacing_e_SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SubcarrierSpacing_r16_Optional {
	bool d;
	SQN_NR_SubcarrierSpacing_e v;
};

struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_RestrictedSetConfig_r16_e_msgA_RestrictedSetConfig_r16_Optional {
	bool d;
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_RestrictedSetConfig_r16_e v;
};

struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_PrioritizationForAccessIdentityTwoStep_r16_ra_PrioritizationForAccessIdentityTwoStep_r16_Optional {
	bool d;
	struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_PrioritizationForAccessIdentityTwoStep_r16 v;
};

struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_ContentionResolutionTimer_r16_e_ra_ContentionResolutionTimer_r16_Optional {
	bool d;
	SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_ContentionResolutionTimer_r16_e v;
};

struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16 {
	struct SQN_NR_RACH_ConfigGenericTwoStepRA_r16 rach_ConfigGenericTwoStepRA_r16;
	struct uint8_t_SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TotalNumberOfRA_Preambles_r16_Optional msgA_TotalNumberOfRA_Preambles_r16;
	struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16_Optional msgA_SSB_PerRACH_OccasionAndCB_PreamblesPerSSB_r16;
	struct uint8_t_SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_CB_PreamblesPerSSB_PerSharedRO_r16_Optional msgA_CB_PreamblesPerSSB_PerSharedRO_r16;
	struct uint8_t_SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SSB_SharedRO_MaskIndex_r16_Optional msgA_SSB_SharedRO_MaskIndex_r16;
	struct SQN_NR_GroupB_ConfiguredTwoStepRA_r16_SQN_NR_RACH_ConfigCommonTwoStepRA_r16_groupB_ConfiguredTwoStepRA_r16_Optional groupB_ConfiguredTwoStepRA_r16;
	struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_PRACH_RootSequenceIndex_r16_msgA_PRACH_RootSequenceIndex_r16_Optional msgA_PRACH_RootSequenceIndex_r16;
	struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_TransMax_r16_e_msgA_TransMax_r16_Optional msgA_TransMax_r16;
	struct SQN_NR_RSRP_Range_SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_RSRP_Threshold_r16_Optional msgA_RSRP_Threshold_r16;
	struct SQN_NR_RSRP_Range_SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_RSRP_ThresholdSSB_r16_Optional msgA_RSRP_ThresholdSSB_r16;
	struct SQN_NR_SubcarrierSpacing_e_SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_SubcarrierSpacing_r16_Optional msgA_SubcarrierSpacing_r16;
	struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_msgA_RestrictedSetConfig_r16_e_msgA_RestrictedSetConfig_r16_Optional msgA_RestrictedSetConfig_r16;
	struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_PrioritizationForAccessIdentityTwoStep_r16_ra_PrioritizationForAccessIdentityTwoStep_r16_Optional ra_PrioritizationForAccessIdentityTwoStep_r16;
	struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16_ra_ContentionResolutionTimer_r16_e_ra_ContentionResolutionTimer_r16_Optional ra_ContentionResolutionTimer_r16;
};

enum SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_PerSlot_r16_e {
	SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_PerSlot_r16_e_one = 0,
	SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_PerSlot_r16_e_two = 1,
	SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_PerSlot_r16_e_three = 2,
	SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_PerSlot_r16_e_six = 3,
};

typedef enum SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_PerSlot_r16_e SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_PerSlot_r16_e;

enum SQN_NR_MsgA_PUSCH_Resource_r16_mappingTypeMsgA_PUSCH_r16_e {
	SQN_NR_MsgA_PUSCH_Resource_r16_mappingTypeMsgA_PUSCH_r16_e_typeA = 0,
	SQN_NR_MsgA_PUSCH_Resource_r16_mappingTypeMsgA_PUSCH_r16_e_typeB = 1,
};

typedef enum SQN_NR_MsgA_PUSCH_Resource_r16_mappingTypeMsgA_PUSCH_r16_e SQN_NR_MsgA_PUSCH_Resource_r16_mappingTypeMsgA_PUSCH_r16_e;

enum SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_FDM_r16_e {
	SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_FDM_r16_e_one = 0,
	SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_FDM_r16_e_two = 1,
	SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_FDM_r16_e_four = 2,
	SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_FDM_r16_e_eight = 3,
};

typedef enum SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_FDM_r16_e SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_FDM_r16_e;

enum SQN_NR_MsgA_PUSCH_Resource_r16_msgA_IntraSlotFrequencyHopping_r16_e {
	SQN_NR_MsgA_PUSCH_Resource_r16_msgA_IntraSlotFrequencyHopping_r16_e_enabled = 0,
};

typedef enum SQN_NR_MsgA_PUSCH_Resource_r16_msgA_IntraSlotFrequencyHopping_r16_e SQN_NR_MsgA_PUSCH_Resource_r16_msgA_IntraSlotFrequencyHopping_r16_e;

enum SQN_NR_MsgA_DMRS_Config_r16_msgA_DMRS_AdditionalPosition_r16_e {
	SQN_NR_MsgA_DMRS_Config_r16_msgA_DMRS_AdditionalPosition_r16_e_pos0 = 0,
	SQN_NR_MsgA_DMRS_Config_r16_msgA_DMRS_AdditionalPosition_r16_e_pos1 = 1,
	SQN_NR_MsgA_DMRS_Config_r16_msgA_DMRS_AdditionalPosition_r16_e_pos3 = 2,
};

typedef enum SQN_NR_MsgA_DMRS_Config_r16_msgA_DMRS_AdditionalPosition_r16_e SQN_NR_MsgA_DMRS_Config_r16_msgA_DMRS_AdditionalPosition_r16_e;

enum SQN_NR_MsgA_DMRS_Config_r16_msgA_MaxLength_r16_e {
	SQN_NR_MsgA_DMRS_Config_r16_msgA_MaxLength_r16_e_len2 = 0,
};

typedef enum SQN_NR_MsgA_DMRS_Config_r16_msgA_MaxLength_r16_e SQN_NR_MsgA_DMRS_Config_r16_msgA_MaxLength_r16_e;

struct SQN_NR_MsgA_DMRS_Config_r16_msgA_DMRS_AdditionalPosition_r16_e_msgA_DMRS_AdditionalPosition_r16_Optional {
	bool d;
	SQN_NR_MsgA_DMRS_Config_r16_msgA_DMRS_AdditionalPosition_r16_e v;
};

struct SQN_NR_MsgA_DMRS_Config_r16_msgA_MaxLength_r16_e_msgA_MaxLength_r16_Optional {
	bool d;
	SQN_NR_MsgA_DMRS_Config_r16_msgA_MaxLength_r16_e v;
};

struct uint8_t_SQN_NR_MsgA_DMRS_Config_r16_msgA_PUSCH_DMRS_CDM_Group_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_MsgA_DMRS_Config_r16_msgA_PUSCH_NrofPorts_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint16_t_SQN_NR_MsgA_DMRS_Config_r16_msgA_ScramblingID0_r16_Optional {
	bool d;
	uint16_t v;
};

struct uint16_t_SQN_NR_MsgA_DMRS_Config_r16_msgA_ScramblingID1_r16_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_MsgA_DMRS_Config_r16 {
	struct SQN_NR_MsgA_DMRS_Config_r16_msgA_DMRS_AdditionalPosition_r16_e_msgA_DMRS_AdditionalPosition_r16_Optional msgA_DMRS_AdditionalPosition_r16;
	struct SQN_NR_MsgA_DMRS_Config_r16_msgA_MaxLength_r16_e_msgA_MaxLength_r16_Optional msgA_MaxLength_r16;
	struct uint8_t_SQN_NR_MsgA_DMRS_Config_r16_msgA_PUSCH_DMRS_CDM_Group_r16_Optional msgA_PUSCH_DMRS_CDM_Group_r16;
	struct uint8_t_SQN_NR_MsgA_DMRS_Config_r16_msgA_PUSCH_NrofPorts_r16_Optional msgA_PUSCH_NrofPorts_r16;
	struct uint16_t_SQN_NR_MsgA_DMRS_Config_r16_msgA_ScramblingID0_r16_Optional msgA_ScramblingID0_r16;
	struct uint16_t_SQN_NR_MsgA_DMRS_Config_r16_msgA_ScramblingID1_r16_Optional msgA_ScramblingID1_r16;
};

enum SQN_NR_MsgA_PUSCH_Resource_r16_msgA_Alpha_r16_e {
	SQN_NR_MsgA_PUSCH_Resource_r16_msgA_Alpha_r16_e_alpha0 = 0,
	SQN_NR_MsgA_PUSCH_Resource_r16_msgA_Alpha_r16_e_alpha04 = 1,
	SQN_NR_MsgA_PUSCH_Resource_r16_msgA_Alpha_r16_e_alpha05 = 2,
	SQN_NR_MsgA_PUSCH_Resource_r16_msgA_Alpha_r16_e_alpha06 = 3,
	SQN_NR_MsgA_PUSCH_Resource_r16_msgA_Alpha_r16_e_alpha07 = 4,
	SQN_NR_MsgA_PUSCH_Resource_r16_msgA_Alpha_r16_e_alpha08 = 5,
	SQN_NR_MsgA_PUSCH_Resource_r16_msgA_Alpha_r16_e_alpha09 = 6,
	SQN_NR_MsgA_PUSCH_Resource_r16_msgA_Alpha_r16_e_alpha1 = 7,
};

typedef enum SQN_NR_MsgA_PUSCH_Resource_r16_msgA_Alpha_r16_e SQN_NR_MsgA_PUSCH_Resource_r16_msgA_Alpha_r16_e;

struct uint8_t_SQN_NR_MsgA_PUSCH_Resource_r16_msgA_PUSCH_TimeDomainAllocation_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_MsgA_PUSCH_Resource_r16_startSymbolAndLengthMsgA_PO_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_MsgA_PUSCH_Resource_r16_mappingTypeMsgA_PUSCH_r16_e_mappingTypeMsgA_PUSCH_r16_Optional {
	bool d;
	SQN_NR_MsgA_PUSCH_Resource_r16_mappingTypeMsgA_PUSCH_r16_e v;
};

struct uint8_t_SQN_NR_MsgA_PUSCH_Resource_r16_guardPeriodMsgA_PUSCH_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_MsgA_PUSCH_Resource_r16_msgA_IntraSlotFrequencyHopping_r16_e_msgA_IntraSlotFrequencyHopping_r16_Optional {
	bool d;
	SQN_NR_MsgA_PUSCH_Resource_r16_msgA_IntraSlotFrequencyHopping_r16_e v;
};

struct B2_SQN_NR_MsgA_PUSCH_Resource_r16_msgA_HoppingBits_r16_Optional {
	bool d;
	B2 v;
};

struct SQN_NR_MsgA_PUSCH_Resource_r16_msgA_Alpha_r16_e_msgA_Alpha_r16_Optional {
	bool d;
	SQN_NR_MsgA_PUSCH_Resource_r16_msgA_Alpha_r16_e v;
};

struct uint8_t_SQN_NR_MsgA_PUSCH_Resource_r16_interlaceIndexFirstPO_MsgA_PUSCH_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_MsgA_PUSCH_Resource_r16_nrofInterlacesPerMsgA_PO_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_MsgA_PUSCH_Resource_r16 {
	uint8_t msgA_MCS_r16;
	uint8_t nrofSlotsMsgA_PUSCH_r16;
	SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_PerSlot_r16_e nrofMsgA_PO_PerSlot_r16;
	uint8_t msgA_PUSCH_TimeDomainOffset_r16;
	struct uint8_t_SQN_NR_MsgA_PUSCH_Resource_r16_msgA_PUSCH_TimeDomainAllocation_r16_Optional msgA_PUSCH_TimeDomainAllocation_r16;
	struct uint8_t_SQN_NR_MsgA_PUSCH_Resource_r16_startSymbolAndLengthMsgA_PO_r16_Optional startSymbolAndLengthMsgA_PO_r16;
	struct SQN_NR_MsgA_PUSCH_Resource_r16_mappingTypeMsgA_PUSCH_r16_e_mappingTypeMsgA_PUSCH_r16_Optional mappingTypeMsgA_PUSCH_r16;
	struct uint8_t_SQN_NR_MsgA_PUSCH_Resource_r16_guardPeriodMsgA_PUSCH_r16_Optional guardPeriodMsgA_PUSCH_r16;
	uint8_t guardBandMsgA_PUSCH_r16;
	uint16_t frequencyStartMsgA_PUSCH_r16;
	uint8_t nrofPRBs_PerMsgA_PO_r16;
	SQN_NR_MsgA_PUSCH_Resource_r16_nrofMsgA_PO_FDM_r16_e nrofMsgA_PO_FDM_r16;
	struct SQN_NR_MsgA_PUSCH_Resource_r16_msgA_IntraSlotFrequencyHopping_r16_e_msgA_IntraSlotFrequencyHopping_r16_Optional msgA_IntraSlotFrequencyHopping_r16;
	struct B2_SQN_NR_MsgA_PUSCH_Resource_r16_msgA_HoppingBits_r16_Optional msgA_HoppingBits_r16;
	struct SQN_NR_MsgA_DMRS_Config_r16 msgA_DMRS_Config_r16;
	uint8_t nrofDMRS_Sequences_r16;
	struct SQN_NR_MsgA_PUSCH_Resource_r16_msgA_Alpha_r16_e_msgA_Alpha_r16_Optional msgA_Alpha_r16;
	struct uint8_t_SQN_NR_MsgA_PUSCH_Resource_r16_interlaceIndexFirstPO_MsgA_PUSCH_r16_Optional interlaceIndexFirstPO_MsgA_PUSCH_r16;
	struct uint8_t_SQN_NR_MsgA_PUSCH_Resource_r16_nrofInterlacesPerMsgA_PO_r16_Optional nrofInterlacesPerMsgA_PO_r16;
};

enum SQN_NR_MsgA_PUSCH_Config_r16_msgA_TransformPrecoder_r16_e {
	SQN_NR_MsgA_PUSCH_Config_r16_msgA_TransformPrecoder_r16_e_enabled = 0,
	SQN_NR_MsgA_PUSCH_Config_r16_msgA_TransformPrecoder_r16_e_disabled = 1,
};

typedef enum SQN_NR_MsgA_PUSCH_Config_r16_msgA_TransformPrecoder_r16_e SQN_NR_MsgA_PUSCH_Config_r16_msgA_TransformPrecoder_r16_e;

struct SQN_NR_MsgA_PUSCH_Resource_r16_SQN_NR_MsgA_PUSCH_Config_r16_msgA_PUSCH_ResourceGroupA_r16_Optional {
	bool d;
	struct SQN_NR_MsgA_PUSCH_Resource_r16 v;
};

struct SQN_NR_MsgA_PUSCH_Resource_r16_SQN_NR_MsgA_PUSCH_Config_r16_msgA_PUSCH_ResourceGroupB_r16_Optional {
	bool d;
	struct SQN_NR_MsgA_PUSCH_Resource_r16 v;
};

struct SQN_NR_MsgA_PUSCH_Config_r16_msgA_TransformPrecoder_r16_e_msgA_TransformPrecoder_r16_Optional {
	bool d;
	SQN_NR_MsgA_PUSCH_Config_r16_msgA_TransformPrecoder_r16_e v;
};

struct uint16_t_SQN_NR_MsgA_PUSCH_Config_r16_msgA_DataScramblingIndex_r16_Optional {
	bool d;
	uint16_t v;
};

struct int8_t_SQN_NR_MsgA_PUSCH_Config_r16_msgA_DeltaPreamble_r16_Optional {
	bool d;
	int8_t v;
};

struct SQN_NR_MsgA_PUSCH_Config_r16 {
	struct SQN_NR_MsgA_PUSCH_Resource_r16_SQN_NR_MsgA_PUSCH_Config_r16_msgA_PUSCH_ResourceGroupA_r16_Optional msgA_PUSCH_ResourceGroupA_r16;
	struct SQN_NR_MsgA_PUSCH_Resource_r16_SQN_NR_MsgA_PUSCH_Config_r16_msgA_PUSCH_ResourceGroupB_r16_Optional msgA_PUSCH_ResourceGroupB_r16;
	struct SQN_NR_MsgA_PUSCH_Config_r16_msgA_TransformPrecoder_r16_e_msgA_TransformPrecoder_r16_Optional msgA_TransformPrecoder_r16;
	struct uint16_t_SQN_NR_MsgA_PUSCH_Config_r16_msgA_DataScramblingIndex_r16_Optional msgA_DataScramblingIndex_r16;
	struct int8_t_SQN_NR_MsgA_PUSCH_Config_r16_msgA_DeltaPreamble_r16_Optional msgA_DeltaPreamble_r16;
};

struct SQN_NR_MsgA_PUSCH_Config_r16_SQN_NR_MsgA_ConfigCommon_r16_msgA_PUSCH_Config_r16_Optional {
	bool d;
	struct SQN_NR_MsgA_PUSCH_Config_r16 v;
};

struct SQN_NR_MsgA_ConfigCommon_r16 {
	struct SQN_NR_RACH_ConfigCommonTwoStepRA_r16 rach_ConfigCommonTwoStepRA_r16;
	struct SQN_NR_MsgA_PUSCH_Config_r16_SQN_NR_MsgA_ConfigCommon_r16_msgA_PUSCH_Config_r16_Optional msgA_PUSCH_Config_r16;
};

enum SQN_NR_SetupRelease_BWP_UplinkCommon_msgA_ConfigCommon_r16_Sel {
	SQN_NR_SetupRelease_BWP_UplinkCommon_msgA_ConfigCommon_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_UplinkCommon_msgA_ConfigCommon_r16_release = 1,
	SQN_NR_SetupRelease_BWP_UplinkCommon_msgA_ConfigCommon_r16_setup = 2,
};

union SQN_NR_SetupRelease_BWP_UplinkCommon_msgA_ConfigCommon_r16_Value {
	Null release;
	struct SQN_NR_MsgA_ConfigCommon_r16 setup;
};

struct SQN_NR_SetupRelease_BWP_UplinkCommon_msgA_ConfigCommon_r16 {
	enum SQN_NR_SetupRelease_BWP_UplinkCommon_msgA_ConfigCommon_r16_Sel d;
	union SQN_NR_SetupRelease_BWP_UplinkCommon_msgA_ConfigCommon_r16_Value v;
};

struct SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommon_SQN_NR_BWP_UplinkCommon_rach_ConfigCommon_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommon v;
};

struct SQN_NR_SetupRelease_BWP_UplinkCommon_pusch_ConfigCommon_SQN_NR_BWP_UplinkCommon_pusch_ConfigCommon_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_UplinkCommon_pusch_ConfigCommon v;
};

struct SQN_NR_SetupRelease_BWP_UplinkCommon_pucch_ConfigCommon_SQN_NR_BWP_UplinkCommon_pucch_ConfigCommon_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_UplinkCommon_pucch_ConfigCommon v;
};

struct SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommonIAB_r16_SQN_NR_BWP_UplinkCommon_rach_ConfigCommonIAB_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommonIAB_r16 v;
};

struct SQN_NR_BWP_UplinkCommon_useInterlacePUCCH_PUSCH_r16_e_useInterlacePUCCH_PUSCH_r16_Optional {
	bool d;
	SQN_NR_BWP_UplinkCommon_useInterlacePUCCH_PUSCH_r16_e v;
};

struct SQN_NR_SetupRelease_BWP_UplinkCommon_msgA_ConfigCommon_r16_SQN_NR_BWP_UplinkCommon_msgA_ConfigCommon_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_UplinkCommon_msgA_ConfigCommon_r16 v;
};

struct SQN_NR_BWP_UplinkCommon {
	struct SQN_NR_BWP genericParameters;
	struct SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommon_SQN_NR_BWP_UplinkCommon_rach_ConfigCommon_Optional rach_ConfigCommon;
	struct SQN_NR_SetupRelease_BWP_UplinkCommon_pusch_ConfigCommon_SQN_NR_BWP_UplinkCommon_pusch_ConfigCommon_Optional pusch_ConfigCommon;
	struct SQN_NR_SetupRelease_BWP_UplinkCommon_pucch_ConfigCommon_SQN_NR_BWP_UplinkCommon_pucch_ConfigCommon_Optional pucch_ConfigCommon;
	struct SQN_NR_SetupRelease_BWP_UplinkCommon_rach_ConfigCommonIAB_r16_SQN_NR_BWP_UplinkCommon_rach_ConfigCommonIAB_r16_Optional rach_ConfigCommonIAB_r16;
	struct SQN_NR_BWP_UplinkCommon_useInterlacePUCCH_PUSCH_r16_e_useInterlacePUCCH_PUSCH_r16_Optional useInterlacePUCCH_PUSCH_r16;
	struct SQN_NR_SetupRelease_BWP_UplinkCommon_msgA_ConfigCommon_r16_SQN_NR_BWP_UplinkCommon_msgA_ConfigCommon_r16_Optional msgA_ConfigCommon_r16;
};

enum SQN_NR_TimeAlignmentTimer_e {
	SQN_NR_TimeAlignmentTimer_e_ms500 = 0,
	SQN_NR_TimeAlignmentTimer_e_ms750 = 1,
	SQN_NR_TimeAlignmentTimer_e_ms1280 = 2,
	SQN_NR_TimeAlignmentTimer_e_ms1920 = 3,
	SQN_NR_TimeAlignmentTimer_e_ms2560 = 4,
	SQN_NR_TimeAlignmentTimer_e_ms5120 = 5,
	SQN_NR_TimeAlignmentTimer_e_ms10240 = 6,
	SQN_NR_TimeAlignmentTimer_e_infinity = 7,
};

typedef enum SQN_NR_TimeAlignmentTimer_e SQN_NR_TimeAlignmentTimer_e;

struct SQN_NR_UplinkConfigCommonSIB {
	struct SQN_NR_FrequencyInfoUL_SIB frequencyInfoUL;
	struct SQN_NR_BWP_UplinkCommon initialUplinkBWP;
	SQN_NR_TimeAlignmentTimer_e timeAlignmentTimerCommon;
};

enum SQN_NR_ServingCellConfigCommonSIB_n_TimingAdvanceOffset_e {
	SQN_NR_ServingCellConfigCommonSIB_n_TimingAdvanceOffset_e_n0 = 0,
	SQN_NR_ServingCellConfigCommonSIB_n_TimingAdvanceOffset_e_n25600 = 1,
	SQN_NR_ServingCellConfigCommonSIB_n_TimingAdvanceOffset_e_n39936 = 2,
};

typedef enum SQN_NR_ServingCellConfigCommonSIB_n_TimingAdvanceOffset_e SQN_NR_ServingCellConfigCommonSIB_n_TimingAdvanceOffset_e;

struct B8_SQN_NR_ServingCellConfigCommonSIB_ssb_PositionsInBurst_groupPresence_Optional {
	bool d;
	B8 v;
};

struct SQN_NR_ServingCellConfigCommonSIB_ssb_PositionsInBurst {
	B8 inOneGroup;
	struct B8_SQN_NR_ServingCellConfigCommonSIB_ssb_PositionsInBurst_groupPresence_Optional groupPresence;
};

enum SQN_NR_ServingCellConfigCommonSIB_ssb_PeriodicityServingCell_e {
	SQN_NR_ServingCellConfigCommonSIB_ssb_PeriodicityServingCell_e_ms5 = 0,
	SQN_NR_ServingCellConfigCommonSIB_ssb_PeriodicityServingCell_e_ms10 = 1,
	SQN_NR_ServingCellConfigCommonSIB_ssb_PeriodicityServingCell_e_ms20 = 2,
	SQN_NR_ServingCellConfigCommonSIB_ssb_PeriodicityServingCell_e_ms40 = 3,
	SQN_NR_ServingCellConfigCommonSIB_ssb_PeriodicityServingCell_e_ms80 = 4,
	SQN_NR_ServingCellConfigCommonSIB_ssb_PeriodicityServingCell_e_ms160 = 5,
};

typedef enum SQN_NR_ServingCellConfigCommonSIB_ssb_PeriodicityServingCell_e SQN_NR_ServingCellConfigCommonSIB_ssb_PeriodicityServingCell_e;

enum SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_e {
	SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_e_ms0p5 = 0,
	SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_e_ms0p625 = 1,
	SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_e_ms1 = 2,
	SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_e_ms1p25 = 3,
	SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_e_ms2 = 4,
	SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_e_ms2p5 = 5,
	SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_e_ms5 = 6,
	SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_e_ms10 = 7,
};

typedef enum SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_e SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_e;

enum SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_v1530_e {
	SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_v1530_e_ms3 = 0,
	SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_v1530_e_ms4 = 1,
};

typedef enum SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_v1530_e SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_v1530_e;

struct SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_v1530_e_dl_UL_TransmissionPeriodicity_v1530_Optional {
	bool d;
	SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_v1530_e v;
};

struct SQN_NR_TDD_UL_DL_Pattern {
	SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_e dl_UL_TransmissionPeriodicity;
	uint16_t nrofDownlinkSlots;
	uint8_t nrofDownlinkSymbols;
	uint16_t nrofUplinkSlots;
	uint8_t nrofUplinkSymbols;
	struct SQN_NR_TDD_UL_DL_Pattern_dl_UL_TransmissionPeriodicity_v1530_e_dl_UL_TransmissionPeriodicity_v1530_Optional dl_UL_TransmissionPeriodicity_v1530;
};

struct SQN_NR_TDD_UL_DL_Pattern_SQN_NR_TDD_UL_DL_ConfigCommon_pattern2_Optional {
	bool d;
	struct SQN_NR_TDD_UL_DL_Pattern v;
};

struct SQN_NR_TDD_UL_DL_ConfigCommon {
	SQN_NR_SubcarrierSpacing_e referenceSubcarrierSpacing;
	struct SQN_NR_TDD_UL_DL_Pattern pattern1;
	struct SQN_NR_TDD_UL_DL_Pattern_SQN_NR_TDD_UL_DL_ConfigCommon_pattern2_Optional pattern2;
};

enum SQN_NR_SemiStaticChannelAccessConfig_period_e {
	SQN_NR_SemiStaticChannelAccessConfig_period_e_ms1 = 0,
	SQN_NR_SemiStaticChannelAccessConfig_period_e_ms2 = 1,
	SQN_NR_SemiStaticChannelAccessConfig_period_e_ms2dot5 = 2,
	SQN_NR_SemiStaticChannelAccessConfig_period_e_ms4 = 3,
	SQN_NR_SemiStaticChannelAccessConfig_period_e_ms5 = 4,
	SQN_NR_SemiStaticChannelAccessConfig_period_e_ms10 = 5,
};

typedef enum SQN_NR_SemiStaticChannelAccessConfig_period_e SQN_NR_SemiStaticChannelAccessConfig_period_e;

struct SQN_NR_SemiStaticChannelAccessConfig {
	SQN_NR_SemiStaticChannelAccessConfig_period_e period;
};

enum SQN_NR_ServingCellConfigCommonSIB_channelAccessMode_r16_Sel {
	SQN_NR_ServingCellConfigCommonSIB_channelAccessMode_r16_UNBOUND_VALUE = 0,
	SQN_NR_ServingCellConfigCommonSIB_channelAccessMode_r16_dynamic = 1,
	SQN_NR_ServingCellConfigCommonSIB_channelAccessMode_r16_semiStatic = 2,
};

union SQN_NR_ServingCellConfigCommonSIB_channelAccessMode_r16_Value {
	Null dynamic;
	struct SQN_NR_SemiStaticChannelAccessConfig semiStatic;
};

struct SQN_NR_ServingCellConfigCommonSIB_channelAccessMode_r16 {
	enum SQN_NR_ServingCellConfigCommonSIB_channelAccessMode_r16_Sel d;
	union SQN_NR_ServingCellConfigCommonSIB_channelAccessMode_r16_Value v;
};

enum SQN_NR_ServingCellConfigCommonSIB_discoveryBurstWindowLength_r16_e {
	SQN_NR_ServingCellConfigCommonSIB_discoveryBurstWindowLength_r16_e_ms0dot5 = 0,
	SQN_NR_ServingCellConfigCommonSIB_discoveryBurstWindowLength_r16_e_ms1 = 1,
	SQN_NR_ServingCellConfigCommonSIB_discoveryBurstWindowLength_r16_e_ms2 = 2,
	SQN_NR_ServingCellConfigCommonSIB_discoveryBurstWindowLength_r16_e_ms3 = 3,
	SQN_NR_ServingCellConfigCommonSIB_discoveryBurstWindowLength_r16_e_ms4 = 4,
	SQN_NR_ServingCellConfigCommonSIB_discoveryBurstWindowLength_r16_e_ms5 = 5,
};

typedef enum SQN_NR_ServingCellConfigCommonSIB_discoveryBurstWindowLength_r16_e SQN_NR_ServingCellConfigCommonSIB_discoveryBurstWindowLength_r16_e;

enum SQN_NR_HighSpeedConfig_r16_highSpeedMeasFlag_r16_e {
	SQN_NR_HighSpeedConfig_r16_highSpeedMeasFlag_r16_e_true = 0,
};

typedef enum SQN_NR_HighSpeedConfig_r16_highSpeedMeasFlag_r16_e SQN_NR_HighSpeedConfig_r16_highSpeedMeasFlag_r16_e;

enum SQN_NR_HighSpeedConfig_r16_highSpeedDemodFlag_r16_e {
	SQN_NR_HighSpeedConfig_r16_highSpeedDemodFlag_r16_e_true = 0,
};

typedef enum SQN_NR_HighSpeedConfig_r16_highSpeedDemodFlag_r16_e SQN_NR_HighSpeedConfig_r16_highSpeedDemodFlag_r16_e;

struct SQN_NR_HighSpeedConfig_r16_highSpeedMeasFlag_r16_e_highSpeedMeasFlag_r16_Optional {
	bool d;
	SQN_NR_HighSpeedConfig_r16_highSpeedMeasFlag_r16_e v;
};

struct SQN_NR_HighSpeedConfig_r16_highSpeedDemodFlag_r16_e_highSpeedDemodFlag_r16_Optional {
	bool d;
	SQN_NR_HighSpeedConfig_r16_highSpeedDemodFlag_r16_e v;
};

struct SQN_NR_HighSpeedConfig_r16 {
	struct SQN_NR_HighSpeedConfig_r16_highSpeedMeasFlag_r16_e_highSpeedMeasFlag_r16_Optional highSpeedMeasFlag_r16;
	struct SQN_NR_HighSpeedConfig_r16_highSpeedDemodFlag_r16_e_highSpeedDemodFlag_r16_Optional highSpeedDemodFlag_r16;
};

struct SQN_NR_UplinkConfigCommonSIB_SQN_NR_ServingCellConfigCommonSIB_uplinkConfigCommon_Optional {
	bool d;
	struct SQN_NR_UplinkConfigCommonSIB v;
};

struct SQN_NR_UplinkConfigCommonSIB_SQN_NR_ServingCellConfigCommonSIB_supplementaryUplink_Optional {
	bool d;
	struct SQN_NR_UplinkConfigCommonSIB v;
};

struct SQN_NR_ServingCellConfigCommonSIB_n_TimingAdvanceOffset_e_n_TimingAdvanceOffset_Optional {
	bool d;
	SQN_NR_ServingCellConfigCommonSIB_n_TimingAdvanceOffset_e v;
};

struct SQN_NR_TDD_UL_DL_ConfigCommon_SQN_NR_ServingCellConfigCommonSIB_tdd_UL_DL_ConfigurationCommon_Optional {
	bool d;
	struct SQN_NR_TDD_UL_DL_ConfigCommon v;
};

struct SQN_NR_ServingCellConfigCommonSIB_channelAccessMode_r16_channelAccessMode_r16_Optional {
	bool d;
	struct SQN_NR_ServingCellConfigCommonSIB_channelAccessMode_r16 v;
};

struct SQN_NR_ServingCellConfigCommonSIB_discoveryBurstWindowLength_r16_e_discoveryBurstWindowLength_r16_Optional {
	bool d;
	SQN_NR_ServingCellConfigCommonSIB_discoveryBurstWindowLength_r16_e v;
};

struct SQN_NR_HighSpeedConfig_r16_SQN_NR_ServingCellConfigCommonSIB_highSpeedConfig_r16_Optional {
	bool d;
	struct SQN_NR_HighSpeedConfig_r16 v;
};

struct SQN_NR_ServingCellConfigCommonSIB {
	struct SQN_NR_DownlinkConfigCommonSIB downlinkConfigCommon;
	struct SQN_NR_UplinkConfigCommonSIB_SQN_NR_ServingCellConfigCommonSIB_uplinkConfigCommon_Optional uplinkConfigCommon;
	struct SQN_NR_UplinkConfigCommonSIB_SQN_NR_ServingCellConfigCommonSIB_supplementaryUplink_Optional supplementaryUplink;
	struct SQN_NR_ServingCellConfigCommonSIB_n_TimingAdvanceOffset_e_n_TimingAdvanceOffset_Optional n_TimingAdvanceOffset;
	struct SQN_NR_ServingCellConfigCommonSIB_ssb_PositionsInBurst ssb_PositionsInBurst;
	SQN_NR_ServingCellConfigCommonSIB_ssb_PeriodicityServingCell_e ssb_PeriodicityServingCell;
	struct SQN_NR_TDD_UL_DL_ConfigCommon_SQN_NR_ServingCellConfigCommonSIB_tdd_UL_DL_ConfigurationCommon_Optional tdd_UL_DL_ConfigurationCommon;
	int8_t ss_PBCH_BlockPower;
	struct SQN_NR_ServingCellConfigCommonSIB_channelAccessMode_r16_channelAccessMode_r16_Optional channelAccessMode_r16;
	struct SQN_NR_ServingCellConfigCommonSIB_discoveryBurstWindowLength_r16_e_discoveryBurstWindowLength_r16_Optional discoveryBurstWindowLength_r16;
	struct SQN_NR_HighSpeedConfig_r16_SQN_NR_ServingCellConfigCommonSIB_highSpeedConfig_r16_Optional highSpeedConfig_r16;
};

enum SQN_NR_SIB1_ims_EmergencySupport_e {
	SQN_NR_SIB1_ims_EmergencySupport_e_true = 0,
};

typedef enum SQN_NR_SIB1_ims_EmergencySupport_e SQN_NR_SIB1_ims_EmergencySupport_e;

enum SQN_NR_SIB1_eCallOverIMS_Support_e {
	SQN_NR_SIB1_eCallOverIMS_Support_e_true = 0,
};

typedef enum SQN_NR_SIB1_eCallOverIMS_Support_e SQN_NR_SIB1_eCallOverIMS_Support_e;

enum SQN_NR_UE_TimersAndConstants_t300_e {
	SQN_NR_UE_TimersAndConstants_t300_e_ms100 = 0,
	SQN_NR_UE_TimersAndConstants_t300_e_ms200 = 1,
	SQN_NR_UE_TimersAndConstants_t300_e_ms300 = 2,
	SQN_NR_UE_TimersAndConstants_t300_e_ms400 = 3,
	SQN_NR_UE_TimersAndConstants_t300_e_ms600 = 4,
	SQN_NR_UE_TimersAndConstants_t300_e_ms1000 = 5,
	SQN_NR_UE_TimersAndConstants_t300_e_ms1500 = 6,
	SQN_NR_UE_TimersAndConstants_t300_e_ms2000 = 7,
};

typedef enum SQN_NR_UE_TimersAndConstants_t300_e SQN_NR_UE_TimersAndConstants_t300_e;

enum SQN_NR_UE_TimersAndConstants_t301_e {
	SQN_NR_UE_TimersAndConstants_t301_e_ms100 = 0,
	SQN_NR_UE_TimersAndConstants_t301_e_ms200 = 1,
	SQN_NR_UE_TimersAndConstants_t301_e_ms300 = 2,
	SQN_NR_UE_TimersAndConstants_t301_e_ms400 = 3,
	SQN_NR_UE_TimersAndConstants_t301_e_ms600 = 4,
	SQN_NR_UE_TimersAndConstants_t301_e_ms1000 = 5,
	SQN_NR_UE_TimersAndConstants_t301_e_ms1500 = 6,
	SQN_NR_UE_TimersAndConstants_t301_e_ms2000 = 7,
};

typedef enum SQN_NR_UE_TimersAndConstants_t301_e SQN_NR_UE_TimersAndConstants_t301_e;

enum SQN_NR_UE_TimersAndConstants_t310_e {
	SQN_NR_UE_TimersAndConstants_t310_e_ms0 = 0,
	SQN_NR_UE_TimersAndConstants_t310_e_ms50 = 1,
	SQN_NR_UE_TimersAndConstants_t310_e_ms100 = 2,
	SQN_NR_UE_TimersAndConstants_t310_e_ms200 = 3,
	SQN_NR_UE_TimersAndConstants_t310_e_ms500 = 4,
	SQN_NR_UE_TimersAndConstants_t310_e_ms1000 = 5,
	SQN_NR_UE_TimersAndConstants_t310_e_ms2000 = 6,
};

typedef enum SQN_NR_UE_TimersAndConstants_t310_e SQN_NR_UE_TimersAndConstants_t310_e;

enum SQN_NR_UE_TimersAndConstants_n310_e {
	SQN_NR_UE_TimersAndConstants_n310_e_n1 = 0,
	SQN_NR_UE_TimersAndConstants_n310_e_n2 = 1,
	SQN_NR_UE_TimersAndConstants_n310_e_n3 = 2,
	SQN_NR_UE_TimersAndConstants_n310_e_n4 = 3,
	SQN_NR_UE_TimersAndConstants_n310_e_n6 = 4,
	SQN_NR_UE_TimersAndConstants_n310_e_n8 = 5,
	SQN_NR_UE_TimersAndConstants_n310_e_n10 = 6,
	SQN_NR_UE_TimersAndConstants_n310_e_n20 = 7,
};

typedef enum SQN_NR_UE_TimersAndConstants_n310_e SQN_NR_UE_TimersAndConstants_n310_e;

enum SQN_NR_UE_TimersAndConstants_t311_e {
	SQN_NR_UE_TimersAndConstants_t311_e_ms1000 = 0,
	SQN_NR_UE_TimersAndConstants_t311_e_ms3000 = 1,
	SQN_NR_UE_TimersAndConstants_t311_e_ms5000 = 2,
	SQN_NR_UE_TimersAndConstants_t311_e_ms10000 = 3,
	SQN_NR_UE_TimersAndConstants_t311_e_ms15000 = 4,
	SQN_NR_UE_TimersAndConstants_t311_e_ms20000 = 5,
	SQN_NR_UE_TimersAndConstants_t311_e_ms30000 = 6,
};

typedef enum SQN_NR_UE_TimersAndConstants_t311_e SQN_NR_UE_TimersAndConstants_t311_e;

enum SQN_NR_UE_TimersAndConstants_n311_e {
	SQN_NR_UE_TimersAndConstants_n311_e_n1 = 0,
	SQN_NR_UE_TimersAndConstants_n311_e_n2 = 1,
	SQN_NR_UE_TimersAndConstants_n311_e_n3 = 2,
	SQN_NR_UE_TimersAndConstants_n311_e_n4 = 3,
	SQN_NR_UE_TimersAndConstants_n311_e_n5 = 4,
	SQN_NR_UE_TimersAndConstants_n311_e_n6 = 5,
	SQN_NR_UE_TimersAndConstants_n311_e_n8 = 6,
	SQN_NR_UE_TimersAndConstants_n311_e_n10 = 7,
};

typedef enum SQN_NR_UE_TimersAndConstants_n311_e SQN_NR_UE_TimersAndConstants_n311_e;

enum SQN_NR_UE_TimersAndConstants_t319_e {
	SQN_NR_UE_TimersAndConstants_t319_e_ms100 = 0,
	SQN_NR_UE_TimersAndConstants_t319_e_ms200 = 1,
	SQN_NR_UE_TimersAndConstants_t319_e_ms300 = 2,
	SQN_NR_UE_TimersAndConstants_t319_e_ms400 = 3,
	SQN_NR_UE_TimersAndConstants_t319_e_ms600 = 4,
	SQN_NR_UE_TimersAndConstants_t319_e_ms1000 = 5,
	SQN_NR_UE_TimersAndConstants_t319_e_ms1500 = 6,
	SQN_NR_UE_TimersAndConstants_t319_e_ms2000 = 7,
};

typedef enum SQN_NR_UE_TimersAndConstants_t319_e SQN_NR_UE_TimersAndConstants_t319_e;

struct SQN_NR_UE_TimersAndConstants {
	SQN_NR_UE_TimersAndConstants_t300_e t300;
	SQN_NR_UE_TimersAndConstants_t301_e t301;
	SQN_NR_UE_TimersAndConstants_t310_e t310;
	SQN_NR_UE_TimersAndConstants_n310_e n310;
	SQN_NR_UE_TimersAndConstants_t311_e t311;
	SQN_NR_UE_TimersAndConstants_n311_e n311;
	SQN_NR_UE_TimersAndConstants_t319_e t319;
};

typedef uint8_t SQN_NR_UAC_BarringInfoSetIndex;

struct SQN_NR_UAC_BarringPerCat {
	uint8_t accessCategory;
	SQN_NR_UAC_BarringInfoSetIndex uac_barringInfoSetIndex;
};

struct SQN_NR_UAC_BarringPerCat_SQN_NR_UAC_BarringPerCatList_Dynamic {
	size_t d;
	struct SQN_NR_UAC_BarringPerCat* v;
};

typedef struct SQN_NR_UAC_BarringPerCat_SQN_NR_UAC_BarringPerCatList_Dynamic SQN_NR_UAC_BarringPerCatList;

enum SQN_NR_UAC_BarringPerPLMN_uac_ACBarringListType_Sel {
	SQN_NR_UAC_BarringPerPLMN_uac_ACBarringListType_UNBOUND_VALUE = 0,
	SQN_NR_UAC_BarringPerPLMN_uac_ACBarringListType_uac_ImplicitACBarringList = 1,
	SQN_NR_UAC_BarringPerPLMN_uac_ACBarringListType_uac_ExplicitACBarringList = 2,
};

union SQN_NR_UAC_BarringPerPLMN_uac_ACBarringListType_Value {
	SQN_NR_UAC_BarringInfoSetIndex uac_ImplicitACBarringList[63];
	SQN_NR_UAC_BarringPerCatList uac_ExplicitACBarringList;
};

struct SQN_NR_UAC_BarringPerPLMN_uac_ACBarringListType {
	enum SQN_NR_UAC_BarringPerPLMN_uac_ACBarringListType_Sel d;
	union SQN_NR_UAC_BarringPerPLMN_uac_ACBarringListType_Value v;
};

struct SQN_NR_UAC_BarringPerPLMN_uac_ACBarringListType_uac_ACBarringListType_Optional {
	bool d;
	struct SQN_NR_UAC_BarringPerPLMN_uac_ACBarringListType v;
};

struct SQN_NR_UAC_BarringPerPLMN {
	uint8_t plmn_IdentityIndex;
	struct SQN_NR_UAC_BarringPerPLMN_uac_ACBarringListType_uac_ACBarringListType_Optional uac_ACBarringListType;
};

struct SQN_NR_UAC_BarringPerPLMN_SQN_NR_UAC_BarringPerPLMN_List_Dynamic {
	size_t d;
	struct SQN_NR_UAC_BarringPerPLMN* v;
};

typedef struct SQN_NR_UAC_BarringPerPLMN_SQN_NR_UAC_BarringPerPLMN_List_Dynamic SQN_NR_UAC_BarringPerPLMN_List;

enum SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e {
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p00 = 0,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p05 = 1,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p10 = 2,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p15 = 3,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p20 = 4,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p25 = 5,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p30 = 6,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p40 = 7,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p50 = 8,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p60 = 9,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p70 = 10,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p75 = 11,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p80 = 12,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p85 = 13,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p90 = 14,
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e_p95 = 15,
};

typedef enum SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e;

enum SQN_NR_UAC_BarringInfoSet_uac_BarringTime_e {
	SQN_NR_UAC_BarringInfoSet_uac_BarringTime_e_s4 = 0,
	SQN_NR_UAC_BarringInfoSet_uac_BarringTime_e_s8 = 1,
	SQN_NR_UAC_BarringInfoSet_uac_BarringTime_e_s16 = 2,
	SQN_NR_UAC_BarringInfoSet_uac_BarringTime_e_s32 = 3,
	SQN_NR_UAC_BarringInfoSet_uac_BarringTime_e_s64 = 4,
	SQN_NR_UAC_BarringInfoSet_uac_BarringTime_e_s128 = 5,
	SQN_NR_UAC_BarringInfoSet_uac_BarringTime_e_s256 = 6,
	SQN_NR_UAC_BarringInfoSet_uac_BarringTime_e_s512 = 7,
};

typedef enum SQN_NR_UAC_BarringInfoSet_uac_BarringTime_e SQN_NR_UAC_BarringInfoSet_uac_BarringTime_e;

struct SQN_NR_UAC_BarringInfoSet {
	SQN_NR_UAC_BarringInfoSet_uac_BarringFactor_e uac_BarringFactor;
	SQN_NR_UAC_BarringInfoSet_uac_BarringTime_e uac_BarringTime;
	B7 uac_BarringForAccessIdentity;
};

struct SQN_NR_UAC_BarringInfoSet_SQN_NR_UAC_BarringInfoSetList_Dynamic {
	size_t d;
	struct SQN_NR_UAC_BarringInfoSet* v;
};

typedef struct SQN_NR_UAC_BarringInfoSet_SQN_NR_UAC_BarringInfoSetList_Dynamic SQN_NR_UAC_BarringInfoSetList;

enum SQN_NR_UAC_AccessCategory1_SelectionAssistanceInfo_e {
	SQN_NR_UAC_AccessCategory1_SelectionAssistanceInfo_e_a = 0,
	SQN_NR_UAC_AccessCategory1_SelectionAssistanceInfo_e_b = 1,
	SQN_NR_UAC_AccessCategory1_SelectionAssistanceInfo_e_c = 2,
};

typedef enum SQN_NR_UAC_AccessCategory1_SelectionAssistanceInfo_e SQN_NR_UAC_AccessCategory1_SelectionAssistanceInfo_e;

enum SQN_NR_SIB1_uac_BarringInfo_uac_AccessCategory1_SelectionAssistanceInfo_Sel {
	SQN_NR_SIB1_uac_BarringInfo_uac_AccessCategory1_SelectionAssistanceInfo_UNBOUND_VALUE = 0,
	SQN_NR_SIB1_uac_BarringInfo_uac_AccessCategory1_SelectionAssistanceInfo_plmnCommon = 1,
	SQN_NR_SIB1_uac_BarringInfo_uac_AccessCategory1_SelectionAssistanceInfo_individualPLMNList = 2,
};

struct SQN_NR_UAC_AccessCategory1_SelectionAssistanceInfo_e_individualPLMNList_Dynamic {
	size_t d;
	SQN_NR_UAC_AccessCategory1_SelectionAssistanceInfo_e* v;
};

union SQN_NR_SIB1_uac_BarringInfo_uac_AccessCategory1_SelectionAssistanceInfo_Value {
	SQN_NR_UAC_AccessCategory1_SelectionAssistanceInfo_e plmnCommon;
	struct SQN_NR_UAC_AccessCategory1_SelectionAssistanceInfo_e_individualPLMNList_Dynamic individualPLMNList;
};

struct SQN_NR_SIB1_uac_BarringInfo_uac_AccessCategory1_SelectionAssistanceInfo {
	enum SQN_NR_SIB1_uac_BarringInfo_uac_AccessCategory1_SelectionAssistanceInfo_Sel d;
	union SQN_NR_SIB1_uac_BarringInfo_uac_AccessCategory1_SelectionAssistanceInfo_Value v;
};

struct SQN_NR_UAC_BarringPerCatList_SQN_NR_SIB1_uac_BarringInfo_uac_BarringForCommon_Optional {
	bool d;
	SQN_NR_UAC_BarringPerCatList v;
};

struct SQN_NR_UAC_BarringPerPLMN_List_SQN_NR_SIB1_uac_BarringInfo_uac_BarringPerPLMN_List_Optional {
	bool d;
	SQN_NR_UAC_BarringPerPLMN_List v;
};

struct SQN_NR_SIB1_uac_BarringInfo_uac_AccessCategory1_SelectionAssistanceInfo_uac_AccessCategory1_SelectionAssistanceInfo_Optional {
	bool d;
	struct SQN_NR_SIB1_uac_BarringInfo_uac_AccessCategory1_SelectionAssistanceInfo v;
};

struct SQN_NR_SIB1_uac_BarringInfo {
	struct SQN_NR_UAC_BarringPerCatList_SQN_NR_SIB1_uac_BarringInfo_uac_BarringForCommon_Optional uac_BarringForCommon;
	struct SQN_NR_UAC_BarringPerPLMN_List_SQN_NR_SIB1_uac_BarringInfo_uac_BarringPerPLMN_List_Optional uac_BarringPerPLMN_List;
	SQN_NR_UAC_BarringInfoSetList uac_BarringInfoSetList;
	struct SQN_NR_SIB1_uac_BarringInfo_uac_AccessCategory1_SelectionAssistanceInfo_uac_AccessCategory1_SelectionAssistanceInfo_Optional uac_AccessCategory1_SelectionAssistanceInfo;
};

enum SQN_NR_SIB1_useFullResumeID_e {
	SQN_NR_SIB1_useFullResumeID_e_true = 0,
};

typedef enum SQN_NR_SIB1_useFullResumeID_e SQN_NR_SIB1_useFullResumeID_e;

enum SQN_NR_SIB1_v1610_IEs_idleModeMeasurementsEUTRA_r16_e {
	SQN_NR_SIB1_v1610_IEs_idleModeMeasurementsEUTRA_r16_e_true = 0,
};

typedef enum SQN_NR_SIB1_v1610_IEs_idleModeMeasurementsEUTRA_r16_e SQN_NR_SIB1_v1610_IEs_idleModeMeasurementsEUTRA_r16_e;

enum SQN_NR_SIB1_v1610_IEs_idleModeMeasurementsNR_r16_e {
	SQN_NR_SIB1_v1610_IEs_idleModeMeasurementsNR_r16_e_true = 0,
};

typedef enum SQN_NR_SIB1_v1610_IEs_idleModeMeasurementsNR_r16_e SQN_NR_SIB1_v1610_IEs_idleModeMeasurementsNR_r16_e;

enum SQN_NR_PosSchedulingInfo_r16_offsetToSI_Used_r16_e {
	SQN_NR_PosSchedulingInfo_r16_offsetToSI_Used_r16_e_true = 0,
};

typedef enum SQN_NR_PosSchedulingInfo_r16_offsetToSI_Used_r16_e SQN_NR_PosSchedulingInfo_r16_offsetToSI_Used_r16_e;

enum SQN_NR_PosSchedulingInfo_r16_posSI_Periodicity_r16_e {
	SQN_NR_PosSchedulingInfo_r16_posSI_Periodicity_r16_e_rf8 = 0,
	SQN_NR_PosSchedulingInfo_r16_posSI_Periodicity_r16_e_rf16 = 1,
	SQN_NR_PosSchedulingInfo_r16_posSI_Periodicity_r16_e_rf32 = 2,
	SQN_NR_PosSchedulingInfo_r16_posSI_Periodicity_r16_e_rf64 = 3,
	SQN_NR_PosSchedulingInfo_r16_posSI_Periodicity_r16_e_rf128 = 4,
	SQN_NR_PosSchedulingInfo_r16_posSI_Periodicity_r16_e_rf256 = 5,
	SQN_NR_PosSchedulingInfo_r16_posSI_Periodicity_r16_e_rf512 = 6,
};

typedef enum SQN_NR_PosSchedulingInfo_r16_posSI_Periodicity_r16_e SQN_NR_PosSchedulingInfo_r16_posSI_Periodicity_r16_e;

enum SQN_NR_PosSchedulingInfo_r16_posSI_BroadcastStatus_r16_e {
	SQN_NR_PosSchedulingInfo_r16_posSI_BroadcastStatus_r16_e_broadcasting = 0,
	SQN_NR_PosSchedulingInfo_r16_posSI_BroadcastStatus_r16_e_notBroadcasting = 1,
};

typedef enum SQN_NR_PosSchedulingInfo_r16_posSI_BroadcastStatus_r16_e SQN_NR_PosSchedulingInfo_r16_posSI_BroadcastStatus_r16_e;

enum SQN_NR_PosSIB_Type_r16_encrypted_r16_e {
	SQN_NR_PosSIB_Type_r16_encrypted_r16_e_true = 0,
};

typedef enum SQN_NR_PosSIB_Type_r16_encrypted_r16_e SQN_NR_PosSIB_Type_r16_encrypted_r16_e;

enum SQN_NR_GNSS_ID_r16_gnss_id_r16_e {
	SQN_NR_GNSS_ID_r16_gnss_id_r16_e_gps = 0,
	SQN_NR_GNSS_ID_r16_gnss_id_r16_e_sbas = 1,
	SQN_NR_GNSS_ID_r16_gnss_id_r16_e_qzss = 2,
	SQN_NR_GNSS_ID_r16_gnss_id_r16_e_galileo = 3,
	SQN_NR_GNSS_ID_r16_gnss_id_r16_e_glonass = 4,
	SQN_NR_GNSS_ID_r16_gnss_id_r16_e_bds = 5,
};

typedef enum SQN_NR_GNSS_ID_r16_gnss_id_r16_e SQN_NR_GNSS_ID_r16_gnss_id_r16_e;

struct SQN_NR_GNSS_ID_r16 {
	SQN_NR_GNSS_ID_r16_gnss_id_r16_e gnss_id_r16;
};

enum SQN_NR_SBAS_ID_r16_sbas_id_r16_e {
	SQN_NR_SBAS_ID_r16_sbas_id_r16_e_waas = 0,
	SQN_NR_SBAS_ID_r16_sbas_id_r16_e_egnos = 1,
	SQN_NR_SBAS_ID_r16_sbas_id_r16_e_msas = 2,
	SQN_NR_SBAS_ID_r16_sbas_id_r16_e_gagan = 3,
};

typedef enum SQN_NR_SBAS_ID_r16_sbas_id_r16_e SQN_NR_SBAS_ID_r16_sbas_id_r16_e;

struct SQN_NR_SBAS_ID_r16 {
	SQN_NR_SBAS_ID_r16_sbas_id_r16_e sbas_id_r16;
};

enum SQN_NR_PosSIB_Type_r16_posSibType_r16_e {
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType1_1 = 0,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType1_2 = 1,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType1_3 = 2,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType1_4 = 3,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType1_5 = 4,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType1_6 = 5,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType1_7 = 6,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType1_8 = 7,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_1 = 8,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_2 = 9,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_3 = 10,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_4 = 11,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_5 = 12,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_6 = 13,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_7 = 14,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_8 = 15,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_9 = 16,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_10 = 17,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_11 = 18,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_12 = 19,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_13 = 20,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_14 = 21,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_15 = 22,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_16 = 23,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_17 = 24,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_18 = 25,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_19 = 26,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_20 = 27,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_21 = 28,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_22 = 29,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType2_23 = 30,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType3_1 = 31,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType4_1 = 32,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType5_1 = 33,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType6_1 = 34,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType6_2 = 35,
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e_posSibType6_3 = 36,
};

typedef enum SQN_NR_PosSIB_Type_r16_posSibType_r16_e SQN_NR_PosSIB_Type_r16_posSibType_r16_e;

enum SQN_NR_PosSIB_Type_r16_areaScope_r16_e {
	SQN_NR_PosSIB_Type_r16_areaScope_r16_e_true = 0,
};

typedef enum SQN_NR_PosSIB_Type_r16_areaScope_r16_e SQN_NR_PosSIB_Type_r16_areaScope_r16_e;

struct SQN_NR_PosSIB_Type_r16_encrypted_r16_e_encrypted_r16_Optional {
	bool d;
	SQN_NR_PosSIB_Type_r16_encrypted_r16_e v;
};

struct SQN_NR_GNSS_ID_r16_SQN_NR_PosSIB_Type_r16_gnss_id_r16_Optional {
	bool d;
	struct SQN_NR_GNSS_ID_r16 v;
};

struct SQN_NR_SBAS_ID_r16_SQN_NR_PosSIB_Type_r16_sbas_id_r16_Optional {
	bool d;
	struct SQN_NR_SBAS_ID_r16 v;
};

struct SQN_NR_PosSIB_Type_r16_areaScope_r16_e_areaScope_r16_Optional {
	bool d;
	SQN_NR_PosSIB_Type_r16_areaScope_r16_e v;
};

struct SQN_NR_PosSIB_Type_r16 {
	struct SQN_NR_PosSIB_Type_r16_encrypted_r16_e_encrypted_r16_Optional encrypted_r16;
	struct SQN_NR_GNSS_ID_r16_SQN_NR_PosSIB_Type_r16_gnss_id_r16_Optional gnss_id_r16;
	struct SQN_NR_SBAS_ID_r16_SQN_NR_PosSIB_Type_r16_sbas_id_r16_Optional sbas_id_r16;
	SQN_NR_PosSIB_Type_r16_posSibType_r16_e posSibType_r16;
	struct SQN_NR_PosSIB_Type_r16_areaScope_r16_e_areaScope_r16_Optional areaScope_r16;
};

struct SQN_NR_PosSIB_Type_r16_SQN_NR_PosSIB_MappingInfo_r16_Dynamic {
	size_t d;
	struct SQN_NR_PosSIB_Type_r16* v;
};

typedef struct SQN_NR_PosSIB_Type_r16_SQN_NR_PosSIB_MappingInfo_r16_Dynamic SQN_NR_PosSIB_MappingInfo_r16;

struct SQN_NR_PosSchedulingInfo_r16_offsetToSI_Used_r16_e_offsetToSI_Used_r16_Optional {
	bool d;
	SQN_NR_PosSchedulingInfo_r16_offsetToSI_Used_r16_e v;
};

struct SQN_NR_PosSchedulingInfo_r16 {
	struct SQN_NR_PosSchedulingInfo_r16_offsetToSI_Used_r16_e_offsetToSI_Used_r16_Optional offsetToSI_Used_r16;
	SQN_NR_PosSchedulingInfo_r16_posSI_Periodicity_r16_e posSI_Periodicity_r16;
	SQN_NR_PosSchedulingInfo_r16_posSI_BroadcastStatus_r16_e posSI_BroadcastStatus_r16;
	SQN_NR_PosSIB_MappingInfo_r16 posSIB_MappingInfo_r16;
};

struct SQN_NR_PosSchedulingInfo_r16_SQN_NR_PosSI_SchedulingInfo_r16_posSchedulingInfoList_r16_Dynamic {
	size_t d;
	struct SQN_NR_PosSchedulingInfo_r16* v;
};

struct SQN_NR_SI_RequestConfig_SQN_NR_PosSI_SchedulingInfo_r16_posSI_RequestConfig_r16_Optional {
	bool d;
	struct SQN_NR_SI_RequestConfig v;
};

struct SQN_NR_SI_RequestConfig_SQN_NR_PosSI_SchedulingInfo_r16_posSI_RequestConfigSUL_r16_Optional {
	bool d;
	struct SQN_NR_SI_RequestConfig v;
};

struct SQN_NR_PosSI_SchedulingInfo_r16 {
	struct SQN_NR_PosSchedulingInfo_r16_SQN_NR_PosSI_SchedulingInfo_r16_posSchedulingInfoList_r16_Dynamic posSchedulingInfoList_r16;
	struct SQN_NR_SI_RequestConfig_SQN_NR_PosSI_SchedulingInfo_r16_posSI_RequestConfig_r16_Optional posSI_RequestConfig_r16;
	struct SQN_NR_SI_RequestConfig_SQN_NR_PosSI_SchedulingInfo_r16_posSI_RequestConfigSUL_r16_Optional posSI_RequestConfigSUL_r16;
};

struct SQN_NR_SIB1_v1610_IEs_nonCriticalExtension {
};

struct SQN_NR_SIB1_v1610_IEs_idleModeMeasurementsEUTRA_r16_e_idleModeMeasurementsEUTRA_r16_Optional {
	bool d;
	SQN_NR_SIB1_v1610_IEs_idleModeMeasurementsEUTRA_r16_e v;
};

struct SQN_NR_SIB1_v1610_IEs_idleModeMeasurementsNR_r16_e_idleModeMeasurementsNR_r16_Optional {
	bool d;
	SQN_NR_SIB1_v1610_IEs_idleModeMeasurementsNR_r16_e v;
};

struct SQN_NR_PosSI_SchedulingInfo_r16_SQN_NR_SIB1_v1610_IEs_posSI_SchedulingInfo_r16_Optional {
	bool d;
	struct SQN_NR_PosSI_SchedulingInfo_r16 v;
};

struct SQN_NR_SIB1_v1610_IEs_nonCriticalExtension_nonCriticalExtension_Optional {
	bool d;
	struct SQN_NR_SIB1_v1610_IEs_nonCriticalExtension v;
};

struct SQN_NR_SIB1_v1610_IEs {
	struct SQN_NR_SIB1_v1610_IEs_idleModeMeasurementsEUTRA_r16_e_idleModeMeasurementsEUTRA_r16_Optional idleModeMeasurementsEUTRA_r16;
	struct SQN_NR_SIB1_v1610_IEs_idleModeMeasurementsNR_r16_e_idleModeMeasurementsNR_r16_Optional idleModeMeasurementsNR_r16;
	struct SQN_NR_PosSI_SchedulingInfo_r16_SQN_NR_SIB1_v1610_IEs_posSI_SchedulingInfo_r16_Optional posSI_SchedulingInfo_r16;
	struct SQN_NR_SIB1_v1610_IEs_nonCriticalExtension_nonCriticalExtension_Optional nonCriticalExtension;
};

struct SQN_NR_SIB1_cellSelectionInfo_cellSelectionInfo_Optional {
	bool d;
	struct SQN_NR_SIB1_cellSelectionInfo v;
};

struct SQN_NR_ConnEstFailureControl_SQN_NR_SIB1_connEstFailureControl_Optional {
	bool d;
	struct SQN_NR_ConnEstFailureControl v;
};

struct SQN_NR_SI_SchedulingInfo_SQN_NR_SIB1_si_SchedulingInfo_Optional {
	bool d;
	struct SQN_NR_SI_SchedulingInfo v;
};

struct SQN_NR_ServingCellConfigCommonSIB_SQN_NR_SIB1_servingCellConfigCommon_Optional {
	bool d;
	struct SQN_NR_ServingCellConfigCommonSIB v;
};

struct SQN_NR_SIB1_ims_EmergencySupport_e_ims_EmergencySupport_Optional {
	bool d;
	SQN_NR_SIB1_ims_EmergencySupport_e v;
};

struct SQN_NR_SIB1_eCallOverIMS_Support_e_eCallOverIMS_Support_Optional {
	bool d;
	SQN_NR_SIB1_eCallOverIMS_Support_e v;
};

struct SQN_NR_UE_TimersAndConstants_SQN_NR_SIB1_ue_TimersAndConstants_Optional {
	bool d;
	struct SQN_NR_UE_TimersAndConstants v;
};

struct SQN_NR_SIB1_uac_BarringInfo_uac_BarringInfo_Optional {
	bool d;
	struct SQN_NR_SIB1_uac_BarringInfo v;
};

struct SQN_NR_SIB1_useFullResumeID_e_useFullResumeID_Optional {
	bool d;
	SQN_NR_SIB1_useFullResumeID_e v;
};

struct OCTET_STRING_SQN_NR_SIB1_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_SIB1_v1610_IEs_SQN_NR_SIB1_nonCriticalExtension_Optional {
	bool d;
	struct SQN_NR_SIB1_v1610_IEs v;
};

struct SQN_NR_SIB1 {
	struct SQN_NR_SIB1_cellSelectionInfo_cellSelectionInfo_Optional cellSelectionInfo;
	struct SQN_NR_CellAccessRelatedInfo cellAccessRelatedInfo;
	struct SQN_NR_ConnEstFailureControl_SQN_NR_SIB1_connEstFailureControl_Optional connEstFailureControl;
	struct SQN_NR_SI_SchedulingInfo_SQN_NR_SIB1_si_SchedulingInfo_Optional si_SchedulingInfo;
	struct SQN_NR_ServingCellConfigCommonSIB_SQN_NR_SIB1_servingCellConfigCommon_Optional servingCellConfigCommon;
	struct SQN_NR_SIB1_ims_EmergencySupport_e_ims_EmergencySupport_Optional ims_EmergencySupport;
	struct SQN_NR_SIB1_eCallOverIMS_Support_e_eCallOverIMS_Support_Optional eCallOverIMS_Support;
	struct SQN_NR_UE_TimersAndConstants_SQN_NR_SIB1_ue_TimersAndConstants_Optional ue_TimersAndConstants;
	struct SQN_NR_SIB1_uac_BarringInfo_uac_BarringInfo_Optional uac_BarringInfo;
	struct SQN_NR_SIB1_useFullResumeID_e_useFullResumeID_Optional useFullResumeID;
	struct OCTET_STRING_SQN_NR_SIB1_lateNonCriticalExtension_Optional lateNonCriticalExtension;
	struct SQN_NR_SIB1_v1610_IEs_SQN_NR_SIB1_nonCriticalExtension_Optional nonCriticalExtension;
};

enum SQN_NR_BCCH_DL_SCH_MessageType_c1_Sel {
	SQN_NR_BCCH_DL_SCH_MessageType_c1_UNBOUND_VALUE = 0,
	SQN_NR_BCCH_DL_SCH_MessageType_c1_systemInformation = 1,
	SQN_NR_BCCH_DL_SCH_MessageType_c1_systemInformationBlockType1 = 2,
};

union SQN_NR_BCCH_DL_SCH_MessageType_c1_Value {
	struct SQN_NR_SystemInformation systemInformation;
	struct SQN_NR_SIB1 systemInformationBlockType1;
};

struct SQN_NR_BCCH_DL_SCH_MessageType_c1 {
	enum SQN_NR_BCCH_DL_SCH_MessageType_c1_Sel d;
	union SQN_NR_BCCH_DL_SCH_MessageType_c1_Value v;
};

struct SQN_NR_BCCH_DL_SCH_MessageType_messageClassExtension {
};

enum SQN_NR_BCCH_DL_SCH_MessageType_Sel {
	SQN_NR_BCCH_DL_SCH_MessageType_UNBOUND_VALUE = 0,
	SQN_NR_BCCH_DL_SCH_MessageType_c1 = 1,
	SQN_NR_BCCH_DL_SCH_MessageType_messageClassExtension = 2,
};

union SQN_NR_BCCH_DL_SCH_MessageType_Value {
	struct SQN_NR_BCCH_DL_SCH_MessageType_c1 c1;
	struct SQN_NR_BCCH_DL_SCH_MessageType_messageClassExtension messageClassExtension;
};

struct SQN_NR_BCCH_DL_SCH_MessageType {
	enum SQN_NR_BCCH_DL_SCH_MessageType_Sel d;
	union SQN_NR_BCCH_DL_SCH_MessageType_Value v;
};

struct SQN_NR_BCCH_DL_SCH_Message {
	struct SQN_NR_BCCH_DL_SCH_MessageType message;
};

typedef uint8_t SQN_NR_BWP_Id;

typedef uint8_t SQN_NR_PUCCH_ResourceSetId;

typedef uint8_t SQN_NR_PUCCH_ResourceId;

struct SQN_NR_PUCCH_ResourceId_resourceList_Dynamic {
	size_t d;
	SQN_NR_PUCCH_ResourceId* v;
};

struct uint16_t_SQN_NR_PUCCH_ResourceSet_maxPayloadSize_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_PUCCH_ResourceSet {
	SQN_NR_PUCCH_ResourceSetId pucch_ResourceSetId;
	struct SQN_NR_PUCCH_ResourceId_resourceList_Dynamic resourceList;
	struct uint16_t_SQN_NR_PUCCH_ResourceSet_maxPayloadSize_Optional maxPayloadSize;
};

typedef uint16_t SQN_NR_PRB_Id;

enum SQN_NR_PUCCH_Resource_intraSlotFrequencyHopping_e {
	SQN_NR_PUCCH_Resource_intraSlotFrequencyHopping_e_enabled = 0,
};

typedef enum SQN_NR_PUCCH_Resource_intraSlotFrequencyHopping_e SQN_NR_PUCCH_Resource_intraSlotFrequencyHopping_e;

struct SQN_NR_PUCCH_format0 {
	uint8_t initialCyclicShift;
	uint8_t nrofSymbols;
	uint8_t startingSymbolIndex;
};

struct SQN_NR_PUCCH_format1 {
	uint8_t initialCyclicShift;
	uint8_t nrofSymbols;
	uint8_t startingSymbolIndex;
	uint8_t timeDomainOCC;
};

struct SQN_NR_PUCCH_format2 {
	uint8_t nrofPRBs;
	uint8_t nrofSymbols;
	uint8_t startingSymbolIndex;
};

struct SQN_NR_PUCCH_format3 {
	uint8_t nrofPRBs;
	uint8_t nrofSymbols;
	uint8_t startingSymbolIndex;
};

enum SQN_NR_PUCCH_format4_occ_Length_e {
	SQN_NR_PUCCH_format4_occ_Length_e_n2 = 0,
	SQN_NR_PUCCH_format4_occ_Length_e_n4 = 1,
};

typedef enum SQN_NR_PUCCH_format4_occ_Length_e SQN_NR_PUCCH_format4_occ_Length_e;

enum SQN_NR_PUCCH_format4_occ_Index_e {
	SQN_NR_PUCCH_format4_occ_Index_e_n0 = 0,
	SQN_NR_PUCCH_format4_occ_Index_e_n1 = 1,
	SQN_NR_PUCCH_format4_occ_Index_e_n2 = 2,
	SQN_NR_PUCCH_format4_occ_Index_e_n3 = 3,
};

typedef enum SQN_NR_PUCCH_format4_occ_Index_e SQN_NR_PUCCH_format4_occ_Index_e;

struct SQN_NR_PUCCH_format4 {
	uint8_t nrofSymbols;
	SQN_NR_PUCCH_format4_occ_Length_e occ_Length;
	SQN_NR_PUCCH_format4_occ_Index_e occ_Index;
	uint8_t startingSymbolIndex;
};

enum SQN_NR_PUCCH_Resource_format_Sel {
	SQN_NR_PUCCH_Resource_format_UNBOUND_VALUE = 0,
	SQN_NR_PUCCH_Resource_format_format0 = 1,
	SQN_NR_PUCCH_Resource_format_format1 = 2,
	SQN_NR_PUCCH_Resource_format_format2 = 3,
	SQN_NR_PUCCH_Resource_format_format3 = 4,
	SQN_NR_PUCCH_Resource_format_format4 = 5,
};

union SQN_NR_PUCCH_Resource_format_Value {
	struct SQN_NR_PUCCH_format0 format0;
	struct SQN_NR_PUCCH_format1 format1;
	struct SQN_NR_PUCCH_format2 format2;
	struct SQN_NR_PUCCH_format3 format3;
	struct SQN_NR_PUCCH_format4 format4;
};

struct SQN_NR_PUCCH_Resource_format {
	enum SQN_NR_PUCCH_Resource_format_Sel d;
	union SQN_NR_PUCCH_Resource_format_Value v;
};

struct SQN_NR_PUCCH_Resource_intraSlotFrequencyHopping_e_intraSlotFrequencyHopping_Optional {
	bool d;
	SQN_NR_PUCCH_Resource_intraSlotFrequencyHopping_e v;
};

struct SQN_NR_PRB_Id_SQN_NR_PUCCH_Resource_secondHopPRB_Optional {
	bool d;
	SQN_NR_PRB_Id v;
};

struct SQN_NR_PUCCH_Resource {
	SQN_NR_PUCCH_ResourceId pucch_ResourceId;
	SQN_NR_PRB_Id startingPRB;
	struct SQN_NR_PUCCH_Resource_intraSlotFrequencyHopping_e_intraSlotFrequencyHopping_Optional intraSlotFrequencyHopping;
	struct SQN_NR_PRB_Id_SQN_NR_PUCCH_Resource_secondHopPRB_Optional secondHopPRB;
	struct SQN_NR_PUCCH_Resource_format format;
};

enum SQN_NR_PUCCH_FormatConfig_interslotFrequencyHopping_e {
	SQN_NR_PUCCH_FormatConfig_interslotFrequencyHopping_e_enabled = 0,
};

typedef enum SQN_NR_PUCCH_FormatConfig_interslotFrequencyHopping_e SQN_NR_PUCCH_FormatConfig_interslotFrequencyHopping_e;

enum SQN_NR_PUCCH_FormatConfig_additionalDMRS_e {
	SQN_NR_PUCCH_FormatConfig_additionalDMRS_e_true = 0,
};

typedef enum SQN_NR_PUCCH_FormatConfig_additionalDMRS_e SQN_NR_PUCCH_FormatConfig_additionalDMRS_e;

enum SQN_NR_PUCCH_MaxCodeRate_e {
	SQN_NR_PUCCH_MaxCodeRate_e_zeroDot08 = 0,
	SQN_NR_PUCCH_MaxCodeRate_e_zeroDot15 = 1,
	SQN_NR_PUCCH_MaxCodeRate_e_zeroDot25 = 2,
	SQN_NR_PUCCH_MaxCodeRate_e_zeroDot35 = 3,
	SQN_NR_PUCCH_MaxCodeRate_e_zeroDot45 = 4,
	SQN_NR_PUCCH_MaxCodeRate_e_zeroDot60 = 5,
	SQN_NR_PUCCH_MaxCodeRate_e_zeroDot80 = 6,
};

typedef enum SQN_NR_PUCCH_MaxCodeRate_e SQN_NR_PUCCH_MaxCodeRate_e;

enum SQN_NR_PUCCH_FormatConfig_nrofSlots_e {
	SQN_NR_PUCCH_FormatConfig_nrofSlots_e_n2 = 0,
	SQN_NR_PUCCH_FormatConfig_nrofSlots_e_n4 = 1,
	SQN_NR_PUCCH_FormatConfig_nrofSlots_e_n8 = 2,
};

typedef enum SQN_NR_PUCCH_FormatConfig_nrofSlots_e SQN_NR_PUCCH_FormatConfig_nrofSlots_e;

enum SQN_NR_PUCCH_FormatConfig_pi2BPSK_e {
	SQN_NR_PUCCH_FormatConfig_pi2BPSK_e_enabled = 0,
};

typedef enum SQN_NR_PUCCH_FormatConfig_pi2BPSK_e SQN_NR_PUCCH_FormatConfig_pi2BPSK_e;

enum SQN_NR_PUCCH_FormatConfig_simultaneousHARQ_ACK_CSI_e {
	SQN_NR_PUCCH_FormatConfig_simultaneousHARQ_ACK_CSI_e_true = 0,
};

typedef enum SQN_NR_PUCCH_FormatConfig_simultaneousHARQ_ACK_CSI_e SQN_NR_PUCCH_FormatConfig_simultaneousHARQ_ACK_CSI_e;

struct SQN_NR_PUCCH_FormatConfig_interslotFrequencyHopping_e_interslotFrequencyHopping_Optional {
	bool d;
	SQN_NR_PUCCH_FormatConfig_interslotFrequencyHopping_e v;
};

struct SQN_NR_PUCCH_FormatConfig_additionalDMRS_e_additionalDMRS_Optional {
	bool d;
	SQN_NR_PUCCH_FormatConfig_additionalDMRS_e v;
};

struct SQN_NR_PUCCH_MaxCodeRate_e_SQN_NR_PUCCH_FormatConfig_maxCodeRate_Optional {
	bool d;
	SQN_NR_PUCCH_MaxCodeRate_e v;
};

struct SQN_NR_PUCCH_FormatConfig_nrofSlots_e_nrofSlots_Optional {
	bool d;
	SQN_NR_PUCCH_FormatConfig_nrofSlots_e v;
};

struct SQN_NR_PUCCH_FormatConfig_pi2BPSK_e_pi2BPSK_Optional {
	bool d;
	SQN_NR_PUCCH_FormatConfig_pi2BPSK_e v;
};

struct SQN_NR_PUCCH_FormatConfig_simultaneousHARQ_ACK_CSI_e_simultaneousHARQ_ACK_CSI_Optional {
	bool d;
	SQN_NR_PUCCH_FormatConfig_simultaneousHARQ_ACK_CSI_e v;
};

struct SQN_NR_PUCCH_FormatConfig {
	struct SQN_NR_PUCCH_FormatConfig_interslotFrequencyHopping_e_interslotFrequencyHopping_Optional interslotFrequencyHopping;
	struct SQN_NR_PUCCH_FormatConfig_additionalDMRS_e_additionalDMRS_Optional additionalDMRS;
	struct SQN_NR_PUCCH_MaxCodeRate_e_SQN_NR_PUCCH_FormatConfig_maxCodeRate_Optional maxCodeRate;
	struct SQN_NR_PUCCH_FormatConfig_nrofSlots_e_nrofSlots_Optional nrofSlots;
	struct SQN_NR_PUCCH_FormatConfig_pi2BPSK_e_pi2BPSK_Optional pi2BPSK;
	struct SQN_NR_PUCCH_FormatConfig_simultaneousHARQ_ACK_CSI_e_simultaneousHARQ_ACK_CSI_Optional simultaneousHARQ_ACK_CSI;
};

enum SQN_NR_SetupRelease_PUCCH_Config_format1_Sel {
	SQN_NR_SetupRelease_PUCCH_Config_format1_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUCCH_Config_format1_release = 1,
	SQN_NR_SetupRelease_PUCCH_Config_format1_setup = 2,
};

union SQN_NR_SetupRelease_PUCCH_Config_format1_Value {
	Null release;
	struct SQN_NR_PUCCH_FormatConfig setup;
};

struct SQN_NR_SetupRelease_PUCCH_Config_format1 {
	enum SQN_NR_SetupRelease_PUCCH_Config_format1_Sel d;
	union SQN_NR_SetupRelease_PUCCH_Config_format1_Value v;
};

enum SQN_NR_SetupRelease_PUCCH_Config_format2_Sel {
	SQN_NR_SetupRelease_PUCCH_Config_format2_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUCCH_Config_format2_release = 1,
	SQN_NR_SetupRelease_PUCCH_Config_format2_setup = 2,
};

union SQN_NR_SetupRelease_PUCCH_Config_format2_Value {
	Null release;
	struct SQN_NR_PUCCH_FormatConfig setup;
};

struct SQN_NR_SetupRelease_PUCCH_Config_format2 {
	enum SQN_NR_SetupRelease_PUCCH_Config_format2_Sel d;
	union SQN_NR_SetupRelease_PUCCH_Config_format2_Value v;
};

enum SQN_NR_SetupRelease_PUCCH_Config_format3_Sel {
	SQN_NR_SetupRelease_PUCCH_Config_format3_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUCCH_Config_format3_release = 1,
	SQN_NR_SetupRelease_PUCCH_Config_format3_setup = 2,
};

union SQN_NR_SetupRelease_PUCCH_Config_format3_Value {
	Null release;
	struct SQN_NR_PUCCH_FormatConfig setup;
};

struct SQN_NR_SetupRelease_PUCCH_Config_format3 {
	enum SQN_NR_SetupRelease_PUCCH_Config_format3_Sel d;
	union SQN_NR_SetupRelease_PUCCH_Config_format3_Value v;
};

enum SQN_NR_SetupRelease_PUCCH_Config_format4_Sel {
	SQN_NR_SetupRelease_PUCCH_Config_format4_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUCCH_Config_format4_release = 1,
	SQN_NR_SetupRelease_PUCCH_Config_format4_setup = 2,
};

union SQN_NR_SetupRelease_PUCCH_Config_format4_Value {
	Null release;
	struct SQN_NR_PUCCH_FormatConfig setup;
};

struct SQN_NR_SetupRelease_PUCCH_Config_format4 {
	enum SQN_NR_SetupRelease_PUCCH_Config_format4_Sel d;
	union SQN_NR_SetupRelease_PUCCH_Config_format4_Value v;
};

typedef uint8_t SQN_NR_SchedulingRequestResourceId;

typedef uint8_t SQN_NR_SchedulingRequestId;

enum SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_Sel {
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_UNBOUND_VALUE = 0,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sym2 = 1,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sym6or7 = 2,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sl1 = 3,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sl2 = 4,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sl4 = 5,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sl5 = 6,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sl8 = 7,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sl10 = 8,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sl16 = 9,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sl20 = 10,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sl40 = 11,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sl80 = 12,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sl160 = 13,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sl320 = 14,
	SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_sl640 = 15,
};

union SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_Value {
	Null sym2;
	Null sym6or7;
	Null sl1;
	uint8_t sl2;
	uint8_t sl4;
	uint8_t sl5;
	uint8_t sl8;
	uint8_t sl10;
	uint8_t sl16;
	uint8_t sl20;
	uint8_t sl40;
	uint8_t sl80;
	uint8_t sl160;
	uint16_t sl320;
	uint16_t sl640;
};

struct SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset {
	enum SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_Sel d;
	union SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_Value v;
};

struct SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_periodicityAndOffset_Optional {
	bool d;
	struct SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset v;
};

struct SQN_NR_PUCCH_ResourceId_SQN_NR_SchedulingRequestResourceConfig_resource_Optional {
	bool d;
	SQN_NR_PUCCH_ResourceId v;
};

struct SQN_NR_SchedulingRequestResourceConfig {
	SQN_NR_SchedulingRequestResourceId schedulingRequestResourceId;
	SQN_NR_SchedulingRequestId schedulingRequestID;
	struct SQN_NR_SchedulingRequestResourceConfig_periodicityAndOffset_periodicityAndOffset_Optional periodicityAndOffset;
	struct SQN_NR_PUCCH_ResourceId_SQN_NR_SchedulingRequestResourceConfig_resource_Optional resource;
};

typedef uint8_t SQN_NR_PUCCH_SpatialRelationInfoId;

typedef uint8_t SQN_NR_ServCellIndex;

typedef uint8_t SQN_NR_SSB_Index;

typedef uint8_t SQN_NR_NZP_CSI_RS_ResourceId;

typedef uint8_t SQN_NR_SRS_ResourceId;

struct SQN_NR_PUCCH_SRS {
	SQN_NR_SRS_ResourceId resource;
	SQN_NR_BWP_Id uplinkBWP;
};

enum SQN_NR_PUCCH_SpatialRelationInfo_referenceSignal_Sel {
	SQN_NR_PUCCH_SpatialRelationInfo_referenceSignal_UNBOUND_VALUE = 0,
	SQN_NR_PUCCH_SpatialRelationInfo_referenceSignal_ssb_Index = 1,
	SQN_NR_PUCCH_SpatialRelationInfo_referenceSignal_csi_RS_Index = 2,
	SQN_NR_PUCCH_SpatialRelationInfo_referenceSignal_srs = 3,
};

union SQN_NR_PUCCH_SpatialRelationInfo_referenceSignal_Value {
	SQN_NR_SSB_Index ssb_Index;
	SQN_NR_NZP_CSI_RS_ResourceId csi_RS_Index;
	struct SQN_NR_PUCCH_SRS srs;
};

struct SQN_NR_PUCCH_SpatialRelationInfo_referenceSignal {
	enum SQN_NR_PUCCH_SpatialRelationInfo_referenceSignal_Sel d;
	union SQN_NR_PUCCH_SpatialRelationInfo_referenceSignal_Value v;
};

typedef uint8_t SQN_NR_PUCCH_PathlossReferenceRS_Id;

typedef uint8_t SQN_NR_P0_PUCCH_Id;

enum SQN_NR_PUCCH_SpatialRelationInfo_closedLoopIndex_e {
	SQN_NR_PUCCH_SpatialRelationInfo_closedLoopIndex_e_i0 = 0,
	SQN_NR_PUCCH_SpatialRelationInfo_closedLoopIndex_e_i1 = 1,
};

typedef enum SQN_NR_PUCCH_SpatialRelationInfo_closedLoopIndex_e SQN_NR_PUCCH_SpatialRelationInfo_closedLoopIndex_e;

struct SQN_NR_ServCellIndex_SQN_NR_PUCCH_SpatialRelationInfo_servingCellId_Optional {
	bool d;
	SQN_NR_ServCellIndex v;
};

struct SQN_NR_PUCCH_SpatialRelationInfo {
	SQN_NR_PUCCH_SpatialRelationInfoId pucch_SpatialRelationInfoId;
	struct SQN_NR_ServCellIndex_SQN_NR_PUCCH_SpatialRelationInfo_servingCellId_Optional servingCellId;
	struct SQN_NR_PUCCH_SpatialRelationInfo_referenceSignal referenceSignal;
	SQN_NR_PUCCH_PathlossReferenceRS_Id pucch_PathlossReferenceRS_Id;
	SQN_NR_P0_PUCCH_Id p0_PUCCH_Id;
	SQN_NR_PUCCH_SpatialRelationInfo_closedLoopIndex_e closedLoopIndex;
};

struct SQN_NR_P0_PUCCH {
	SQN_NR_P0_PUCCH_Id p0_PUCCH_Id;
	int8_t p0_PUCCH_Value;
};

enum SQN_NR_PUCCH_PathlossReferenceRS_referenceSignal_Sel {
	SQN_NR_PUCCH_PathlossReferenceRS_referenceSignal_UNBOUND_VALUE = 0,
	SQN_NR_PUCCH_PathlossReferenceRS_referenceSignal_ssb_Index = 1,
	SQN_NR_PUCCH_PathlossReferenceRS_referenceSignal_csi_RS_Index = 2,
};

union SQN_NR_PUCCH_PathlossReferenceRS_referenceSignal_Value {
	SQN_NR_SSB_Index ssb_Index;
	SQN_NR_NZP_CSI_RS_ResourceId csi_RS_Index;
};

struct SQN_NR_PUCCH_PathlossReferenceRS_referenceSignal {
	enum SQN_NR_PUCCH_PathlossReferenceRS_referenceSignal_Sel d;
	union SQN_NR_PUCCH_PathlossReferenceRS_referenceSignal_Value v;
};

struct SQN_NR_PUCCH_PathlossReferenceRS {
	SQN_NR_PUCCH_PathlossReferenceRS_Id pucch_PathlossReferenceRS_Id;
	struct SQN_NR_PUCCH_PathlossReferenceRS_referenceSignal referenceSignal;
};

enum SQN_NR_PUCCH_PowerControl_twoPUCCH_PC_AdjustmentStates_e {
	SQN_NR_PUCCH_PowerControl_twoPUCCH_PC_AdjustmentStates_e_twoStates = 0,
};

typedef enum SQN_NR_PUCCH_PowerControl_twoPUCCH_PC_AdjustmentStates_e SQN_NR_PUCCH_PowerControl_twoPUCCH_PC_AdjustmentStates_e;

typedef uint8_t SQN_NR_PUCCH_PathlossReferenceRS_Id_v1610;

enum SQN_NR_PUCCH_PathlossReferenceRS_r16_referenceSignal_r16_Sel {
	SQN_NR_PUCCH_PathlossReferenceRS_r16_referenceSignal_r16_UNBOUND_VALUE = 0,
	SQN_NR_PUCCH_PathlossReferenceRS_r16_referenceSignal_r16_ssb_Index_r16 = 1,
	SQN_NR_PUCCH_PathlossReferenceRS_r16_referenceSignal_r16_csi_RS_Index_r16 = 2,
};

union SQN_NR_PUCCH_PathlossReferenceRS_r16_referenceSignal_r16_Value {
	SQN_NR_SSB_Index ssb_Index_r16;
	SQN_NR_NZP_CSI_RS_ResourceId csi_RS_Index_r16;
};

struct SQN_NR_PUCCH_PathlossReferenceRS_r16_referenceSignal_r16 {
	enum SQN_NR_PUCCH_PathlossReferenceRS_r16_referenceSignal_r16_Sel d;
	union SQN_NR_PUCCH_PathlossReferenceRS_r16_referenceSignal_r16_Value v;
};

struct SQN_NR_PUCCH_PathlossReferenceRS_r16 {
	SQN_NR_PUCCH_PathlossReferenceRS_Id_v1610 pucch_PathlossReferenceRS_Id_r16;
	struct SQN_NR_PUCCH_PathlossReferenceRS_r16_referenceSignal_r16 referenceSignal_r16;
};

struct SQN_NR_PUCCH_PathlossReferenceRS_r16_SQN_NR_PathlossReferenceRSs_v1610_Dynamic {
	size_t d;
	struct SQN_NR_PUCCH_PathlossReferenceRS_r16* v;
};

typedef struct SQN_NR_PUCCH_PathlossReferenceRS_r16_SQN_NR_PathlossReferenceRSs_v1610_Dynamic SQN_NR_PathlossReferenceRSs_v1610;

enum SQN_NR_SetupRelease_PUCCH_PowerControl_pathlossReferenceRSs_v1610_Sel {
	SQN_NR_SetupRelease_PUCCH_PowerControl_pathlossReferenceRSs_v1610_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUCCH_PowerControl_pathlossReferenceRSs_v1610_release = 1,
	SQN_NR_SetupRelease_PUCCH_PowerControl_pathlossReferenceRSs_v1610_setup = 2,
};

union SQN_NR_SetupRelease_PUCCH_PowerControl_pathlossReferenceRSs_v1610_Value {
	Null release;
	SQN_NR_PathlossReferenceRSs_v1610 setup;
};

struct SQN_NR_SetupRelease_PUCCH_PowerControl_pathlossReferenceRSs_v1610 {
	enum SQN_NR_SetupRelease_PUCCH_PowerControl_pathlossReferenceRSs_v1610_Sel d;
	union SQN_NR_SetupRelease_PUCCH_PowerControl_pathlossReferenceRSs_v1610_Value v;
};

struct int8_t_SQN_NR_PUCCH_PowerControl_deltaF_PUCCH_f0_Optional {
	bool d;
	int8_t v;
};

struct int8_t_SQN_NR_PUCCH_PowerControl_deltaF_PUCCH_f1_Optional {
	bool d;
	int8_t v;
};

struct int8_t_SQN_NR_PUCCH_PowerControl_deltaF_PUCCH_f2_Optional {
	bool d;
	int8_t v;
};

struct int8_t_SQN_NR_PUCCH_PowerControl_deltaF_PUCCH_f3_Optional {
	bool d;
	int8_t v;
};

struct int8_t_SQN_NR_PUCCH_PowerControl_deltaF_PUCCH_f4_Optional {
	bool d;
	int8_t v;
};

struct SQN_NR_PUCCH_PowerControl_SQN_NR_P0_PUCCH_p0_Set_Dynamic {
	size_t d;
	struct SQN_NR_P0_PUCCH* v;
};

struct SQN_NR_P0_PUCCH_SQN_NR_PUCCH_PowerControl_p0_Set_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_PowerControl_SQN_NR_P0_PUCCH_p0_Set_Dynamic v;
};

struct SQN_NR_PUCCH_PowerControl_SQN_NR_PUCCH_PathlossReferenceRS_pathlossReferenceRSs_Dynamic {
	size_t d;
	struct SQN_NR_PUCCH_PathlossReferenceRS* v;
};

struct SQN_NR_PUCCH_PathlossReferenceRS_SQN_NR_PUCCH_PowerControl_pathlossReferenceRSs_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_PowerControl_SQN_NR_PUCCH_PathlossReferenceRS_pathlossReferenceRSs_Dynamic v;
};

struct SQN_NR_PUCCH_PowerControl_twoPUCCH_PC_AdjustmentStates_e_twoPUCCH_PC_AdjustmentStates_Optional {
	bool d;
	SQN_NR_PUCCH_PowerControl_twoPUCCH_PC_AdjustmentStates_e v;
};

struct SQN_NR_SetupRelease_PUCCH_PowerControl_pathlossReferenceRSs_v1610_SQN_NR_PUCCH_PowerControl_pathlossReferenceRSs_v1610_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUCCH_PowerControl_pathlossReferenceRSs_v1610 v;
};

struct SQN_NR_PUCCH_PowerControl {
	struct int8_t_SQN_NR_PUCCH_PowerControl_deltaF_PUCCH_f0_Optional deltaF_PUCCH_f0;
	struct int8_t_SQN_NR_PUCCH_PowerControl_deltaF_PUCCH_f1_Optional deltaF_PUCCH_f1;
	struct int8_t_SQN_NR_PUCCH_PowerControl_deltaF_PUCCH_f2_Optional deltaF_PUCCH_f2;
	struct int8_t_SQN_NR_PUCCH_PowerControl_deltaF_PUCCH_f3_Optional deltaF_PUCCH_f3;
	struct int8_t_SQN_NR_PUCCH_PowerControl_deltaF_PUCCH_f4_Optional deltaF_PUCCH_f4;
	struct SQN_NR_P0_PUCCH_SQN_NR_PUCCH_PowerControl_p0_Set_DynamicOptional p0_Set;
	struct SQN_NR_PUCCH_PathlossReferenceRS_SQN_NR_PUCCH_PowerControl_pathlossReferenceRSs_DynamicOptional pathlossReferenceRSs;
	struct SQN_NR_PUCCH_PowerControl_twoPUCCH_PC_AdjustmentStates_e_twoPUCCH_PC_AdjustmentStates_Optional twoPUCCH_PC_AdjustmentStates;
	struct SQN_NR_SetupRelease_PUCCH_PowerControl_pathlossReferenceRSs_v1610_SQN_NR_PUCCH_PowerControl_pathlossReferenceRSs_v1610_Optional pathlossReferenceRSs_v1610;
};

enum SQN_NR_PUCCH_ResourceExt_r16_interlaceAllocation_r16_interlace0_Sel {
	SQN_NR_PUCCH_ResourceExt_r16_interlaceAllocation_r16_interlace0_UNBOUND_VALUE = 0,
	SQN_NR_PUCCH_ResourceExt_r16_interlaceAllocation_r16_interlace0_scs15 = 1,
	SQN_NR_PUCCH_ResourceExt_r16_interlaceAllocation_r16_interlace0_scs30 = 2,
};

union SQN_NR_PUCCH_ResourceExt_r16_interlaceAllocation_r16_interlace0_Value {
	uint8_t scs15;
	uint8_t scs30;
};

struct SQN_NR_PUCCH_ResourceExt_r16_interlaceAllocation_r16_interlace0 {
	enum SQN_NR_PUCCH_ResourceExt_r16_interlaceAllocation_r16_interlace0_Sel d;
	union SQN_NR_PUCCH_ResourceExt_r16_interlaceAllocation_r16_interlace0_Value v;
};

struct SQN_NR_PUCCH_ResourceExt_r16_interlaceAllocation_r16 {
	uint8_t rb_SetIndex;
	struct SQN_NR_PUCCH_ResourceExt_r16_interlaceAllocation_r16_interlace0 interlace0;
};

enum SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Length_v1610_e {
	SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Length_v1610_e_n2 = 0,
	SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Length_v1610_e_n4 = 1,
};

typedef enum SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Length_v1610_e SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Length_v1610_e;

enum SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Index_v1610_e {
	SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Index_v1610_e_n0 = 0,
	SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Index_v1610_e_n1 = 1,
	SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Index_v1610_e_n2 = 2,
	SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Index_v1610_e_n3 = 3,
};

typedef enum SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Index_v1610_e SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Index_v1610_e;

struct SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Length_v1610_e_occ_Length_v1610_Optional {
	bool d;
	SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Length_v1610_e v;
};

struct SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Index_v1610_e_occ_Index_v1610_Optional {
	bool d;
	SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Index_v1610_e v;
};

struct SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610 {
	struct SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Length_v1610_e_occ_Length_v1610_Optional occ_Length_v1610;
	struct SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610_occ_Index_v1610_e_occ_Index_v1610_Optional occ_Index_v1610;
};

enum SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_Sel {
	SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_UNBOUND_VALUE = 0,
	SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_interlace1_v1610 = 1,
	SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610 = 2,
};

union SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_Value {
	uint8_t interlace1_v1610;
	struct SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_occ_v1610 occ_v1610;
};

struct SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610 {
	enum SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_Sel d;
	union SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_Value v;
};

struct SQN_NR_PUCCH_ResourceExt_r16_interlaceAllocation_r16_interlaceAllocation_r16_Optional {
	bool d;
	struct SQN_NR_PUCCH_ResourceExt_r16_interlaceAllocation_r16 v;
};

struct SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_formatExt_v1610_Optional {
	bool d;
	struct SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610 v;
};

struct SQN_NR_PUCCH_ResourceExt_r16 {
	struct SQN_NR_PUCCH_ResourceExt_r16_interlaceAllocation_r16_interlaceAllocation_r16_Optional interlaceAllocation_r16;
	struct SQN_NR_PUCCH_ResourceExt_r16_formatExt_v1610_formatExt_v1610_Optional formatExt_v1610;
};

struct int8_t_SQN_NR_DL_DataToUL_ACK_r16_Dynamic {
	size_t d;
	int8_t* v;
};

typedef struct int8_t_SQN_NR_DL_DataToUL_ACK_r16_Dynamic SQN_NR_DL_DataToUL_ACK_r16;

enum SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_r16_Sel {
	SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_r16_release = 1,
	SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_r16_Value {
	Null release;
	SQN_NR_DL_DataToUL_ACK_r16 setup;
};

struct SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_r16 {
	enum SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_r16_Sel d;
	union SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_r16_Value v;
};

struct uint8_t_SQN_NR_UL_AccessConfigListDCI_1_1_r16_Dynamic {
	size_t d;
	uint8_t* v;
};

typedef struct uint8_t_SQN_NR_UL_AccessConfigListDCI_1_1_r16_Dynamic SQN_NR_UL_AccessConfigListDCI_1_1_r16;

enum SQN_NR_SetupRelease_PUCCH_Config_ul_AccessConfigListDCI_1_1_r16_Sel {
	SQN_NR_SetupRelease_PUCCH_Config_ul_AccessConfigListDCI_1_1_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUCCH_Config_ul_AccessConfigListDCI_1_1_r16_release = 1,
	SQN_NR_SetupRelease_PUCCH_Config_ul_AccessConfigListDCI_1_1_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUCCH_Config_ul_AccessConfigListDCI_1_1_r16_Value {
	Null release;
	SQN_NR_UL_AccessConfigListDCI_1_1_r16 setup;
};

struct SQN_NR_SetupRelease_PUCCH_Config_ul_AccessConfigListDCI_1_1_r16 {
	enum SQN_NR_SetupRelease_PUCCH_Config_ul_AccessConfigListDCI_1_1_r16_Sel d;
	union SQN_NR_SetupRelease_PUCCH_Config_ul_AccessConfigListDCI_1_1_r16_Value v;
};

enum SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_normalCP_r16_e {
	SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_normalCP_r16_e_n2 = 0,
	SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_normalCP_r16_e_n7 = 1,
};

typedef enum SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_normalCP_r16_e SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_normalCP_r16_e;

enum SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_extendedCP_r16_e {
	SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_extendedCP_r16_e_n2 = 0,
	SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_extendedCP_r16_e_n6 = 1,
};

typedef enum SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_extendedCP_r16_e SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_extendedCP_r16_e;

enum SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_Sel {
	SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_UNBOUND_VALUE = 0,
	SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_normalCP_r16 = 1,
	SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_extendedCP_r16 = 2,
};

union SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_Value {
	SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_normalCP_r16_e normalCP_r16;
	SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_extendedCP_r16_e extendedCP_r16;
};

struct SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16 {
	enum SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_Sel d;
	union SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_Value v;
};

struct uint8_t_SQN_NR_DL_DataToUL_ACK_DCI_1_2_r16_Dynamic {
	size_t d;
	uint8_t* v;
};

typedef struct uint8_t_SQN_NR_DL_DataToUL_ACK_DCI_1_2_r16_Dynamic SQN_NR_DL_DataToUL_ACK_DCI_1_2_r16;

enum SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_DCI_1_2_r16_Sel {
	SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_DCI_1_2_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_DCI_1_2_r16_release = 1,
	SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_DCI_1_2_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_DCI_1_2_r16_Value {
	Null release;
	SQN_NR_DL_DataToUL_ACK_DCI_1_2_r16 setup;
};

struct SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_DCI_1_2_r16 {
	enum SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_DCI_1_2_r16_Sel d;
	union SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_DCI_1_2_r16_Value v;
};

enum SQN_NR_PUCCH_Config_dmrs_UplinkTransformPrecodingPUCCH_r16_e {
	SQN_NR_PUCCH_Config_dmrs_UplinkTransformPrecodingPUCCH_r16_e_enabled = 0,
};

typedef enum SQN_NR_PUCCH_Config_dmrs_UplinkTransformPrecodingPUCCH_r16_e SQN_NR_PUCCH_Config_dmrs_UplinkTransformPrecodingPUCCH_r16_e;

typedef uint8_t SQN_NR_PUCCH_SpatialRelationInfoId_v1610;

struct SQN_NR_PUCCH_SpatialRelationInfoId_v1610_SQN_NR_PUCCH_SpatialRelationInfoExt_r16_pucch_SpatialRelationInfoId_v1610_Optional {
	bool d;
	SQN_NR_PUCCH_SpatialRelationInfoId_v1610 v;
};

struct SQN_NR_PUCCH_PathlossReferenceRS_Id_v1610_SQN_NR_PUCCH_SpatialRelationInfoExt_r16_pucch_PathlossReferenceRS_Id_v1610_Optional {
	bool d;
	SQN_NR_PUCCH_PathlossReferenceRS_Id_v1610 v;
};

struct SQN_NR_PUCCH_SpatialRelationInfoExt_r16 {
	struct SQN_NR_PUCCH_SpatialRelationInfoId_v1610_SQN_NR_PUCCH_SpatialRelationInfoExt_r16_pucch_SpatialRelationInfoId_v1610_Optional pucch_SpatialRelationInfoId_v1610;
	struct SQN_NR_PUCCH_PathlossReferenceRS_Id_v1610_SQN_NR_PUCCH_SpatialRelationInfoExt_r16_pucch_PathlossReferenceRS_Id_v1610_Optional pucch_PathlossReferenceRS_Id_v1610;
};

typedef uint8_t SQN_NR_PUCCH_SpatialRelationInfoId_r16;

typedef uint8_t SQN_NR_PUCCH_ResourceGroupId_r16;

struct SQN_NR_PUCCH_ResourceId_resourcePerGroupList_r16_Dynamic {
	size_t d;
	SQN_NR_PUCCH_ResourceId* v;
};

struct SQN_NR_PUCCH_ResourceGroup_r16 {
	SQN_NR_PUCCH_ResourceGroupId_r16 pucch_ResourceGroupId_r16;
	struct SQN_NR_PUCCH_ResourceId_resourcePerGroupList_r16_Dynamic resourcePerGroupList_r16;
};

struct uint16_t_SQN_NR_SPS_PUCCH_AN_r16_maxPayloadSize_r16_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_SPS_PUCCH_AN_r16 {
	SQN_NR_PUCCH_ResourceId sps_PUCCH_AN_ResourceID_r16;
	struct uint16_t_SQN_NR_SPS_PUCCH_AN_r16_maxPayloadSize_r16_Optional maxPayloadSize_r16;
};

struct SQN_NR_SPS_PUCCH_AN_r16_SQN_NR_SPS_PUCCH_AN_List_r16_Dynamic {
	size_t d;
	struct SQN_NR_SPS_PUCCH_AN_r16* v;
};

typedef struct SQN_NR_SPS_PUCCH_AN_r16_SQN_NR_SPS_PUCCH_AN_List_r16_Dynamic SQN_NR_SPS_PUCCH_AN_List_r16;

enum SQN_NR_SetupRelease_PUCCH_Config_sps_PUCCH_AN_List_r16_Sel {
	SQN_NR_SetupRelease_PUCCH_Config_sps_PUCCH_AN_List_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUCCH_Config_sps_PUCCH_AN_List_r16_release = 1,
	SQN_NR_SetupRelease_PUCCH_Config_sps_PUCCH_AN_List_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUCCH_Config_sps_PUCCH_AN_List_r16_Value {
	Null release;
	SQN_NR_SPS_PUCCH_AN_List_r16 setup;
};

struct SQN_NR_SetupRelease_PUCCH_Config_sps_PUCCH_AN_List_r16 {
	enum SQN_NR_SetupRelease_PUCCH_Config_sps_PUCCH_AN_List_r16_Sel d;
	union SQN_NR_SetupRelease_PUCCH_Config_sps_PUCCH_AN_List_r16_Value v;
};

enum SQN_NR_SchedulingRequestResourceConfig_v1610_phy_PriorityIndex_r16_e {
	SQN_NR_SchedulingRequestResourceConfig_v1610_phy_PriorityIndex_r16_e_p0 = 0,
	SQN_NR_SchedulingRequestResourceConfig_v1610_phy_PriorityIndex_r16_e_p1 = 1,
};

typedef enum SQN_NR_SchedulingRequestResourceConfig_v1610_phy_PriorityIndex_r16_e SQN_NR_SchedulingRequestResourceConfig_v1610_phy_PriorityIndex_r16_e;

struct SQN_NR_SchedulingRequestResourceConfig_v1610_phy_PriorityIndex_r16_e_phy_PriorityIndex_r16_Optional {
	bool d;
	SQN_NR_SchedulingRequestResourceConfig_v1610_phy_PriorityIndex_r16_e v;
};

struct SQN_NR_SchedulingRequestResourceConfig_v1610 {
	struct SQN_NR_SchedulingRequestResourceConfig_v1610_phy_PriorityIndex_r16_e_phy_PriorityIndex_r16_Optional phy_PriorityIndex_r16;
};

struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_ResourceSet_resourceSetToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_PUCCH_ResourceSet* v;
};

struct SQN_NR_PUCCH_ResourceSet_SQN_NR_PUCCH_Config_resourceSetToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_ResourceSet_resourceSetToAddModList_Dynamic v;
};

struct SQN_NR_PUCCH_ResourceSetId_SQN_NR_PUCCH_Config_resourceSetToReleaseList_Dynamic {
	size_t d;
	SQN_NR_PUCCH_ResourceSetId* v;
};

struct SQN_NR_PUCCH_ResourceSetId_SQN_NR_PUCCH_Config_resourceSetToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_ResourceSetId_SQN_NR_PUCCH_Config_resourceSetToReleaseList_Dynamic v;
};

struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_Resource_resourceToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_PUCCH_Resource* v;
};

struct SQN_NR_PUCCH_Resource_SQN_NR_PUCCH_Config_resourceToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_Resource_resourceToAddModList_Dynamic v;
};

struct SQN_NR_PUCCH_ResourceId_SQN_NR_PUCCH_Config_resourceToReleaseList_Dynamic {
	size_t d;
	SQN_NR_PUCCH_ResourceId* v;
};

struct SQN_NR_PUCCH_ResourceId_SQN_NR_PUCCH_Config_resourceToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_ResourceId_SQN_NR_PUCCH_Config_resourceToReleaseList_Dynamic v;
};

struct SQN_NR_SetupRelease_PUCCH_Config_format1_SQN_NR_PUCCH_Config_format1_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUCCH_Config_format1 v;
};

struct SQN_NR_SetupRelease_PUCCH_Config_format2_SQN_NR_PUCCH_Config_format2_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUCCH_Config_format2 v;
};

struct SQN_NR_SetupRelease_PUCCH_Config_format3_SQN_NR_PUCCH_Config_format3_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUCCH_Config_format3 v;
};

struct SQN_NR_SetupRelease_PUCCH_Config_format4_SQN_NR_PUCCH_Config_format4_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUCCH_Config_format4 v;
};

struct SQN_NR_PUCCH_Config_SQN_NR_SchedulingRequestResourceConfig_schedulingRequestResourceToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_SchedulingRequestResourceConfig* v;
};

struct SQN_NR_SchedulingRequestResourceConfig_SQN_NR_PUCCH_Config_schedulingRequestResourceToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_Config_SQN_NR_SchedulingRequestResourceConfig_schedulingRequestResourceToAddModList_Dynamic v;
};

struct SQN_NR_SchedulingRequestResourceId_SQN_NR_PUCCH_Config_schedulingRequestResourceToReleaseList_Dynamic {
	size_t d;
	SQN_NR_SchedulingRequestResourceId* v;
};

struct SQN_NR_SchedulingRequestResourceId_SQN_NR_PUCCH_Config_schedulingRequestResourceToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_SchedulingRequestResourceId_SQN_NR_PUCCH_Config_schedulingRequestResourceToReleaseList_Dynamic v;
};

struct SQN_NR_PUCCH_ResourceId_SQN_NR_PUCCH_Config_multi_CSI_PUCCH_ResourceList_Dynamic {
	size_t d;
	SQN_NR_PUCCH_ResourceId* v;
};

struct SQN_NR_PUCCH_ResourceId_SQN_NR_PUCCH_Config_multi_CSI_PUCCH_ResourceList_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_ResourceId_SQN_NR_PUCCH_Config_multi_CSI_PUCCH_ResourceList_Dynamic v;
};

struct uint8_t_SQN_NR_PUCCH_Config_dl_DataToUL_ACK_Dynamic {
	size_t d;
	uint8_t* v;
};

struct uint8_t_SQN_NR_PUCCH_Config_dl_DataToUL_ACK_DynamicOptional {
	bool d;
	struct uint8_t_SQN_NR_PUCCH_Config_dl_DataToUL_ACK_Dynamic v;
};

struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_SpatialRelationInfo_spatialRelationInfoToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_PUCCH_SpatialRelationInfo* v;
};

struct SQN_NR_PUCCH_SpatialRelationInfo_SQN_NR_PUCCH_Config_spatialRelationInfoToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_SpatialRelationInfo_spatialRelationInfoToAddModList_Dynamic v;
};

struct SQN_NR_PUCCH_SpatialRelationInfoId_SQN_NR_PUCCH_Config_spatialRelationInfoToReleaseList_Dynamic {
	size_t d;
	SQN_NR_PUCCH_SpatialRelationInfoId* v;
};

struct SQN_NR_PUCCH_SpatialRelationInfoId_SQN_NR_PUCCH_Config_spatialRelationInfoToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_SpatialRelationInfoId_SQN_NR_PUCCH_Config_spatialRelationInfoToReleaseList_Dynamic v;
};

struct SQN_NR_PUCCH_PowerControl_SQN_NR_PUCCH_Config_pucch_PowerControl_Optional {
	bool d;
	struct SQN_NR_PUCCH_PowerControl v;
};

struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_ResourceExt_r16_resourceToAddModListExt_r16_Dynamic {
	size_t d;
	struct SQN_NR_PUCCH_ResourceExt_r16* v;
};

struct SQN_NR_PUCCH_ResourceExt_r16_SQN_NR_PUCCH_Config_resourceToAddModListExt_r16_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_ResourceExt_r16_resourceToAddModListExt_r16_Dynamic v;
};

struct SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_r16_SQN_NR_PUCCH_Config_dl_DataToUL_ACK_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_r16 v;
};

struct SQN_NR_SetupRelease_PUCCH_Config_ul_AccessConfigListDCI_1_1_r16_SQN_NR_PUCCH_Config_ul_AccessConfigListDCI_1_1_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUCCH_Config_ul_AccessConfigListDCI_1_1_r16 v;
};

struct SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_subslotLengthForPUCCH_r16_Optional {
	bool d;
	struct SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16 v;
};

struct SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_DCI_1_2_r16_SQN_NR_PUCCH_Config_dl_DataToUL_ACK_DCI_1_2_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_DCI_1_2_r16 v;
};

struct uint8_t_SQN_NR_PUCCH_Config_numberOfBitsForPUCCH_ResourceIndicatorDCI_1_2_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PUCCH_Config_dmrs_UplinkTransformPrecodingPUCCH_r16_e_dmrs_UplinkTransformPrecodingPUCCH_r16_Optional {
	bool d;
	SQN_NR_PUCCH_Config_dmrs_UplinkTransformPrecodingPUCCH_r16_e v;
};

struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_SpatialRelationInfo_spatialRelationInfoToAddModList2_r16_Dynamic {
	size_t d;
	struct SQN_NR_PUCCH_SpatialRelationInfo* v;
};

struct SQN_NR_PUCCH_SpatialRelationInfo_SQN_NR_PUCCH_Config_spatialRelationInfoToAddModList2_r16_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_SpatialRelationInfo_spatialRelationInfoToAddModList2_r16_Dynamic v;
};

struct SQN_NR_PUCCH_SpatialRelationInfoId_SQN_NR_PUCCH_Config_spatialRelationInfoToReleaseList2_r16_Dynamic {
	size_t d;
	SQN_NR_PUCCH_SpatialRelationInfoId* v;
};

struct SQN_NR_PUCCH_SpatialRelationInfoId_SQN_NR_PUCCH_Config_spatialRelationInfoToReleaseList2_r16_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_SpatialRelationInfoId_SQN_NR_PUCCH_Config_spatialRelationInfoToReleaseList2_r16_Dynamic v;
};

struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_SpatialRelationInfoExt_r16_spatialRelationInfoToAddModListExt_r16_Dynamic {
	size_t d;
	struct SQN_NR_PUCCH_SpatialRelationInfoExt_r16* v;
};

struct SQN_NR_PUCCH_SpatialRelationInfoExt_r16_SQN_NR_PUCCH_Config_spatialRelationInfoToAddModListExt_r16_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_SpatialRelationInfoExt_r16_spatialRelationInfoToAddModListExt_r16_Dynamic v;
};

struct SQN_NR_PUCCH_SpatialRelationInfoId_r16_SQN_NR_PUCCH_Config_spatialRelationInfoToReleaseList_r16_Dynamic {
	size_t d;
	SQN_NR_PUCCH_SpatialRelationInfoId_r16* v;
};

struct SQN_NR_PUCCH_SpatialRelationInfoId_r16_SQN_NR_PUCCH_Config_spatialRelationInfoToReleaseList_r16_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_SpatialRelationInfoId_r16_SQN_NR_PUCCH_Config_spatialRelationInfoToReleaseList_r16_Dynamic v;
};

struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_ResourceGroup_r16_resourceGroupToAddModList_r16_Dynamic {
	size_t d;
	struct SQN_NR_PUCCH_ResourceGroup_r16* v;
};

struct SQN_NR_PUCCH_ResourceGroup_r16_SQN_NR_PUCCH_Config_resourceGroupToAddModList_r16_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_ResourceGroup_r16_resourceGroupToAddModList_r16_Dynamic v;
};

struct SQN_NR_PUCCH_ResourceGroupId_r16_SQN_NR_PUCCH_Config_resourceGroupToReleaseList_r16_Dynamic {
	size_t d;
	SQN_NR_PUCCH_ResourceGroupId_r16* v;
};

struct SQN_NR_PUCCH_ResourceGroupId_r16_SQN_NR_PUCCH_Config_resourceGroupToReleaseList_r16_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_ResourceGroupId_r16_SQN_NR_PUCCH_Config_resourceGroupToReleaseList_r16_Dynamic v;
};

struct SQN_NR_SetupRelease_PUCCH_Config_sps_PUCCH_AN_List_r16_SQN_NR_PUCCH_Config_sps_PUCCH_AN_List_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUCCH_Config_sps_PUCCH_AN_List_r16 v;
};

struct SQN_NR_PUCCH_Config_SQN_NR_SchedulingRequestResourceConfig_v1610_schedulingRequestResourceToAddModList_v1610_Dynamic {
	size_t d;
	struct SQN_NR_SchedulingRequestResourceConfig_v1610* v;
};

struct SQN_NR_SchedulingRequestResourceConfig_v1610_SQN_NR_PUCCH_Config_schedulingRequestResourceToAddModList_v1610_DynamicOptional {
	bool d;
	struct SQN_NR_PUCCH_Config_SQN_NR_SchedulingRequestResourceConfig_v1610_schedulingRequestResourceToAddModList_v1610_Dynamic v;
};

struct SQN_NR_PUCCH_Config {
	struct SQN_NR_PUCCH_ResourceSet_SQN_NR_PUCCH_Config_resourceSetToAddModList_DynamicOptional resourceSetToAddModList;
	struct SQN_NR_PUCCH_ResourceSetId_SQN_NR_PUCCH_Config_resourceSetToReleaseList_DynamicOptional resourceSetToReleaseList;
	struct SQN_NR_PUCCH_Resource_SQN_NR_PUCCH_Config_resourceToAddModList_DynamicOptional resourceToAddModList;
	struct SQN_NR_PUCCH_ResourceId_SQN_NR_PUCCH_Config_resourceToReleaseList_DynamicOptional resourceToReleaseList;
	struct SQN_NR_SetupRelease_PUCCH_Config_format1_SQN_NR_PUCCH_Config_format1_Optional format1;
	struct SQN_NR_SetupRelease_PUCCH_Config_format2_SQN_NR_PUCCH_Config_format2_Optional format2;
	struct SQN_NR_SetupRelease_PUCCH_Config_format3_SQN_NR_PUCCH_Config_format3_Optional format3;
	struct SQN_NR_SetupRelease_PUCCH_Config_format4_SQN_NR_PUCCH_Config_format4_Optional format4;
	struct SQN_NR_SchedulingRequestResourceConfig_SQN_NR_PUCCH_Config_schedulingRequestResourceToAddModList_DynamicOptional schedulingRequestResourceToAddModList;
	struct SQN_NR_SchedulingRequestResourceId_SQN_NR_PUCCH_Config_schedulingRequestResourceToReleaseList_DynamicOptional schedulingRequestResourceToReleaseList;
	struct SQN_NR_PUCCH_ResourceId_SQN_NR_PUCCH_Config_multi_CSI_PUCCH_ResourceList_DynamicOptional multi_CSI_PUCCH_ResourceList;
	struct uint8_t_SQN_NR_PUCCH_Config_dl_DataToUL_ACK_DynamicOptional dl_DataToUL_ACK;
	struct SQN_NR_PUCCH_SpatialRelationInfo_SQN_NR_PUCCH_Config_spatialRelationInfoToAddModList_DynamicOptional spatialRelationInfoToAddModList;
	struct SQN_NR_PUCCH_SpatialRelationInfoId_SQN_NR_PUCCH_Config_spatialRelationInfoToReleaseList_DynamicOptional spatialRelationInfoToReleaseList;
	struct SQN_NR_PUCCH_PowerControl_SQN_NR_PUCCH_Config_pucch_PowerControl_Optional pucch_PowerControl;
	struct SQN_NR_PUCCH_ResourceExt_r16_SQN_NR_PUCCH_Config_resourceToAddModListExt_r16_DynamicOptional resourceToAddModListExt_r16;
	struct SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_r16_SQN_NR_PUCCH_Config_dl_DataToUL_ACK_r16_Optional dl_DataToUL_ACK_r16;
	struct SQN_NR_SetupRelease_PUCCH_Config_ul_AccessConfigListDCI_1_1_r16_SQN_NR_PUCCH_Config_ul_AccessConfigListDCI_1_1_r16_Optional ul_AccessConfigListDCI_1_1_r16;
	struct SQN_NR_PUCCH_Config_subslotLengthForPUCCH_r16_subslotLengthForPUCCH_r16_Optional subslotLengthForPUCCH_r16;
	struct SQN_NR_SetupRelease_PUCCH_Config_dl_DataToUL_ACK_DCI_1_2_r16_SQN_NR_PUCCH_Config_dl_DataToUL_ACK_DCI_1_2_r16_Optional dl_DataToUL_ACK_DCI_1_2_r16;
	struct uint8_t_SQN_NR_PUCCH_Config_numberOfBitsForPUCCH_ResourceIndicatorDCI_1_2_r16_Optional numberOfBitsForPUCCH_ResourceIndicatorDCI_1_2_r16;
	struct SQN_NR_PUCCH_Config_dmrs_UplinkTransformPrecodingPUCCH_r16_e_dmrs_UplinkTransformPrecodingPUCCH_r16_Optional dmrs_UplinkTransformPrecodingPUCCH_r16;
	struct SQN_NR_PUCCH_SpatialRelationInfo_SQN_NR_PUCCH_Config_spatialRelationInfoToAddModList2_r16_DynamicOptional spatialRelationInfoToAddModList2_r16;
	struct SQN_NR_PUCCH_SpatialRelationInfoId_SQN_NR_PUCCH_Config_spatialRelationInfoToReleaseList2_r16_DynamicOptional spatialRelationInfoToReleaseList2_r16;
	struct SQN_NR_PUCCH_SpatialRelationInfoExt_r16_SQN_NR_PUCCH_Config_spatialRelationInfoToAddModListExt_r16_DynamicOptional spatialRelationInfoToAddModListExt_r16;
	struct SQN_NR_PUCCH_SpatialRelationInfoId_r16_SQN_NR_PUCCH_Config_spatialRelationInfoToReleaseList_r16_DynamicOptional spatialRelationInfoToReleaseList_r16;
	struct SQN_NR_PUCCH_ResourceGroup_r16_SQN_NR_PUCCH_Config_resourceGroupToAddModList_r16_DynamicOptional resourceGroupToAddModList_r16;
	struct SQN_NR_PUCCH_ResourceGroupId_r16_SQN_NR_PUCCH_Config_resourceGroupToReleaseList_r16_DynamicOptional resourceGroupToReleaseList_r16;
	struct SQN_NR_SetupRelease_PUCCH_Config_sps_PUCCH_AN_List_r16_SQN_NR_PUCCH_Config_sps_PUCCH_AN_List_r16_Optional sps_PUCCH_AN_List_r16;
	struct SQN_NR_SchedulingRequestResourceConfig_v1610_SQN_NR_PUCCH_Config_schedulingRequestResourceToAddModList_v1610_DynamicOptional schedulingRequestResourceToAddModList_v1610;
};

enum SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_Config_Sel {
	SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_Config_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_Config_release = 1,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_Config_setup = 2,
};

union SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_Config_Value {
	Null release;
	struct SQN_NR_PUCCH_Config setup;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_Config {
	enum SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_Config_Sel d;
	union SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_Config_Value v;
};

enum SQN_NR_PUSCH_Config_txConfig_e {
	SQN_NR_PUSCH_Config_txConfig_e_codebook = 0,
	SQN_NR_PUSCH_Config_txConfig_e_nonCodebook = 1,
};

typedef enum SQN_NR_PUSCH_Config_txConfig_e SQN_NR_PUSCH_Config_txConfig_e;

enum SQN_NR_DMRS_UplinkConfig_dmrs_Type_e {
	SQN_NR_DMRS_UplinkConfig_dmrs_Type_e_type2 = 0,
};

typedef enum SQN_NR_DMRS_UplinkConfig_dmrs_Type_e SQN_NR_DMRS_UplinkConfig_dmrs_Type_e;

enum SQN_NR_DMRS_UplinkConfig_dmrs_AdditionalPosition_e {
	SQN_NR_DMRS_UplinkConfig_dmrs_AdditionalPosition_e_pos0 = 0,
	SQN_NR_DMRS_UplinkConfig_dmrs_AdditionalPosition_e_pos1 = 1,
	SQN_NR_DMRS_UplinkConfig_dmrs_AdditionalPosition_e_pos3 = 2,
};

typedef enum SQN_NR_DMRS_UplinkConfig_dmrs_AdditionalPosition_e SQN_NR_DMRS_UplinkConfig_dmrs_AdditionalPosition_e;

enum SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_maxNrofPorts_e {
	SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_maxNrofPorts_e_n1 = 0,
	SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_maxNrofPorts_e_n2 = 1,
};

typedef enum SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_maxNrofPorts_e SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_maxNrofPorts_e;

enum SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_resourceElementOffset_e {
	SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_resourceElementOffset_e_offset01 = 0,
	SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_resourceElementOffset_e_offset10 = 1,
	SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_resourceElementOffset_e_offset11 = 2,
};

typedef enum SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_resourceElementOffset_e SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_resourceElementOffset_e;

enum SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_ptrs_Power_e {
	SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_ptrs_Power_e_p00 = 0,
	SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_ptrs_Power_e_p01 = 1,
	SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_ptrs_Power_e_p10 = 2,
	SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_ptrs_Power_e_p11 = 3,
};

typedef enum SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_ptrs_Power_e SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_ptrs_Power_e;

struct uint16_t_SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_frequencyDensity_ArrayOptional {
	bool d;
	uint16_t v[2];
};

struct uint8_t_SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_timeDensity_ArrayOptional {
	bool d;
	uint8_t v[3];
};

struct SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_resourceElementOffset_e_resourceElementOffset_Optional {
	bool d;
	SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_resourceElementOffset_e v;
};

struct SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled {
	struct uint16_t_SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_frequencyDensity_ArrayOptional frequencyDensity;
	struct uint8_t_SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_timeDensity_ArrayOptional timeDensity;
	SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_maxNrofPorts_e maxNrofPorts;
	struct SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_resourceElementOffset_e_resourceElementOffset_Optional resourceElementOffset;
	SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_ptrs_Power_e ptrs_Power;
};

enum SQN_NR_PTRS_UplinkConfig_transformPrecoderEnabled_timeDensityTransformPrecoding_e {
	SQN_NR_PTRS_UplinkConfig_transformPrecoderEnabled_timeDensityTransformPrecoding_e_d2 = 0,
};

typedef enum SQN_NR_PTRS_UplinkConfig_transformPrecoderEnabled_timeDensityTransformPrecoding_e SQN_NR_PTRS_UplinkConfig_transformPrecoderEnabled_timeDensityTransformPrecoding_e;

struct SQN_NR_PTRS_UplinkConfig_transformPrecoderEnabled_timeDensityTransformPrecoding_e_timeDensityTransformPrecoding_Optional {
	bool d;
	SQN_NR_PTRS_UplinkConfig_transformPrecoderEnabled_timeDensityTransformPrecoding_e v;
};

struct SQN_NR_PTRS_UplinkConfig_transformPrecoderEnabled {
	uint16_t sampleDensity[5];
	struct SQN_NR_PTRS_UplinkConfig_transformPrecoderEnabled_timeDensityTransformPrecoding_e_timeDensityTransformPrecoding_Optional timeDensityTransformPrecoding;
};

struct SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_transformPrecoderDisabled_Optional {
	bool d;
	struct SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled v;
};

struct SQN_NR_PTRS_UplinkConfig_transformPrecoderEnabled_transformPrecoderEnabled_Optional {
	bool d;
	struct SQN_NR_PTRS_UplinkConfig_transformPrecoderEnabled v;
};

struct SQN_NR_PTRS_UplinkConfig {
	struct SQN_NR_PTRS_UplinkConfig_transformPrecoderDisabled_transformPrecoderDisabled_Optional transformPrecoderDisabled;
	struct SQN_NR_PTRS_UplinkConfig_transformPrecoderEnabled_transformPrecoderEnabled_Optional transformPrecoderEnabled;
};

enum SQN_NR_SetupRelease_DMRS_UplinkConfig_phaseTrackingRS_Sel {
	SQN_NR_SetupRelease_DMRS_UplinkConfig_phaseTrackingRS_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_DMRS_UplinkConfig_phaseTrackingRS_release = 1,
	SQN_NR_SetupRelease_DMRS_UplinkConfig_phaseTrackingRS_setup = 2,
};

union SQN_NR_SetupRelease_DMRS_UplinkConfig_phaseTrackingRS_Value {
	Null release;
	struct SQN_NR_PTRS_UplinkConfig setup;
};

struct SQN_NR_SetupRelease_DMRS_UplinkConfig_phaseTrackingRS {
	enum SQN_NR_SetupRelease_DMRS_UplinkConfig_phaseTrackingRS_Sel d;
	union SQN_NR_SetupRelease_DMRS_UplinkConfig_phaseTrackingRS_Value v;
};

enum SQN_NR_DMRS_UplinkConfig_maxLength_e {
	SQN_NR_DMRS_UplinkConfig_maxLength_e_len2 = 0,
};

typedef enum SQN_NR_DMRS_UplinkConfig_maxLength_e SQN_NR_DMRS_UplinkConfig_maxLength_e;

enum SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled_dmrs_Uplink_r16_e {
	SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled_dmrs_Uplink_r16_e_enabled = 0,
};

typedef enum SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled_dmrs_Uplink_r16_e SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled_dmrs_Uplink_r16_e;

struct uint16_t_SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled_scramblingID0_Optional {
	bool d;
	uint16_t v;
};

struct uint16_t_SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled_scramblingID1_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled_dmrs_Uplink_r16_e_dmrs_Uplink_r16_Optional {
	bool d;
	SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled_dmrs_Uplink_r16_e v;
};

struct SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled {
	struct uint16_t_SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled_scramblingID0_Optional scramblingID0;
	struct uint16_t_SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled_scramblingID1_Optional scramblingID1;
	struct SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled_dmrs_Uplink_r16_e_dmrs_Uplink_r16_Optional dmrs_Uplink_r16;
};

enum SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_sequenceGroupHopping_e {
	SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_sequenceGroupHopping_e_disabled = 0,
};

typedef enum SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_sequenceGroupHopping_e SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_sequenceGroupHopping_e;

enum SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_sequenceHopping_e {
	SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_sequenceHopping_e_enabled = 0,
};

typedef enum SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_sequenceHopping_e SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_sequenceHopping_e;

struct uint16_t_SQN_NR_DMRS_UplinkTransformPrecoding_r16_pi2BPSK_ScramblingID0_Optional {
	bool d;
	uint16_t v;
};

struct uint16_t_SQN_NR_DMRS_UplinkTransformPrecoding_r16_pi2BPSK_ScramblingID1_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_DMRS_UplinkTransformPrecoding_r16 {
	struct uint16_t_SQN_NR_DMRS_UplinkTransformPrecoding_r16_pi2BPSK_ScramblingID0_Optional pi2BPSK_ScramblingID0;
	struct uint16_t_SQN_NR_DMRS_UplinkTransformPrecoding_r16_pi2BPSK_ScramblingID1_Optional pi2BPSK_ScramblingID1;
};

enum SQN_NR_SetupRelease_DMRS_UplinkConfig_transformPrecodingEnabled_dmrs_UplinkTransformPrecoding_r16_Sel {
	SQN_NR_SetupRelease_DMRS_UplinkConfig_transformPrecodingEnabled_dmrs_UplinkTransformPrecoding_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_DMRS_UplinkConfig_transformPrecodingEnabled_dmrs_UplinkTransformPrecoding_r16_release = 1,
	SQN_NR_SetupRelease_DMRS_UplinkConfig_transformPrecodingEnabled_dmrs_UplinkTransformPrecoding_r16_setup = 2,
};

union SQN_NR_SetupRelease_DMRS_UplinkConfig_transformPrecodingEnabled_dmrs_UplinkTransformPrecoding_r16_Value {
	Null release;
	struct SQN_NR_DMRS_UplinkTransformPrecoding_r16 setup;
};

struct SQN_NR_SetupRelease_DMRS_UplinkConfig_transformPrecodingEnabled_dmrs_UplinkTransformPrecoding_r16 {
	enum SQN_NR_SetupRelease_DMRS_UplinkConfig_transformPrecodingEnabled_dmrs_UplinkTransformPrecoding_r16_Sel d;
	union SQN_NR_SetupRelease_DMRS_UplinkConfig_transformPrecodingEnabled_dmrs_UplinkTransformPrecoding_r16_Value v;
};

struct uint16_t_SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_nPUSCH_Identity_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_sequenceGroupHopping_e_sequenceGroupHopping_Optional {
	bool d;
	SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_sequenceGroupHopping_e v;
};

struct SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_sequenceHopping_e_sequenceHopping_Optional {
	bool d;
	SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_sequenceHopping_e v;
};

struct SQN_NR_SetupRelease_DMRS_UplinkConfig_transformPrecodingEnabled_dmrs_UplinkTransformPrecoding_r16_SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_dmrs_UplinkTransformPrecoding_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_DMRS_UplinkConfig_transformPrecodingEnabled_dmrs_UplinkTransformPrecoding_r16 v;
};

struct SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled {
	struct uint16_t_SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_nPUSCH_Identity_Optional nPUSCH_Identity;
	struct SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_sequenceGroupHopping_e_sequenceGroupHopping_Optional sequenceGroupHopping;
	struct SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_sequenceHopping_e_sequenceHopping_Optional sequenceHopping;
	struct SQN_NR_SetupRelease_DMRS_UplinkConfig_transformPrecodingEnabled_dmrs_UplinkTransformPrecoding_r16_SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_dmrs_UplinkTransformPrecoding_r16_Optional dmrs_UplinkTransformPrecoding_r16;
};

struct SQN_NR_DMRS_UplinkConfig_dmrs_Type_e_dmrs_Type_Optional {
	bool d;
	SQN_NR_DMRS_UplinkConfig_dmrs_Type_e v;
};

struct SQN_NR_DMRS_UplinkConfig_dmrs_AdditionalPosition_e_dmrs_AdditionalPosition_Optional {
	bool d;
	SQN_NR_DMRS_UplinkConfig_dmrs_AdditionalPosition_e v;
};

struct SQN_NR_SetupRelease_DMRS_UplinkConfig_phaseTrackingRS_SQN_NR_DMRS_UplinkConfig_phaseTrackingRS_Optional {
	bool d;
	struct SQN_NR_SetupRelease_DMRS_UplinkConfig_phaseTrackingRS v;
};

struct SQN_NR_DMRS_UplinkConfig_maxLength_e_maxLength_Optional {
	bool d;
	SQN_NR_DMRS_UplinkConfig_maxLength_e v;
};

struct SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled_transformPrecodingDisabled_Optional {
	bool d;
	struct SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled v;
};

struct SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_transformPrecodingEnabled_Optional {
	bool d;
	struct SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled v;
};

struct SQN_NR_DMRS_UplinkConfig {
	struct SQN_NR_DMRS_UplinkConfig_dmrs_Type_e_dmrs_Type_Optional dmrs_Type;
	struct SQN_NR_DMRS_UplinkConfig_dmrs_AdditionalPosition_e_dmrs_AdditionalPosition_Optional dmrs_AdditionalPosition;
	struct SQN_NR_SetupRelease_DMRS_UplinkConfig_phaseTrackingRS_SQN_NR_DMRS_UplinkConfig_phaseTrackingRS_Optional phaseTrackingRS;
	struct SQN_NR_DMRS_UplinkConfig_maxLength_e_maxLength_Optional maxLength;
	struct SQN_NR_DMRS_UplinkConfig_transformPrecodingDisabled_transformPrecodingDisabled_Optional transformPrecodingDisabled;
	struct SQN_NR_DMRS_UplinkConfig_transformPrecodingEnabled_transformPrecodingEnabled_Optional transformPrecodingEnabled;
};

enum SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_Value {
	Null release;
	struct SQN_NR_DMRS_UplinkConfig setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA {
	enum SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_Value v;
};

enum SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_Value {
	Null release;
	struct SQN_NR_DMRS_UplinkConfig setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB {
	enum SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_Value v;
};

enum SQN_NR_PUSCH_PowerControl_tpc_Accumulation_e {
	SQN_NR_PUSCH_PowerControl_tpc_Accumulation_e_disabled = 0,
};

typedef enum SQN_NR_PUSCH_PowerControl_tpc_Accumulation_e SQN_NR_PUSCH_PowerControl_tpc_Accumulation_e;

enum SQN_NR_Alpha_e {
	SQN_NR_Alpha_e_alpha0 = 0,
	SQN_NR_Alpha_e_alpha04 = 1,
	SQN_NR_Alpha_e_alpha05 = 2,
	SQN_NR_Alpha_e_alpha06 = 3,
	SQN_NR_Alpha_e_alpha07 = 4,
	SQN_NR_Alpha_e_alpha08 = 5,
	SQN_NR_Alpha_e_alpha09 = 6,
	SQN_NR_Alpha_e_alpha1 = 7,
};

typedef enum SQN_NR_Alpha_e SQN_NR_Alpha_e;

typedef uint8_t SQN_NR_P0_PUSCH_AlphaSetId;

struct int8_t_SQN_NR_P0_PUSCH_AlphaSet_p0_Optional {
	bool d;
	int8_t v;
};

struct SQN_NR_Alpha_e_SQN_NR_P0_PUSCH_AlphaSet_alpha_Optional {
	bool d;
	SQN_NR_Alpha_e v;
};

struct SQN_NR_P0_PUSCH_AlphaSet {
	SQN_NR_P0_PUSCH_AlphaSetId p0_PUSCH_AlphaSetId;
	struct int8_t_SQN_NR_P0_PUSCH_AlphaSet_p0_Optional p0;
	struct SQN_NR_Alpha_e_SQN_NR_P0_PUSCH_AlphaSet_alpha_Optional alpha;
};

typedef uint8_t SQN_NR_PUSCH_PathlossReferenceRS_Id;

enum SQN_NR_PUSCH_PathlossReferenceRS_referenceSignal_Sel {
	SQN_NR_PUSCH_PathlossReferenceRS_referenceSignal_UNBOUND_VALUE = 0,
	SQN_NR_PUSCH_PathlossReferenceRS_referenceSignal_ssb_Index = 1,
	SQN_NR_PUSCH_PathlossReferenceRS_referenceSignal_csi_RS_Index = 2,
};

union SQN_NR_PUSCH_PathlossReferenceRS_referenceSignal_Value {
	SQN_NR_SSB_Index ssb_Index;
	SQN_NR_NZP_CSI_RS_ResourceId csi_RS_Index;
};

struct SQN_NR_PUSCH_PathlossReferenceRS_referenceSignal {
	enum SQN_NR_PUSCH_PathlossReferenceRS_referenceSignal_Sel d;
	union SQN_NR_PUSCH_PathlossReferenceRS_referenceSignal_Value v;
};

struct SQN_NR_PUSCH_PathlossReferenceRS {
	SQN_NR_PUSCH_PathlossReferenceRS_Id pusch_PathlossReferenceRS_Id;
	struct SQN_NR_PUSCH_PathlossReferenceRS_referenceSignal referenceSignal;
};

enum SQN_NR_PUSCH_PowerControl_twoPUSCH_PC_AdjustmentStates_e {
	SQN_NR_PUSCH_PowerControl_twoPUSCH_PC_AdjustmentStates_e_twoStates = 0,
};

typedef enum SQN_NR_PUSCH_PowerControl_twoPUSCH_PC_AdjustmentStates_e SQN_NR_PUSCH_PowerControl_twoPUSCH_PC_AdjustmentStates_e;

enum SQN_NR_PUSCH_PowerControl_deltaMCS_e {
	SQN_NR_PUSCH_PowerControl_deltaMCS_e_enabled = 0,
};

typedef enum SQN_NR_PUSCH_PowerControl_deltaMCS_e SQN_NR_PUSCH_PowerControl_deltaMCS_e;

typedef uint8_t SQN_NR_SRI_PUSCH_PowerControlId;

enum SQN_NR_SRI_PUSCH_PowerControl_sri_PUSCH_ClosedLoopIndex_e {
	SQN_NR_SRI_PUSCH_PowerControl_sri_PUSCH_ClosedLoopIndex_e_i0 = 0,
	SQN_NR_SRI_PUSCH_PowerControl_sri_PUSCH_ClosedLoopIndex_e_i1 = 1,
};

typedef enum SQN_NR_SRI_PUSCH_PowerControl_sri_PUSCH_ClosedLoopIndex_e SQN_NR_SRI_PUSCH_PowerControl_sri_PUSCH_ClosedLoopIndex_e;

struct SQN_NR_SRI_PUSCH_PowerControl {
	SQN_NR_SRI_PUSCH_PowerControlId sri_PUSCH_PowerControlId;
	SQN_NR_PUSCH_PathlossReferenceRS_Id sri_PUSCH_PathlossReferenceRS_Id;
	SQN_NR_P0_PUSCH_AlphaSetId sri_P0_PUSCH_AlphaSetId;
	SQN_NR_SRI_PUSCH_PowerControl_sri_PUSCH_ClosedLoopIndex_e sri_PUSCH_ClosedLoopIndex;
};

struct SQN_NR_PUSCH_PowerControl_tpc_Accumulation_e_tpc_Accumulation_Optional {
	bool d;
	SQN_NR_PUSCH_PowerControl_tpc_Accumulation_e v;
};

struct SQN_NR_Alpha_e_SQN_NR_PUSCH_PowerControl_msg3_Alpha_Optional {
	bool d;
	SQN_NR_Alpha_e v;
};

struct int16_t_SQN_NR_PUSCH_PowerControl_p0_NominalWithoutGrant_Optional {
	bool d;
	int16_t v;
};

struct SQN_NR_PUSCH_PowerControl_SQN_NR_P0_PUSCH_AlphaSet_p0_AlphaSets_Dynamic {
	size_t d;
	struct SQN_NR_P0_PUSCH_AlphaSet* v;
};

struct SQN_NR_P0_PUSCH_AlphaSet_SQN_NR_PUSCH_PowerControl_p0_AlphaSets_DynamicOptional {
	bool d;
	struct SQN_NR_PUSCH_PowerControl_SQN_NR_P0_PUSCH_AlphaSet_p0_AlphaSets_Dynamic v;
};

struct SQN_NR_PUSCH_PowerControl_SQN_NR_PUSCH_PathlossReferenceRS_pathlossReferenceRSToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_PUSCH_PathlossReferenceRS* v;
};

struct SQN_NR_PUSCH_PathlossReferenceRS_SQN_NR_PUSCH_PowerControl_pathlossReferenceRSToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_PUSCH_PowerControl_SQN_NR_PUSCH_PathlossReferenceRS_pathlossReferenceRSToAddModList_Dynamic v;
};

struct SQN_NR_PUSCH_PathlossReferenceRS_Id_SQN_NR_PUSCH_PowerControl_pathlossReferenceRSToReleaseList_Dynamic {
	size_t d;
	SQN_NR_PUSCH_PathlossReferenceRS_Id* v;
};

struct SQN_NR_PUSCH_PathlossReferenceRS_Id_SQN_NR_PUSCH_PowerControl_pathlossReferenceRSToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_PUSCH_PathlossReferenceRS_Id_SQN_NR_PUSCH_PowerControl_pathlossReferenceRSToReleaseList_Dynamic v;
};

struct SQN_NR_PUSCH_PowerControl_twoPUSCH_PC_AdjustmentStates_e_twoPUSCH_PC_AdjustmentStates_Optional {
	bool d;
	SQN_NR_PUSCH_PowerControl_twoPUSCH_PC_AdjustmentStates_e v;
};

struct SQN_NR_PUSCH_PowerControl_deltaMCS_e_deltaMCS_Optional {
	bool d;
	SQN_NR_PUSCH_PowerControl_deltaMCS_e v;
};

struct SQN_NR_PUSCH_PowerControl_SQN_NR_SRI_PUSCH_PowerControl_sri_PUSCH_MappingToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_SRI_PUSCH_PowerControl* v;
};

struct SQN_NR_SRI_PUSCH_PowerControl_SQN_NR_PUSCH_PowerControl_sri_PUSCH_MappingToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_PUSCH_PowerControl_SQN_NR_SRI_PUSCH_PowerControl_sri_PUSCH_MappingToAddModList_Dynamic v;
};

struct SQN_NR_SRI_PUSCH_PowerControlId_SQN_NR_PUSCH_PowerControl_sri_PUSCH_MappingToReleaseList_Dynamic {
	size_t d;
	SQN_NR_SRI_PUSCH_PowerControlId* v;
};

struct SQN_NR_SRI_PUSCH_PowerControlId_SQN_NR_PUSCH_PowerControl_sri_PUSCH_MappingToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_SRI_PUSCH_PowerControlId_SQN_NR_PUSCH_PowerControl_sri_PUSCH_MappingToReleaseList_Dynamic v;
};

struct SQN_NR_PUSCH_PowerControl {
	struct SQN_NR_PUSCH_PowerControl_tpc_Accumulation_e_tpc_Accumulation_Optional tpc_Accumulation;
	struct SQN_NR_Alpha_e_SQN_NR_PUSCH_PowerControl_msg3_Alpha_Optional msg3_Alpha;
	struct int16_t_SQN_NR_PUSCH_PowerControl_p0_NominalWithoutGrant_Optional p0_NominalWithoutGrant;
	struct SQN_NR_P0_PUSCH_AlphaSet_SQN_NR_PUSCH_PowerControl_p0_AlphaSets_DynamicOptional p0_AlphaSets;
	struct SQN_NR_PUSCH_PathlossReferenceRS_SQN_NR_PUSCH_PowerControl_pathlossReferenceRSToAddModList_DynamicOptional pathlossReferenceRSToAddModList;
	struct SQN_NR_PUSCH_PathlossReferenceRS_Id_SQN_NR_PUSCH_PowerControl_pathlossReferenceRSToReleaseList_DynamicOptional pathlossReferenceRSToReleaseList;
	struct SQN_NR_PUSCH_PowerControl_twoPUSCH_PC_AdjustmentStates_e_twoPUSCH_PC_AdjustmentStates_Optional twoPUSCH_PC_AdjustmentStates;
	struct SQN_NR_PUSCH_PowerControl_deltaMCS_e_deltaMCS_Optional deltaMCS;
	struct SQN_NR_SRI_PUSCH_PowerControl_SQN_NR_PUSCH_PowerControl_sri_PUSCH_MappingToAddModList_DynamicOptional sri_PUSCH_MappingToAddModList;
	struct SQN_NR_SRI_PUSCH_PowerControlId_SQN_NR_PUSCH_PowerControl_sri_PUSCH_MappingToReleaseList_DynamicOptional sri_PUSCH_MappingToReleaseList;
};

enum SQN_NR_PUSCH_Config_frequencyHopping_e {
	SQN_NR_PUSCH_Config_frequencyHopping_e_intraSlot = 0,
	SQN_NR_PUSCH_Config_frequencyHopping_e_interSlot = 1,
};

typedef enum SQN_NR_PUSCH_Config_frequencyHopping_e SQN_NR_PUSCH_Config_frequencyHopping_e;

enum SQN_NR_PUSCH_Config_resourceAllocation_e {
	SQN_NR_PUSCH_Config_resourceAllocation_e_resourceAllocationType0 = 0,
	SQN_NR_PUSCH_Config_resourceAllocation_e_resourceAllocationType1 = 1,
	SQN_NR_PUSCH_Config_resourceAllocation_e_dynamicSwitch = 2,
};

typedef enum SQN_NR_PUSCH_Config_resourceAllocation_e SQN_NR_PUSCH_Config_resourceAllocation_e;

enum SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationList_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationList_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationList_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationList_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationList_Value {
	Null release;
	SQN_NR_PUSCH_TimeDomainResourceAllocationList setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationList {
	enum SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationList_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationList_Value v;
};

enum SQN_NR_PUSCH_Config_pusch_AggregationFactor_e {
	SQN_NR_PUSCH_Config_pusch_AggregationFactor_e_n2 = 0,
	SQN_NR_PUSCH_Config_pusch_AggregationFactor_e_n4 = 1,
	SQN_NR_PUSCH_Config_pusch_AggregationFactor_e_n8 = 2,
};

typedef enum SQN_NR_PUSCH_Config_pusch_AggregationFactor_e SQN_NR_PUSCH_Config_pusch_AggregationFactor_e;

enum SQN_NR_PUSCH_Config_mcs_Table_e {
	SQN_NR_PUSCH_Config_mcs_Table_e_qam256 = 0,
	SQN_NR_PUSCH_Config_mcs_Table_e_qam64LowSE = 1,
};

typedef enum SQN_NR_PUSCH_Config_mcs_Table_e SQN_NR_PUSCH_Config_mcs_Table_e;

enum SQN_NR_PUSCH_Config_mcs_TableTransformPrecoder_e {
	SQN_NR_PUSCH_Config_mcs_TableTransformPrecoder_e_qam256 = 0,
	SQN_NR_PUSCH_Config_mcs_TableTransformPrecoder_e_qam64LowSE = 1,
};

typedef enum SQN_NR_PUSCH_Config_mcs_TableTransformPrecoder_e SQN_NR_PUSCH_Config_mcs_TableTransformPrecoder_e;

enum SQN_NR_PUSCH_Config_transformPrecoder_e {
	SQN_NR_PUSCH_Config_transformPrecoder_e_enabled = 0,
	SQN_NR_PUSCH_Config_transformPrecoder_e_disabled = 1,
};

typedef enum SQN_NR_PUSCH_Config_transformPrecoder_e SQN_NR_PUSCH_Config_transformPrecoder_e;

enum SQN_NR_PUSCH_Config_codebookSubset_e {
	SQN_NR_PUSCH_Config_codebookSubset_e_fullyAndPartialAndNonCoherent = 0,
	SQN_NR_PUSCH_Config_codebookSubset_e_partialAndNonCoherent = 1,
	SQN_NR_PUSCH_Config_codebookSubset_e_nonCoherent = 2,
};

typedef enum SQN_NR_PUSCH_Config_codebookSubset_e SQN_NR_PUSCH_Config_codebookSubset_e;

enum SQN_NR_PUSCH_Config_rbg_Size_e {
	SQN_NR_PUSCH_Config_rbg_Size_e_config2 = 0,
};

typedef enum SQN_NR_PUSCH_Config_rbg_Size_e SQN_NR_PUSCH_Config_rbg_Size_e;

struct uint8_t_SQN_NR_BetaOffsets_betaOffsetACK_Index1_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_BetaOffsets_betaOffsetACK_Index2_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_BetaOffsets_betaOffsetACK_Index3_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_BetaOffsets_betaOffsetCSI_Part1_Index1_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_BetaOffsets_betaOffsetCSI_Part1_Index2_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_BetaOffsets_betaOffsetCSI_Part2_Index1_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_BetaOffsets_betaOffsetCSI_Part2_Index2_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_BetaOffsets {
	struct uint8_t_SQN_NR_BetaOffsets_betaOffsetACK_Index1_Optional betaOffsetACK_Index1;
	struct uint8_t_SQN_NR_BetaOffsets_betaOffsetACK_Index2_Optional betaOffsetACK_Index2;
	struct uint8_t_SQN_NR_BetaOffsets_betaOffsetACK_Index3_Optional betaOffsetACK_Index3;
	struct uint8_t_SQN_NR_BetaOffsets_betaOffsetCSI_Part1_Index1_Optional betaOffsetCSI_Part1_Index1;
	struct uint8_t_SQN_NR_BetaOffsets_betaOffsetCSI_Part1_Index2_Optional betaOffsetCSI_Part1_Index2;
	struct uint8_t_SQN_NR_BetaOffsets_betaOffsetCSI_Part2_Index1_Optional betaOffsetCSI_Part2_Index1;
	struct uint8_t_SQN_NR_BetaOffsets_betaOffsetCSI_Part2_Index2_Optional betaOffsetCSI_Part2_Index2;
};

enum SQN_NR_UCI_OnPUSCH_betaOffsets_Sel {
	SQN_NR_UCI_OnPUSCH_betaOffsets_UNBOUND_VALUE = 0,
	SQN_NR_UCI_OnPUSCH_betaOffsets_dynamic = 1,
	SQN_NR_UCI_OnPUSCH_betaOffsets_semiStatic = 2,
};

union SQN_NR_UCI_OnPUSCH_betaOffsets_Value {
	struct SQN_NR_BetaOffsets dynamic[4];
	struct SQN_NR_BetaOffsets semiStatic;
};

struct SQN_NR_UCI_OnPUSCH_betaOffsets {
	enum SQN_NR_UCI_OnPUSCH_betaOffsets_Sel d;
	union SQN_NR_UCI_OnPUSCH_betaOffsets_Value v;
};

enum SQN_NR_UCI_OnPUSCH_scaling_e {
	SQN_NR_UCI_OnPUSCH_scaling_e_f0p5 = 0,
	SQN_NR_UCI_OnPUSCH_scaling_e_f0p65 = 1,
	SQN_NR_UCI_OnPUSCH_scaling_e_f0p8 = 2,
	SQN_NR_UCI_OnPUSCH_scaling_e_f1 = 3,
};

typedef enum SQN_NR_UCI_OnPUSCH_scaling_e SQN_NR_UCI_OnPUSCH_scaling_e;

struct SQN_NR_UCI_OnPUSCH_betaOffsets_betaOffsets_Optional {
	bool d;
	struct SQN_NR_UCI_OnPUSCH_betaOffsets v;
};

struct SQN_NR_UCI_OnPUSCH {
	struct SQN_NR_UCI_OnPUSCH_betaOffsets_betaOffsets_Optional betaOffsets;
	SQN_NR_UCI_OnPUSCH_scaling_e scaling;
};

enum SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_Value {
	Null release;
	struct SQN_NR_UCI_OnPUSCH setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH {
	enum SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_Value v;
};

enum SQN_NR_PUSCH_Config_tp_pi2BPSK_e {
	SQN_NR_PUSCH_Config_tp_pi2BPSK_e_enabled = 0,
};

typedef enum SQN_NR_PUSCH_Config_tp_pi2BPSK_e SQN_NR_PUSCH_Config_tp_pi2BPSK_e;

struct uint8_t_SQN_NR_MinSchedulingOffsetK2_Values_r16_Dynamic {
	size_t d;
	uint8_t* v;
};

typedef struct uint8_t_SQN_NR_MinSchedulingOffsetK2_Values_r16_Dynamic SQN_NR_MinSchedulingOffsetK2_Values_r16;

enum SQN_NR_SetupRelease_PUSCH_Config_minimumSchedulingOffsetK2_r16_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_minimumSchedulingOffsetK2_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_minimumSchedulingOffsetK2_r16_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_minimumSchedulingOffsetK2_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_minimumSchedulingOffsetK2_r16_Value {
	Null release;
	SQN_NR_MinSchedulingOffsetK2_Values_r16 setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_minimumSchedulingOffsetK2_r16 {
	enum SQN_NR_SetupRelease_PUSCH_Config_minimumSchedulingOffsetK2_r16_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_minimumSchedulingOffsetK2_r16_Value v;
};

struct uint8_t_SQN_NR_UL_AccessConfigListDCI_0_1_r16_Dynamic {
	size_t d;
	uint8_t* v;
};

typedef struct uint8_t_SQN_NR_UL_AccessConfigListDCI_0_1_r16_Dynamic SQN_NR_UL_AccessConfigListDCI_0_1_r16;

enum SQN_NR_SetupRelease_PUSCH_Config_ul_AccessConfigListDCI_0_1_r16_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_ul_AccessConfigListDCI_0_1_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_ul_AccessConfigListDCI_0_1_r16_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_ul_AccessConfigListDCI_0_1_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_ul_AccessConfigListDCI_0_1_r16_Value {
	Null release;
	SQN_NR_UL_AccessConfigListDCI_0_1_r16 setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_ul_AccessConfigListDCI_0_1_r16 {
	enum SQN_NR_SetupRelease_PUSCH_Config_ul_AccessConfigListDCI_0_1_r16_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_ul_AccessConfigListDCI_0_1_r16_Value v;
};

enum SQN_NR_PUSCH_Config_dmrs_SequenceInitializationDCI_0_2_r16_e {
	SQN_NR_PUSCH_Config_dmrs_SequenceInitializationDCI_0_2_r16_e_enabled = 0,
};

typedef enum SQN_NR_PUSCH_Config_dmrs_SequenceInitializationDCI_0_2_r16_e SQN_NR_PUSCH_Config_dmrs_SequenceInitializationDCI_0_2_r16_e;

enum SQN_NR_PUSCH_Config_antennaPortsFieldPresenceDCI_0_2_r16_e {
	SQN_NR_PUSCH_Config_antennaPortsFieldPresenceDCI_0_2_r16_e_enabled = 0,
};

typedef enum SQN_NR_PUSCH_Config_antennaPortsFieldPresenceDCI_0_2_r16_e SQN_NR_PUSCH_Config_antennaPortsFieldPresenceDCI_0_2_r16_e;

enum SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_DCI_0_2_r16_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_DCI_0_2_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_DCI_0_2_r16_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_DCI_0_2_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_DCI_0_2_r16_Value {
	Null release;
	struct SQN_NR_DMRS_UplinkConfig setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_DCI_0_2_r16 {
	enum SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_DCI_0_2_r16_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_DCI_0_2_r16_Value v;
};

enum SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_DCI_0_2_r16_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_DCI_0_2_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_DCI_0_2_r16_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_DCI_0_2_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_DCI_0_2_r16_Value {
	Null release;
	struct SQN_NR_DMRS_UplinkConfig setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_DCI_0_2_r16 {
	enum SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_DCI_0_2_r16_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_DCI_0_2_r16_Value v;
};

enum SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_pusch_RepTypeA_e {
	SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_pusch_RepTypeA_e_intraSlot = 0,
	SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_pusch_RepTypeA_e_interSlot = 1,
};

typedef enum SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_pusch_RepTypeA_e SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_pusch_RepTypeA_e;

enum SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_pusch_RepTypeB_e {
	SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_pusch_RepTypeB_e_interRepetition = 0,
	SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_pusch_RepTypeB_e_interSlot = 1,
};

typedef enum SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_pusch_RepTypeB_e SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_pusch_RepTypeB_e;

enum SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_Sel {
	SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_UNBOUND_VALUE = 0,
	SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_pusch_RepTypeA = 1,
	SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_pusch_RepTypeB = 2,
};

union SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_Value {
	SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_pusch_RepTypeA_e pusch_RepTypeA;
	SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_pusch_RepTypeB_e pusch_RepTypeB;
};

struct SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16 {
	enum SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_Sel d;
	union SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_Value v;
};

struct uint16_t_SQN_NR_FrequencyHoppingOffsetListsDCI_0_2_r16_Dynamic {
	size_t d;
	uint16_t* v;
};

typedef struct uint16_t_SQN_NR_FrequencyHoppingOffsetListsDCI_0_2_r16_Dynamic SQN_NR_FrequencyHoppingOffsetListsDCI_0_2_r16;

enum SQN_NR_SetupRelease_PUSCH_Config_frequencyHoppingOffsetListsDCI_0_2_r16_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_frequencyHoppingOffsetListsDCI_0_2_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_frequencyHoppingOffsetListsDCI_0_2_r16_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_frequencyHoppingOffsetListsDCI_0_2_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_frequencyHoppingOffsetListsDCI_0_2_r16_Value {
	Null release;
	SQN_NR_FrequencyHoppingOffsetListsDCI_0_2_r16 setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_frequencyHoppingOffsetListsDCI_0_2_r16 {
	enum SQN_NR_SetupRelease_PUSCH_Config_frequencyHoppingOffsetListsDCI_0_2_r16_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_frequencyHoppingOffsetListsDCI_0_2_r16_Value v;
};

enum SQN_NR_PUSCH_Config_codebookSubsetDCI_0_2_r16_e {
	SQN_NR_PUSCH_Config_codebookSubsetDCI_0_2_r16_e_fullyAndPartialAndNonCoherent = 0,
	SQN_NR_PUSCH_Config_codebookSubsetDCI_0_2_r16_e_partialAndNonCoherent = 1,
	SQN_NR_PUSCH_Config_codebookSubsetDCI_0_2_r16_e_nonCoherent = 2,
};

typedef enum SQN_NR_PUSCH_Config_codebookSubsetDCI_0_2_r16_e SQN_NR_PUSCH_Config_codebookSubsetDCI_0_2_r16_e;

enum SQN_NR_PUSCH_Config_invalidSymbolPatternIndicatorDCI_0_2_r16_e {
	SQN_NR_PUSCH_Config_invalidSymbolPatternIndicatorDCI_0_2_r16_e_enabled = 0,
};

typedef enum SQN_NR_PUSCH_Config_invalidSymbolPatternIndicatorDCI_0_2_r16_e SQN_NR_PUSCH_Config_invalidSymbolPatternIndicatorDCI_0_2_r16_e;

enum SQN_NR_PUSCH_Config_mcs_TableDCI_0_2_r16_e {
	SQN_NR_PUSCH_Config_mcs_TableDCI_0_2_r16_e_qam256 = 0,
	SQN_NR_PUSCH_Config_mcs_TableDCI_0_2_r16_e_qam64LowSE = 1,
};

typedef enum SQN_NR_PUSCH_Config_mcs_TableDCI_0_2_r16_e SQN_NR_PUSCH_Config_mcs_TableDCI_0_2_r16_e;

enum SQN_NR_PUSCH_Config_mcs_TableTransformPrecoderDCI_0_2_r16_e {
	SQN_NR_PUSCH_Config_mcs_TableTransformPrecoderDCI_0_2_r16_e_qam256 = 0,
	SQN_NR_PUSCH_Config_mcs_TableTransformPrecoderDCI_0_2_r16_e_qam64LowSE = 1,
};

typedef enum SQN_NR_PUSCH_Config_mcs_TableTransformPrecoderDCI_0_2_r16_e SQN_NR_PUSCH_Config_mcs_TableTransformPrecoderDCI_0_2_r16_e;

enum SQN_NR_PUSCH_Config_priorityIndicatorDCI_0_2_r16_e {
	SQN_NR_PUSCH_Config_priorityIndicatorDCI_0_2_r16_e_enabled = 0,
};

typedef enum SQN_NR_PUSCH_Config_priorityIndicatorDCI_0_2_r16_e SQN_NR_PUSCH_Config_priorityIndicatorDCI_0_2_r16_e;

enum SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_2_r16_e {
	SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_2_r16_e_pusch_RepTypeA = 0,
	SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_2_r16_e_pusch_RepTypeB = 1,
};

typedef enum SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_2_r16_e SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_2_r16_e;

enum SQN_NR_PUSCH_Config_resourceAllocationDCI_0_2_r16_e {
	SQN_NR_PUSCH_Config_resourceAllocationDCI_0_2_r16_e_resourceAllocationType0 = 0,
	SQN_NR_PUSCH_Config_resourceAllocationDCI_0_2_r16_e_resourceAllocationType1 = 1,
	SQN_NR_PUSCH_Config_resourceAllocationDCI_0_2_r16_e_dynamicSwitch = 2,
};

typedef enum SQN_NR_PUSCH_Config_resourceAllocationDCI_0_2_r16_e SQN_NR_PUSCH_Config_resourceAllocationDCI_0_2_r16_e;

enum SQN_NR_PUSCH_Config_resourceAllocationType1GranularityDCI_0_2_r16_e {
	SQN_NR_PUSCH_Config_resourceAllocationType1GranularityDCI_0_2_r16_e_n2 = 0,
	SQN_NR_PUSCH_Config_resourceAllocationType1GranularityDCI_0_2_r16_e_n4 = 1,
	SQN_NR_PUSCH_Config_resourceAllocationType1GranularityDCI_0_2_r16_e_n8 = 2,
	SQN_NR_PUSCH_Config_resourceAllocationType1GranularityDCI_0_2_r16_e_n16 = 3,
};

typedef enum SQN_NR_PUSCH_Config_resourceAllocationType1GranularityDCI_0_2_r16_e SQN_NR_PUSCH_Config_resourceAllocationType1GranularityDCI_0_2_r16_e;

enum SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_dynamicDCI_0_2_r16_Sel {
	SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_dynamicDCI_0_2_r16_UNBOUND_VALUE = 0,
	SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_dynamicDCI_0_2_r16_oneBit_r16 = 1,
	SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_dynamicDCI_0_2_r16_twoBits_r16 = 2,
};

union SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_dynamicDCI_0_2_r16_Value {
	struct SQN_NR_BetaOffsets oneBit_r16[2];
	struct SQN_NR_BetaOffsets twoBits_r16[4];
};

struct SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_dynamicDCI_0_2_r16 {
	enum SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_dynamicDCI_0_2_r16_Sel d;
	union SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_dynamicDCI_0_2_r16_Value v;
};

enum SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_Sel {
	SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_UNBOUND_VALUE = 0,
	SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_dynamicDCI_0_2_r16 = 1,
	SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_semiStaticDCI_0_2_r16 = 2,
};

union SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_Value {
	struct SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_dynamicDCI_0_2_r16 dynamicDCI_0_2_r16;
	struct SQN_NR_BetaOffsets semiStaticDCI_0_2_r16;
};

struct SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16 {
	enum SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_Sel d;
	union SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_Value v;
};

enum SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_scalingDCI_0_2_r16_e {
	SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_scalingDCI_0_2_r16_e_f0p5 = 0,
	SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_scalingDCI_0_2_r16_e_f0p65 = 1,
	SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_scalingDCI_0_2_r16_e_f0p8 = 2,
	SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_scalingDCI_0_2_r16_e_f1 = 3,
};

typedef enum SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_scalingDCI_0_2_r16_e SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_scalingDCI_0_2_r16_e;

struct SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_betaOffsetsDCI_0_2_r16_Optional {
	bool d;
	struct SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16 v;
};

struct SQN_NR_UCI_OnPUSCH_DCI_0_2_r16 {
	struct SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_betaOffsetsDCI_0_2_r16_betaOffsetsDCI_0_2_r16_Optional betaOffsetsDCI_0_2_r16;
	SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_scalingDCI_0_2_r16_e scalingDCI_0_2_r16;
};

struct SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_SQN_NR_UCI_OnPUSCH_ListDCI_0_2_r16_Dynamic {
	size_t d;
	struct SQN_NR_UCI_OnPUSCH_DCI_0_2_r16* v;
};

typedef struct SQN_NR_UCI_OnPUSCH_DCI_0_2_r16_SQN_NR_UCI_OnPUSCH_ListDCI_0_2_r16_Dynamic SQN_NR_UCI_OnPUSCH_ListDCI_0_2_r16;

enum SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_2_r16_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_2_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_2_r16_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_2_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_2_r16_Value {
	Null release;
	SQN_NR_UCI_OnPUSCH_ListDCI_0_2_r16 setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_2_r16 {
	enum SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_2_r16_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_2_r16_Value v;
};

enum SQN_NR_PUSCH_Allocation_r16_mappingType_r16_e {
	SQN_NR_PUSCH_Allocation_r16_mappingType_r16_e_typeA = 0,
	SQN_NR_PUSCH_Allocation_r16_mappingType_r16_e_typeB = 1,
};

typedef enum SQN_NR_PUSCH_Allocation_r16_mappingType_r16_e SQN_NR_PUSCH_Allocation_r16_mappingType_r16_e;

enum SQN_NR_PUSCH_Allocation_r16_numberOfRepetitions_r16_e {
	SQN_NR_PUSCH_Allocation_r16_numberOfRepetitions_r16_e_n1 = 0,
	SQN_NR_PUSCH_Allocation_r16_numberOfRepetitions_r16_e_n2 = 1,
	SQN_NR_PUSCH_Allocation_r16_numberOfRepetitions_r16_e_n3 = 2,
	SQN_NR_PUSCH_Allocation_r16_numberOfRepetitions_r16_e_n4 = 3,
	SQN_NR_PUSCH_Allocation_r16_numberOfRepetitions_r16_e_n7 = 4,
	SQN_NR_PUSCH_Allocation_r16_numberOfRepetitions_r16_e_n8 = 5,
	SQN_NR_PUSCH_Allocation_r16_numberOfRepetitions_r16_e_n12 = 6,
	SQN_NR_PUSCH_Allocation_r16_numberOfRepetitions_r16_e_n16 = 7,
};

typedef enum SQN_NR_PUSCH_Allocation_r16_numberOfRepetitions_r16_e SQN_NR_PUSCH_Allocation_r16_numberOfRepetitions_r16_e;

struct SQN_NR_PUSCH_Allocation_r16_mappingType_r16_e_mappingType_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Allocation_r16_mappingType_r16_e v;
};

struct uint8_t_SQN_NR_PUSCH_Allocation_r16_startSymbolAndLength_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_PUSCH_Allocation_r16_startSymbol_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_PUSCH_Allocation_r16_length_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PUSCH_Allocation_r16_numberOfRepetitions_r16_e_numberOfRepetitions_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Allocation_r16_numberOfRepetitions_r16_e v;
};

struct SQN_NR_PUSCH_Allocation_r16 {
	struct SQN_NR_PUSCH_Allocation_r16_mappingType_r16_e_mappingType_r16_Optional mappingType_r16;
	struct uint8_t_SQN_NR_PUSCH_Allocation_r16_startSymbolAndLength_r16_Optional startSymbolAndLength_r16;
	struct uint8_t_SQN_NR_PUSCH_Allocation_r16_startSymbol_r16_Optional startSymbol_r16;
	struct uint8_t_SQN_NR_PUSCH_Allocation_r16_length_r16_Optional length_r16;
	struct SQN_NR_PUSCH_Allocation_r16_numberOfRepetitions_r16_e_numberOfRepetitions_r16_Optional numberOfRepetitions_r16;
};

struct uint8_t_SQN_NR_PUSCH_TimeDomainResourceAllocation_r16_k2_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PUSCH_Allocation_r16_SQN_NR_PUSCH_TimeDomainResourceAllocation_r16_puschAllocationList_r16_Dynamic {
	size_t d;
	struct SQN_NR_PUSCH_Allocation_r16* v;
};

struct SQN_NR_PUSCH_TimeDomainResourceAllocation_r16 {
	struct uint8_t_SQN_NR_PUSCH_TimeDomainResourceAllocation_r16_k2_r16_Optional k2_r16;
	struct SQN_NR_PUSCH_Allocation_r16_SQN_NR_PUSCH_TimeDomainResourceAllocation_r16_puschAllocationList_r16_Dynamic puschAllocationList_r16;
};

struct SQN_NR_PUSCH_TimeDomainResourceAllocation_r16_SQN_NR_PUSCH_TimeDomainResourceAllocationList_r16_Dynamic {
	size_t d;
	struct SQN_NR_PUSCH_TimeDomainResourceAllocation_r16* v;
};

typedef struct SQN_NR_PUSCH_TimeDomainResourceAllocation_r16_SQN_NR_PUSCH_TimeDomainResourceAllocationList_r16_Dynamic SQN_NR_PUSCH_TimeDomainResourceAllocationList_r16;

enum SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_2_r16_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_2_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_2_r16_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_2_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_2_r16_Value {
	Null release;
	SQN_NR_PUSCH_TimeDomainResourceAllocationList_r16 setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_2_r16 {
	enum SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_2_r16_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_2_r16_Value v;
};

enum SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_1_r16_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_1_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_1_r16_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_1_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_1_r16_Value {
	Null release;
	SQN_NR_PUSCH_TimeDomainResourceAllocationList_r16 setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_1_r16 {
	enum SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_1_r16_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_1_r16_Value v;
};

enum SQN_NR_PUSCH_Config_invalidSymbolPatternIndicatorDCI_0_1_r16_e {
	SQN_NR_PUSCH_Config_invalidSymbolPatternIndicatorDCI_0_1_r16_e_enabled = 0,
};

typedef enum SQN_NR_PUSCH_Config_invalidSymbolPatternIndicatorDCI_0_1_r16_e SQN_NR_PUSCH_Config_invalidSymbolPatternIndicatorDCI_0_1_r16_e;

enum SQN_NR_PUSCH_Config_priorityIndicatorDCI_0_1_r16_e {
	SQN_NR_PUSCH_Config_priorityIndicatorDCI_0_1_r16_e_enabled = 0,
};

typedef enum SQN_NR_PUSCH_Config_priorityIndicatorDCI_0_1_r16_e SQN_NR_PUSCH_Config_priorityIndicatorDCI_0_1_r16_e;

enum SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_1_r16_e {
	SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_1_r16_e_pusch_RepTypeA = 0,
	SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_1_r16_e_pusch_RepTypeB = 1,
};

typedef enum SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_1_r16_e SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_1_r16_e;

enum SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_1_r16_e {
	SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_1_r16_e_interRepetition = 0,
	SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_1_r16_e_interSlot = 1,
};

typedef enum SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_1_r16_e SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_1_r16_e;

struct SQN_NR_UCI_OnPUSCH_SQN_NR_UCI_OnPUSCH_ListDCI_0_1_r16_Dynamic {
	size_t d;
	struct SQN_NR_UCI_OnPUSCH* v;
};

typedef struct SQN_NR_UCI_OnPUSCH_SQN_NR_UCI_OnPUSCH_ListDCI_0_1_r16_Dynamic SQN_NR_UCI_OnPUSCH_ListDCI_0_1_r16;

enum SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_1_r16_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_1_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_1_r16_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_1_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_1_r16_Value {
	Null release;
	SQN_NR_UCI_OnPUSCH_ListDCI_0_1_r16 setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_1_r16 {
	enum SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_1_r16_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_1_r16_Value v;
};

enum SQN_NR_InvalidSymbolPattern_r16_symbols_r16_Sel {
	SQN_NR_InvalidSymbolPattern_r16_symbols_r16_UNBOUND_VALUE = 0,
	SQN_NR_InvalidSymbolPattern_r16_symbols_r16_oneSlot = 1,
	SQN_NR_InvalidSymbolPattern_r16_symbols_r16_twoSlots = 2,
};

union SQN_NR_InvalidSymbolPattern_r16_symbols_r16_Value {
	B14 oneSlot;
	B28 twoSlots;
};

struct SQN_NR_InvalidSymbolPattern_r16_symbols_r16 {
	enum SQN_NR_InvalidSymbolPattern_r16_symbols_r16_Sel d;
	union SQN_NR_InvalidSymbolPattern_r16_symbols_r16_Value v;
};

enum SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16_Sel {
	SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16_UNBOUND_VALUE = 0,
	SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16_n2 = 1,
	SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16_n4 = 2,
	SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16_n5 = 3,
	SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16_n8 = 4,
	SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16_n10 = 5,
	SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16_n20 = 6,
	SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16_n40 = 7,
};

union SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16_Value {
	B2 n2;
	B4 n4;
	B5 n5;
	B8 n8;
	B10 n10;
	B20 n20;
	B40 n40;
};

struct SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16 {
	enum SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16_Sel d;
	union SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16_Value v;
};

struct SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16_periodicityAndPattern_r16_Optional {
	bool d;
	struct SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16 v;
};

struct SQN_NR_InvalidSymbolPattern_r16 {
	struct SQN_NR_InvalidSymbolPattern_r16_symbols_r16 symbols_r16;
	struct SQN_NR_InvalidSymbolPattern_r16_periodicityAndPattern_r16_periodicityAndPattern_r16_Optional periodicityAndPattern_r16;
};

typedef uint8_t SQN_NR_PUSCH_PathlossReferenceRS_Id_v1610;

enum SQN_NR_PUSCH_PathlossReferenceRS_r16_referenceSignal_r16_Sel {
	SQN_NR_PUSCH_PathlossReferenceRS_r16_referenceSignal_r16_UNBOUND_VALUE = 0,
	SQN_NR_PUSCH_PathlossReferenceRS_r16_referenceSignal_r16_ssb_Index_r16 = 1,
	SQN_NR_PUSCH_PathlossReferenceRS_r16_referenceSignal_r16_csi_RS_Index_r16 = 2,
};

union SQN_NR_PUSCH_PathlossReferenceRS_r16_referenceSignal_r16_Value {
	SQN_NR_SSB_Index ssb_Index_r16;
	SQN_NR_NZP_CSI_RS_ResourceId csi_RS_Index_r16;
};

struct SQN_NR_PUSCH_PathlossReferenceRS_r16_referenceSignal_r16 {
	enum SQN_NR_PUSCH_PathlossReferenceRS_r16_referenceSignal_r16_Sel d;
	union SQN_NR_PUSCH_PathlossReferenceRS_r16_referenceSignal_r16_Value v;
};

struct SQN_NR_PUSCH_PathlossReferenceRS_r16 {
	SQN_NR_PUSCH_PathlossReferenceRS_Id_v1610 pusch_PathlossReferenceRS_Id_r16;
	struct SQN_NR_PUSCH_PathlossReferenceRS_r16_referenceSignal_r16 referenceSignal_r16;
};

typedef uint8_t SQN_NR_P0_PUSCH_SetId_r16;

typedef int8_t SQN_NR_P0_PUSCH_r16;

struct SQN_NR_P0_PUSCH_r16_SQN_NR_P0_PUSCH_Set_r16_p0_List_r16_Dynamic {
	size_t d;
	SQN_NR_P0_PUSCH_r16* v;
};

struct SQN_NR_P0_PUSCH_r16_SQN_NR_P0_PUSCH_Set_r16_p0_List_r16_DynamicOptional {
	bool d;
	struct SQN_NR_P0_PUSCH_r16_SQN_NR_P0_PUSCH_Set_r16_p0_List_r16_Dynamic v;
};

struct SQN_NR_P0_PUSCH_Set_r16 {
	SQN_NR_P0_PUSCH_SetId_r16 p0_PUSCH_SetId_r16;
	struct SQN_NR_P0_PUSCH_r16_SQN_NR_P0_PUSCH_Set_r16_p0_List_r16_DynamicOptional p0_List_r16;
};

struct uint8_t_SQN_NR_PUSCH_PowerControl_v1610_olpc_ParameterSet_olpc_ParameterSetDCI_0_1_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_PUSCH_PowerControl_v1610_olpc_ParameterSet_olpc_ParameterSetDCI_0_2_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PUSCH_PowerControl_v1610_olpc_ParameterSet {
	struct uint8_t_SQN_NR_PUSCH_PowerControl_v1610_olpc_ParameterSet_olpc_ParameterSetDCI_0_1_r16_Optional olpc_ParameterSetDCI_0_1_r16;
	struct uint8_t_SQN_NR_PUSCH_PowerControl_v1610_olpc_ParameterSet_olpc_ParameterSetDCI_0_2_r16_Optional olpc_ParameterSetDCI_0_2_r16;
};

struct SQN_NR_PUSCH_PowerControl_v1610_SQN_NR_PUSCH_PathlossReferenceRS_r16_pathlossReferenceRSToAddModList2_r16_Dynamic {
	size_t d;
	struct SQN_NR_PUSCH_PathlossReferenceRS_r16* v;
};

struct SQN_NR_PUSCH_PathlossReferenceRS_r16_SQN_NR_PUSCH_PowerControl_v1610_pathlossReferenceRSToAddModList2_r16_DynamicOptional {
	bool d;
	struct SQN_NR_PUSCH_PowerControl_v1610_SQN_NR_PUSCH_PathlossReferenceRS_r16_pathlossReferenceRSToAddModList2_r16_Dynamic v;
};

struct SQN_NR_PUSCH_PathlossReferenceRS_Id_v1610_SQN_NR_PUSCH_PowerControl_v1610_pathlossReferenceRSToReleaseList2_r16_Dynamic {
	size_t d;
	SQN_NR_PUSCH_PathlossReferenceRS_Id_v1610* v;
};

struct SQN_NR_PUSCH_PathlossReferenceRS_Id_v1610_SQN_NR_PUSCH_PowerControl_v1610_pathlossReferenceRSToReleaseList2_r16_DynamicOptional {
	bool d;
	struct SQN_NR_PUSCH_PathlossReferenceRS_Id_v1610_SQN_NR_PUSCH_PowerControl_v1610_pathlossReferenceRSToReleaseList2_r16_Dynamic v;
};

struct SQN_NR_PUSCH_PowerControl_v1610_SQN_NR_P0_PUSCH_Set_r16_p0_PUSCH_SetList_r16_Dynamic {
	size_t d;
	struct SQN_NR_P0_PUSCH_Set_r16* v;
};

struct SQN_NR_P0_PUSCH_Set_r16_SQN_NR_PUSCH_PowerControl_v1610_p0_PUSCH_SetList_r16_DynamicOptional {
	bool d;
	struct SQN_NR_PUSCH_PowerControl_v1610_SQN_NR_P0_PUSCH_Set_r16_p0_PUSCH_SetList_r16_Dynamic v;
};

struct SQN_NR_PUSCH_PowerControl_v1610_olpc_ParameterSet_olpc_ParameterSet_Optional {
	bool d;
	struct SQN_NR_PUSCH_PowerControl_v1610_olpc_ParameterSet v;
};

struct SQN_NR_PUSCH_PowerControl_v1610 {
	struct SQN_NR_PUSCH_PathlossReferenceRS_r16_SQN_NR_PUSCH_PowerControl_v1610_pathlossReferenceRSToAddModList2_r16_DynamicOptional pathlossReferenceRSToAddModList2_r16;
	struct SQN_NR_PUSCH_PathlossReferenceRS_Id_v1610_SQN_NR_PUSCH_PowerControl_v1610_pathlossReferenceRSToReleaseList2_r16_DynamicOptional pathlossReferenceRSToReleaseList2_r16;
	struct SQN_NR_P0_PUSCH_Set_r16_SQN_NR_PUSCH_PowerControl_v1610_p0_PUSCH_SetList_r16_DynamicOptional p0_PUSCH_SetList_r16;
	struct SQN_NR_PUSCH_PowerControl_v1610_olpc_ParameterSet_olpc_ParameterSet_Optional olpc_ParameterSet;
};

enum SQN_NR_SetupRelease_PUSCH_Config_pusch_PowerControl_v1610_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_pusch_PowerControl_v1610_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_pusch_PowerControl_v1610_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_pusch_PowerControl_v1610_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_pusch_PowerControl_v1610_Value {
	Null release;
	struct SQN_NR_PUSCH_PowerControl_v1610 setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_pusch_PowerControl_v1610 {
	enum SQN_NR_SetupRelease_PUSCH_Config_pusch_PowerControl_v1610_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_pusch_PowerControl_v1610_Value v;
};

enum SQN_NR_PUSCH_Config_ul_FullPowerTransmission_r16_e {
	SQN_NR_PUSCH_Config_ul_FullPowerTransmission_r16_e_fullpower = 0,
	SQN_NR_PUSCH_Config_ul_FullPowerTransmission_r16_e_fullpowerMode1 = 1,
	SQN_NR_PUSCH_Config_ul_FullPowerTransmission_r16_e_fullpoweMode2 = 2,
};

typedef enum SQN_NR_PUSCH_Config_ul_FullPowerTransmission_r16_e SQN_NR_PUSCH_Config_ul_FullPowerTransmission_r16_e;

enum SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListForMultiPUSCH_r16_Sel {
	SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListForMultiPUSCH_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListForMultiPUSCH_r16_release = 1,
	SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListForMultiPUSCH_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListForMultiPUSCH_r16_Value {
	Null release;
	SQN_NR_PUSCH_TimeDomainResourceAllocationList_r16 setup;
};

struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListForMultiPUSCH_r16 {
	enum SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListForMultiPUSCH_r16_Sel d;
	union SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListForMultiPUSCH_r16_Value v;
};

struct uint16_t_SQN_NR_PUSCH_Config_dataScramblingIdentityPUSCH_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_PUSCH_Config_txConfig_e_txConfig_Optional {
	bool d;
	SQN_NR_PUSCH_Config_txConfig_e v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_SQN_NR_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_SQN_NR_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB v;
};

struct SQN_NR_PUSCH_PowerControl_SQN_NR_PUSCH_Config_pusch_PowerControl_Optional {
	bool d;
	struct SQN_NR_PUSCH_PowerControl v;
};

struct SQN_NR_PUSCH_Config_frequencyHopping_e_frequencyHopping_Optional {
	bool d;
	SQN_NR_PUSCH_Config_frequencyHopping_e v;
};

struct uint16_t_SQN_NR_PUSCH_Config_frequencyHoppingOffsetLists_Dynamic {
	size_t d;
	uint16_t* v;
};

struct uint16_t_SQN_NR_PUSCH_Config_frequencyHoppingOffsetLists_DynamicOptional {
	bool d;
	struct uint16_t_SQN_NR_PUSCH_Config_frequencyHoppingOffsetLists_Dynamic v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationList_SQN_NR_PUSCH_Config_pusch_TimeDomainAllocationList_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationList v;
};

struct SQN_NR_PUSCH_Config_pusch_AggregationFactor_e_pusch_AggregationFactor_Optional {
	bool d;
	SQN_NR_PUSCH_Config_pusch_AggregationFactor_e v;
};

struct SQN_NR_PUSCH_Config_mcs_Table_e_mcs_Table_Optional {
	bool d;
	SQN_NR_PUSCH_Config_mcs_Table_e v;
};

struct SQN_NR_PUSCH_Config_mcs_TableTransformPrecoder_e_mcs_TableTransformPrecoder_Optional {
	bool d;
	SQN_NR_PUSCH_Config_mcs_TableTransformPrecoder_e v;
};

struct SQN_NR_PUSCH_Config_transformPrecoder_e_transformPrecoder_Optional {
	bool d;
	SQN_NR_PUSCH_Config_transformPrecoder_e v;
};

struct SQN_NR_PUSCH_Config_codebookSubset_e_codebookSubset_Optional {
	bool d;
	SQN_NR_PUSCH_Config_codebookSubset_e v;
};

struct uint8_t_SQN_NR_PUSCH_Config_maxRank_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PUSCH_Config_rbg_Size_e_rbg_Size_Optional {
	bool d;
	SQN_NR_PUSCH_Config_rbg_Size_e v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_SQN_NR_PUSCH_Config_uci_OnPUSCH_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH v;
};

struct SQN_NR_PUSCH_Config_tp_pi2BPSK_e_tp_pi2BPSK_Optional {
	bool d;
	SQN_NR_PUSCH_Config_tp_pi2BPSK_e v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_minimumSchedulingOffsetK2_r16_SQN_NR_PUSCH_Config_minimumSchedulingOffsetK2_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_minimumSchedulingOffsetK2_r16 v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_ul_AccessConfigListDCI_0_1_r16_SQN_NR_PUSCH_Config_ul_AccessConfigListDCI_0_1_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_ul_AccessConfigListDCI_0_1_r16 v;
};

struct uint8_t_SQN_NR_PUSCH_Config_harq_ProcessNumberSizeDCI_0_2_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PUSCH_Config_dmrs_SequenceInitializationDCI_0_2_r16_e_dmrs_SequenceInitializationDCI_0_2_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_dmrs_SequenceInitializationDCI_0_2_r16_e v;
};

struct uint8_t_SQN_NR_PUSCH_Config_numberOfBitsForRV_DCI_0_2_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PUSCH_Config_antennaPortsFieldPresenceDCI_0_2_r16_e_antennaPortsFieldPresenceDCI_0_2_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_antennaPortsFieldPresenceDCI_0_2_r16_e v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_DCI_0_2_r16_SQN_NR_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_DCI_0_2_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_DCI_0_2_r16 v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_DCI_0_2_r16_SQN_NR_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_DCI_0_2_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_DCI_0_2_r16 v;
};

struct SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_frequencyHoppingDCI_0_2_r16_Optional {
	bool d;
	struct SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16 v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_frequencyHoppingOffsetListsDCI_0_2_r16_SQN_NR_PUSCH_Config_frequencyHoppingOffsetListsDCI_0_2_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_frequencyHoppingOffsetListsDCI_0_2_r16 v;
};

struct SQN_NR_PUSCH_Config_codebookSubsetDCI_0_2_r16_e_codebookSubsetDCI_0_2_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_codebookSubsetDCI_0_2_r16_e v;
};

struct SQN_NR_PUSCH_Config_invalidSymbolPatternIndicatorDCI_0_2_r16_e_invalidSymbolPatternIndicatorDCI_0_2_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_invalidSymbolPatternIndicatorDCI_0_2_r16_e v;
};

struct uint8_t_SQN_NR_PUSCH_Config_maxRankDCI_0_2_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PUSCH_Config_mcs_TableDCI_0_2_r16_e_mcs_TableDCI_0_2_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_mcs_TableDCI_0_2_r16_e v;
};

struct SQN_NR_PUSCH_Config_mcs_TableTransformPrecoderDCI_0_2_r16_e_mcs_TableTransformPrecoderDCI_0_2_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_mcs_TableTransformPrecoderDCI_0_2_r16_e v;
};

struct SQN_NR_PUSCH_Config_priorityIndicatorDCI_0_2_r16_e_priorityIndicatorDCI_0_2_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_priorityIndicatorDCI_0_2_r16_e v;
};

struct SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_2_r16_e_pusch_RepTypeIndicatorDCI_0_2_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_2_r16_e v;
};

struct SQN_NR_PUSCH_Config_resourceAllocationDCI_0_2_r16_e_resourceAllocationDCI_0_2_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_resourceAllocationDCI_0_2_r16_e v;
};

struct SQN_NR_PUSCH_Config_resourceAllocationType1GranularityDCI_0_2_r16_e_resourceAllocationType1GranularityDCI_0_2_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_resourceAllocationType1GranularityDCI_0_2_r16_e v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_2_r16_SQN_NR_PUSCH_Config_uci_OnPUSCH_ListDCI_0_2_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_2_r16 v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_2_r16_SQN_NR_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_2_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_2_r16 v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_1_r16_SQN_NR_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_1_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_1_r16 v;
};

struct SQN_NR_PUSCH_Config_invalidSymbolPatternIndicatorDCI_0_1_r16_e_invalidSymbolPatternIndicatorDCI_0_1_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_invalidSymbolPatternIndicatorDCI_0_1_r16_e v;
};

struct SQN_NR_PUSCH_Config_priorityIndicatorDCI_0_1_r16_e_priorityIndicatorDCI_0_1_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_priorityIndicatorDCI_0_1_r16_e v;
};

struct SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_1_r16_e_pusch_RepTypeIndicatorDCI_0_1_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_1_r16_e v;
};

struct SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_1_r16_e_frequencyHoppingDCI_0_1_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_1_r16_e v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_1_r16_SQN_NR_PUSCH_Config_uci_OnPUSCH_ListDCI_0_1_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_1_r16 v;
};

struct SQN_NR_InvalidSymbolPattern_r16_SQN_NR_PUSCH_Config_invalidSymbolPattern_r16_Optional {
	bool d;
	struct SQN_NR_InvalidSymbolPattern_r16 v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_pusch_PowerControl_v1610_SQN_NR_PUSCH_Config_pusch_PowerControl_v1610_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_pusch_PowerControl_v1610 v;
};

struct SQN_NR_PUSCH_Config_ul_FullPowerTransmission_r16_e_ul_FullPowerTransmission_r16_Optional {
	bool d;
	SQN_NR_PUSCH_Config_ul_FullPowerTransmission_r16_e v;
};

struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListForMultiPUSCH_r16_SQN_NR_PUSCH_Config_pusch_TimeDomainAllocationListForMultiPUSCH_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListForMultiPUSCH_r16 v;
};

struct uint8_t_SQN_NR_PUSCH_Config_numberOfInvalidSymbolsForDL_UL_Switching_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PUSCH_Config {
	struct uint16_t_SQN_NR_PUSCH_Config_dataScramblingIdentityPUSCH_Optional dataScramblingIdentityPUSCH;
	struct SQN_NR_PUSCH_Config_txConfig_e_txConfig_Optional txConfig;
	struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_SQN_NR_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_Optional dmrs_UplinkForPUSCH_MappingTypeA;
	struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_SQN_NR_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_Optional dmrs_UplinkForPUSCH_MappingTypeB;
	struct SQN_NR_PUSCH_PowerControl_SQN_NR_PUSCH_Config_pusch_PowerControl_Optional pusch_PowerControl;
	struct SQN_NR_PUSCH_Config_frequencyHopping_e_frequencyHopping_Optional frequencyHopping;
	struct uint16_t_SQN_NR_PUSCH_Config_frequencyHoppingOffsetLists_DynamicOptional frequencyHoppingOffsetLists;
	SQN_NR_PUSCH_Config_resourceAllocation_e resourceAllocation;
	struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationList_SQN_NR_PUSCH_Config_pusch_TimeDomainAllocationList_Optional pusch_TimeDomainAllocationList;
	struct SQN_NR_PUSCH_Config_pusch_AggregationFactor_e_pusch_AggregationFactor_Optional pusch_AggregationFactor;
	struct SQN_NR_PUSCH_Config_mcs_Table_e_mcs_Table_Optional mcs_Table;
	struct SQN_NR_PUSCH_Config_mcs_TableTransformPrecoder_e_mcs_TableTransformPrecoder_Optional mcs_TableTransformPrecoder;
	struct SQN_NR_PUSCH_Config_transformPrecoder_e_transformPrecoder_Optional transformPrecoder;
	struct SQN_NR_PUSCH_Config_codebookSubset_e_codebookSubset_Optional codebookSubset;
	struct uint8_t_SQN_NR_PUSCH_Config_maxRank_Optional maxRank;
	struct SQN_NR_PUSCH_Config_rbg_Size_e_rbg_Size_Optional rbg_Size;
	struct SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_SQN_NR_PUSCH_Config_uci_OnPUSCH_Optional uci_OnPUSCH;
	struct SQN_NR_PUSCH_Config_tp_pi2BPSK_e_tp_pi2BPSK_Optional tp_pi2BPSK;
	struct SQN_NR_SetupRelease_PUSCH_Config_minimumSchedulingOffsetK2_r16_SQN_NR_PUSCH_Config_minimumSchedulingOffsetK2_r16_Optional minimumSchedulingOffsetK2_r16;
	struct SQN_NR_SetupRelease_PUSCH_Config_ul_AccessConfigListDCI_0_1_r16_SQN_NR_PUSCH_Config_ul_AccessConfigListDCI_0_1_r16_Optional ul_AccessConfigListDCI_0_1_r16;
	struct uint8_t_SQN_NR_PUSCH_Config_harq_ProcessNumberSizeDCI_0_2_r16_Optional harq_ProcessNumberSizeDCI_0_2_r16;
	struct SQN_NR_PUSCH_Config_dmrs_SequenceInitializationDCI_0_2_r16_e_dmrs_SequenceInitializationDCI_0_2_r16_Optional dmrs_SequenceInitializationDCI_0_2_r16;
	struct uint8_t_SQN_NR_PUSCH_Config_numberOfBitsForRV_DCI_0_2_r16_Optional numberOfBitsForRV_DCI_0_2_r16;
	struct SQN_NR_PUSCH_Config_antennaPortsFieldPresenceDCI_0_2_r16_e_antennaPortsFieldPresenceDCI_0_2_r16_Optional antennaPortsFieldPresenceDCI_0_2_r16;
	struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_DCI_0_2_r16_SQN_NR_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeA_DCI_0_2_r16_Optional dmrs_UplinkForPUSCH_MappingTypeA_DCI_0_2_r16;
	struct SQN_NR_SetupRelease_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_DCI_0_2_r16_SQN_NR_PUSCH_Config_dmrs_UplinkForPUSCH_MappingTypeB_DCI_0_2_r16_Optional dmrs_UplinkForPUSCH_MappingTypeB_DCI_0_2_r16;
	struct SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_2_r16_frequencyHoppingDCI_0_2_r16_Optional frequencyHoppingDCI_0_2_r16;
	struct SQN_NR_SetupRelease_PUSCH_Config_frequencyHoppingOffsetListsDCI_0_2_r16_SQN_NR_PUSCH_Config_frequencyHoppingOffsetListsDCI_0_2_r16_Optional frequencyHoppingOffsetListsDCI_0_2_r16;
	struct SQN_NR_PUSCH_Config_codebookSubsetDCI_0_2_r16_e_codebookSubsetDCI_0_2_r16_Optional codebookSubsetDCI_0_2_r16;
	struct SQN_NR_PUSCH_Config_invalidSymbolPatternIndicatorDCI_0_2_r16_e_invalidSymbolPatternIndicatorDCI_0_2_r16_Optional invalidSymbolPatternIndicatorDCI_0_2_r16;
	struct uint8_t_SQN_NR_PUSCH_Config_maxRankDCI_0_2_r16_Optional maxRankDCI_0_2_r16;
	struct SQN_NR_PUSCH_Config_mcs_TableDCI_0_2_r16_e_mcs_TableDCI_0_2_r16_Optional mcs_TableDCI_0_2_r16;
	struct SQN_NR_PUSCH_Config_mcs_TableTransformPrecoderDCI_0_2_r16_e_mcs_TableTransformPrecoderDCI_0_2_r16_Optional mcs_TableTransformPrecoderDCI_0_2_r16;
	struct SQN_NR_PUSCH_Config_priorityIndicatorDCI_0_2_r16_e_priorityIndicatorDCI_0_2_r16_Optional priorityIndicatorDCI_0_2_r16;
	struct SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_2_r16_e_pusch_RepTypeIndicatorDCI_0_2_r16_Optional pusch_RepTypeIndicatorDCI_0_2_r16;
	struct SQN_NR_PUSCH_Config_resourceAllocationDCI_0_2_r16_e_resourceAllocationDCI_0_2_r16_Optional resourceAllocationDCI_0_2_r16;
	struct SQN_NR_PUSCH_Config_resourceAllocationType1GranularityDCI_0_2_r16_e_resourceAllocationType1GranularityDCI_0_2_r16_Optional resourceAllocationType1GranularityDCI_0_2_r16;
	struct SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_2_r16_SQN_NR_PUSCH_Config_uci_OnPUSCH_ListDCI_0_2_r16_Optional uci_OnPUSCH_ListDCI_0_2_r16;
	struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_2_r16_SQN_NR_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_2_r16_Optional pusch_TimeDomainAllocationListDCI_0_2_r16;
	struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_1_r16_SQN_NR_PUSCH_Config_pusch_TimeDomainAllocationListDCI_0_1_r16_Optional pusch_TimeDomainAllocationListDCI_0_1_r16;
	struct SQN_NR_PUSCH_Config_invalidSymbolPatternIndicatorDCI_0_1_r16_e_invalidSymbolPatternIndicatorDCI_0_1_r16_Optional invalidSymbolPatternIndicatorDCI_0_1_r16;
	struct SQN_NR_PUSCH_Config_priorityIndicatorDCI_0_1_r16_e_priorityIndicatorDCI_0_1_r16_Optional priorityIndicatorDCI_0_1_r16;
	struct SQN_NR_PUSCH_Config_pusch_RepTypeIndicatorDCI_0_1_r16_e_pusch_RepTypeIndicatorDCI_0_1_r16_Optional pusch_RepTypeIndicatorDCI_0_1_r16;
	struct SQN_NR_PUSCH_Config_frequencyHoppingDCI_0_1_r16_e_frequencyHoppingDCI_0_1_r16_Optional frequencyHoppingDCI_0_1_r16;
	struct SQN_NR_SetupRelease_PUSCH_Config_uci_OnPUSCH_ListDCI_0_1_r16_SQN_NR_PUSCH_Config_uci_OnPUSCH_ListDCI_0_1_r16_Optional uci_OnPUSCH_ListDCI_0_1_r16;
	struct SQN_NR_InvalidSymbolPattern_r16_SQN_NR_PUSCH_Config_invalidSymbolPattern_r16_Optional invalidSymbolPattern_r16;
	struct SQN_NR_SetupRelease_PUSCH_Config_pusch_PowerControl_v1610_SQN_NR_PUSCH_Config_pusch_PowerControl_v1610_Optional pusch_PowerControl_v1610;
	struct SQN_NR_PUSCH_Config_ul_FullPowerTransmission_r16_e_ul_FullPowerTransmission_r16_Optional ul_FullPowerTransmission_r16;
	struct SQN_NR_SetupRelease_PUSCH_Config_pusch_TimeDomainAllocationListForMultiPUSCH_r16_SQN_NR_PUSCH_Config_pusch_TimeDomainAllocationListForMultiPUSCH_r16_Optional pusch_TimeDomainAllocationListForMultiPUSCH_r16;
	struct uint8_t_SQN_NR_PUSCH_Config_numberOfInvalidSymbolsForDL_UL_Switching_r16_Optional numberOfInvalidSymbolsForDL_UL_Switching_r16;
};

enum SQN_NR_SetupRelease_BWP_UplinkDedicated_pusch_Config_Sel {
	SQN_NR_SetupRelease_BWP_UplinkDedicated_pusch_Config_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_pusch_Config_release = 1,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_pusch_Config_setup = 2,
};

union SQN_NR_SetupRelease_BWP_UplinkDedicated_pusch_Config_Value {
	Null release;
	struct SQN_NR_PUSCH_Config setup;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_pusch_Config {
	enum SQN_NR_SetupRelease_BWP_UplinkDedicated_pusch_Config_Sel d;
	union SQN_NR_SetupRelease_BWP_UplinkDedicated_pusch_Config_Value v;
};

enum SQN_NR_ConfiguredGrantConfig_frequencyHopping_e {
	SQN_NR_ConfiguredGrantConfig_frequencyHopping_e_intraSlot = 0,
	SQN_NR_ConfiguredGrantConfig_frequencyHopping_e_interSlot = 1,
};

typedef enum SQN_NR_ConfiguredGrantConfig_frequencyHopping_e SQN_NR_ConfiguredGrantConfig_frequencyHopping_e;

enum SQN_NR_ConfiguredGrantConfig_mcs_Table_e {
	SQN_NR_ConfiguredGrantConfig_mcs_Table_e_qam256 = 0,
	SQN_NR_ConfiguredGrantConfig_mcs_Table_e_qam64LowSE = 1,
};

typedef enum SQN_NR_ConfiguredGrantConfig_mcs_Table_e SQN_NR_ConfiguredGrantConfig_mcs_Table_e;

enum SQN_NR_ConfiguredGrantConfig_mcs_TableTransformPrecoder_e {
	SQN_NR_ConfiguredGrantConfig_mcs_TableTransformPrecoder_e_qam256 = 0,
	SQN_NR_ConfiguredGrantConfig_mcs_TableTransformPrecoder_e_qam64LowSE = 1,
};

typedef enum SQN_NR_ConfiguredGrantConfig_mcs_TableTransformPrecoder_e SQN_NR_ConfiguredGrantConfig_mcs_TableTransformPrecoder_e;

enum SQN_NR_CG_UCI_OnPUSCH_Sel {
	SQN_NR_CG_UCI_OnPUSCH_UNBOUND_VALUE = 0,
	SQN_NR_CG_UCI_OnPUSCH_dynamic = 1,
	SQN_NR_CG_UCI_OnPUSCH_semiStatic = 2,
};

struct SQN_NR_BetaOffsets_SQN_NR_CG_UCI_OnPUSCH_dynamic_Dynamic {
	size_t d;
	struct SQN_NR_BetaOffsets* v;
};

union SQN_NR_CG_UCI_OnPUSCH_Value {
	struct SQN_NR_BetaOffsets_SQN_NR_CG_UCI_OnPUSCH_dynamic_Dynamic dynamic;
	struct SQN_NR_BetaOffsets semiStatic;
};

struct SQN_NR_CG_UCI_OnPUSCH {
	enum SQN_NR_CG_UCI_OnPUSCH_Sel d;
	union SQN_NR_CG_UCI_OnPUSCH_Value v;
};

enum SQN_NR_SetupRelease_ConfiguredGrantConfig_uci_OnPUSCH_Sel {
	SQN_NR_SetupRelease_ConfiguredGrantConfig_uci_OnPUSCH_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_ConfiguredGrantConfig_uci_OnPUSCH_release = 1,
	SQN_NR_SetupRelease_ConfiguredGrantConfig_uci_OnPUSCH_setup = 2,
};

union SQN_NR_SetupRelease_ConfiguredGrantConfig_uci_OnPUSCH_Value {
	Null release;
	struct SQN_NR_CG_UCI_OnPUSCH setup;
};

struct SQN_NR_SetupRelease_ConfiguredGrantConfig_uci_OnPUSCH {
	enum SQN_NR_SetupRelease_ConfiguredGrantConfig_uci_OnPUSCH_Sel d;
	union SQN_NR_SetupRelease_ConfiguredGrantConfig_uci_OnPUSCH_Value v;
};

enum SQN_NR_ConfiguredGrantConfig_resourceAllocation_e {
	SQN_NR_ConfiguredGrantConfig_resourceAllocation_e_resourceAllocationType0 = 0,
	SQN_NR_ConfiguredGrantConfig_resourceAllocation_e_resourceAllocationType1 = 1,
	SQN_NR_ConfiguredGrantConfig_resourceAllocation_e_dynamicSwitch = 2,
};

typedef enum SQN_NR_ConfiguredGrantConfig_resourceAllocation_e SQN_NR_ConfiguredGrantConfig_resourceAllocation_e;

enum SQN_NR_ConfiguredGrantConfig_rbg_Size_e {
	SQN_NR_ConfiguredGrantConfig_rbg_Size_e_config2 = 0,
};

typedef enum SQN_NR_ConfiguredGrantConfig_rbg_Size_e SQN_NR_ConfiguredGrantConfig_rbg_Size_e;

enum SQN_NR_ConfiguredGrantConfig_powerControlLoopToUse_e {
	SQN_NR_ConfiguredGrantConfig_powerControlLoopToUse_e_n0 = 0,
	SQN_NR_ConfiguredGrantConfig_powerControlLoopToUse_e_n1 = 1,
};

typedef enum SQN_NR_ConfiguredGrantConfig_powerControlLoopToUse_e SQN_NR_ConfiguredGrantConfig_powerControlLoopToUse_e;

enum SQN_NR_ConfiguredGrantConfig_transformPrecoder_e {
	SQN_NR_ConfiguredGrantConfig_transformPrecoder_e_enabled = 0,
	SQN_NR_ConfiguredGrantConfig_transformPrecoder_e_disabled = 1,
};

typedef enum SQN_NR_ConfiguredGrantConfig_transformPrecoder_e SQN_NR_ConfiguredGrantConfig_transformPrecoder_e;

enum SQN_NR_ConfiguredGrantConfig_repK_e {
	SQN_NR_ConfiguredGrantConfig_repK_e_n1 = 0,
	SQN_NR_ConfiguredGrantConfig_repK_e_n2 = 1,
	SQN_NR_ConfiguredGrantConfig_repK_e_n4 = 2,
	SQN_NR_ConfiguredGrantConfig_repK_e_n8 = 3,
};

typedef enum SQN_NR_ConfiguredGrantConfig_repK_e SQN_NR_ConfiguredGrantConfig_repK_e;

enum SQN_NR_ConfiguredGrantConfig_repK_RV_e {
	SQN_NR_ConfiguredGrantConfig_repK_RV_e_s1_0231 = 0,
	SQN_NR_ConfiguredGrantConfig_repK_RV_e_s2_0303 = 1,
	SQN_NR_ConfiguredGrantConfig_repK_RV_e_s3_0000 = 2,
};

typedef enum SQN_NR_ConfiguredGrantConfig_repK_RV_e SQN_NR_ConfiguredGrantConfig_repK_RV_e;

enum SQN_NR_ConfiguredGrantConfig_periodicity_e {
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym2 = 0,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym7 = 1,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym1x14 = 2,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym2x14 = 3,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym4x14 = 4,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym5x14 = 5,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym8x14 = 6,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym10x14 = 7,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym16x14 = 8,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym20x14 = 9,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym32x14 = 10,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym40x14 = 11,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym64x14 = 12,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym80x14 = 13,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym128x14 = 14,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym160x14 = 15,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym256x14 = 16,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym320x14 = 17,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym512x14 = 18,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym640x14 = 19,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym1024x14 = 20,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym1280x14 = 21,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym2560x14 = 22,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym5120x14 = 23,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym6 = 24,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym1x12 = 25,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym2x12 = 26,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym4x12 = 27,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym5x12 = 28,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym8x12 = 29,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym10x12 = 30,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym16x12 = 31,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym20x12 = 32,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym32x12 = 33,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym40x12 = 34,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym64x12 = 35,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym80x12 = 36,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym128x12 = 37,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym160x12 = 38,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym256x12 = 39,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym320x12 = 40,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym512x12 = 41,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym640x12 = 42,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym1280x12 = 43,
	SQN_NR_ConfiguredGrantConfig_periodicity_e_sym2560x12 = 44,
};

typedef enum SQN_NR_ConfiguredGrantConfig_periodicity_e SQN_NR_ConfiguredGrantConfig_periodicity_e;

enum SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_pusch_RepTypeIndicator_r16_e {
	SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_pusch_RepTypeIndicator_r16_e_pusch_RepTypeA = 0,
	SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_pusch_RepTypeIndicator_r16_e_pusch_RepTypeB = 1,
};

typedef enum SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_pusch_RepTypeIndicator_r16_e SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_pusch_RepTypeIndicator_r16_e;

enum SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_frequencyHoppingPUSCH_RepTypeB_r16_e {
	SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_frequencyHoppingPUSCH_RepTypeB_r16_e_interRepetition = 0,
	SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_frequencyHoppingPUSCH_RepTypeB_r16_e_interSlot = 1,
};

typedef enum SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_frequencyHoppingPUSCH_RepTypeB_r16_e SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_frequencyHoppingPUSCH_RepTypeB_r16_e;

enum SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_timeReferenceSFN_r16_e {
	SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_timeReferenceSFN_r16_e_sfn512 = 0,
};

typedef enum SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_timeReferenceSFN_r16_e SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_timeReferenceSFN_r16_e;

struct uint8_t_SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_dmrs_SeqInitialization_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_srs_ResourceIndicator_Optional {
	bool d;
	uint8_t v;
};

struct uint16_t_SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_frequencyHoppingOffset_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_pusch_RepTypeIndicator_r16_e_pusch_RepTypeIndicator_r16_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_pusch_RepTypeIndicator_r16_e v;
};

struct SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_frequencyHoppingPUSCH_RepTypeB_r16_e_frequencyHoppingPUSCH_RepTypeB_r16_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_frequencyHoppingPUSCH_RepTypeB_r16_e v;
};

struct SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_timeReferenceSFN_r16_e_timeReferenceSFN_r16_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_timeReferenceSFN_r16_e v;
};

struct SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant {
	uint16_t timeDomainOffset;
	uint8_t timeDomainAllocation;
	B18 frequencyDomainAllocation;
	uint8_t antennaPort;
	struct uint8_t_SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_dmrs_SeqInitialization_Optional dmrs_SeqInitialization;
	uint8_t precodingAndNumberOfLayers;
	struct uint8_t_SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_srs_ResourceIndicator_Optional srs_ResourceIndicator;
	uint8_t mcsAndTBS;
	struct uint16_t_SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_frequencyHoppingOffset_Optional frequencyHoppingOffset;
	uint8_t pathlossReferenceIndex;
	struct SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_pusch_RepTypeIndicator_r16_e_pusch_RepTypeIndicator_r16_Optional pusch_RepTypeIndicator_r16;
	struct SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_frequencyHoppingPUSCH_RepTypeB_r16_e_frequencyHoppingPUSCH_RepTypeB_r16_Optional frequencyHoppingPUSCH_RepTypeB_r16;
	struct SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_timeReferenceSFN_r16_e_timeReferenceSFN_r16_Optional timeReferenceSFN_r16;
};

enum SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e {
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym7 = 0,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym1x14 = 1,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym2x14 = 2,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym3x14 = 3,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym4x14 = 4,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym5x14 = 5,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym6x14 = 6,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym7x14 = 7,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym8x14 = 8,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym9x14 = 9,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym10x14 = 10,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym11x14 = 11,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym12x14 = 12,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym13x14 = 13,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym14x14 = 14,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym15x14 = 15,
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_sym16x14 = 16,
};

typedef enum SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e;

struct uint8_t_SQN_NR_CG_StartingOffsets_r16_cg_StartingFullBW_InsideCOT_r16_Dynamic {
	size_t d;
	uint8_t* v;
};

struct uint8_t_SQN_NR_CG_StartingOffsets_r16_cg_StartingFullBW_InsideCOT_r16_DynamicOptional {
	bool d;
	struct uint8_t_SQN_NR_CG_StartingOffsets_r16_cg_StartingFullBW_InsideCOT_r16_Dynamic v;
};

struct uint8_t_SQN_NR_CG_StartingOffsets_r16_cg_StartingFullBW_OutsideCOT_r16_Dynamic {
	size_t d;
	uint8_t* v;
};

struct uint8_t_SQN_NR_CG_StartingOffsets_r16_cg_StartingFullBW_OutsideCOT_r16_DynamicOptional {
	bool d;
	struct uint8_t_SQN_NR_CG_StartingOffsets_r16_cg_StartingFullBW_OutsideCOT_r16_Dynamic v;
};

struct uint8_t_SQN_NR_CG_StartingOffsets_r16_cg_StartingPartialBW_InsideCOT_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_CG_StartingOffsets_r16_cg_StartingPartialBW_OutsideCOT_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_CG_StartingOffsets_r16 {
	struct uint8_t_SQN_NR_CG_StartingOffsets_r16_cg_StartingFullBW_InsideCOT_r16_DynamicOptional cg_StartingFullBW_InsideCOT_r16;
	struct uint8_t_SQN_NR_CG_StartingOffsets_r16_cg_StartingFullBW_OutsideCOT_r16_DynamicOptional cg_StartingFullBW_OutsideCOT_r16;
	struct uint8_t_SQN_NR_CG_StartingOffsets_r16_cg_StartingPartialBW_InsideCOT_r16_Optional cg_StartingPartialBW_InsideCOT_r16;
	struct uint8_t_SQN_NR_CG_StartingOffsets_r16_cg_StartingPartialBW_OutsideCOT_r16_Optional cg_StartingPartialBW_OutsideCOT_r16;
};

enum SQN_NR_ConfiguredGrantConfig_cg_UCI_Multiplexing_e {
	SQN_NR_ConfiguredGrantConfig_cg_UCI_Multiplexing_e_enabled = 0,
};

typedef enum SQN_NR_ConfiguredGrantConfig_cg_UCI_Multiplexing_e SQN_NR_ConfiguredGrantConfig_cg_UCI_Multiplexing_e;

struct SQN_NR_CG_COT_Sharing_r16_cot_Sharing_r16 {
	uint8_t duration_r16;
	uint8_t offset_r16;
	uint8_t channelAccessPriority_r16;
};

enum SQN_NR_CG_COT_Sharing_r16_Sel {
	SQN_NR_CG_COT_Sharing_r16_UNBOUND_VALUE = 0,
	SQN_NR_CG_COT_Sharing_r16_noCOT_Sharing_r16 = 1,
	SQN_NR_CG_COT_Sharing_r16_cot_Sharing_r16 = 2,
};

union SQN_NR_CG_COT_Sharing_r16_Value {
	Null noCOT_Sharing_r16;
	struct SQN_NR_CG_COT_Sharing_r16_cot_Sharing_r16 cot_Sharing_r16;
};

struct SQN_NR_CG_COT_Sharing_r16 {
	enum SQN_NR_CG_COT_Sharing_r16_Sel d;
	union SQN_NR_CG_COT_Sharing_r16_Value v;
};

typedef uint8_t SQN_NR_ConfiguredGrantConfigIndex_r16;

typedef uint8_t SQN_NR_ConfiguredGrantConfigIndexMAC_r16;

enum SQN_NR_ConfiguredGrantConfig_startingFromRV0_r16_e {
	SQN_NR_ConfiguredGrantConfig_startingFromRV0_r16_e_on = 0,
	SQN_NR_ConfiguredGrantConfig_startingFromRV0_r16_e_off = 1,
};

typedef enum SQN_NR_ConfiguredGrantConfig_startingFromRV0_r16_e SQN_NR_ConfiguredGrantConfig_startingFromRV0_r16_e;

enum SQN_NR_ConfiguredGrantConfig_phy_PriorityIndex_r16_e {
	SQN_NR_ConfiguredGrantConfig_phy_PriorityIndex_r16_e_p0 = 0,
	SQN_NR_ConfiguredGrantConfig_phy_PriorityIndex_r16_e_p1 = 1,
};

typedef enum SQN_NR_ConfiguredGrantConfig_phy_PriorityIndex_r16_e SQN_NR_ConfiguredGrantConfig_phy_PriorityIndex_r16_e;

enum SQN_NR_ConfiguredGrantConfig_autonomousTx_r16_e {
	SQN_NR_ConfiguredGrantConfig_autonomousTx_r16_e_enabled = 0,
};

typedef enum SQN_NR_ConfiguredGrantConfig_autonomousTx_r16_e SQN_NR_ConfiguredGrantConfig_autonomousTx_r16_e;

struct SQN_NR_ConfiguredGrantConfig_frequencyHopping_e_frequencyHopping_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfig_frequencyHopping_e v;
};

struct SQN_NR_ConfiguredGrantConfig_mcs_Table_e_mcs_Table_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfig_mcs_Table_e v;
};

struct SQN_NR_ConfiguredGrantConfig_mcs_TableTransformPrecoder_e_mcs_TableTransformPrecoder_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfig_mcs_TableTransformPrecoder_e v;
};

struct SQN_NR_SetupRelease_ConfiguredGrantConfig_uci_OnPUSCH_SQN_NR_ConfiguredGrantConfig_uci_OnPUSCH_Optional {
	bool d;
	struct SQN_NR_SetupRelease_ConfiguredGrantConfig_uci_OnPUSCH v;
};

struct SQN_NR_ConfiguredGrantConfig_rbg_Size_e_rbg_Size_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfig_rbg_Size_e v;
};

struct SQN_NR_ConfiguredGrantConfig_transformPrecoder_e_transformPrecoder_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfig_transformPrecoder_e v;
};

struct SQN_NR_ConfiguredGrantConfig_repK_RV_e_repK_RV_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfig_repK_RV_e v;
};

struct uint8_t_SQN_NR_ConfiguredGrantConfig_configuredGrantTimer_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_rrc_ConfiguredUplinkGrant_Optional {
	bool d;
	struct SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant v;
};

struct uint8_t_SQN_NR_ConfiguredGrantConfig_cg_RetransmissionTimer_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_cg_minDFI_Delay_r16_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e v;
};

struct uint8_t_SQN_NR_ConfiguredGrantConfig_cg_nrofPUSCH_InSlot_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_ConfiguredGrantConfig_cg_nrofSlots_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_CG_StartingOffsets_r16_SQN_NR_ConfiguredGrantConfig_cg_StartingOffsets_r16_Optional {
	bool d;
	struct SQN_NR_CG_StartingOffsets_r16 v;
};

struct SQN_NR_ConfiguredGrantConfig_cg_UCI_Multiplexing_e_cg_UCI_Multiplexing_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfig_cg_UCI_Multiplexing_e v;
};

struct uint8_t_SQN_NR_ConfiguredGrantConfig_cg_COT_SharingOffset_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_ConfiguredGrantConfig_betaOffsetCG_UCI_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_ConfiguredGrantConfig_SQN_NR_CG_COT_Sharing_r16_cg_COT_SharingList_r16_Dynamic {
	size_t d;
	struct SQN_NR_CG_COT_Sharing_r16* v;
};

struct SQN_NR_CG_COT_Sharing_r16_SQN_NR_ConfiguredGrantConfig_cg_COT_SharingList_r16_DynamicOptional {
	bool d;
	struct SQN_NR_ConfiguredGrantConfig_SQN_NR_CG_COT_Sharing_r16_cg_COT_SharingList_r16_Dynamic v;
};

struct uint8_t_SQN_NR_ConfiguredGrantConfig_harq_ProcID_Offset_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_ConfiguredGrantConfig_harq_ProcID_Offset2_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_ConfiguredGrantConfigIndex_r16_SQN_NR_ConfiguredGrantConfig_configuredGrantConfigIndex_r16_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfigIndex_r16 v;
};

struct SQN_NR_ConfiguredGrantConfigIndexMAC_r16_SQN_NR_ConfiguredGrantConfig_configuredGrantConfigIndexMAC_r16_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfigIndexMAC_r16 v;
};

struct uint16_t_SQN_NR_ConfiguredGrantConfig_periodicityExt_r16_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_ConfiguredGrantConfig_startingFromRV0_r16_e_startingFromRV0_r16_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfig_startingFromRV0_r16_e v;
};

struct SQN_NR_ConfiguredGrantConfig_phy_PriorityIndex_r16_e_phy_PriorityIndex_r16_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfig_phy_PriorityIndex_r16_e v;
};

struct SQN_NR_ConfiguredGrantConfig_autonomousTx_r16_e_autonomousTx_r16_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfig_autonomousTx_r16_e v;
};

struct SQN_NR_ConfiguredGrantConfig {
	struct SQN_NR_ConfiguredGrantConfig_frequencyHopping_e_frequencyHopping_Optional frequencyHopping;
	struct SQN_NR_DMRS_UplinkConfig cg_DMRS_Configuration;
	struct SQN_NR_ConfiguredGrantConfig_mcs_Table_e_mcs_Table_Optional mcs_Table;
	struct SQN_NR_ConfiguredGrantConfig_mcs_TableTransformPrecoder_e_mcs_TableTransformPrecoder_Optional mcs_TableTransformPrecoder;
	struct SQN_NR_SetupRelease_ConfiguredGrantConfig_uci_OnPUSCH_SQN_NR_ConfiguredGrantConfig_uci_OnPUSCH_Optional uci_OnPUSCH;
	SQN_NR_ConfiguredGrantConfig_resourceAllocation_e resourceAllocation;
	struct SQN_NR_ConfiguredGrantConfig_rbg_Size_e_rbg_Size_Optional rbg_Size;
	SQN_NR_ConfiguredGrantConfig_powerControlLoopToUse_e powerControlLoopToUse;
	SQN_NR_P0_PUSCH_AlphaSetId p0_PUSCH_Alpha;
	struct SQN_NR_ConfiguredGrantConfig_transformPrecoder_e_transformPrecoder_Optional transformPrecoder;
	uint8_t nrofHARQ_Processes;
	SQN_NR_ConfiguredGrantConfig_repK_e repK;
	struct SQN_NR_ConfiguredGrantConfig_repK_RV_e_repK_RV_Optional repK_RV;
	SQN_NR_ConfiguredGrantConfig_periodicity_e periodicity;
	struct uint8_t_SQN_NR_ConfiguredGrantConfig_configuredGrantTimer_Optional configuredGrantTimer;
	struct SQN_NR_ConfiguredGrantConfig_rrc_ConfiguredUplinkGrant_rrc_ConfiguredUplinkGrant_Optional rrc_ConfiguredUplinkGrant;
	struct uint8_t_SQN_NR_ConfiguredGrantConfig_cg_RetransmissionTimer_r16_Optional cg_RetransmissionTimer_r16;
	struct SQN_NR_ConfiguredGrantConfig_cg_minDFI_Delay_r16_e_cg_minDFI_Delay_r16_Optional cg_minDFI_Delay_r16;
	struct uint8_t_SQN_NR_ConfiguredGrantConfig_cg_nrofPUSCH_InSlot_r16_Optional cg_nrofPUSCH_InSlot_r16;
	struct uint8_t_SQN_NR_ConfiguredGrantConfig_cg_nrofSlots_r16_Optional cg_nrofSlots_r16;
	struct SQN_NR_CG_StartingOffsets_r16_SQN_NR_ConfiguredGrantConfig_cg_StartingOffsets_r16_Optional cg_StartingOffsets_r16;
	struct SQN_NR_ConfiguredGrantConfig_cg_UCI_Multiplexing_e_cg_UCI_Multiplexing_Optional cg_UCI_Multiplexing;
	struct uint8_t_SQN_NR_ConfiguredGrantConfig_cg_COT_SharingOffset_r16_Optional cg_COT_SharingOffset_r16;
	struct uint8_t_SQN_NR_ConfiguredGrantConfig_betaOffsetCG_UCI_r16_Optional betaOffsetCG_UCI_r16;
	struct SQN_NR_CG_COT_Sharing_r16_SQN_NR_ConfiguredGrantConfig_cg_COT_SharingList_r16_DynamicOptional cg_COT_SharingList_r16;
	struct uint8_t_SQN_NR_ConfiguredGrantConfig_harq_ProcID_Offset_r16_Optional harq_ProcID_Offset_r16;
	struct uint8_t_SQN_NR_ConfiguredGrantConfig_harq_ProcID_Offset2_r16_Optional harq_ProcID_Offset2_r16;
	struct SQN_NR_ConfiguredGrantConfigIndex_r16_SQN_NR_ConfiguredGrantConfig_configuredGrantConfigIndex_r16_Optional configuredGrantConfigIndex_r16;
	struct SQN_NR_ConfiguredGrantConfigIndexMAC_r16_SQN_NR_ConfiguredGrantConfig_configuredGrantConfigIndexMAC_r16_Optional configuredGrantConfigIndexMAC_r16;
	struct uint16_t_SQN_NR_ConfiguredGrantConfig_periodicityExt_r16_Optional periodicityExt_r16;
	struct SQN_NR_ConfiguredGrantConfig_startingFromRV0_r16_e_startingFromRV0_r16_Optional startingFromRV0_r16;
	struct SQN_NR_ConfiguredGrantConfig_phy_PriorityIndex_r16_e_phy_PriorityIndex_r16_Optional phy_PriorityIndex_r16;
	struct SQN_NR_ConfiguredGrantConfig_autonomousTx_r16_e_autonomousTx_r16_Optional autonomousTx_r16;
};

enum SQN_NR_SetupRelease_BWP_UplinkDedicated_configuredGrantConfig_Sel {
	SQN_NR_SetupRelease_BWP_UplinkDedicated_configuredGrantConfig_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_configuredGrantConfig_release = 1,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_configuredGrantConfig_setup = 2,
};

union SQN_NR_SetupRelease_BWP_UplinkDedicated_configuredGrantConfig_Value {
	Null release;
	struct SQN_NR_ConfiguredGrantConfig setup;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_configuredGrantConfig {
	enum SQN_NR_SetupRelease_BWP_UplinkDedicated_configuredGrantConfig_Sel d;
	union SQN_NR_SetupRelease_BWP_UplinkDedicated_configuredGrantConfig_Value v;
};

typedef uint8_t SQN_NR_SRS_ResourceSetId;

struct SQN_NR_NZP_CSI_RS_ResourceId_SQN_NR_SRS_ResourceSet_resourceType_aperiodic_csi_RS_Optional {
	bool d;
	SQN_NR_NZP_CSI_RS_ResourceId v;
};

struct uint8_t_SQN_NR_SRS_ResourceSet_resourceType_aperiodic_slotOffset_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_SRS_ResourceSet_resourceType_aperiodic_aperiodicSRS_ResourceTriggerList_Dynamic {
	size_t d;
	uint8_t* v;
};

struct uint8_t_SQN_NR_SRS_ResourceSet_resourceType_aperiodic_aperiodicSRS_ResourceTriggerList_DynamicOptional {
	bool d;
	struct uint8_t_SQN_NR_SRS_ResourceSet_resourceType_aperiodic_aperiodicSRS_ResourceTriggerList_Dynamic v;
};

struct SQN_NR_SRS_ResourceSet_resourceType_aperiodic {
	uint8_t aperiodicSRS_ResourceTrigger;
	struct SQN_NR_NZP_CSI_RS_ResourceId_SQN_NR_SRS_ResourceSet_resourceType_aperiodic_csi_RS_Optional csi_RS;
	struct uint8_t_SQN_NR_SRS_ResourceSet_resourceType_aperiodic_slotOffset_Optional slotOffset;
	struct uint8_t_SQN_NR_SRS_ResourceSet_resourceType_aperiodic_aperiodicSRS_ResourceTriggerList_DynamicOptional aperiodicSRS_ResourceTriggerList;
};

struct SQN_NR_NZP_CSI_RS_ResourceId_SQN_NR_SRS_ResourceSet_resourceType_semi_persistent_associatedCSI_RS_Optional {
	bool d;
	SQN_NR_NZP_CSI_RS_ResourceId v;
};

struct SQN_NR_SRS_ResourceSet_resourceType_semi_persistent {
	struct SQN_NR_NZP_CSI_RS_ResourceId_SQN_NR_SRS_ResourceSet_resourceType_semi_persistent_associatedCSI_RS_Optional associatedCSI_RS;
};

struct SQN_NR_NZP_CSI_RS_ResourceId_SQN_NR_SRS_ResourceSet_resourceType_periodic_associatedCSI_RS_Optional {
	bool d;
	SQN_NR_NZP_CSI_RS_ResourceId v;
};

struct SQN_NR_SRS_ResourceSet_resourceType_periodic {
	struct SQN_NR_NZP_CSI_RS_ResourceId_SQN_NR_SRS_ResourceSet_resourceType_periodic_associatedCSI_RS_Optional associatedCSI_RS;
};

enum SQN_NR_SRS_ResourceSet_resourceType_Sel {
	SQN_NR_SRS_ResourceSet_resourceType_UNBOUND_VALUE = 0,
	SQN_NR_SRS_ResourceSet_resourceType_aperiodic = 1,
	SQN_NR_SRS_ResourceSet_resourceType_semi_persistent = 2,
	SQN_NR_SRS_ResourceSet_resourceType_periodic = 3,
};

union SQN_NR_SRS_ResourceSet_resourceType_Value {
	struct SQN_NR_SRS_ResourceSet_resourceType_aperiodic aperiodic;
	struct SQN_NR_SRS_ResourceSet_resourceType_semi_persistent semi_persistent;
	struct SQN_NR_SRS_ResourceSet_resourceType_periodic periodic;
};

struct SQN_NR_SRS_ResourceSet_resourceType {
	enum SQN_NR_SRS_ResourceSet_resourceType_Sel d;
	union SQN_NR_SRS_ResourceSet_resourceType_Value v;
};

enum SQN_NR_SRS_ResourceSet_usage_e {
	SQN_NR_SRS_ResourceSet_usage_e_beamManagement = 0,
	SQN_NR_SRS_ResourceSet_usage_e_codebook = 1,
	SQN_NR_SRS_ResourceSet_usage_e_nonCodebook = 2,
	SQN_NR_SRS_ResourceSet_usage_e_antennaSwitching = 3,
};

typedef enum SQN_NR_SRS_ResourceSet_usage_e SQN_NR_SRS_ResourceSet_usage_e;

enum SQN_NR_PathlossReferenceRS_Config_Sel {
	SQN_NR_PathlossReferenceRS_Config_UNBOUND_VALUE = 0,
	SQN_NR_PathlossReferenceRS_Config_ssb_Index = 1,
	SQN_NR_PathlossReferenceRS_Config_csi_RS_Index = 2,
};

union SQN_NR_PathlossReferenceRS_Config_Value {
	SQN_NR_SSB_Index ssb_Index;
	SQN_NR_NZP_CSI_RS_ResourceId csi_RS_Index;
};

struct SQN_NR_PathlossReferenceRS_Config {
	enum SQN_NR_PathlossReferenceRS_Config_Sel d;
	union SQN_NR_PathlossReferenceRS_Config_Value v;
};

enum SQN_NR_SRS_ResourceSet_srs_PowerControlAdjustmentStates_e {
	SQN_NR_SRS_ResourceSet_srs_PowerControlAdjustmentStates_e_sameAsFci2 = 0,
	SQN_NR_SRS_ResourceSet_srs_PowerControlAdjustmentStates_e_separateClosedLoop = 1,
};

typedef enum SQN_NR_SRS_ResourceSet_srs_PowerControlAdjustmentStates_e SQN_NR_SRS_ResourceSet_srs_PowerControlAdjustmentStates_e;

typedef uint8_t SQN_NR_SRS_PathlossReferenceRS_Id_r16;

struct SQN_NR_PathlossReferenceRS_r16 {
	SQN_NR_SRS_PathlossReferenceRS_Id_r16 srs_PathlossReferenceRS_Id_r16;
	struct SQN_NR_PathlossReferenceRS_Config pathlossReferenceRS_r16;
};

struct SQN_NR_PathlossReferenceRS_r16_SQN_NR_PathlossReferenceRSList_r16_Dynamic {
	size_t d;
	struct SQN_NR_PathlossReferenceRS_r16* v;
};

typedef struct SQN_NR_PathlossReferenceRS_r16_SQN_NR_PathlossReferenceRSList_r16_Dynamic SQN_NR_PathlossReferenceRSList_r16;

enum SQN_NR_SetupRelease_SRS_ResourceSet_pathlossReferenceRSList_r16_Sel {
	SQN_NR_SetupRelease_SRS_ResourceSet_pathlossReferenceRSList_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_SRS_ResourceSet_pathlossReferenceRSList_r16_release = 1,
	SQN_NR_SetupRelease_SRS_ResourceSet_pathlossReferenceRSList_r16_setup = 2,
};

union SQN_NR_SetupRelease_SRS_ResourceSet_pathlossReferenceRSList_r16_Value {
	Null release;
	SQN_NR_PathlossReferenceRSList_r16 setup;
};

struct SQN_NR_SetupRelease_SRS_ResourceSet_pathlossReferenceRSList_r16 {
	enum SQN_NR_SetupRelease_SRS_ResourceSet_pathlossReferenceRSList_r16_Sel d;
	union SQN_NR_SetupRelease_SRS_ResourceSet_pathlossReferenceRSList_r16_Value v;
};

struct SQN_NR_SRS_ResourceId_SQN_NR_SRS_ResourceSet_srs_ResourceIdList_Dynamic {
	size_t d;
	SQN_NR_SRS_ResourceId* v;
};

struct SQN_NR_SRS_ResourceId_SQN_NR_SRS_ResourceSet_srs_ResourceIdList_DynamicOptional {
	bool d;
	struct SQN_NR_SRS_ResourceId_SQN_NR_SRS_ResourceSet_srs_ResourceIdList_Dynamic v;
};

struct SQN_NR_Alpha_e_SQN_NR_SRS_ResourceSet_alpha_Optional {
	bool d;
	SQN_NR_Alpha_e v;
};

struct int16_t_SQN_NR_SRS_ResourceSet_p0_Optional {
	bool d;
	int16_t v;
};

struct SQN_NR_PathlossReferenceRS_Config_SQN_NR_SRS_ResourceSet_pathlossReferenceRS_Optional {
	bool d;
	struct SQN_NR_PathlossReferenceRS_Config v;
};

struct SQN_NR_SRS_ResourceSet_srs_PowerControlAdjustmentStates_e_srs_PowerControlAdjustmentStates_Optional {
	bool d;
	SQN_NR_SRS_ResourceSet_srs_PowerControlAdjustmentStates_e v;
};

struct SQN_NR_SetupRelease_SRS_ResourceSet_pathlossReferenceRSList_r16_SQN_NR_SRS_ResourceSet_pathlossReferenceRSList_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_SRS_ResourceSet_pathlossReferenceRSList_r16 v;
};

struct SQN_NR_SRS_ResourceSet {
	SQN_NR_SRS_ResourceSetId srs_ResourceSetId;
	struct SQN_NR_SRS_ResourceId_SQN_NR_SRS_ResourceSet_srs_ResourceIdList_DynamicOptional srs_ResourceIdList;
	struct SQN_NR_SRS_ResourceSet_resourceType resourceType;
	SQN_NR_SRS_ResourceSet_usage_e usage;
	struct SQN_NR_Alpha_e_SQN_NR_SRS_ResourceSet_alpha_Optional alpha;
	struct int16_t_SQN_NR_SRS_ResourceSet_p0_Optional p0;
	struct SQN_NR_PathlossReferenceRS_Config_SQN_NR_SRS_ResourceSet_pathlossReferenceRS_Optional pathlossReferenceRS;
	struct SQN_NR_SRS_ResourceSet_srs_PowerControlAdjustmentStates_e_srs_PowerControlAdjustmentStates_Optional srs_PowerControlAdjustmentStates;
	struct SQN_NR_SetupRelease_SRS_ResourceSet_pathlossReferenceRSList_r16_SQN_NR_SRS_ResourceSet_pathlossReferenceRSList_r16_Optional pathlossReferenceRSList_r16;
};

enum SQN_NR_SRS_Resource_nrofSRS_Ports_e {
	SQN_NR_SRS_Resource_nrofSRS_Ports_e_port1 = 0,
	SQN_NR_SRS_Resource_nrofSRS_Ports_e_ports2 = 1,
	SQN_NR_SRS_Resource_nrofSRS_Ports_e_ports4 = 2,
};

typedef enum SQN_NR_SRS_Resource_nrofSRS_Ports_e SQN_NR_SRS_Resource_nrofSRS_Ports_e;

enum SQN_NR_SRS_Resource_ptrs_PortIndex_e {
	SQN_NR_SRS_Resource_ptrs_PortIndex_e_n0 = 0,
	SQN_NR_SRS_Resource_ptrs_PortIndex_e_n1 = 1,
};

typedef enum SQN_NR_SRS_Resource_ptrs_PortIndex_e SQN_NR_SRS_Resource_ptrs_PortIndex_e;

struct SQN_NR_SRS_Resource_transmissionComb_n2 {
	uint8_t combOffset_n2;
	uint8_t cyclicShift_n2;
};

struct SQN_NR_SRS_Resource_transmissionComb_n4 {
	uint8_t combOffset_n4;
	uint8_t cyclicShift_n4;
};

enum SQN_NR_SRS_Resource_transmissionComb_Sel {
	SQN_NR_SRS_Resource_transmissionComb_UNBOUND_VALUE = 0,
	SQN_NR_SRS_Resource_transmissionComb_n2 = 1,
	SQN_NR_SRS_Resource_transmissionComb_n4 = 2,
};

union SQN_NR_SRS_Resource_transmissionComb_Value {
	struct SQN_NR_SRS_Resource_transmissionComb_n2 n2;
	struct SQN_NR_SRS_Resource_transmissionComb_n4 n4;
};

struct SQN_NR_SRS_Resource_transmissionComb {
	enum SQN_NR_SRS_Resource_transmissionComb_Sel d;
	union SQN_NR_SRS_Resource_transmissionComb_Value v;
};

enum SQN_NR_SRS_Resource_resourceMapping_nrofSymbols_e {
	SQN_NR_SRS_Resource_resourceMapping_nrofSymbols_e_n1 = 0,
	SQN_NR_SRS_Resource_resourceMapping_nrofSymbols_e_n2 = 1,
	SQN_NR_SRS_Resource_resourceMapping_nrofSymbols_e_n4 = 2,
};

typedef enum SQN_NR_SRS_Resource_resourceMapping_nrofSymbols_e SQN_NR_SRS_Resource_resourceMapping_nrofSymbols_e;

enum SQN_NR_SRS_Resource_resourceMapping_repetitionFactor_e {
	SQN_NR_SRS_Resource_resourceMapping_repetitionFactor_e_n1 = 0,
	SQN_NR_SRS_Resource_resourceMapping_repetitionFactor_e_n2 = 1,
	SQN_NR_SRS_Resource_resourceMapping_repetitionFactor_e_n4 = 2,
};

typedef enum SQN_NR_SRS_Resource_resourceMapping_repetitionFactor_e SQN_NR_SRS_Resource_resourceMapping_repetitionFactor_e;

struct SQN_NR_SRS_Resource_resourceMapping {
	uint8_t startPosition;
	SQN_NR_SRS_Resource_resourceMapping_nrofSymbols_e nrofSymbols;
	SQN_NR_SRS_Resource_resourceMapping_repetitionFactor_e repetitionFactor;
};

struct SQN_NR_SRS_Resource_freqHopping {
	uint8_t c_SRS;
	uint8_t b_SRS;
	uint8_t b_hop;
};

enum SQN_NR_SRS_Resource_groupOrSequenceHopping_e {
	SQN_NR_SRS_Resource_groupOrSequenceHopping_e_neither = 0,
	SQN_NR_SRS_Resource_groupOrSequenceHopping_e_groupHopping = 1,
	SQN_NR_SRS_Resource_groupOrSequenceHopping_e_sequenceHopping = 2,
};

typedef enum SQN_NR_SRS_Resource_groupOrSequenceHopping_e SQN_NR_SRS_Resource_groupOrSequenceHopping_e;

struct SQN_NR_SRS_Resource_resourceType_aperiodic {
};

enum SQN_NR_SRS_PeriodicityAndOffset_Sel {
	SQN_NR_SRS_PeriodicityAndOffset_UNBOUND_VALUE = 0,
	SQN_NR_SRS_PeriodicityAndOffset_sl1 = 1,
	SQN_NR_SRS_PeriodicityAndOffset_sl2 = 2,
	SQN_NR_SRS_PeriodicityAndOffset_sl4 = 3,
	SQN_NR_SRS_PeriodicityAndOffset_sl5 = 4,
	SQN_NR_SRS_PeriodicityAndOffset_sl8 = 5,
	SQN_NR_SRS_PeriodicityAndOffset_sl10 = 6,
	SQN_NR_SRS_PeriodicityAndOffset_sl16 = 7,
	SQN_NR_SRS_PeriodicityAndOffset_sl20 = 8,
	SQN_NR_SRS_PeriodicityAndOffset_sl32 = 9,
	SQN_NR_SRS_PeriodicityAndOffset_sl40 = 10,
	SQN_NR_SRS_PeriodicityAndOffset_sl64 = 11,
	SQN_NR_SRS_PeriodicityAndOffset_sl80 = 12,
	SQN_NR_SRS_PeriodicityAndOffset_sl160 = 13,
	SQN_NR_SRS_PeriodicityAndOffset_sl320 = 14,
	SQN_NR_SRS_PeriodicityAndOffset_sl640 = 15,
	SQN_NR_SRS_PeriodicityAndOffset_sl1280 = 16,
	SQN_NR_SRS_PeriodicityAndOffset_sl2560 = 17,
};

union SQN_NR_SRS_PeriodicityAndOffset_Value {
	Null sl1;
	uint8_t sl2;
	uint8_t sl4;
	uint8_t sl5;
	uint8_t sl8;
	uint8_t sl10;
	uint8_t sl16;
	uint8_t sl20;
	uint8_t sl32;
	uint8_t sl40;
	uint8_t sl64;
	uint8_t sl80;
	uint8_t sl160;
	uint16_t sl320;
	uint16_t sl640;
	uint16_t sl1280;
	uint16_t sl2560;
};

struct SQN_NR_SRS_PeriodicityAndOffset {
	enum SQN_NR_SRS_PeriodicityAndOffset_Sel d;
	union SQN_NR_SRS_PeriodicityAndOffset_Value v;
};

struct SQN_NR_SRS_Resource_resourceType_semi_persistent {
	struct SQN_NR_SRS_PeriodicityAndOffset periodicityAndOffset_sp;
};

struct SQN_NR_SRS_Resource_resourceType_periodic {
	struct SQN_NR_SRS_PeriodicityAndOffset periodicityAndOffset_p;
};

enum SQN_NR_SRS_Resource_resourceType_Sel {
	SQN_NR_SRS_Resource_resourceType_UNBOUND_VALUE = 0,
	SQN_NR_SRS_Resource_resourceType_aperiodic = 1,
	SQN_NR_SRS_Resource_resourceType_semi_persistent = 2,
	SQN_NR_SRS_Resource_resourceType_periodic = 3,
};

union SQN_NR_SRS_Resource_resourceType_Value {
	struct SQN_NR_SRS_Resource_resourceType_aperiodic aperiodic;
	struct SQN_NR_SRS_Resource_resourceType_semi_persistent semi_persistent;
	struct SQN_NR_SRS_Resource_resourceType_periodic periodic;
};

struct SQN_NR_SRS_Resource_resourceType {
	enum SQN_NR_SRS_Resource_resourceType_Sel d;
	union SQN_NR_SRS_Resource_resourceType_Value v;
};

struct SQN_NR_SRS_SpatialRelationInfo_referenceSignal_srs {
	SQN_NR_SRS_ResourceId resourceId;
	SQN_NR_BWP_Id uplinkBWP;
};

enum SQN_NR_SRS_SpatialRelationInfo_referenceSignal_Sel {
	SQN_NR_SRS_SpatialRelationInfo_referenceSignal_UNBOUND_VALUE = 0,
	SQN_NR_SRS_SpatialRelationInfo_referenceSignal_ssb_Index = 1,
	SQN_NR_SRS_SpatialRelationInfo_referenceSignal_csi_RS_Index = 2,
	SQN_NR_SRS_SpatialRelationInfo_referenceSignal_srs = 3,
};

union SQN_NR_SRS_SpatialRelationInfo_referenceSignal_Value {
	SQN_NR_SSB_Index ssb_Index;
	SQN_NR_NZP_CSI_RS_ResourceId csi_RS_Index;
	struct SQN_NR_SRS_SpatialRelationInfo_referenceSignal_srs srs;
};

struct SQN_NR_SRS_SpatialRelationInfo_referenceSignal {
	enum SQN_NR_SRS_SpatialRelationInfo_referenceSignal_Sel d;
	union SQN_NR_SRS_SpatialRelationInfo_referenceSignal_Value v;
};

struct SQN_NR_ServCellIndex_SQN_NR_SRS_SpatialRelationInfo_servingCellId_Optional {
	bool d;
	SQN_NR_ServCellIndex v;
};

struct SQN_NR_SRS_SpatialRelationInfo {
	struct SQN_NR_ServCellIndex_SQN_NR_SRS_SpatialRelationInfo_servingCellId_Optional servingCellId;
	struct SQN_NR_SRS_SpatialRelationInfo_referenceSignal referenceSignal;
};

enum SQN_NR_SRS_Resource_resourceMapping_r16_nrofSymbols_r16_e {
	SQN_NR_SRS_Resource_resourceMapping_r16_nrofSymbols_r16_e_n1 = 0,
	SQN_NR_SRS_Resource_resourceMapping_r16_nrofSymbols_r16_e_n2 = 1,
	SQN_NR_SRS_Resource_resourceMapping_r16_nrofSymbols_r16_e_n4 = 2,
};

typedef enum SQN_NR_SRS_Resource_resourceMapping_r16_nrofSymbols_r16_e SQN_NR_SRS_Resource_resourceMapping_r16_nrofSymbols_r16_e;

enum SQN_NR_SRS_Resource_resourceMapping_r16_repetitionFactor_r16_e {
	SQN_NR_SRS_Resource_resourceMapping_r16_repetitionFactor_r16_e_n1 = 0,
	SQN_NR_SRS_Resource_resourceMapping_r16_repetitionFactor_r16_e_n2 = 1,
	SQN_NR_SRS_Resource_resourceMapping_r16_repetitionFactor_r16_e_n4 = 2,
};

typedef enum SQN_NR_SRS_Resource_resourceMapping_r16_repetitionFactor_r16_e SQN_NR_SRS_Resource_resourceMapping_r16_repetitionFactor_r16_e;

struct SQN_NR_SRS_Resource_resourceMapping_r16 {
	uint8_t startPosition_r16;
	SQN_NR_SRS_Resource_resourceMapping_r16_nrofSymbols_r16_e nrofSymbols_r16;
	SQN_NR_SRS_Resource_resourceMapping_r16_repetitionFactor_r16_e repetitionFactor_r16;
};

struct SQN_NR_SRS_Resource_ptrs_PortIndex_e_ptrs_PortIndex_Optional {
	bool d;
	SQN_NR_SRS_Resource_ptrs_PortIndex_e v;
};

struct SQN_NR_SRS_SpatialRelationInfo_SQN_NR_SRS_Resource_spatialRelationInfo_Optional {
	bool d;
	struct SQN_NR_SRS_SpatialRelationInfo v;
};

struct SQN_NR_SRS_Resource_resourceMapping_r16_resourceMapping_r16_Optional {
	bool d;
	struct SQN_NR_SRS_Resource_resourceMapping_r16 v;
};

struct SQN_NR_SRS_Resource {
	SQN_NR_SRS_ResourceId srs_ResourceId;
	SQN_NR_SRS_Resource_nrofSRS_Ports_e nrofSRS_Ports;
	struct SQN_NR_SRS_Resource_ptrs_PortIndex_e_ptrs_PortIndex_Optional ptrs_PortIndex;
	struct SQN_NR_SRS_Resource_transmissionComb transmissionComb;
	struct SQN_NR_SRS_Resource_resourceMapping resourceMapping;
	uint8_t freqDomainPosition;
	uint16_t freqDomainShift;
	struct SQN_NR_SRS_Resource_freqHopping freqHopping;
	SQN_NR_SRS_Resource_groupOrSequenceHopping_e groupOrSequenceHopping;
	struct SQN_NR_SRS_Resource_resourceType resourceType;
	uint16_t sequenceId;
	struct SQN_NR_SRS_SpatialRelationInfo_SQN_NR_SRS_Resource_spatialRelationInfo_Optional spatialRelationInfo;
	struct SQN_NR_SRS_Resource_resourceMapping_r16_resourceMapping_r16_Optional resourceMapping_r16;
};

enum SQN_NR_SRS_Config_tpc_Accumulation_e {
	SQN_NR_SRS_Config_tpc_Accumulation_e_disabled = 0,
};

typedef enum SQN_NR_SRS_Config_tpc_Accumulation_e SQN_NR_SRS_Config_tpc_Accumulation_e;

typedef uint8_t SQN_NR_SRS_PosResourceSetId_r16;

typedef uint8_t SQN_NR_SRS_PosResourceId_r16;

struct uint8_t_SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_aperiodic_r16_aperiodicSRS_ResourceTriggerList_r16_Dynamic {
	size_t d;
	uint8_t* v;
};

struct uint8_t_SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_aperiodic_r16_aperiodicSRS_ResourceTriggerList_r16_DynamicOptional {
	bool d;
	struct uint8_t_SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_aperiodic_r16_aperiodicSRS_ResourceTriggerList_r16_Dynamic v;
};

struct SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_aperiodic_r16 {
	struct uint8_t_SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_aperiodic_r16_aperiodicSRS_ResourceTriggerList_r16_DynamicOptional aperiodicSRS_ResourceTriggerList_r16;
};

struct SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_semi_persistent_r16 {
};

struct SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_periodic_r16 {
};

enum SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_Sel {
	SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_UNBOUND_VALUE = 0,
	SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_aperiodic_r16 = 1,
	SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_semi_persistent_r16 = 2,
	SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_periodic_r16 = 3,
};

union SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_Value {
	struct SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_aperiodic_r16 aperiodic_r16;
	struct SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_semi_persistent_r16 semi_persistent_r16;
	struct SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_periodic_r16 periodic_r16;
};

struct SQN_NR_SRS_PosResourceSet_r16_resourceType_r16 {
	enum SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_Sel d;
	union SQN_NR_SRS_PosResourceSet_r16_resourceType_r16_Value v;
};

enum SQN_NR_SSB_Configuration_r16_halfFrameIndex_r16_e {
	SQN_NR_SSB_Configuration_r16_halfFrameIndex_r16_e_zero = 0,
	SQN_NR_SSB_Configuration_r16_halfFrameIndex_r16_e_one = 1,
};

typedef enum SQN_NR_SSB_Configuration_r16_halfFrameIndex_r16_e SQN_NR_SSB_Configuration_r16_halfFrameIndex_r16_e;

enum SQN_NR_SSB_Configuration_r16_ssb_Periodicity_r16_e {
	SQN_NR_SSB_Configuration_r16_ssb_Periodicity_r16_e_ms5 = 0,
	SQN_NR_SSB_Configuration_r16_ssb_Periodicity_r16_e_ms10 = 1,
	SQN_NR_SSB_Configuration_r16_ssb_Periodicity_r16_e_ms20 = 2,
	SQN_NR_SSB_Configuration_r16_ssb_Periodicity_r16_e_ms40 = 3,
	SQN_NR_SSB_Configuration_r16_ssb_Periodicity_r16_e_ms80 = 4,
	SQN_NR_SSB_Configuration_r16_ssb_Periodicity_r16_e_ms160 = 5,
	SQN_NR_SSB_Configuration_r16_ssb_Periodicity_r16_e_spare2 = 6,
	SQN_NR_SSB_Configuration_r16_ssb_Periodicity_r16_e_spare1 = 7,
};

typedef enum SQN_NR_SSB_Configuration_r16_ssb_Periodicity_r16_e SQN_NR_SSB_Configuration_r16_ssb_Periodicity_r16_e;

struct uint8_t_SQN_NR_SSB_Configuration_r16_sfn0_Offset_r16_integerSubframeOffset_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_SSB_Configuration_r16_sfn0_Offset_r16 {
	uint16_t sfn_Offset_r16;
	struct uint8_t_SQN_NR_SSB_Configuration_r16_sfn0_Offset_r16_integerSubframeOffset_r16_Optional integerSubframeOffset_r16;
};

struct SQN_NR_SSB_Configuration_r16_ssb_Periodicity_r16_e_ssb_Periodicity_r16_Optional {
	bool d;
	SQN_NR_SSB_Configuration_r16_ssb_Periodicity_r16_e v;
};

struct SQN_NR_SSB_Configuration_r16_sfn0_Offset_r16_sfn0_Offset_r16_Optional {
	bool d;
	struct SQN_NR_SSB_Configuration_r16_sfn0_Offset_r16 v;
};

struct int8_t_SQN_NR_SSB_Configuration_r16_ss_PBCH_BlockPower_r16_Optional {
	bool d;
	int8_t v;
};

struct SQN_NR_SSB_Configuration_r16 {
	SQN_NR_ARFCN_ValueNR ssb_Freq_r16;
	SQN_NR_SSB_Configuration_r16_halfFrameIndex_r16_e halfFrameIndex_r16;
	SQN_NR_SubcarrierSpacing_e ssbSubcarrierSpacing_r16;
	struct SQN_NR_SSB_Configuration_r16_ssb_Periodicity_r16_e_ssb_Periodicity_r16_Optional ssb_Periodicity_r16;
	struct SQN_NR_SSB_Configuration_r16_sfn0_Offset_r16_sfn0_Offset_r16_Optional sfn0_Offset_r16;
	uint8_t sfn_SSB_Offset_r16;
	struct int8_t_SQN_NR_SSB_Configuration_r16_ss_PBCH_BlockPower_r16_Optional ss_PBCH_BlockPower_r16;
};

struct SQN_NR_SSB_Index_SQN_NR_SSB_InfoNcell_r16_ssb_IndexNcell_r16_Optional {
	bool d;
	SQN_NR_SSB_Index v;
};

struct SQN_NR_SSB_Configuration_r16_SQN_NR_SSB_InfoNcell_r16_ssb_Configuration_r16_Optional {
	bool d;
	struct SQN_NR_SSB_Configuration_r16 v;
};

struct SQN_NR_SSB_InfoNcell_r16 {
	SQN_NR_PhysCellId physicalCellId_r16;
	struct SQN_NR_SSB_Index_SQN_NR_SSB_InfoNcell_r16_ssb_IndexNcell_r16_Optional ssb_IndexNcell_r16;
	struct SQN_NR_SSB_Configuration_r16_SQN_NR_SSB_InfoNcell_r16_ssb_Configuration_r16_Optional ssb_Configuration_r16;
};

struct uint8_t_SQN_NR_DL_PRS_Info_r16_dl_PRS_ResourceId_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_DL_PRS_Info_r16 {
	uint8_t dl_PRS_ID_r16;
	uint8_t dl_PRS_ResourceSetId_r16;
	struct uint8_t_SQN_NR_DL_PRS_Info_r16_dl_PRS_ResourceId_r16_Optional dl_PRS_ResourceId_r16;
};

enum SQN_NR_SRS_PosResourceSet_r16_pathlossReferenceRS_Pos_r16_Sel {
	SQN_NR_SRS_PosResourceSet_r16_pathlossReferenceRS_Pos_r16_UNBOUND_VALUE = 0,
	SQN_NR_SRS_PosResourceSet_r16_pathlossReferenceRS_Pos_r16_ssb_IndexServing_r16 = 1,
	SQN_NR_SRS_PosResourceSet_r16_pathlossReferenceRS_Pos_r16_ssb_Ncell_r16 = 2,
	SQN_NR_SRS_PosResourceSet_r16_pathlossReferenceRS_Pos_r16_dl_PRS_r16 = 3,
};

union SQN_NR_SRS_PosResourceSet_r16_pathlossReferenceRS_Pos_r16_Value {
	SQN_NR_SSB_Index ssb_IndexServing_r16;
	struct SQN_NR_SSB_InfoNcell_r16 ssb_Ncell_r16;
	struct SQN_NR_DL_PRS_Info_r16 dl_PRS_r16;
};

struct SQN_NR_SRS_PosResourceSet_r16_pathlossReferenceRS_Pos_r16 {
	enum SQN_NR_SRS_PosResourceSet_r16_pathlossReferenceRS_Pos_r16_Sel d;
	union SQN_NR_SRS_PosResourceSet_r16_pathlossReferenceRS_Pos_r16_Value v;
};

struct SQN_NR_SRS_PosResourceId_r16_SQN_NR_SRS_PosResourceSet_r16_srs_PosResourceIdList_r16_Dynamic {
	size_t d;
	SQN_NR_SRS_PosResourceId_r16* v;
};

struct SQN_NR_SRS_PosResourceId_r16_SQN_NR_SRS_PosResourceSet_r16_srs_PosResourceIdList_r16_DynamicOptional {
	bool d;
	struct SQN_NR_SRS_PosResourceId_r16_SQN_NR_SRS_PosResourceSet_r16_srs_PosResourceIdList_r16_Dynamic v;
};

struct SQN_NR_Alpha_e_SQN_NR_SRS_PosResourceSet_r16_alpha_r16_Optional {
	bool d;
	SQN_NR_Alpha_e v;
};

struct int16_t_SQN_NR_SRS_PosResourceSet_r16_p0_r16_Optional {
	bool d;
	int16_t v;
};

struct SQN_NR_SRS_PosResourceSet_r16_pathlossReferenceRS_Pos_r16_pathlossReferenceRS_Pos_r16_Optional {
	bool d;
	struct SQN_NR_SRS_PosResourceSet_r16_pathlossReferenceRS_Pos_r16 v;
};

struct SQN_NR_SRS_PosResourceSet_r16 {
	SQN_NR_SRS_PosResourceSetId_r16 srs_PosResourceSetId_r16;
	struct SQN_NR_SRS_PosResourceId_r16_SQN_NR_SRS_PosResourceSet_r16_srs_PosResourceIdList_r16_DynamicOptional srs_PosResourceIdList_r16;
	struct SQN_NR_SRS_PosResourceSet_r16_resourceType_r16 resourceType_r16;
	struct SQN_NR_Alpha_e_SQN_NR_SRS_PosResourceSet_r16_alpha_r16_Optional alpha_r16;
	struct int16_t_SQN_NR_SRS_PosResourceSet_r16_p0_r16_Optional p0_r16;
	struct SQN_NR_SRS_PosResourceSet_r16_pathlossReferenceRS_Pos_r16_pathlossReferenceRS_Pos_r16_Optional pathlossReferenceRS_Pos_r16;
};

struct SQN_NR_SRS_PosResource_r16_transmissionComb_r16_n2_r16 {
	uint8_t combOffset_n2_r16;
	uint8_t cyclicShift_n2_r16;
};

struct SQN_NR_SRS_PosResource_r16_transmissionComb_r16_n4_r16 {
	uint8_t combOffset_n4_16;
	uint8_t cyclicShift_n4_r16;
};

struct SQN_NR_SRS_PosResource_r16_transmissionComb_r16_n8_r16 {
	uint8_t combOffset_n8_r16;
	uint8_t cyclicShift_n8_r16;
};

enum SQN_NR_SRS_PosResource_r16_transmissionComb_r16_Sel {
	SQN_NR_SRS_PosResource_r16_transmissionComb_r16_UNBOUND_VALUE = 0,
	SQN_NR_SRS_PosResource_r16_transmissionComb_r16_n2_r16 = 1,
	SQN_NR_SRS_PosResource_r16_transmissionComb_r16_n4_r16 = 2,
	SQN_NR_SRS_PosResource_r16_transmissionComb_r16_n8_r16 = 3,
};

union SQN_NR_SRS_PosResource_r16_transmissionComb_r16_Value {
	struct SQN_NR_SRS_PosResource_r16_transmissionComb_r16_n2_r16 n2_r16;
	struct SQN_NR_SRS_PosResource_r16_transmissionComb_r16_n4_r16 n4_r16;
	struct SQN_NR_SRS_PosResource_r16_transmissionComb_r16_n8_r16 n8_r16;
};

struct SQN_NR_SRS_PosResource_r16_transmissionComb_r16 {
	enum SQN_NR_SRS_PosResource_r16_transmissionComb_r16_Sel d;
	union SQN_NR_SRS_PosResource_r16_transmissionComb_r16_Value v;
};

enum SQN_NR_SRS_PosResource_r16_resourceMapping_r16_nrofSymbols_r16_e {
	SQN_NR_SRS_PosResource_r16_resourceMapping_r16_nrofSymbols_r16_e_n1 = 0,
	SQN_NR_SRS_PosResource_r16_resourceMapping_r16_nrofSymbols_r16_e_n2 = 1,
	SQN_NR_SRS_PosResource_r16_resourceMapping_r16_nrofSymbols_r16_e_n4 = 2,
	SQN_NR_SRS_PosResource_r16_resourceMapping_r16_nrofSymbols_r16_e_n8 = 3,
	SQN_NR_SRS_PosResource_r16_resourceMapping_r16_nrofSymbols_r16_e_n12 = 4,
};

typedef enum SQN_NR_SRS_PosResource_r16_resourceMapping_r16_nrofSymbols_r16_e SQN_NR_SRS_PosResource_r16_resourceMapping_r16_nrofSymbols_r16_e;

struct SQN_NR_SRS_PosResource_r16_resourceMapping_r16 {
	uint8_t startPosition_r16;
	SQN_NR_SRS_PosResource_r16_resourceMapping_r16_nrofSymbols_r16_e nrofSymbols_r16;
};

struct SQN_NR_SRS_PosResource_r16_freqHopping_r16 {
	uint8_t c_SRS_r16;
};

enum SQN_NR_SRS_PosResource_r16_groupOrSequenceHopping_r16_e {
	SQN_NR_SRS_PosResource_r16_groupOrSequenceHopping_r16_e_neither = 0,
	SQN_NR_SRS_PosResource_r16_groupOrSequenceHopping_r16_e_groupHopping = 1,
	SQN_NR_SRS_PosResource_r16_groupOrSequenceHopping_r16_e_sequenceHopping = 2,
};

typedef enum SQN_NR_SRS_PosResource_r16_groupOrSequenceHopping_r16_e SQN_NR_SRS_PosResource_r16_groupOrSequenceHopping_r16_e;

struct uint8_t_SQN_NR_SRS_PosResource_r16_resourceType_r16_aperiodic_r16_slotOffset_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_SRS_PosResource_r16_resourceType_r16_aperiodic_r16 {
	struct uint8_t_SQN_NR_SRS_PosResource_r16_resourceType_r16_aperiodic_r16_slotOffset_r16_Optional slotOffset_r16;
};

enum SQN_NR_SRS_PeriodicityAndOffset_r16_Sel {
	SQN_NR_SRS_PeriodicityAndOffset_r16_UNBOUND_VALUE = 0,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl1 = 1,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl2 = 2,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl4 = 3,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl5 = 4,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl8 = 5,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl10 = 6,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl16 = 7,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl20 = 8,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl32 = 9,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl40 = 10,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl64 = 11,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl80 = 12,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl160 = 13,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl320 = 14,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl640 = 15,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl1280 = 16,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl2560 = 17,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl5120 = 18,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl10240 = 19,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl40960 = 20,
	SQN_NR_SRS_PeriodicityAndOffset_r16_sl81920 = 21,
};

union SQN_NR_SRS_PeriodicityAndOffset_r16_Value {
	Null sl1;
	uint8_t sl2;
	uint8_t sl4;
	uint8_t sl5;
	uint8_t sl8;
	uint8_t sl10;
	uint8_t sl16;
	uint8_t sl20;
	uint8_t sl32;
	uint8_t sl40;
	uint8_t sl64;
	uint8_t sl80;
	uint8_t sl160;
	uint16_t sl320;
	uint16_t sl640;
	uint16_t sl1280;
	uint16_t sl2560;
	uint16_t sl5120;
	uint16_t sl10240;
	uint16_t sl40960;
	uint32_t sl81920;
};

struct SQN_NR_SRS_PeriodicityAndOffset_r16 {
	enum SQN_NR_SRS_PeriodicityAndOffset_r16_Sel d;
	union SQN_NR_SRS_PeriodicityAndOffset_r16_Value v;
};

struct SQN_NR_SRS_PosResource_r16_resourceType_r16_semi_persistent_r16 {
	struct SQN_NR_SRS_PeriodicityAndOffset_r16 periodicityAndOffset_sp_r16;
};

struct SQN_NR_SRS_PosResource_r16_resourceType_r16_periodic_r16 {
	struct SQN_NR_SRS_PeriodicityAndOffset_r16 periodicityAndOffset_p_r16;
};

enum SQN_NR_SRS_PosResource_r16_resourceType_r16_Sel {
	SQN_NR_SRS_PosResource_r16_resourceType_r16_UNBOUND_VALUE = 0,
	SQN_NR_SRS_PosResource_r16_resourceType_r16_aperiodic_r16 = 1,
	SQN_NR_SRS_PosResource_r16_resourceType_r16_semi_persistent_r16 = 2,
	SQN_NR_SRS_PosResource_r16_resourceType_r16_periodic_r16 = 3,
};

union SQN_NR_SRS_PosResource_r16_resourceType_r16_Value {
	struct SQN_NR_SRS_PosResource_r16_resourceType_r16_aperiodic_r16 aperiodic_r16;
	struct SQN_NR_SRS_PosResource_r16_resourceType_r16_semi_persistent_r16 semi_persistent_r16;
	struct SQN_NR_SRS_PosResource_r16_resourceType_r16_periodic_r16 periodic_r16;
};

struct SQN_NR_SRS_PosResource_r16_resourceType_r16 {
	enum SQN_NR_SRS_PosResource_r16_resourceType_r16_Sel d;
	union SQN_NR_SRS_PosResource_r16_resourceType_r16_Value v;
};

enum SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_srs_SpatialRelation_r16resourceSelection_r16_Sel {
	SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_srs_SpatialRelation_r16resourceSelection_r16_UNBOUND_VALUE = 0,
	SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_srs_SpatialRelation_r16resourceSelection_r16_srs_ResourceId_r16 = 1,
	SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_srs_SpatialRelation_r16resourceSelection_r16_srs_PosResourceId_r16 = 2,
};

union SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_srs_SpatialRelation_r16resourceSelection_r16_Value {
	SQN_NR_SRS_ResourceId srs_ResourceId_r16;
	SQN_NR_SRS_PosResourceId_r16 srs_PosResourceId_r16;
};

struct SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_srs_SpatialRelation_r16resourceSelection_r16 {
	enum SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_srs_SpatialRelation_r16resourceSelection_r16_Sel d;
	union SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_srs_SpatialRelation_r16resourceSelection_r16_Value v;
};

struct SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_srs_SpatialRelation_r16 {
	struct SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_srs_SpatialRelation_r16resourceSelection_r16 resourceSelection_r16;
	SQN_NR_BWP_Id uplinkBWP_r16;
};

enum SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_Sel {
	SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_UNBOUND_VALUE = 0,
	SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_ssb_IndexServing_r16 = 1,
	SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_csi_RS_IndexServing_r16 = 2,
	SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_srs_SpatialRelation_r16 = 3,
};

union SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_Value {
	SQN_NR_SSB_Index ssb_IndexServing_r16;
	SQN_NR_NZP_CSI_RS_ResourceId csi_RS_IndexServing_r16;
	struct SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_srs_SpatialRelation_r16 srs_SpatialRelation_r16;
};

struct SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16 {
	enum SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_Sel d;
	union SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16_Value v;
};

struct SQN_NR_ServCellIndex_SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_servingCellId_Optional {
	bool d;
	SQN_NR_ServCellIndex v;
};

struct SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16 {
	struct SQN_NR_ServCellIndex_SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_servingCellId_Optional servingCellId;
	struct SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16_referenceSignal_r16 referenceSignal_r16;
};

enum SQN_NR_SRS_SpatialRelationInfoPos_r16_Sel {
	SQN_NR_SRS_SpatialRelationInfoPos_r16_UNBOUND_VALUE = 0,
	SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16 = 1,
	SQN_NR_SRS_SpatialRelationInfoPos_r16_ssb_Ncell_r16 = 2,
	SQN_NR_SRS_SpatialRelationInfoPos_r16_dl_PRS_r16 = 3,
};

union SQN_NR_SRS_SpatialRelationInfoPos_r16_Value {
	struct SQN_NR_SRS_SpatialRelationInfoPos_r16_servingRS_r16 servingRS_r16;
	struct SQN_NR_SSB_InfoNcell_r16 ssb_Ncell_r16;
	struct SQN_NR_DL_PRS_Info_r16 dl_PRS_r16;
};

struct SQN_NR_SRS_SpatialRelationInfoPos_r16 {
	enum SQN_NR_SRS_SpatialRelationInfoPos_r16_Sel d;
	union SQN_NR_SRS_SpatialRelationInfoPos_r16_Value v;
};

struct SQN_NR_SRS_SpatialRelationInfoPos_r16_SQN_NR_SRS_PosResource_r16_spatialRelationInfoPos_r16_Optional {
	bool d;
	struct SQN_NR_SRS_SpatialRelationInfoPos_r16 v;
};

struct SQN_NR_SRS_PosResource_r16 {
	SQN_NR_SRS_PosResourceId_r16 srs_PosResourceId_r16;
	struct SQN_NR_SRS_PosResource_r16_transmissionComb_r16 transmissionComb_r16;
	struct SQN_NR_SRS_PosResource_r16_resourceMapping_r16 resourceMapping_r16;
	uint16_t freqDomainShift_r16;
	struct SQN_NR_SRS_PosResource_r16_freqHopping_r16 freqHopping_r16;
	SQN_NR_SRS_PosResource_r16_groupOrSequenceHopping_r16_e groupOrSequenceHopping_r16;
	struct SQN_NR_SRS_PosResource_r16_resourceType_r16 resourceType_r16;
	uint16_t sequenceId_r16;
	struct SQN_NR_SRS_SpatialRelationInfoPos_r16_SQN_NR_SRS_PosResource_r16_spatialRelationInfoPos_r16_Optional spatialRelationInfoPos_r16;
};

struct SQN_NR_SRS_ResourceSetId_SQN_NR_SRS_Config_srs_ResourceSetToReleaseList_Dynamic {
	size_t d;
	SQN_NR_SRS_ResourceSetId* v;
};

struct SQN_NR_SRS_ResourceSetId_SQN_NR_SRS_Config_srs_ResourceSetToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_SRS_ResourceSetId_SQN_NR_SRS_Config_srs_ResourceSetToReleaseList_Dynamic v;
};

struct SQN_NR_SRS_Config_SQN_NR_SRS_ResourceSet_srs_ResourceSetToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_SRS_ResourceSet* v;
};

struct SQN_NR_SRS_ResourceSet_SQN_NR_SRS_Config_srs_ResourceSetToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_SRS_Config_SQN_NR_SRS_ResourceSet_srs_ResourceSetToAddModList_Dynamic v;
};

struct SQN_NR_SRS_ResourceId_SQN_NR_SRS_Config_srs_ResourceToReleaseList_Dynamic {
	size_t d;
	SQN_NR_SRS_ResourceId* v;
};

struct SQN_NR_SRS_ResourceId_SQN_NR_SRS_Config_srs_ResourceToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_SRS_ResourceId_SQN_NR_SRS_Config_srs_ResourceToReleaseList_Dynamic v;
};

struct SQN_NR_SRS_Config_SQN_NR_SRS_Resource_srs_ResourceToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_SRS_Resource* v;
};

struct SQN_NR_SRS_Resource_SQN_NR_SRS_Config_srs_ResourceToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_SRS_Config_SQN_NR_SRS_Resource_srs_ResourceToAddModList_Dynamic v;
};

struct SQN_NR_SRS_Config_tpc_Accumulation_e_tpc_Accumulation_Optional {
	bool d;
	SQN_NR_SRS_Config_tpc_Accumulation_e v;
};

struct uint8_t_SQN_NR_SRS_Config_srs_RequestDCI_1_2_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_SRS_Config_srs_RequestDCI_0_2_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_SRS_Config_SQN_NR_SRS_ResourceSet_srs_ResourceSetToAddModListDCI_0_2_r16_Dynamic {
	size_t d;
	struct SQN_NR_SRS_ResourceSet* v;
};

struct SQN_NR_SRS_ResourceSet_SQN_NR_SRS_Config_srs_ResourceSetToAddModListDCI_0_2_r16_DynamicOptional {
	bool d;
	struct SQN_NR_SRS_Config_SQN_NR_SRS_ResourceSet_srs_ResourceSetToAddModListDCI_0_2_r16_Dynamic v;
};

struct SQN_NR_SRS_ResourceSetId_SQN_NR_SRS_Config_srs_ResourceSetToReleaseListDCI_0_2_r16_Dynamic {
	size_t d;
	SQN_NR_SRS_ResourceSetId* v;
};

struct SQN_NR_SRS_ResourceSetId_SQN_NR_SRS_Config_srs_ResourceSetToReleaseListDCI_0_2_r16_DynamicOptional {
	bool d;
	struct SQN_NR_SRS_ResourceSetId_SQN_NR_SRS_Config_srs_ResourceSetToReleaseListDCI_0_2_r16_Dynamic v;
};

struct SQN_NR_SRS_PosResourceSetId_r16_SQN_NR_SRS_Config_srs_PosResourceSetToReleaseList_r16_Dynamic {
	size_t d;
	SQN_NR_SRS_PosResourceSetId_r16* v;
};

struct SQN_NR_SRS_PosResourceSetId_r16_SQN_NR_SRS_Config_srs_PosResourceSetToReleaseList_r16_DynamicOptional {
	bool d;
	struct SQN_NR_SRS_PosResourceSetId_r16_SQN_NR_SRS_Config_srs_PosResourceSetToReleaseList_r16_Dynamic v;
};

struct SQN_NR_SRS_Config_SQN_NR_SRS_PosResourceSet_r16_srs_PosResourceSetToAddModList_r16_Dynamic {
	size_t d;
	struct SQN_NR_SRS_PosResourceSet_r16* v;
};

struct SQN_NR_SRS_PosResourceSet_r16_SQN_NR_SRS_Config_srs_PosResourceSetToAddModList_r16_DynamicOptional {
	bool d;
	struct SQN_NR_SRS_Config_SQN_NR_SRS_PosResourceSet_r16_srs_PosResourceSetToAddModList_r16_Dynamic v;
};

struct SQN_NR_SRS_PosResourceId_r16_SQN_NR_SRS_Config_srs_PosResourceToReleaseList_r16_Dynamic {
	size_t d;
	SQN_NR_SRS_PosResourceId_r16* v;
};

struct SQN_NR_SRS_PosResourceId_r16_SQN_NR_SRS_Config_srs_PosResourceToReleaseList_r16_DynamicOptional {
	bool d;
	struct SQN_NR_SRS_PosResourceId_r16_SQN_NR_SRS_Config_srs_PosResourceToReleaseList_r16_Dynamic v;
};

struct SQN_NR_SRS_Config_SQN_NR_SRS_PosResource_r16_srs_PosResourceToAddModList_r16_Dynamic {
	size_t d;
	struct SQN_NR_SRS_PosResource_r16* v;
};

struct SQN_NR_SRS_PosResource_r16_SQN_NR_SRS_Config_srs_PosResourceToAddModList_r16_DynamicOptional {
	bool d;
	struct SQN_NR_SRS_Config_SQN_NR_SRS_PosResource_r16_srs_PosResourceToAddModList_r16_Dynamic v;
};

struct SQN_NR_SRS_Config {
	struct SQN_NR_SRS_ResourceSetId_SQN_NR_SRS_Config_srs_ResourceSetToReleaseList_DynamicOptional srs_ResourceSetToReleaseList;
	struct SQN_NR_SRS_ResourceSet_SQN_NR_SRS_Config_srs_ResourceSetToAddModList_DynamicOptional srs_ResourceSetToAddModList;
	struct SQN_NR_SRS_ResourceId_SQN_NR_SRS_Config_srs_ResourceToReleaseList_DynamicOptional srs_ResourceToReleaseList;
	struct SQN_NR_SRS_Resource_SQN_NR_SRS_Config_srs_ResourceToAddModList_DynamicOptional srs_ResourceToAddModList;
	struct SQN_NR_SRS_Config_tpc_Accumulation_e_tpc_Accumulation_Optional tpc_Accumulation;
	struct uint8_t_SQN_NR_SRS_Config_srs_RequestDCI_1_2_r16_Optional srs_RequestDCI_1_2_r16;
	struct uint8_t_SQN_NR_SRS_Config_srs_RequestDCI_0_2_r16_Optional srs_RequestDCI_0_2_r16;
	struct SQN_NR_SRS_ResourceSet_SQN_NR_SRS_Config_srs_ResourceSetToAddModListDCI_0_2_r16_DynamicOptional srs_ResourceSetToAddModListDCI_0_2_r16;
	struct SQN_NR_SRS_ResourceSetId_SQN_NR_SRS_Config_srs_ResourceSetToReleaseListDCI_0_2_r16_DynamicOptional srs_ResourceSetToReleaseListDCI_0_2_r16;
	struct SQN_NR_SRS_PosResourceSetId_r16_SQN_NR_SRS_Config_srs_PosResourceSetToReleaseList_r16_DynamicOptional srs_PosResourceSetToReleaseList_r16;
	struct SQN_NR_SRS_PosResourceSet_r16_SQN_NR_SRS_Config_srs_PosResourceSetToAddModList_r16_DynamicOptional srs_PosResourceSetToAddModList_r16;
	struct SQN_NR_SRS_PosResourceId_r16_SQN_NR_SRS_Config_srs_PosResourceToReleaseList_r16_DynamicOptional srs_PosResourceToReleaseList_r16;
	struct SQN_NR_SRS_PosResource_r16_SQN_NR_SRS_Config_srs_PosResourceToAddModList_r16_DynamicOptional srs_PosResourceToAddModList_r16;
};

enum SQN_NR_SetupRelease_BWP_UplinkDedicated_srs_Config_Sel {
	SQN_NR_SetupRelease_BWP_UplinkDedicated_srs_Config_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_srs_Config_release = 1,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_srs_Config_setup = 2,
};

union SQN_NR_SetupRelease_BWP_UplinkDedicated_srs_Config_Value {
	Null release;
	struct SQN_NR_SRS_Config setup;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_srs_Config {
	enum SQN_NR_SetupRelease_BWP_UplinkDedicated_srs_Config_Sel d;
	union SQN_NR_SetupRelease_BWP_UplinkDedicated_srs_Config_Value v;
};

struct SQN_NR_BFR_SSB_Resource {
	SQN_NR_SSB_Index ssb;
	uint8_t ra_PreambleIndex;
};

struct uint16_t_SQN_NR_BFR_CSIRS_Resource_ra_OccasionList_Dynamic {
	size_t d;
	uint16_t* v;
};

struct uint16_t_SQN_NR_BFR_CSIRS_Resource_ra_OccasionList_DynamicOptional {
	bool d;
	struct uint16_t_SQN_NR_BFR_CSIRS_Resource_ra_OccasionList_Dynamic v;
};

struct uint8_t_SQN_NR_BFR_CSIRS_Resource_ra_PreambleIndex_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_BFR_CSIRS_Resource {
	SQN_NR_NZP_CSI_RS_ResourceId csi_RS;
	struct uint16_t_SQN_NR_BFR_CSIRS_Resource_ra_OccasionList_DynamicOptional ra_OccasionList;
	struct uint8_t_SQN_NR_BFR_CSIRS_Resource_ra_PreambleIndex_Optional ra_PreambleIndex;
};

enum SQN_NR_PRACH_ResourceDedicatedBFR_Sel {
	SQN_NR_PRACH_ResourceDedicatedBFR_UNBOUND_VALUE = 0,
	SQN_NR_PRACH_ResourceDedicatedBFR_ssb = 1,
	SQN_NR_PRACH_ResourceDedicatedBFR_csi_RS = 2,
};

union SQN_NR_PRACH_ResourceDedicatedBFR_Value {
	struct SQN_NR_BFR_SSB_Resource ssb;
	struct SQN_NR_BFR_CSIRS_Resource csi_RS;
};

struct SQN_NR_PRACH_ResourceDedicatedBFR {
	enum SQN_NR_PRACH_ResourceDedicatedBFR_Sel d;
	union SQN_NR_PRACH_ResourceDedicatedBFR_Value v;
};

enum SQN_NR_BeamFailureRecoveryConfig_ssb_perRACH_Occasion_e {
	SQN_NR_BeamFailureRecoveryConfig_ssb_perRACH_Occasion_e_oneEighth = 0,
	SQN_NR_BeamFailureRecoveryConfig_ssb_perRACH_Occasion_e_oneFourth = 1,
	SQN_NR_BeamFailureRecoveryConfig_ssb_perRACH_Occasion_e_oneHalf = 2,
	SQN_NR_BeamFailureRecoveryConfig_ssb_perRACH_Occasion_e_one = 3,
	SQN_NR_BeamFailureRecoveryConfig_ssb_perRACH_Occasion_e_two = 4,
	SQN_NR_BeamFailureRecoveryConfig_ssb_perRACH_Occasion_e_four = 5,
	SQN_NR_BeamFailureRecoveryConfig_ssb_perRACH_Occasion_e_eight = 6,
	SQN_NR_BeamFailureRecoveryConfig_ssb_perRACH_Occasion_e_sixteen = 7,
};

typedef enum SQN_NR_BeamFailureRecoveryConfig_ssb_perRACH_Occasion_e SQN_NR_BeamFailureRecoveryConfig_ssb_perRACH_Occasion_e;

enum SQN_NR_BeamFailureRecoveryConfig_beamFailureRecoveryTimer_e {
	SQN_NR_BeamFailureRecoveryConfig_beamFailureRecoveryTimer_e_ms10 = 0,
	SQN_NR_BeamFailureRecoveryConfig_beamFailureRecoveryTimer_e_ms20 = 1,
	SQN_NR_BeamFailureRecoveryConfig_beamFailureRecoveryTimer_e_ms40 = 2,
	SQN_NR_BeamFailureRecoveryConfig_beamFailureRecoveryTimer_e_ms60 = 3,
	SQN_NR_BeamFailureRecoveryConfig_beamFailureRecoveryTimer_e_ms80 = 4,
	SQN_NR_BeamFailureRecoveryConfig_beamFailureRecoveryTimer_e_ms100 = 5,
	SQN_NR_BeamFailureRecoveryConfig_beamFailureRecoveryTimer_e_ms150 = 6,
	SQN_NR_BeamFailureRecoveryConfig_beamFailureRecoveryTimer_e_ms200 = 7,
};

typedef enum SQN_NR_BeamFailureRecoveryConfig_beamFailureRecoveryTimer_e SQN_NR_BeamFailureRecoveryConfig_beamFailureRecoveryTimer_e;

struct SQN_NR_PRACH_ResourceDedicatedBFR_SQN_NR_CandidateBeamRSListExt_r16_Dynamic {
	size_t d;
	struct SQN_NR_PRACH_ResourceDedicatedBFR* v;
};

typedef struct SQN_NR_PRACH_ResourceDedicatedBFR_SQN_NR_CandidateBeamRSListExt_r16_Dynamic SQN_NR_CandidateBeamRSListExt_r16;

enum SQN_NR_SetupRelease_BeamFailureRecoveryConfig_candidateBeamRSListExt_v1610_Sel {
	SQN_NR_SetupRelease_BeamFailureRecoveryConfig_candidateBeamRSListExt_v1610_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BeamFailureRecoveryConfig_candidateBeamRSListExt_v1610_release = 1,
	SQN_NR_SetupRelease_BeamFailureRecoveryConfig_candidateBeamRSListExt_v1610_setup = 2,
};

union SQN_NR_SetupRelease_BeamFailureRecoveryConfig_candidateBeamRSListExt_v1610_Value {
	Null release;
	SQN_NR_CandidateBeamRSListExt_r16 setup;
};

struct SQN_NR_SetupRelease_BeamFailureRecoveryConfig_candidateBeamRSListExt_v1610 {
	enum SQN_NR_SetupRelease_BeamFailureRecoveryConfig_candidateBeamRSListExt_v1610_Sel d;
	union SQN_NR_SetupRelease_BeamFailureRecoveryConfig_candidateBeamRSListExt_v1610_Value v;
};

struct uint8_t_SQN_NR_BeamFailureRecoveryConfig_rootSequenceIndex_BFR_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_RACH_ConfigGeneric_SQN_NR_BeamFailureRecoveryConfig_rach_ConfigBFR_Optional {
	bool d;
	struct SQN_NR_RACH_ConfigGeneric v;
};

struct SQN_NR_RSRP_Range_SQN_NR_BeamFailureRecoveryConfig_rsrp_ThresholdSSB_Optional {
	bool d;
	SQN_NR_RSRP_Range v;
};

struct SQN_NR_BeamFailureRecoveryConfig_SQN_NR_PRACH_ResourceDedicatedBFR_candidateBeamRSList_Dynamic {
	size_t d;
	struct SQN_NR_PRACH_ResourceDedicatedBFR* v;
};

struct SQN_NR_PRACH_ResourceDedicatedBFR_SQN_NR_BeamFailureRecoveryConfig_candidateBeamRSList_DynamicOptional {
	bool d;
	struct SQN_NR_BeamFailureRecoveryConfig_SQN_NR_PRACH_ResourceDedicatedBFR_candidateBeamRSList_Dynamic v;
};

struct SQN_NR_BeamFailureRecoveryConfig_ssb_perRACH_Occasion_e_ssb_perRACH_Occasion_Optional {
	bool d;
	SQN_NR_BeamFailureRecoveryConfig_ssb_perRACH_Occasion_e v;
};

struct uint8_t_SQN_NR_BeamFailureRecoveryConfig_ra_ssb_OccasionMaskIndex_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_SearchSpaceId_SQN_NR_BeamFailureRecoveryConfig_recoverySearchSpaceId_Optional {
	bool d;
	SQN_NR_SearchSpaceId v;
};

struct SQN_NR_RA_Prioritization_SQN_NR_BeamFailureRecoveryConfig_ra_Prioritization_Optional {
	bool d;
	struct SQN_NR_RA_Prioritization v;
};

struct SQN_NR_BeamFailureRecoveryConfig_beamFailureRecoveryTimer_e_beamFailureRecoveryTimer_Optional {
	bool d;
	SQN_NR_BeamFailureRecoveryConfig_beamFailureRecoveryTimer_e v;
};

struct SQN_NR_SubcarrierSpacing_e_SQN_NR_BeamFailureRecoveryConfig_msg1_SubcarrierSpacing_Optional {
	bool d;
	SQN_NR_SubcarrierSpacing_e v;
};

struct SQN_NR_RA_Prioritization_SQN_NR_BeamFailureRecoveryConfig_ra_PrioritizationTwoStep_r16_Optional {
	bool d;
	struct SQN_NR_RA_Prioritization v;
};

struct SQN_NR_SetupRelease_BeamFailureRecoveryConfig_candidateBeamRSListExt_v1610_SQN_NR_BeamFailureRecoveryConfig_candidateBeamRSListExt_v1610_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BeamFailureRecoveryConfig_candidateBeamRSListExt_v1610 v;
};

struct SQN_NR_BeamFailureRecoveryConfig {
	struct uint8_t_SQN_NR_BeamFailureRecoveryConfig_rootSequenceIndex_BFR_Optional rootSequenceIndex_BFR;
	struct SQN_NR_RACH_ConfigGeneric_SQN_NR_BeamFailureRecoveryConfig_rach_ConfigBFR_Optional rach_ConfigBFR;
	struct SQN_NR_RSRP_Range_SQN_NR_BeamFailureRecoveryConfig_rsrp_ThresholdSSB_Optional rsrp_ThresholdSSB;
	struct SQN_NR_PRACH_ResourceDedicatedBFR_SQN_NR_BeamFailureRecoveryConfig_candidateBeamRSList_DynamicOptional candidateBeamRSList;
	struct SQN_NR_BeamFailureRecoveryConfig_ssb_perRACH_Occasion_e_ssb_perRACH_Occasion_Optional ssb_perRACH_Occasion;
	struct uint8_t_SQN_NR_BeamFailureRecoveryConfig_ra_ssb_OccasionMaskIndex_Optional ra_ssb_OccasionMaskIndex;
	struct SQN_NR_SearchSpaceId_SQN_NR_BeamFailureRecoveryConfig_recoverySearchSpaceId_Optional recoverySearchSpaceId;
	struct SQN_NR_RA_Prioritization_SQN_NR_BeamFailureRecoveryConfig_ra_Prioritization_Optional ra_Prioritization;
	struct SQN_NR_BeamFailureRecoveryConfig_beamFailureRecoveryTimer_e_beamFailureRecoveryTimer_Optional beamFailureRecoveryTimer;
	struct SQN_NR_SubcarrierSpacing_e_SQN_NR_BeamFailureRecoveryConfig_msg1_SubcarrierSpacing_Optional msg1_SubcarrierSpacing;
	struct SQN_NR_RA_Prioritization_SQN_NR_BeamFailureRecoveryConfig_ra_PrioritizationTwoStep_r16_Optional ra_PrioritizationTwoStep_r16;
	struct SQN_NR_SetupRelease_BeamFailureRecoveryConfig_candidateBeamRSListExt_v1610_SQN_NR_BeamFailureRecoveryConfig_candidateBeamRSListExt_v1610_Optional candidateBeamRSListExt_v1610;
};

enum SQN_NR_SetupRelease_BWP_UplinkDedicated_beamFailureRecoveryConfig_Sel {
	SQN_NR_SetupRelease_BWP_UplinkDedicated_beamFailureRecoveryConfig_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_beamFailureRecoveryConfig_release = 1,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_beamFailureRecoveryConfig_setup = 2,
};

union SQN_NR_SetupRelease_BWP_UplinkDedicated_beamFailureRecoveryConfig_Value {
	Null release;
	struct SQN_NR_BeamFailureRecoveryConfig setup;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_beamFailureRecoveryConfig {
	enum SQN_NR_SetupRelease_BWP_UplinkDedicated_beamFailureRecoveryConfig_Sel d;
	union SQN_NR_SetupRelease_BWP_UplinkDedicated_beamFailureRecoveryConfig_Value v;
};

enum SQN_NR_SetupRelease_BWP_UplinkDedicated_sl_PUCCH_Config_r16_Sel {
	SQN_NR_SetupRelease_BWP_UplinkDedicated_sl_PUCCH_Config_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_sl_PUCCH_Config_r16_release = 1,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_sl_PUCCH_Config_r16_setup = 2,
};

union SQN_NR_SetupRelease_BWP_UplinkDedicated_sl_PUCCH_Config_r16_Value {
	Null release;
	struct SQN_NR_PUCCH_Config setup;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_sl_PUCCH_Config_r16 {
	enum SQN_NR_SetupRelease_BWP_UplinkDedicated_sl_PUCCH_Config_r16_Sel d;
	union SQN_NR_SetupRelease_BWP_UplinkDedicated_sl_PUCCH_Config_r16_Value v;
};

enum SQN_NR_BWP_UplinkDedicated_useInterlacePUCCH_PUSCH_r16_e {
	SQN_NR_BWP_UplinkDedicated_useInterlacePUCCH_PUSCH_r16_e_enabled = 0,
};

typedef enum SQN_NR_BWP_UplinkDedicated_useInterlacePUCCH_PUSCH_r16_e SQN_NR_BWP_UplinkDedicated_useInterlacePUCCH_PUSCH_r16_e;

struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_ConfigurationList_r16_Dynamic {
	size_t d;
	struct SQN_NR_PUCCH_Config* v;
};

typedef struct SQN_NR_PUCCH_Config_SQN_NR_PUCCH_ConfigurationList_r16_Dynamic SQN_NR_PUCCH_ConfigurationList_r16;

enum SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_ConfigurationList_r16_Sel {
	SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_ConfigurationList_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_ConfigurationList_r16_release = 1,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_ConfigurationList_r16_setup = 2,
};

union SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_ConfigurationList_r16_Value {
	Null release;
	SQN_NR_PUCCH_ConfigurationList_r16 setup;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_ConfigurationList_r16 {
	enum SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_ConfigurationList_r16_Sel d;
	union SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_ConfigurationList_r16_Value v;
};

enum SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureInstanceMaxCount_r16_e {
	SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureInstanceMaxCount_r16_e_n4 = 0,
	SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureInstanceMaxCount_r16_e_n8 = 1,
	SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureInstanceMaxCount_r16_e_n16 = 2,
	SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureInstanceMaxCount_r16_e_n32 = 3,
	SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureInstanceMaxCount_r16_e_n64 = 4,
	SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureInstanceMaxCount_r16_e_n128 = 5,
};

typedef enum SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureInstanceMaxCount_r16_e SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureInstanceMaxCount_r16_e;

enum SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureDetectionTimer_r16_e {
	SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureDetectionTimer_r16_e_ms10 = 0,
	SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureDetectionTimer_r16_e_ms20 = 1,
	SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureDetectionTimer_r16_e_ms40 = 2,
	SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureDetectionTimer_r16_e_ms80 = 3,
	SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureDetectionTimer_r16_e_ms160 = 4,
	SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureDetectionTimer_r16_e_ms320 = 5,
};

typedef enum SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureDetectionTimer_r16_e SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureDetectionTimer_r16_e;

struct SQN_NR_LBT_FailureRecoveryConfig_r16 {
	SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureInstanceMaxCount_r16_e lbt_FailureInstanceMaxCount_r16;
	SQN_NR_LBT_FailureRecoveryConfig_r16_lbt_FailureDetectionTimer_r16_e lbt_FailureDetectionTimer_r16;
};

enum SQN_NR_SetupRelease_BWP_UplinkDedicated_lbt_FailureRecoveryConfig_r16_Sel {
	SQN_NR_SetupRelease_BWP_UplinkDedicated_lbt_FailureRecoveryConfig_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_lbt_FailureRecoveryConfig_r16_release = 1,
	SQN_NR_SetupRelease_BWP_UplinkDedicated_lbt_FailureRecoveryConfig_r16_setup = 2,
};

union SQN_NR_SetupRelease_BWP_UplinkDedicated_lbt_FailureRecoveryConfig_r16_Value {
	Null release;
	struct SQN_NR_LBT_FailureRecoveryConfig_r16 setup;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_lbt_FailureRecoveryConfig_r16 {
	enum SQN_NR_SetupRelease_BWP_UplinkDedicated_lbt_FailureRecoveryConfig_r16_Sel d;
	union SQN_NR_SetupRelease_BWP_UplinkDedicated_lbt_FailureRecoveryConfig_r16_Value v;
};

struct SQN_NR_ConfiguredGrantConfig_SQN_NR_ConfiguredGrantConfigToAddModList_r16_Dynamic {
	size_t d;
	struct SQN_NR_ConfiguredGrantConfig* v;
};

typedef struct SQN_NR_ConfiguredGrantConfig_SQN_NR_ConfiguredGrantConfigToAddModList_r16_Dynamic SQN_NR_ConfiguredGrantConfigToAddModList_r16;

struct SQN_NR_ConfiguredGrantConfigIndex_r16_SQN_NR_ConfiguredGrantConfigToReleaseList_r16_Dynamic {
	size_t d;
	SQN_NR_ConfiguredGrantConfigIndex_r16* v;
};

typedef struct SQN_NR_ConfiguredGrantConfigIndex_r16_SQN_NR_ConfiguredGrantConfigToReleaseList_r16_Dynamic SQN_NR_ConfiguredGrantConfigToReleaseList_r16;

struct SQN_NR_ConfiguredGrantConfigIndex_r16_SQN_NR_ConfiguredGrantConfigType2DeactivationState_r16_Dynamic {
	size_t d;
	SQN_NR_ConfiguredGrantConfigIndex_r16* v;
};

typedef struct SQN_NR_ConfiguredGrantConfigIndex_r16_SQN_NR_ConfiguredGrantConfigType2DeactivationState_r16_Dynamic SQN_NR_ConfiguredGrantConfigType2DeactivationState_r16;

struct SQN_NR_ConfiguredGrantConfigType2DeactivationState_r16_SQN_NR_ConfiguredGrantConfigType2DeactivationStateList_r16_Dynamic {
	size_t d;
	SQN_NR_ConfiguredGrantConfigType2DeactivationState_r16* v;
};

typedef struct SQN_NR_ConfiguredGrantConfigType2DeactivationState_r16_SQN_NR_ConfiguredGrantConfigType2DeactivationStateList_r16_Dynamic SQN_NR_ConfiguredGrantConfigType2DeactivationStateList_r16;

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_Config_SQN_NR_BWP_UplinkDedicated_pucch_Config_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_Config v;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_pusch_Config_SQN_NR_BWP_UplinkDedicated_pusch_Config_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_pusch_Config v;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_configuredGrantConfig_SQN_NR_BWP_UplinkDedicated_configuredGrantConfig_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_configuredGrantConfig v;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_srs_Config_SQN_NR_BWP_UplinkDedicated_srs_Config_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_srs_Config v;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_beamFailureRecoveryConfig_SQN_NR_BWP_UplinkDedicated_beamFailureRecoveryConfig_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_beamFailureRecoveryConfig v;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_sl_PUCCH_Config_r16_SQN_NR_BWP_UplinkDedicated_sl_PUCCH_Config_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_sl_PUCCH_Config_r16 v;
};

struct uint8_t_SQN_NR_BWP_UplinkDedicated_cp_ExtensionC2_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_BWP_UplinkDedicated_cp_ExtensionC3_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_BWP_UplinkDedicated_useInterlacePUCCH_PUSCH_r16_e_useInterlacePUCCH_PUSCH_r16_Optional {
	bool d;
	SQN_NR_BWP_UplinkDedicated_useInterlacePUCCH_PUSCH_r16_e v;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_ConfigurationList_r16_SQN_NR_BWP_UplinkDedicated_pucch_ConfigurationList_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_ConfigurationList_r16 v;
};

struct SQN_NR_SetupRelease_BWP_UplinkDedicated_lbt_FailureRecoveryConfig_r16_SQN_NR_BWP_UplinkDedicated_lbt_FailureRecoveryConfig_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_lbt_FailureRecoveryConfig_r16 v;
};

struct SQN_NR_ConfiguredGrantConfigToAddModList_r16_SQN_NR_BWP_UplinkDedicated_configuredGrantConfigToAddModList_r16_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfigToAddModList_r16 v;
};

struct SQN_NR_ConfiguredGrantConfigToReleaseList_r16_SQN_NR_BWP_UplinkDedicated_configuredGrantConfigToReleaseList_r16_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfigToReleaseList_r16 v;
};

struct SQN_NR_ConfiguredGrantConfigType2DeactivationStateList_r16_SQN_NR_BWP_UplinkDedicated_configuredGrantConfigType2DeactivationStateList_r16_Optional {
	bool d;
	SQN_NR_ConfiguredGrantConfigType2DeactivationStateList_r16 v;
};

struct SQN_NR_BWP_UplinkDedicated {
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_Config_SQN_NR_BWP_UplinkDedicated_pucch_Config_Optional pucch_Config;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_pusch_Config_SQN_NR_BWP_UplinkDedicated_pusch_Config_Optional pusch_Config;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_configuredGrantConfig_SQN_NR_BWP_UplinkDedicated_configuredGrantConfig_Optional configuredGrantConfig;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_srs_Config_SQN_NR_BWP_UplinkDedicated_srs_Config_Optional srs_Config;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_beamFailureRecoveryConfig_SQN_NR_BWP_UplinkDedicated_beamFailureRecoveryConfig_Optional beamFailureRecoveryConfig;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_sl_PUCCH_Config_r16_SQN_NR_BWP_UplinkDedicated_sl_PUCCH_Config_r16_Optional sl_PUCCH_Config_r16;
	struct uint8_t_SQN_NR_BWP_UplinkDedicated_cp_ExtensionC2_r16_Optional cp_ExtensionC2_r16;
	struct uint8_t_SQN_NR_BWP_UplinkDedicated_cp_ExtensionC3_r16_Optional cp_ExtensionC3_r16;
	struct SQN_NR_BWP_UplinkDedicated_useInterlacePUCCH_PUSCH_r16_e_useInterlacePUCCH_PUSCH_r16_Optional useInterlacePUCCH_PUSCH_r16;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_pucch_ConfigurationList_r16_SQN_NR_BWP_UplinkDedicated_pucch_ConfigurationList_r16_Optional pucch_ConfigurationList_r16;
	struct SQN_NR_SetupRelease_BWP_UplinkDedicated_lbt_FailureRecoveryConfig_r16_SQN_NR_BWP_UplinkDedicated_lbt_FailureRecoveryConfig_r16_Optional lbt_FailureRecoveryConfig_r16;
	struct SQN_NR_ConfiguredGrantConfigToAddModList_r16_SQN_NR_BWP_UplinkDedicated_configuredGrantConfigToAddModList_r16_Optional configuredGrantConfigToAddModList_r16;
	struct SQN_NR_ConfiguredGrantConfigToReleaseList_r16_SQN_NR_BWP_UplinkDedicated_configuredGrantConfigToReleaseList_r16_Optional configuredGrantConfigToReleaseList_r16;
	struct SQN_NR_ConfiguredGrantConfigType2DeactivationStateList_r16_SQN_NR_BWP_UplinkDedicated_configuredGrantConfigType2DeactivationStateList_r16_Optional configuredGrantConfigType2DeactivationStateList_r16;
};

enum SQN_NR_CSI_RS_ResourceMapping_frequencyDomainAllocation_Sel {
	SQN_NR_CSI_RS_ResourceMapping_frequencyDomainAllocation_UNBOUND_VALUE = 0,
	SQN_NR_CSI_RS_ResourceMapping_frequencyDomainAllocation_row1 = 1,
	SQN_NR_CSI_RS_ResourceMapping_frequencyDomainAllocation_row2 = 2,
	SQN_NR_CSI_RS_ResourceMapping_frequencyDomainAllocation_row4 = 3,
	SQN_NR_CSI_RS_ResourceMapping_frequencyDomainAllocation_other = 4,
};

union SQN_NR_CSI_RS_ResourceMapping_frequencyDomainAllocation_Value {
	B4 row1;
	B12 row2;
	B3 row4;
	B6 other;
};

struct SQN_NR_CSI_RS_ResourceMapping_frequencyDomainAllocation {
	enum SQN_NR_CSI_RS_ResourceMapping_frequencyDomainAllocation_Sel d;
	union SQN_NR_CSI_RS_ResourceMapping_frequencyDomainAllocation_Value v;
};

enum SQN_NR_CSI_RS_ResourceMapping_nrofPorts_e {
	SQN_NR_CSI_RS_ResourceMapping_nrofPorts_e_p1 = 0,
	SQN_NR_CSI_RS_ResourceMapping_nrofPorts_e_p2 = 1,
	SQN_NR_CSI_RS_ResourceMapping_nrofPorts_e_p4 = 2,
	SQN_NR_CSI_RS_ResourceMapping_nrofPorts_e_p8 = 3,
	SQN_NR_CSI_RS_ResourceMapping_nrofPorts_e_p12 = 4,
	SQN_NR_CSI_RS_ResourceMapping_nrofPorts_e_p16 = 5,
	SQN_NR_CSI_RS_ResourceMapping_nrofPorts_e_p24 = 6,
	SQN_NR_CSI_RS_ResourceMapping_nrofPorts_e_p32 = 7,
};

typedef enum SQN_NR_CSI_RS_ResourceMapping_nrofPorts_e SQN_NR_CSI_RS_ResourceMapping_nrofPorts_e;

enum SQN_NR_CSI_RS_ResourceMapping_cdm_Type_e {
	SQN_NR_CSI_RS_ResourceMapping_cdm_Type_e_noCDM = 0,
	SQN_NR_CSI_RS_ResourceMapping_cdm_Type_e_fd_CDM2 = 1,
	SQN_NR_CSI_RS_ResourceMapping_cdm_Type_e_cdm4_FD2_TD2 = 2,
	SQN_NR_CSI_RS_ResourceMapping_cdm_Type_e_cdm8_FD2_TD4 = 3,
};

typedef enum SQN_NR_CSI_RS_ResourceMapping_cdm_Type_e SQN_NR_CSI_RS_ResourceMapping_cdm_Type_e;

enum SQN_NR_CSI_RS_ResourceMapping_density_dot5_e {
	SQN_NR_CSI_RS_ResourceMapping_density_dot5_e_evenPRBs = 0,
	SQN_NR_CSI_RS_ResourceMapping_density_dot5_e_oddPRBs = 1,
};

typedef enum SQN_NR_CSI_RS_ResourceMapping_density_dot5_e SQN_NR_CSI_RS_ResourceMapping_density_dot5_e;

enum SQN_NR_CSI_RS_ResourceMapping_density_Sel {
	SQN_NR_CSI_RS_ResourceMapping_density_UNBOUND_VALUE = 0,
	SQN_NR_CSI_RS_ResourceMapping_density_dot5 = 1,
	SQN_NR_CSI_RS_ResourceMapping_density_one = 2,
	SQN_NR_CSI_RS_ResourceMapping_density_three = 3,
	SQN_NR_CSI_RS_ResourceMapping_density_spare = 4,
};

union SQN_NR_CSI_RS_ResourceMapping_density_Value {
	SQN_NR_CSI_RS_ResourceMapping_density_dot5_e dot5;
	Null one;
	Null three;
	Null spare;
};

struct SQN_NR_CSI_RS_ResourceMapping_density {
	enum SQN_NR_CSI_RS_ResourceMapping_density_Sel d;
	union SQN_NR_CSI_RS_ResourceMapping_density_Value v;
};

struct SQN_NR_CSI_FrequencyOccupation {
	uint16_t startingRB;
	uint16_t nrofRBs;
};

struct uint8_t_SQN_NR_CSI_RS_ResourceMapping_firstOFDMSymbolInTimeDomain2_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_CSI_RS_ResourceMapping {
	struct SQN_NR_CSI_RS_ResourceMapping_frequencyDomainAllocation frequencyDomainAllocation;
	SQN_NR_CSI_RS_ResourceMapping_nrofPorts_e nrofPorts;
	uint8_t firstOFDMSymbolInTimeDomain;
	struct uint8_t_SQN_NR_CSI_RS_ResourceMapping_firstOFDMSymbolInTimeDomain2_Optional firstOFDMSymbolInTimeDomain2;
	SQN_NR_CSI_RS_ResourceMapping_cdm_Type_e cdm_Type;
	struct SQN_NR_CSI_RS_ResourceMapping_density density;
	struct SQN_NR_CSI_FrequencyOccupation freqBand;
};

typedef uint8_t SQN_NR_CellGroupId;

enum SQN_NR_CipheringAlgorithm_e {
	SQN_NR_CipheringAlgorithm_e_nea0 = 0,
	SQN_NR_CipheringAlgorithm_e_nea1 = 1,
	SQN_NR_CipheringAlgorithm_e_nea2 = 2,
	SQN_NR_CipheringAlgorithm_e_nea3 = 3,
	SQN_NR_CipheringAlgorithm_e_spare4 = 4,
	SQN_NR_CipheringAlgorithm_e_spare3 = 5,
	SQN_NR_CipheringAlgorithm_e_spare2 = 6,
	SQN_NR_CipheringAlgorithm_e_spare1 = 7,
};

typedef enum SQN_NR_CipheringAlgorithm_e SQN_NR_CipheringAlgorithm_e;

enum SQN_NR_SN_FieldLengthAM_e {
	SQN_NR_SN_FieldLengthAM_e_size12 = 0,
	SQN_NR_SN_FieldLengthAM_e_size18 = 1,
};

typedef enum SQN_NR_SN_FieldLengthAM_e SQN_NR_SN_FieldLengthAM_e;

enum SQN_NR_T_Reassembly_e {
	SQN_NR_T_Reassembly_e_ms0 = 0,
	SQN_NR_T_Reassembly_e_ms5 = 1,
	SQN_NR_T_Reassembly_e_ms10 = 2,
	SQN_NR_T_Reassembly_e_ms15 = 3,
	SQN_NR_T_Reassembly_e_ms20 = 4,
	SQN_NR_T_Reassembly_e_ms25 = 5,
	SQN_NR_T_Reassembly_e_ms30 = 6,
	SQN_NR_T_Reassembly_e_ms35 = 7,
	SQN_NR_T_Reassembly_e_ms40 = 8,
	SQN_NR_T_Reassembly_e_ms45 = 9,
	SQN_NR_T_Reassembly_e_ms50 = 10,
	SQN_NR_T_Reassembly_e_ms55 = 11,
	SQN_NR_T_Reassembly_e_ms60 = 12,
	SQN_NR_T_Reassembly_e_ms65 = 13,
	SQN_NR_T_Reassembly_e_ms70 = 14,
	SQN_NR_T_Reassembly_e_ms75 = 15,
	SQN_NR_T_Reassembly_e_ms80 = 16,
	SQN_NR_T_Reassembly_e_ms85 = 17,
	SQN_NR_T_Reassembly_e_ms90 = 18,
	SQN_NR_T_Reassembly_e_ms95 = 19,
	SQN_NR_T_Reassembly_e_ms100 = 20,
	SQN_NR_T_Reassembly_e_ms110 = 21,
	SQN_NR_T_Reassembly_e_ms120 = 22,
	SQN_NR_T_Reassembly_e_ms130 = 23,
	SQN_NR_T_Reassembly_e_ms140 = 24,
	SQN_NR_T_Reassembly_e_ms150 = 25,
	SQN_NR_T_Reassembly_e_ms160 = 26,
	SQN_NR_T_Reassembly_e_ms170 = 27,
	SQN_NR_T_Reassembly_e_ms180 = 28,
	SQN_NR_T_Reassembly_e_ms190 = 29,
	SQN_NR_T_Reassembly_e_ms200 = 30,
	SQN_NR_T_Reassembly_e_spare1 = 31,
};

typedef enum SQN_NR_T_Reassembly_e SQN_NR_T_Reassembly_e;

enum SQN_NR_T_StatusProhibit_e {
	SQN_NR_T_StatusProhibit_e_ms0 = 0,
	SQN_NR_T_StatusProhibit_e_ms5 = 1,
	SQN_NR_T_StatusProhibit_e_ms10 = 2,
	SQN_NR_T_StatusProhibit_e_ms15 = 3,
	SQN_NR_T_StatusProhibit_e_ms20 = 4,
	SQN_NR_T_StatusProhibit_e_ms25 = 5,
	SQN_NR_T_StatusProhibit_e_ms30 = 6,
	SQN_NR_T_StatusProhibit_e_ms35 = 7,
	SQN_NR_T_StatusProhibit_e_ms40 = 8,
	SQN_NR_T_StatusProhibit_e_ms45 = 9,
	SQN_NR_T_StatusProhibit_e_ms50 = 10,
	SQN_NR_T_StatusProhibit_e_ms55 = 11,
	SQN_NR_T_StatusProhibit_e_ms60 = 12,
	SQN_NR_T_StatusProhibit_e_ms65 = 13,
	SQN_NR_T_StatusProhibit_e_ms70 = 14,
	SQN_NR_T_StatusProhibit_e_ms75 = 15,
	SQN_NR_T_StatusProhibit_e_ms80 = 16,
	SQN_NR_T_StatusProhibit_e_ms85 = 17,
	SQN_NR_T_StatusProhibit_e_ms90 = 18,
	SQN_NR_T_StatusProhibit_e_ms95 = 19,
	SQN_NR_T_StatusProhibit_e_ms100 = 20,
	SQN_NR_T_StatusProhibit_e_ms105 = 21,
	SQN_NR_T_StatusProhibit_e_ms110 = 22,
	SQN_NR_T_StatusProhibit_e_ms115 = 23,
	SQN_NR_T_StatusProhibit_e_ms120 = 24,
	SQN_NR_T_StatusProhibit_e_ms125 = 25,
	SQN_NR_T_StatusProhibit_e_ms130 = 26,
	SQN_NR_T_StatusProhibit_e_ms135 = 27,
	SQN_NR_T_StatusProhibit_e_ms140 = 28,
	SQN_NR_T_StatusProhibit_e_ms145 = 29,
	SQN_NR_T_StatusProhibit_e_ms150 = 30,
	SQN_NR_T_StatusProhibit_e_ms155 = 31,
	SQN_NR_T_StatusProhibit_e_ms160 = 32,
	SQN_NR_T_StatusProhibit_e_ms165 = 33,
	SQN_NR_T_StatusProhibit_e_ms170 = 34,
	SQN_NR_T_StatusProhibit_e_ms175 = 35,
	SQN_NR_T_StatusProhibit_e_ms180 = 36,
	SQN_NR_T_StatusProhibit_e_ms185 = 37,
	SQN_NR_T_StatusProhibit_e_ms190 = 38,
	SQN_NR_T_StatusProhibit_e_ms195 = 39,
	SQN_NR_T_StatusProhibit_e_ms200 = 40,
	SQN_NR_T_StatusProhibit_e_ms205 = 41,
	SQN_NR_T_StatusProhibit_e_ms210 = 42,
	SQN_NR_T_StatusProhibit_e_ms215 = 43,
	SQN_NR_T_StatusProhibit_e_ms220 = 44,
	SQN_NR_T_StatusProhibit_e_ms225 = 45,
	SQN_NR_T_StatusProhibit_e_ms230 = 46,
	SQN_NR_T_StatusProhibit_e_ms235 = 47,
	SQN_NR_T_StatusProhibit_e_ms240 = 48,
	SQN_NR_T_StatusProhibit_e_ms245 = 49,
	SQN_NR_T_StatusProhibit_e_ms250 = 50,
	SQN_NR_T_StatusProhibit_e_ms300 = 51,
	SQN_NR_T_StatusProhibit_e_ms350 = 52,
	SQN_NR_T_StatusProhibit_e_ms400 = 53,
	SQN_NR_T_StatusProhibit_e_ms450 = 54,
	SQN_NR_T_StatusProhibit_e_ms500 = 55,
	SQN_NR_T_StatusProhibit_e_ms800 = 56,
	SQN_NR_T_StatusProhibit_e_ms1000 = 57,
	SQN_NR_T_StatusProhibit_e_ms1200 = 58,
	SQN_NR_T_StatusProhibit_e_ms1600 = 59,
	SQN_NR_T_StatusProhibit_e_ms2000 = 60,
	SQN_NR_T_StatusProhibit_e_ms2400 = 61,
	SQN_NR_T_StatusProhibit_e_spare2 = 62,
	SQN_NR_T_StatusProhibit_e_spare1 = 63,
};

typedef enum SQN_NR_T_StatusProhibit_e SQN_NR_T_StatusProhibit_e;

struct SQN_NR_SN_FieldLengthAM_e_SQN_NR_DL_AM_RLC_sn_FieldLength_Optional {
	bool d;
	SQN_NR_SN_FieldLengthAM_e v;
};

struct SQN_NR_DL_AM_RLC {
	struct SQN_NR_SN_FieldLengthAM_e_SQN_NR_DL_AM_RLC_sn_FieldLength_Optional sn_FieldLength;
	SQN_NR_T_Reassembly_e t_Reassembly;
	SQN_NR_T_StatusProhibit_e t_StatusProhibit;
};

enum SQN_NR_SN_FieldLengthUM_e {
	SQN_NR_SN_FieldLengthUM_e_size6 = 0,
	SQN_NR_SN_FieldLengthUM_e_size12 = 1,
};

typedef enum SQN_NR_SN_FieldLengthUM_e SQN_NR_SN_FieldLengthUM_e;

struct SQN_NR_SN_FieldLengthUM_e_SQN_NR_DL_UM_RLC_sn_FieldLength_Optional {
	bool d;
	SQN_NR_SN_FieldLengthUM_e v;
};

struct SQN_NR_DL_UM_RLC {
	struct SQN_NR_SN_FieldLengthUM_e_SQN_NR_DL_UM_RLC_sn_FieldLength_Optional sn_FieldLength;
	SQN_NR_T_Reassembly_e t_Reassembly;
};

typedef uint8_t SQN_NR_DRB_Identity;

enum SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e {
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms1 = 0,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms2 = 1,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms3 = 2,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms4 = 3,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms5 = 4,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms6 = 5,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms8 = 6,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms10 = 7,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms20 = 8,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms30 = 9,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms40 = 10,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms50 = 11,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms60 = 12,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms80 = 13,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms100 = 14,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms200 = 15,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms300 = 16,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms400 = 17,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms500 = 18,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms600 = 19,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms800 = 20,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms1000 = 21,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms1200 = 22,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_ms1600 = 23,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_spare8 = 24,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_spare7 = 25,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_spare6 = 26,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_spare5 = 27,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_spare4 = 28,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_spare3 = 29,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_spare2 = 30,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e_spare1 = 31,
};

typedef enum SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e;

enum SQN_NR_DRX_Config_drx_onDurationTimer_Sel {
	SQN_NR_DRX_Config_drx_onDurationTimer_UNBOUND_VALUE = 0,
	SQN_NR_DRX_Config_drx_onDurationTimer_subMilliSeconds = 1,
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds = 2,
};

union SQN_NR_DRX_Config_drx_onDurationTimer_Value {
	uint8_t subMilliSeconds;
	SQN_NR_DRX_Config_drx_onDurationTimer_milliSeconds_e milliSeconds;
};

struct SQN_NR_DRX_Config_drx_onDurationTimer {
	enum SQN_NR_DRX_Config_drx_onDurationTimer_Sel d;
	union SQN_NR_DRX_Config_drx_onDurationTimer_Value v;
};

enum SQN_NR_DRX_Config_drx_InactivityTimer_e {
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms0 = 0,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms1 = 1,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms2 = 2,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms3 = 3,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms4 = 4,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms5 = 5,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms6 = 6,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms8 = 7,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms10 = 8,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms20 = 9,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms30 = 10,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms40 = 11,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms50 = 12,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms60 = 13,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms80 = 14,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms100 = 15,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms200 = 16,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms300 = 17,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms500 = 18,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms750 = 19,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms1280 = 20,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms1920 = 21,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_ms2560 = 22,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_spare9 = 23,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_spare8 = 24,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_spare7 = 25,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_spare6 = 26,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_spare5 = 27,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_spare4 = 28,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_spare3 = 29,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_spare2 = 30,
	SQN_NR_DRX_Config_drx_InactivityTimer_e_spare1 = 31,
};

typedef enum SQN_NR_DRX_Config_drx_InactivityTimer_e SQN_NR_DRX_Config_drx_InactivityTimer_e;

enum SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e {
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl0 = 0,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl1 = 1,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl2 = 2,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl4 = 3,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl6 = 4,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl8 = 5,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl16 = 6,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl24 = 7,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl33 = 8,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl40 = 9,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl64 = 10,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl80 = 11,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl96 = 12,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl112 = 13,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl128 = 14,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl160 = 15,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_sl320 = 16,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare15 = 17,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare14 = 18,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare13 = 19,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare12 = 20,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare11 = 21,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare10 = 22,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare9 = 23,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare8 = 24,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare7 = 25,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare6 = 26,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare5 = 27,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare4 = 28,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare3 = 29,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare2 = 30,
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e_spare1 = 31,
};

typedef enum SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e;

enum SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e {
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl0 = 0,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl1 = 1,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl2 = 2,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl4 = 3,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl6 = 4,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl8 = 5,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl16 = 6,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl24 = 7,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl33 = 8,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl40 = 9,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl64 = 10,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl80 = 11,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl96 = 12,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl112 = 13,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl128 = 14,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl160 = 15,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_sl320 = 16,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare15 = 17,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare14 = 18,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare13 = 19,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare12 = 20,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare11 = 21,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare10 = 22,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare9 = 23,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare8 = 24,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare7 = 25,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare6 = 26,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare5 = 27,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare4 = 28,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare3 = 29,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare2 = 30,
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e_spare1 = 31,
};

typedef enum SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e;

enum SQN_NR_DRX_Config_drx_LongCycleStartOffset_Sel {
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_UNBOUND_VALUE = 0,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms10 = 1,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms20 = 2,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms32 = 3,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms40 = 4,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms60 = 5,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms64 = 6,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms70 = 7,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms80 = 8,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms128 = 9,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms160 = 10,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms256 = 11,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms320 = 12,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms512 = 13,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms640 = 14,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms1024 = 15,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms1280 = 16,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms2048 = 17,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms2560 = 18,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms5120 = 19,
	SQN_NR_DRX_Config_drx_LongCycleStartOffset_ms10240 = 20,
};

union SQN_NR_DRX_Config_drx_LongCycleStartOffset_Value {
	uint8_t ms10;
	uint8_t ms20;
	uint8_t ms32;
	uint8_t ms40;
	uint8_t ms60;
	uint8_t ms64;
	uint8_t ms70;
	uint8_t ms80;
	uint8_t ms128;
	uint8_t ms160;
	uint8_t ms256;
	uint16_t ms320;
	uint16_t ms512;
	uint16_t ms640;
	uint16_t ms1024;
	uint16_t ms1280;
	uint16_t ms2048;
	uint16_t ms2560;
	uint16_t ms5120;
	uint16_t ms10240;
};

struct SQN_NR_DRX_Config_drx_LongCycleStartOffset {
	enum SQN_NR_DRX_Config_drx_LongCycleStartOffset_Sel d;
	union SQN_NR_DRX_Config_drx_LongCycleStartOffset_Value v;
};

enum SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e {
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms2 = 0,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms3 = 1,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms4 = 2,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms5 = 3,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms6 = 4,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms7 = 5,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms8 = 6,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms10 = 7,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms14 = 8,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms16 = 9,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms20 = 10,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms30 = 11,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms32 = 12,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms35 = 13,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms40 = 14,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms64 = 15,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms80 = 16,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms128 = 17,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms160 = 18,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms256 = 19,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms320 = 20,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms512 = 21,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_ms640 = 22,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_spare9 = 23,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_spare8 = 24,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_spare7 = 25,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_spare6 = 26,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_spare5 = 27,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_spare4 = 28,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_spare3 = 29,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_spare2 = 30,
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e_spare1 = 31,
};

typedef enum SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e;

struct SQN_NR_DRX_Config_shortDRX {
	SQN_NR_DRX_Config_shortDRX_drx_ShortCycle_e drx_ShortCycle;
	uint8_t drx_ShortCycleTimer;
};

struct SQN_NR_DRX_Config_shortDRX_shortDRX_Optional {
	bool d;
	struct SQN_NR_DRX_Config_shortDRX v;
};

struct SQN_NR_DRX_Config {
	struct SQN_NR_DRX_Config_drx_onDurationTimer drx_onDurationTimer;
	SQN_NR_DRX_Config_drx_InactivityTimer_e drx_InactivityTimer;
	uint8_t drx_HARQ_RTT_TimerDL;
	uint8_t drx_HARQ_RTT_TimerUL;
	SQN_NR_DRX_Config_drx_RetransmissionTimerDL_e drx_RetransmissionTimerDL;
	SQN_NR_DRX_Config_drx_RetransmissionTimerUL_e drx_RetransmissionTimerUL;
	struct SQN_NR_DRX_Config_drx_LongCycleStartOffset drx_LongCycleStartOffset;
	struct SQN_NR_DRX_Config_shortDRX_shortDRX_Optional shortDRX;
	uint8_t drx_SlotOffset;
};

struct SQN_NR_ARFCN_ValueNR_SQN_NR_FrequencyInfoDL_absoluteFrequencySSB_Optional {
	bool d;
	SQN_NR_ARFCN_ValueNR v;
};

struct SQN_NR_SCS_SpecificCarrier_SQN_NR_FrequencyInfoDL_scs_SpecificCarrierList_Dynamic {
	size_t d;
	struct SQN_NR_SCS_SpecificCarrier* v;
};

struct SQN_NR_FrequencyInfoDL {
	struct SQN_NR_ARFCN_ValueNR_SQN_NR_FrequencyInfoDL_absoluteFrequencySSB_Optional absoluteFrequencySSB;
	SQN_NR_MultiFrequencyBandListNR frequencyBandList;
	SQN_NR_ARFCN_ValueNR absoluteFrequencyPointA;
	struct SQN_NR_SCS_SpecificCarrier_SQN_NR_FrequencyInfoDL_scs_SpecificCarrierList_Dynamic scs_SpecificCarrierList;
};

enum SQN_NR_FrequencyInfoUL_frequencyShift7p5khz_e {
	SQN_NR_FrequencyInfoUL_frequencyShift7p5khz_e_true = 0,
};

typedef enum SQN_NR_FrequencyInfoUL_frequencyShift7p5khz_e SQN_NR_FrequencyInfoUL_frequencyShift7p5khz_e;

struct SQN_NR_MultiFrequencyBandListNR_SQN_NR_FrequencyInfoUL_frequencyBandList_Optional {
	bool d;
	SQN_NR_MultiFrequencyBandListNR v;
};

struct SQN_NR_ARFCN_ValueNR_SQN_NR_FrequencyInfoUL_absoluteFrequencyPointA_Optional {
	bool d;
	SQN_NR_ARFCN_ValueNR v;
};

struct SQN_NR_SCS_SpecificCarrier_SQN_NR_FrequencyInfoUL_scs_SpecificCarrierList_Dynamic {
	size_t d;
	struct SQN_NR_SCS_SpecificCarrier* v;
};

struct SQN_NR_AdditionalSpectrumEmission_SQN_NR_FrequencyInfoUL_additionalSpectrumEmission_Optional {
	bool d;
	SQN_NR_AdditionalSpectrumEmission v;
};

struct SQN_NR_P_Max_SQN_NR_FrequencyInfoUL_p_Max_Optional {
	bool d;
	SQN_NR_P_Max v;
};

struct SQN_NR_FrequencyInfoUL_frequencyShift7p5khz_e_frequencyShift7p5khz_Optional {
	bool d;
	SQN_NR_FrequencyInfoUL_frequencyShift7p5khz_e v;
};

struct SQN_NR_FrequencyInfoUL {
	struct SQN_NR_MultiFrequencyBandListNR_SQN_NR_FrequencyInfoUL_frequencyBandList_Optional frequencyBandList;
	struct SQN_NR_ARFCN_ValueNR_SQN_NR_FrequencyInfoUL_absoluteFrequencyPointA_Optional absoluteFrequencyPointA;
	struct SQN_NR_SCS_SpecificCarrier_SQN_NR_FrequencyInfoUL_scs_SpecificCarrierList_Dynamic scs_SpecificCarrierList;
	struct SQN_NR_AdditionalSpectrumEmission_SQN_NR_FrequencyInfoUL_additionalSpectrumEmission_Optional additionalSpectrumEmission;
	struct SQN_NR_P_Max_SQN_NR_FrequencyInfoUL_p_Max_Optional p_Max;
	struct SQN_NR_FrequencyInfoUL_frequencyShift7p5khz_e_frequencyShift7p5khz_Optional frequencyShift7p5khz;
};

enum SQN_NR_IntegrityProtAlgorithm_e {
	SQN_NR_IntegrityProtAlgorithm_e_nia0 = 0,
	SQN_NR_IntegrityProtAlgorithm_e_nia1 = 1,
	SQN_NR_IntegrityProtAlgorithm_e_nia2 = 2,
	SQN_NR_IntegrityProtAlgorithm_e_nia3 = 3,
	SQN_NR_IntegrityProtAlgorithm_e_spare4 = 4,
	SQN_NR_IntegrityProtAlgorithm_e_spare3 = 5,
	SQN_NR_IntegrityProtAlgorithm_e_spare2 = 6,
	SQN_NR_IntegrityProtAlgorithm_e_spare1 = 7,
};

typedef enum SQN_NR_IntegrityProtAlgorithm_e SQN_NR_IntegrityProtAlgorithm_e;

enum SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e {
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps0 = 0,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps8 = 1,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps16 = 2,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps32 = 3,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps64 = 4,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps128 = 5,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps256 = 6,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps512 = 7,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps1024 = 8,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps2048 = 9,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps4096 = 10,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps8192 = 11,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps16384 = 12,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps32768 = 13,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_kBps65536 = 14,
	SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e_infinity = 15,
};

typedef enum SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e SQN_NR_LogicalChannelConfig_ul_SpecificParameters_prioritisedBitRate_e;

enum SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_Config_Sel {
	SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_Config_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_Config_release = 1,
	SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_Config_setup = 2,
};

union SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_Config_Value {
	Null release;
	struct SQN_NR_DRX_Config setup;
};

struct SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_Config {
	enum SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_Config_Sel d;
	union SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_Config_Value v;
};

enum SQN_NR_SchedulingRequestToAddMod_sr_ProhibitTimer_e {
	SQN_NR_SchedulingRequestToAddMod_sr_ProhibitTimer_e_ms1 = 0,
	SQN_NR_SchedulingRequestToAddMod_sr_ProhibitTimer_e_ms2 = 1,
	SQN_NR_SchedulingRequestToAddMod_sr_ProhibitTimer_e_ms4 = 2,
	SQN_NR_SchedulingRequestToAddMod_sr_ProhibitTimer_e_ms8 = 3,
	SQN_NR_SchedulingRequestToAddMod_sr_ProhibitTimer_e_ms16 = 4,
	SQN_NR_SchedulingRequestToAddMod_sr_ProhibitTimer_e_ms32 = 5,
	SQN_NR_SchedulingRequestToAddMod_sr_ProhibitTimer_e_ms64 = 6,
	SQN_NR_SchedulingRequestToAddMod_sr_ProhibitTimer_e_ms128 = 7,
};

typedef enum SQN_NR_SchedulingRequestToAddMod_sr_ProhibitTimer_e SQN_NR_SchedulingRequestToAddMod_sr_ProhibitTimer_e;

enum SQN_NR_SchedulingRequestToAddMod_sr_TransMax_e {
	SQN_NR_SchedulingRequestToAddMod_sr_TransMax_e_n4 = 0,
	SQN_NR_SchedulingRequestToAddMod_sr_TransMax_e_n8 = 1,
	SQN_NR_SchedulingRequestToAddMod_sr_TransMax_e_n16 = 2,
	SQN_NR_SchedulingRequestToAddMod_sr_TransMax_e_n32 = 3,
	SQN_NR_SchedulingRequestToAddMod_sr_TransMax_e_n64 = 4,
	SQN_NR_SchedulingRequestToAddMod_sr_TransMax_e_spare3 = 5,
	SQN_NR_SchedulingRequestToAddMod_sr_TransMax_e_spare2 = 6,
	SQN_NR_SchedulingRequestToAddMod_sr_TransMax_e_spare1 = 7,
};

typedef enum SQN_NR_SchedulingRequestToAddMod_sr_TransMax_e SQN_NR_SchedulingRequestToAddMod_sr_TransMax_e;

struct SQN_NR_SchedulingRequestToAddMod_sr_ProhibitTimer_e_sr_ProhibitTimer_Optional {
	bool d;
	SQN_NR_SchedulingRequestToAddMod_sr_ProhibitTimer_e v;
};

struct SQN_NR_SchedulingRequestToAddMod {
	SQN_NR_SchedulingRequestId schedulingRequestId;
	struct SQN_NR_SchedulingRequestToAddMod_sr_ProhibitTimer_e_sr_ProhibitTimer_Optional sr_ProhibitTimer;
	SQN_NR_SchedulingRequestToAddMod_sr_TransMax_e sr_TransMax;
};

struct SQN_NR_SchedulingRequestConfig_SQN_NR_SchedulingRequestToAddMod_schedulingRequestToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_SchedulingRequestToAddMod* v;
};

struct SQN_NR_SchedulingRequestToAddMod_SQN_NR_SchedulingRequestConfig_schedulingRequestToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_SchedulingRequestConfig_SQN_NR_SchedulingRequestToAddMod_schedulingRequestToAddModList_Dynamic v;
};

struct SQN_NR_SchedulingRequestId_SQN_NR_SchedulingRequestConfig_schedulingRequestToReleaseList_Dynamic {
	size_t d;
	SQN_NR_SchedulingRequestId* v;
};

struct SQN_NR_SchedulingRequestId_SQN_NR_SchedulingRequestConfig_schedulingRequestToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_SchedulingRequestId_SQN_NR_SchedulingRequestConfig_schedulingRequestToReleaseList_Dynamic v;
};

struct SQN_NR_SchedulingRequestConfig {
	struct SQN_NR_SchedulingRequestToAddMod_SQN_NR_SchedulingRequestConfig_schedulingRequestToAddModList_DynamicOptional schedulingRequestToAddModList;
	struct SQN_NR_SchedulingRequestId_SQN_NR_SchedulingRequestConfig_schedulingRequestToReleaseList_DynamicOptional schedulingRequestToReleaseList;
};

enum SQN_NR_BSR_Config_periodicBSR_Timer_e {
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf1 = 0,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf5 = 1,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf10 = 2,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf16 = 3,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf20 = 4,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf32 = 5,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf40 = 6,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf64 = 7,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf80 = 8,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf128 = 9,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf160 = 10,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf320 = 11,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf640 = 12,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf1280 = 13,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_sf2560 = 14,
	SQN_NR_BSR_Config_periodicBSR_Timer_e_infinity = 15,
};

typedef enum SQN_NR_BSR_Config_periodicBSR_Timer_e SQN_NR_BSR_Config_periodicBSR_Timer_e;

enum SQN_NR_BSR_Config_retxBSR_Timer_e {
	SQN_NR_BSR_Config_retxBSR_Timer_e_sf10 = 0,
	SQN_NR_BSR_Config_retxBSR_Timer_e_sf20 = 1,
	SQN_NR_BSR_Config_retxBSR_Timer_e_sf40 = 2,
	SQN_NR_BSR_Config_retxBSR_Timer_e_sf80 = 3,
	SQN_NR_BSR_Config_retxBSR_Timer_e_sf160 = 4,
	SQN_NR_BSR_Config_retxBSR_Timer_e_sf320 = 5,
	SQN_NR_BSR_Config_retxBSR_Timer_e_sf640 = 6,
	SQN_NR_BSR_Config_retxBSR_Timer_e_sf1280 = 7,
	SQN_NR_BSR_Config_retxBSR_Timer_e_sf2560 = 8,
	SQN_NR_BSR_Config_retxBSR_Timer_e_sf5120 = 9,
	SQN_NR_BSR_Config_retxBSR_Timer_e_sf10240 = 10,
	SQN_NR_BSR_Config_retxBSR_Timer_e_spare5 = 11,
	SQN_NR_BSR_Config_retxBSR_Timer_e_spare4 = 12,
	SQN_NR_BSR_Config_retxBSR_Timer_e_spare3 = 13,
	SQN_NR_BSR_Config_retxBSR_Timer_e_spare2 = 14,
	SQN_NR_BSR_Config_retxBSR_Timer_e_spare1 = 15,
};

typedef enum SQN_NR_BSR_Config_retxBSR_Timer_e SQN_NR_BSR_Config_retxBSR_Timer_e;

enum SQN_NR_BSR_Config_logicalChannelSR_DelayTimer_e {
	SQN_NR_BSR_Config_logicalChannelSR_DelayTimer_e_sf20 = 0,
	SQN_NR_BSR_Config_logicalChannelSR_DelayTimer_e_sf40 = 1,
	SQN_NR_BSR_Config_logicalChannelSR_DelayTimer_e_sf64 = 2,
	SQN_NR_BSR_Config_logicalChannelSR_DelayTimer_e_sf128 = 3,
	SQN_NR_BSR_Config_logicalChannelSR_DelayTimer_e_sf512 = 4,
	SQN_NR_BSR_Config_logicalChannelSR_DelayTimer_e_sf1024 = 5,
	SQN_NR_BSR_Config_logicalChannelSR_DelayTimer_e_sf2560 = 6,
	SQN_NR_BSR_Config_logicalChannelSR_DelayTimer_e_spare1 = 7,
};

typedef enum SQN_NR_BSR_Config_logicalChannelSR_DelayTimer_e SQN_NR_BSR_Config_logicalChannelSR_DelayTimer_e;

struct SQN_NR_BSR_Config_logicalChannelSR_DelayTimer_e_logicalChannelSR_DelayTimer_Optional {
	bool d;
	SQN_NR_BSR_Config_logicalChannelSR_DelayTimer_e v;
};

struct SQN_NR_BSR_Config {
	SQN_NR_BSR_Config_periodicBSR_Timer_e periodicBSR_Timer;
	SQN_NR_BSR_Config_retxBSR_Timer_e retxBSR_Timer;
	struct SQN_NR_BSR_Config_logicalChannelSR_DelayTimer_e_logicalChannelSR_DelayTimer_Optional logicalChannelSR_DelayTimer;
};

typedef uint8_t SQN_NR_TAG_Id;

struct SQN_NR_TAG {
	SQN_NR_TAG_Id tag_Id;
	SQN_NR_TimeAlignmentTimer_e timeAlignmentTimer;
};

struct SQN_NR_TAG_Id_SQN_NR_TAG_Config_tag_ToReleaseList_Dynamic {
	size_t d;
	SQN_NR_TAG_Id* v;
};

struct SQN_NR_TAG_Id_SQN_NR_TAG_Config_tag_ToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_TAG_Id_SQN_NR_TAG_Config_tag_ToReleaseList_Dynamic v;
};

struct SQN_NR_TAG_Config_SQN_NR_TAG_tag_ToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_TAG* v;
};

struct SQN_NR_TAG_SQN_NR_TAG_Config_tag_ToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_TAG_Config_SQN_NR_TAG_tag_ToAddModList_Dynamic v;
};

struct SQN_NR_TAG_Config {
	struct SQN_NR_TAG_Id_SQN_NR_TAG_Config_tag_ToReleaseList_DynamicOptional tag_ToReleaseList;
	struct SQN_NR_TAG_SQN_NR_TAG_Config_tag_ToAddModList_DynamicOptional tag_ToAddModList;
};

enum SQN_NR_PHR_Config_phr_PeriodicTimer_e {
	SQN_NR_PHR_Config_phr_PeriodicTimer_e_sf10 = 0,
	SQN_NR_PHR_Config_phr_PeriodicTimer_e_sf20 = 1,
	SQN_NR_PHR_Config_phr_PeriodicTimer_e_sf50 = 2,
	SQN_NR_PHR_Config_phr_PeriodicTimer_e_sf100 = 3,
	SQN_NR_PHR_Config_phr_PeriodicTimer_e_sf200 = 4,
	SQN_NR_PHR_Config_phr_PeriodicTimer_e_sf500 = 5,
	SQN_NR_PHR_Config_phr_PeriodicTimer_e_sf1000 = 6,
	SQN_NR_PHR_Config_phr_PeriodicTimer_e_infinity = 7,
};

typedef enum SQN_NR_PHR_Config_phr_PeriodicTimer_e SQN_NR_PHR_Config_phr_PeriodicTimer_e;

enum SQN_NR_PHR_Config_phr_ProhibitTimer_e {
	SQN_NR_PHR_Config_phr_ProhibitTimer_e_sf0 = 0,
	SQN_NR_PHR_Config_phr_ProhibitTimer_e_sf10 = 1,
	SQN_NR_PHR_Config_phr_ProhibitTimer_e_sf20 = 2,
	SQN_NR_PHR_Config_phr_ProhibitTimer_e_sf50 = 3,
	SQN_NR_PHR_Config_phr_ProhibitTimer_e_sf100 = 4,
	SQN_NR_PHR_Config_phr_ProhibitTimer_e_sf200 = 5,
	SQN_NR_PHR_Config_phr_ProhibitTimer_e_sf500 = 6,
	SQN_NR_PHR_Config_phr_ProhibitTimer_e_sf1000 = 7,
};

typedef enum SQN_NR_PHR_Config_phr_ProhibitTimer_e SQN_NR_PHR_Config_phr_ProhibitTimer_e;

enum SQN_NR_PHR_Config_phr_Tx_PowerFactorChange_e {
	SQN_NR_PHR_Config_phr_Tx_PowerFactorChange_e_dB1 = 0,
	SQN_NR_PHR_Config_phr_Tx_PowerFactorChange_e_dB3 = 1,
	SQN_NR_PHR_Config_phr_Tx_PowerFactorChange_e_dB6 = 2,
	SQN_NR_PHR_Config_phr_Tx_PowerFactorChange_e_infinity = 3,
};

typedef enum SQN_NR_PHR_Config_phr_Tx_PowerFactorChange_e SQN_NR_PHR_Config_phr_Tx_PowerFactorChange_e;

enum SQN_NR_PHR_Config_phr_ModeOtherCG_e {
	SQN_NR_PHR_Config_phr_ModeOtherCG_e_real = 0,
	SQN_NR_PHR_Config_phr_ModeOtherCG_e_virtual = 1,
};

typedef enum SQN_NR_PHR_Config_phr_ModeOtherCG_e SQN_NR_PHR_Config_phr_ModeOtherCG_e;

enum SQN_NR_MPE_Config_FR2_r16_mpe_ProhibitTimer_r16_e {
	SQN_NR_MPE_Config_FR2_r16_mpe_ProhibitTimer_r16_e_sf0 = 0,
	SQN_NR_MPE_Config_FR2_r16_mpe_ProhibitTimer_r16_e_sf10 = 1,
	SQN_NR_MPE_Config_FR2_r16_mpe_ProhibitTimer_r16_e_sf20 = 2,
	SQN_NR_MPE_Config_FR2_r16_mpe_ProhibitTimer_r16_e_sf50 = 3,
	SQN_NR_MPE_Config_FR2_r16_mpe_ProhibitTimer_r16_e_sf100 = 4,
	SQN_NR_MPE_Config_FR2_r16_mpe_ProhibitTimer_r16_e_sf200 = 5,
	SQN_NR_MPE_Config_FR2_r16_mpe_ProhibitTimer_r16_e_sf500 = 6,
	SQN_NR_MPE_Config_FR2_r16_mpe_ProhibitTimer_r16_e_sf1000 = 7,
};

typedef enum SQN_NR_MPE_Config_FR2_r16_mpe_ProhibitTimer_r16_e SQN_NR_MPE_Config_FR2_r16_mpe_ProhibitTimer_r16_e;

enum SQN_NR_MPE_Config_FR2_r16_mpe_Threshold_r16_e {
	SQN_NR_MPE_Config_FR2_r16_mpe_Threshold_r16_e_dB3 = 0,
	SQN_NR_MPE_Config_FR2_r16_mpe_Threshold_r16_e_dB6 = 1,
	SQN_NR_MPE_Config_FR2_r16_mpe_Threshold_r16_e_dB9 = 2,
	SQN_NR_MPE_Config_FR2_r16_mpe_Threshold_r16_e_dB12 = 3,
};

typedef enum SQN_NR_MPE_Config_FR2_r16_mpe_Threshold_r16_e SQN_NR_MPE_Config_FR2_r16_mpe_Threshold_r16_e;

struct SQN_NR_MPE_Config_FR2_r16 {
	SQN_NR_MPE_Config_FR2_r16_mpe_ProhibitTimer_r16_e mpe_ProhibitTimer_r16;
	SQN_NR_MPE_Config_FR2_r16_mpe_Threshold_r16_e mpe_Threshold_r16;
};

enum SQN_NR_SetupRelease_PHR_Config_mpe_Reporting_FR2_r16_Sel {
	SQN_NR_SetupRelease_PHR_Config_mpe_Reporting_FR2_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PHR_Config_mpe_Reporting_FR2_r16_release = 1,
	SQN_NR_SetupRelease_PHR_Config_mpe_Reporting_FR2_r16_setup = 2,
};

union SQN_NR_SetupRelease_PHR_Config_mpe_Reporting_FR2_r16_Value {
	Null release;
	struct SQN_NR_MPE_Config_FR2_r16 setup;
};

struct SQN_NR_SetupRelease_PHR_Config_mpe_Reporting_FR2_r16 {
	enum SQN_NR_SetupRelease_PHR_Config_mpe_Reporting_FR2_r16_Sel d;
	union SQN_NR_SetupRelease_PHR_Config_mpe_Reporting_FR2_r16_Value v;
};

struct SQN_NR_SetupRelease_PHR_Config_mpe_Reporting_FR2_r16_SQN_NR_PHR_Config_mpe_Reporting_FR2_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PHR_Config_mpe_Reporting_FR2_r16 v;
};

struct SQN_NR_PHR_Config {
	SQN_NR_PHR_Config_phr_PeriodicTimer_e phr_PeriodicTimer;
	SQN_NR_PHR_Config_phr_ProhibitTimer_e phr_ProhibitTimer;
	SQN_NR_PHR_Config_phr_Tx_PowerFactorChange_e phr_Tx_PowerFactorChange;
	bool multiplePHR;
	bool dummy;
	bool phr_Type2OtherCell;
	SQN_NR_PHR_Config_phr_ModeOtherCG_e phr_ModeOtherCG;
	struct SQN_NR_SetupRelease_PHR_Config_mpe_Reporting_FR2_r16_SQN_NR_PHR_Config_mpe_Reporting_FR2_r16_Optional mpe_Reporting_FR2_r16;
};

enum SQN_NR_SetupRelease_MAC_CellGroupConfig_phr_Config_Sel {
	SQN_NR_SetupRelease_MAC_CellGroupConfig_phr_Config_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_MAC_CellGroupConfig_phr_Config_release = 1,
	SQN_NR_SetupRelease_MAC_CellGroupConfig_phr_Config_setup = 2,
};

union SQN_NR_SetupRelease_MAC_CellGroupConfig_phr_Config_Value {
	Null release;
	struct SQN_NR_PHR_Config setup;
};

struct SQN_NR_SetupRelease_MAC_CellGroupConfig_phr_Config {
	enum SQN_NR_SetupRelease_MAC_CellGroupConfig_phr_Config_Sel d;
	union SQN_NR_SetupRelease_MAC_CellGroupConfig_phr_Config_Value v;
};

enum SQN_NR_DataInactivityTimer_e {
	SQN_NR_DataInactivityTimer_e_s1 = 0,
	SQN_NR_DataInactivityTimer_e_s2 = 1,
	SQN_NR_DataInactivityTimer_e_s3 = 2,
	SQN_NR_DataInactivityTimer_e_s5 = 3,
	SQN_NR_DataInactivityTimer_e_s7 = 4,
	SQN_NR_DataInactivityTimer_e_s10 = 5,
	SQN_NR_DataInactivityTimer_e_s15 = 6,
	SQN_NR_DataInactivityTimer_e_s20 = 7,
	SQN_NR_DataInactivityTimer_e_s40 = 8,
	SQN_NR_DataInactivityTimer_e_s50 = 9,
	SQN_NR_DataInactivityTimer_e_s60 = 10,
	SQN_NR_DataInactivityTimer_e_s80 = 11,
	SQN_NR_DataInactivityTimer_e_s100 = 12,
	SQN_NR_DataInactivityTimer_e_s120 = 13,
	SQN_NR_DataInactivityTimer_e_s150 = 14,
	SQN_NR_DataInactivityTimer_e_s180 = 15,
};

typedef enum SQN_NR_DataInactivityTimer_e SQN_NR_DataInactivityTimer_e;

enum SQN_NR_SetupRelease_MAC_CellGroupConfig_dataInactivityTimer_Sel {
	SQN_NR_SetupRelease_MAC_CellGroupConfig_dataInactivityTimer_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_MAC_CellGroupConfig_dataInactivityTimer_release = 1,
	SQN_NR_SetupRelease_MAC_CellGroupConfig_dataInactivityTimer_setup = 2,
};

union SQN_NR_SetupRelease_MAC_CellGroupConfig_dataInactivityTimer_Value {
	Null release;
	SQN_NR_DataInactivityTimer_e setup;
};

struct SQN_NR_SetupRelease_MAC_CellGroupConfig_dataInactivityTimer {
	enum SQN_NR_SetupRelease_MAC_CellGroupConfig_dataInactivityTimer_Sel d;
	union SQN_NR_SetupRelease_MAC_CellGroupConfig_dataInactivityTimer_Value v;
};

enum SQN_NR_MAC_CellGroupConfig_usePreBSR_r16_e {
	SQN_NR_MAC_CellGroupConfig_usePreBSR_r16_e_true = 0,
};

typedef enum SQN_NR_MAC_CellGroupConfig_usePreBSR_r16_e SQN_NR_MAC_CellGroupConfig_usePreBSR_r16_e;

enum SQN_NR_MAC_CellGroupConfig_lch_BasedPrioritization_r16_e {
	SQN_NR_MAC_CellGroupConfig_lch_BasedPrioritization_r16_e_enabled = 0,
};

typedef enum SQN_NR_MAC_CellGroupConfig_lch_BasedPrioritization_r16_e SQN_NR_MAC_CellGroupConfig_lch_BasedPrioritization_r16_e;

enum SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e {
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms1 = 0,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms2 = 1,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms3 = 2,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms4 = 3,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms5 = 4,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms6 = 5,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms8 = 6,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms10 = 7,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms20 = 8,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms30 = 9,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms40 = 10,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms50 = 11,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms60 = 12,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms80 = 13,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms100 = 14,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms200 = 15,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms300 = 16,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms400 = 17,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms500 = 18,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms600 = 19,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms800 = 20,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms1000 = 21,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms1200 = 22,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_ms1600 = 23,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_spare8 = 24,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_spare7 = 25,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_spare6 = 26,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_spare5 = 27,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_spare4 = 28,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_spare3 = 29,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_spare2 = 30,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e_spare1 = 31,
};

typedef enum SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e;

enum SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_Sel {
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_UNBOUND_VALUE = 0,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_subMilliSeconds = 1,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds = 2,
};

union SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_Value {
	uint8_t subMilliSeconds;
	SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_milliSeconds_e milliSeconds;
};

struct SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer {
	enum SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_Sel d;
	union SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer_Value v;
};

enum SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e {
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms0 = 0,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms1 = 1,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms2 = 2,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms3 = 3,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms4 = 4,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms5 = 5,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms6 = 6,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms8 = 7,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms10 = 8,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms20 = 9,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms30 = 10,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms40 = 11,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms50 = 12,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms60 = 13,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms80 = 14,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms100 = 15,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms200 = 16,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms300 = 17,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms500 = 18,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms750 = 19,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms1280 = 20,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms1920 = 21,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_ms2560 = 22,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_spare9 = 23,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_spare8 = 24,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_spare7 = 25,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_spare6 = 26,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_spare5 = 27,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_spare4 = 28,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_spare3 = 29,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_spare2 = 30,
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e_spare1 = 31,
};

typedef enum SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e;

struct SQN_NR_DRX_ConfigSecondaryGroup {
	struct SQN_NR_DRX_ConfigSecondaryGroup_drx_onDurationTimer drx_onDurationTimer;
	SQN_NR_DRX_ConfigSecondaryGroup_drx_InactivityTimer_e drx_InactivityTimer;
};

enum SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_ConfigSecondaryGroup_r16_Sel {
	SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_ConfigSecondaryGroup_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_ConfigSecondaryGroup_r16_release = 1,
	SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_ConfigSecondaryGroup_r16_setup = 2,
};

union SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_ConfigSecondaryGroup_r16_Value {
	Null release;
	struct SQN_NR_DRX_ConfigSecondaryGroup setup;
};

struct SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_ConfigSecondaryGroup_r16 {
	enum SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_ConfigSecondaryGroup_r16_Sel d;
	union SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_ConfigSecondaryGroup_r16_Value v;
};

struct SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_Config_SQN_NR_MAC_CellGroupConfig_drx_Config_Optional {
	bool d;
	struct SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_Config v;
};

struct SQN_NR_SchedulingRequestConfig_SQN_NR_MAC_CellGroupConfig_schedulingRequestConfig_Optional {
	bool d;
	struct SQN_NR_SchedulingRequestConfig v;
};

struct SQN_NR_BSR_Config_SQN_NR_MAC_CellGroupConfig_bsr_Config_Optional {
	bool d;
	struct SQN_NR_BSR_Config v;
};

struct SQN_NR_TAG_Config_SQN_NR_MAC_CellGroupConfig_tag_Config_Optional {
	bool d;
	struct SQN_NR_TAG_Config v;
};

struct SQN_NR_SetupRelease_MAC_CellGroupConfig_phr_Config_SQN_NR_MAC_CellGroupConfig_phr_Config_Optional {
	bool d;
	struct SQN_NR_SetupRelease_MAC_CellGroupConfig_phr_Config v;
};

struct bool_SQN_NR_MAC_CellGroupConfig_csi_Mask_Optional {
	bool d;
	bool v;
};

struct SQN_NR_SetupRelease_MAC_CellGroupConfig_dataInactivityTimer_SQN_NR_MAC_CellGroupConfig_dataInactivityTimer_Optional {
	bool d;
	struct SQN_NR_SetupRelease_MAC_CellGroupConfig_dataInactivityTimer v;
};

struct SQN_NR_MAC_CellGroupConfig_usePreBSR_r16_e_usePreBSR_r16_Optional {
	bool d;
	SQN_NR_MAC_CellGroupConfig_usePreBSR_r16_e v;
};

struct SQN_NR_SchedulingRequestId_SQN_NR_MAC_CellGroupConfig_schedulingRequestID_LBT_SCell_r16_Optional {
	bool d;
	SQN_NR_SchedulingRequestId v;
};

struct SQN_NR_MAC_CellGroupConfig_lch_BasedPrioritization_r16_e_lch_BasedPrioritization_r16_Optional {
	bool d;
	SQN_NR_MAC_CellGroupConfig_lch_BasedPrioritization_r16_e v;
};

struct SQN_NR_SchedulingRequestId_SQN_NR_MAC_CellGroupConfig_schedulingRequestID_BFR_SCell_r16_Optional {
	bool d;
	SQN_NR_SchedulingRequestId v;
};

struct SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_ConfigSecondaryGroup_r16_SQN_NR_MAC_CellGroupConfig_drx_ConfigSecondaryGroup_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_ConfigSecondaryGroup_r16 v;
};

struct SQN_NR_MAC_CellGroupConfig {
	struct SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_Config_SQN_NR_MAC_CellGroupConfig_drx_Config_Optional drx_Config;
	struct SQN_NR_SchedulingRequestConfig_SQN_NR_MAC_CellGroupConfig_schedulingRequestConfig_Optional schedulingRequestConfig;
	struct SQN_NR_BSR_Config_SQN_NR_MAC_CellGroupConfig_bsr_Config_Optional bsr_Config;
	struct SQN_NR_TAG_Config_SQN_NR_MAC_CellGroupConfig_tag_Config_Optional tag_Config;
	struct SQN_NR_SetupRelease_MAC_CellGroupConfig_phr_Config_SQN_NR_MAC_CellGroupConfig_phr_Config_Optional phr_Config;
	bool skipUplinkTxDynamic;
	struct bool_SQN_NR_MAC_CellGroupConfig_csi_Mask_Optional csi_Mask;
	struct SQN_NR_SetupRelease_MAC_CellGroupConfig_dataInactivityTimer_SQN_NR_MAC_CellGroupConfig_dataInactivityTimer_Optional dataInactivityTimer;
	struct SQN_NR_MAC_CellGroupConfig_usePreBSR_r16_e_usePreBSR_r16_Optional usePreBSR_r16;
	struct SQN_NR_SchedulingRequestId_SQN_NR_MAC_CellGroupConfig_schedulingRequestID_LBT_SCell_r16_Optional schedulingRequestID_LBT_SCell_r16;
	struct SQN_NR_MAC_CellGroupConfig_lch_BasedPrioritization_r16_e_lch_BasedPrioritization_r16_Optional lch_BasedPrioritization_r16;
	struct SQN_NR_SchedulingRequestId_SQN_NR_MAC_CellGroupConfig_schedulingRequestID_BFR_SCell_r16_Optional schedulingRequestID_BFR_SCell_r16;
	struct SQN_NR_SetupRelease_MAC_CellGroupConfig_drx_ConfigSecondaryGroup_r16_SQN_NR_MAC_CellGroupConfig_drx_ConfigSecondaryGroup_r16_Optional drx_ConfigSecondaryGroup_r16;
};

enum SQN_NR_GapConfig_mgl_e {
	SQN_NR_GapConfig_mgl_e_ms1dot5 = 0,
	SQN_NR_GapConfig_mgl_e_ms3 = 1,
	SQN_NR_GapConfig_mgl_e_ms3dot5 = 2,
	SQN_NR_GapConfig_mgl_e_ms4 = 3,
	SQN_NR_GapConfig_mgl_e_ms5dot5 = 4,
	SQN_NR_GapConfig_mgl_e_ms6 = 5,
};

typedef enum SQN_NR_GapConfig_mgl_e SQN_NR_GapConfig_mgl_e;

enum SQN_NR_GapConfig_mgrp_e {
	SQN_NR_GapConfig_mgrp_e_ms20 = 0,
	SQN_NR_GapConfig_mgrp_e_ms40 = 1,
	SQN_NR_GapConfig_mgrp_e_ms80 = 2,
	SQN_NR_GapConfig_mgrp_e_ms160 = 3,
};

typedef enum SQN_NR_GapConfig_mgrp_e SQN_NR_GapConfig_mgrp_e;

enum SQN_NR_GapConfig_mgta_e {
	SQN_NR_GapConfig_mgta_e_ms0 = 0,
	SQN_NR_GapConfig_mgta_e_ms0dot25 = 1,
	SQN_NR_GapConfig_mgta_e_ms0dot5 = 2,
};

typedef enum SQN_NR_GapConfig_mgta_e SQN_NR_GapConfig_mgta_e;

enum SQN_NR_GapConfig_refServCellIndicator_e {
	SQN_NR_GapConfig_refServCellIndicator_e_pCell = 0,
	SQN_NR_GapConfig_refServCellIndicator_e_pSCell = 1,
	SQN_NR_GapConfig_refServCellIndicator_e_mcg_FR2 = 2,
};

typedef enum SQN_NR_GapConfig_refServCellIndicator_e SQN_NR_GapConfig_refServCellIndicator_e;

enum SQN_NR_GapConfig_mgl_r16_e {
	SQN_NR_GapConfig_mgl_r16_e_ms10 = 0,
	SQN_NR_GapConfig_mgl_r16_e_ms20 = 1,
};

typedef enum SQN_NR_GapConfig_mgl_r16_e SQN_NR_GapConfig_mgl_r16_e;

struct SQN_NR_GapConfig_refServCellIndicator_e_refServCellIndicator_Optional {
	bool d;
	SQN_NR_GapConfig_refServCellIndicator_e v;
};

struct SQN_NR_ServCellIndex_SQN_NR_GapConfig_refFR2ServCellAsyncCA_r16_Optional {
	bool d;
	SQN_NR_ServCellIndex v;
};

struct SQN_NR_GapConfig_mgl_r16_e_mgl_r16_Optional {
	bool d;
	SQN_NR_GapConfig_mgl_r16_e v;
};

struct SQN_NR_GapConfig {
	uint8_t gapOffset;
	SQN_NR_GapConfig_mgl_e mgl;
	SQN_NR_GapConfig_mgrp_e mgrp;
	SQN_NR_GapConfig_mgta_e mgta;
	struct SQN_NR_GapConfig_refServCellIndicator_e_refServCellIndicator_Optional refServCellIndicator;
	struct SQN_NR_ServCellIndex_SQN_NR_GapConfig_refFR2ServCellAsyncCA_r16_Optional refFR2ServCellAsyncCA_r16;
	struct SQN_NR_GapConfig_mgl_r16_e_mgl_r16_Optional mgl_r16;
};

enum SQN_NR_SetupRelease_MeasGapConfig_gapFR2_Sel {
	SQN_NR_SetupRelease_MeasGapConfig_gapFR2_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_MeasGapConfig_gapFR2_release = 1,
	SQN_NR_SetupRelease_MeasGapConfig_gapFR2_setup = 2,
};

union SQN_NR_SetupRelease_MeasGapConfig_gapFR2_Value {
	Null release;
	struct SQN_NR_GapConfig setup;
};

struct SQN_NR_SetupRelease_MeasGapConfig_gapFR2 {
	enum SQN_NR_SetupRelease_MeasGapConfig_gapFR2_Sel d;
	union SQN_NR_SetupRelease_MeasGapConfig_gapFR2_Value v;
};

enum SQN_NR_SetupRelease_MeasGapConfig_gapFR1_Sel {
	SQN_NR_SetupRelease_MeasGapConfig_gapFR1_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_MeasGapConfig_gapFR1_release = 1,
	SQN_NR_SetupRelease_MeasGapConfig_gapFR1_setup = 2,
};

union SQN_NR_SetupRelease_MeasGapConfig_gapFR1_Value {
	Null release;
	struct SQN_NR_GapConfig setup;
};

struct SQN_NR_SetupRelease_MeasGapConfig_gapFR1 {
	enum SQN_NR_SetupRelease_MeasGapConfig_gapFR1_Sel d;
	union SQN_NR_SetupRelease_MeasGapConfig_gapFR1_Value v;
};

enum SQN_NR_SetupRelease_MeasGapConfig_gapUE_Sel {
	SQN_NR_SetupRelease_MeasGapConfig_gapUE_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_MeasGapConfig_gapUE_release = 1,
	SQN_NR_SetupRelease_MeasGapConfig_gapUE_setup = 2,
};

union SQN_NR_SetupRelease_MeasGapConfig_gapUE_Value {
	Null release;
	struct SQN_NR_GapConfig setup;
};

struct SQN_NR_SetupRelease_MeasGapConfig_gapUE {
	enum SQN_NR_SetupRelease_MeasGapConfig_gapUE_Sel d;
	union SQN_NR_SetupRelease_MeasGapConfig_gapUE_Value v;
};

struct SQN_NR_SetupRelease_MeasGapConfig_gapFR2_SQN_NR_MeasGapConfig_gapFR2_Optional {
	bool d;
	struct SQN_NR_SetupRelease_MeasGapConfig_gapFR2 v;
};

struct SQN_NR_SetupRelease_MeasGapConfig_gapFR1_SQN_NR_MeasGapConfig_gapFR1_Optional {
	bool d;
	struct SQN_NR_SetupRelease_MeasGapConfig_gapFR1 v;
};

struct SQN_NR_SetupRelease_MeasGapConfig_gapUE_SQN_NR_MeasGapConfig_gapUE_Optional {
	bool d;
	struct SQN_NR_SetupRelease_MeasGapConfig_gapUE v;
};

struct SQN_NR_MeasGapConfig {
	struct SQN_NR_SetupRelease_MeasGapConfig_gapFR2_SQN_NR_MeasGapConfig_gapFR2_Optional gapFR2;
	struct SQN_NR_SetupRelease_MeasGapConfig_gapFR1_SQN_NR_MeasGapConfig_gapFR1_Optional gapFR1;
	struct SQN_NR_SetupRelease_MeasGapConfig_gapUE_SQN_NR_MeasGapConfig_gapUE_Optional gapUE;
};

typedef B48 SQN_NR_NG_5G_S_TMSI;

typedef B40 SQN_NR_I_RNTI_Value;

enum SQN_NR_PagingUE_Identity_Sel {
	SQN_NR_PagingUE_Identity_UNBOUND_VALUE = 0,
	SQN_NR_PagingUE_Identity_ng_5G_S_TMSI = 1,
	SQN_NR_PagingUE_Identity_fullI_RNTI = 2,
};

union SQN_NR_PagingUE_Identity_Value {
	SQN_NR_NG_5G_S_TMSI ng_5G_S_TMSI;
	SQN_NR_I_RNTI_Value fullI_RNTI;
};

struct SQN_NR_PagingUE_Identity {
	enum SQN_NR_PagingUE_Identity_Sel d;
	union SQN_NR_PagingUE_Identity_Value v;
};

enum SQN_NR_PagingRecord_accessType_e {
	SQN_NR_PagingRecord_accessType_e_non3GPP = 0,
};

typedef enum SQN_NR_PagingRecord_accessType_e SQN_NR_PagingRecord_accessType_e;

struct SQN_NR_PagingRecord_accessType_e_accessType_Optional {
	bool d;
	SQN_NR_PagingRecord_accessType_e v;
};

struct SQN_NR_PagingRecord {
	struct SQN_NR_PagingUE_Identity ue_Identity;
	struct SQN_NR_PagingRecord_accessType_e_accessType_Optional accessType;
};

struct SQN_NR_PagingRecord_SQN_NR_PagingRecordList_Dynamic {
	size_t d;
	struct SQN_NR_PagingRecord* v;
};

typedef struct SQN_NR_PagingRecord_SQN_NR_PagingRecordList_Dynamic SQN_NR_PagingRecordList;

struct SQN_NR_Paging_nonCriticalExtension {
};

struct SQN_NR_PagingRecordList_SQN_NR_Paging_pagingRecordList_Optional {
	bool d;
	SQN_NR_PagingRecordList v;
};

struct OCTET_STRING_SQN_NR_Paging_lateNonCriticalExtension_Optional {
	bool d;
	OCTET_STRING v;
};

struct SQN_NR_Paging_nonCriticalExtension_nonCriticalExtension_Optional {
	bool d;
	struct SQN_NR_Paging_nonCriticalExtension v;
};

struct SQN_NR_Paging {
	struct SQN_NR_PagingRecordList_SQN_NR_Paging_pagingRecordList_Optional pagingRecordList;
	struct OCTET_STRING_SQN_NR_Paging_lateNonCriticalExtension_Optional lateNonCriticalExtension;
	struct SQN_NR_Paging_nonCriticalExtension_nonCriticalExtension_Optional nonCriticalExtension;
};

enum SQN_NR_PCCH_MessageType_c1_Sel {
	SQN_NR_PCCH_MessageType_c1_UNBOUND_VALUE = 0,
	SQN_NR_PCCH_MessageType_c1_paging = 1,
	SQN_NR_PCCH_MessageType_c1_spare1 = 2,
};

union SQN_NR_PCCH_MessageType_c1_Value {
	struct SQN_NR_Paging paging;
	Null spare1;
};

struct SQN_NR_PCCH_MessageType_c1 {
	enum SQN_NR_PCCH_MessageType_c1_Sel d;
	union SQN_NR_PCCH_MessageType_c1_Value v;
};

struct SQN_NR_PCCH_MessageType_messageClassExtension {
};

enum SQN_NR_PCCH_MessageType_Sel {
	SQN_NR_PCCH_MessageType_UNBOUND_VALUE = 0,
	SQN_NR_PCCH_MessageType_c1 = 1,
	SQN_NR_PCCH_MessageType_messageClassExtension = 2,
};

union SQN_NR_PCCH_MessageType_Value {
	struct SQN_NR_PCCH_MessageType_c1 c1;
	struct SQN_NR_PCCH_MessageType_messageClassExtension messageClassExtension;
};

struct SQN_NR_PCCH_MessageType {
	enum SQN_NR_PCCH_MessageType_Sel d;
	union SQN_NR_PCCH_MessageType_Value v;
};

struct SQN_NR_PCCH_Message {
	struct SQN_NR_PCCH_MessageType message;
};

enum SQN_NR_DMRS_DownlinkConfig_dmrs_Type_e {
	SQN_NR_DMRS_DownlinkConfig_dmrs_Type_e_type2 = 0,
};

typedef enum SQN_NR_DMRS_DownlinkConfig_dmrs_Type_e SQN_NR_DMRS_DownlinkConfig_dmrs_Type_e;

enum SQN_NR_DMRS_DownlinkConfig_dmrs_AdditionalPosition_e {
	SQN_NR_DMRS_DownlinkConfig_dmrs_AdditionalPosition_e_pos0 = 0,
	SQN_NR_DMRS_DownlinkConfig_dmrs_AdditionalPosition_e_pos1 = 1,
	SQN_NR_DMRS_DownlinkConfig_dmrs_AdditionalPosition_e_pos3 = 2,
};

typedef enum SQN_NR_DMRS_DownlinkConfig_dmrs_AdditionalPosition_e SQN_NR_DMRS_DownlinkConfig_dmrs_AdditionalPosition_e;

enum SQN_NR_DMRS_DownlinkConfig_maxLength_e {
	SQN_NR_DMRS_DownlinkConfig_maxLength_e_len2 = 0,
};

typedef enum SQN_NR_DMRS_DownlinkConfig_maxLength_e SQN_NR_DMRS_DownlinkConfig_maxLength_e;

enum SQN_NR_PTRS_DownlinkConfig_resourceElementOffset_e {
	SQN_NR_PTRS_DownlinkConfig_resourceElementOffset_e_offset01 = 0,
	SQN_NR_PTRS_DownlinkConfig_resourceElementOffset_e_offset10 = 1,
	SQN_NR_PTRS_DownlinkConfig_resourceElementOffset_e_offset11 = 2,
};

typedef enum SQN_NR_PTRS_DownlinkConfig_resourceElementOffset_e SQN_NR_PTRS_DownlinkConfig_resourceElementOffset_e;

enum SQN_NR_PTRS_DownlinkConfig_maxNrofPorts_r16_e {
	SQN_NR_PTRS_DownlinkConfig_maxNrofPorts_r16_e_n1 = 0,
	SQN_NR_PTRS_DownlinkConfig_maxNrofPorts_r16_e_n2 = 1,
};

typedef enum SQN_NR_PTRS_DownlinkConfig_maxNrofPorts_r16_e SQN_NR_PTRS_DownlinkConfig_maxNrofPorts_r16_e;

struct uint16_t_SQN_NR_PTRS_DownlinkConfig_frequencyDensity_ArrayOptional {
	bool d;
	uint16_t v[2];
};

struct uint8_t_SQN_NR_PTRS_DownlinkConfig_timeDensity_ArrayOptional {
	bool d;
	uint8_t v[3];
};

struct uint8_t_SQN_NR_PTRS_DownlinkConfig_epre_Ratio_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PTRS_DownlinkConfig_resourceElementOffset_e_resourceElementOffset_Optional {
	bool d;
	SQN_NR_PTRS_DownlinkConfig_resourceElementOffset_e v;
};

struct SQN_NR_PTRS_DownlinkConfig_maxNrofPorts_r16_e_maxNrofPorts_r16_Optional {
	bool d;
	SQN_NR_PTRS_DownlinkConfig_maxNrofPorts_r16_e v;
};

struct SQN_NR_PTRS_DownlinkConfig {
	struct uint16_t_SQN_NR_PTRS_DownlinkConfig_frequencyDensity_ArrayOptional frequencyDensity;
	struct uint8_t_SQN_NR_PTRS_DownlinkConfig_timeDensity_ArrayOptional timeDensity;
	struct uint8_t_SQN_NR_PTRS_DownlinkConfig_epre_Ratio_Optional epre_Ratio;
	struct SQN_NR_PTRS_DownlinkConfig_resourceElementOffset_e_resourceElementOffset_Optional resourceElementOffset;
	struct SQN_NR_PTRS_DownlinkConfig_maxNrofPorts_r16_e_maxNrofPorts_r16_Optional maxNrofPorts_r16;
};

enum SQN_NR_SetupRelease_DMRS_DownlinkConfig_phaseTrackingRS_Sel {
	SQN_NR_SetupRelease_DMRS_DownlinkConfig_phaseTrackingRS_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_DMRS_DownlinkConfig_phaseTrackingRS_release = 1,
	SQN_NR_SetupRelease_DMRS_DownlinkConfig_phaseTrackingRS_setup = 2,
};

union SQN_NR_SetupRelease_DMRS_DownlinkConfig_phaseTrackingRS_Value {
	Null release;
	struct SQN_NR_PTRS_DownlinkConfig setup;
};

struct SQN_NR_SetupRelease_DMRS_DownlinkConfig_phaseTrackingRS {
	enum SQN_NR_SetupRelease_DMRS_DownlinkConfig_phaseTrackingRS_Sel d;
	union SQN_NR_SetupRelease_DMRS_DownlinkConfig_phaseTrackingRS_Value v;
};

enum SQN_NR_DMRS_DownlinkConfig_dmrs_Downlink_r16_e {
	SQN_NR_DMRS_DownlinkConfig_dmrs_Downlink_r16_e_enabled = 0,
};

typedef enum SQN_NR_DMRS_DownlinkConfig_dmrs_Downlink_r16_e SQN_NR_DMRS_DownlinkConfig_dmrs_Downlink_r16_e;

struct SQN_NR_DMRS_DownlinkConfig_dmrs_Type_e_dmrs_Type_Optional {
	bool d;
	SQN_NR_DMRS_DownlinkConfig_dmrs_Type_e v;
};

struct SQN_NR_DMRS_DownlinkConfig_dmrs_AdditionalPosition_e_dmrs_AdditionalPosition_Optional {
	bool d;
	SQN_NR_DMRS_DownlinkConfig_dmrs_AdditionalPosition_e v;
};

struct SQN_NR_DMRS_DownlinkConfig_maxLength_e_maxLength_Optional {
	bool d;
	SQN_NR_DMRS_DownlinkConfig_maxLength_e v;
};

struct uint16_t_SQN_NR_DMRS_DownlinkConfig_scramblingID0_Optional {
	bool d;
	uint16_t v;
};

struct uint16_t_SQN_NR_DMRS_DownlinkConfig_scramblingID1_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_SetupRelease_DMRS_DownlinkConfig_phaseTrackingRS_SQN_NR_DMRS_DownlinkConfig_phaseTrackingRS_Optional {
	bool d;
	struct SQN_NR_SetupRelease_DMRS_DownlinkConfig_phaseTrackingRS v;
};

struct SQN_NR_DMRS_DownlinkConfig_dmrs_Downlink_r16_e_dmrs_Downlink_r16_Optional {
	bool d;
	SQN_NR_DMRS_DownlinkConfig_dmrs_Downlink_r16_e v;
};

struct SQN_NR_DMRS_DownlinkConfig {
	struct SQN_NR_DMRS_DownlinkConfig_dmrs_Type_e_dmrs_Type_Optional dmrs_Type;
	struct SQN_NR_DMRS_DownlinkConfig_dmrs_AdditionalPosition_e_dmrs_AdditionalPosition_Optional dmrs_AdditionalPosition;
	struct SQN_NR_DMRS_DownlinkConfig_maxLength_e_maxLength_Optional maxLength;
	struct uint16_t_SQN_NR_DMRS_DownlinkConfig_scramblingID0_Optional scramblingID0;
	struct uint16_t_SQN_NR_DMRS_DownlinkConfig_scramblingID1_Optional scramblingID1;
	struct SQN_NR_SetupRelease_DMRS_DownlinkConfig_phaseTrackingRS_SQN_NR_DMRS_DownlinkConfig_phaseTrackingRS_Optional phaseTrackingRS;
	struct SQN_NR_DMRS_DownlinkConfig_dmrs_Downlink_r16_e_dmrs_Downlink_r16_Optional dmrs_Downlink_r16;
};

enum SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_Sel {
	SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_release = 1,
	SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_setup = 2,
};

union SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_Value {
	Null release;
	struct SQN_NR_DMRS_DownlinkConfig setup;
};

struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA {
	enum SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_Sel d;
	union SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_Value v;
};

enum SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_Sel {
	SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_release = 1,
	SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_setup = 2,
};

union SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_Value {
	Null release;
	struct SQN_NR_DMRS_DownlinkConfig setup;
};

struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB {
	enum SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_Sel d;
	union SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_Value v;
};

enum SQN_NR_QCL_Info_referenceSignal_Sel {
	SQN_NR_QCL_Info_referenceSignal_UNBOUND_VALUE = 0,
	SQN_NR_QCL_Info_referenceSignal_csi_rs = 1,
	SQN_NR_QCL_Info_referenceSignal_ssb = 2,
};

union SQN_NR_QCL_Info_referenceSignal_Value {
	SQN_NR_NZP_CSI_RS_ResourceId csi_rs;
	SQN_NR_SSB_Index ssb;
};

struct SQN_NR_QCL_Info_referenceSignal {
	enum SQN_NR_QCL_Info_referenceSignal_Sel d;
	union SQN_NR_QCL_Info_referenceSignal_Value v;
};

enum SQN_NR_QCL_Info_qcl_Type_e {
	SQN_NR_QCL_Info_qcl_Type_e_typeA = 0,
	SQN_NR_QCL_Info_qcl_Type_e_typeB = 1,
	SQN_NR_QCL_Info_qcl_Type_e_typeC = 2,
	SQN_NR_QCL_Info_qcl_Type_e_typeD = 3,
};

typedef enum SQN_NR_QCL_Info_qcl_Type_e SQN_NR_QCL_Info_qcl_Type_e;

struct SQN_NR_ServCellIndex_SQN_NR_QCL_Info_cell_Optional {
	bool d;
	SQN_NR_ServCellIndex v;
};

struct SQN_NR_BWP_Id_SQN_NR_QCL_Info_bwp_Id_Optional {
	bool d;
	SQN_NR_BWP_Id v;
};

struct SQN_NR_QCL_Info {
	struct SQN_NR_ServCellIndex_SQN_NR_QCL_Info_cell_Optional cell;
	struct SQN_NR_BWP_Id_SQN_NR_QCL_Info_bwp_Id_Optional bwp_Id;
	struct SQN_NR_QCL_Info_referenceSignal referenceSignal;
	SQN_NR_QCL_Info_qcl_Type_e qcl_Type;
};

struct SQN_NR_QCL_Info_SQN_NR_TCI_State_qcl_Type2_Optional {
	bool d;
	struct SQN_NR_QCL_Info v;
};

struct SQN_NR_TCI_State {
	SQN_NR_TCI_StateId tci_StateId;
	struct SQN_NR_QCL_Info qcl_Type1;
	struct SQN_NR_QCL_Info_SQN_NR_TCI_State_qcl_Type2_Optional qcl_Type2;
};

enum SQN_NR_PDSCH_Config_vrb_ToPRB_Interleaver_e {
	SQN_NR_PDSCH_Config_vrb_ToPRB_Interleaver_e_n2 = 0,
	SQN_NR_PDSCH_Config_vrb_ToPRB_Interleaver_e_n4 = 1,
};

typedef enum SQN_NR_PDSCH_Config_vrb_ToPRB_Interleaver_e SQN_NR_PDSCH_Config_vrb_ToPRB_Interleaver_e;

enum SQN_NR_PDSCH_Config_resourceAllocation_e {
	SQN_NR_PDSCH_Config_resourceAllocation_e_resourceAllocationType0 = 0,
	SQN_NR_PDSCH_Config_resourceAllocation_e_resourceAllocationType1 = 1,
	SQN_NR_PDSCH_Config_resourceAllocation_e_dynamicSwitch = 2,
};

typedef enum SQN_NR_PDSCH_Config_resourceAllocation_e SQN_NR_PDSCH_Config_resourceAllocation_e;

enum SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_Sel {
	SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_release = 1,
	SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_setup = 2,
};

union SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_Value {
	Null release;
	SQN_NR_PDSCH_TimeDomainResourceAllocationList setup;
};

struct SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList {
	enum SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_Sel d;
	union SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_Value v;
};

enum SQN_NR_PDSCH_Config_pdsch_AggregationFactor_e {
	SQN_NR_PDSCH_Config_pdsch_AggregationFactor_e_n2 = 0,
	SQN_NR_PDSCH_Config_pdsch_AggregationFactor_e_n4 = 1,
	SQN_NR_PDSCH_Config_pdsch_AggregationFactor_e_n8 = 2,
};

typedef enum SQN_NR_PDSCH_Config_pdsch_AggregationFactor_e SQN_NR_PDSCH_Config_pdsch_AggregationFactor_e;

typedef uint8_t SQN_NR_RateMatchPatternId;

enum SQN_NR_RateMatchPattern_patternType_bitmaps_symbolsInResourceBlock_Sel {
	SQN_NR_RateMatchPattern_patternType_bitmaps_symbolsInResourceBlock_UNBOUND_VALUE = 0,
	SQN_NR_RateMatchPattern_patternType_bitmaps_symbolsInResourceBlock_oneSlot = 1,
	SQN_NR_RateMatchPattern_patternType_bitmaps_symbolsInResourceBlock_twoSlots = 2,
};

union SQN_NR_RateMatchPattern_patternType_bitmaps_symbolsInResourceBlock_Value {
	B14 oneSlot;
	B28 twoSlots;
};

struct SQN_NR_RateMatchPattern_patternType_bitmaps_symbolsInResourceBlock {
	enum SQN_NR_RateMatchPattern_patternType_bitmaps_symbolsInResourceBlock_Sel d;
	union SQN_NR_RateMatchPattern_patternType_bitmaps_symbolsInResourceBlock_Value v;
};

enum SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern_Sel {
	SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern_UNBOUND_VALUE = 0,
	SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern_n2 = 1,
	SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern_n4 = 2,
	SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern_n5 = 3,
	SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern_n8 = 4,
	SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern_n10 = 5,
	SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern_n20 = 6,
	SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern_n40 = 7,
};

union SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern_Value {
	B2 n2;
	B4 n4;
	B5 n5;
	B8 n8;
	B10 n10;
	B20 n20;
	B40 n40;
};

struct SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern {
	enum SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern_Sel d;
	union SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern_Value v;
};

struct SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern_periodicityAndPattern_Optional {
	bool d;
	struct SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern v;
};

struct SQN_NR_RateMatchPattern_patternType_bitmaps {
	B275 resourceBlocks;
	struct SQN_NR_RateMatchPattern_patternType_bitmaps_symbolsInResourceBlock symbolsInResourceBlock;
	struct SQN_NR_RateMatchPattern_patternType_bitmaps_periodicityAndPattern_periodicityAndPattern_Optional periodicityAndPattern;
};

enum SQN_NR_RateMatchPattern_patternType_Sel {
	SQN_NR_RateMatchPattern_patternType_UNBOUND_VALUE = 0,
	SQN_NR_RateMatchPattern_patternType_bitmaps = 1,
	SQN_NR_RateMatchPattern_patternType_controlResourceSet = 2,
};

union SQN_NR_RateMatchPattern_patternType_Value {
	struct SQN_NR_RateMatchPattern_patternType_bitmaps bitmaps;
	SQN_NR_ControlResourceSetId controlResourceSet;
};

struct SQN_NR_RateMatchPattern_patternType {
	enum SQN_NR_RateMatchPattern_patternType_Sel d;
	union SQN_NR_RateMatchPattern_patternType_Value v;
};

enum SQN_NR_RateMatchPattern_dummy_e {
	SQN_NR_RateMatchPattern_dummy_e_dynamic = 0,
	SQN_NR_RateMatchPattern_dummy_e_semiStatic = 1,
};

typedef enum SQN_NR_RateMatchPattern_dummy_e SQN_NR_RateMatchPattern_dummy_e;

struct SQN_NR_SubcarrierSpacing_e_SQN_NR_RateMatchPattern_subcarrierSpacing_Optional {
	bool d;
	SQN_NR_SubcarrierSpacing_e v;
};

struct SQN_NR_ControlResourceSetId_r16_SQN_NR_RateMatchPattern_controlResourceSet_r16_Optional {
	bool d;
	SQN_NR_ControlResourceSetId_r16 v;
};

struct SQN_NR_RateMatchPattern {
	SQN_NR_RateMatchPatternId rateMatchPatternId;
	struct SQN_NR_RateMatchPattern_patternType patternType;
	struct SQN_NR_SubcarrierSpacing_e_SQN_NR_RateMatchPattern_subcarrierSpacing_Optional subcarrierSpacing;
	SQN_NR_RateMatchPattern_dummy_e dummy;
	struct SQN_NR_ControlResourceSetId_r16_SQN_NR_RateMatchPattern_controlResourceSet_r16_Optional controlResourceSet_r16;
};

enum SQN_NR_RateMatchPatternGroup_s_Sel {
	SQN_NR_RateMatchPatternGroup_s_UNBOUND_VALUE = 0,
	SQN_NR_RateMatchPatternGroup_s_cellLevel = 1,
	SQN_NR_RateMatchPatternGroup_s_bwpLevel = 2,
};

union SQN_NR_RateMatchPatternGroup_s_Value {
	SQN_NR_RateMatchPatternId cellLevel;
	SQN_NR_RateMatchPatternId bwpLevel;
};

struct SQN_NR_RateMatchPatternGroup_s {
	enum SQN_NR_RateMatchPatternGroup_s_Sel d;
	union SQN_NR_RateMatchPatternGroup_s_Value v;
};

struct SQN_NR_RateMatchPatternGroup_s_SQN_NR_RateMatchPatternGroup_Dynamic {
	size_t d;
	struct SQN_NR_RateMatchPatternGroup_s* v;
};

typedef struct SQN_NR_RateMatchPatternGroup_s_SQN_NR_RateMatchPatternGroup_Dynamic SQN_NR_RateMatchPatternGroup;

enum SQN_NR_PDSCH_Config_rbg_Size_e {
	SQN_NR_PDSCH_Config_rbg_Size_e_config1 = 0,
	SQN_NR_PDSCH_Config_rbg_Size_e_config2 = 1,
};

typedef enum SQN_NR_PDSCH_Config_rbg_Size_e SQN_NR_PDSCH_Config_rbg_Size_e;

enum SQN_NR_PDSCH_Config_mcs_Table_e {
	SQN_NR_PDSCH_Config_mcs_Table_e_qam256 = 0,
	SQN_NR_PDSCH_Config_mcs_Table_e_qam64LowSE = 1,
};

typedef enum SQN_NR_PDSCH_Config_mcs_Table_e SQN_NR_PDSCH_Config_mcs_Table_e;

enum SQN_NR_PDSCH_Config_maxNrofCodeWordsScheduledByDCI_e {
	SQN_NR_PDSCH_Config_maxNrofCodeWordsScheduledByDCI_e_n1 = 0,
	SQN_NR_PDSCH_Config_maxNrofCodeWordsScheduledByDCI_e_n2 = 1,
};

typedef enum SQN_NR_PDSCH_Config_maxNrofCodeWordsScheduledByDCI_e SQN_NR_PDSCH_Config_maxNrofCodeWordsScheduledByDCI_e;

enum SQN_NR_PDSCH_Config_prb_BundlingType_staticBundling_bundleSize_e {
	SQN_NR_PDSCH_Config_prb_BundlingType_staticBundling_bundleSize_e_n4 = 0,
	SQN_NR_PDSCH_Config_prb_BundlingType_staticBundling_bundleSize_e_wideband = 1,
};

typedef enum SQN_NR_PDSCH_Config_prb_BundlingType_staticBundling_bundleSize_e SQN_NR_PDSCH_Config_prb_BundlingType_staticBundling_bundleSize_e;

struct SQN_NR_PDSCH_Config_prb_BundlingType_staticBundling_bundleSize_e_bundleSize_Optional {
	bool d;
	SQN_NR_PDSCH_Config_prb_BundlingType_staticBundling_bundleSize_e v;
};

struct SQN_NR_PDSCH_Config_prb_BundlingType_staticBundling {
	struct SQN_NR_PDSCH_Config_prb_BundlingType_staticBundling_bundleSize_e_bundleSize_Optional bundleSize;
};

enum SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet1_e {
	SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet1_e_n4 = 0,
	SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet1_e_wideband = 1,
	SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet1_e_n2_wideband = 2,
	SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet1_e_n4_wideband = 3,
};

typedef enum SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet1_e SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet1_e;

enum SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet2_e {
	SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet2_e_n4 = 0,
	SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet2_e_wideband = 1,
};

typedef enum SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet2_e SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet2_e;

struct SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet1_e_bundleSizeSet1_Optional {
	bool d;
	SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet1_e v;
};

struct SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet2_e_bundleSizeSet2_Optional {
	bool d;
	SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet2_e v;
};

struct SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling {
	struct SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet1_e_bundleSizeSet1_Optional bundleSizeSet1;
	struct SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling_bundleSizeSet2_e_bundleSizeSet2_Optional bundleSizeSet2;
};

enum SQN_NR_PDSCH_Config_prb_BundlingType_Sel {
	SQN_NR_PDSCH_Config_prb_BundlingType_UNBOUND_VALUE = 0,
	SQN_NR_PDSCH_Config_prb_BundlingType_staticBundling = 1,
	SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling = 2,
};

union SQN_NR_PDSCH_Config_prb_BundlingType_Value {
	struct SQN_NR_PDSCH_Config_prb_BundlingType_staticBundling staticBundling;
	struct SQN_NR_PDSCH_Config_prb_BundlingType_dynamicBundling dynamicBundling;
};

struct SQN_NR_PDSCH_Config_prb_BundlingType {
	enum SQN_NR_PDSCH_Config_prb_BundlingType_Sel d;
	union SQN_NR_PDSCH_Config_prb_BundlingType_Value v;
};

typedef uint8_t SQN_NR_ZP_CSI_RS_ResourceId;

enum SQN_NR_CSI_ResourcePeriodicityAndOffset_Sel {
	SQN_NR_CSI_ResourcePeriodicityAndOffset_UNBOUND_VALUE = 0,
	SQN_NR_CSI_ResourcePeriodicityAndOffset_slots4 = 1,
	SQN_NR_CSI_ResourcePeriodicityAndOffset_slots5 = 2,
	SQN_NR_CSI_ResourcePeriodicityAndOffset_slots8 = 3,
	SQN_NR_CSI_ResourcePeriodicityAndOffset_slots10 = 4,
	SQN_NR_CSI_ResourcePeriodicityAndOffset_slots16 = 5,
	SQN_NR_CSI_ResourcePeriodicityAndOffset_slots20 = 6,
	SQN_NR_CSI_ResourcePeriodicityAndOffset_slots32 = 7,
	SQN_NR_CSI_ResourcePeriodicityAndOffset_slots40 = 8,
	SQN_NR_CSI_ResourcePeriodicityAndOffset_slots64 = 9,
	SQN_NR_CSI_ResourcePeriodicityAndOffset_slots80 = 10,
	SQN_NR_CSI_ResourcePeriodicityAndOffset_slots160 = 11,
	SQN_NR_CSI_ResourcePeriodicityAndOffset_slots320 = 12,
	SQN_NR_CSI_ResourcePeriodicityAndOffset_slots640 = 13,
};

union SQN_NR_CSI_ResourcePeriodicityAndOffset_Value {
	uint8_t slots4;
	uint8_t slots5;
	uint8_t slots8;
	uint8_t slots10;
	uint8_t slots16;
	uint8_t slots20;
	uint8_t slots32;
	uint8_t slots40;
	uint8_t slots64;
	uint8_t slots80;
	uint8_t slots160;
	uint16_t slots320;
	uint16_t slots640;
};

struct SQN_NR_CSI_ResourcePeriodicityAndOffset {
	enum SQN_NR_CSI_ResourcePeriodicityAndOffset_Sel d;
	union SQN_NR_CSI_ResourcePeriodicityAndOffset_Value v;
};

struct SQN_NR_CSI_ResourcePeriodicityAndOffset_SQN_NR_ZP_CSI_RS_Resource_periodicityAndOffset_Optional {
	bool d;
	struct SQN_NR_CSI_ResourcePeriodicityAndOffset v;
};

struct SQN_NR_ZP_CSI_RS_Resource {
	SQN_NR_ZP_CSI_RS_ResourceId zp_CSI_RS_ResourceId;
	struct SQN_NR_CSI_RS_ResourceMapping resourceMapping;
	struct SQN_NR_CSI_ResourcePeriodicityAndOffset_SQN_NR_ZP_CSI_RS_Resource_periodicityAndOffset_Optional periodicityAndOffset;
};

typedef uint8_t SQN_NR_ZP_CSI_RS_ResourceSetId;

struct SQN_NR_ZP_CSI_RS_ResourceId_zp_CSI_RS_ResourceIdList_Dynamic {
	size_t d;
	SQN_NR_ZP_CSI_RS_ResourceId* v;
};

struct SQN_NR_ZP_CSI_RS_ResourceSet {
	SQN_NR_ZP_CSI_RS_ResourceSetId zp_CSI_RS_ResourceSetId;
	struct SQN_NR_ZP_CSI_RS_ResourceId_zp_CSI_RS_ResourceIdList_Dynamic zp_CSI_RS_ResourceIdList;
};

enum SQN_NR_SetupRelease_PDSCH_Config_p_ZP_CSI_RS_ResourceSet_Sel {
	SQN_NR_SetupRelease_PDSCH_Config_p_ZP_CSI_RS_ResourceSet_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PDSCH_Config_p_ZP_CSI_RS_ResourceSet_release = 1,
	SQN_NR_SetupRelease_PDSCH_Config_p_ZP_CSI_RS_ResourceSet_setup = 2,
};

union SQN_NR_SetupRelease_PDSCH_Config_p_ZP_CSI_RS_ResourceSet_Value {
	Null release;
	struct SQN_NR_ZP_CSI_RS_ResourceSet setup;
};

struct SQN_NR_SetupRelease_PDSCH_Config_p_ZP_CSI_RS_ResourceSet {
	enum SQN_NR_SetupRelease_PDSCH_Config_p_ZP_CSI_RS_ResourceSet_Sel d;
	union SQN_NR_SetupRelease_PDSCH_Config_p_ZP_CSI_RS_ResourceSet_Value v;
};

typedef uint8_t SQN_NR_MaxMIMO_LayersDL_r16;

enum SQN_NR_SetupRelease_PDSCH_Config_maxMIMO_Layers_r16_Sel {
	SQN_NR_SetupRelease_PDSCH_Config_maxMIMO_Layers_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PDSCH_Config_maxMIMO_Layers_r16_release = 1,
	SQN_NR_SetupRelease_PDSCH_Config_maxMIMO_Layers_r16_setup = 2,
};

union SQN_NR_SetupRelease_PDSCH_Config_maxMIMO_Layers_r16_Value {
	Null release;
	SQN_NR_MaxMIMO_LayersDL_r16 setup;
};

struct SQN_NR_SetupRelease_PDSCH_Config_maxMIMO_Layers_r16 {
	enum SQN_NR_SetupRelease_PDSCH_Config_maxMIMO_Layers_r16_Sel d;
	union SQN_NR_SetupRelease_PDSCH_Config_maxMIMO_Layers_r16_Value v;
};

struct uint8_t_SQN_NR_MinSchedulingOffsetK0_Values_r16_Dynamic {
	size_t d;
	uint8_t* v;
};

typedef struct uint8_t_SQN_NR_MinSchedulingOffsetK0_Values_r16_Dynamic SQN_NR_MinSchedulingOffsetK0_Values_r16;

enum SQN_NR_SetupRelease_PDSCH_Config_minimumSchedulingOffsetK0_r16_Sel {
	SQN_NR_SetupRelease_PDSCH_Config_minimumSchedulingOffsetK0_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PDSCH_Config_minimumSchedulingOffsetK0_r16_release = 1,
	SQN_NR_SetupRelease_PDSCH_Config_minimumSchedulingOffsetK0_r16_setup = 2,
};

union SQN_NR_SetupRelease_PDSCH_Config_minimumSchedulingOffsetK0_r16_Value {
	Null release;
	SQN_NR_MinSchedulingOffsetK0_Values_r16 setup;
};

struct SQN_NR_SetupRelease_PDSCH_Config_minimumSchedulingOffsetK0_r16 {
	enum SQN_NR_SetupRelease_PDSCH_Config_minimumSchedulingOffsetK0_r16_Sel d;
	union SQN_NR_SetupRelease_PDSCH_Config_minimumSchedulingOffsetK0_r16_Value v;
};

enum SQN_NR_PDSCH_Config_antennaPortsFieldPresenceDCI_1_2_r16_e {
	SQN_NR_PDSCH_Config_antennaPortsFieldPresenceDCI_1_2_r16_e_enabled = 0,
};

typedef enum SQN_NR_PDSCH_Config_antennaPortsFieldPresenceDCI_1_2_r16_e SQN_NR_PDSCH_Config_antennaPortsFieldPresenceDCI_1_2_r16_e;

enum SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_DCI_1_2_r16_Sel {
	SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_DCI_1_2_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_DCI_1_2_r16_release = 1,
	SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_DCI_1_2_r16_setup = 2,
};

union SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_DCI_1_2_r16_Value {
	Null release;
	struct SQN_NR_DMRS_DownlinkConfig setup;
};

struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_DCI_1_2_r16 {
	enum SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_DCI_1_2_r16_Sel d;
	union SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_DCI_1_2_r16_Value v;
};

enum SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_DCI_1_2_r16_Sel {
	SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_DCI_1_2_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_DCI_1_2_r16_release = 1,
	SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_DCI_1_2_r16_setup = 2,
};

union SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_DCI_1_2_r16_Value {
	Null release;
	struct SQN_NR_DMRS_DownlinkConfig setup;
};

struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_DCI_1_2_r16 {
	enum SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_DCI_1_2_r16_Sel d;
	union SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_DCI_1_2_r16_Value v;
};

enum SQN_NR_PDSCH_Config_dmrs_SequenceInitializationDCI_1_2_r16_e {
	SQN_NR_PDSCH_Config_dmrs_SequenceInitializationDCI_1_2_r16_e_enabled = 0,
};

typedef enum SQN_NR_PDSCH_Config_dmrs_SequenceInitializationDCI_1_2_r16_e SQN_NR_PDSCH_Config_dmrs_SequenceInitializationDCI_1_2_r16_e;

enum SQN_NR_PDSCH_Config_mcs_TableDCI_1_2_r16_e {
	SQN_NR_PDSCH_Config_mcs_TableDCI_1_2_r16_e_qam256 = 0,
	SQN_NR_PDSCH_Config_mcs_TableDCI_1_2_r16_e_qam64LowSE = 1,
};

typedef enum SQN_NR_PDSCH_Config_mcs_TableDCI_1_2_r16_e SQN_NR_PDSCH_Config_mcs_TableDCI_1_2_r16_e;

enum SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_mappingType_r16_e {
	SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_mappingType_r16_e_typeA = 0,
	SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_mappingType_r16_e_typeB = 1,
};

typedef enum SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_mappingType_r16_e SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_mappingType_r16_e;

enum SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_repetitionNumber_r16_e {
	SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_repetitionNumber_r16_e_n2 = 0,
	SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_repetitionNumber_r16_e_n3 = 1,
	SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_repetitionNumber_r16_e_n4 = 2,
	SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_repetitionNumber_r16_e_n5 = 3,
	SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_repetitionNumber_r16_e_n6 = 4,
	SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_repetitionNumber_r16_e_n7 = 5,
	SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_repetitionNumber_r16_e_n8 = 6,
	SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_repetitionNumber_r16_e_n16 = 7,
};

typedef enum SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_repetitionNumber_r16_e SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_repetitionNumber_r16_e;

struct uint8_t_SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_k0_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_repetitionNumber_r16_e_repetitionNumber_r16_Optional {
	bool d;
	SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_repetitionNumber_r16_e v;
};

struct SQN_NR_PDSCH_TimeDomainResourceAllocation_r16 {
	struct uint8_t_SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_k0_r16_Optional k0_r16;
	SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_mappingType_r16_e mappingType_r16;
	uint8_t startSymbolAndLength_r16;
	struct SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_repetitionNumber_r16_e_repetitionNumber_r16_Optional repetitionNumber_r16;
};

struct SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_SQN_NR_PDSCH_TimeDomainResourceAllocationList_r16_Dynamic {
	size_t d;
	struct SQN_NR_PDSCH_TimeDomainResourceAllocation_r16* v;
};

typedef struct SQN_NR_PDSCH_TimeDomainResourceAllocation_r16_SQN_NR_PDSCH_TimeDomainResourceAllocationList_r16_Dynamic SQN_NR_PDSCH_TimeDomainResourceAllocationList_r16;

enum SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationListDCI_1_2_r16_Sel {
	SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationListDCI_1_2_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationListDCI_1_2_r16_release = 1,
	SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationListDCI_1_2_r16_setup = 2,
};

union SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationListDCI_1_2_r16_Value {
	Null release;
	SQN_NR_PDSCH_TimeDomainResourceAllocationList_r16 setup;
};

struct SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationListDCI_1_2_r16 {
	enum SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationListDCI_1_2_r16_Sel d;
	union SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationListDCI_1_2_r16_Value v;
};

enum SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_staticBundling_r16_bundleSize_r16_e {
	SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_staticBundling_r16_bundleSize_r16_e_n4 = 0,
	SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_staticBundling_r16_bundleSize_r16_e_wideband = 1,
};

typedef enum SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_staticBundling_r16_bundleSize_r16_e SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_staticBundling_r16_bundleSize_r16_e;

struct SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_staticBundling_r16_bundleSize_r16_e_bundleSize_r16_Optional {
	bool d;
	SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_staticBundling_r16_bundleSize_r16_e v;
};

struct SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_staticBundling_r16 {
	struct SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_staticBundling_r16_bundleSize_r16_e_bundleSize_r16_Optional bundleSize_r16;
};

enum SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet1_r16_e {
	SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet1_r16_e_n4 = 0,
	SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet1_r16_e_wideband = 1,
	SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet1_r16_e_n2_wideband = 2,
	SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet1_r16_e_n4_wideband = 3,
};

typedef enum SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet1_r16_e SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet1_r16_e;

enum SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet2_r16_e {
	SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet2_r16_e_n4 = 0,
	SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet2_r16_e_wideband = 1,
};

typedef enum SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet2_r16_e SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet2_r16_e;

struct SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet1_r16_e_bundleSizeSet1_r16_Optional {
	bool d;
	SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet1_r16_e v;
};

struct SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet2_r16_e_bundleSizeSet2_r16_Optional {
	bool d;
	SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet2_r16_e v;
};

struct SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16 {
	struct SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet1_r16_e_bundleSizeSet1_r16_Optional bundleSizeSet1_r16;
	struct SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16_bundleSizeSet2_r16_e_bundleSizeSet2_r16_Optional bundleSizeSet2_r16;
};

enum SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_Sel {
	SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_UNBOUND_VALUE = 0,
	SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_staticBundling_r16 = 1,
	SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16 = 2,
};

union SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_Value {
	struct SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_staticBundling_r16 staticBundling_r16;
	struct SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_dynamicBundling_r16 dynamicBundling_r16;
};

struct SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16 {
	enum SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_Sel d;
	union SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_Value v;
};

enum SQN_NR_PDSCH_Config_priorityIndicatorDCI_1_2_r16_e {
	SQN_NR_PDSCH_Config_priorityIndicatorDCI_1_2_r16_e_enabled = 0,
};

typedef enum SQN_NR_PDSCH_Config_priorityIndicatorDCI_1_2_r16_e SQN_NR_PDSCH_Config_priorityIndicatorDCI_1_2_r16_e;

enum SQN_NR_PDSCH_Config_resourceAllocationType1GranularityDCI_1_2_r16_e {
	SQN_NR_PDSCH_Config_resourceAllocationType1GranularityDCI_1_2_r16_e_n2 = 0,
	SQN_NR_PDSCH_Config_resourceAllocationType1GranularityDCI_1_2_r16_e_n4 = 1,
	SQN_NR_PDSCH_Config_resourceAllocationType1GranularityDCI_1_2_r16_e_n8 = 2,
	SQN_NR_PDSCH_Config_resourceAllocationType1GranularityDCI_1_2_r16_e_n16 = 3,
};

typedef enum SQN_NR_PDSCH_Config_resourceAllocationType1GranularityDCI_1_2_r16_e SQN_NR_PDSCH_Config_resourceAllocationType1GranularityDCI_1_2_r16_e;

enum SQN_NR_PDSCH_Config_vrb_ToPRB_InterleaverDCI_1_2_r16_e {
	SQN_NR_PDSCH_Config_vrb_ToPRB_InterleaverDCI_1_2_r16_e_n2 = 0,
	SQN_NR_PDSCH_Config_vrb_ToPRB_InterleaverDCI_1_2_r16_e_n4 = 1,
};

typedef enum SQN_NR_PDSCH_Config_vrb_ToPRB_InterleaverDCI_1_2_r16_e SQN_NR_PDSCH_Config_vrb_ToPRB_InterleaverDCI_1_2_r16_e;

enum SQN_NR_PDSCH_Config_referenceOfSLIVDCI_1_2_r16_e {
	SQN_NR_PDSCH_Config_referenceOfSLIVDCI_1_2_r16_e_enabled = 0,
};

typedef enum SQN_NR_PDSCH_Config_referenceOfSLIVDCI_1_2_r16_e SQN_NR_PDSCH_Config_referenceOfSLIVDCI_1_2_r16_e;

enum SQN_NR_PDSCH_Config_resourceAllocationDCI_1_2_r16_e {
	SQN_NR_PDSCH_Config_resourceAllocationDCI_1_2_r16_e_resourceAllocationType0 = 0,
	SQN_NR_PDSCH_Config_resourceAllocationDCI_1_2_r16_e_resourceAllocationType1 = 1,
	SQN_NR_PDSCH_Config_resourceAllocationDCI_1_2_r16_e_dynamicSwitch = 2,
};

typedef enum SQN_NR_PDSCH_Config_resourceAllocationDCI_1_2_r16_e SQN_NR_PDSCH_Config_resourceAllocationDCI_1_2_r16_e;

enum SQN_NR_PDSCH_Config_priorityIndicatorDCI_1_1_r16_e {
	SQN_NR_PDSCH_Config_priorityIndicatorDCI_1_1_r16_e_enabled = 0,
};

typedef enum SQN_NR_PDSCH_Config_priorityIndicatorDCI_1_1_r16_e SQN_NR_PDSCH_Config_priorityIndicatorDCI_1_1_r16_e;

enum SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_r16_Sel {
	SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_r16_release = 1,
	SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_r16_setup = 2,
};

union SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_r16_Value {
	Null release;
	SQN_NR_PDSCH_TimeDomainResourceAllocationList_r16 setup;
};

struct SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_r16 {
	enum SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_r16_Sel d;
	union SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_r16_Value v;
};

enum SQN_NR_FDM_TDM_r16_repetitionScheme_r16_e {
	SQN_NR_FDM_TDM_r16_repetitionScheme_r16_e_fdmSchemeA = 0,
	SQN_NR_FDM_TDM_r16_repetitionScheme_r16_e_fdmSchemeB = 1,
	SQN_NR_FDM_TDM_r16_repetitionScheme_r16_e_tdmSchemeA = 2,
};

typedef enum SQN_NR_FDM_TDM_r16_repetitionScheme_r16_e SQN_NR_FDM_TDM_r16_repetitionScheme_r16_e;

struct uint8_t_SQN_NR_FDM_TDM_r16_startingSymbolOffsetK_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_FDM_TDM_r16 {
	SQN_NR_FDM_TDM_r16_repetitionScheme_r16_e repetitionScheme_r16;
	struct uint8_t_SQN_NR_FDM_TDM_r16_startingSymbolOffsetK_r16_Optional startingSymbolOffsetK_r16;
};

enum SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_fdm_TDM_r16_Sel {
	SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_fdm_TDM_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_fdm_TDM_r16_release = 1,
	SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_fdm_TDM_r16_setup = 2,
};

union SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_fdm_TDM_r16_Value {
	Null release;
	struct SQN_NR_FDM_TDM_r16 setup;
};

struct SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_fdm_TDM_r16 {
	enum SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_fdm_TDM_r16_Sel d;
	union SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_fdm_TDM_r16_Value v;
};

enum SQN_NR_SlotBased_r16_tciMapping_r16_e {
	SQN_NR_SlotBased_r16_tciMapping_r16_e_cyclicMapping = 0,
	SQN_NR_SlotBased_r16_tciMapping_r16_e_sequenticalMapping = 1,
};

typedef enum SQN_NR_SlotBased_r16_tciMapping_r16_e SQN_NR_SlotBased_r16_tciMapping_r16_e;

struct SQN_NR_SlotBased_r16 {
	SQN_NR_SlotBased_r16_tciMapping_r16_e tciMapping_r16;
	uint8_t sequenceOffsetforRV_r16;
};

enum SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_slotBased_r16_Sel {
	SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_slotBased_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_slotBased_r16_release = 1,
	SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_slotBased_r16_setup = 2,
};

union SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_slotBased_r16_Value {
	Null release;
	struct SQN_NR_SlotBased_r16 setup;
};

struct SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_slotBased_r16 {
	enum SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_slotBased_r16_Sel d;
	union SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_slotBased_r16_Value v;
};

enum SQN_NR_RepetitionSchemeConfig_r16_Sel {
	SQN_NR_RepetitionSchemeConfig_r16_UNBOUND_VALUE = 0,
	SQN_NR_RepetitionSchemeConfig_r16_fdm_TDM_r16 = 1,
	SQN_NR_RepetitionSchemeConfig_r16_slotBased_r16 = 2,
};

union SQN_NR_RepetitionSchemeConfig_r16_Value {
	struct SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_fdm_TDM_r16 fdm_TDM_r16;
	struct SQN_NR_SetupRelease_RepetitionSchemeConfig_r16_slotBased_r16 slotBased_r16;
};

struct SQN_NR_RepetitionSchemeConfig_r16 {
	enum SQN_NR_RepetitionSchemeConfig_r16_Sel d;
	union SQN_NR_RepetitionSchemeConfig_r16_Value v;
};

enum SQN_NR_SetupRelease_PDSCH_Config_repetitionSchemeConfig_r16_Sel {
	SQN_NR_SetupRelease_PDSCH_Config_repetitionSchemeConfig_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PDSCH_Config_repetitionSchemeConfig_r16_release = 1,
	SQN_NR_SetupRelease_PDSCH_Config_repetitionSchemeConfig_r16_setup = 2,
};

union SQN_NR_SetupRelease_PDSCH_Config_repetitionSchemeConfig_r16_Value {
	Null release;
	struct SQN_NR_RepetitionSchemeConfig_r16 setup;
};

struct SQN_NR_SetupRelease_PDSCH_Config_repetitionSchemeConfig_r16 {
	enum SQN_NR_SetupRelease_PDSCH_Config_repetitionSchemeConfig_r16_Sel d;
	union SQN_NR_SetupRelease_PDSCH_Config_repetitionSchemeConfig_r16_Value v;
};

struct uint16_t_SQN_NR_PDSCH_Config_dataScramblingIdentityPDSCH_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_SQN_NR_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA v;
};

struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_SQN_NR_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB v;
};

struct SQN_NR_PDSCH_Config_SQN_NR_TCI_State_tci_StatesToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_TCI_State* v;
};

struct SQN_NR_TCI_State_SQN_NR_PDSCH_Config_tci_StatesToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_PDSCH_Config_SQN_NR_TCI_State_tci_StatesToAddModList_Dynamic v;
};

struct SQN_NR_TCI_StateId_SQN_NR_PDSCH_Config_tci_StatesToReleaseList_Dynamic {
	size_t d;
	SQN_NR_TCI_StateId* v;
};

struct SQN_NR_TCI_StateId_SQN_NR_PDSCH_Config_tci_StatesToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_TCI_StateId_SQN_NR_PDSCH_Config_tci_StatesToReleaseList_Dynamic v;
};

struct SQN_NR_PDSCH_Config_vrb_ToPRB_Interleaver_e_vrb_ToPRB_Interleaver_Optional {
	bool d;
	SQN_NR_PDSCH_Config_vrb_ToPRB_Interleaver_e v;
};

struct SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_SQN_NR_PDSCH_Config_pdsch_TimeDomainAllocationList_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList v;
};

struct SQN_NR_PDSCH_Config_pdsch_AggregationFactor_e_pdsch_AggregationFactor_Optional {
	bool d;
	SQN_NR_PDSCH_Config_pdsch_AggregationFactor_e v;
};

struct SQN_NR_PDSCH_Config_SQN_NR_RateMatchPattern_rateMatchPatternToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_RateMatchPattern* v;
};

struct SQN_NR_RateMatchPattern_SQN_NR_PDSCH_Config_rateMatchPatternToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_PDSCH_Config_SQN_NR_RateMatchPattern_rateMatchPatternToAddModList_Dynamic v;
};

struct SQN_NR_RateMatchPatternId_SQN_NR_PDSCH_Config_rateMatchPatternToReleaseList_Dynamic {
	size_t d;
	SQN_NR_RateMatchPatternId* v;
};

struct SQN_NR_RateMatchPatternId_SQN_NR_PDSCH_Config_rateMatchPatternToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_RateMatchPatternId_SQN_NR_PDSCH_Config_rateMatchPatternToReleaseList_Dynamic v;
};

struct SQN_NR_RateMatchPatternGroup_SQN_NR_PDSCH_Config_rateMatchPatternGroup1_Optional {
	bool d;
	SQN_NR_RateMatchPatternGroup v;
};

struct SQN_NR_RateMatchPatternGroup_SQN_NR_PDSCH_Config_rateMatchPatternGroup2_Optional {
	bool d;
	SQN_NR_RateMatchPatternGroup v;
};

struct SQN_NR_PDSCH_Config_mcs_Table_e_mcs_Table_Optional {
	bool d;
	SQN_NR_PDSCH_Config_mcs_Table_e v;
};

struct SQN_NR_PDSCH_Config_maxNrofCodeWordsScheduledByDCI_e_maxNrofCodeWordsScheduledByDCI_Optional {
	bool d;
	SQN_NR_PDSCH_Config_maxNrofCodeWordsScheduledByDCI_e v;
};

struct SQN_NR_PDSCH_Config_SQN_NR_ZP_CSI_RS_Resource_zp_CSI_RS_ResourceToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_ZP_CSI_RS_Resource* v;
};

struct SQN_NR_ZP_CSI_RS_Resource_SQN_NR_PDSCH_Config_zp_CSI_RS_ResourceToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_PDSCH_Config_SQN_NR_ZP_CSI_RS_Resource_zp_CSI_RS_ResourceToAddModList_Dynamic v;
};

struct SQN_NR_ZP_CSI_RS_ResourceId_SQN_NR_PDSCH_Config_zp_CSI_RS_ResourceToReleaseList_Dynamic {
	size_t d;
	SQN_NR_ZP_CSI_RS_ResourceId* v;
};

struct SQN_NR_ZP_CSI_RS_ResourceId_SQN_NR_PDSCH_Config_zp_CSI_RS_ResourceToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_ZP_CSI_RS_ResourceId_SQN_NR_PDSCH_Config_zp_CSI_RS_ResourceToReleaseList_Dynamic v;
};

struct SQN_NR_PDSCH_Config_SQN_NR_ZP_CSI_RS_ResourceSet_aperiodic_ZP_CSI_RS_ResourceSetsToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_ZP_CSI_RS_ResourceSet* v;
};

struct SQN_NR_ZP_CSI_RS_ResourceSet_SQN_NR_PDSCH_Config_aperiodic_ZP_CSI_RS_ResourceSetsToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_PDSCH_Config_SQN_NR_ZP_CSI_RS_ResourceSet_aperiodic_ZP_CSI_RS_ResourceSetsToAddModList_Dynamic v;
};

struct SQN_NR_ZP_CSI_RS_ResourceSetId_SQN_NR_PDSCH_Config_aperiodic_ZP_CSI_RS_ResourceSetsToReleaseList_Dynamic {
	size_t d;
	SQN_NR_ZP_CSI_RS_ResourceSetId* v;
};

struct SQN_NR_ZP_CSI_RS_ResourceSetId_SQN_NR_PDSCH_Config_aperiodic_ZP_CSI_RS_ResourceSetsToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_ZP_CSI_RS_ResourceSetId_SQN_NR_PDSCH_Config_aperiodic_ZP_CSI_RS_ResourceSetsToReleaseList_Dynamic v;
};

struct SQN_NR_PDSCH_Config_SQN_NR_ZP_CSI_RS_ResourceSet_sp_ZP_CSI_RS_ResourceSetsToAddModList_Dynamic {
	size_t d;
	struct SQN_NR_ZP_CSI_RS_ResourceSet* v;
};

struct SQN_NR_ZP_CSI_RS_ResourceSet_SQN_NR_PDSCH_Config_sp_ZP_CSI_RS_ResourceSetsToAddModList_DynamicOptional {
	bool d;
	struct SQN_NR_PDSCH_Config_SQN_NR_ZP_CSI_RS_ResourceSet_sp_ZP_CSI_RS_ResourceSetsToAddModList_Dynamic v;
};

struct SQN_NR_ZP_CSI_RS_ResourceSetId_SQN_NR_PDSCH_Config_sp_ZP_CSI_RS_ResourceSetsToReleaseList_Dynamic {
	size_t d;
	SQN_NR_ZP_CSI_RS_ResourceSetId* v;
};

struct SQN_NR_ZP_CSI_RS_ResourceSetId_SQN_NR_PDSCH_Config_sp_ZP_CSI_RS_ResourceSetsToReleaseList_DynamicOptional {
	bool d;
	struct SQN_NR_ZP_CSI_RS_ResourceSetId_SQN_NR_PDSCH_Config_sp_ZP_CSI_RS_ResourceSetsToReleaseList_Dynamic v;
};

struct SQN_NR_SetupRelease_PDSCH_Config_p_ZP_CSI_RS_ResourceSet_SQN_NR_PDSCH_Config_p_ZP_CSI_RS_ResourceSet_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PDSCH_Config_p_ZP_CSI_RS_ResourceSet v;
};

struct SQN_NR_SetupRelease_PDSCH_Config_maxMIMO_Layers_r16_SQN_NR_PDSCH_Config_maxMIMO_Layers_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PDSCH_Config_maxMIMO_Layers_r16 v;
};

struct SQN_NR_SetupRelease_PDSCH_Config_minimumSchedulingOffsetK0_r16_SQN_NR_PDSCH_Config_minimumSchedulingOffsetK0_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PDSCH_Config_minimumSchedulingOffsetK0_r16 v;
};

struct SQN_NR_PDSCH_Config_antennaPortsFieldPresenceDCI_1_2_r16_e_antennaPortsFieldPresenceDCI_1_2_r16_Optional {
	bool d;
	SQN_NR_PDSCH_Config_antennaPortsFieldPresenceDCI_1_2_r16_e v;
};

struct SQN_NR_PDSCH_Config_SQN_NR_ZP_CSI_RS_ResourceSet_aperiodicZP_CSI_RS_ResourceSetsToAddModListDCI_1_2_r16_Dynamic {
	size_t d;
	struct SQN_NR_ZP_CSI_RS_ResourceSet* v;
};

struct SQN_NR_ZP_CSI_RS_ResourceSet_SQN_NR_PDSCH_Config_aperiodicZP_CSI_RS_ResourceSetsToAddModListDCI_1_2_r16_DynamicOptional {
	bool d;
	struct SQN_NR_PDSCH_Config_SQN_NR_ZP_CSI_RS_ResourceSet_aperiodicZP_CSI_RS_ResourceSetsToAddModListDCI_1_2_r16_Dynamic v;
};

struct SQN_NR_ZP_CSI_RS_ResourceSetId_SQN_NR_PDSCH_Config_aperiodicZP_CSI_RS_ResourceSetsToReleaseListDCI_1_2_r16_Dynamic {
	size_t d;
	SQN_NR_ZP_CSI_RS_ResourceSetId* v;
};

struct SQN_NR_ZP_CSI_RS_ResourceSetId_SQN_NR_PDSCH_Config_aperiodicZP_CSI_RS_ResourceSetsToReleaseListDCI_1_2_r16_DynamicOptional {
	bool d;
	struct SQN_NR_ZP_CSI_RS_ResourceSetId_SQN_NR_PDSCH_Config_aperiodicZP_CSI_RS_ResourceSetsToReleaseListDCI_1_2_r16_Dynamic v;
};

struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_DCI_1_2_r16_SQN_NR_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_DCI_1_2_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_DCI_1_2_r16 v;
};

struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_DCI_1_2_r16_SQN_NR_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_DCI_1_2_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_DCI_1_2_r16 v;
};

struct SQN_NR_PDSCH_Config_dmrs_SequenceInitializationDCI_1_2_r16_e_dmrs_SequenceInitializationDCI_1_2_r16_Optional {
	bool d;
	SQN_NR_PDSCH_Config_dmrs_SequenceInitializationDCI_1_2_r16_e v;
};

struct uint8_t_SQN_NR_PDSCH_Config_harq_ProcessNumberSizeDCI_1_2_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_PDSCH_Config_mcs_TableDCI_1_2_r16_e_mcs_TableDCI_1_2_r16_Optional {
	bool d;
	SQN_NR_PDSCH_Config_mcs_TableDCI_1_2_r16_e v;
};

struct uint8_t_SQN_NR_PDSCH_Config_numberOfBitsForRV_DCI_1_2_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationListDCI_1_2_r16_SQN_NR_PDSCH_Config_pdsch_TimeDomainAllocationListDCI_1_2_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationListDCI_1_2_r16 v;
};

struct SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_prb_BundlingTypeDCI_1_2_r16_Optional {
	bool d;
	struct SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16 v;
};

struct SQN_NR_PDSCH_Config_priorityIndicatorDCI_1_2_r16_e_priorityIndicatorDCI_1_2_r16_Optional {
	bool d;
	SQN_NR_PDSCH_Config_priorityIndicatorDCI_1_2_r16_e v;
};

struct SQN_NR_RateMatchPatternGroup_SQN_NR_PDSCH_Config_rateMatchPatternGroup1DCI_1_2_r16_Optional {
	bool d;
	SQN_NR_RateMatchPatternGroup v;
};

struct SQN_NR_RateMatchPatternGroup_SQN_NR_PDSCH_Config_rateMatchPatternGroup2DCI_1_2_r16_Optional {
	bool d;
	SQN_NR_RateMatchPatternGroup v;
};

struct SQN_NR_PDSCH_Config_resourceAllocationType1GranularityDCI_1_2_r16_e_resourceAllocationType1GranularityDCI_1_2_r16_Optional {
	bool d;
	SQN_NR_PDSCH_Config_resourceAllocationType1GranularityDCI_1_2_r16_e v;
};

struct SQN_NR_PDSCH_Config_vrb_ToPRB_InterleaverDCI_1_2_r16_e_vrb_ToPRB_InterleaverDCI_1_2_r16_Optional {
	bool d;
	SQN_NR_PDSCH_Config_vrb_ToPRB_InterleaverDCI_1_2_r16_e v;
};

struct SQN_NR_PDSCH_Config_referenceOfSLIVDCI_1_2_r16_e_referenceOfSLIVDCI_1_2_r16_Optional {
	bool d;
	SQN_NR_PDSCH_Config_referenceOfSLIVDCI_1_2_r16_e v;
};

struct SQN_NR_PDSCH_Config_resourceAllocationDCI_1_2_r16_e_resourceAllocationDCI_1_2_r16_Optional {
	bool d;
	SQN_NR_PDSCH_Config_resourceAllocationDCI_1_2_r16_e v;
};

struct SQN_NR_PDSCH_Config_priorityIndicatorDCI_1_1_r16_e_priorityIndicatorDCI_1_1_r16_Optional {
	bool d;
	SQN_NR_PDSCH_Config_priorityIndicatorDCI_1_1_r16_e v;
};

struct uint16_t_SQN_NR_PDSCH_Config_dataScramblingIdentityPDSCH2_r16_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_r16_SQN_NR_PDSCH_Config_pdsch_TimeDomainAllocationList_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_r16 v;
};

struct SQN_NR_SetupRelease_PDSCH_Config_repetitionSchemeConfig_r16_SQN_NR_PDSCH_Config_repetitionSchemeConfig_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PDSCH_Config_repetitionSchemeConfig_r16 v;
};

struct SQN_NR_PDSCH_Config {
	struct uint16_t_SQN_NR_PDSCH_Config_dataScramblingIdentityPDSCH_Optional dataScramblingIdentityPDSCH;
	struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_SQN_NR_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_Optional dmrs_DownlinkForPDSCH_MappingTypeA;
	struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_SQN_NR_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_Optional dmrs_DownlinkForPDSCH_MappingTypeB;
	struct SQN_NR_TCI_State_SQN_NR_PDSCH_Config_tci_StatesToAddModList_DynamicOptional tci_StatesToAddModList;
	struct SQN_NR_TCI_StateId_SQN_NR_PDSCH_Config_tci_StatesToReleaseList_DynamicOptional tci_StatesToReleaseList;
	struct SQN_NR_PDSCH_Config_vrb_ToPRB_Interleaver_e_vrb_ToPRB_Interleaver_Optional vrb_ToPRB_Interleaver;
	SQN_NR_PDSCH_Config_resourceAllocation_e resourceAllocation;
	struct SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_SQN_NR_PDSCH_Config_pdsch_TimeDomainAllocationList_Optional pdsch_TimeDomainAllocationList;
	struct SQN_NR_PDSCH_Config_pdsch_AggregationFactor_e_pdsch_AggregationFactor_Optional pdsch_AggregationFactor;
	struct SQN_NR_RateMatchPattern_SQN_NR_PDSCH_Config_rateMatchPatternToAddModList_DynamicOptional rateMatchPatternToAddModList;
	struct SQN_NR_RateMatchPatternId_SQN_NR_PDSCH_Config_rateMatchPatternToReleaseList_DynamicOptional rateMatchPatternToReleaseList;
	struct SQN_NR_RateMatchPatternGroup_SQN_NR_PDSCH_Config_rateMatchPatternGroup1_Optional rateMatchPatternGroup1;
	struct SQN_NR_RateMatchPatternGroup_SQN_NR_PDSCH_Config_rateMatchPatternGroup2_Optional rateMatchPatternGroup2;
	SQN_NR_PDSCH_Config_rbg_Size_e rbg_Size;
	struct SQN_NR_PDSCH_Config_mcs_Table_e_mcs_Table_Optional mcs_Table;
	struct SQN_NR_PDSCH_Config_maxNrofCodeWordsScheduledByDCI_e_maxNrofCodeWordsScheduledByDCI_Optional maxNrofCodeWordsScheduledByDCI;
	struct SQN_NR_PDSCH_Config_prb_BundlingType prb_BundlingType;
	struct SQN_NR_ZP_CSI_RS_Resource_SQN_NR_PDSCH_Config_zp_CSI_RS_ResourceToAddModList_DynamicOptional zp_CSI_RS_ResourceToAddModList;
	struct SQN_NR_ZP_CSI_RS_ResourceId_SQN_NR_PDSCH_Config_zp_CSI_RS_ResourceToReleaseList_DynamicOptional zp_CSI_RS_ResourceToReleaseList;
	struct SQN_NR_ZP_CSI_RS_ResourceSet_SQN_NR_PDSCH_Config_aperiodic_ZP_CSI_RS_ResourceSetsToAddModList_DynamicOptional aperiodic_ZP_CSI_RS_ResourceSetsToAddModList;
	struct SQN_NR_ZP_CSI_RS_ResourceSetId_SQN_NR_PDSCH_Config_aperiodic_ZP_CSI_RS_ResourceSetsToReleaseList_DynamicOptional aperiodic_ZP_CSI_RS_ResourceSetsToReleaseList;
	struct SQN_NR_ZP_CSI_RS_ResourceSet_SQN_NR_PDSCH_Config_sp_ZP_CSI_RS_ResourceSetsToAddModList_DynamicOptional sp_ZP_CSI_RS_ResourceSetsToAddModList;
	struct SQN_NR_ZP_CSI_RS_ResourceSetId_SQN_NR_PDSCH_Config_sp_ZP_CSI_RS_ResourceSetsToReleaseList_DynamicOptional sp_ZP_CSI_RS_ResourceSetsToReleaseList;
	struct SQN_NR_SetupRelease_PDSCH_Config_p_ZP_CSI_RS_ResourceSet_SQN_NR_PDSCH_Config_p_ZP_CSI_RS_ResourceSet_Optional p_ZP_CSI_RS_ResourceSet;
	struct SQN_NR_SetupRelease_PDSCH_Config_maxMIMO_Layers_r16_SQN_NR_PDSCH_Config_maxMIMO_Layers_r16_Optional maxMIMO_Layers_r16;
	struct SQN_NR_SetupRelease_PDSCH_Config_minimumSchedulingOffsetK0_r16_SQN_NR_PDSCH_Config_minimumSchedulingOffsetK0_r16_Optional minimumSchedulingOffsetK0_r16;
	struct SQN_NR_PDSCH_Config_antennaPortsFieldPresenceDCI_1_2_r16_e_antennaPortsFieldPresenceDCI_1_2_r16_Optional antennaPortsFieldPresenceDCI_1_2_r16;
	struct SQN_NR_ZP_CSI_RS_ResourceSet_SQN_NR_PDSCH_Config_aperiodicZP_CSI_RS_ResourceSetsToAddModListDCI_1_2_r16_DynamicOptional aperiodicZP_CSI_RS_ResourceSetsToAddModListDCI_1_2_r16;
	struct SQN_NR_ZP_CSI_RS_ResourceSetId_SQN_NR_PDSCH_Config_aperiodicZP_CSI_RS_ResourceSetsToReleaseListDCI_1_2_r16_DynamicOptional aperiodicZP_CSI_RS_ResourceSetsToReleaseListDCI_1_2_r16;
	struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_DCI_1_2_r16_SQN_NR_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeA_DCI_1_2_r16_Optional dmrs_DownlinkForPDSCH_MappingTypeA_DCI_1_2_r16;
	struct SQN_NR_SetupRelease_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_DCI_1_2_r16_SQN_NR_PDSCH_Config_dmrs_DownlinkForPDSCH_MappingTypeB_DCI_1_2_r16_Optional dmrs_DownlinkForPDSCH_MappingTypeB_DCI_1_2_r16;
	struct SQN_NR_PDSCH_Config_dmrs_SequenceInitializationDCI_1_2_r16_e_dmrs_SequenceInitializationDCI_1_2_r16_Optional dmrs_SequenceInitializationDCI_1_2_r16;
	struct uint8_t_SQN_NR_PDSCH_Config_harq_ProcessNumberSizeDCI_1_2_r16_Optional harq_ProcessNumberSizeDCI_1_2_r16;
	struct SQN_NR_PDSCH_Config_mcs_TableDCI_1_2_r16_e_mcs_TableDCI_1_2_r16_Optional mcs_TableDCI_1_2_r16;
	struct uint8_t_SQN_NR_PDSCH_Config_numberOfBitsForRV_DCI_1_2_r16_Optional numberOfBitsForRV_DCI_1_2_r16;
	struct SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationListDCI_1_2_r16_SQN_NR_PDSCH_Config_pdsch_TimeDomainAllocationListDCI_1_2_r16_Optional pdsch_TimeDomainAllocationListDCI_1_2_r16;
	struct SQN_NR_PDSCH_Config_prb_BundlingTypeDCI_1_2_r16_prb_BundlingTypeDCI_1_2_r16_Optional prb_BundlingTypeDCI_1_2_r16;
	struct SQN_NR_PDSCH_Config_priorityIndicatorDCI_1_2_r16_e_priorityIndicatorDCI_1_2_r16_Optional priorityIndicatorDCI_1_2_r16;
	struct SQN_NR_RateMatchPatternGroup_SQN_NR_PDSCH_Config_rateMatchPatternGroup1DCI_1_2_r16_Optional rateMatchPatternGroup1DCI_1_2_r16;
	struct SQN_NR_RateMatchPatternGroup_SQN_NR_PDSCH_Config_rateMatchPatternGroup2DCI_1_2_r16_Optional rateMatchPatternGroup2DCI_1_2_r16;
	struct SQN_NR_PDSCH_Config_resourceAllocationType1GranularityDCI_1_2_r16_e_resourceAllocationType1GranularityDCI_1_2_r16_Optional resourceAllocationType1GranularityDCI_1_2_r16;
	struct SQN_NR_PDSCH_Config_vrb_ToPRB_InterleaverDCI_1_2_r16_e_vrb_ToPRB_InterleaverDCI_1_2_r16_Optional vrb_ToPRB_InterleaverDCI_1_2_r16;
	struct SQN_NR_PDSCH_Config_referenceOfSLIVDCI_1_2_r16_e_referenceOfSLIVDCI_1_2_r16_Optional referenceOfSLIVDCI_1_2_r16;
	struct SQN_NR_PDSCH_Config_resourceAllocationDCI_1_2_r16_e_resourceAllocationDCI_1_2_r16_Optional resourceAllocationDCI_1_2_r16;
	struct SQN_NR_PDSCH_Config_priorityIndicatorDCI_1_1_r16_e_priorityIndicatorDCI_1_1_r16_Optional priorityIndicatorDCI_1_1_r16;
	struct uint16_t_SQN_NR_PDSCH_Config_dataScramblingIdentityPDSCH2_r16_Optional dataScramblingIdentityPDSCH2_r16;
	struct SQN_NR_SetupRelease_PDSCH_Config_pdsch_TimeDomainAllocationList_r16_SQN_NR_PDSCH_Config_pdsch_TimeDomainAllocationList_r16_Optional pdsch_TimeDomainAllocationList_r16;
	struct SQN_NR_SetupRelease_PDSCH_Config_repetitionSchemeConfig_r16_SQN_NR_PDSCH_Config_repetitionSchemeConfig_r16_Optional repetitionSchemeConfig_r16;
};

enum SQN_NR_PDSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e {
	SQN_NR_PDSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e_n2 = 0,
	SQN_NR_PDSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e_n4 = 1,
	SQN_NR_PDSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e_n6 = 2,
	SQN_NR_PDSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e_n8 = 3,
};

typedef enum SQN_NR_PDSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e SQN_NR_PDSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e;

struct SQN_NR_PDSCH_CodeBlockGroupTransmission {
	SQN_NR_PDSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e maxCodeBlockGroupsPerTransportBlock;
	bool codeBlockGroupFlushIndicator;
};

enum SQN_NR_SetupRelease_PDSCH_ServingCellConfig_codeBlockGroupTransmission_Sel {
	SQN_NR_SetupRelease_PDSCH_ServingCellConfig_codeBlockGroupTransmission_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PDSCH_ServingCellConfig_codeBlockGroupTransmission_release = 1,
	SQN_NR_SetupRelease_PDSCH_ServingCellConfig_codeBlockGroupTransmission_setup = 2,
};

union SQN_NR_SetupRelease_PDSCH_ServingCellConfig_codeBlockGroupTransmission_Value {
	Null release;
	struct SQN_NR_PDSCH_CodeBlockGroupTransmission setup;
};

struct SQN_NR_SetupRelease_PDSCH_ServingCellConfig_codeBlockGroupTransmission {
	enum SQN_NR_SetupRelease_PDSCH_ServingCellConfig_codeBlockGroupTransmission_Sel d;
	union SQN_NR_SetupRelease_PDSCH_ServingCellConfig_codeBlockGroupTransmission_Value v;
};

enum SQN_NR_PDSCH_ServingCellConfig_xOverhead_e {
	SQN_NR_PDSCH_ServingCellConfig_xOverhead_e_xOh6 = 0,
	SQN_NR_PDSCH_ServingCellConfig_xOverhead_e_xOh12 = 1,
	SQN_NR_PDSCH_ServingCellConfig_xOverhead_e_xOh18 = 2,
};

typedef enum SQN_NR_PDSCH_ServingCellConfig_xOverhead_e SQN_NR_PDSCH_ServingCellConfig_xOverhead_e;

enum SQN_NR_PDSCH_ServingCellConfig_nrofHARQ_ProcessesForPDSCH_e {
	SQN_NR_PDSCH_ServingCellConfig_nrofHARQ_ProcessesForPDSCH_e_n2 = 0,
	SQN_NR_PDSCH_ServingCellConfig_nrofHARQ_ProcessesForPDSCH_e_n4 = 1,
	SQN_NR_PDSCH_ServingCellConfig_nrofHARQ_ProcessesForPDSCH_e_n6 = 2,
	SQN_NR_PDSCH_ServingCellConfig_nrofHARQ_ProcessesForPDSCH_e_n10 = 3,
	SQN_NR_PDSCH_ServingCellConfig_nrofHARQ_ProcessesForPDSCH_e_n12 = 4,
	SQN_NR_PDSCH_ServingCellConfig_nrofHARQ_ProcessesForPDSCH_e_n16 = 5,
};

typedef enum SQN_NR_PDSCH_ServingCellConfig_nrofHARQ_ProcessesForPDSCH_e SQN_NR_PDSCH_ServingCellConfig_nrofHARQ_ProcessesForPDSCH_e;

struct SQN_NR_PDSCH_CodeBlockGroupTransmission_SQN_NR_PDSCH_CodeBlockGroupTransmissionList_r16_Dynamic {
	size_t d;
	struct SQN_NR_PDSCH_CodeBlockGroupTransmission* v;
};

typedef struct SQN_NR_PDSCH_CodeBlockGroupTransmission_SQN_NR_PDSCH_CodeBlockGroupTransmissionList_r16_Dynamic SQN_NR_PDSCH_CodeBlockGroupTransmissionList_r16;

enum SQN_NR_SetupRelease_PDSCH_ServingCellConfig_pdsch_CodeBlockGroupTransmissionList_r16_Sel {
	SQN_NR_SetupRelease_PDSCH_ServingCellConfig_pdsch_CodeBlockGroupTransmissionList_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PDSCH_ServingCellConfig_pdsch_CodeBlockGroupTransmissionList_r16_release = 1,
	SQN_NR_SetupRelease_PDSCH_ServingCellConfig_pdsch_CodeBlockGroupTransmissionList_r16_setup = 2,
};

union SQN_NR_SetupRelease_PDSCH_ServingCellConfig_pdsch_CodeBlockGroupTransmissionList_r16_Value {
	Null release;
	SQN_NR_PDSCH_CodeBlockGroupTransmissionList_r16 setup;
};

struct SQN_NR_SetupRelease_PDSCH_ServingCellConfig_pdsch_CodeBlockGroupTransmissionList_r16 {
	enum SQN_NR_SetupRelease_PDSCH_ServingCellConfig_pdsch_CodeBlockGroupTransmissionList_r16_Sel d;
	union SQN_NR_SetupRelease_PDSCH_ServingCellConfig_pdsch_CodeBlockGroupTransmissionList_r16_Value v;
};

struct SQN_NR_SetupRelease_PDSCH_ServingCellConfig_codeBlockGroupTransmission_SQN_NR_PDSCH_ServingCellConfig_codeBlockGroupTransmission_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PDSCH_ServingCellConfig_codeBlockGroupTransmission v;
};

struct SQN_NR_PDSCH_ServingCellConfig_xOverhead_e_xOverhead_Optional {
	bool d;
	SQN_NR_PDSCH_ServingCellConfig_xOverhead_e v;
};

struct SQN_NR_PDSCH_ServingCellConfig_nrofHARQ_ProcessesForPDSCH_e_nrofHARQ_ProcessesForPDSCH_Optional {
	bool d;
	SQN_NR_PDSCH_ServingCellConfig_nrofHARQ_ProcessesForPDSCH_e v;
};

struct SQN_NR_ServCellIndex_SQN_NR_PDSCH_ServingCellConfig_pucch_Cell_Optional {
	bool d;
	SQN_NR_ServCellIndex v;
};

struct uint8_t_SQN_NR_PDSCH_ServingCellConfig_maxMIMO_Layers_Optional {
	bool d;
	uint8_t v;
};

struct bool_SQN_NR_PDSCH_ServingCellConfig_processingType2Enabled_Optional {
	bool d;
	bool v;
};

struct SQN_NR_SetupRelease_PDSCH_ServingCellConfig_pdsch_CodeBlockGroupTransmissionList_r16_SQN_NR_PDSCH_ServingCellConfig_pdsch_CodeBlockGroupTransmissionList_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PDSCH_ServingCellConfig_pdsch_CodeBlockGroupTransmissionList_r16 v;
};

struct SQN_NR_PDSCH_ServingCellConfig {
	struct SQN_NR_SetupRelease_PDSCH_ServingCellConfig_codeBlockGroupTransmission_SQN_NR_PDSCH_ServingCellConfig_codeBlockGroupTransmission_Optional codeBlockGroupTransmission;
	struct SQN_NR_PDSCH_ServingCellConfig_xOverhead_e_xOverhead_Optional xOverhead;
	struct SQN_NR_PDSCH_ServingCellConfig_nrofHARQ_ProcessesForPDSCH_e_nrofHARQ_ProcessesForPDSCH_Optional nrofHARQ_ProcessesForPDSCH;
	struct SQN_NR_ServCellIndex_SQN_NR_PDSCH_ServingCellConfig_pucch_Cell_Optional pucch_Cell;
	struct uint8_t_SQN_NR_PDSCH_ServingCellConfig_maxMIMO_Layers_Optional maxMIMO_Layers;
	struct bool_SQN_NR_PDSCH_ServingCellConfig_processingType2Enabled_Optional processingType2Enabled;
	struct SQN_NR_SetupRelease_PDSCH_ServingCellConfig_pdsch_CodeBlockGroupTransmissionList_r16_SQN_NR_PDSCH_ServingCellConfig_pdsch_CodeBlockGroupTransmissionList_r16_Optional pdsch_CodeBlockGroupTransmissionList_r16;
};

enum SQN_NR_PUSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e {
	SQN_NR_PUSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e_n2 = 0,
	SQN_NR_PUSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e_n4 = 1,
	SQN_NR_PUSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e_n6 = 2,
	SQN_NR_PUSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e_n8 = 3,
};

typedef enum SQN_NR_PUSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e SQN_NR_PUSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e;

struct SQN_NR_PUSCH_CodeBlockGroupTransmission {
	SQN_NR_PUSCH_CodeBlockGroupTransmission_maxCodeBlockGroupsPerTransportBlock_e maxCodeBlockGroupsPerTransportBlock;
};

enum SQN_NR_SetupRelease_PUSCH_ServingCellConfig_codeBlockGroupTransmission_Sel {
	SQN_NR_SetupRelease_PUSCH_ServingCellConfig_codeBlockGroupTransmission_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_ServingCellConfig_codeBlockGroupTransmission_release = 1,
	SQN_NR_SetupRelease_PUSCH_ServingCellConfig_codeBlockGroupTransmission_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_ServingCellConfig_codeBlockGroupTransmission_Value {
	Null release;
	struct SQN_NR_PUSCH_CodeBlockGroupTransmission setup;
};

struct SQN_NR_SetupRelease_PUSCH_ServingCellConfig_codeBlockGroupTransmission {
	enum SQN_NR_SetupRelease_PUSCH_ServingCellConfig_codeBlockGroupTransmission_Sel d;
	union SQN_NR_SetupRelease_PUSCH_ServingCellConfig_codeBlockGroupTransmission_Value v;
};

enum SQN_NR_PUSCH_ServingCellConfig_rateMatching_e {
	SQN_NR_PUSCH_ServingCellConfig_rateMatching_e_limitedBufferRM = 0,
};

typedef enum SQN_NR_PUSCH_ServingCellConfig_rateMatching_e SQN_NR_PUSCH_ServingCellConfig_rateMatching_e;

enum SQN_NR_PUSCH_ServingCellConfig_xOverhead_e {
	SQN_NR_PUSCH_ServingCellConfig_xOverhead_e_xoh6 = 0,
	SQN_NR_PUSCH_ServingCellConfig_xOverhead_e_xoh12 = 1,
	SQN_NR_PUSCH_ServingCellConfig_xOverhead_e_xoh18 = 2,
};

typedef enum SQN_NR_PUSCH_ServingCellConfig_xOverhead_e SQN_NR_PUSCH_ServingCellConfig_xOverhead_e;

typedef uint8_t SQN_NR_MaxMIMO_LayersDCI_0_2_r16;

enum SQN_NR_SetupRelease_PUSCH_ServingCellConfig_maxMIMO_LayersDCI_0_2_r16_Sel {
	SQN_NR_SetupRelease_PUSCH_ServingCellConfig_maxMIMO_LayersDCI_0_2_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PUSCH_ServingCellConfig_maxMIMO_LayersDCI_0_2_r16_release = 1,
	SQN_NR_SetupRelease_PUSCH_ServingCellConfig_maxMIMO_LayersDCI_0_2_r16_setup = 2,
};

union SQN_NR_SetupRelease_PUSCH_ServingCellConfig_maxMIMO_LayersDCI_0_2_r16_Value {
	Null release;
	SQN_NR_MaxMIMO_LayersDCI_0_2_r16 setup;
};

struct SQN_NR_SetupRelease_PUSCH_ServingCellConfig_maxMIMO_LayersDCI_0_2_r16 {
	enum SQN_NR_SetupRelease_PUSCH_ServingCellConfig_maxMIMO_LayersDCI_0_2_r16_Sel d;
	union SQN_NR_SetupRelease_PUSCH_ServingCellConfig_maxMIMO_LayersDCI_0_2_r16_Value v;
};

struct SQN_NR_SetupRelease_PUSCH_ServingCellConfig_codeBlockGroupTransmission_SQN_NR_PUSCH_ServingCellConfig_codeBlockGroupTransmission_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_ServingCellConfig_codeBlockGroupTransmission v;
};

struct SQN_NR_PUSCH_ServingCellConfig_rateMatching_e_rateMatching_Optional {
	bool d;
	SQN_NR_PUSCH_ServingCellConfig_rateMatching_e v;
};

struct SQN_NR_PUSCH_ServingCellConfig_xOverhead_e_xOverhead_Optional {
	bool d;
	SQN_NR_PUSCH_ServingCellConfig_xOverhead_e v;
};

struct uint8_t_SQN_NR_PUSCH_ServingCellConfig_maxMIMO_Layers_Optional {
	bool d;
	uint8_t v;
};

struct bool_SQN_NR_PUSCH_ServingCellConfig_processingType2Enabled_Optional {
	bool d;
	bool v;
};

struct SQN_NR_SetupRelease_PUSCH_ServingCellConfig_maxMIMO_LayersDCI_0_2_r16_SQN_NR_PUSCH_ServingCellConfig_maxMIMO_LayersDCI_0_2_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PUSCH_ServingCellConfig_maxMIMO_LayersDCI_0_2_r16 v;
};

struct SQN_NR_PUSCH_ServingCellConfig {
	struct SQN_NR_SetupRelease_PUSCH_ServingCellConfig_codeBlockGroupTransmission_SQN_NR_PUSCH_ServingCellConfig_codeBlockGroupTransmission_Optional codeBlockGroupTransmission;
	struct SQN_NR_PUSCH_ServingCellConfig_rateMatching_e_rateMatching_Optional rateMatching;
	struct SQN_NR_PUSCH_ServingCellConfig_xOverhead_e_xOverhead_Optional xOverhead;
	struct uint8_t_SQN_NR_PUSCH_ServingCellConfig_maxMIMO_Layers_Optional maxMIMO_Layers;
	struct bool_SQN_NR_PUSCH_ServingCellConfig_processingType2Enabled_Optional processingType2Enabled;
	struct SQN_NR_SetupRelease_PUSCH_ServingCellConfig_maxMIMO_LayersDCI_0_2_r16_SQN_NR_PUSCH_ServingCellConfig_maxMIMO_LayersDCI_0_2_r16_Optional maxMIMO_LayersDCI_0_2_r16;
};

enum SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_e {
	SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_e_true = 0,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_e SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_e;

enum SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_e {
	SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_e_true = 0,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_e SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_e;

enum SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_e {
	SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_e_semiStatic = 0,
	SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_e_dynamic = 1,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_e SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_e;

typedef uint16_t SQN_NR_RNTI_Value;

enum SQN_NR_SetupRelease_PhysicalCellGroupConfig_cs_RNTI_Sel {
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_cs_RNTI_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_cs_RNTI_release = 1,
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_cs_RNTI_setup = 2,
};

union SQN_NR_SetupRelease_PhysicalCellGroupConfig_cs_RNTI_Value {
	Null release;
	SQN_NR_RNTI_Value setup;
};

struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_cs_RNTI {
	enum SQN_NR_SetupRelease_PhysicalCellGroupConfig_cs_RNTI_Sel d;
	union SQN_NR_SetupRelease_PhysicalCellGroupConfig_cs_RNTI_Value v;
};

enum SQN_NR_PhysicalCellGroupConfig_xScale_e {
	SQN_NR_PhysicalCellGroupConfig_xScale_e_dB0 = 0,
	SQN_NR_PhysicalCellGroupConfig_xScale_e_dB6 = 1,
	SQN_NR_PhysicalCellGroupConfig_xScale_e_spare2 = 2,
	SQN_NR_PhysicalCellGroupConfig_xScale_e_spare1 = 3,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_xScale_e SQN_NR_PhysicalCellGroupConfig_xScale_e;

typedef uint8_t SQN_NR_PDCCH_BlindDetection;

enum SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection_Sel {
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection_release = 1,
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection_setup = 2,
};

union SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection_Value {
	Null release;
	SQN_NR_PDCCH_BlindDetection setup;
};

struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection {
	enum SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection_Sel d;
	union SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection_Value v;
};

enum SQN_NR_DCP_Config_r16_ps_WakeUp_r16_e {
	SQN_NR_DCP_Config_r16_ps_WakeUp_r16_e_true = 0,
};

typedef enum SQN_NR_DCP_Config_r16_ps_WakeUp_r16_e SQN_NR_DCP_Config_r16_ps_WakeUp_r16_e;

enum SQN_NR_DCP_Config_r16_ps_TransmitPeriodicL1_RSRP_r16_e {
	SQN_NR_DCP_Config_r16_ps_TransmitPeriodicL1_RSRP_r16_e_true = 0,
};

typedef enum SQN_NR_DCP_Config_r16_ps_TransmitPeriodicL1_RSRP_r16_e SQN_NR_DCP_Config_r16_ps_TransmitPeriodicL1_RSRP_r16_e;

enum SQN_NR_DCP_Config_r16_ps_TransmitOtherPeriodicCSI_r16_e {
	SQN_NR_DCP_Config_r16_ps_TransmitOtherPeriodicCSI_r16_e_true = 0,
};

typedef enum SQN_NR_DCP_Config_r16_ps_TransmitOtherPeriodicCSI_r16_e SQN_NR_DCP_Config_r16_ps_TransmitOtherPeriodicCSI_r16_e;

struct SQN_NR_DCP_Config_r16_ps_WakeUp_r16_e_ps_WakeUp_r16_Optional {
	bool d;
	SQN_NR_DCP_Config_r16_ps_WakeUp_r16_e v;
};

struct SQN_NR_DCP_Config_r16_ps_TransmitPeriodicL1_RSRP_r16_e_ps_TransmitPeriodicL1_RSRP_r16_Optional {
	bool d;
	SQN_NR_DCP_Config_r16_ps_TransmitPeriodicL1_RSRP_r16_e v;
};

struct SQN_NR_DCP_Config_r16_ps_TransmitOtherPeriodicCSI_r16_e_ps_TransmitOtherPeriodicCSI_r16_Optional {
	bool d;
	SQN_NR_DCP_Config_r16_ps_TransmitOtherPeriodicCSI_r16_e v;
};

struct SQN_NR_DCP_Config_r16 {
	SQN_NR_RNTI_Value ps_RNTI_r16;
	uint8_t ps_Offset_r16;
	uint8_t sizeDCI_2_6_r16;
	uint8_t ps_PositionDCI_2_6_r16;
	struct SQN_NR_DCP_Config_r16_ps_WakeUp_r16_e_ps_WakeUp_r16_Optional ps_WakeUp_r16;
	struct SQN_NR_DCP_Config_r16_ps_TransmitPeriodicL1_RSRP_r16_e_ps_TransmitPeriodicL1_RSRP_r16_Optional ps_TransmitPeriodicL1_RSRP_r16;
	struct SQN_NR_DCP_Config_r16_ps_TransmitOtherPeriodicCSI_r16_e_ps_TransmitOtherPeriodicCSI_r16_Optional ps_TransmitOtherPeriodicCSI_r16;
};

enum SQN_NR_SetupRelease_PhysicalCellGroupConfig_dcp_Config_r16_Sel {
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_dcp_Config_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_dcp_Config_r16_release = 1,
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_dcp_Config_r16_setup = 2,
};

union SQN_NR_SetupRelease_PhysicalCellGroupConfig_dcp_Config_r16_Value {
	Null release;
	struct SQN_NR_DCP_Config_r16 setup;
};

struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_dcp_Config_r16 {
	enum SQN_NR_SetupRelease_PhysicalCellGroupConfig_dcp_Config_r16_Sel d;
	union SQN_NR_SetupRelease_PhysicalCellGroupConfig_dcp_Config_r16_Value v;
};

enum SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_secondaryPUCCHgroup_r16_e {
	SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_secondaryPUCCHgroup_r16_e_enabled = 0,
	SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_secondaryPUCCHgroup_r16_e_disabled = 1,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_secondaryPUCCHgroup_r16_e SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_secondaryPUCCHgroup_r16_e;

enum SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_secondaryPUCCHgroup_r16_e {
	SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_secondaryPUCCHgroup_r16_e_enabled = 0,
	SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_secondaryPUCCHgroup_r16_e_disabled = 1,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_secondaryPUCCHgroup_r16_e SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_secondaryPUCCHgroup_r16_e;

enum SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_secondaryPUCCHgroup_r16_e {
	SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_secondaryPUCCHgroup_r16_e_semiStatic = 0,
	SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_secondaryPUCCHgroup_r16_e_dynamic = 1,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_secondaryPUCCHgroup_r16_e SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_secondaryPUCCHgroup_r16_e;

enum SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR1_r16_e {
	SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR1_r16_e_semi_static_mode1 = 0,
	SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR1_r16_e_semi_static_mode2 = 1,
	SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR1_r16_e_dynamic = 2,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR1_r16_e SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR1_r16_e;

enum SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR2_r16_e {
	SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR2_r16_e_semi_static_mode1 = 0,
	SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR2_r16_e_semi_static_mode2 = 1,
	SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR2_r16_e_dynamic = 2,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR2_r16_e SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR2_r16_e;

enum SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_r16_e {
	SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_r16_e_enhancedDynamic = 0,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_r16_e SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_r16_e;

enum SQN_NR_PhysicalCellGroupConfig_nfi_TotalDAI_Included_r16_e {
	SQN_NR_PhysicalCellGroupConfig_nfi_TotalDAI_Included_r16_e_true = 0,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_nfi_TotalDAI_Included_r16_e SQN_NR_PhysicalCellGroupConfig_nfi_TotalDAI_Included_r16_e;

enum SQN_NR_PhysicalCellGroupConfig_ul_TotalDAI_Included_r16_e {
	SQN_NR_PhysicalCellGroupConfig_ul_TotalDAI_Included_r16_e_true = 0,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_ul_TotalDAI_Included_r16_e SQN_NR_PhysicalCellGroupConfig_ul_TotalDAI_Included_r16_e;

enum SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedback_r16_e {
	SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedback_r16_e_true = 0,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedback_r16_e SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedback_r16_e;

enum SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedbackNDI_r16_e {
	SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedbackNDI_r16_e_true = 0,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedbackNDI_r16_e SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedbackNDI_r16_e;

enum SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedbackCBG_r16_e {
	SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedbackCBG_r16_e_true = 0,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedbackCBG_r16_e SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedbackCBG_r16_e;

enum SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_0_2_r16_e {
	SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_0_2_r16_e_enabled = 0,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_0_2_r16_e SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_0_2_r16_e;

enum SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_1_2_r16_e {
	SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_1_2_r16_e_n1 = 0,
	SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_1_2_r16_e_n2 = 1,
	SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_1_2_r16_e_n4 = 2,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_1_2_r16_e SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_1_2_r16_e;

enum SQN_NR_PDSCH_HARQ_ACK_CodebookList_r16_e_e {
	SQN_NR_PDSCH_HARQ_ACK_CodebookList_r16_e_e_semiStatic = 0,
	SQN_NR_PDSCH_HARQ_ACK_CodebookList_r16_e_e_dynamic = 1,
};

typedef enum SQN_NR_PDSCH_HARQ_ACK_CodebookList_r16_e_e SQN_NR_PDSCH_HARQ_ACK_CodebookList_r16_e_e;

struct SQN_NR_PDSCH_HARQ_ACK_CodebookList_r16_e_e_SQN_NR_PDSCH_HARQ_ACK_CodebookList_r16_Dynamic {
	size_t d;
	SQN_NR_PDSCH_HARQ_ACK_CodebookList_r16_e_e* v;
};

typedef struct SQN_NR_PDSCH_HARQ_ACK_CodebookList_r16_e_e_SQN_NR_PDSCH_HARQ_ACK_CodebookList_r16_Dynamic SQN_NR_PDSCH_HARQ_ACK_CodebookList_r16;

enum SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdsch_HARQ_ACK_CodebookList_r16_Sel {
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdsch_HARQ_ACK_CodebookList_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdsch_HARQ_ACK_CodebookList_r16_release = 1,
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdsch_HARQ_ACK_CodebookList_r16_setup = 2,
};

union SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdsch_HARQ_ACK_CodebookList_r16_Value {
	Null release;
	SQN_NR_PDSCH_HARQ_ACK_CodebookList_r16 setup;
};

struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdsch_HARQ_ACK_CodebookList_r16 {
	enum SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdsch_HARQ_ACK_CodebookList_r16_Sel d;
	union SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdsch_HARQ_ACK_CodebookList_r16_Value v;
};

enum SQN_NR_PhysicalCellGroupConfig_ackNackFeedbackMode_r16_e {
	SQN_NR_PhysicalCellGroupConfig_ackNackFeedbackMode_r16_e_joint = 0,
	SQN_NR_PhysicalCellGroupConfig_ackNackFeedbackMode_r16_e_separate = 1,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_ackNackFeedbackMode_r16_e SQN_NR_PhysicalCellGroupConfig_ackNackFeedbackMode_r16_e;

struct SQN_NR_PDCCH_BlindDetectionCA_CombIndicator_r16 {
	uint8_t pdcch_BlindDetectionCA1_r16;
	uint8_t pdcch_BlindDetectionCA2_r16;
};

enum SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetectionCA_CombIndicator_r16_Sel {
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetectionCA_CombIndicator_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetectionCA_CombIndicator_r16_release = 1,
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetectionCA_CombIndicator_r16_setup = 2,
};

union SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetectionCA_CombIndicator_r16_Value {
	Null release;
	struct SQN_NR_PDCCH_BlindDetectionCA_CombIndicator_r16 setup;
};

struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetectionCA_CombIndicator_r16 {
	enum SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetectionCA_CombIndicator_r16_Sel d;
	union SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetectionCA_CombIndicator_r16_Value v;
};

typedef uint8_t SQN_NR_PDCCH_BlindDetection2_r16;

enum SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection2_r16_Sel {
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection2_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection2_r16_release = 1,
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection2_r16_setup = 2,
};

union SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection2_r16_Value {
	Null release;
	SQN_NR_PDCCH_BlindDetection2_r16 setup;
};

struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection2_r16 {
	enum SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection2_r16_Sel d;
	union SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection2_r16_Value v;
};

typedef uint8_t SQN_NR_PDCCH_BlindDetection3_r16;

enum SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection3_r16_Sel {
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection3_r16_UNBOUND_VALUE = 0,
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection3_r16_release = 1,
	SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection3_r16_setup = 2,
};

union SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection3_r16_Value {
	Null release;
	SQN_NR_PDCCH_BlindDetection3_r16 setup;
};

struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection3_r16 {
	enum SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection3_r16_Sel d;
	union SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection3_r16_Value v;
};

enum SQN_NR_PhysicalCellGroupConfig_bdFactorR_r16_e {
	SQN_NR_PhysicalCellGroupConfig_bdFactorR_r16_e_n1 = 0,
};

typedef enum SQN_NR_PhysicalCellGroupConfig_bdFactorR_r16_e SQN_NR_PhysicalCellGroupConfig_bdFactorR_r16_e;

struct SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_e_harq_ACK_SpatialBundlingPUCCH_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_e v;
};

struct SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_e_harq_ACK_SpatialBundlingPUSCH_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_e v;
};

struct SQN_NR_P_Max_SQN_NR_PhysicalCellGroupConfig_p_NR_FR1_Optional {
	bool d;
	SQN_NR_P_Max v;
};

struct SQN_NR_RNTI_Value_SQN_NR_PhysicalCellGroupConfig_tpc_SRS_RNTI_Optional {
	bool d;
	SQN_NR_RNTI_Value v;
};

struct SQN_NR_RNTI_Value_SQN_NR_PhysicalCellGroupConfig_tpc_PUCCH_RNTI_Optional {
	bool d;
	SQN_NR_RNTI_Value v;
};

struct SQN_NR_RNTI_Value_SQN_NR_PhysicalCellGroupConfig_tpc_PUSCH_RNTI_Optional {
	bool d;
	SQN_NR_RNTI_Value v;
};

struct SQN_NR_RNTI_Value_SQN_NR_PhysicalCellGroupConfig_sp_CSI_RNTI_Optional {
	bool d;
	SQN_NR_RNTI_Value v;
};

struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_cs_RNTI_SQN_NR_PhysicalCellGroupConfig_cs_RNTI_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_cs_RNTI v;
};

struct SQN_NR_RNTI_Value_SQN_NR_PhysicalCellGroupConfig_mcs_C_RNTI_Optional {
	bool d;
	SQN_NR_RNTI_Value v;
};

struct SQN_NR_P_Max_SQN_NR_PhysicalCellGroupConfig_p_UE_FR1_Optional {
	bool d;
	SQN_NR_P_Max v;
};

struct SQN_NR_PhysicalCellGroupConfig_xScale_e_xScale_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_xScale_e v;
};

struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection_SQN_NR_PhysicalCellGroupConfig_pdcch_BlindDetection_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection v;
};

struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_dcp_Config_r16_SQN_NR_PhysicalCellGroupConfig_dcp_Config_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_dcp_Config_r16 v;
};

struct SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_secondaryPUCCHgroup_r16_e_harq_ACK_SpatialBundlingPUCCH_secondaryPUCCHgroup_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_secondaryPUCCHgroup_r16_e v;
};

struct SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_secondaryPUCCHgroup_r16_e_harq_ACK_SpatialBundlingPUSCH_secondaryPUCCHgroup_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_secondaryPUCCHgroup_r16_e v;
};

struct SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_secondaryPUCCHgroup_r16_e_pdsch_HARQ_ACK_Codebook_secondaryPUCCHgroup_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_secondaryPUCCHgroup_r16_e v;
};

struct SQN_NR_P_Max_SQN_NR_PhysicalCellGroupConfig_p_NR_FR2_r16_Optional {
	bool d;
	SQN_NR_P_Max v;
};

struct SQN_NR_P_Max_SQN_NR_PhysicalCellGroupConfig_p_UE_FR2_r16_Optional {
	bool d;
	SQN_NR_P_Max v;
};

struct SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR1_r16_e_nrdc_PCmode_FR1_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR1_r16_e v;
};

struct SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR2_r16_e_nrdc_PCmode_FR2_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR2_r16_e v;
};

struct SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_r16_e_pdsch_HARQ_ACK_Codebook_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_r16_e v;
};

struct SQN_NR_PhysicalCellGroupConfig_nfi_TotalDAI_Included_r16_e_nfi_TotalDAI_Included_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_nfi_TotalDAI_Included_r16_e v;
};

struct SQN_NR_PhysicalCellGroupConfig_ul_TotalDAI_Included_r16_e_ul_TotalDAI_Included_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_ul_TotalDAI_Included_r16_e v;
};

struct SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedback_r16_e_pdsch_HARQ_ACK_OneShotFeedback_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedback_r16_e v;
};

struct SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedbackNDI_r16_e_pdsch_HARQ_ACK_OneShotFeedbackNDI_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedbackNDI_r16_e v;
};

struct SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedbackCBG_r16_e_pdsch_HARQ_ACK_OneShotFeedbackCBG_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedbackCBG_r16_e v;
};

struct SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_0_2_r16_e_downlinkAssignmentIndexDCI_0_2_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_0_2_r16_e v;
};

struct SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_1_2_r16_e_downlinkAssignmentIndexDCI_1_2_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_1_2_r16_e v;
};

struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdsch_HARQ_ACK_CodebookList_r16_SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_CodebookList_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdsch_HARQ_ACK_CodebookList_r16 v;
};

struct SQN_NR_PhysicalCellGroupConfig_ackNackFeedbackMode_r16_e_ackNackFeedbackMode_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_ackNackFeedbackMode_r16_e v;
};

struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetectionCA_CombIndicator_r16_SQN_NR_PhysicalCellGroupConfig_pdcch_BlindDetectionCA_CombIndicator_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetectionCA_CombIndicator_r16 v;
};

struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection2_r16_SQN_NR_PhysicalCellGroupConfig_pdcch_BlindDetection2_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection2_r16 v;
};

struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection3_r16_SQN_NR_PhysicalCellGroupConfig_pdcch_BlindDetection3_r16_Optional {
	bool d;
	struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection3_r16 v;
};

struct SQN_NR_PhysicalCellGroupConfig_bdFactorR_r16_e_bdFactorR_r16_Optional {
	bool d;
	SQN_NR_PhysicalCellGroupConfig_bdFactorR_r16_e v;
};

struct SQN_NR_PhysicalCellGroupConfig {
	struct SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_e_harq_ACK_SpatialBundlingPUCCH_Optional harq_ACK_SpatialBundlingPUCCH;
	struct SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_e_harq_ACK_SpatialBundlingPUSCH_Optional harq_ACK_SpatialBundlingPUSCH;
	struct SQN_NR_P_Max_SQN_NR_PhysicalCellGroupConfig_p_NR_FR1_Optional p_NR_FR1;
	SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_e pdsch_HARQ_ACK_Codebook;
	struct SQN_NR_RNTI_Value_SQN_NR_PhysicalCellGroupConfig_tpc_SRS_RNTI_Optional tpc_SRS_RNTI;
	struct SQN_NR_RNTI_Value_SQN_NR_PhysicalCellGroupConfig_tpc_PUCCH_RNTI_Optional tpc_PUCCH_RNTI;
	struct SQN_NR_RNTI_Value_SQN_NR_PhysicalCellGroupConfig_tpc_PUSCH_RNTI_Optional tpc_PUSCH_RNTI;
	struct SQN_NR_RNTI_Value_SQN_NR_PhysicalCellGroupConfig_sp_CSI_RNTI_Optional sp_CSI_RNTI;
	struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_cs_RNTI_SQN_NR_PhysicalCellGroupConfig_cs_RNTI_Optional cs_RNTI;
	struct SQN_NR_RNTI_Value_SQN_NR_PhysicalCellGroupConfig_mcs_C_RNTI_Optional mcs_C_RNTI;
	struct SQN_NR_P_Max_SQN_NR_PhysicalCellGroupConfig_p_UE_FR1_Optional p_UE_FR1;
	struct SQN_NR_PhysicalCellGroupConfig_xScale_e_xScale_Optional xScale;
	struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection_SQN_NR_PhysicalCellGroupConfig_pdcch_BlindDetection_Optional pdcch_BlindDetection;
	struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_dcp_Config_r16_SQN_NR_PhysicalCellGroupConfig_dcp_Config_r16_Optional dcp_Config_r16;
	struct SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUCCH_secondaryPUCCHgroup_r16_e_harq_ACK_SpatialBundlingPUCCH_secondaryPUCCHgroup_r16_Optional harq_ACK_SpatialBundlingPUCCH_secondaryPUCCHgroup_r16;
	struct SQN_NR_PhysicalCellGroupConfig_harq_ACK_SpatialBundlingPUSCH_secondaryPUCCHgroup_r16_e_harq_ACK_SpatialBundlingPUSCH_secondaryPUCCHgroup_r16_Optional harq_ACK_SpatialBundlingPUSCH_secondaryPUCCHgroup_r16;
	struct SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_secondaryPUCCHgroup_r16_e_pdsch_HARQ_ACK_Codebook_secondaryPUCCHgroup_r16_Optional pdsch_HARQ_ACK_Codebook_secondaryPUCCHgroup_r16;
	struct SQN_NR_P_Max_SQN_NR_PhysicalCellGroupConfig_p_NR_FR2_r16_Optional p_NR_FR2_r16;
	struct SQN_NR_P_Max_SQN_NR_PhysicalCellGroupConfig_p_UE_FR2_r16_Optional p_UE_FR2_r16;
	struct SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR1_r16_e_nrdc_PCmode_FR1_r16_Optional nrdc_PCmode_FR1_r16;
	struct SQN_NR_PhysicalCellGroupConfig_nrdc_PCmode_FR2_r16_e_nrdc_PCmode_FR2_r16_Optional nrdc_PCmode_FR2_r16;
	struct SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_Codebook_r16_e_pdsch_HARQ_ACK_Codebook_r16_Optional pdsch_HARQ_ACK_Codebook_r16;
	struct SQN_NR_PhysicalCellGroupConfig_nfi_TotalDAI_Included_r16_e_nfi_TotalDAI_Included_r16_Optional nfi_TotalDAI_Included_r16;
	struct SQN_NR_PhysicalCellGroupConfig_ul_TotalDAI_Included_r16_e_ul_TotalDAI_Included_r16_Optional ul_TotalDAI_Included_r16;
	struct SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedback_r16_e_pdsch_HARQ_ACK_OneShotFeedback_r16_Optional pdsch_HARQ_ACK_OneShotFeedback_r16;
	struct SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedbackNDI_r16_e_pdsch_HARQ_ACK_OneShotFeedbackNDI_r16_Optional pdsch_HARQ_ACK_OneShotFeedbackNDI_r16;
	struct SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_OneShotFeedbackCBG_r16_e_pdsch_HARQ_ACK_OneShotFeedbackCBG_r16_Optional pdsch_HARQ_ACK_OneShotFeedbackCBG_r16;
	struct SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_0_2_r16_e_downlinkAssignmentIndexDCI_0_2_r16_Optional downlinkAssignmentIndexDCI_0_2_r16;
	struct SQN_NR_PhysicalCellGroupConfig_downlinkAssignmentIndexDCI_1_2_r16_e_downlinkAssignmentIndexDCI_1_2_r16_Optional downlinkAssignmentIndexDCI_1_2_r16;
	struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdsch_HARQ_ACK_CodebookList_r16_SQN_NR_PhysicalCellGroupConfig_pdsch_HARQ_ACK_CodebookList_r16_Optional pdsch_HARQ_ACK_CodebookList_r16;
	struct SQN_NR_PhysicalCellGroupConfig_ackNackFeedbackMode_r16_e_ackNackFeedbackMode_r16_Optional ackNackFeedbackMode_r16;
	struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetectionCA_CombIndicator_r16_SQN_NR_PhysicalCellGroupConfig_pdcch_BlindDetectionCA_CombIndicator_r16_Optional pdcch_BlindDetectionCA_CombIndicator_r16;
	struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection2_r16_SQN_NR_PhysicalCellGroupConfig_pdcch_BlindDetection2_r16_Optional pdcch_BlindDetection2_r16;
	struct SQN_NR_SetupRelease_PhysicalCellGroupConfig_pdcch_BlindDetection3_r16_SQN_NR_PhysicalCellGroupConfig_pdcch_BlindDetection3_r16_Optional pdcch_BlindDetection3_r16;
	struct SQN_NR_PhysicalCellGroupConfig_bdFactorR_r16_e_bdFactorR_r16_Optional bdFactorR_r16;
};

enum SQN_NR_CFRA_occasions_ssb_perRACH_Occasion_e {
	SQN_NR_CFRA_occasions_ssb_perRACH_Occasion_e_oneEighth = 0,
	SQN_NR_CFRA_occasions_ssb_perRACH_Occasion_e_oneFourth = 1,
	SQN_NR_CFRA_occasions_ssb_perRACH_Occasion_e_oneHalf = 2,
	SQN_NR_CFRA_occasions_ssb_perRACH_Occasion_e_one = 3,
	SQN_NR_CFRA_occasions_ssb_perRACH_Occasion_e_two = 4,
	SQN_NR_CFRA_occasions_ssb_perRACH_Occasion_e_four = 5,
	SQN_NR_CFRA_occasions_ssb_perRACH_Occasion_e_eight = 6,
	SQN_NR_CFRA_occasions_ssb_perRACH_Occasion_e_sixteen = 7,
};

typedef enum SQN_NR_CFRA_occasions_ssb_perRACH_Occasion_e SQN_NR_CFRA_occasions_ssb_perRACH_Occasion_e;

struct SQN_NR_CFRA_occasions_ssb_perRACH_Occasion_e_ssb_perRACH_Occasion_Optional {
	bool d;
	SQN_NR_CFRA_occasions_ssb_perRACH_Occasion_e v;
};

struct SQN_NR_CFRA_occasions {
	struct SQN_NR_RACH_ConfigGeneric rach_ConfigGeneric;
	struct SQN_NR_CFRA_occasions_ssb_perRACH_Occasion_e_ssb_perRACH_Occasion_Optional ssb_perRACH_Occasion;
};

struct uint16_t_SQN_NR_CFRA_SSB_Resource_msgA_PUSCH_resource_Index_r16_Optional {
	bool d;
	uint16_t v;
};

struct SQN_NR_CFRA_SSB_Resource {
	SQN_NR_SSB_Index ssb;
	uint8_t ra_PreambleIndex;
	struct uint16_t_SQN_NR_CFRA_SSB_Resource_msgA_PUSCH_resource_Index_r16_Optional msgA_PUSCH_resource_Index_r16;
};

struct SQN_NR_CFRA_SSB_Resource_SQN_NR_CFRA_resources_ssb_ssb_ResourceList_Dynamic {
	size_t d;
	struct SQN_NR_CFRA_SSB_Resource* v;
};

struct SQN_NR_CFRA_resources_ssb {
	struct SQN_NR_CFRA_SSB_Resource_SQN_NR_CFRA_resources_ssb_ssb_ResourceList_Dynamic ssb_ResourceList;
	uint8_t ra_ssb_OccasionMaskIndex;
};

typedef uint8_t SQN_NR_CSI_RS_Index;

struct uint16_t_SQN_NR_CFRA_CSIRS_Resource_ra_OccasionList_Dynamic {
	size_t d;
	uint16_t* v;
};

struct SQN_NR_CFRA_CSIRS_Resource {
	SQN_NR_CSI_RS_Index csi_RS;
	struct uint16_t_SQN_NR_CFRA_CSIRS_Resource_ra_OccasionList_Dynamic ra_OccasionList;
	uint8_t ra_PreambleIndex;
};

struct SQN_NR_CFRA_CSIRS_Resource_SQN_NR_CFRA_resources_csirs_csirs_ResourceList_Dynamic {
	size_t d;
	struct SQN_NR_CFRA_CSIRS_Resource* v;
};

struct SQN_NR_CFRA_resources_csirs {
	struct SQN_NR_CFRA_CSIRS_Resource_SQN_NR_CFRA_resources_csirs_csirs_ResourceList_Dynamic csirs_ResourceList;
	SQN_NR_RSRP_Range rsrp_ThresholdCSI_RS;
};

enum SQN_NR_CFRA_resources_Sel {
	SQN_NR_CFRA_resources_UNBOUND_VALUE = 0,
	SQN_NR_CFRA_resources_ssb = 1,
	SQN_NR_CFRA_resources_csirs = 2,
};

union SQN_NR_CFRA_resources_Value {
	struct SQN_NR_CFRA_resources_ssb ssb;
	struct SQN_NR_CFRA_resources_csirs csirs;
};

struct SQN_NR_CFRA_resources {
	enum SQN_NR_CFRA_resources_Sel d;
	union SQN_NR_CFRA_resources_Value v;
};

struct SQN_NR_CFRA_occasions_occasions_Optional {
	bool d;
	struct SQN_NR_CFRA_occasions v;
};

struct uint8_t_SQN_NR_CFRA_totalNumberOfRA_Preambles_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_CFRA {
	struct SQN_NR_CFRA_occasions_occasions_Optional occasions;
	struct SQN_NR_CFRA_resources resources;
	struct uint8_t_SQN_NR_CFRA_totalNumberOfRA_Preambles_Optional totalNumberOfRA_Preambles;
};

enum SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16_ssb_PerRACH_OccasionTwoStepRA_r16_e {
	SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16_ssb_PerRACH_OccasionTwoStepRA_r16_e_oneEighth = 0,
	SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16_ssb_PerRACH_OccasionTwoStepRA_r16_e_oneFourth = 1,
	SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16_ssb_PerRACH_OccasionTwoStepRA_r16_e_oneHalf = 2,
	SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16_ssb_PerRACH_OccasionTwoStepRA_r16_e_one = 3,
	SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16_ssb_PerRACH_OccasionTwoStepRA_r16_e_two = 4,
	SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16_ssb_PerRACH_OccasionTwoStepRA_r16_e_four = 5,
	SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16_ssb_PerRACH_OccasionTwoStepRA_r16_e_eight = 6,
	SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16_ssb_PerRACH_OccasionTwoStepRA_r16_e_sixteen = 7,
};

typedef enum SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16_ssb_PerRACH_OccasionTwoStepRA_r16_e SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16_ssb_PerRACH_OccasionTwoStepRA_r16_e;

struct SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16 {
	struct SQN_NR_RACH_ConfigGenericTwoStepRA_r16 rach_ConfigGenericTwoStepRA_r16;
	SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16_ssb_PerRACH_OccasionTwoStepRA_r16_e ssb_PerRACH_OccasionTwoStepRA_r16;
};

enum SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e {
	SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e_n1 = 0,
	SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e_n2 = 1,
	SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e_n4 = 2,
	SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e_n6 = 3,
	SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e_n8 = 4,
	SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e_n10 = 5,
	SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e_n20 = 6,
	SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e_n50 = 7,
	SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e_n100 = 8,
	SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e_n200 = 9,
};

typedef enum SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e;

struct SQN_NR_CFRA_SSB_Resource_SQN_NR_CFRA_TwoStep_r16_resourcesTwoStep_r16_ssb_ResourceList_Dynamic {
	size_t d;
	struct SQN_NR_CFRA_SSB_Resource* v;
};

struct SQN_NR_CFRA_TwoStep_r16_resourcesTwoStep_r16 {
	struct SQN_NR_CFRA_SSB_Resource_SQN_NR_CFRA_TwoStep_r16_resourcesTwoStep_r16_ssb_ResourceList_Dynamic ssb_ResourceList;
	uint8_t ra_ssb_OccasionMaskIndex;
};

struct SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16_occasionsTwoStepRA_r16_Optional {
	bool d;
	struct SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16 v;
};

struct SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e_msgA_TransMax_r16_Optional {
	bool d;
	SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e v;
};

struct SQN_NR_CFRA_TwoStep_r16 {
	struct SQN_NR_CFRA_TwoStep_r16_occasionsTwoStepRA_r16_occasionsTwoStepRA_r16_Optional occasionsTwoStepRA_r16;
	struct SQN_NR_MsgA_PUSCH_Resource_r16 msgA_CFRA_PUSCH_r16;
	struct SQN_NR_CFRA_TwoStep_r16_msgA_TransMax_r16_e_msgA_TransMax_r16_Optional msgA_TransMax_r16;
	struct SQN_NR_CFRA_TwoStep_r16_resourcesTwoStep_r16 resourcesTwoStep_r16;
};

struct SQN_NR_CFRA_SQN_NR_RACH_ConfigDedicated_cfra_Optional {
	bool d;
	struct SQN_NR_CFRA v;
};

struct SQN_NR_RA_Prioritization_SQN_NR_RACH_ConfigDedicated_ra_Prioritization_Optional {
	bool d;
	struct SQN_NR_RA_Prioritization v;
};

struct SQN_NR_RA_Prioritization_SQN_NR_RACH_ConfigDedicated_ra_PrioritizationTwoStep_r16_Optional {
	bool d;
	struct SQN_NR_RA_Prioritization v;
};

struct SQN_NR_CFRA_TwoStep_r16_SQN_NR_RACH_ConfigDedicated_cfra_TwoStep_r16_Optional {
	bool d;
	struct SQN_NR_CFRA_TwoStep_r16 v;
};

struct SQN_NR_RACH_ConfigDedicated {
	struct SQN_NR_CFRA_SQN_NR_RACH_ConfigDedicated_cfra_Optional cfra;
	struct SQN_NR_RA_Prioritization_SQN_NR_RACH_ConfigDedicated_ra_Prioritization_Optional ra_Prioritization;
	struct SQN_NR_RA_Prioritization_SQN_NR_RACH_ConfigDedicated_ra_PrioritizationTwoStep_r16_Optional ra_PrioritizationTwoStep_r16;
	struct SQN_NR_CFRA_TwoStep_r16_SQN_NR_RACH_ConfigDedicated_cfra_TwoStep_r16_Optional cfra_TwoStep_r16;
};

enum SQN_NR_RateMatchPatternLTE_CRS_carrierBandwidthDL_e {
	SQN_NR_RateMatchPatternLTE_CRS_carrierBandwidthDL_e_n6 = 0,
	SQN_NR_RateMatchPatternLTE_CRS_carrierBandwidthDL_e_n15 = 1,
	SQN_NR_RateMatchPatternLTE_CRS_carrierBandwidthDL_e_n25 = 2,
	SQN_NR_RateMatchPatternLTE_CRS_carrierBandwidthDL_e_n50 = 3,
	SQN_NR_RateMatchPatternLTE_CRS_carrierBandwidthDL_e_n75 = 4,
	SQN_NR_RateMatchPatternLTE_CRS_carrierBandwidthDL_e_n100 = 5,
	SQN_NR_RateMatchPatternLTE_CRS_carrierBandwidthDL_e_spare2 = 6,
	SQN_NR_RateMatchPatternLTE_CRS_carrierBandwidthDL_e_spare1 = 7,
};

typedef enum SQN_NR_RateMatchPatternLTE_CRS_carrierBandwidthDL_e SQN_NR_RateMatchPatternLTE_CRS_carrierBandwidthDL_e;

enum SQN_NR_EUTRA_MBSFN_SubframeConfig_radioframeAllocationPeriod_e {
	SQN_NR_EUTRA_MBSFN_SubframeConfig_radioframeAllocationPeriod_e_n1 = 0,
	SQN_NR_EUTRA_MBSFN_SubframeConfig_radioframeAllocationPeriod_e_n2 = 1,
	SQN_NR_EUTRA_MBSFN_SubframeConfig_radioframeAllocationPeriod_e_n4 = 2,
	SQN_NR_EUTRA_MBSFN_SubframeConfig_radioframeAllocationPeriod_e_n8 = 3,
	SQN_NR_EUTRA_MBSFN_SubframeConfig_radioframeAllocationPeriod_e_n16 = 4,
	SQN_NR_EUTRA_MBSFN_SubframeConfig_radioframeAllocationPeriod_e_n32 = 5,
};

typedef enum SQN_NR_EUTRA_MBSFN_SubframeConfig_radioframeAllocationPeriod_e SQN_NR_EUTRA_MBSFN_SubframeConfig_radioframeAllocationPeriod_e;

enum SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation1_Sel {
	SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation1_UNBOUND_VALUE = 0,
	SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation1_oneFrame = 1,
	SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation1_fourFrames = 2,
};

union SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation1_Value {
	B6 oneFrame;
	B24 fourFrames;
};

struct SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation1 {
	enum SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation1_Sel d;
	union SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation1_Value v;
};

enum SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation2_Sel {
	SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation2_UNBOUND_VALUE = 0,
	SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation2_oneFrame = 1,
	SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation2_fourFrames = 2,
};

union SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation2_Value {
	B2 oneFrame;
	B8 fourFrames;
};

struct SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation2 {
	enum SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation2_Sel d;
	union SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation2_Value v;
};

struct SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation2_subframeAllocation2_Optional {
	bool d;
	struct SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation2 v;
};

struct SQN_NR_EUTRA_MBSFN_SubframeConfig {
	SQN_NR_EUTRA_MBSFN_SubframeConfig_radioframeAllocationPeriod_e radioframeAllocationPeriod;
	uint8_t radioframeAllocationOffset;
	struct SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation1 subframeAllocation1;
	struct SQN_NR_EUTRA_MBSFN_SubframeConfig_subframeAllocation2_subframeAllocation2_Optional subframeAllocation2;
};

struct SQN_NR_EUTRA_MBSFN_SubframeConfig_SQN_NR_EUTRA_MBSFN_SubframeConfigList_Dynamic {
	size_t d;
	struct SQN_NR_EUTRA_MBSFN_SubframeConfig* v;
};

typedef struct SQN_NR_EUTRA_MBSFN_SubframeConfig_SQN_NR_EUTRA_MBSFN_SubframeConfigList_Dynamic SQN_NR_EUTRA_MBSFN_SubframeConfigList;

enum SQN_NR_RateMatchPatternLTE_CRS_nrofCRS_Ports_e {
	SQN_NR_RateMatchPatternLTE_CRS_nrofCRS_Ports_e_n1 = 0,
	SQN_NR_RateMatchPatternLTE_CRS_nrofCRS_Ports_e_n2 = 1,
	SQN_NR_RateMatchPatternLTE_CRS_nrofCRS_Ports_e_n4 = 2,
};

typedef enum SQN_NR_RateMatchPatternLTE_CRS_nrofCRS_Ports_e SQN_NR_RateMatchPatternLTE_CRS_nrofCRS_Ports_e;

enum SQN_NR_RateMatchPatternLTE_CRS_v_Shift_e {
	SQN_NR_RateMatchPatternLTE_CRS_v_Shift_e_n0 = 0,
	SQN_NR_RateMatchPatternLTE_CRS_v_Shift_e_n1 = 1,
	SQN_NR_RateMatchPatternLTE_CRS_v_Shift_e_n2 = 2,
	SQN_NR_RateMatchPatternLTE_CRS_v_Shift_e_n3 = 3,
	SQN_NR_RateMatchPatternLTE_CRS_v_Shift_e_n4 = 4,
	SQN_NR_RateMatchPatternLTE_CRS_v_Shift_e_n5 = 5,
};

typedef enum SQN_NR_RateMatchPatternLTE_CRS_v_Shift_e SQN_NR_RateMatchPatternLTE_CRS_v_Shift_e;

struct SQN_NR_EUTRA_MBSFN_SubframeConfigList_SQN_NR_RateMatchPatternLTE_CRS_mbsfn_SubframeConfigList_Optional {
	bool d;
	SQN_NR_EUTRA_MBSFN_SubframeConfigList v;
};

struct SQN_NR_RateMatchPatternLTE_CRS {
	uint16_t carrierFreqDL;
	SQN_NR_RateMatchPatternLTE_CRS_carrierBandwidthDL_e carrierBandwidthDL;
	struct SQN_NR_EUTRA_MBSFN_SubframeConfigList_SQN_NR_RateMatchPatternLTE_CRS_mbsfn_SubframeConfigList_Optional mbsfn_SubframeConfigList;
	SQN_NR_RateMatchPatternLTE_CRS_nrofCRS_Ports_e nrofCRS_Ports;
	SQN_NR_RateMatchPatternLTE_CRS_v_Shift_e v_Shift;
};

enum SQN_NR_SPS_Config_periodicity_e {
	SQN_NR_SPS_Config_periodicity_e_ms10 = 0,
	SQN_NR_SPS_Config_periodicity_e_ms20 = 1,
	SQN_NR_SPS_Config_periodicity_e_ms32 = 2,
	SQN_NR_SPS_Config_periodicity_e_ms40 = 3,
	SQN_NR_SPS_Config_periodicity_e_ms64 = 4,
	SQN_NR_SPS_Config_periodicity_e_ms80 = 5,
	SQN_NR_SPS_Config_periodicity_e_ms128 = 6,
	SQN_NR_SPS_Config_periodicity_e_ms160 = 7,
	SQN_NR_SPS_Config_periodicity_e_ms320 = 8,
	SQN_NR_SPS_Config_periodicity_e_ms640 = 9,
	SQN_NR_SPS_Config_periodicity_e_spare6 = 10,
	SQN_NR_SPS_Config_periodicity_e_spare5 = 11,
	SQN_NR_SPS_Config_periodicity_e_spare4 = 12,
	SQN_NR_SPS_Config_periodicity_e_spare3 = 13,
	SQN_NR_SPS_Config_periodicity_e_spare2 = 14,
	SQN_NR_SPS_Config_periodicity_e_spare1 = 15,
};

typedef enum SQN_NR_SPS_Config_periodicity_e SQN_NR_SPS_Config_periodicity_e;

enum SQN_NR_SPS_Config_mcs_Table_e {
	SQN_NR_SPS_Config_mcs_Table_e_qam64LowSE = 0,
};

typedef enum SQN_NR_SPS_Config_mcs_Table_e SQN_NR_SPS_Config_mcs_Table_e;

typedef uint8_t SQN_NR_SPS_ConfigIndex_r16;

enum SQN_NR_SPS_Config_pdsch_AggregationFactor_r16_e {
	SQN_NR_SPS_Config_pdsch_AggregationFactor_r16_e_n1 = 0,
	SQN_NR_SPS_Config_pdsch_AggregationFactor_r16_e_n2 = 1,
	SQN_NR_SPS_Config_pdsch_AggregationFactor_r16_e_n4 = 2,
	SQN_NR_SPS_Config_pdsch_AggregationFactor_r16_e_n8 = 3,
};

typedef enum SQN_NR_SPS_Config_pdsch_AggregationFactor_r16_e SQN_NR_SPS_Config_pdsch_AggregationFactor_r16_e;

struct SQN_NR_PUCCH_ResourceId_SQN_NR_SPS_Config_n1PUCCH_AN_Optional {
	bool d;
	SQN_NR_PUCCH_ResourceId v;
};

struct SQN_NR_SPS_Config_mcs_Table_e_mcs_Table_Optional {
	bool d;
	SQN_NR_SPS_Config_mcs_Table_e v;
};

struct SQN_NR_SPS_ConfigIndex_r16_SQN_NR_SPS_Config_sps_ConfigIndex_r16_Optional {
	bool d;
	SQN_NR_SPS_ConfigIndex_r16 v;
};

struct uint8_t_SQN_NR_SPS_Config_harq_ProcID_Offset_r16_Optional {
	bool d;
	uint8_t v;
};

struct uint16_t_SQN_NR_SPS_Config_periodicityExt_r16_Optional {
	bool d;
	uint16_t v;
};

struct uint8_t_SQN_NR_SPS_Config_harq_CodebookID_r16_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_SPS_Config_pdsch_AggregationFactor_r16_e_pdsch_AggregationFactor_r16_Optional {
	bool d;
	SQN_NR_SPS_Config_pdsch_AggregationFactor_r16_e v;
};

struct SQN_NR_SPS_Config {
	SQN_NR_SPS_Config_periodicity_e periodicity;
	uint8_t nrofHARQ_Processes;
	struct SQN_NR_PUCCH_ResourceId_SQN_NR_SPS_Config_n1PUCCH_AN_Optional n1PUCCH_AN;
	struct SQN_NR_SPS_Config_mcs_Table_e_mcs_Table_Optional mcs_Table;
	struct SQN_NR_SPS_ConfigIndex_r16_SQN_NR_SPS_Config_sps_ConfigIndex_r16_Optional sps_ConfigIndex_r16;
	struct uint8_t_SQN_NR_SPS_Config_harq_ProcID_Offset_r16_Optional harq_ProcID_Offset_r16;
	struct uint16_t_SQN_NR_SPS_Config_periodicityExt_r16_Optional periodicityExt_r16;
	struct uint8_t_SQN_NR_SPS_Config_harq_CodebookID_r16_Optional harq_CodebookID_r16;
	struct SQN_NR_SPS_Config_pdsch_AggregationFactor_r16_e_pdsch_AggregationFactor_r16_Optional pdsch_AggregationFactor_r16;
};

typedef uint16_t SQN_NR_ScramblingId;

enum SQN_NR_ServingCellConfigCommon_ssb_PositionsInBurst_Sel {
	SQN_NR_ServingCellConfigCommon_ssb_PositionsInBurst_UNBOUND_VALUE = 0,
	SQN_NR_ServingCellConfigCommon_ssb_PositionsInBurst_shortBitmap = 1,
	SQN_NR_ServingCellConfigCommon_ssb_PositionsInBurst_mediumBitmap = 2,
	SQN_NR_ServingCellConfigCommon_ssb_PositionsInBurst_longBitmap = 3,
};

union SQN_NR_ServingCellConfigCommon_ssb_PositionsInBurst_Value {
	B4 shortBitmap;
	B8 mediumBitmap;
	B64 longBitmap;
};

struct SQN_NR_ServingCellConfigCommon_ssb_PositionsInBurst {
	enum SQN_NR_ServingCellConfigCommon_ssb_PositionsInBurst_Sel d;
	union SQN_NR_ServingCellConfigCommon_ssb_PositionsInBurst_Value v;
};

enum SQN_NR_ServingCellConfigCommon_ssb_periodicityServingCell_e {
	SQN_NR_ServingCellConfigCommon_ssb_periodicityServingCell_e_ms5 = 0,
	SQN_NR_ServingCellConfigCommon_ssb_periodicityServingCell_e_ms10 = 1,
	SQN_NR_ServingCellConfigCommon_ssb_periodicityServingCell_e_ms20 = 2,
	SQN_NR_ServingCellConfigCommon_ssb_periodicityServingCell_e_ms40 = 3,
	SQN_NR_ServingCellConfigCommon_ssb_periodicityServingCell_e_ms80 = 4,
	SQN_NR_ServingCellConfigCommon_ssb_periodicityServingCell_e_ms160 = 5,
	SQN_NR_ServingCellConfigCommon_ssb_periodicityServingCell_e_spare2 = 6,
	SQN_NR_ServingCellConfigCommon_ssb_periodicityServingCell_e_spare1 = 7,
};

typedef enum SQN_NR_ServingCellConfigCommon_ssb_periodicityServingCell_e SQN_NR_ServingCellConfigCommon_ssb_periodicityServingCell_e;

typedef uint16_t SQN_NR_TDD_UL_DL_SlotIndex;

struct uint8_t_SQN_NR_TDD_UL_DL_SlotConfig_symbols_explicit__nrofDownlinkSymbols_Optional {
	bool d;
	uint8_t v;
};

struct uint8_t_SQN_NR_TDD_UL_DL_SlotConfig_symbols_explicit__nrofUplinkSymbols_Optional {
	bool d;
	uint8_t v;
};

struct SQN_NR_TDD_UL_DL_SlotConfig_symbols_explicit_ {
	struct uint8_t_SQN_NR_TDD_UL_DL_SlotConfig_symbols_explicit__nrofDownlinkSymbols_Optional nrofDownlinkSymbols;
	struct uint8_t_SQN_NR_TDD_UL_DL_SlotConfig_symbols_explicit__nrofUplinkSymbols_Optional nrofUplinkSymbols;
};

enum SQN_NR_TDD_UL_DL_SlotConfig_symbols_Sel {
	SQN_NR_TDD_UL_DL_SlotConfig_symbols_UNBOUND_VALUE = 0,
	SQN_NR_TDD_UL_DL_SlotConfig_symbols_allDownlink = 1,
	SQN_NR_TDD_UL_DL_SlotConfig_symbols_allUplink = 2,
	SQN_NR_TDD_UL_DL_SlotConfig_symbols_explicit_ = 3,
};

union SQN_NR_TDD_UL_DL_SlotConfig_symbols_Value {
	Null allDownlink;
	Null allUplink;
	struct SQN_NR_TDD_UL_DL_SlotConfig_symbols_explicit_ explicit_;
};

struct SQN_NR_TDD_UL_DL_SlotConfig_symbols {
	enum SQN_NR_TDD_UL_DL_SlotConfig_symbols_Sel d;
	union SQN_NR_TDD_UL_DL_SlotConfig_symbols_Value v;
};

struct SQN_NR_TDD_UL_DL_SlotConfig {
	SQN_NR_TDD_UL_DL_SlotIndex slotIndex;
	struct SQN_NR_TDD_UL_DL_SlotConfig_symbols symbols;
};

enum SQN_NR_T_PollRetransmit_e {
	SQN_NR_T_PollRetransmit_e_ms5 = 0,
	SQN_NR_T_PollRetransmit_e_ms10 = 1,
	SQN_NR_T_PollRetransmit_e_ms15 = 2,
	SQN_NR_T_PollRetransmit_e_ms20 = 3,
	SQN_NR_T_PollRetransmit_e_ms25 = 4,
	SQN_NR_T_PollRetransmit_e_ms30 = 5,
	SQN_NR_T_PollRetransmit_e_ms35 = 6,
	SQN_NR_T_PollRetransmit_e_ms40 = 7,
	SQN_NR_T_PollRetransmit_e_ms45 = 8,
	SQN_NR_T_PollRetransmit_e_ms50 = 9,
	SQN_NR_T_PollRetransmit_e_ms55 = 10,
	SQN_NR_T_PollRetransmit_e_ms60 = 11,
	SQN_NR_T_PollRetransmit_e_ms65 = 12,
	SQN_NR_T_PollRetransmit_e_ms70 = 13,
	SQN_NR_T_PollRetransmit_e_ms75 = 14,
	SQN_NR_T_PollRetransmit_e_ms80 = 15,
	SQN_NR_T_PollRetransmit_e_ms85 = 16,
	SQN_NR_T_PollRetransmit_e_ms90 = 17,
	SQN_NR_T_PollRetransmit_e_ms95 = 18,
	SQN_NR_T_PollRetransmit_e_ms100 = 19,
	SQN_NR_T_PollRetransmit_e_ms105 = 20,
	SQN_NR_T_PollRetransmit_e_ms110 = 21,
	SQN_NR_T_PollRetransmit_e_ms115 = 22,
	SQN_NR_T_PollRetransmit_e_ms120 = 23,
	SQN_NR_T_PollRetransmit_e_ms125 = 24,
	SQN_NR_T_PollRetransmit_e_ms130 = 25,
	SQN_NR_T_PollRetransmit_e_ms135 = 26,
	SQN_NR_T_PollRetransmit_e_ms140 = 27,
	SQN_NR_T_PollRetransmit_e_ms145 = 28,
	SQN_NR_T_PollRetransmit_e_ms150 = 29,
	SQN_NR_T_PollRetransmit_e_ms155 = 30,
	SQN_NR_T_PollRetransmit_e_ms160 = 31,
	SQN_NR_T_PollRetransmit_e_ms165 = 32,
	SQN_NR_T_PollRetransmit_e_ms170 = 33,
	SQN_NR_T_PollRetransmit_e_ms175 = 34,
	SQN_NR_T_PollRetransmit_e_ms180 = 35,
	SQN_NR_T_PollRetransmit_e_ms185 = 36,
	SQN_NR_T_PollRetransmit_e_ms190 = 37,
	SQN_NR_T_PollRetransmit_e_ms195 = 38,
	SQN_NR_T_PollRetransmit_e_ms200 = 39,
	SQN_NR_T_PollRetransmit_e_ms205 = 40,
	SQN_NR_T_PollRetransmit_e_ms210 = 41,
	SQN_NR_T_PollRetransmit_e_ms215 = 42,
	SQN_NR_T_PollRetransmit_e_ms220 = 43,
	SQN_NR_T_PollRetransmit_e_ms225 = 44,
	SQN_NR_T_PollRetransmit_e_ms230 = 45,
	SQN_NR_T_PollRetransmit_e_ms235 = 46,
	SQN_NR_T_PollRetransmit_e_ms240 = 47,
	SQN_NR_T_PollRetransmit_e_ms245 = 48,
	SQN_NR_T_PollRetransmit_e_ms250 = 49,
	SQN_NR_T_PollRetransmit_e_ms300 = 50,
	SQN_NR_T_PollRetransmit_e_ms350 = 51,
	SQN_NR_T_PollRetransmit_e_ms400 = 52,
	SQN_NR_T_PollRetransmit_e_ms450 = 53,
	SQN_NR_T_PollRetransmit_e_ms500 = 54,
	SQN_NR_T_PollRetransmit_e_ms800 = 55,
	SQN_NR_T_PollRetransmit_e_ms1000 = 56,
	SQN_NR_T_PollRetransmit_e_ms2000 = 57,
	SQN_NR_T_PollRetransmit_e_ms4000 = 58,
	SQN_NR_T_PollRetransmit_e_ms1_v1610 = 59,
	SQN_NR_T_PollRetransmit_e_ms2_v1610 = 60,
	SQN_NR_T_PollRetransmit_e_ms3_v1610 = 61,
	SQN_NR_T_PollRetransmit_e_ms4_v1610 = 62,
	SQN_NR_T_PollRetransmit_e_spare1 = 63,
};

typedef enum SQN_NR_T_PollRetransmit_e SQN_NR_T_PollRetransmit_e;

enum SQN_NR_PollPDU_e {
	SQN_NR_PollPDU_e_p4 = 0,
	SQN_NR_PollPDU_e_p8 = 1,
	SQN_NR_PollPDU_e_p16 = 2,
	SQN_NR_PollPDU_e_p32 = 3,
	SQN_NR_PollPDU_e_p64 = 4,
	SQN_NR_PollPDU_e_p128 = 5,
	SQN_NR_PollPDU_e_p256 = 6,
	SQN_NR_PollPDU_e_p512 = 7,
	SQN_NR_PollPDU_e_p1024 = 8,
	SQN_NR_PollPDU_e_p2048 = 9,
	SQN_NR_PollPDU_e_p4096 = 10,
	SQN_NR_PollPDU_e_p6144 = 11,
	SQN_NR_PollPDU_e_p8192 = 12,
	SQN_NR_PollPDU_e_p12288 = 13,
	SQN_NR_PollPDU_e_p16384 = 14,
	SQN_NR_PollPDU_e_p20480 = 15,
	SQN_NR_PollPDU_e_p24576 = 16,
	SQN_NR_PollPDU_e_p28672 = 17,
	SQN_NR_PollPDU_e_p32768 = 18,
	SQN_NR_PollPDU_e_p40960 = 19,
	SQN_NR_PollPDU_e_p49152 = 20,
	SQN_NR_PollPDU_e_p57344 = 21,
	SQN_NR_PollPDU_e_p65536 = 22,
	SQN_NR_PollPDU_e_infinity = 23,
	SQN_NR_PollPDU_e_spare8 = 24,
	SQN_NR_PollPDU_e_spare7 = 25,
	SQN_NR_PollPDU_e_spare6 = 26,
	SQN_NR_PollPDU_e_spare5 = 27,
	SQN_NR_PollPDU_e_spare4 = 28,
	SQN_NR_PollPDU_e_spare3 = 29,
	SQN_NR_PollPDU_e_spare2 = 30,
	SQN_NR_PollPDU_e_spare1 = 31,
};

typedef enum SQN_NR_PollPDU_e SQN_NR_PollPDU_e;

enum SQN_NR_PollByte_e {
	SQN_NR_PollByte_e_kB1 = 0,
	SQN_NR_PollByte_e_kB2 = 1,
	SQN_NR_PollByte_e_kB5 = 2,
	SQN_NR_PollByte_e_kB8 = 3,
	SQN_NR_PollByte_e_kB10 = 4,
	SQN_NR_PollByte_e_kB15 = 5,
	SQN_NR_PollByte_e_kB25 = 6,
	SQN_NR_PollByte_e_kB50 = 7,
	SQN_NR_PollByte_e_kB75 = 8,
	SQN_NR_PollByte_e_kB100 = 9,
	SQN_NR_PollByte_e_kB125 = 10,
	SQN_NR_PollByte_e_kB250 = 11,
	SQN_NR_PollByte_e_kB375 = 12,
	SQN_NR_PollByte_e_kB500 = 13,
	SQN_NR_PollByte_e_kB750 = 14,
	SQN_NR_PollByte_e_kB1000 = 15,
	SQN_NR_PollByte_e_kB1250 = 16,
	SQN_NR_PollByte_e_kB1500 = 17,
	SQN_NR_PollByte_e_kB2000 = 18,
	SQN_NR_PollByte_e_kB3000 = 19,
	SQN_NR_PollByte_e_kB4000 = 20,
	SQN_NR_PollByte_e_kB4500 = 21,
	SQN_NR_PollByte_e_kB5000 = 22,
	SQN_NR_PollByte_e_kB5500 = 23,
	SQN_NR_PollByte_e_kB6000 = 24,
	SQN_NR_PollByte_e_kB6500 = 25,
	SQN_NR_PollByte_e_kB7000 = 26,
	SQN_NR_PollByte_e_kB7500 = 27,
	SQN_NR_PollByte_e_mB8 = 28,
	SQN_NR_PollByte_e_mB9 = 29,
	SQN_NR_PollByte_e_mB10 = 30,
	SQN_NR_PollByte_e_mB11 = 31,
	SQN_NR_PollByte_e_mB12 = 32,
	SQN_NR_PollByte_e_mB13 = 33,
	SQN_NR_PollByte_e_mB14 = 34,
	SQN_NR_PollByte_e_mB15 = 35,
	SQN_NR_PollByte_e_mB16 = 36,
	SQN_NR_PollByte_e_mB17 = 37,
	SQN_NR_PollByte_e_mB18 = 38,
	SQN_NR_PollByte_e_mB20 = 39,
	SQN_NR_PollByte_e_mB25 = 40,
	SQN_NR_PollByte_e_mB30 = 41,
	SQN_NR_PollByte_e_mB40 = 42,
	SQN_NR_PollByte_e_infinity = 43,
	SQN_NR_PollByte_e_spare20 = 44,
	SQN_NR_PollByte_e_spare19 = 45,
	SQN_NR_PollByte_e_spare18 = 46,
	SQN_NR_PollByte_e_spare17 = 47,
	SQN_NR_PollByte_e_spare16 = 48,
	SQN_NR_PollByte_e_spare15 = 49,
	SQN_NR_PollByte_e_spare14 = 50,
	SQN_NR_PollByte_e_spare13 = 51,
	SQN_NR_PollByte_e_spare12 = 52,
	SQN_NR_PollByte_e_spare11 = 53,
	SQN_NR_PollByte_e_spare10 = 54,
	SQN_NR_PollByte_e_spare9 = 55,
	SQN_NR_PollByte_e_spare8 = 56,
	SQN_NR_PollByte_e_spare7 = 57,
	SQN_NR_PollByte_e_spare6 = 58,
	SQN_NR_PollByte_e_spare5 = 59,
	SQN_NR_PollByte_e_spare4 = 60,
	SQN_NR_PollByte_e_spare3 = 61,
	SQN_NR_PollByte_e_spare2 = 62,
	SQN_NR_PollByte_e_spare1 = 63,
};

typedef enum SQN_NR_PollByte_e SQN_NR_PollByte_e;

enum SQN_NR_UL_AM_RLC_maxRetxThreshold_e {
	SQN_NR_UL_AM_RLC_maxRetxThreshold_e_t1 = 0,
	SQN_NR_UL_AM_RLC_maxRetxThreshold_e_t2 = 1,
	SQN_NR_UL_AM_RLC_maxRetxThreshold_e_t3 = 2,
	SQN_NR_UL_AM_RLC_maxRetxThreshold_e_t4 = 3,
	SQN_NR_UL_AM_RLC_maxRetxThreshold_e_t6 = 4,
	SQN_NR_UL_AM_RLC_maxRetxThreshold_e_t8 = 5,
	SQN_NR_UL_AM_RLC_maxRetxThreshold_e_t16 = 6,
	SQN_NR_UL_AM_RLC_maxRetxThreshold_e_t32 = 7,
};

typedef enum SQN_NR_UL_AM_RLC_maxRetxThreshold_e SQN_NR_UL_AM_RLC_maxRetxThreshold_e;

struct SQN_NR_SN_FieldLengthAM_e_SQN_NR_UL_AM_RLC_sn_FieldLength_Optional {
	bool d;
	SQN_NR_SN_FieldLengthAM_e v;
};

struct SQN_NR_UL_AM_RLC {
	struct SQN_NR_SN_FieldLengthAM_e_SQN_NR_UL_AM_RLC_sn_FieldLength_Optional sn_FieldLength;
	SQN_NR_T_PollRetransmit_e t_PollRetransmit;
	SQN_NR_PollPDU_e pollPDU;
	SQN_NR_PollByte_e pollByte;
	SQN_NR_UL_AM_RLC_maxRetxThreshold_e maxRetxThreshold;
};

struct SQN_NR_SN_FieldLengthUM_e_SQN_NR_UL_UM_RLC_sn_FieldLength_Optional {
	bool d;
	SQN_NR_SN_FieldLengthUM_e v;
};

struct SQN_NR_UL_UM_RLC {
	struct SQN_NR_SN_FieldLengthUM_e_SQN_NR_UL_UM_RLC_sn_FieldLength_Optional sn_FieldLength;
};

SIDL_END_C_INTERFACE
