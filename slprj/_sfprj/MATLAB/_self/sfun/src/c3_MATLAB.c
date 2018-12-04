/* Include files */

#include <stddef.h>
#include "blas.h"
#include "MATLAB_sfun.h"
#include "c3_MATLAB.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "MATLAB_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[41] = { "N", "Sp_elec", "Sp_therm",
  "te", "I_elec", "I_therm", "poly_therm", "poly_elec", "f", "g", "F", "G", "m",
  "opt_index", "Sp", "alpha_min", "alpha_max", "alpha", "S", "k", "T_therm",
  "T_elec", "p", "nargin", "nargout", "T", "V", "Tmax_elec", "Tmin_elec",
  "Tmax_therm", "Tmin_therm", "GBX", "SOC", "SP_elec", "SP_therm",
  "fa_differential_ratio", "fa_gearbox_ratio", "ra_differential_ratio",
  "Tab_poly_therm", "Tab_poly_elec", "alpha_opt" };

static const char * c3_b_debug_family_names[7] = { "valeur", "indice", "nargin",
  "nargout", "tab", "val", "I" };

static const char * c3_c_debug_family_names[7] = { "valeur", "indice", "nargin",
  "nargout", "tab", "val", "I" };

/* Function Declarations */
static void initialize_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance);
static void initialize_params_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance);
static void enable_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance);
static void disable_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_MATLAB(SFc3_MATLABInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_MATLAB(SFc3_MATLABInstanceStruct
  *chartInstance);
static void set_sim_state_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_st);
static void finalize_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance);
static void sf_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance);
static void c3_chartstep_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance);
static void initSimStructsc3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance);
static void registerMessagesc3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance);
static real_T c3_plus_proche(SFc3_MATLABInstanceStruct *chartInstance, real_T
  c3_tab[48], real_T c3_val);
static real_T c3_b_plus_proche(SFc3_MATLABInstanceStruct *chartInstance, real_T
  c3_tab[81], real_T c3_val);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_alpha_opt, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[567]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[336]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_e_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[7]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_f_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[48]);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_g_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[81]);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, real_T
  c3_inData_data[101], int32_T c3_inData_sizes[2]);
static void c3_h_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y_data
  [101], int32_T c3_y_sizes[2]);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, real_T c3_outData_data[101],
  int32_T c3_outData_sizes[2]);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_i_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[401]);
static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_j_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2800]);
static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[92]);
static void c3_b_info_helper(c3_ResolvedFunctionInfo c3_info[92]);
static void c3_eml_scalar_eg(SFc3_MATLABInstanceStruct *chartInstance);
static void c3_float_colon_length(SFc3_MATLABInstanceStruct *chartInstance,
  real_T c3_a, real_T c3_b, int32_T *c3_n, real_T *c3_anew, real_T *c3_bnew,
  boolean_T *c3_n_too_large);
static real_T c3_mpower(SFc3_MATLABInstanceStruct *chartInstance, real_T c3_a,
  real_T c3_b);
static void c3_eml_error(SFc3_MATLABInstanceStruct *chartInstance);
static void c3_sum(SFc3_MATLABInstanceStruct *chartInstance, real_T c3_x[2800],
                   real_T c3_y[7]);
static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_k_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_l_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_MATLAB, const char_T *c3_identifier);
static uint8_T c3_m_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_MATLABInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_MATLAB = 0U;
}

