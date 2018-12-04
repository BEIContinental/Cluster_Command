/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AxleSplitHEVv5_sfun.h"
#include "c1_AxleSplitHEVv5.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "AxleSplitHEVv5_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_STATE_1                  ((uint8_T)1U)
#define c1_IN_STATE_21                 ((uint8_T)2U)
#define c1_IN_STATE_22                 ((uint8_T)3U)
#define c1_IN_STATE_3                  ((uint8_T)4U)
#define c1_IN_STATE_4                  ((uint8_T)5U)
#define c1_IN_STATE_5                  ((uint8_T)6U)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_g_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_h_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_i_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_j_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_k_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_l_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_m_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_n_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_o_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_p_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_q_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_r_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_s_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_t_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_u_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_v_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_w_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_x_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_y_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ab_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_bb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_cb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_db_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_eb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_fb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_gb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_hb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ib_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_jb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_kb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_lb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_mb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_nb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ob_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_pb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_qb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_rb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_sb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_tb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_ub_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_vb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_wb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_xb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c1_yb_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static boolean_T c1_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void initialize_params_c1_AxleSplitHEVv5
  (SFc1_AxleSplitHEVv5InstanceStruct *chartInstance);
static void enable_c1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void disable_c1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_AxleSplitHEVv5
  (SFc1_AxleSplitHEVv5InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_AxleSplitHEVv5
  (SFc1_AxleSplitHEVv5InstanceStruct *chartInstance);
static void set_sim_state_c1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_AxleSplitHEVv5
  (SFc1_AxleSplitHEVv5InstanceStruct *chartInstance);
static void finalize_c1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void sf_c1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void c1_chartstep_c1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void initSimStructsc1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void registerMessagesc1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct *
  chartInstance);
