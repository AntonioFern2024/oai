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
#include "SidlASN1.h"
#include "SidlASN1Base.h"
#include "SidlBase.h"
#include "SidlCommon.h"
#include "SidlCommonBase.h"
#include "SidlNrASN1.h"
#include "SidlNrCommon.h"

SIDL_BEGIN_C_INTERFACE

enum NR_CellCapability_Type {
	NR_CellCapability_broadcastOnlyCell = 0,
	NR_CellCapability_minimumUplinkCell = 1,
	NR_CellCapability_fullCell = 2,
};

typedef enum NR_CellCapability_Type NR_CellCapability_Type;

enum NR_CellInitialCAConfig_Type {
	NR_CellInitialCAConfig_SpCell = 0,
	NR_CellInitialCAConfig_Scell_Active = 1,
	NR_CellInitialCAConfig_Scell_Inactive = 2,
	NR_CellInitialCAConfig_Scell_None = 3,
};

typedef enum NR_CellInitialCAConfig_Type NR_CellInitialCAConfig_Type;

struct NR_SS_StaticCellResourceConfig_Type {
	NR_CellCapability_Type CellCapability;
	NR_CellInitialCAConfig_Type CarrierAggregation;
};

SIDL_END_C_INTERFACE