static void initialize_params_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance)
{
  real_T c3_dv0[81];
  int32_T c3_i0;
  real_T c3_dv1[48];
  int32_T c3_i1;
  real_T c3_d0;
  real_T c3_dv2[7];
  int32_T c3_i2;
  real_T c3_d1;
  real_T c3_dv3[336];
  int32_T c3_i3;
  real_T c3_dv4[567];
  int32_T c3_i4;
  sf_set_error_prefix_string(
    "Error evaluating data 'SP_elec' in the parent workspace.\n");
  sf_mex_import_named("SP_elec", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c3_dv0, 0, 0, 0U, 1, 0U, 2, 1, 81);
  for (c3_i0 = 0; c3_i0 < 81; c3_i0++) {
    chartInstance->c3_SP_elec[c3_i0] = c3_dv0[c3_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'SP_therm' in the parent workspace.\n");
  sf_mex_import_named("SP_therm", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      c3_dv1, 0, 0, 0U, 1, 0U, 2, 1, 48);
  for (c3_i1 = 0; c3_i1 < 48; c3_i1++) {
    chartInstance->c3_SP_therm[c3_i1] = c3_dv1[c3_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'fa_differential_ratio' in the parent workspace.\n");
  sf_mex_import_named("fa_differential_ratio", sf_mex_get_sfun_param
                      (chartInstance->S, 4, 0), &c3_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_fa_differential_ratio = c3_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'fa_gearbox_ratio' in the parent workspace.\n");
  sf_mex_import_named("fa_gearbox_ratio", sf_mex_get_sfun_param(chartInstance->S,
    5, 0), c3_dv2, 0, 0, 0U, 1, 0U, 2, 1, 7);
  for (c3_i2 = 0; c3_i2 < 7; c3_i2++) {
    chartInstance->c3_fa_gearbox_ratio[c3_i2] = c3_dv2[c3_i2];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'ra_differential_ratio' in the parent workspace.\n");
  sf_mex_import_named("ra_differential_ratio", sf_mex_get_sfun_param
                      (chartInstance->S, 6, 0), &c3_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_ra_differential_ratio = c3_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'Tab_poly_therm' in the parent workspace.\n");
  sf_mex_import_named("Tab_poly_therm", sf_mex_get_sfun_param(chartInstance->S,
    3, 0), c3_dv3, 0, 0, 0U, 1, 0U, 2, 48, 7);
  for (c3_i3 = 0; c3_i3 < 336; c3_i3++) {
    chartInstance->c3_Tab_poly_therm[c3_i3] = c3_dv3[c3_i3];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'Tab_poly_elec' in the parent workspace.\n");
  sf_mex_import_named("Tab_poly_elec", sf_mex_get_sfun_param(chartInstance->S, 2,
    0), c3_dv4, 0, 0, 0U, 1, 0U, 2, 81, 7);
  for (c3_i4 = 0; c3_i4 < 567; c3_i4++) {
    chartInstance->c3_Tab_poly_elec[c3_i4] = c3_dv4[c3_i4];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_MATLAB(SFc3_MATLABInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_MATLAB(SFc3_MATLABInstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T *c3_alpha_opt;
  c3_alpha_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  c3_hoistedGlobal = *c3_alpha_opt;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_active_c3_MATLAB;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_alpha_opt;
  c3_alpha_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_alpha_opt = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 0)), "alpha_opt");
  chartInstance->c3_is_active_c3_MATLAB = c3_l_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 1)), "is_active_c3_MATLAB");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_MATLAB(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance)
{
}

static void sf_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance)
{
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  real_T *c3_T;
  real_T *c3_alpha_opt;
  real_T *c3_V;
  real_T *c3_Tmax_elec;
  real_T *c3_Tmin_elec;
  real_T *c3_Tmax_therm;
  real_T *c3_Tmin_therm;
  real_T *c3_GBX;
  real_T *c3_SOC;
  c3_SOC = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_GBX = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_Tmin_therm = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_Tmax_therm = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_Tmin_elec = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_Tmax_elec = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_alpha_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_T, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_alpha_opt, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_V, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_Tmax_elec, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_Tmin_elec, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_Tmax_therm, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_Tmin_therm, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_GBX, 7U);
  _SFD_DATA_RANGE_CHECK(*c3_SOC, 8U);
  for (c3_i5 = 0; c3_i5 < 81; c3_i5++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_SP_elec[c3_i5], 9U);
  }

  for (c3_i6 = 0; c3_i6 < 48; c3_i6++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_SP_therm[c3_i6], 10U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c3_fa_differential_ratio, 11U);
  for (c3_i7 = 0; c3_i7 < 7; c3_i7++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_fa_gearbox_ratio[c3_i7], 12U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c3_ra_differential_ratio, 13U);
  for (c3_i8 = 0; c3_i8 < 336; c3_i8++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_Tab_poly_therm[c3_i8], 14U);
  }

  for (c3_i9 = 0; c3_i9 < 567; c3_i9++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_Tab_poly_elec[c3_i9], 15U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_MATLAB(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_MATLABMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_f_hoistedGlobal;
  real_T c3_g_hoistedGlobal;
  real_T c3_h_hoistedGlobal;
  real_T c3_i_hoistedGlobal;
  real_T c3_j_hoistedGlobal;
  real_T c3_T;
  real_T c3_V;
  real_T c3_Tmax_elec;
  real_T c3_Tmin_elec;
  real_T c3_Tmax_therm;
  real_T c3_Tmin_therm;
  real_T c3_GBX;
  real_T c3_SOC;
  int32_T c3_i10;
  real_T c3_b_SP_elec[81];
  int32_T c3_i11;
  real_T c3_b_SP_therm[48];
  real_T c3_b_fa_differential_ratio;
  int32_T c3_i12;
  real_T c3_b_fa_gearbox_ratio[7];
  real_T c3_b_ra_differential_ratio;
  int32_T c3_i13;
  real_T c3_b_Tab_poly_therm[336];
  int32_T c3_i14;
  real_T c3_b_Tab_poly_elec[567];
  uint32_T c3_debug_family_var_map[41];
  real_T c3_N;
  real_T c3_Sp_elec[401];
  real_T c3_Sp_therm[401];
  real_T c3_te;
  real_T c3_I_elec;
  real_T c3_I_therm;
  real_T c3_poly_therm[7];
  real_T c3_poly_elec[7];
  real_T c3_f[2800];
  real_T c3_g[2800];
  real_T c3_F[7];
  real_T c3_G[7];
  real_T c3_m;
  real_T c3_opt_index;
  real_T c3_Sp[401];
  real_T c3_alpha_min;
  real_T c3_alpha_max;
  int32_T c3_alpha_sizes[2];
  real_T c3_alpha_data[101];
  int32_T c3_S_sizes[2];
  real_T c3_S_data[101];
  real_T c3_k;
  real_T c3_T_therm;
  real_T c3_T_elec;
  real_T c3_p;
  real_T c3_nargin = 15.0;
  real_T c3_nargout = 1.0;
  real_T c3_alpha_opt;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  real_T c3_A;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_y;
  real_T c3_b_A;
  real_T c3_B;
  real_T c3_c_x;
  real_T c3_b_y;
  real_T c3_d_x;
  real_T c3_c_y;
  real_T c3_d_y;
  real_T c3_c_A;
  real_T c3_b_B;
  real_T c3_e_x;
  real_T c3_e_y;
  real_T c3_f_x;
  real_T c3_f_y;
  real_T c3_g_y;
  real_T c3_varargin_1;
  real_T c3_varargin_2;
  real_T c3_b_varargin_2;
  real_T c3_varargin_3;
  real_T c3_g_x;
  real_T c3_h_y;
  real_T c3_h_x;
  real_T c3_i_y;
  real_T c3_xk;
  real_T c3_yk;
  real_T c3_i_x;
  real_T c3_j_y;
  real_T c3_maxval;
  real_T c3_c_varargin_2;
  real_T c3_b_varargin_3;
  real_T c3_k_y;
  real_T c3_l_y;
  real_T c3_b_yk;
  real_T c3_m_y;
  real_T c3_d_A;
  real_T c3_c_B;
  real_T c3_j_x;
  real_T c3_n_y;
  real_T c3_k_x;
  real_T c3_o_y;
  real_T c3_p_y;
  real_T c3_e_A;
  real_T c3_d_B;
  real_T c3_l_x;
  real_T c3_q_y;
  real_T c3_m_x;
  real_T c3_r_y;
  real_T c3_s_y;
  real_T c3_b_varargin_1;
  real_T c3_d_varargin_2;
  real_T c3_e_varargin_2;
  real_T c3_c_varargin_3;
  real_T c3_n_x;
  real_T c3_t_y;
  real_T c3_o_x;
  real_T c3_u_y;
  real_T c3_b_xk;
  real_T c3_c_yk;
  real_T c3_p_x;
  real_T c3_v_y;
  real_T c3_minval;
  real_T c3_f_varargin_2;
  real_T c3_d_varargin_3;
  real_T c3_w_y;
  real_T c3_x_y;
  real_T c3_d_yk;
  real_T c3_y_y;
  real_T c3_a;
  real_T c3_b;
  real_T c3_b_a;
  real_T c3_b_b;
  boolean_T c3_n_too_large;
  real_T c3_bnew;
  real_T c3_anew;
  int32_T c3_n;
  int32_T c3_b_n;
  real_T c3_b_anew;
  real_T c3_b_bnew;
  boolean_T c3_b_n_too_large;
  boolean_T c3_b_p;
  int32_T c3_i24;
  static char_T c3_cv0[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  char_T c3_u[21];
  const mxArray *c3_ab_y = NULL;
  int32_T c3_x_sizes[2];
  int32_T c3_iv0[2];
  int32_T c3_q_x;
  int32_T c3_r_x;
  int32_T c3_loop_ub;
  int32_T c3_i25;
  real_T c3_x_data[101];
  int32_T c3_i26;
  int32_T c3_c_a;
  int32_T c3_nm1;
  int32_T c3_d_a;
  int32_T c3_i27;
  int32_T c3_nm1d2;
  int32_T c3_e_a;
  int32_T c3_i28;
  int32_T c3_b_k;
  int32_T c3_c_k;
  real_T c3_f_a;
  real_T c3_kd;
  int32_T c3_g_a;
  int32_T c3_c;
  int32_T c3_h_a;
  int32_T c3_c_b;
  int32_T c3_b_c;
  int32_T c3_d_b;
  int32_T c3_c_c;
  int32_T c3_i_a;
  int32_T c3_d_c;
  real_T c3_j_a;
  int32_T c3_k_a;
  int32_T c3_e_c;
  int32_T c3_l_a;
  int32_T c3_f_c;
  int32_T c3_s_x;
  int32_T c3_t_x;
  int32_T c3_b_loop_ub;
  int32_T c3_i29;
  real_T c3_c_n;
  int32_T c3_iv1[2];
  int32_T c3_S;
  int32_T c3_b_S;
  int32_T c3_c_loop_ub;
  int32_T c3_i30;
  int32_T c3_d_k;
  real_T c3_m_a;
  real_T c3_bb_y;
  int32_T c3_i31;
  real_T c3_n_a[401];
  real_T c3_e_b;
  int32_T c3_i32;
  real_T c3_o_a;
  real_T c3_f_b;
  real_T c3_cb_y;
  int32_T c3_i33;
  real_T c3_g_b;
  int32_T c3_i34;
  real_T c3_p_a;
  real_T c3_h_b;
  real_T c3_db_y;
  real_T c3_f_A;
  real_T c3_e_B;
  real_T c3_u_x;
  real_T c3_eb_y;
  real_T c3_v_x;
  real_T c3_fb_y;
  real_T c3_g_A;
  real_T c3_f_B;
  real_T c3_w_x;
  real_T c3_gb_y;
  real_T c3_x_x;
  real_T c3_hb_y;
  int32_T c3_e_k;
  real_T c3_q_a;
  real_T c3_ib_y;
  int32_T c3_i35;
  real_T c3_c_SP_therm[48];
  real_T c3_r_a;
  real_T c3_jb_y;
  int32_T c3_i36;
  real_T c3_c_SP_elec[81];
  int32_T c3_b_I_therm;
  int32_T c3_i37;
  int32_T c3_b_I_elec;
  int32_T c3_i38;
  int32_T c3_c_p;
  real_T c3_s_a;
  real_T c3_i_b;
  real_T c3_kb_y;
  real_T c3_t_a;
  real_T c3_j_b;
  real_T c3_lb_y;
  int32_T c3_f_k;
  int32_T c3_i39;
  int32_T c3_g_k;
  int32_T c3_i40;
  int32_T c3_i41;
  real_T c3_b_f[2800];
  real_T c3_dv5[7];
  int32_T c3_i42;
  int32_T c3_i43;
  real_T c3_b_g[2800];
  real_T c3_dv6[7];
  int32_T c3_i44;
  int32_T c3_y_x;
  int32_T c3_ab_x;
  int32_T c3_d_loop_ub;
  int32_T c3_i45;
  real_T c3_d2;
  int32_T c3_i46;
  int32_T c3_h_k;
  int32_T c3_d_p;
  real_T c3_u_a;
  real_T c3_k_b;
  real_T c3_mb_y;
  real_T c3_v_a;
  real_T c3_l_b;
  real_T c3_nb_y;
  real_T c3_w_a;
  real_T c3_m_b;
  real_T c3_ob_y;
  real_T c3_x_a;
  real_T c3_n_b;
  real_T c3_pb_y;
  int32_T c3_bb_x;
  int32_T c3_cb_x;
  int32_T c3_e_loop_ub;
  int32_T c3_i47;
  boolean_T c3_b0;
  boolean_T c3_b1;
  int32_T c3_i48;
  static char_T c3_cv1[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  char_T c3_b_u[36];
  const mxArray *c3_qb_y = NULL;
  int32_T c3_i49;
  static char_T c3_cv2[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  char_T c3_c_u[39];
  const mxArray *c3_rb_y = NULL;
  int32_T c3_ixstart;
  int32_T c3_d_n;
  int32_T c3_ixstop;
  real_T c3_mtmp;
  int32_T c3_itmp;
  real_T c3_db_x;
  boolean_T c3_o_b;
  int32_T c3_b_ixstop;
  int32_T c3_ix;
  int32_T c3_b_ix;
  real_T c3_eb_x;
  boolean_T c3_p_b;
  int32_T c3_y_a;
  int32_T c3_i50;
  int32_T c3_c_ixstop;
  int32_T c3_c_ix;
  real_T c3_ab_a;
  real_T c3_q_b;
  boolean_T c3_e_p;
  real_T c3_b_mtmp;
  int32_T c3_b_itmp;
  real_T c3_extremum;
  int32_T c3_iindx;
  real_T c3_b_minval;
  int32_T c3_b_iindx;
  real_T c3_indx;
  real_T c3_b_m;
  real_T c3_b_opt_index;
  real_T *c3_b_SOC;
  real_T *c3_b_GBX;
  real_T *c3_b_Tmin_therm;
  real_T *c3_b_Tmax_therm;
  real_T *c3_b_Tmin_elec;
  real_T *c3_b_Tmax_elec;
  real_T *c3_b_V;
  real_T *c3_b_T;
  real_T *c3_b_alpha_opt;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T exitg1;
  c3_b_SOC = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_b_GBX = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_b_Tmin_therm = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_Tmax_therm = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_Tmin_elec = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_Tmax_elec = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_alpha_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_T;
  c3_b_hoistedGlobal = *c3_b_V;
  c3_c_hoistedGlobal = *c3_b_Tmax_elec;
  c3_d_hoistedGlobal = *c3_b_Tmin_elec;
  c3_e_hoistedGlobal = *c3_b_Tmax_therm;
  c3_f_hoistedGlobal = *c3_b_Tmin_therm;
  c3_g_hoistedGlobal = *c3_b_GBX;
  c3_h_hoistedGlobal = *c3_b_SOC;
  c3_i_hoistedGlobal = chartInstance->c3_fa_differential_ratio;
  c3_j_hoistedGlobal = chartInstance->c3_ra_differential_ratio;
  c3_T = c3_hoistedGlobal;
  c3_V = c3_b_hoistedGlobal;
  c3_Tmax_elec = c3_c_hoistedGlobal;
  c3_Tmin_elec = c3_d_hoistedGlobal;
  c3_Tmax_therm = c3_e_hoistedGlobal;
  c3_Tmin_therm = c3_f_hoistedGlobal;
  c3_GBX = c3_g_hoistedGlobal;
  c3_SOC = c3_h_hoistedGlobal;
  for (c3_i10 = 0; c3_i10 < 81; c3_i10++) {
    c3_b_SP_elec[c3_i10] = chartInstance->c3_SP_elec[c3_i10];
  }

  for (c3_i11 = 0; c3_i11 < 48; c3_i11++) {
    c3_b_SP_therm[c3_i11] = chartInstance->c3_SP_therm[c3_i11];
  }

  c3_b_fa_differential_ratio = c3_i_hoistedGlobal;
  for (c3_i12 = 0; c3_i12 < 7; c3_i12++) {
    c3_b_fa_gearbox_ratio[c3_i12] = chartInstance->c3_fa_gearbox_ratio[c3_i12];
  }

  c3_b_ra_differential_ratio = c3_j_hoistedGlobal;
  for (c3_i13 = 0; c3_i13 < 336; c3_i13++) {
    c3_b_Tab_poly_therm[c3_i13] = chartInstance->c3_Tab_poly_therm[c3_i13];
  }

  for (c3_i14 = 0; c3_i14 < 567; c3_i14++) {
    c3_b_Tab_poly_elec[c3_i14] = chartInstance->c3_Tab_poly_elec[c3_i14];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 41U, 41U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_N, 0U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_Sp_elec, 1U, c3_h_sf_marshallOut,
    c3_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_Sp_therm, 2U, c3_h_sf_marshallOut,
    c3_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_te, 3U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_I_elec, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_I_therm, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_poly_therm, 6U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_poly_elec, 7U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_f, 8U, c3_i_sf_marshallOut,
    c3_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_g, 9U, c3_i_sf_marshallOut,
    c3_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_F, 10U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_G, 11U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m, 12U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_opt_index, 13U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_Sp, 14U, c3_h_sf_marshallOut,
    c3_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_alpha_min, 15U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_alpha_max, 16U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c3_alpha_data, (const int32_T *)
    &c3_alpha_sizes, NULL, 0, 17, (void *)c3_g_sf_marshallOut, (void *)
    c3_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c3_S_data, (const int32_T *)
    &c3_S_sizes, NULL, 0, 18, (void *)c3_g_sf_marshallOut, (void *)
    c3_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k, 19U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_T_therm, 20U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_T_elec, 21U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_p, 22U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 23U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 24U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_T, 25U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_V, 26U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Tmax_elec, 27U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Tmin_elec, 28U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Tmax_therm, 29U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Tmin_therm, 30U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_GBX, 31U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_SOC, 32U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_SP_elec, 33U, c3_f_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_SP_therm, 34U, c3_e_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_fa_differential_ratio, 35U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_fa_gearbox_ratio, 36U,
    c3_d_sf_marshallOut, c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_ra_differential_ratio, 37U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_Tab_poly_therm, 38U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_Tab_poly_elec, 39U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_alpha_opt, 40U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
  c3_N = 400.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 31);
  for (c3_i15 = 0; c3_i15 < 401; c3_i15++) {
    c3_Sp_elec[c3_i15] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
  for (c3_i16 = 0; c3_i16 < 401; c3_i16++) {
    c3_Sp_therm[c3_i16] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 33);
  c3_te = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
  c3_I_elec = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 35);
  c3_I_therm = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 36);
  for (c3_i17 = 0; c3_i17 < 7; c3_i17++) {
    c3_poly_therm[c3_i17] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
  for (c3_i18 = 0; c3_i18 < 7; c3_i18++) {
    c3_poly_elec[c3_i18] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 38);
  for (c3_i19 = 0; c3_i19 < 2800; c3_i19++) {
    c3_f[c3_i19] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 39);
  for (c3_i20 = 0; c3_i20 < 2800; c3_i20++) {
    c3_g[c3_i20] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
  for (c3_i21 = 0; c3_i21 < 7; c3_i21++) {
    c3_F[c3_i21] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
  for (c3_i22 = 0; c3_i22 < 7; c3_i22++) {
    c3_G[c3_i22] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 42);
  c3_m = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 43);
  c3_alpha_opt = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 44);
  c3_opt_index = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 45);
  for (c3_i23 = 0; c3_i23 < 401; c3_i23++) {
    c3_Sp[c3_i23] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 47);
  c3_A = c3_V;
  c3_x = c3_A;
  c3_b_x = c3_x;
  c3_y = c3_b_x / 9.5492965855137211;
  c3_Sp[0] = c3_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 53);
  c3_b_A = c3_Tmax_elec;
  c3_B = c3_T;
  c3_c_x = c3_b_A;
  c3_b_y = c3_B;
  c3_d_x = c3_c_x;
  c3_c_y = c3_b_y;
  c3_d_y = c3_d_x / c3_c_y;
  c3_c_A = c3_Tmin_therm;
  c3_b_B = c3_T;
  c3_e_x = c3_c_A;
  c3_e_y = c3_b_B;
  c3_f_x = c3_e_x;
  c3_f_y = c3_e_y;
  c3_g_y = c3_f_x / c3_f_y;
  c3_varargin_1 = 1.0 - c3_d_y;
  c3_varargin_2 = c3_g_y;
  c3_b_varargin_2 = c3_varargin_1;
  c3_varargin_3 = c3_varargin_2;
  c3_g_x = c3_b_varargin_2;
  c3_h_y = c3_varargin_3;
  c3_h_x = c3_g_x;
  c3_i_y = c3_h_y;
  c3_eml_scalar_eg(chartInstance);
  c3_xk = c3_h_x;
  c3_yk = c3_i_y;
  c3_i_x = c3_xk;
  c3_j_y = c3_yk;
  c3_eml_scalar_eg(chartInstance);
  c3_maxval = muDoubleScalarMax(c3_i_x, c3_j_y);
  c3_c_varargin_2 = c3_maxval;
  c3_b_varargin_3 = c3_c_varargin_2;
  c3_k_y = c3_b_varargin_3;
  c3_l_y = c3_k_y;
  c3_eml_scalar_eg(chartInstance);
  c3_b_yk = c3_l_y;
  c3_m_y = c3_b_yk;
  c3_eml_scalar_eg(chartInstance);
  c3_alpha_min = muDoubleScalarMax(0.0, c3_m_y);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 54);
  c3_d_A = c3_Tmin_elec;
  c3_c_B = c3_T;
  c3_j_x = c3_d_A;
  c3_n_y = c3_c_B;
  c3_k_x = c3_j_x;
  c3_o_y = c3_n_y;
  c3_p_y = c3_k_x / c3_o_y;
  c3_e_A = c3_Tmax_therm;
  c3_d_B = c3_T;
  c3_l_x = c3_e_A;
  c3_q_y = c3_d_B;
  c3_m_x = c3_l_x;
  c3_r_y = c3_q_y;
  c3_s_y = c3_m_x / c3_r_y;
  c3_b_varargin_1 = 1.0 - c3_p_y;
  c3_d_varargin_2 = c3_s_y;
  c3_e_varargin_2 = c3_b_varargin_1;
  c3_c_varargin_3 = c3_d_varargin_2;
  c3_n_x = c3_e_varargin_2;
  c3_t_y = c3_c_varargin_3;
  c3_o_x = c3_n_x;
  c3_u_y = c3_t_y;
  c3_eml_scalar_eg(chartInstance);
  c3_b_xk = c3_o_x;
  c3_c_yk = c3_u_y;
  c3_p_x = c3_b_xk;
  c3_v_y = c3_c_yk;
  c3_eml_scalar_eg(chartInstance);
  c3_minval = muDoubleScalarMin(c3_p_x, c3_v_y);
  c3_f_varargin_2 = c3_minval;
  c3_d_varargin_3 = c3_f_varargin_2;
  c3_w_y = c3_d_varargin_3;
  c3_x_y = c3_w_y;
  c3_eml_scalar_eg(chartInstance);
  c3_d_yk = c3_x_y;
  c3_y_y = c3_d_yk;
  c3_eml_scalar_eg(chartInstance);
  c3_alpha_max = muDoubleScalarMin(1.0, c3_y_y);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 58);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 0, c3_alpha_max < c3_alpha_min)) {
    guard1 = TRUE;
  } else if (CV_EML_COND(0, 1, 1, c3_GBX == 0.0)) {
    guard1 = TRUE;
  } else {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 62);
    c3_a = c3_alpha_min;
    c3_b = c3_alpha_max;
    c3_b_a = c3_a;
    c3_b_b = c3_b;
    c3_float_colon_length(chartInstance, c3_b_a, c3_b_b, &c3_n, &c3_anew,
                          &c3_bnew, &c3_n_too_large);
    c3_b_n = c3_n;
    c3_b_anew = c3_anew;
    c3_b_bnew = c3_bnew;
    c3_b_n_too_large = c3_n_too_large;
    c3_b_p = !c3_b_n_too_large;
    if (c3_b_p) {
    } else {
      for (c3_i24 = 0; c3_i24 < 21; c3_i24++) {
        c3_u[c3_i24] = c3_cv0[c3_i24];
      }

      c3_ab_y = NULL;
      sf_mex_assign(&c3_ab_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 21),
                    FALSE);
      sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
        14, c3_ab_y));
    }

    c3_x_sizes[0] = 1;
    c3_iv0[0] = 1;
    c3_iv0[1] = c3_b_n;
    c3_x_sizes[1] = c3_iv0[1];
    c3_q_x = c3_x_sizes[0];
    c3_r_x = c3_x_sizes[1];
    c3_loop_ub = c3_b_n - 1;
    for (c3_i25 = 0; c3_i25 <= c3_loop_ub; c3_i25++) {
      c3_x_data[c3_i25] = 0.0;
    }

    for (c3_i26 = 0; c3_i26 < 2; c3_i26++) {
      c3_alpha_sizes[c3_i26] = c3_x_sizes[c3_i26];
    }

    if (c3_b_n > 0) {
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c3_alpha_sizes[1], 1, 0);
      c3_alpha_data[0] = c3_b_anew;
      if (c3_b_n > 1) {
        c3_alpha_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_b_n, 1, c3_alpha_sizes
          [1], 1, 0) - 1] = c3_b_bnew;
        c3_c_a = c3_b_n - 1;
        c3_nm1 = c3_c_a;
        c3_d_a = c3_nm1;
        c3_i27 = c3_d_a;
        c3_nm1d2 = (c3_i27 + (c3_i27 < 0)) >> 1;
        c3_e_a = c3_nm1d2 - 1;
        c3_i28 = c3_e_a;
        for (c3_b_k = 1; c3_b_k <= c3_i28; c3_b_k++) {
          c3_c_k = c3_b_k;
          c3_f_a = (real_T)c3_c_k;
          c3_kd = c3_f_a * 0.01;
          c3_g_a = c3_c_k + 1;
          c3_c = c3_g_a;
          c3_alpha_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_c, 1, c3_alpha_sizes
            [1], 1, 0) - 1] = c3_b_anew + c3_kd;
          c3_h_a = c3_b_n;
          c3_c_b = c3_c_k;
          c3_b_c = c3_h_a - c3_c_b;
          c3_alpha_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_b_c, 1,
            c3_alpha_sizes[1], 1, 0) - 1] = c3_b_bnew - c3_kd;
        }

        c3_d_b = c3_nm1d2;
        c3_c_c = c3_d_b << 1;
        if (c3_c_c == c3_nm1) {
          c3_i_a = c3_nm1d2 + 1;
          c3_d_c = c3_i_a;
          c3_alpha_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_d_c, 1,
            c3_alpha_sizes[1], 1, 0) - 1] = (c3_b_anew + c3_b_bnew) / 2.0;
        } else {
          c3_j_a = (real_T)c3_nm1d2;
          c3_kd = c3_j_a * 0.01;
          c3_k_a = c3_nm1d2 + 1;
          c3_e_c = c3_k_a;
          c3_alpha_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_e_c, 1,
            c3_alpha_sizes[1], 1, 0) - 1] = c3_b_anew + c3_kd;
          c3_l_a = c3_nm1d2 + 2;
          c3_f_c = c3_l_a;
          c3_alpha_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_f_c, 1,
            c3_alpha_sizes[1], 1, 0) - 1] = c3_b_bnew - c3_kd;
        }
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 64);
    c3_x_sizes[0] = 1;
    c3_x_sizes[1] = c3_alpha_sizes[1];
    c3_s_x = c3_x_sizes[0];
    c3_t_x = c3_x_sizes[1];
    c3_b_loop_ub = c3_alpha_sizes[0] * c3_alpha_sizes[1] - 1;
    for (c3_i29 = 0; c3_i29 <= c3_b_loop_ub; c3_i29++) {
      c3_x_data[c3_i29] = c3_alpha_data[c3_i29];
    }

    c3_c_n = (real_T)c3_x_sizes[1];
    c3_S_sizes[0] = 1;
    c3_iv1[0] = 1;
    c3_iv1[1] = (int32_T)c3_c_n;
    c3_S_sizes[1] = c3_iv1[1];
    c3_S = c3_S_sizes[0];
    c3_b_S = c3_S_sizes[1];
    c3_c_loop_ub = (int32_T)c3_c_n - 1;
    for (c3_i30 = 0; c3_i30 <= c3_c_loop_ub; c3_i30++) {
      c3_S_data[c3_i30] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 67);
    c3_k = 1.0;
    c3_d_k = 0;
    while (c3_d_k < 400) {
      c3_k = 1.0 + (real_T)c3_d_k;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 68);
      c3_m_a = c3_T;
      c3_bb_y = c3_m_a * 0.01;
      c3_Sp[(int32_T)(c3_k + 1.0) - 1] = c3_bb_y + c3_Sp[(int32_T)c3_k - 1];
      c3_d_k++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 71);
    for (c3_i31 = 0; c3_i31 < 401; c3_i31++) {
      c3_n_a[c3_i31] = c3_Sp[c3_i31];
    }

    c3_e_b = c3_b_ra_differential_ratio;
    for (c3_i32 = 0; c3_i32 < 401; c3_i32++) {
      c3_Sp_elec[c3_i32] = c3_n_a[c3_i32] * c3_e_b;
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 72);
    c3_o_a = c3_b_fa_differential_ratio;
    c3_f_b = c3_b_fa_gearbox_ratio[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "fa_gearbox_ratio", (int32_T)_SFD_INTEGER_CHECK("GBX+1", c3_GBX + 1.0), 1,
      7, 1, 0) - 1];
    c3_cb_y = c3_o_a * c3_f_b;
    for (c3_i33 = 0; c3_i33 < 401; c3_i33++) {
      c3_n_a[c3_i33] = c3_Sp[c3_i33];
    }

    c3_g_b = c3_cb_y;
    for (c3_i34 = 0; c3_i34 < 401; c3_i34++) {
      c3_Sp_therm[c3_i34] = c3_n_a[c3_i34] * c3_g_b;
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 77);
    c3_p_a = c3_b_fa_differential_ratio;
    c3_h_b = c3_b_fa_gearbox_ratio[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "fa_gearbox_ratio", (int32_T)_SFD_INTEGER_CHECK("GBX+1", c3_GBX + 1.0), 1,
      7, 1, 0) - 1];
    c3_db_y = c3_p_a * c3_h_b;
    c3_f_A = c3_T;
    c3_e_B = c3_db_y;
    c3_u_x = c3_f_A;
    c3_eb_y = c3_e_B;
    c3_v_x = c3_u_x;
    c3_fb_y = c3_eb_y;
    c3_T_therm = c3_v_x / c3_fb_y;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 78);
    c3_g_A = c3_T;
    c3_f_B = c3_b_ra_differential_ratio;
    c3_w_x = c3_g_A;
    c3_gb_y = c3_f_B;
    c3_x_x = c3_w_x;
    c3_hb_y = c3_gb_y;
    c3_T_elec = c3_x_x / c3_hb_y;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 81);
    c3_k = 1.0;
    c3_e_k = 0;
    while (c3_e_k < 400) {
      c3_k = 1.0 + (real_T)c3_e_k;
      CV_EML_FOR(0, 1, 1, 1);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 83);
      c3_q_a = c3_Sp_therm[(int32_T)c3_k - 1];
      c3_ib_y = c3_q_a * 9.5492965855137211;
      for (c3_i35 = 0; c3_i35 < 48; c3_i35++) {
        c3_c_SP_therm[c3_i35] = c3_b_SP_therm[c3_i35];
      }

      c3_I_therm = c3_plus_proche(chartInstance, c3_c_SP_therm, c3_ib_y);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 84);
      c3_r_a = c3_Sp_elec[(int32_T)c3_k - 1];
      c3_jb_y = c3_r_a * 9.5492965855137211;
      for (c3_i36 = 0; c3_i36 < 81; c3_i36++) {
        c3_c_SP_elec[c3_i36] = c3_b_SP_elec[c3_i36];
      }

      c3_I_elec = c3_b_plus_proche(chartInstance, c3_c_SP_elec, c3_jb_y);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 87);
      c3_b_I_therm = (int32_T)c3_I_therm - 1;
      for (c3_i37 = 0; c3_i37 < 7; c3_i37++) {
        c3_poly_therm[c3_i37] = c3_b_Tab_poly_therm[c3_b_I_therm + 48 * c3_i37];
      }

      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 88);
      c3_b_I_elec = (int32_T)c3_I_elec - 1;
      for (c3_i38 = 0; c3_i38 < 7; c3_i38++) {
        c3_poly_elec[c3_i38] = c3_b_Tab_poly_elec[c3_b_I_elec + 81 * c3_i38];
      }

      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 91);
      c3_p = 1.0;
      c3_c_p = 0;
      while (c3_c_p < 7) {
        c3_p = 1.0 + (real_T)c3_c_p;
        CV_EML_FOR(0, 1, 2, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 92);
        c3_s_a = c3_poly_therm[(int32_T)c3_p - 1];
        c3_i_b = c3_mpower(chartInstance, c3_T_therm, 7.0 - c3_p);
        c3_kb_y = c3_s_a * c3_i_b;
        c3_poly_therm[(int32_T)c3_p - 1] = c3_kb_y;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 93);
        c3_t_a = c3_poly_elec[(int32_T)c3_p - 1];
        c3_j_b = c3_mpower(chartInstance, c3_T_elec, 7.0 - c3_p);
        c3_lb_y = c3_t_a * c3_j_b;
        c3_poly_elec[(int32_T)c3_p - 1] = c3_lb_y;
        c3_c_p++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 2, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 96);
      c3_f_k = (int32_T)c3_k - 1;
      for (c3_i39 = 0; c3_i39 < 7; c3_i39++) {
        c3_f[c3_f_k + 400 * c3_i39] = c3_poly_therm[c3_i39];
      }

      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 97);
      c3_g_k = (int32_T)c3_k - 1;
      for (c3_i40 = 0; c3_i40 < 7; c3_i40++) {
        c3_g[c3_g_k + 400 * c3_i40] = -c3_poly_elec[c3_i40];
      }

      c3_e_k++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 1, 0);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 102);
    for (c3_i41 = 0; c3_i41 < 2800; c3_i41++) {
      c3_b_f[c3_i41] = c3_f[c3_i41];
    }

    c3_sum(chartInstance, c3_b_f, c3_dv5);
    for (c3_i42 = 0; c3_i42 < 7; c3_i42++) {
      c3_F[c3_i42] = c3_dv5[c3_i42];
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 103);
    for (c3_i43 = 0; c3_i43 < 2800; c3_i43++) {
      c3_b_g[c3_i43] = c3_g[c3_i43];
    }

    c3_sum(chartInstance, c3_b_g, c3_dv6);
    for (c3_i44 = 0; c3_i44 < 7; c3_i44++) {
      c3_G[c3_i44] = c3_dv6[c3_i44];
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 108);
    c3_x_sizes[0] = 1;
    c3_x_sizes[1] = c3_alpha_sizes[1];
    c3_y_x = c3_x_sizes[0];
    c3_ab_x = c3_x_sizes[1];
    c3_d_loop_ub = c3_alpha_sizes[0] * c3_alpha_sizes[1] - 1;
    for (c3_i45 = 0; c3_i45 <= c3_d_loop_ub; c3_i45++) {
      c3_x_data[c3_i45] = c3_alpha_data[c3_i45];
    }

    c3_d2 = (real_T)c3_x_sizes[1];
    c3_i46 = (int32_T)c3_d2 - 1;
    c3_k = 1.0;
    c3_h_k = 0;
    while (c3_h_k <= c3_i46) {
      c3_k = 1.0 + (real_T)c3_h_k;
      CV_EML_FOR(0, 1, 3, 1);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 109);
      c3_p = 1.0;
      c3_d_p = 0;
      while (c3_d_p < 7) {
        c3_p = 1.0 + (real_T)c3_d_p;
        CV_EML_FOR(0, 1, 4, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 110);
        c3_u_a = c3_SOC;
        c3_k_b = c3_F[(int32_T)c3_p - 1];
        c3_mb_y = c3_u_a * c3_k_b;
        c3_v_a = c3_mb_y;
        c3_l_b = c3_mpower(chartInstance, c3_alpha_data[(int32_T)(real_T)
                           _SFD_EML_ARRAY_BOUNDS_CHECK("alpha", (int32_T)c3_k, 1,
          c3_alpha_sizes[1], 1, 0) - 1], 7.0 - c3_p);
        c3_nb_y = c3_v_a * c3_l_b;
        c3_w_a = 1.0 - c3_SOC;
        c3_m_b = c3_G[(int32_T)c3_p - 1];
        c3_ob_y = c3_w_a * c3_m_b;
        c3_x_a = c3_ob_y;
        c3_n_b = c3_mpower(chartInstance, 1.0 - c3_alpha_data[(int32_T)(real_T)
                           _SFD_EML_ARRAY_BOUNDS_CHECK("alpha", (int32_T)c3_k, 1,
          c3_alpha_sizes[1], 1, 0) - 1], 7.0 - c3_p);
        c3_pb_y = c3_x_a * c3_n_b;
        c3_S_data[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("S", (int32_T)
          c3_k, 1, c3_S_sizes[1], 1, 0) - 1] = (c3_S_data[(int32_T)(real_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("S", (int32_T)c3_k, 1, c3_S_sizes[1], 1, 0)
          - 1] + c3_nb_y) + c3_pb_y;
        c3_d_p++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 4, 0);
      c3_h_k++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 3, 0);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 115);
    c3_x_sizes[0] = 1;
    c3_x_sizes[1] = c3_S_sizes[1];
    c3_bb_x = c3_x_sizes[0];
    c3_cb_x = c3_x_sizes[1];
    c3_e_loop_ub = c3_S_sizes[0] * c3_S_sizes[1] - 1;
    for (c3_i47 = 0; c3_i47 <= c3_e_loop_ub; c3_i47++) {
      c3_x_data[c3_i47] = c3_S_data[c3_i47];
    }

    c3_b0 = (c3_x_sizes[1] == 1);
    guard2 = FALSE;
    if (c3_b0) {
      guard2 = TRUE;
    } else if ((real_T)c3_x_sizes[1] != 1.0) {
      guard2 = TRUE;
    } else {
      c3_b1 = FALSE;
    }

    if (guard2 == TRUE) {
      c3_b1 = TRUE;
    }

    if (c3_b1) {
    } else {
      for (c3_i48 = 0; c3_i48 < 36; c3_i48++) {
        c3_b_u[c3_i48] = c3_cv1[c3_i48];
      }

      c3_qb_y = NULL;
      sf_mex_assign(&c3_qb_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1,
        36), FALSE);
      sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
        14, c3_qb_y));
    }

    if ((real_T)c3_x_sizes[1] > 0.0) {
    } else {
      for (c3_i49 = 0; c3_i49 < 39; c3_i49++) {
        c3_c_u[c3_i49] = c3_cv2[c3_i49];
      }

      c3_rb_y = NULL;
      sf_mex_assign(&c3_rb_y, sf_mex_create("y", c3_c_u, 10, 0U, 1U, 0U, 2, 1,
        39), FALSE);
      sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
        14, c3_rb_y));
    }

    c3_ixstart = 1;
    c3_d_n = (int32_T)(real_T)c3_x_sizes[1];
    c3_ixstop = c3_d_n;
    c3_mtmp = c3_x_data[0];
    c3_itmp = 1;
    if (c3_d_n > 1) {
      c3_db_x = c3_mtmp;
      c3_o_b = muDoubleScalarIsNaN(c3_db_x);
      if (c3_o_b) {
        c3_b_ixstop = c3_ixstop;
        c3_ix = 2;
        exitg1 = FALSE;
        while ((exitg1 == FALSE) && (c3_ix <= c3_b_ixstop)) {
          c3_b_ix = c3_ix;
          c3_ixstart = c3_b_ix;
          c3_eb_x = c3_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_b_ix, 1,
            c3_x_sizes[1], 1, 0) - 1];
          c3_p_b = muDoubleScalarIsNaN(c3_eb_x);
          if (!c3_p_b) {
            c3_mtmp = c3_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_b_ix, 1,
              c3_x_sizes[1], 1, 0) - 1];
            c3_itmp = c3_b_ix;
            exitg1 = TRUE;
          } else {
            c3_ix++;
          }
        }
      }

      if (c3_ixstart < c3_ixstop) {
        c3_y_a = c3_ixstart + 1;
        c3_i50 = c3_y_a;
        c3_c_ixstop = c3_ixstop;
        for (c3_c_ix = c3_i50; c3_c_ix <= c3_c_ixstop; c3_c_ix++) {
          c3_b_ix = c3_c_ix;
          c3_ab_a = c3_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_b_ix, 1,
            c3_x_sizes[1], 1, 0) - 1];
          c3_q_b = c3_mtmp;
          c3_e_p = (c3_ab_a < c3_q_b);
          if (c3_e_p) {
            c3_mtmp = c3_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_b_ix, 1,
              c3_x_sizes[1], 1, 0) - 1];
            c3_itmp = c3_b_ix;
          }
        }
      }
    }

    c3_b_mtmp = c3_mtmp;
    c3_b_itmp = c3_itmp;
    c3_extremum = c3_b_mtmp;
    c3_iindx = c3_b_itmp;
    c3_b_minval = c3_extremum;
    c3_b_iindx = c3_iindx;
    c3_indx = (real_T)c3_b_iindx;
    c3_b_m = c3_b_minval;
    c3_b_opt_index = c3_indx;
    c3_m = c3_b_m;
    c3_opt_index = c3_b_opt_index;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 116);
    c3_alpha_opt = c3_alpha_data[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "alpha", (int32_T)c3_opt_index, 1, c3_alpha_sizes[1], 1, 0) - 1];
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, TRUE);
    CV_EML_IF(0, 1, 0, TRUE);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 59);
    c3_alpha_opt = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -116);
  _SFD_SYMBOL_SCOPE_POP();
  *c3_b_alpha_opt = c3_alpha_opt;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance)
{
}

