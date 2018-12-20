/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AxleSplitHEVv5_sfun.h"
#include "c2_AxleSplitHEVv5.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "AxleSplitHEVv5_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_Running                  ((uint8_T)1U)
#define c2_IN_Stall                    ((uint8_T)2U)
#define c2_IN_Start                    ((uint8_T)3U)
#define c2_IN_Starter                  ((uint8_T)1U)
#define c2_IN_StarterAndTQI            ((uint8_T)2U)
#define c2_IN_Force_tracking           ((uint8_T)1U)
#define c2_IN_Idle                     ((uint8_T)2U)
#define c2_IN_IdleTransOn              ((uint8_T)3U)
#define c2_IN_InjectionInhibed         ((uint8_T)1U)
#define c2_IN_Standard_force_tracking  ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void initialize_params_c2_AxleSplitHEVv5
  (SFc2_AxleSplitHEVv5InstanceStruct *chartInstance);
static void enable_c2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void disable_c2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_AxleSplitHEVv5
  (SFc2_AxleSplitHEVv5InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_AxleSplitHEVv5
  (SFc2_AxleSplitHEVv5InstanceStruct *chartInstance);
static void set_sim_state_c2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_st);
static void c2_set_sim_state_side_effects_c2_AxleSplitHEVv5
  (SFc2_AxleSplitHEVv5InstanceStruct *chartInstance);
static void finalize_c2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void sf_c2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void c2_chartstep_c2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void initSimStructsc2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void registerMessagesc2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct *
  chartInstance);