static void c1_STATE_3(SFc1_AxleSplitHEVv5InstanceStruct *chartInstance);
static void c1_STATE_22(SFc1_AxleSplitHEVv5InstanceStruct *chartInstance);
static void c1_STATE_4(SFc1_AxleSplitHEVv5InstanceStruct *chartInstance);
static void c1_STATE_1(SFc1_AxleSplitHEVv5InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_nargout, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_c_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_b_tp_STATE_3, const char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_g_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_h_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_updateDataWrittenToVector(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, uint32_T c1_vectorIndex);
static void init_test_point_addr_map(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static void **get_test_point_address_map(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc1_AxleSplitHEVv5InstanceStruct *chartInstance);
static void init_dsm_address_info(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_tp_STATE_1 = 0U;
  chartInstance->c1_tp_STATE_21 = 0U;
  chartInstance->c1_tp_STATE_22 = 0U;
  chartInstance->c1_tp_STATE_3 = 0U;
  chartInstance->c1_tp_STATE_4 = 0U;
  chartInstance->c1_tp_STATE_5 = 0U;
  chartInstance->c1_is_active_c1_AxleSplitHEVv5 = 0U;
  chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c1_AxleSplitHEVv5
  (SFc1_AxleSplitHEVv5InstanceStruct *chartInstance)
{
}

static void enable_c1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_AxleSplitHEVv5
  (SFc1_AxleSplitHEVv5InstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_AxleSplitHEVv5 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_AxleSplitHEVv5 == c1_IN_STATE_3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_AxleSplitHEVv5 == c1_IN_STATE_5) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_AxleSplitHEVv5 == c1_IN_STATE_22) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_AxleSplitHEVv5 == c1_IN_STATE_4) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_AxleSplitHEVv5 == c1_IN_STATE_1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_AxleSplitHEVv5 == c1_IN_STATE_21) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_AxleSplitHEVv5
  (SFc1_AxleSplitHEVv5InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_c_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T *c1_FA_GAS_CONSUMPTION;
  c1_FA_GAS_CONSUMPTION = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3), FALSE);
  c1_hoistedGlobal = *c1_FA_GAS_CONSUMPTION;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_AxleSplitHEVv5;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = chartInstance->c1_is_c1_AxleSplitHEVv5;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_FA_GAS_CONSUMPTION;
  c1_FA_GAS_CONSUMPTION = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = sf_mex_dup(c1_st);
  *c1_FA_GAS_CONSUMPTION = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 0)), "FA_GAS_CONSUMPTION");
  chartInstance->c1_is_active_c1_AxleSplitHEVv5 = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_AxleSplitHEVv5");
  chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 2)), "is_c1_AxleSplitHEVv5");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 3)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_AxleSplitHEVv5(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_AxleSplitHEVv5
  (SFc1_AxleSplitHEVv5InstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_c1_AxleSplitHEVv5 == c1_IN_STATE_1) {
      chartInstance->c1_tp_STATE_1 = 1U;
    } else {
      chartInstance->c1_tp_STATE_1 = 0U;
    }

    if (chartInstance->c1_is_c1_AxleSplitHEVv5 == c1_IN_STATE_21) {
      chartInstance->c1_tp_STATE_21 = 1U;
    } else {
      chartInstance->c1_tp_STATE_21 = 0U;
    }

    if (chartInstance->c1_is_c1_AxleSplitHEVv5 == c1_IN_STATE_22) {
      chartInstance->c1_tp_STATE_22 = 1U;
    } else {
      chartInstance->c1_tp_STATE_22 = 0U;
    }

    if (chartInstance->c1_is_c1_AxleSplitHEVv5 == c1_IN_STATE_3) {
      chartInstance->c1_tp_STATE_3 = 1U;
    } else {
      chartInstance->c1_tp_STATE_3 = 0U;
    }

    if (chartInstance->c1_is_c1_AxleSplitHEVv5 == c1_IN_STATE_4) {
      chartInstance->c1_tp_STATE_4 = 1U;
    } else {
      chartInstance->c1_tp_STATE_4 = 0U;
    }

    if (chartInstance->c1_is_c1_AxleSplitHEVv5 == c1_IN_STATE_5) {
      chartInstance->c1_tp_STATE_5 = 1U;
    } else {
      chartInstance->c1_tp_STATE_5 = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_c1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  c1_set_sim_state_side_effects_c1_AxleSplitHEVv5(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_AxleSplitHEVv5(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_AxleSplitHEVv5MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_c_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 1.0;
  boolean_T c1_e_out;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_f_out;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 1.0;
  boolean_T c1_g_out;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 1.0;
  boolean_T c1_h_out;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 1.0;
  boolean_T c1_i_out;
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 0.0;
  real_T *c1_FA_ICE_STATE;
  real_T *c1_FA_GAS_CONSUMPTION;
  c1_FA_ICE_STATE = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_FA_GAS_CONSUMPTION = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_AxleSplitHEVv5 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_AxleSplitHEVv5 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_STATE_1 = 1U;
  } else {
    switch (chartInstance->c1_is_c1_AxleSplitHEVv5) {
     case c1_IN_STATE_1:
      CV_CHART_EVAL(0, 0, 1);
      c1_STATE_1(chartInstance);
      break;

     case c1_IN_STATE_21:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_q_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_out = CV_EML_IF(12, 0, 0, *c1_FA_ICE_STATE == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 12;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_lb_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_b_out = (*c1_FA_ICE_STATE == 2.2);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_b_out) {
            transitionList[numTransitions] = 15;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_STATE_21 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_STATE_1 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_o_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_c_out = CV_EML_IF(15, 0, 0, *c1_FA_ICE_STATE == 2.2);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_STATE_21 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_22;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_STATE_22 = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                       chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_f_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          *c1_FA_GAS_CONSUMPTION = 0.0;
          c1_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_STATE_22:
      CV_CHART_EVAL(0, 0, 3);
      c1_STATE_22(chartInstance);
      break;

     case c1_IN_STATE_3:
      CV_CHART_EVAL(0, 0, 4);
      c1_STATE_3(chartInstance);
      break;

     case c1_IN_STATE_4:
      CV_CHART_EVAL(0, 0, 5);
      c1_STATE_4(chartInstance);
      break;

     case c1_IN_STATE_5:
      CV_CHART_EVAL(0, 0, 6);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_s_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_d_out = CV_EML_IF(0, 0, 0, *c1_FA_ICE_STATE == 4.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_d_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[3];
          unsigned int numTransitions = 1;
          transitionList[0] = 0;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_sb_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_e_out = (*c1_FA_ICE_STATE == 1.0);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_e_out) {
            transitionList[numTransitions] = 11;
            numTransitions++;
          }

          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_tb_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_f_out = (*c1_FA_ICE_STATE == 3.0);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_f_out) {
            transitionList[numTransitions] = 4;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_STATE_5 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_4;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_STATE_4 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_v_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_g_out = CV_EML_IF(11, 0, 0, *c1_FA_ICE_STATE == 1.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_g_out) {
          if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 11;
            _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_tb_debug_family_names,
              c1_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_out, 2U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            c1_h_out = (*c1_FA_ICE_STATE == 3.0);
            _SFD_SYMBOL_SCOPE_POP();
            if (c1_h_out) {
              transitionList[numTransitions] = 4;
              numTransitions++;
            }

            _SFD_TRANSITION_CONFLICT_CHECK_END();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_STATE_5 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_STATE_1 = 1U;
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                       chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_w_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_i_out = CV_EML_IF(4, 0, 0, *c1_FA_ICE_STATE == 3.0);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_i_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_STATE_5 = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
            chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_3;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_STATE_3 = 1U;
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                         chartInstance->c1_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_b_debug_family_names,
              c1_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            *c1_FA_GAS_CONSUMPTION = 0.0;
            c1_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_SYMBOL_SCOPE_POP();
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
}

static void registerMessagesc1_AxleSplitHEVv5(SFc1_AxleSplitHEVv5InstanceStruct *
  chartInstance)
{
}

static void c1_STATE_3(SFc1_AxleSplitHEVv5InstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_c_out;
  boolean_T c1_b0;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_e_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 1.0;
  boolean_T c1_f_out;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_g_out;
  boolean_T c1_b1;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 1.0;
  boolean_T c1_h_out;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 1.0;
  boolean_T c1_i_out;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 1.0;
  boolean_T c1_j_out;
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 1.0;
  boolean_T c1_k_out;
  real_T c1_l_nargin = 0.0;
  real_T c1_l_nargout = 1.0;
  boolean_T c1_l_out;
  real_T c1_m_nargin = 0.0;
  real_T c1_m_nargout = 1.0;
  boolean_T c1_m_out;
  real_T c1_n_nargin = 0.0;
  real_T c1_n_nargout = 1.0;
  boolean_T c1_n_out;
  real_T c1_o_nargin = 0.0;
  real_T c1_o_nargout = 1.0;
  boolean_T c1_o_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_p_nargin = 0.0;
  real_T c1_p_nargout = 0.0;
  real_T *c1_FA_ICE_STATE;
  real_T *c1_FA_GAS_CONSUMPTION;
  real_T *c1_fa_conso_idle;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c1_fa_conso_idle = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_FA_ICE_STATE = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_FA_GAS_CONSUMPTION = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_r_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_out = CV_EML_IF(9, 0, 0, *c1_FA_ICE_STATE == 4.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[5];
      unsigned int numTransitions = 1;
      transitionList[0] = 9;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_yb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_b_out = (*c1_FA_ICE_STATE == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        transitionList[numTransitions] = 5;
        numTransitions++;
      }

      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_hb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      guard3 = FALSE;
      if (*c1_FA_ICE_STATE == 5.1) {
        guard3 = TRUE;
      } else if (*c1_FA_ICE_STATE == 5.2) {
        guard3 = TRUE;
      } else {
        c1_b0 = FALSE;
      }

      if (guard3 == TRUE) {
        c1_b0 = TRUE;
      }

      c1_c_out = c1_b0;
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        transitionList[numTransitions] = 16;
        numTransitions++;
      }

      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_rb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_d_out = (*c1_FA_ICE_STATE == 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_d_out) {
        transitionList[numTransitions] = 17;
        numTransitions++;
      }

      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_vb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_e_out = (*c1_FA_ICE_STATE == 2.1);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_e_out) {
        transitionList[numTransitions] = 19;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_STATE_3 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_4;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_STATE_4 = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_cb_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_f_out = CV_EML_IF(5, 0, 0, *c1_FA_ICE_STATE == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_f_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[4];
        unsigned int numTransitions = 1;
        transitionList[0] = 5;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_hb_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        guard2 = FALSE;
        if (*c1_FA_ICE_STATE == 5.1) {
          guard2 = TRUE;
        } else if (*c1_FA_ICE_STATE == 5.2) {
          guard2 = TRUE;
        } else {
          c1_b1 = FALSE;
        }

        if (guard2 == TRUE) {
          c1_b1 = TRUE;
        }

        c1_g_out = c1_b1;
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_g_out) {
          transitionList[numTransitions] = 16;
          numTransitions++;
        }

        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_rb_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_h_out = (*c1_FA_ICE_STATE == 2.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_h_out) {
          transitionList[numTransitions] = 17;
          numTransitions++;
        }

        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_vb_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_i_out = (*c1_FA_ICE_STATE == 2.1);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_i_out) {
          transitionList[numTransitions] = 19;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_STATE_3 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_STATE_1 = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_k_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      guard1 = FALSE;
      if (CV_EML_COND(16, 0, 0, *c1_FA_ICE_STATE == 5.1)) {
        guard1 = TRUE;
      } else if (CV_EML_COND(16, 0, 1, *c1_FA_ICE_STATE == 5.2)) {
        guard1 = TRUE;
      } else {
        CV_EML_MCDC(16, 0, 0, FALSE);
        CV_EML_IF(16, 0, 0, FALSE);
        c1_j_out = FALSE;
      }

      if (guard1 == TRUE) {
        CV_EML_MCDC(16, 0, 0, TRUE);
        CV_EML_IF(16, 0, 0, TRUE);
        c1_j_out = TRUE;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c1_j_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[3];
          unsigned int numTransitions = 1;
          transitionList[0] = 16;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_rb_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_k_out = (*c1_FA_ICE_STATE == 2.0);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_k_out) {
            transitionList[numTransitions] = 17;
            numTransitions++;
          }

          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_vb_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_l_out = (*c1_FA_ICE_STATE == 2.1);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_l_out) {
            transitionList[numTransitions] = 19;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_STATE_3 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_5;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_STATE_5 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_u_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_m_out = CV_EML_IF(17, 0, 0, *c1_FA_ICE_STATE == 2.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_m_out) {
          if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 17;
            _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_vb_debug_family_names,
              c1_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_nargin, 0U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_nargout, 1U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n_out, 2U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            c1_n_out = (*c1_FA_ICE_STATE == 2.1);
            _SFD_SYMBOL_SCOPE_POP();
            if (c1_n_out) {
              transitionList[numTransitions] = 19;
              numTransitions++;
            }

            _SFD_TRANSITION_CONFLICT_CHECK_END();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_STATE_3 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_22;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_STATE_22 = 1U;
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                       chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_y_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_o_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_o_out = CV_EML_IF(19, 0, 0, *c1_FA_ICE_STATE == 2.1);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_o_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_STATE_3 = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
            chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_21;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_STATE_21 = 1U;
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                         chartInstance->c1_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
              c1_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_p_nargin, 0U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_p_nargout, 1U,
              c1_sf_marshallOut, c1_sf_marshallIn);
            *c1_FA_GAS_CONSUMPTION = *c1_fa_conso_idle;
            c1_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_SYMBOL_SCOPE_POP();
          }
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
}

static void c1_STATE_22(SFc1_AxleSplitHEVv5InstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_d_out;
  boolean_T c1_b2;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_e_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 1.0;
  boolean_T c1_f_out;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_g_out;
  boolean_T c1_b3;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 1.0;
  boolean_T c1_h_out;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 1.0;
  boolean_T c1_i_out;
  boolean_T c1_b4;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 1.0;
  boolean_T c1_j_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 0.0;
  real_T *c1_FA_ICE_STATE;
  real_T *c1_FA_GAS_CONSUMPTION;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  c1_FA_ICE_STATE = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_FA_GAS_CONSUMPTION = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_m_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_out = CV_EML_IF(13, 0, 0, *c1_FA_ICE_STATE == 3.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[4];
      unsigned int numTransitions = 1;
      transitionList[0] = 13;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ub_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_b_out = (*c1_FA_ICE_STATE == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        transitionList[numTransitions] = 6;
        numTransitions++;
      }

      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ib_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_c_out = (*c1_FA_ICE_STATE == 4.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        transitionList[numTransitions] = 14;
        numTransitions++;
      }

      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_eb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      guard4 = FALSE;
      if (*c1_FA_ICE_STATE == 5.1) {
        guard4 = TRUE;
      } else if (*c1_FA_ICE_STATE == 5.2) {
        guard4 = TRUE;
      } else {
        c1_b2 = FALSE;
      }

      if (guard4 == TRUE) {
        c1_b2 = TRUE;
      }

      c1_d_out = c1_b2;
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_d_out) {
        transitionList[numTransitions] = 18;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_STATE_22 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_3;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_STATE_3 = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_x_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_e_out = CV_EML_IF(6, 0, 0, *c1_FA_ICE_STATE == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_e_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[3];
        unsigned int numTransitions = 1;
        transitionList[0] = 6;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ib_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_f_out = (*c1_FA_ICE_STATE == 4.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_f_out) {
          transitionList[numTransitions] = 14;
          numTransitions++;
        }

        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_eb_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        guard3 = FALSE;
        if (*c1_FA_ICE_STATE == 5.1) {
          guard3 = TRUE;
        } else if (*c1_FA_ICE_STATE == 5.2) {
          guard3 = TRUE;
        } else {
          c1_b3 = FALSE;
        }

        if (guard3 == TRUE) {
          c1_b3 = TRUE;
        }

        c1_g_out = c1_b3;
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_g_out) {
          transitionList[numTransitions] = 18;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_STATE_22 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_STATE_1 = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_l_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_h_out = CV_EML_IF(14, 0, 0, *c1_FA_ICE_STATE == 4.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_h_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 14;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_eb_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          guard2 = FALSE;
          if (*c1_FA_ICE_STATE == 5.1) {
            guard2 = TRUE;
          } else if (*c1_FA_ICE_STATE == 5.2) {
            guard2 = TRUE;
          } else {
            c1_b4 = FALSE;
          }

          if (guard2 == TRUE) {
            c1_b4 = TRUE;
          }

          c1_i_out = c1_b4;
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_i_out) {
            transitionList[numTransitions] = 18;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_STATE_22 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_4;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_STATE_4 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_h_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        guard1 = FALSE;
        if (CV_EML_COND(18, 0, 0, *c1_FA_ICE_STATE == 5.1)) {
          guard1 = TRUE;
        } else if (CV_EML_COND(18, 0, 1, *c1_FA_ICE_STATE == 5.2)) {
          guard1 = TRUE;
        } else {
          CV_EML_MCDC(18, 0, 0, FALSE);
          CV_EML_IF(18, 0, 0, FALSE);
          c1_j_out = FALSE;
        }

        if (guard1 == TRUE) {
          CV_EML_MCDC(18, 0, 0, TRUE);
          CV_EML_IF(18, 0, 0, TRUE);
          c1_j_out = TRUE;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c1_j_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_STATE_22 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_5;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_STATE_5 = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_c_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          *c1_FA_GAS_CONSUMPTION = 0.0;
          c1_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
}

static void c1_STATE_4(SFc1_AxleSplitHEVv5InstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  boolean_T c1_b5;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_e_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 1.0;
  boolean_T c1_f_out;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_g_out;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 1.0;
  boolean_T c1_h_out;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 1.0;
  boolean_T c1_i_out;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 1.0;
  boolean_T c1_j_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 0.0;
  real_T *c1_FA_ICE_STATE;
  real_T *c1_FA_GAS_CONSUMPTION;
  real_T *c1_fa_conso_idle;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c1_fa_conso_idle = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_FA_ICE_STATE = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_FA_GAS_CONSUMPTION = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_n_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_out = CV_EML_IF(10, 0, 0, *c1_FA_ICE_STATE == 3.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[4];
      unsigned int numTransitions = 1;
      transitionList[0] = 10;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_mb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      guard2 = FALSE;
      if (*c1_FA_ICE_STATE == 5.1) {
        guard2 = TRUE;
      } else if (*c1_FA_ICE_STATE == 5.2) {
        guard2 = TRUE;
      } else {
        c1_b5 = FALSE;
      }

      if (guard2 == TRUE) {
        c1_b5 = TRUE;
      }

      c1_b_out = c1_b5;
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        transitionList[numTransitions] = 3;
        numTransitions++;
      }

      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_xb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_c_out = (*c1_FA_ICE_STATE == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        transitionList[numTransitions] = 7;
        numTransitions++;
      }

      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_wb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_d_out = (*c1_FA_ICE_STATE == 2.1);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_d_out) {
        transitionList[numTransitions] = 20;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_STATE_4 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_3;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_STATE_3 = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_p_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    guard1 = FALSE;
    if (CV_EML_COND(3, 0, 0, *c1_FA_ICE_STATE == 5.1)) {
      guard1 = TRUE;
    } else if (CV_EML_COND(3, 0, 1, *c1_FA_ICE_STATE == 5.2)) {
      guard1 = TRUE;
    } else {
      CV_EML_MCDC(3, 0, 0, FALSE);
      CV_EML_IF(3, 0, 0, FALSE);
      c1_e_out = FALSE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(3, 0, 0, TRUE);
      CV_EML_IF(3, 0, 0, TRUE);
      c1_e_out = TRUE;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c1_e_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[3];
        unsigned int numTransitions = 1;
        transitionList[0] = 3;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_xb_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_f_out = (*c1_FA_ICE_STATE == 1.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_f_out) {
          transitionList[numTransitions] = 7;
          numTransitions++;
        }

        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_wb_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_g_out = (*c1_FA_ICE_STATE == 2.1);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_g_out) {
          transitionList[numTransitions] = 20;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_STATE_4 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_5;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_STATE_5 = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_bb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_h_out = CV_EML_IF(7, 0, 0, *c1_FA_ICE_STATE == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_h_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 7;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_wb_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_i_out = (*c1_FA_ICE_STATE == 2.1);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_i_out) {
            transitionList[numTransitions] = 20;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_STATE_4 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_STATE_1 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ab_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_j_out = CV_EML_IF(20, 0, 0, *c1_FA_ICE_STATE == 2.1);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_j_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_STATE_4 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_21;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_STATE_21 = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                       chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_d_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          *c1_FA_GAS_CONSUMPTION = *c1_fa_conso_idle;
          c1_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
}

static void c1_STATE_1(SFc1_AxleSplitHEVv5InstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_e_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 1.0;
  boolean_T c1_f_out;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_g_out;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 1.0;
  boolean_T c1_h_out;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 1.0;
  boolean_T c1_i_out;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 1.0;
  boolean_T c1_j_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 0.0;
  real_T *c1_FA_ICE_STATE;
  real_T *c1_FA_GAS_CONSUMPTION;
  c1_FA_ICE_STATE = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_FA_GAS_CONSUMPTION = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_t_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_out = CV_EML_IF(1, 0, 0, *c1_FA_ICE_STATE == 2.1);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[4];
      unsigned int numTransitions = 1;
      transitionList[0] = 1;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_db_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_b_out = (*c1_FA_ICE_STATE == 5.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        transitionList[numTransitions] = 8;
        numTransitions++;
      }

      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_gb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_c_out = (*c1_FA_ICE_STATE == 2.2);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        transitionList[numTransitions] = 21;
        numTransitions++;
      }

      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_fb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_d_out = (*c1_FA_ICE_STATE == 3.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_d_out) {
        transitionList[numTransitions] = 22;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_STATE_1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_21;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_STATE_21 = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_g_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_e_out = CV_EML_IF(8, 0, 0, *c1_FA_ICE_STATE == 5.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_e_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[3];
        unsigned int numTransitions = 1;
        transitionList[0] = 8;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_gb_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_f_out = (*c1_FA_ICE_STATE == 2.2);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_f_out) {
          transitionList[numTransitions] = 21;
          numTransitions++;
        }

        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_fb_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_g_out = (*c1_FA_ICE_STATE == 3.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_g_out) {
          transitionList[numTransitions] = 22;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_STATE_1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_5;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_STATE_5 = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_j_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_h_out = CV_EML_IF(21, 0, 0, *c1_FA_ICE_STATE == 2.2);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_h_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 21;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_fb_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_out, 2U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_i_out = (*c1_FA_ICE_STATE == 3.0);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_i_out) {
            transitionList[numTransitions] = 22;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_STATE_1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_22;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_STATE_22 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_i_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_j_out = CV_EML_IF(22, 0, 0, *c1_FA_ICE_STATE == 3.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_j_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_STATE_1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_c1_AxleSplitHEVv5 = c1_IN_STATE_3;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_STATE_3 = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                       chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_e_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          *c1_FA_GAS_CONSUMPTION = 0.0;
          c1_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc1_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_nargout, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc1_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc1_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static boolean_T c1_c_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b6;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b6, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b6;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_evilsf_internal_predicateOutput;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc1_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c1_evilsf_internal_predicateOutput = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_evilsf_internal_predicateOutput), &c1_thisId);
  sf_mex_destroy(&c1_evilsf_internal_predicateOutput);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_AxleSplitHEVv5_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc1_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc1_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc1_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_b_tp_STATE_3, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_STATE_3),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_STATE_3);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_STATE_3;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc1_AxleSplitHEVv5InstanceStruct *)chartInstanceVoid;
  c1_b_tp_STATE_3 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_STATE_3),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_STATE_3);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), FALSE);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_h_emlrt_marshallIn(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), FALSE);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_updateDataWrittenToVector(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance, uint32_T c1_vectorIndex)
{
  c1_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c1_vectorIndex, 0, 0, 1, 0)] = TRUE;
}

static void init_test_point_addr_map(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  chartInstance->c1_testPointAddrMap[0] = &chartInstance->c1_tp_STATE_1;
}

static void **get_test_point_address_map(SFc1_AxleSplitHEVv5InstanceStruct
  *chartInstance)
{
  return &chartInstance->c1_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc1_AxleSplitHEVv5InstanceStruct *chartInstance)
{
  return &chartInstance->c1_testPointMappingInfo;
}

static void init_dsm_address_info(SFc1_AxleSplitHEVv5InstanceStruct
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

static void init_test_point_mapping_info(SimStruct *S);
void sf_c1_AxleSplitHEVv5_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2237400794U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4170780359U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2664752114U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3213879881U);
}

mxArray *sf_c1_AxleSplitHEVv5_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("OXxIgQzEuLcG4Y8cNYE5cF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

mxArray *sf_c1_AxleSplitHEVv5_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_AxleSplitHEVv5(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[40],T\"FA_GAS_CONSUMPTION\",},{M[8],M[0],T\"is_active_c1_AxleSplitHEVv5\",},{M[9],M[0],T\"is_c1_AxleSplitHEVv5\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_AxleSplitHEVv5_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_AxleSplitHEVv5InstanceStruct *chartInstance;
    chartInstance = (SFc1_AxleSplitHEVv5InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AxleSplitHEVv5MachineNumber_,
           1,
           6,
           23,
           3,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"FA_GAS_CONSUMPTION");
          _SFD_SET_DATA_PROPS(1,1,1,0,"FA_ICE_STATE");
          _SFD_SET_DATA_PROPS(2,1,1,0,"fa_conso_idle");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_CH_SUBSTATE_COUNT(6);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_CH_SUBSTATE_INDEX(4,4);
          _SFD_CH_SUBSTATE_INDEX(5,5);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
        }

        _SFD_CV_INIT_CHART(6,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
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

        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,17,1,18);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(18,0,0,1,42,1,43);

        {
          static int condStart[] = { 3, 24 };

          static int condEnd[] = { 20, 41 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(18,0,0,2,42,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(22,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(22,0,0,1,17,1,18);
        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,1,19,1,20);
        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(16,0,0,1,42,1,43);

        {
          static int condStart[] = { 3, 24 };

          static int condEnd[] = { 20, 41 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(16,0,0,2,42,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,17,1,18);
        _SFD_CV_INIT_EML(2,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,17,1,18);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,17,1,18);
        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,1,19,1,20);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,42,1,43);

        {
          static int condStart[] = { 3, 24 };

          static int condEnd[] = { 20, 41 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,2,42,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,1,17,1,18);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,17,1,18);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,17,1,18);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,19,1,20);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,1,17,1,18);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,17,1,18);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,17,1,18);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,17,1,18);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,1,19,1,20);
        _SFD_CV_INIT_EML(20,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(20,0,0,1,19,1,20);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,17,1,18);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,17,1,18);
        _SFD_TRANS_COV_WTS(8,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(8,
                              0,NULL,NULL,
                              0,NULL,NULL,
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

        _SFD_TRANS_COV_WTS(22,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(22,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(21,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(21,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(16,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(16,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(14,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(14,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(13,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(13,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(10,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(10,
                              0,NULL,NULL,
                              0,NULL,NULL,
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

        _SFD_TRANS_COV_WTS(3,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(12,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(12,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(9,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(9,
                              0,NULL,NULL,
                              0,NULL,NULL,
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

        _SFD_TRANS_COV_WTS(1,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(17,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(17,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(11,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(11,
                              0,NULL,NULL,
                              0,NULL,NULL,
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

        _SFD_TRANS_COV_WTS(6,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(6,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(19,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(19,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(20,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(20,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(7,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(7,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(5,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(5,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_FA_GAS_CONSUMPTION;
          real_T *c1_FA_ICE_STATE;
          real_T *c1_fa_conso_idle;
          c1_fa_conso_idle = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_FA_ICE_STATE = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_FA_GAS_CONSUMPTION = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_FA_GAS_CONSUMPTION);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_FA_ICE_STATE);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_fa_conso_idle);
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
  return "O4OkN7YgruB2cOX9K8H8EG";
}

static void sf_opaque_initialize_c1_AxleSplitHEVv5(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_AxleSplitHEVv5InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_AxleSplitHEVv5((SFc1_AxleSplitHEVv5InstanceStruct*)
    chartInstanceVar);
  initialize_c1_AxleSplitHEVv5((SFc1_AxleSplitHEVv5InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_AxleSplitHEVv5(void *chartInstanceVar)
{
  enable_c1_AxleSplitHEVv5((SFc1_AxleSplitHEVv5InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_AxleSplitHEVv5(void *chartInstanceVar)
{
  disable_c1_AxleSplitHEVv5((SFc1_AxleSplitHEVv5InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_AxleSplitHEVv5(void *chartInstanceVar)
{
  sf_c1_AxleSplitHEVv5((SFc1_AxleSplitHEVv5InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_AxleSplitHEVv5(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_AxleSplitHEVv5
    ((SFc1_AxleSplitHEVv5InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_AxleSplitHEVv5();/* state var info */
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

extern void sf_internal_set_sim_state_c1_AxleSplitHEVv5(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_AxleSplitHEVv5();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_AxleSplitHEVv5((SFc1_AxleSplitHEVv5InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_AxleSplitHEVv5(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_AxleSplitHEVv5(S);
}

static void sf_opaque_set_sim_state_c1_AxleSplitHEVv5(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_AxleSplitHEVv5(S, st);
}

static void sf_opaque_terminate_c1_AxleSplitHEVv5(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_AxleSplitHEVv5InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AxleSplitHEVv5_optimization_info();
    }

    finalize_c1_AxleSplitHEVv5((SFc1_AxleSplitHEVv5InstanceStruct*)
      chartInstanceVar);
    if (!sim_mode_is_rtw_gen(S)) {
      ssSetModelMappingInfoPtr(S, NULL);
    }

    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_AxleSplitHEVv5((SFc1_AxleSplitHEVv5InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_AxleSplitHEVv5(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_AxleSplitHEVv5((SFc1_AxleSplitHEVv5InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_AxleSplitHEVv5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_AxleSplitHEVv5_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1627972192U));
  ssSetChecksum1(S,(129868489U));
  ssSetChecksum2(S,(3869730899U));
  ssSetChecksum3(S,(4229502221U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_AxleSplitHEVv5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_AxleSplitHEVv5(SimStruct *S)
{
  SFc1_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc1_AxleSplitHEVv5InstanceStruct *)utMalloc(sizeof
    (SFc1_AxleSplitHEVv5InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_AxleSplitHEVv5InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_AxleSplitHEVv5;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_AxleSplitHEVv5;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_AxleSplitHEVv5;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_AxleSplitHEVv5;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_AxleSplitHEVv5;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_AxleSplitHEVv5;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_AxleSplitHEVv5;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_AxleSplitHEVv5;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_AxleSplitHEVv5;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_AxleSplitHEVv5;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_AxleSplitHEVv5;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
    init_test_point_mapping_info(S);
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_AxleSplitHEVv5_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_AxleSplitHEVv5(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_AxleSplitHEVv5(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_AxleSplitHEVv5(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_AxleSplitHEVv5_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  { "uint8_T", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 } };

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0 } };

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_SCALAR, 0, 2 } };

static const uint_T dimensionArray[] = {
  1, 1 };

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  { &sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0 }
};

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  { 0, 0, "StateflowChart/STATE_1", "STATE_1", 0, 0, 0, 0, 0 } };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    1,                                 /* Num Block IO signals */
    NULL,                              /* Root Inputs Array    */
    0,                                 /* Num root inputs      */
    NULL,                              /* Root Outputs Array */
    0                                  /* Num root outputs   */
  },

  /* parameter tuning */
  {
    NULL,                              /* Block parameters Array    */
    0,                                 /* Num block parameters      */
    NULL,                              /* Variable parameters Array */
    0                                  /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                              /* Block States array        */
    0                                  /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                       /* Data Type Map            */
    dimensionMap,                      /* Data Dimension Map       */
    fixedPointMap,                     /* Fixed Point Map          */
    NULL,                              /* Structure Element map    */
    sampleTimeMap,                     /* Sample Times Map         */
    dimensionArray                     /* Dimension Array          */
  },

  /* Target type */
  "float"
};

static void init_test_point_mapping_info(SimStruct *S)
{
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;
  SFc1_AxleSplitHEVv5InstanceStruct *chartInstance;
  chartInstance = (SFc1_AxleSplitHEVv5InstanceStruct *) ((ChartInfoStruct *)
    (ssGetUserData(S)))->chartInstance;
  init_test_point_addr_map(chartInstance);
  testPointMappingInfo = get_test_point_mapping_info(chartInstance);
  testPointAddrMap = get_test_point_address_map(chartInstance);
  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetLoggingStaticMap(*testPointMappingInfo, NULL);
  rtwCAPI_SetInstanceLoggingInfo(*testPointMappingInfo, NULL);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);
  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
}