static void registerMessagesc3_MATLAB(SFc3_MATLABInstanceStruct *chartInstance)
{
}

static real_T c3_plus_proche(SFc3_MATLABInstanceStruct *chartInstance, real_T
  c3_tab[48], real_T c3_val)
{
  real_T c3_I;
  uint32_T c3_debug_family_var_map[7];
  real_T c3_valeur;
  real_T c3_indice;
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i51;
  int32_T c3_i52;
  real_T c3_x[48];
  int32_T c3_k;
  real_T c3_b_k;
  real_T c3_b_x;
  real_T c3_y;
  real_T c3_b_y[48];
  int32_T c3_ixstart;
  real_T c3_mtmp;
  int32_T c3_itmp;
  real_T c3_c_x;
  boolean_T c3_b;
  int32_T c3_ix;
  int32_T c3_b_ix;
  real_T c3_d_x;
  boolean_T c3_b_b;
  int32_T c3_a;
  int32_T c3_i53;
  int32_T c3_c_ix;
  real_T c3_b_a;
  real_T c3_c_b;
  boolean_T c3_p;
  real_T c3_b_mtmp;
  int32_T c3_b_itmp;
  real_T c3_extremum;
  int32_T c3_iindx;
  real_T c3_minval;
  int32_T c3_b_iindx;
  real_T c3_indx;
  real_T c3_b_valeur;
  real_T c3_b_indice;
  boolean_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c3_b_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_valeur, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_indice, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tab, 4U, c3_e_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_val, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_I, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  for (c3_i51 = 0; c3_i51 < 48; c3_i51++) {
    c3_tab[c3_i51] -= c3_val;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 5);
  for (c3_i52 = 0; c3_i52 < 48; c3_i52++) {
    c3_x[c3_i52] = c3_tab[c3_i52];
  }

  for (c3_k = 0; c3_k < 48; c3_k++) {
    c3_b_k = 1.0 + (real_T)c3_k;
    c3_b_x = c3_x[(int32_T)c3_b_k - 1];
    c3_y = muDoubleScalarAbs(c3_b_x);
    c3_b_y[(int32_T)c3_b_k - 1] = c3_y;
  }

  c3_ixstart = 1;
  c3_mtmp = c3_b_y[0];
  c3_itmp = 1;
  c3_c_x = c3_mtmp;
  c3_b = muDoubleScalarIsNaN(c3_c_x);
  if (c3_b) {
    c3_ix = 2;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (c3_ix < 49)) {
      c3_b_ix = c3_ix;
      c3_ixstart = c3_b_ix;
      c3_d_x = c3_b_y[c3_b_ix - 1];
      c3_b_b = muDoubleScalarIsNaN(c3_d_x);
      if (!c3_b_b) {
        c3_mtmp = c3_b_y[c3_b_ix - 1];
        c3_itmp = c3_b_ix;
        exitg1 = TRUE;
      } else {
        c3_ix++;
      }
    }
  }

  if (c3_ixstart < 48) {
    c3_a = c3_ixstart;
    c3_i53 = c3_a;
    for (c3_c_ix = c3_i53 + 1; c3_c_ix < 49; c3_c_ix++) {
      c3_b_ix = c3_c_ix - 1;
      c3_b_a = c3_b_y[c3_b_ix];
      c3_c_b = c3_mtmp;
      c3_p = (c3_b_a < c3_c_b);
      if (c3_p) {
        c3_mtmp = c3_b_y[c3_b_ix];
        c3_itmp = c3_b_ix + 1;
      }
    }
  }

  c3_b_mtmp = c3_mtmp;
  c3_b_itmp = c3_itmp;
  c3_extremum = c3_b_mtmp;
  c3_iindx = c3_b_itmp;
  c3_minval = c3_extremum;
  c3_b_iindx = c3_iindx;
  c3_indx = (real_T)c3_b_iindx;
  c3_b_valeur = c3_minval;
  c3_b_indice = c3_indx;
  c3_valeur = c3_b_valeur;
  c3_indice = c3_b_indice;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_I = c3_indice;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  return c3_I;
}