static void c2_exit_internal_Start(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void c2_Running(SFc2_AxleSplitHEVv5InstanceStruct *chartInstance);
static void c2_exit_internal_Force_tracking(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static int32_T c2_emlrt_marshallIn(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_b_emlrt_marshallIn(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_b_tp_Start, const char_T *c2_identifier);
static uint8_T c2_c_emlrt_marshallIn(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_d_emlrt_marshallIn(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_FA_ICE_STATE, const char_T *c2_identifier);
static real_T c2_e_emlrt_marshallIn(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_emlrt_marshallIn(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier);
static const mxArray *c2_g_emlrt_marshallIn(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  real_T *c2_FA_ICE_STATE;
  c2_FA_ICE_STATE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_is_Running = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_tp_Running = 0U;
  chartInstance->c2_is_Force_tracking = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_tp_Force_tracking = 0U;
  chartInstance->c2_tp_InjectionInhibed = 0U;
  chartInstance->c2_tp_Standard_force_tracking = 0U;
  chartInstance->c2_tp_Idle = 0U;
  chartInstance->c2_tp_IdleTransOn = 0U;
  chartInstance->c2_tp_Stall = 0U;
  chartInstance->c2_is_Start = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_tp_Start = 0U;
  chartInstance->c2_tp_Starter = 0U;
  chartInstance->c2_tp_StarterAndTQI = 0U;
  chartInstance->c2_is_active_c2_AxleSplitHEVv5 = 0U;
  chartInstance->c2_is_c2_AxleSplitHEVv5 = c2_IN_NO_ACTIVE_CHILD;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c2_FA_ICE_STATE = 0.0;
  }
}

static void initialize_params_c2_AxleSplitHEVv5
  (SFc2_AxleSplitHEVv5InstanceStruct *chartInstance)
{
}

static void enable_c2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_AxleSplitHEVv5
  (SFc2_AxleSplitHEVv5InstanceStruct *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_AxleSplitHEVv5 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_AxleSplitHEVv5 == c2_IN_Start) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_Start == c2_IN_Starter) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_Start == c2_IN_StarterAndTQI) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_AxleSplitHEVv5 == c2_IN_Stall) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_AxleSplitHEVv5 == c2_IN_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_Running == c2_IN_Idle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_Running == c2_IN_IdleTransOn) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_Running == c2_IN_Force_tracking) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_Force_tracking == c2_IN_Standard_force_tracking) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_Force_tracking == c2_IN_InjectionInhibed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_AxleSplitHEVv5
  (SFc2_AxleSplitHEVv5InstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_e_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  uint8_T c2_f_hoistedGlobal;
  uint8_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  real_T *c2_FA_ICE_STATE;
  c2_FA_ICE_STATE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(6), FALSE);
  c2_hoistedGlobal = *c2_FA_ICE_STATE;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_AxleSplitHEVv5;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_c2_AxleSplitHEVv5;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = chartInstance->c2_is_Force_tracking;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_is_Start;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = chartInstance->c2_is_Running;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_FA_ICE_STATE;
  c2_FA_ICE_STATE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_u = sf_mex_dup(c2_st);
  *c2_FA_ICE_STATE = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "FA_ICE_STATE");
  chartInstance->c2_is_active_c2_AxleSplitHEVv5 = c2_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_AxleSplitHEVv5");
  chartInstance->c2_is_c2_AxleSplitHEVv5 = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 2)), "is_c2_AxleSplitHEVv5");
  chartInstance->c2_is_Force_tracking = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 3)), "is_Force_tracking");
  chartInstance->c2_is_Start = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 4)), "is_Start");
  chartInstance->c2_is_Running = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 5)), "is_Running");
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 6)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_AxleSplitHEVv5(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_AxleSplitHEVv5
  (SFc2_AxleSplitHEVv5InstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    if (chartInstance->c2_is_c2_AxleSplitHEVv5 == c2_IN_Running) {
      chartInstance->c2_tp_Running = 1U;
    } else {
      chartInstance->c2_tp_Running = 0U;
    }

    if (chartInstance->c2_is_Running == c2_IN_Force_tracking) {
      chartInstance->c2_tp_Force_tracking = 1U;
    } else {
      chartInstance->c2_tp_Force_tracking = 0U;
    }

    if (chartInstance->c2_is_Force_tracking == c2_IN_InjectionInhibed) {
      chartInstance->c2_tp_InjectionInhibed = 1U;
    } else {
      chartInstance->c2_tp_InjectionInhibed = 0U;
    }

    if (chartInstance->c2_is_Force_tracking == c2_IN_Standard_force_tracking) {
      chartInstance->c2_tp_Standard_force_tracking = 1U;
    } else {
      chartInstance->c2_tp_Standard_force_tracking = 0U;
    }

    if (chartInstance->c2_is_Running == c2_IN_Idle) {
      chartInstance->c2_tp_Idle = 1U;
    } else {
      chartInstance->c2_tp_Idle = 0U;
    }

    if (chartInstance->c2_is_Running == c2_IN_IdleTransOn) {
      chartInstance->c2_tp_IdleTransOn = 1U;
    } else {
      chartInstance->c2_tp_IdleTransOn = 0U;
    }

    if (chartInstance->c2_is_c2_AxleSplitHEVv5 == c2_IN_Stall) {
      chartInstance->c2_tp_Stall = 1U;
    } else {
      chartInstance->c2_tp_Stall = 0U;
    }

    if (chartInstance->c2_is_c2_AxleSplitHEVv5 == c2_IN_Start) {
      chartInstance->c2_tp_Start = 1U;
    } else {
      chartInstance->c2_tp_Start = 0U;
    }

    if (chartInstance->c2_is_Start == c2_IN_Starter) {
      chartInstance->c2_tp_Starter = 1U;
    } else {
      chartInstance->c2_tp_Starter = 0U;
    }

    if (chartInstance->c2_is_Start == c2_IN_StarterAndTQI) {
      chartInstance->c2_tp_StarterAndTQI = 1U;
    } else {
      chartInstance->c2_tp_StarterAndTQI = 0U;
    }

    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_c2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  boolean_T *c2_FA_ICE_SYNCHRO;
  real_T *c2_FA_N_ICE;
  real_T *c2_CMD_FA_TQ_SP;
  real_T *c2_DRI_GBX_SP;
  real_T *c2_FA_ICE_STATE;
  boolean_T *c2_FA_CLU_STUCK;
  real_T *c2_FA_TQ_MIN_ICE;
  real_T *c2_FA_START_ICE;
  c2_FA_START_ICE = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_FA_TQ_MIN_ICE = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_FA_CLU_STUCK = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_FA_ICE_STATE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_DRI_GBX_SP = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_CMD_FA_TQ_SP = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_FA_N_ICE = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_FA_ICE_SYNCHRO = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_set_sim_state_side_effects_c2_AxleSplitHEVv5(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_FA_ICE_SYNCHRO, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_FA_N_ICE, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_CMD_FA_TQ_SP, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_DRI_GBX_SP, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_FA_CLU_STUCK, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_FA_TQ_MIN_ICE, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_FA_START_ICE, 7U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_AxleSplitHEVv5(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_AxleSplitHEVv5MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  boolean_T c2_temp;
  boolean_T c2_out;
  boolean_T c2_b_out;
  boolean_T c2_b_temp;
  boolean_T c2_c_temp;
  boolean_T c2_d_temp;
  boolean_T c2_c_out;
  boolean_T c2_d_out;
  boolean_T c2_e_out;
  boolean_T c2_e_temp;
  boolean_T c2_f_out;
  boolean_T c2_g_out;
  boolean_T c2_f_temp;
  boolean_T c2_h_out;
  boolean_T c2_i_out;
  real_T *c2_FA_START_ICE;
  real_T *c2_FA_N_ICE;
  real_T *c2_DRI_GBX_SP;
  boolean_T *c2_FA_CLU_STUCK;
  real_T *c2_FA_ICE_STATE;
  boolean_T *c2_FA_ICE_SYNCHRO;
  boolean_T guard1 = FALSE;
  c2_FA_START_ICE = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_FA_CLU_STUCK = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_FA_ICE_STATE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_DRI_GBX_SP = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_FA_N_ICE = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_FA_ICE_SYNCHRO = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  if (chartInstance->c2_is_active_c2_AxleSplitHEVv5 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_active_c2_AxleSplitHEVv5 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_AxleSplitHEVv5 = c2_IN_Stall;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_Stall = 1U;
    *c2_FA_ICE_STATE = 1.0;
    _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
  } else {
    switch (chartInstance->c2_is_c2_AxleSplitHEVv5) {
     case c2_IN_Running:
      CV_CHART_EVAL(1, 0, 1);
      c2_Running(chartInstance);
      break;

     case c2_IN_Stall:
      CV_CHART_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c2_sfEvent);
      c2_temp = (_SFD_CCP_CALL(1U, 0, *c2_FA_START_ICE == 1.0 != 0U,
                  chartInstance->c2_sfEvent) != 0);
      if (c2_temp) {
        c2_temp = (_SFD_CCP_CALL(1U, 1, *c2_FA_N_ICE < 30.0 != 0U,
                    chartInstance->c2_sfEvent) != 0);
      }

      c2_out = (CV_TRANSITION_EVAL(1U, (int32_T)c2_temp) != 0);
      if (c2_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 1;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          c2_b_out = ((*c2_FA_START_ICE == 1.0) && (*c2_FA_N_ICE > 600.0) &&
                      (*c2_DRI_GBX_SP != 0.0) && ((int16_T)*c2_FA_CLU_STUCK == 1));
          if (c2_b_out) {
            transitionList[numTransitions] = 19;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Stall = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_AxleSplitHEVv5 = c2_IN_Start;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Start = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_Start = c2_IN_Starter;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Starter = 1U;
        *c2_FA_ICE_STATE = 2.1;
        _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                     chartInstance->c2_sfEvent);
        c2_b_temp = (_SFD_CCP_CALL(19U, 0, *c2_FA_START_ICE == 1.0 != 0U,
          chartInstance->c2_sfEvent) != 0);
        if (c2_b_temp) {
          c2_b_temp = (_SFD_CCP_CALL(19U, 1, *c2_FA_N_ICE > 600.0 != 0U,
            chartInstance->c2_sfEvent) != 0);
        }

        c2_c_temp = c2_b_temp;
        if (c2_c_temp) {
          c2_c_temp = (_SFD_CCP_CALL(19U, 2, *c2_DRI_GBX_SP != 0.0 != 0U,
            chartInstance->c2_sfEvent) != 0);
        }

        c2_d_temp = c2_c_temp;
        if (c2_d_temp) {
          c2_d_temp = (_SFD_CCP_CALL(19U, 3, (int16_T)*c2_FA_CLU_STUCK == 1 !=
            0U, chartInstance->c2_sfEvent) != 0);
        }

        c2_c_out = (CV_TRANSITION_EVAL(19U, (int32_T)c2_d_temp) != 0);
        if (c2_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_Stall = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_c2_AxleSplitHEVv5 = c2_IN_Running;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_Running = 1U;
          chartInstance->c2_is_Running = c2_IN_Force_tracking;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_Force_tracking = 1U;
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_Force_tracking = c2_IN_Standard_force_tracking;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_Standard_force_tracking = 1U;
          *c2_FA_ICE_STATE = 5.1;
          _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                       chartInstance->c2_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_Start:
      CV_CHART_EVAL(1, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c2_sfEvent);
      c2_d_out = (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0,
        *c2_FA_N_ICE > 600.0 != 0U, chartInstance->c2_sfEvent)) != 0);
      guard1 = FALSE;
      if (c2_d_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 2;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          c2_e_out = (*c2_FA_START_ICE != 1.0);
          if (c2_e_out) {
            transitionList[numTransitions] = 17;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        c2_exit_internal_Start(chartInstance);
        chartInstance->c2_tp_Start = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_AxleSplitHEVv5 = c2_IN_Running;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Running = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c2_sfEvent);
        c2_e_temp = (_SFD_CCP_CALL(5U, 0, *c2_FA_CLU_STUCK != 0U,
          chartInstance->c2_sfEvent) != 0);
        if (c2_e_temp) {
          c2_e_temp = (_SFD_CCP_CALL(5U, 1, *c2_DRI_GBX_SP != 0.0 != 0U,
            chartInstance->c2_sfEvent) != 0);
        }

        c2_f_out = (CV_TRANSITION_EVAL(5U, (int32_T)c2_e_temp) != 0);
        if (c2_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_Running = c2_IN_IdleTransOn;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_IdleTransOn = 1U;
          *c2_FA_ICE_STATE = 4.0;
          _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_Running = c2_IN_Idle;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_Idle = 1U;
          *c2_FA_ICE_STATE = 3.0;
          _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
        }

        guard1 = TRUE;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                     chartInstance->c2_sfEvent);
        c2_g_out = (CV_TRANSITION_EVAL(17U, (int32_T)_SFD_CCP_CALL(17U, 0,
          *c2_FA_START_ICE != 1.0 != 0U, chartInstance->c2_sfEvent)) != 0);
        if (c2_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
          c2_exit_internal_Start(chartInstance);
          chartInstance->c2_tp_Start = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_c2_AxleSplitHEVv5 = c2_IN_Stall;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_Stall = 1U;
          *c2_FA_ICE_STATE = 1.0;
          _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
          guard1 = TRUE;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                       chartInstance->c2_sfEvent);
          switch (chartInstance->c2_is_Start) {
           case c2_IN_Starter:
            CV_STATE_EVAL(7, 0, 1);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                         chartInstance->c2_sfEvent);
            c2_f_temp = (_SFD_CCP_CALL(11U, 0, *c2_FA_N_ICE > 250.0 != 0U,
              chartInstance->c2_sfEvent) != 0);
            if (c2_f_temp) {
              c2_f_temp = (_SFD_CCP_CALL(11U, 1, (int16_T)*c2_FA_ICE_SYNCHRO ==
                1 != 0U, chartInstance->c2_sfEvent) != 0);
            }

            c2_h_out = (CV_TRANSITION_EVAL(11U, (int32_T)c2_f_temp) != 0);
            if (c2_h_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
              chartInstance->c2_tp_Starter = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
              chartInstance->c2_is_Start = c2_IN_StarterAndTQI;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
              chartInstance->c2_tp_StarterAndTQI = 1U;
              *c2_FA_ICE_STATE = 2.2;
              _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
            } else {
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                           chartInstance->c2_sfEvent);
            }

            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c2_sfEvent);
            guard1 = TRUE;
            break;

           case c2_IN_StarterAndTQI:
            CV_STATE_EVAL(7, 0, 2);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                         chartInstance->c2_sfEvent);
            c2_i_out = (CV_TRANSITION_EVAL(16U, (int32_T)_SFD_CCP_CALL(16U, 0,
              *c2_FA_N_ICE < 250.0 != 0U, chartInstance->c2_sfEvent)) != 0);
            if (c2_i_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
              chartInstance->c2_tp_StarterAndTQI = 0U;
              chartInstance->c2_is_Start = c2_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
              chartInstance->c2_tp_Start = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
              chartInstance->c2_is_c2_AxleSplitHEVv5 = c2_IN_Stall;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
              chartInstance->c2_tp_Stall = 1U;
              *c2_FA_ICE_STATE = 1.0;
              _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
            } else {
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                           chartInstance->c2_sfEvent);
            }

            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c2_sfEvent);
            if (chartInstance->c2_is_c2_AxleSplitHEVv5 != c2_IN_Start) {
            } else {
              guard1 = TRUE;
            }
            break;

           default:
            CV_STATE_EVAL(7, 0, 0);
            chartInstance->c2_is_Start = c2_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
            guard1 = TRUE;
            break;
          }
        }
      }

      if (guard1 == TRUE) {
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
      }
      break;

     default:
      CV_CHART_EVAL(1, 0, 0);
      chartInstance->c2_is_c2_AxleSplitHEVv5 = c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
}

