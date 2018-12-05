/*
 * MATLAB_sf.h
 *
 * Code generation for model "MATLAB_sf".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Thu Jun 18 14:47:52 2015
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_MATLAB_sf_h_
#define RTW_HEADER_MATLAB_sf_h_
#ifndef MATLAB_sf_COMMON_INCLUDES_
# define MATLAB_sf_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#define S_FUNCTION_NAME                MATLAB_sf
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                                 /* MATLAB_sf_COMMON_INCLUDES_ */

#include "MATLAB_sf_types.h"

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: SP_elec
   * Referenced by: '<Root>/MATLAB Function: Optimization Algorithm'
   */
  real_T MATLABFunctionOptimi[81];

  /* Expression: SP_therm
   * Referenced by: '<Root>/MATLAB Function: Optimization Algorithm'
   */
  real_T MATLABFunctionOpti_o[48];

  /* Expression: Tab_poly_elec
   * Referenced by: '<Root>/MATLAB Function: Optimization Algorithm'
   */
  real_T MATLABFunctionOptim[567];

  /* Expression: Tab_poly_therm
   * Referenced by: '<Root>/MATLAB Function: Optimization Algorithm'
   */
  real_T MATLABFunctionOpt_d[336];

  /* Expression: fa_gearbox_ratio
   * Referenced by: '<Root>/MATLAB Function: Optimization Algorithm'
   */
  real_T MATLABFunctionOptimiz[7];
} ConstP_MATLAB_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *T;                           /* '<Root>/T' */
  real_T *V;                           /* '<Root>/V' */
  real_T *Tmax_elec;                   /* '<Root>/Tmax_elec' */
  real_T *Tmin_elec;                   /* '<Root>/Tmin_elec' */
  real_T *Tmax_therm;                  /* '<Root>/Tmax_therm' */
  real_T *Tmin_therm;                  /* '<Root>/Tmin_therm' */
  real_T *GBX;                         /* '<Root>/GBX' */
  real_T *SOC;                         /* '<Root>/SOC' */
} ExternalUPtrs_MATLAB_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *alpha_opt;                   /* '<Root>/alpha_opt' */
} ExtY_MATLAB_T;

/* Constant parameters (auto storage) */
extern const ConstP_MATLAB_T MATLAB_ConstP;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Optimization_Algorithm/MATLAB Function: Optimization Algorithm')    - opens subsystem Optimization_Algorithm/MATLAB Function: Optimization Algorithm
 * hilite_system('Optimization_Algorithm/MATLAB Function: Optimization Algorithm/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Optimization_Algorithm'
 * '<S1>'   : 'Optimization_Algorithm/MATLAB Function: Optimization Algorithm'
 */
#endif                                 /* RTW_HEADER_MATLAB_sf_h_ */