static real_T c3_b_plus_proche(SFc3_MATLABInstanceStruct *chartInstance, real_T
  c3_tab[81], real_T c3_val)
{
  real_T c3_I;
  uint32_T c3_debug_family_var_map[7];
  real_T c3_valeur;
  real_T c3_indice;
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i54;
  int32_T c3_i55;
  real_T c3_x[81];
  int32_T c3_k;
  real_T c3_b_k;
  real_T c3_b_x;
  real_T c3_y;
  real_T c3_b_y[81];
  int32_T c3_ixstart;
  real_T c3_mtmp;
  int32_T c3_itmp;
  real_T c3_c_x;
  boolean_T c3_b;
  int32_T c3_ix;
  int32_T c3_b_ix;
  real_T c3_d_x;
  boolean_T c3_b_b;
  int32_T c3_a;
  int32_T c3_i56;
  int32_T c3_c_ix;
  real_T c3_b_a;
  real_T c3_c_b;
  boolean_T c3_p;
  real_T c3_b_mtmp;
  int32_T c3_b_itmp;
  real_T c3_extremum;
  int32_T c3_iindx;
  real_T c3_minval;
  int32_T c3_b_iindx;
  real_T c3_indx;
  real_T c3_b_valeur;
  real_T c3_b_indice;
  boolean_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c3_c_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_valeur, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_indice, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tab, 4U, c3_f_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_val, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_I, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  for (c3_i54 = 0; c3_i54 < 81; c3_i54++) {
    c3_tab[c3_i54] -= c3_val;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 5);
  for (c3_i55 = 0; c3_i55 < 81; c3_i55++) {
    c3_x[c3_i55] = c3_tab[c3_i55];
  }

  for (c3_k = 0; c3_k < 81; c3_k++) {
    c3_b_k = 1.0 + (real_T)c3_k;
    c3_b_x = c3_x[(int32_T)c3_b_k - 1];
    c3_y = muDoubleScalarAbs(c3_b_x);
    c3_b_y[(int32_T)c3_b_k - 1] = c3_y;
  }

  c3_ixstart = 1;
  c3_mtmp = c3_b_y[0];
  c3_itmp = 1;
  c3_c_x = c3_mtmp;
  c3_b = muDoubleScalarIsNaN(c3_c_x);
  if (c3_b) {
    c3_ix = 2;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (c3_ix < 82)) {
      c3_b_ix = c3_ix;
      c3_ixstart = c3_b_ix;
      c3_d_x = c3_b_y[c3_b_ix - 1];
      c3_b_b = muDoubleScalarIsNaN(c3_d_x);
      if (!c3_b_b) {
        c3_mtmp = c3_b_y[c3_b_ix - 1];
        c3_itmp = c3_b_ix;
        exitg1 = TRUE;
      } else {
        c3_ix++;
      }
    }
  }

  if (c3_ixstart < 81) {
    c3_a = c3_ixstart;
    c3_i56 = c3_a;
    for (c3_c_ix = c3_i56 + 1; c3_c_ix < 82; c3_c_ix++) {
      c3_b_ix = c3_c_ix - 1;
      c3_b_a = c3_b_y[c3_b_ix];
      c3_c_b = c3_mtmp;
      c3_p = (c3_b_a < c3_c_b);
      if (c3_p) {
        c3_mtmp = c3_b_y[c3_b_ix];
        c3_itmp = c3_b_ix + 1;
      }
    }
  }

  c3_b_mtmp = c3_mtmp;
  c3_b_itmp = c3_itmp;
  c3_extremum = c3_b_mtmp;
  c3_iindx = c3_b_itmp;
  c3_minval = c3_extremum;
  c3_b_iindx = c3_iindx;
  c3_indx = (real_T)c3_b_iindx;
  c3_b_valeur = c3_minval;
  c3_b_indice = c3_indx;
  c3_valeur = c3_b_valeur;
  c3_indice = c3_b_indice;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_I = c3_indice;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  return c3_I;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, 0U, sf_debug_get_script_id(
    "C:/Users/uidr6416/Documents/BEI_N7/AxelSplitHEV_5.0/plus_proche.m"));
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_alpha_opt, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_alpha_opt),
    &c3_thisId);
  sf_mex_destroy(&c3_alpha_opt);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d3;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d3, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d3;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_alpha_opt;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_alpha_opt = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_alpha_opt),
    &c3_thisId);
  sf_mex_destroy(&c3_alpha_opt);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i57;
  int32_T c3_i58;
  int32_T c3_i59;
  real_T c3_b_inData[567];
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  real_T c3_u[567];
  const mxArray *c3_y = NULL;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i57 = 0;
  for (c3_i58 = 0; c3_i58 < 7; c3_i58++) {
    for (c3_i59 = 0; c3_i59 < 81; c3_i59++) {
      c3_b_inData[c3_i59 + c3_i57] = (*(real_T (*)[567])c3_inData)[c3_i59 +
        c3_i57];
    }

    c3_i57 += 81;
  }

  c3_i60 = 0;
  for (c3_i61 = 0; c3_i61 < 7; c3_i61++) {
    for (c3_i62 = 0; c3_i62 < 81; c3_i62++) {
      c3_u[c3_i62 + c3_i60] = c3_b_inData[c3_i62 + c3_i60];
    }

    c3_i60 += 81;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 81, 7), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[567])
{
  real_T c3_dv7[567];
  int32_T c3_i63;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv7, 1, 0, 0U, 1, 0U, 2, 81, 7);
  for (c3_i63 = 0; c3_i63 < 567; c3_i63++) {
    c3_y[c3_i63] = c3_dv7[c3_i63];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_Tab_poly_elec;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[567];
  int32_T c3_i64;
  int32_T c3_i65;
  int32_T c3_i66;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_b_Tab_poly_elec = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Tab_poly_elec),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_Tab_poly_elec);
  c3_i64 = 0;
  for (c3_i65 = 0; c3_i65 < 7; c3_i65++) {
    for (c3_i66 = 0; c3_i66 < 81; c3_i66++) {
      (*(real_T (*)[567])c3_outData)[c3_i66 + c3_i64] = c3_y[c3_i66 + c3_i64];
    }

    c3_i64 += 81;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i67;
  int32_T c3_i68;
  int32_T c3_i69;
  real_T c3_b_inData[336];
  int32_T c3_i70;
  int32_T c3_i71;
  int32_T c3_i72;
  real_T c3_u[336];
  const mxArray *c3_y = NULL;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i67 = 0;
  for (c3_i68 = 0; c3_i68 < 7; c3_i68++) {
    for (c3_i69 = 0; c3_i69 < 48; c3_i69++) {
      c3_b_inData[c3_i69 + c3_i67] = (*(real_T (*)[336])c3_inData)[c3_i69 +
        c3_i67];
    }

    c3_i67 += 48;
  }

  c3_i70 = 0;
  for (c3_i71 = 0; c3_i71 < 7; c3_i71++) {
    for (c3_i72 = 0; c3_i72 < 48; c3_i72++) {
      c3_u[c3_i72 + c3_i70] = c3_b_inData[c3_i72 + c3_i70];
    }

    c3_i70 += 48;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 48, 7), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[336])
{
  real_T c3_dv8[336];
  int32_T c3_i73;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv8, 1, 0, 0U, 1, 0U, 2, 48, 7);
  for (c3_i73 = 0; c3_i73 < 336; c3_i73++) {
    c3_y[c3_i73] = c3_dv8[c3_i73];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_Tab_poly_therm;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[336];
  int32_T c3_i74;
  int32_T c3_i75;
  int32_T c3_i76;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_b_Tab_poly_therm = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Tab_poly_therm),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_Tab_poly_therm);
  c3_i74 = 0;
  for (c3_i75 = 0; c3_i75 < 7; c3_i75++) {
    for (c3_i76 = 0; c3_i76 < 48; c3_i76++) {
      (*(real_T (*)[336])c3_outData)[c3_i76 + c3_i74] = c3_y[c3_i76 + c3_i74];
    }

    c3_i74 += 48;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i77;
  real_T c3_b_inData[7];
  int32_T c3_i78;
  real_T c3_u[7];
  const mxArray *c3_y = NULL;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i77 = 0; c3_i77 < 7; c3_i77++) {
    c3_b_inData[c3_i77] = (*(real_T (*)[7])c3_inData)[c3_i77];
  }

  for (c3_i78 = 0; c3_i78 < 7; c3_i78++) {
    c3_u[c3_i78] = c3_b_inData[c3_i78];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 7), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_e_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[7])
{
  real_T c3_dv9[7];
  int32_T c3_i79;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv9, 1, 0, 0U, 1, 0U, 2, 1, 7);
  for (c3_i79 = 0; c3_i79 < 7; c3_i79++) {
    c3_y[c3_i79] = c3_dv9[c3_i79];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_fa_gearbox_ratio;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[7];
  int32_T c3_i80;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_b_fa_gearbox_ratio = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_fa_gearbox_ratio),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_fa_gearbox_ratio);
  for (c3_i80 = 0; c3_i80 < 7; c3_i80++) {
    (*(real_T (*)[7])c3_outData)[c3_i80] = c3_y[c3_i80];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i81;
  real_T c3_b_inData[48];
  int32_T c3_i82;
  real_T c3_u[48];
  const mxArray *c3_y = NULL;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i81 = 0; c3_i81 < 48; c3_i81++) {
    c3_b_inData[c3_i81] = (*(real_T (*)[48])c3_inData)[c3_i81];
  }

  for (c3_i82 = 0; c3_i82 < 48; c3_i82++) {
    c3_u[c3_i82] = c3_b_inData[c3_i82];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 48), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_f_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[48])
{
  real_T c3_dv10[48];
  int32_T c3_i83;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv10, 1, 0, 0U, 1, 0U, 2, 1,
                48);
  for (c3_i83 = 0; c3_i83 < 48; c3_i83++) {
    c3_y[c3_i83] = c3_dv10[c3_i83];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_SP_therm;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[48];
  int32_T c3_i84;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_b_SP_therm = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_SP_therm), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_b_SP_therm);
  for (c3_i84 = 0; c3_i84 < 48; c3_i84++) {
    (*(real_T (*)[48])c3_outData)[c3_i84] = c3_y[c3_i84];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i85;
  real_T c3_b_inData[81];
  int32_T c3_i86;
  real_T c3_u[81];
  const mxArray *c3_y = NULL;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i85 = 0; c3_i85 < 81; c3_i85++) {
    c3_b_inData[c3_i85] = (*(real_T (*)[81])c3_inData)[c3_i85];
  }

  for (c3_i86 = 0; c3_i86 < 81; c3_i86++) {
    c3_u[c3_i86] = c3_b_inData[c3_i86];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 81), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_g_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[81])
{
  real_T c3_dv11[81];
  int32_T c3_i87;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv11, 1, 0, 0U, 1, 0U, 2, 1,
                81);
  for (c3_i87 = 0; c3_i87 < 81; c3_i87++) {
    c3_y[c3_i87] = c3_dv11[c3_i87];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_SP_elec;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[81];
  int32_T c3_i88;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_b_SP_elec = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_SP_elec), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_b_SP_elec);
  for (c3_i88 = 0; c3_i88 < 81; c3_i88++) {
    (*(real_T (*)[81])c3_outData)[c3_i88] = c3_y[c3_i88];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, real_T
  c3_inData_data[101], int32_T c3_inData_sizes[2])
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_b_inData_sizes[2];
  int32_T c3_loop_ub;
  int32_T c3_i89;
  real_T c3_b_inData_data[101];
  int32_T c3_u_sizes[2];
  int32_T c3_b_loop_ub;
  int32_T c3_i90;
  real_T c3_u_data[101];
  const mxArray *c3_y = NULL;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_b_inData_sizes[0] = 1;
  c3_b_inData_sizes[1] = c3_inData_sizes[1];
  c3_loop_ub = c3_inData_sizes[1] - 1;
  for (c3_i89 = 0; c3_i89 <= c3_loop_ub; c3_i89++) {
    c3_b_inData_data[c3_b_inData_sizes[0] * c3_i89] =
      c3_inData_data[c3_inData_sizes[0] * c3_i89];
  }

  c3_u_sizes[0] = 1;
  c3_u_sizes[1] = c3_b_inData_sizes[1];
  c3_b_loop_ub = c3_b_inData_sizes[1] - 1;
  for (c3_i90 = 0; c3_i90 <= c3_b_loop_ub; c3_i90++) {
    c3_u_data[c3_u_sizes[0] * c3_i90] = c3_b_inData_data[c3_b_inData_sizes[0] *
      c3_i90];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u_data, 0, 0U, 1U, 0U, 2,
    c3_u_sizes[0], c3_u_sizes[1]), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_h_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y_data
  [101], int32_T c3_y_sizes[2])
{
  int32_T c3_i91;
  uint32_T c3_uv0[2];
  int32_T c3_i92;
  static boolean_T c3_bv0[2] = { FALSE, TRUE };

  boolean_T c3_bv1[2];
  int32_T c3_tmp_sizes[2];
  real_T c3_tmp_data[101];
  int32_T c3_y;
  int32_T c3_b_y;
  int32_T c3_loop_ub;
  int32_T c3_i93;
  for (c3_i91 = 0; c3_i91 < 2; c3_i91++) {
    c3_uv0[c3_i91] = 1U + 100U * (uint32_T)c3_i91;
  }

  for (c3_i92 = 0; c3_i92 < 2; c3_i92++) {
    c3_bv1[c3_i92] = c3_bv0[c3_i92];
  }

  sf_mex_import_vs(c3_parentId, sf_mex_dup(c3_u), c3_tmp_data, 1, 0, 0U, 1, 0U,
                   2, c3_bv1, c3_uv0, c3_tmp_sizes);
  c3_y_sizes[0] = 1;
  c3_y_sizes[1] = c3_tmp_sizes[1];
  c3_y = c3_y_sizes[0];
  c3_b_y = c3_y_sizes[1];
  c3_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
  for (c3_i93 = 0; c3_i93 <= c3_loop_ub; c3_i93++) {
    c3_y_data[c3_i93] = c3_tmp_data[c3_i93];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, real_T c3_outData_data[101],
  int32_T c3_outData_sizes[2])
{
  const mxArray *c3_S;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y_sizes[2];
  real_T c3_y_data[101];
  int32_T c3_loop_ub;
  int32_T c3_i94;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_S = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_S), &c3_thisId, c3_y_data,
                        c3_y_sizes);
  sf_mex_destroy(&c3_S);
  c3_outData_sizes[0] = 1;
  c3_outData_sizes[1] = c3_y_sizes[1];
  c3_loop_ub = c3_y_sizes[1] - 1;
  for (c3_i94 = 0; c3_i94 <= c3_loop_ub; c3_i94++) {
    c3_outData_data[c3_outData_sizes[0] * c3_i94] = c3_y_data[c3_y_sizes[0] *
      c3_i94];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i95;
  real_T c3_b_inData[401];
  int32_T c3_i96;
  real_T c3_u[401];
  const mxArray *c3_y = NULL;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i95 = 0; c3_i95 < 401; c3_i95++) {
    c3_b_inData[c3_i95] = (*(real_T (*)[401])c3_inData)[c3_i95];
  }

  for (c3_i96 = 0; c3_i96 < 401; c3_i96++) {
    c3_u[c3_i96] = c3_b_inData[c3_i96];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 401), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_i_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[401])
{
  real_T c3_dv12[401];
  int32_T c3_i97;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv12, 1, 0, 0U, 1, 0U, 1, 401);
  for (c3_i97 = 0; c3_i97 < 401; c3_i97++) {
    c3_y[c3_i97] = c3_dv12[c3_i97];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_Sp;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[401];
  int32_T c3_i98;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_Sp = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Sp), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_Sp);
  for (c3_i98 = 0; c3_i98 < 401; c3_i98++) {
    (*(real_T (*)[401])c3_outData)[c3_i98] = c3_y[c3_i98];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i99;
  int32_T c3_i100;
  int32_T c3_i101;
  real_T c3_b_inData[2800];
  int32_T c3_i102;
  int32_T c3_i103;
  int32_T c3_i104;
  real_T c3_u[2800];
  const mxArray *c3_y = NULL;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i99 = 0;
  for (c3_i100 = 0; c3_i100 < 7; c3_i100++) {
    for (c3_i101 = 0; c3_i101 < 400; c3_i101++) {
      c3_b_inData[c3_i101 + c3_i99] = (*(real_T (*)[2800])c3_inData)[c3_i101 +
        c3_i99];
    }

    c3_i99 += 400;
  }

  c3_i102 = 0;
  for (c3_i103 = 0; c3_i103 < 7; c3_i103++) {
    for (c3_i104 = 0; c3_i104 < 400; c3_i104++) {
      c3_u[c3_i104 + c3_i102] = c3_b_inData[c3_i104 + c3_i102];
    }

    c3_i102 += 400;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 400, 7), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_j_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2800])
{
  real_T c3_dv13[2800];
  int32_T c3_i105;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv13, 1, 0, 0U, 1, 0U, 2, 400,
                7);
  for (c3_i105 = 0; c3_i105 < 2800; c3_i105++) {
    c3_y[c3_i105] = c3_dv13[c3_i105];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_g;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2800];
  int32_T c3_i106;
  int32_T c3_i107;
  int32_T c3_i108;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_g = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_g), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_g);
  c3_i106 = 0;
  for (c3_i107 = 0; c3_i107 < 7; c3_i107++) {
    for (c3_i108 = 0; c3_i108 < 400; c3_i108++) {
      (*(real_T (*)[2800])c3_outData)[c3_i108 + c3_i106] = c3_y[c3_i108 +
        c3_i106];
    }

    c3_i106 += 400;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_MATLAB_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[92];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i109;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  c3_b_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 92), FALSE);
  for (c3_i109 = 0; c3_i109 < 92; c3_i109++) {
    c3_r0 = &c3_info[c3_i109];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i109);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i109);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i109);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i109);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i109);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i109);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i109);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i109);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[92])
{
  c3_info[0].context = "";
  c3_info[0].name = "mtimes";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[0].fileTimeLo = 1289519692U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "";
  c3_info[1].name = "mrdivide";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[1].fileTimeLo = 1357951548U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 1319729966U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[2].name = "rdivide";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[2].fileTimeLo = 1346510388U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[3].name = "eml_scalexp_compatible";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c3_info[3].fileTimeLo = 1286818796U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[4].name = "eml_div";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[4].fileTimeLo = 1313347810U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context = "";
  c3_info[5].name = "max";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c3_info[5].fileTimeLo = 1311255316U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c3_info[6].name = "eml_min_or_max";
  c3_info[6].dominantType = "char";
  c3_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[6].fileTimeLo = 1334071490U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[7].name = "eml_scalar_eg";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[7].fileTimeLo = 1286818796U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[8].name = "eml_scalexp_alloc";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[8].fileTimeLo = 1352424860U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[9].name = "eml_index_class";
  c3_info[9].dominantType = "";
  c3_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[9].fileTimeLo = 1323170578U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c3_info[10].name = "eml_scalar_eg";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[10].fileTimeLo = 1286818796U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context = "";
  c3_info[11].name = "min";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[11].fileTimeLo = 1311255318U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[12].name = "eml_min_or_max";
  c3_info[12].dominantType = "char";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[12].fileTimeLo = 1334071490U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context = "";
  c3_info[13].name = "colon";
  c3_info[13].dominantType = "double";
  c3_info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c3_info[13].fileTimeLo = 1348191928U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c3_info[14].name = "isfinite";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c3_info[14].fileTimeLo = 1286818758U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c3_info[15].name = "isinf";
  c3_info[15].dominantType = "double";
  c3_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c3_info[15].fileTimeLo = 1286818760U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c3_info[16].name = "isnan";
  c3_info[16].dominantType = "double";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c3_info[16].fileTimeLo = 1286818760U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c3_info[17].name = "floor";
  c3_info[17].dominantType = "double";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[17].fileTimeLo = 1343830380U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[18].name = "eml_scalar_floor";
  c3_info[18].dominantType = "double";
  c3_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[18].fileTimeLo = 1286818726U;
  c3_info[18].fileTimeHi = 0U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c3_info[19].name = "realmax";
  c3_info[19].dominantType = "char";
  c3_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c3_info[19].fileTimeLo = 1307651242U;
  c3_info[19].fileTimeHi = 0U;
  c3_info[19].mFileTimeLo = 0U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c3_info[20].name = "eml_realmax";
  c3_info[20].dominantType = "char";
  c3_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c3_info[20].fileTimeLo = 1326727996U;
  c3_info[20].fileTimeHi = 0U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c3_info[21].name = "eml_float_model";
  c3_info[21].dominantType = "char";
  c3_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c3_info[21].fileTimeLo = 1326727996U;
  c3_info[21].fileTimeHi = 0U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
  c3_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c3_info[22].name = "mtimes";
  c3_info[22].dominantType = "double";
  c3_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[22].fileTimeLo = 1289519692U;
  c3_info[22].fileTimeHi = 0U;
  c3_info[22].mFileTimeLo = 0U;
  c3_info[22].mFileTimeHi = 0U;
  c3_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c3_info[23].name = "isnan";
  c3_info[23].dominantType = "double";
  c3_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c3_info[23].fileTimeLo = 1286818760U;
  c3_info[23].fileTimeHi = 0U;
  c3_info[23].mFileTimeLo = 0U;
  c3_info[23].mFileTimeHi = 0U;
  c3_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c3_info[24].name = "eml_index_class";
  c3_info[24].dominantType = "";
  c3_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[24].fileTimeLo = 1323170578U;
  c3_info[24].fileTimeHi = 0U;
  c3_info[24].mFileTimeLo = 0U;
  c3_info[24].mFileTimeHi = 0U;
  c3_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c3_info[25].name = "eml_guarded_nan";
  c3_info[25].dominantType = "char";
  c3_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c3_info[25].fileTimeLo = 1286818776U;
  c3_info[25].fileTimeHi = 0U;
  c3_info[25].mFileTimeLo = 0U;
  c3_info[25].mFileTimeHi = 0U;
  c3_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c3_info[26].name = "eml_is_float_class";
  c3_info[26].dominantType = "char";
  c3_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c3_info[26].fileTimeLo = 1286818782U;
  c3_info[26].fileTimeHi = 0U;
  c3_info[26].mFileTimeLo = 0U;
  c3_info[26].mFileTimeHi = 0U;
  c3_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c3_info[27].name = "isinf";
  c3_info[27].dominantType = "double";
  c3_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c3_info[27].fileTimeLo = 1286818760U;
  c3_info[27].fileTimeHi = 0U;
  c3_info[27].mFileTimeLo = 0U;
  c3_info[27].mFileTimeHi = 0U;
  c3_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c3_info[28].name = "floor";
  c3_info[28].dominantType = "double";
  c3_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[28].fileTimeLo = 1343830380U;
  c3_info[28].fileTimeHi = 0U;
  c3_info[28].mFileTimeLo = 0U;
  c3_info[28].mFileTimeHi = 0U;
  c3_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c3_info[29].name = "mtimes";
  c3_info[29].dominantType = "double";
  c3_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[29].fileTimeLo = 1289519692U;
  c3_info[29].fileTimeHi = 0U;
  c3_info[29].mFileTimeLo = 0U;
  c3_info[29].mFileTimeHi = 0U;
  c3_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c3_info[30].name = "abs";
  c3_info[30].dominantType = "double";
  c3_info[30].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[30].fileTimeLo = 1343830366U;
  c3_info[30].fileTimeHi = 0U;
  c3_info[30].mFileTimeLo = 0U;
  c3_info[30].mFileTimeHi = 0U;
  c3_info[31].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[31].name = "eml_scalar_abs";
  c3_info[31].dominantType = "double";
  c3_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[31].fileTimeLo = 1286818712U;
  c3_info[31].fileTimeHi = 0U;
  c3_info[31].mFileTimeLo = 0U;
  c3_info[31].mFileTimeHi = 0U;
  c3_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c3_info[32].name = "eps";
  c3_info[32].dominantType = "char";
  c3_info[32].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[32].fileTimeLo = 1326727996U;
  c3_info[32].fileTimeHi = 0U;
  c3_info[32].mFileTimeLo = 0U;
  c3_info[32].mFileTimeHi = 0U;
  c3_info[33].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[33].name = "eml_is_float_class";
  c3_info[33].dominantType = "char";
  c3_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c3_info[33].fileTimeLo = 1286818782U;
  c3_info[33].fileTimeHi = 0U;
  c3_info[33].mFileTimeLo = 0U;
  c3_info[33].mFileTimeHi = 0U;
  c3_info[34].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[34].name = "eml_eps";
  c3_info[34].dominantType = "char";
  c3_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c3_info[34].fileTimeLo = 1326727996U;
  c3_info[34].fileTimeHi = 0U;
  c3_info[34].mFileTimeLo = 0U;
  c3_info[34].mFileTimeHi = 0U;
  c3_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c3_info[35].name = "eml_float_model";
  c3_info[35].dominantType = "char";
  c3_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c3_info[35].fileTimeLo = 1326727996U;
  c3_info[35].fileTimeHi = 0U;
  c3_info[35].mFileTimeLo = 0U;
  c3_info[35].mFileTimeHi = 0U;
  c3_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!maxabs";
  c3_info[36].name = "abs";
  c3_info[36].dominantType = "double";
  c3_info[36].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[36].fileTimeLo = 1343830366U;
  c3_info[36].fileTimeHi = 0U;
  c3_info[36].mFileTimeLo = 0U;
  c3_info[36].mFileTimeHi = 0U;
  c3_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c3_info[37].name = "intmax";
  c3_info[37].dominantType = "char";
  c3_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[37].fileTimeLo = 1311255316U;
  c3_info[37].fileTimeHi = 0U;
  c3_info[37].mFileTimeLo = 0U;
  c3_info[37].mFileTimeHi = 0U;
  c3_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c3_info[38].name = "coder.internal.indexIntRelop";
  c3_info[38].dominantType = "";
  c3_info[38].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c3_info[38].fileTimeLo = 1326728322U;
  c3_info[38].fileTimeHi = 0U;
  c3_info[38].mFileTimeLo = 0U;
  c3_info[38].mFileTimeHi = 0U;
  c3_info[39].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  c3_info[39].name = "eml_float_model";
  c3_info[39].dominantType = "char";
  c3_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c3_info[39].fileTimeLo = 1326727996U;
  c3_info[39].fileTimeHi = 0U;
  c3_info[39].mFileTimeLo = 0U;
  c3_info[39].mFileTimeHi = 0U;
  c3_info[40].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  c3_info[40].name = "intmin";
  c3_info[40].dominantType = "char";
  c3_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c3_info[40].fileTimeLo = 1311255318U;
  c3_info[40].fileTimeHi = 0U;
  c3_info[40].mFileTimeLo = 0U;
  c3_info[40].mFileTimeHi = 0U;
  c3_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c3_info[41].name = "eml_index_minus";
  c3_info[41].dominantType = "double";
  c3_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[41].fileTimeLo = 1286818778U;
  c3_info[41].fileTimeHi = 0U;
  c3_info[41].mFileTimeLo = 0U;
  c3_info[41].mFileTimeHi = 0U;
  c3_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[42].name = "eml_index_class";
  c3_info[42].dominantType = "";
  c3_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[42].fileTimeLo = 1323170578U;
  c3_info[42].fileTimeHi = 0U;
  c3_info[42].mFileTimeLo = 0U;
  c3_info[42].mFileTimeHi = 0U;
  c3_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c3_info[43].name = "eml_index_rdivide";
  c3_info[43].dominantType = "double";
  c3_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c3_info[43].fileTimeLo = 1286818780U;
  c3_info[43].fileTimeHi = 0U;
  c3_info[43].mFileTimeLo = 0U;
  c3_info[43].mFileTimeHi = 0U;
  c3_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c3_info[44].name = "eml_index_class";
  c3_info[44].dominantType = "";
  c3_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[44].fileTimeLo = 1323170578U;
  c3_info[44].fileTimeHi = 0U;
  c3_info[44].mFileTimeLo = 0U;
  c3_info[44].mFileTimeHi = 0U;
  c3_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c3_info[45].name = "eml_int_forloop_overflow_check";
  c3_info[45].dominantType = "";
  c3_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[45].fileTimeLo = 1346510340U;
  c3_info[45].fileTimeHi = 0U;
  c3_info[45].mFileTimeLo = 0U;
  c3_info[45].mFileTimeHi = 0U;
  c3_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c3_info[46].name = "intmax";
  c3_info[46].dominantType = "char";
  c3_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[46].fileTimeLo = 1311255316U;
  c3_info[46].fileTimeHi = 0U;
  c3_info[46].mFileTimeLo = 0U;
  c3_info[46].mFileTimeHi = 0U;
  c3_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c3_info[47].name = "mtimes";
  c3_info[47].dominantType = "double";
  c3_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[47].fileTimeLo = 1289519692U;
  c3_info[47].fileTimeHi = 0U;
  c3_info[47].mFileTimeLo = 0U;
  c3_info[47].mFileTimeHi = 0U;
  c3_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c3_info[48].name = "eml_index_times";
  c3_info[48].dominantType = "double";
  c3_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[48].fileTimeLo = 1286818780U;
  c3_info[48].fileTimeHi = 0U;
  c3_info[48].mFileTimeLo = 0U;
  c3_info[48].mFileTimeHi = 0U;
  c3_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[49].name = "eml_index_class";
  c3_info[49].dominantType = "";
  c3_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[49].fileTimeLo = 1323170578U;
  c3_info[49].fileTimeHi = 0U;
  c3_info[49].mFileTimeLo = 0U;
  c3_info[49].mFileTimeHi = 0U;
  c3_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c3_info[50].name = "eml_index_plus";
  c3_info[50].dominantType = "double";
  c3_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[50].fileTimeLo = 1286818778U;
  c3_info[50].fileTimeHi = 0U;
  c3_info[50].mFileTimeLo = 0U;
  c3_info[50].mFileTimeHi = 0U;
  c3_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[51].name = "eml_index_class";
  c3_info[51].dominantType = "";
  c3_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[51].fileTimeLo = 1323170578U;
  c3_info[51].fileTimeHi = 0U;
  c3_info[51].mFileTimeLo = 0U;
  c3_info[51].mFileTimeHi = 0U;
  c3_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c3_info[52].name = "eml_index_minus";
  c3_info[52].dominantType = "coder.internal.indexInt";
  c3_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[52].fileTimeLo = 1286818778U;
  c3_info[52].fileTimeHi = 0U;
  c3_info[52].mFileTimeLo = 0U;
  c3_info[52].mFileTimeHi = 0U;
  c3_info[53].context = "";
  c3_info[53].name = "length";
  c3_info[53].dominantType = "double";
  c3_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c3_info[53].fileTimeLo = 1303146206U;
  c3_info[53].fileTimeHi = 0U;
  c3_info[53].mFileTimeLo = 0U;
  c3_info[53].mFileTimeHi = 0U;
  c3_info[54].context = "";
  c3_info[54].name = "plus_proche";
  c3_info[54].dominantType = "double";
  c3_info[54].resolved =
    "[E]C:/Users/uidr6416/Documents/BEI_N7/AxelSplitHEV_5.0/plus_proche.m";
  c3_info[54].fileTimeLo = 1429271102U;
  c3_info[54].fileTimeHi = 0U;
  c3_info[54].mFileTimeLo = 0U;
  c3_info[54].mFileTimeHi = 0U;
  c3_info[55].context =
    "[E]C:/Users/uidr6416/Documents/BEI_N7/AxelSplitHEV_5.0/plus_proche.m";
  c3_info[55].name = "abs";
  c3_info[55].dominantType = "double";
  c3_info[55].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[55].fileTimeLo = 1343830366U;
  c3_info[55].fileTimeHi = 0U;
  c3_info[55].mFileTimeLo = 0U;
  c3_info[55].mFileTimeHi = 0U;
  c3_info[56].context =
    "[E]C:/Users/uidr6416/Documents/BEI_N7/AxelSplitHEV_5.0/plus_proche.m";
  c3_info[56].name = "min";
  c3_info[56].dominantType = "double";
  c3_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[56].fileTimeLo = 1311255318U;
  c3_info[56].fileTimeHi = 0U;
  c3_info[56].mFileTimeLo = 0U;
  c3_info[56].mFileTimeHi = 0U;
  c3_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c3_info[57].name = "eml_const_nonsingleton_dim";
  c3_info[57].dominantType = "double";
  c3_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c3_info[57].fileTimeLo = 1286818696U;
  c3_info[57].fileTimeHi = 0U;
  c3_info[57].mFileTimeLo = 0U;
  c3_info[57].mFileTimeHi = 0U;
  c3_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c3_info[58].name = "eml_scalar_eg";
  c3_info[58].dominantType = "double";
  c3_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[58].fileTimeLo = 1286818796U;
  c3_info[58].fileTimeHi = 0U;
  c3_info[58].mFileTimeLo = 0U;
  c3_info[58].mFileTimeHi = 0U;
  c3_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c3_info[59].name = "eml_index_class";
  c3_info[59].dominantType = "";
  c3_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[59].fileTimeLo = 1323170578U;
  c3_info[59].fileTimeHi = 0U;
  c3_info[59].mFileTimeLo = 0U;
  c3_info[59].mFileTimeHi = 0U;
  c3_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c3_info[60].name = "eml_index_class";
  c3_info[60].dominantType = "";
  c3_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[60].fileTimeLo = 1323170578U;
  c3_info[60].fileTimeHi = 0U;
  c3_info[60].mFileTimeLo = 0U;
  c3_info[60].mFileTimeHi = 0U;
  c3_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c3_info[61].name = "isnan";
  c3_info[61].dominantType = "double";
  c3_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c3_info[61].fileTimeLo = 1286818760U;
  c3_info[61].fileTimeHi = 0U;
  c3_info[61].mFileTimeLo = 0U;
  c3_info[61].mFileTimeHi = 0U;
  c3_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c3_info[62].name = "eml_index_plus";
  c3_info[62].dominantType = "coder.internal.indexInt";
  c3_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[62].fileTimeLo = 1286818778U;
  c3_info[62].fileTimeHi = 0U;
  c3_info[62].mFileTimeLo = 0U;
  c3_info[62].mFileTimeHi = 0U;
  c3_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c3_info[63].name = "eml_int_forloop_overflow_check";
  c3_info[63].dominantType = "";
  c3_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[63].fileTimeLo = 1346510340U;
  c3_info[63].fileTimeHi = 0U;
  c3_info[63].mFileTimeLo = 0U;
  c3_info[63].mFileTimeHi = 0U;
}