static void registerMessagesc2_AxleSplitHEVv5(SFc2_AxleSplitHEVv5InstanceStruct *
  chartInstance)
{
}

static void c2_exit_internal_Start(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  switch (chartInstance->c2_is_Start) {
   case c2_IN_Starter:
    CV_STATE_EVAL(7, 1, 1);
    chartInstance->c2_tp_Starter = 0U;
    chartInstance->c2_is_Start = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_StarterAndTQI:
    CV_STATE_EVAL(7, 1, 2);
    chartInstance->c2_tp_StarterAndTQI = 0U;
    chartInstance->c2_is_Start = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_STATE_EVAL(7, 1, 0);
    chartInstance->c2_is_Start = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
    break;
  }
}

static void c2_Running(SFc2_AxleSplitHEVv5InstanceStruct *chartInstance)
{
  boolean_T c2_temp;
  boolean_T c2_out;
  boolean_T c2_b_temp;
  boolean_T c2_b_out;
  boolean_T c2_c_out;
  boolean_T c2_c_temp;
  boolean_T c2_d_temp;
  boolean_T c2_d_out;
  boolean_T c2_e_out;
  boolean_T c2_e_temp;
  boolean_T c2_f_out;
  boolean_T c2_f_temp;
  boolean_T c2_g_out;
  boolean_T c2_h_out;
  boolean_T c2_g_temp;
  boolean_T c2_h_temp;
  boolean_T c2_i_out;
  real_T *c2_FA_START_ICE;
  real_T *c2_FA_N_ICE;
  boolean_T *c2_FA_CLU_STUCK;
  real_T *c2_DRI_GBX_SP;
  real_T *c2_CMD_FA_TQ_SP;
  real_T *c2_FA_TQ_MIN_ICE;
  real_T *c2_FA_ICE_STATE;
  boolean_T guard1 = FALSE;
  c2_FA_START_ICE = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_FA_TQ_MIN_ICE = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_FA_CLU_STUCK = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_FA_ICE_STATE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_DRI_GBX_SP = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_CMD_FA_TQ_SP = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_FA_N_ICE = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c2_sfEvent);
  c2_temp = (_SFD_CCP_CALL(3U, 0, *c2_FA_START_ICE != 1.0 != 0U,
              chartInstance->c2_sfEvent) != 0);
  if (!c2_temp) {
    c2_temp = (_SFD_CCP_CALL(3U, 1, *c2_FA_N_ICE < 400.0 != 0U,
                chartInstance->c2_sfEvent) != 0);
  }

  c2_out = (CV_TRANSITION_EVAL(3U, (int32_T)c2_temp) != 0);
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
    switch (chartInstance->c2_is_Running) {
     case c2_IN_Force_tracking:
      CV_STATE_EVAL(0, 1, 1);
      c2_exit_internal_Force_tracking(chartInstance);
      chartInstance->c2_tp_Force_tracking = 0U;
      chartInstance->c2_is_Running = c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_Idle:
      CV_STATE_EVAL(0, 1, 2);
      chartInstance->c2_tp_Idle = 0U;
      chartInstance->c2_is_Running = c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_IdleTransOn:
      CV_STATE_EVAL(0, 1, 3);
      chartInstance->c2_tp_IdleTransOn = 0U;
      chartInstance->c2_is_Running = c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
      break;

     default:
      CV_STATE_EVAL(0, 1, 0);
      chartInstance->c2_is_Running = c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
      break;
    }

    chartInstance->c2_tp_Running = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_AxleSplitHEVv5 = c2_IN_Stall;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_Stall = 1U;
    *c2_FA_ICE_STATE = 1.0;
    _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
    switch (chartInstance->c2_is_Running) {
     case c2_IN_Force_tracking:
      CV_STATE_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   chartInstance->c2_sfEvent);
      c2_b_temp = (_SFD_CCP_CALL(10U, 0, (int16_T)*c2_FA_CLU_STUCK == 0 != 0U,
        chartInstance->c2_sfEvent) != 0);
      if (!c2_b_temp) {
        c2_b_temp = (_SFD_CCP_CALL(10U, 1, *c2_DRI_GBX_SP == 0.0 != 0U,
          chartInstance->c2_sfEvent) != 0);
      }

      c2_b_out = (CV_TRANSITION_EVAL(10U, (int32_T)c2_b_temp) != 0);
      guard1 = FALSE;
      if (c2_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
        c2_exit_internal_Force_tracking(chartInstance);
        chartInstance->c2_tp_Force_tracking = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_Running = c2_IN_Idle;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Idle = 1U;
        *c2_FA_ICE_STATE = 3.0;
        _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
        guard1 = TRUE;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c2_sfEvent);
        switch (chartInstance->c2_is_Force_tracking) {
         case c2_IN_InjectionInhibed:
          CV_STATE_EVAL(1, 0, 1);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                       chartInstance->c2_sfEvent);
          c2_c_out = (CV_TRANSITION_EVAL(13U, (int32_T)_SFD_CCP_CALL(13U, 0,
            *c2_CMD_FA_TQ_SP > *c2_FA_TQ_MIN_ICE != 0U,
            chartInstance->c2_sfEvent)) != 0);
          if (c2_c_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_InjectionInhibed = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
            chartInstance->c2_is_Force_tracking = c2_IN_Standard_force_tracking;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_Standard_force_tracking = 1U;
            *c2_FA_ICE_STATE = 5.1;
            _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                         chartInstance->c2_sfEvent);
            c2_c_temp = (_SFD_CCP_CALL(9U, 0, *c2_FA_N_ICE < 1200.0 != 0U,
              chartInstance->c2_sfEvent) != 0);
            if (c2_c_temp) {
              c2_c_temp = (_SFD_CCP_CALL(9U, 1, (int16_T)*c2_FA_CLU_STUCK == 1
                != 0U, chartInstance->c2_sfEvent) != 0);
            }

            c2_d_temp = c2_c_temp;
            if (c2_d_temp) {
              c2_d_temp = (_SFD_CCP_CALL(9U, 2, *c2_DRI_GBX_SP != 0.0 != 0U,
                chartInstance->c2_sfEvent) != 0);
            }

            c2_d_out = (CV_TRANSITION_EVAL(9U, (int32_T)c2_d_temp) != 0);
            if (c2_d_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
              chartInstance->c2_tp_InjectionInhibed = 0U;
              chartInstance->c2_is_Force_tracking = c2_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
              chartInstance->c2_tp_Force_tracking = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
              chartInstance->c2_is_Running = c2_IN_IdleTransOn;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
              chartInstance->c2_tp_IdleTransOn = 1U;
              *c2_FA_ICE_STATE = 4.0;
              _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
            } else {
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                           chartInstance->c2_sfEvent);
            }
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
          if (chartInstance->c2_is_Running != c2_IN_Force_tracking) {
          } else {
            guard1 = TRUE;
          }
          break;

         case c2_IN_Standard_force_tracking:
          CV_STATE_EVAL(1, 0, 2);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                       chartInstance->c2_sfEvent);
          c2_e_out = (CV_TRANSITION_EVAL(14U, (int32_T)_SFD_CCP_CALL(14U, 0,
            *c2_CMD_FA_TQ_SP == *c2_FA_TQ_MIN_ICE != 0U,
            chartInstance->c2_sfEvent)) != 0);
          if (c2_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_Standard_force_tracking = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
            chartInstance->c2_is_Force_tracking = c2_IN_InjectionInhibed;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_InjectionInhibed = 1U;
            *c2_FA_ICE_STATE = 5.2;
            _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                         chartInstance->c2_sfEvent);
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c2_sfEvent);
          guard1 = TRUE;
          break;

         default:
          CV_STATE_EVAL(1, 0, 0);
          chartInstance->c2_is_Force_tracking = c2_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
          guard1 = TRUE;
          break;
        }
      }

      if (guard1 == TRUE) {
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
      }
      break;

     case c2_IN_Idle:
      CV_STATE_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c2_sfEvent);
      c2_e_temp = (_SFD_CCP_CALL(6U, 0, *c2_FA_CLU_STUCK != 0U,
        chartInstance->c2_sfEvent) != 0);
      if (c2_e_temp) {
        c2_e_temp = (_SFD_CCP_CALL(6U, 1, *c2_DRI_GBX_SP != 0.0 != 0U,
          chartInstance->c2_sfEvent) != 0);
      }

      c2_f_out = (CV_TRANSITION_EVAL(6U, (int32_T)c2_e_temp) != 0);
      if (c2_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Idle = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_Running = c2_IN_IdleTransOn;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_IdleTransOn = 1U;
        *c2_FA_ICE_STATE = 4.0;
        _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c2_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_IdleTransOn:
      CV_STATE_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c2_sfEvent);
      c2_f_temp = (_SFD_CCP_CALL(7U, 0, (int16_T)*c2_FA_CLU_STUCK == 0 != 0U,
        chartInstance->c2_sfEvent) != 0);
      if (!c2_f_temp) {
        c2_f_temp = (_SFD_CCP_CALL(7U, 1, *c2_DRI_GBX_SP == 0.0 != 0U,
          chartInstance->c2_sfEvent) != 0);
      }

      c2_g_out = (CV_TRANSITION_EVAL(7U, (int32_T)c2_f_temp) != 0);
      if (c2_g_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 7;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          c2_h_out = (((int16_T)*c2_FA_CLU_STUCK == 1) && (*c2_DRI_GBX_SP != 0.0)
                      && (*c2_CMD_FA_TQ_SP > 0.0));
          if (c2_h_out) {
            transitionList[numTransitions] = 8;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_IdleTransOn = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_Running = c2_IN_Idle;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Idle = 1U;
        *c2_FA_ICE_STATE = 3.0;
        _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                     chartInstance->c2_sfEvent);
        c2_g_temp = (_SFD_CCP_CALL(8U, 0, (int16_T)*c2_FA_CLU_STUCK == 1 != 0U,
          chartInstance->c2_sfEvent) != 0);
        if (c2_g_temp) {
          c2_g_temp = (_SFD_CCP_CALL(8U, 1, *c2_DRI_GBX_SP != 0.0 != 0U,
            chartInstance->c2_sfEvent) != 0);
        }

        c2_h_temp = c2_g_temp;
        if (c2_h_temp) {
          c2_h_temp = (_SFD_CCP_CALL(8U, 2, *c2_CMD_FA_TQ_SP > 0.0 != 0U,
            chartInstance->c2_sfEvent) != 0);
        }

        c2_i_out = (CV_TRANSITION_EVAL(8U, (int32_T)c2_h_temp) != 0);
        if (c2_i_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_IdleTransOn = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_Running = c2_IN_Force_tracking;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_Force_tracking = 1U;
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_Force_tracking = c2_IN_Standard_force_tracking;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_Standard_force_tracking = 1U;
          *c2_FA_ICE_STATE = 5.1;
          _SFD_DATA_RANGE_CHECK(*c2_FA_ICE_STATE, 4U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                       chartInstance->c2_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c2_sfEvent);
      break;

     default:
      CV_STATE_EVAL(0, 0, 0);
      chartInstance->c2_is_Running = c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void c2_exit_internal_Force_tracking(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  switch (chartInstance->c2_is_Force_tracking) {
   case c2_IN_InjectionInhibed:
    CV_STATE_EVAL(1, 1, 1);
    chartInstance->c2_tp_InjectionInhibed = 0U;
    chartInstance->c2_is_Force_tracking = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_Standard_force_tracking:
    CV_STATE_EVAL(1, 1, 2);
    chartInstance->c2_tp_Standard_force_tracking = 0U;
    chartInstance->c2_is_Force_tracking = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    chartInstance->c2_is_Force_tracking = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

const mxArray *sf_c2_AxleSplitHEVv5_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc2_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_emlrt_marshallIn(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i0, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc2_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc2_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static uint8_T c2_b_emlrt_marshallIn(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_b_tp_Start, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_Start),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_Start);
  return c2_y;
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tp_Start;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc2_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c2_b_tp_Start = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_Start),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_Start);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  boolean_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc2_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(boolean_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc2_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_d_emlrt_marshallIn(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_FA_ICE_STATE, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_FA_ICE_STATE),
    &c2_thisId);
  sf_mex_destroy(&c2_FA_ICE_STATE);
  return c2_y;
}

static real_T c2_e_emlrt_marshallIn(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_FA_ICE_STATE;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc2_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c2_FA_ICE_STATE = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_FA_ICE_STATE),
    &c2_thisId);
  sf_mex_destroy(&c2_FA_ICE_STATE);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_emlrt_marshallIn(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  sf_mex_assign(&c2_y, c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), FALSE);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_g_emlrt_marshallIn(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), FALSE);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_AxleSplitHEVv5_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1029309686U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4031423353U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(991059166U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(252044382U);
}

mxArray *sf_c2_AxleSplitHEVv5_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("zdcjuemXbZFjYl1IE9dnrF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_AxleSplitHEVv5_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_AxleSplitHEVv5(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[18],T\"FA_ICE_STATE\",},{M[8],M[0],T\"is_active_c2_AxleSplitHEVv5\",},{M[9],M[0],T\"is_c2_AxleSplitHEVv5\",},{M[9],M[3],T\"is_Force_tracking\",},{M[9],M[20],T\"is_Start\",},{M[9],M[86],T\"is_Running\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_AxleSplitHEVv5_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_AxleSplitHEVv5InstanceStruct *chartInstance;
    chartInstance = (SFc2_AxleSplitHEVv5InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AxleSplitHEVv5MachineNumber_,
           2,
           10,
           20,
           8,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_AxleSplitHEVv5MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_AxleSplitHEVv5MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _AxleSplitHEVv5MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"FA_ICE_SYNCHRO");
          _SFD_SET_DATA_PROPS(1,1,1,0,"FA_N_ICE");
          _SFD_SET_DATA_PROPS(2,1,1,0,"CMD_FA_TQ_SP");
          _SFD_SET_DATA_PROPS(3,1,1,0,"DRI_GBX_SP");
          _SFD_SET_DATA_PROPS(4,2,0,1,"FA_ICE_STATE");
          _SFD_SET_DATA_PROPS(5,1,1,0,"FA_CLU_STUCK");
          _SFD_SET_DATA_PROPS(6,1,1,0,"FA_TQ_MIN_ICE");
          _SFD_SET_DATA_PROPS(7,1,1,0,"FA_START_ICE");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,6);
          _SFD_CH_SUBSTATE_INDEX(2,7);
          _SFD_ST_SUBSTATE_COUNT(0,3);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,4);
          _SFD_ST_SUBSTATE_INDEX(0,2,5);
          _SFD_ST_SUBSTATE_COUNT(1,2);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,2);
          _SFD_ST_SUBSTATE_INDEX(7,0,8);
          _SFD_ST_SUBSTATE_INDEX(7,1,9);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 18 };

          static unsigned int sEndGuardMap[] = { 14, 35 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(11,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 21 };

          static unsigned int sEndGuardMap[] = { 17, 34 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(5,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 3, 22 };

          static unsigned int sEndGuardMap[] = { 18, 35 };

          static int sPostFixPredicateTree[] = { 0, 1, -2 };

          _SFD_CV_INIT_TRANS(7,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 21 };

          static unsigned int sEndGuardMap[] = { 17, 34 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(6,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 3, 22 };

          static unsigned int sEndGuardMap[] = { 18, 35 };

          static int sPostFixPredicateTree[] = { 0, 1, -2 };

          _SFD_CV_INIT_TRANS(10,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 21, 38 };

          static unsigned int sEndGuardMap[] = { 17, 34, 52 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(8,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 19, 38 };

          static unsigned int sEndGuardMap[] = { 15, 34, 51 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(9,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 27 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(13,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 29 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(14,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 16 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(17,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 21 };

          static unsigned int sEndGuardMap[] = { 17, 32 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(1,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 21, 37, 54 };

          static unsigned int sEndGuardMap[] = { 17, 33, 50, 69 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_TRANS(19,4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 21 };

          static unsigned int sEndGuardMap[] = { 17, 33 };

          static int sPostFixPredicateTree[] = { 0, 1, -2 };

          _SFD_CV_INIT_TRANS(3,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(16,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_TRANS_COV_WTS(12,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(12,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(11,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 18 };

          static unsigned int sEndGuardMap[] = { 14, 35 };

          _SFD_TRANS_COV_MAPS(11,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(18,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(18,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(5,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 21 };

          static unsigned int sEndGuardMap[] = { 17, 34 };

          _SFD_TRANS_COV_MAPS(5,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(4,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(7,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 3, 22 };

          static unsigned int sEndGuardMap[] = { 18, 35 };

          _SFD_TRANS_COV_MAPS(7,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(6,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 21 };

          static unsigned int sEndGuardMap[] = { 17, 34 };

          _SFD_TRANS_COV_MAPS(6,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(10,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 3, 22 };

          static unsigned int sEndGuardMap[] = { 18, 35 };

          _SFD_TRANS_COV_MAPS(10,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(8,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 21, 38 };

          static unsigned int sEndGuardMap[] = { 17, 34, 52 };

          _SFD_TRANS_COV_MAPS(8,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(9,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 19, 38 };

          static unsigned int sEndGuardMap[] = { 15, 34, 51 };

          _SFD_TRANS_COV_MAPS(9,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(15,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(15,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(13,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 27 };

          _SFD_TRANS_COV_MAPS(13,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(14,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 29 };

          _SFD_TRANS_COV_MAPS(14,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(0,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(17,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 16 };

          _SFD_TRANS_COV_MAPS(17,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 21 };

          static unsigned int sEndGuardMap[] = { 17, 32 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(19,0,4,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 21, 37, 54 };

          static unsigned int sEndGuardMap[] = { 17, 33, 50, 69 };

          _SFD_TRANS_COV_MAPS(19,
                              0,NULL,NULL,
                              4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(3,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 21 };

          static unsigned int sEndGuardMap[] = { 17, 33 };

          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(16,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 14 };

          _SFD_TRANS_COV_MAPS(16,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          boolean_T *c2_FA_ICE_SYNCHRO;
          real_T *c2_FA_N_ICE;
          real_T *c2_CMD_FA_TQ_SP;
          real_T *c2_DRI_GBX_SP;
          real_T *c2_FA_ICE_STATE;
          boolean_T *c2_FA_CLU_STUCK;
          real_T *c2_FA_TQ_MIN_ICE;
          real_T *c2_FA_START_ICE;
          c2_FA_START_ICE = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c2_FA_TQ_MIN_ICE = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_FA_CLU_STUCK = (boolean_T *)ssGetInputPortSignal(chartInstance->S,
            4);
          c2_FA_ICE_STATE = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_DRI_GBX_SP = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_CMD_FA_TQ_SP = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_FA_N_ICE = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_FA_ICE_SYNCHRO = (boolean_T *)ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_FA_ICE_SYNCHRO);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_FA_N_ICE);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_CMD_FA_TQ_SP);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_DRI_GBX_SP);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_FA_ICE_STATE);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_FA_CLU_STUCK);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_FA_TQ_MIN_ICE);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_FA_START_ICE);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _AxleSplitHEVv5MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "Xx5ixPro1ejtUjDvYExTRH";
}

static void sf_opaque_initialize_c2_AxleSplitHEVv5(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_AxleSplitHEVv5InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_AxleSplitHEVv5((SFc2_AxleSplitHEVv5InstanceStruct*)
    chartInstanceVar);
  initialize_c2_AxleSplitHEVv5((SFc2_AxleSplitHEVv5InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_AxleSplitHEVv5(void *chartInstanceVar)
{
  enable_c2_AxleSplitHEVv5((SFc2_AxleSplitHEVv5InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_AxleSplitHEVv5(void *chartInstanceVar)
{
  disable_c2_AxleSplitHEVv5((SFc2_AxleSplitHEVv5InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_AxleSplitHEVv5(void *chartInstanceVar)
{
  sf_c2_AxleSplitHEVv5((SFc2_AxleSplitHEVv5InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_AxleSplitHEVv5(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_AxleSplitHEVv5
    ((SFc2_AxleSplitHEVv5InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_AxleSplitHEVv5();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_AxleSplitHEVv5(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_AxleSplitHEVv5();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_AxleSplitHEVv5((SFc2_AxleSplitHEVv5InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_AxleSplitHEVv5(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_AxleSplitHEVv5(S);
}

static void sf_opaque_set_sim_state_c2_AxleSplitHEVv5(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_AxleSplitHEVv5(S, st);
}

static void sf_opaque_terminate_c2_AxleSplitHEVv5(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_AxleSplitHEVv5InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AxleSplitHEVv5_optimization_info();
    }

    finalize_c2_AxleSplitHEVv5((SFc2_AxleSplitHEVv5InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_AxleSplitHEVv5((SFc2_AxleSplitHEVv5InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_AxleSplitHEVv5(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_AxleSplitHEVv5((SFc2_AxleSplitHEVv5InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_AxleSplitHEVv5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_AxleSplitHEVv5_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2769219781U));
  ssSetChecksum1(S,(2662052820U));
  ssSetChecksum2(S,(1269453640U));
  ssSetChecksum3(S,(718341763U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_AxleSplitHEVv5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_AxleSplitHEVv5(SimStruct *S)
{
  SFc2_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc2_AxleSplitHEVv5InstanceStruct *)utMalloc(sizeof
    (SFc2_AxleSplitHEVv5InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_AxleSplitHEVv5InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_AxleSplitHEVv5;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_AxleSplitHEVv5;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_AxleSplitHEVv5;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_AxleSplitHEVv5;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_AxleSplitHEVv5;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_AxleSplitHEVv5;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_AxleSplitHEVv5;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_AxleSplitHEVv5;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_AxleSplitHEVv5;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_AxleSplitHEVv5;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_AxleSplitHEVv5;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_AxleSplitHEVv5_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_AxleSplitHEVv5(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_AxleSplitHEVv5(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_AxleSplitHEVv5(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_AxleSplitHEVv5_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