static void c3_b_info_helper(c3_ResolvedFunctionInfo c3_info[92])
{
  c3_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c3_info[64].name = "eml_relop";
  c3_info[64].dominantType = "function_handle";
  c3_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c3_info[64].fileTimeLo = 1342451182U;
  c3_info[64].fileTimeHi = 0U;
  c3_info[64].mFileTimeLo = 0U;
  c3_info[64].mFileTimeHi = 0U;
  c3_info[65].context = "";
  c3_info[65].name = "mpower";
  c3_info[65].dominantType = "double";
  c3_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[65].fileTimeLo = 1286818842U;
  c3_info[65].fileTimeHi = 0U;
  c3_info[65].mFileTimeLo = 0U;
  c3_info[65].mFileTimeHi = 0U;
  c3_info[66].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[66].name = "power";
  c3_info[66].dominantType = "double";
  c3_info[66].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[66].fileTimeLo = 1348191930U;
  c3_info[66].fileTimeHi = 0U;
  c3_info[66].mFileTimeLo = 0U;
  c3_info[66].mFileTimeHi = 0U;
  c3_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[67].name = "eml_scalar_eg";
  c3_info[67].dominantType = "double";
  c3_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[67].fileTimeLo = 1286818796U;
  c3_info[67].fileTimeHi = 0U;
  c3_info[67].mFileTimeLo = 0U;
  c3_info[67].mFileTimeHi = 0U;
  c3_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[68].name = "eml_scalexp_alloc";
  c3_info[68].dominantType = "double";
  c3_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[68].fileTimeLo = 1352424860U;
  c3_info[68].fileTimeHi = 0U;
  c3_info[68].mFileTimeLo = 0U;
  c3_info[68].mFileTimeHi = 0U;
  c3_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[69].name = "floor";
  c3_info[69].dominantType = "double";
  c3_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[69].fileTimeLo = 1343830380U;
  c3_info[69].fileTimeHi = 0U;
  c3_info[69].mFileTimeLo = 0U;
  c3_info[69].mFileTimeHi = 0U;
  c3_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[70].name = "eml_error";
  c3_info[70].dominantType = "char";
  c3_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[70].fileTimeLo = 1343830358U;
  c3_info[70].fileTimeHi = 0U;
  c3_info[70].mFileTimeLo = 0U;
  c3_info[70].mFileTimeHi = 0U;
  c3_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c3_info[71].name = "eml_scalar_eg";
  c3_info[71].dominantType = "double";
  c3_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[71].fileTimeLo = 1286818796U;
  c3_info[71].fileTimeHi = 0U;
  c3_info[71].mFileTimeLo = 0U;
  c3_info[71].mFileTimeHi = 0U;
  c3_info[72].context = "";
  c3_info[72].name = "sum";
  c3_info[72].dominantType = "double";
  c3_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[72].fileTimeLo = 1314736612U;
  c3_info[72].fileTimeHi = 0U;
  c3_info[72].mFileTimeLo = 0U;
  c3_info[72].mFileTimeHi = 0U;
  c3_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[73].name = "eml_assert_valid_dim";
  c3_info[73].dominantType = "double";
  c3_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c3_info[73].fileTimeLo = 1286818694U;
  c3_info[73].fileTimeHi = 0U;
  c3_info[73].mFileTimeLo = 0U;
  c3_info[73].mFileTimeHi = 0U;
  c3_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c3_info[74].name = "eml_scalar_floor";
  c3_info[74].dominantType = "double";
  c3_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[74].fileTimeLo = 1286818726U;
  c3_info[74].fileTimeHi = 0U;
  c3_info[74].mFileTimeLo = 0U;
  c3_info[74].mFileTimeHi = 0U;
  c3_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c3_info[75].name = "eml_index_class";
  c3_info[75].dominantType = "";
  c3_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[75].fileTimeLo = 1323170578U;
  c3_info[75].fileTimeHi = 0U;
  c3_info[75].mFileTimeLo = 0U;
  c3_info[75].mFileTimeHi = 0U;
  c3_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c3_info[76].name = "intmax";
  c3_info[76].dominantType = "char";
  c3_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[76].fileTimeLo = 1311255316U;
  c3_info[76].fileTimeHi = 0U;
  c3_info[76].mFileTimeLo = 0U;
  c3_info[76].mFileTimeHi = 0U;
  c3_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[77].name = "eml_index_class";
  c3_info[77].dominantType = "";
  c3_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[77].fileTimeLo = 1323170578U;
  c3_info[77].fileTimeHi = 0U;
  c3_info[77].mFileTimeLo = 0U;
  c3_info[77].mFileTimeHi = 0U;
  c3_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[78].name = "eml_scalar_eg";
  c3_info[78].dominantType = "double";
  c3_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[78].fileTimeLo = 1286818796U;
  c3_info[78].fileTimeHi = 0U;
  c3_info[78].mFileTimeLo = 0U;
  c3_info[78].mFileTimeHi = 0U;
  c3_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[79].name = "eml_matrix_vstride";
  c3_info[79].dominantType = "double";
  c3_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  c3_info[79].fileTimeLo = 1286818788U;
  c3_info[79].fileTimeHi = 0U;
  c3_info[79].mFileTimeLo = 0U;
  c3_info[79].mFileTimeHi = 0U;
  c3_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  c3_info[80].name = "eml_index_minus";
  c3_info[80].dominantType = "double";
  c3_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[80].fileTimeLo = 1286818778U;
  c3_info[80].fileTimeHi = 0U;
  c3_info[80].mFileTimeLo = 0U;
  c3_info[80].mFileTimeHi = 0U;
  c3_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  c3_info[81].name = "eml_index_class";
  c3_info[81].dominantType = "";
  c3_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[81].fileTimeLo = 1323170578U;
  c3_info[81].fileTimeHi = 0U;
  c3_info[81].mFileTimeLo = 0U;
  c3_info[81].mFileTimeHi = 0U;
  c3_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  c3_info[82].name = "eml_size_prod";
  c3_info[82].dominantType = "double";
  c3_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c3_info[82].fileTimeLo = 1286818798U;
  c3_info[82].fileTimeHi = 0U;
  c3_info[82].mFileTimeLo = 0U;
  c3_info[82].mFileTimeHi = 0U;
  c3_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c3_info[83].name = "eml_index_class";
  c3_info[83].dominantType = "";
  c3_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[83].fileTimeLo = 1323170578U;
  c3_info[83].fileTimeHi = 0U;
  c3_info[83].mFileTimeLo = 0U;
  c3_info[83].mFileTimeHi = 0U;
  c3_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[84].name = "eml_matrix_npages";
  c3_info[84].dominantType = "double";
  c3_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  c3_info[84].fileTimeLo = 1286818786U;
  c3_info[84].fileTimeHi = 0U;
  c3_info[84].mFileTimeLo = 0U;
  c3_info[84].mFileTimeHi = 0U;
  c3_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  c3_info[85].name = "eml_index_plus";
  c3_info[85].dominantType = "double";
  c3_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[85].fileTimeLo = 1286818778U;
  c3_info[85].fileTimeHi = 0U;
  c3_info[85].mFileTimeLo = 0U;
  c3_info[85].mFileTimeHi = 0U;
  c3_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  c3_info[86].name = "eml_index_class";
  c3_info[86].dominantType = "";
  c3_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[86].fileTimeLo = 1323170578U;
  c3_info[86].fileTimeHi = 0U;
  c3_info[86].mFileTimeLo = 0U;
  c3_info[86].mFileTimeHi = 0U;
  c3_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  c3_info[87].name = "eml_size_prod";
  c3_info[87].dominantType = "double";
  c3_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c3_info[87].fileTimeLo = 1286818798U;
  c3_info[87].fileTimeHi = 0U;
  c3_info[87].mFileTimeLo = 0U;
  c3_info[87].mFileTimeHi = 0U;
  c3_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  c3_info[88].name = "eml_index_times";
  c3_info[88].dominantType = "double";
  c3_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[88].fileTimeLo = 1286818780U;
  c3_info[88].fileTimeHi = 0U;
  c3_info[88].mFileTimeLo = 0U;
  c3_info[88].mFileTimeHi = 0U;
  c3_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[89].name = "eml_int_forloop_overflow_check";
  c3_info[89].dominantType = "";
  c3_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[89].fileTimeLo = 1346510340U;
  c3_info[89].fileTimeHi = 0U;
  c3_info[89].mFileTimeLo = 0U;
  c3_info[89].mFileTimeHi = 0U;
  c3_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[90].name = "eml_index_plus";
  c3_info[90].dominantType = "double";
  c3_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[90].fileTimeLo = 1286818778U;
  c3_info[90].fileTimeHi = 0U;
  c3_info[90].mFileTimeLo = 0U;
  c3_info[90].mFileTimeHi = 0U;
  c3_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[91].name = "eml_index_plus";
  c3_info[91].dominantType = "coder.internal.indexInt";
  c3_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[91].fileTimeLo = 1286818778U;
  c3_info[91].fileTimeHi = 0U;
  c3_info[91].mFileTimeLo = 0U;
  c3_info[91].mFileTimeHi = 0U;
}

static void c3_eml_scalar_eg(SFc3_MATLABInstanceStruct *chartInstance)
{
}

static void c3_float_colon_length(SFc3_MATLABInstanceStruct *chartInstance,
  real_T c3_a, real_T c3_b, int32_T *c3_n, real_T *c3_anew, real_T *c3_bnew,
  boolean_T *c3_n_too_large)
{
  real_T c3_x;
  boolean_T c3_b_b;
  real_T c3_b_x;
  boolean_T c3_c_b;
  real_T c3_c_x;
  boolean_T c3_d_b;
  real_T c3_d_x;
  boolean_T c3_e_b;
  boolean_T c3_b2;
  real_T c3_e_x;
  real_T c3_ndbl;
  real_T c3_b_a;
  real_T c3_y;
  real_T c3_apnd;
  real_T c3_cdiff;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_b_y;
  real_T c3_c_a;
  real_T c3_f_b;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_absa;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_absb;
  real_T c3_c;
  real_T c3_g_b;
  real_T c3_c_y;
  real_T c3_d_a;
  real_T c3_d_y;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c3_x = c3_a;
  c3_b_b = muDoubleScalarIsNaN(c3_x);
  guard1 = FALSE;
  if (c3_b_b) {
    guard1 = TRUE;
  } else {
    c3_b_x = c3_b;
    c3_c_b = muDoubleScalarIsNaN(c3_b_x);
    if (c3_c_b) {
      guard1 = TRUE;
    } else if (c3_b < c3_a) {
      *c3_n = 0;
      *c3_anew = c3_a;
      *c3_bnew = c3_b;
      *c3_n_too_large = FALSE;
    } else {
      c3_c_x = c3_a;
      c3_d_b = muDoubleScalarIsInf(c3_c_x);
      guard2 = FALSE;
      if (c3_d_b) {
        guard2 = TRUE;
      } else {
        c3_d_x = c3_b;
        c3_e_b = muDoubleScalarIsInf(c3_d_x);
        if (c3_e_b) {
          guard2 = TRUE;
        } else {
          *c3_anew = c3_a;
          c3_e_x = (c3_b - c3_a) / 0.01 + 0.5;
          c3_ndbl = c3_e_x;
          c3_ndbl = muDoubleScalarFloor(c3_ndbl);
          c3_b_a = c3_ndbl;
          c3_y = c3_b_a * 0.01;
          c3_apnd = c3_a + c3_y;
          c3_cdiff = c3_apnd - c3_b;
          c3_f_x = c3_cdiff;
          c3_g_x = c3_f_x;
          c3_b_y = muDoubleScalarAbs(c3_g_x);
          c3_c_a = c3_a;
          c3_f_b = c3_b;
          c3_h_x = c3_c_a;
          c3_i_x = c3_h_x;
          c3_absa = muDoubleScalarAbs(c3_i_x);
          c3_j_x = c3_f_b;
          c3_k_x = c3_j_x;
          c3_absb = muDoubleScalarAbs(c3_k_x);
          c3_c = muDoubleScalarMax(c3_absa, c3_absb);
          c3_g_b = c3_c;
          c3_c_y = 4.4408920985006262E-16 * c3_g_b;
          if (c3_b_y < c3_c_y) {
            c3_ndbl++;
            *c3_bnew = c3_b;
          } else if (c3_cdiff > 0.0) {
            c3_d_a = c3_ndbl - 1.0;
            c3_d_y = c3_d_a * 0.01;
            *c3_bnew = c3_a + c3_d_y;
          } else {
            c3_ndbl++;
            *c3_bnew = c3_apnd;
          }

          *c3_n_too_large = FALSE;
          if (c3_ndbl >= 0.0) {
            *c3_n = (int32_T)muDoubleScalarFloor(c3_ndbl);
          } else {
            *c3_n = 0;
          }
        }
      }

      if (guard2 == TRUE) {
        *c3_n = 1;
        *c3_anew = rtNaN;
        *c3_bnew = c3_b;
        c3_b2 = (c3_a == c3_b);
        *c3_n_too_large = !c3_b2;
      }
    }
  }

  if (guard1 == TRUE) {
    *c3_n = 1;
    *c3_anew = rtNaN;
    *c3_bnew = c3_b;
    *c3_n_too_large = FALSE;
  }
}

static real_T c3_mpower(SFc3_MATLABInstanceStruct *chartInstance, real_T c3_a,
  real_T c3_b)
{
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_ak;
  real_T c3_bk;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_ar;
  real_T c3_br;
  c3_b_a = c3_a;
  c3_b_b = c3_b;
  c3_c_a = c3_b_a;
  c3_c_b = c3_b_b;
  c3_eml_scalar_eg(chartInstance);
  c3_ak = c3_c_a;
  c3_bk = c3_c_b;
  if (c3_ak < 0.0) {
    c3_x = c3_bk;
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarFloor(c3_b_x);
    if (c3_b_x != c3_bk) {
      c3_eml_error(chartInstance);
    }
  }

  c3_d_a = c3_ak;
  c3_d_b = c3_bk;
  c3_eml_scalar_eg(chartInstance);
  c3_ar = c3_d_a;
  c3_br = c3_d_b;
  return muDoubleScalarPower(c3_ar, c3_br);
}

static void c3_eml_error(SFc3_MATLABInstanceStruct *chartInstance)
{
  int32_T c3_i110;
  static char_T c3_cv3[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[31];
  const mxArray *c3_y = NULL;
  for (c3_i110 = 0; c3_i110 < 31; c3_i110++) {
    c3_u[c3_i110] = c3_cv3[c3_i110];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 31), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c3_y));
}

static void c3_sum(SFc3_MATLABInstanceStruct *chartInstance, real_T c3_x[2800],
                   real_T c3_y[7])
{
  int32_T c3_ix;
  int32_T c3_iy;
  int32_T c3_i;
  int32_T c3_ixstart;
  int32_T c3_a;
  real_T c3_s;
  int32_T c3_k;
  int32_T c3_b_a;
  int32_T c3_c_a;
  c3_ix = 0;
  c3_iy = 0;
  for (c3_i = 1; c3_i < 8; c3_i++) {
    c3_ixstart = c3_ix;
    c3_a = c3_ixstart;
    c3_ixstart = c3_a;
    c3_ix = c3_ixstart + 1;
    c3_s = c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_ix, 1, 2800, 1, 0) - 1];
    for (c3_k = 2; c3_k < 401; c3_k++) {
      c3_b_a = c3_ix + 1;
      c3_ix = c3_b_a;
      c3_s += c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_ix, 1, 2800, 1, 0) - 1];
    }

    c3_c_a = c3_iy + 1;
    c3_iy = c3_c_a;
    c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_iy, 1, 7, 1, 0) - 1] = c3_s;
  }
}

static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_k_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i111;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i111, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i111;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_l_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_MATLAB, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_MATLAB), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_MATLAB);
  return c3_y;
}

static uint8_T c3_m_emlrt_marshallIn(SFc3_MATLABInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_MATLABInstanceStruct *chartInstance)
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

void sf_c3_MATLAB_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3459963345U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1174190072U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(278522033U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4074553449U);
}

mxArray *sf_c3_MATLAB_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("H7elQTuS9ff2iTv1cSR4nH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(81);
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
      pr[1] = (double)(48);
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
      pr[0] = (double)(81);
      pr[1] = (double)(7);
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
      pr[0] = (double)(48);
      pr[1] = (double)(7);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(7);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
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

mxArray *sf_c3_MATLAB_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c3_MATLAB(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"alpha_opt\",},{M[8],M[0],T\"is_active_c3_MATLAB\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_MATLAB_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_MATLABInstanceStruct *chartInstance;
    chartInstance = (SFc3_MATLABInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _MATLABMachineNumber_,
           3,
           1,
           1,
           16,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_MATLABMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_MATLABMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _MATLABMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"T");
          _SFD_SET_DATA_PROPS(1,2,0,1,"alpha_opt");
          _SFD_SET_DATA_PROPS(2,1,1,0,"V");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Tmax_elec");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Tmin_elec");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Tmax_therm");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Tmin_therm");
          _SFD_SET_DATA_PROPS(7,1,1,0,"GBX");
          _SFD_SET_DATA_PROPS(8,1,1,0,"SOC");
          _SFD_SET_DATA_PROPS(9,10,0,0,"SP_elec");
          _SFD_SET_DATA_PROPS(10,10,0,0,"SP_therm");
          _SFD_SET_DATA_PROPS(11,10,0,0,"fa_differential_ratio");
          _SFD_SET_DATA_PROPS(12,10,0,0,"fa_gearbox_ratio");
          _SFD_SET_DATA_PROPS(13,10,0,0,"ra_differential_ratio");
          _SFD_SET_DATA_PROPS(14,10,0,0,"Tab_poly_therm");
          _SFD_SET_DATA_PROPS(15,10,0,0,"Tab_poly_elec");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,5,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4381);
        _SFD_CV_INIT_EML_IF(0,1,0,2708,2744,2813,4376);
        _SFD_CV_INIT_EML_FOR(0,1,0,2962,2976,3009);
        _SFD_CV_INIT_EML_FOR(0,1,1,3331,3345,3926);
        _SFD_CV_INIT_EML_FOR(0,1,2,3701,3715,3826);
        _SFD_CV_INIT_EML_FOR(0,1,3,4110,4136,4241);
        _SFD_CV_INIT_EML_FOR(0,1,4,4136,4150,4237);

        {
          static int condStart[] = { 2712, 2735 };

          static int condEnd[] = { 2731, 2743 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,2711,2744,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"plus_proche",0,-1,171);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 81;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)
            c3_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 48;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)
            c3_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 48;
          dimVector[1]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)
            c3_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 81;
          dimVector[1]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          real_T *c3_T;
          real_T *c3_alpha_opt;
          real_T *c3_V;
          real_T *c3_Tmax_elec;
          real_T *c3_Tmin_elec;
          real_T *c3_Tmax_therm;
          real_T *c3_Tmin_therm;
          real_T *c3_GBX;
          real_T *c3_SOC;
          c3_SOC = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c3_GBX = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c3_Tmin_therm = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_Tmax_therm = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_Tmin_elec = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_Tmax_elec = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_alpha_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_T);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_alpha_opt);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_V);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_Tmax_elec);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_Tmin_elec);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_Tmax_therm);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_Tmin_therm);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_GBX);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_SOC);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c3_SP_elec);
          _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c3_SP_therm);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c3_fa_differential_ratio);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c3_fa_gearbox_ratio);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c3_ra_differential_ratio);
          _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c3_Tab_poly_therm);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c3_Tab_poly_elec);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _MATLABMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "8DS4MQLO4n8h1RwTR7aocF";
}

static void sf_opaque_initialize_c3_MATLAB(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_MATLABInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c3_MATLAB((SFc3_MATLABInstanceStruct*) chartInstanceVar);
  initialize_c3_MATLAB((SFc3_MATLABInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_MATLAB(void *chartInstanceVar)
{
  enable_c3_MATLAB((SFc3_MATLABInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_MATLAB(void *chartInstanceVar)
{
  disable_c3_MATLAB((SFc3_MATLABInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_MATLAB(void *chartInstanceVar)
{
  sf_c3_MATLAB((SFc3_MATLABInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_MATLAB(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_MATLAB((SFc3_MATLABInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_MATLAB();/* state var info */
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

extern void sf_internal_set_sim_state_c3_MATLAB(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_MATLAB();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_MATLAB((SFc3_MATLABInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_MATLAB(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_MATLAB(S);
}

static void sf_opaque_set_sim_state_c3_MATLAB(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_MATLAB(S, st);
}

static void sf_opaque_terminate_c3_MATLAB(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_MATLABInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_MATLAB_optimization_info();
    }

    finalize_c3_MATLAB((SFc3_MATLABInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_MATLAB((SFc3_MATLABInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_MATLAB(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_MATLAB((SFc3_MATLABInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_MATLAB(SimStruct *S)
{
  /* Actual parameters from chart:
     SP_elec SP_therm Tab_poly_elec Tab_poly_therm fa_differential_ratio fa_gearbox_ratio ra_differential_ratio
   */
  const char_T *rtParamNames[] = { "SP_elec", "SP_therm", "Tab_poly_elec",
    "Tab_poly_therm", "fa_differential_ratio", "fa_gearbox_ratio",
    "ra_differential_ratio" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for SP_elec*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for SP_therm*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for Tab_poly_elec*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for Tab_poly_therm*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for fa_differential_ratio*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for fa_gearbox_ratio*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);

  /* registration for ra_differential_ratio*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MATLAB_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3378889764U));
  ssSetChecksum1(S,(2331993191U));
  ssSetChecksum2(S,(3281006000U));
  ssSetChecksum3(S,(1121345793U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_MATLAB(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_MATLAB(SimStruct *S)
{
  SFc3_MATLABInstanceStruct *chartInstance;
  chartInstance = (SFc3_MATLABInstanceStruct *)utMalloc(sizeof
    (SFc3_MATLABInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_MATLABInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_MATLAB;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_MATLAB;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_MATLAB;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_MATLAB;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_MATLAB;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_MATLAB;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_MATLAB;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_MATLAB;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_MATLAB;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_MATLAB;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_MATLAB;
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

void c3_MATLAB_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_MATLAB(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_MATLAB(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_MATLAB(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_MATLAB_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
