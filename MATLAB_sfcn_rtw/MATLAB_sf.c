/*
 * MATLAB_sf.c
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
#include <math.h>
#include "MATLAB_sf.h"
#include "MATLAB_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *MATLAB_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

/* Forward declaration for local functions */
static void MATLAB_sum(const real_T x[2800], real_T y[7]);
static real_T MATLAB_plus_proche(real_T tab[48], real_T val);
static real_T MATLAB_plus_proche_c(real_T tab[81], real_T val);
static real_T MATLAB_rt_powd_snf(real_T u0, real_T u1);

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* Function for MATLAB Function: '<Root>/MATLAB Function: Optimization Algorithm' */
static void MATLAB_sum(const real_T x[2800], real_T y[7])
{
  int32_T ix;
  int32_T iy;
  int32_T ixstart;
  real_T s;
  int32_T i;
  ix = -1;
  iy = -1;
  for (i = 0; i < 7; i++) {
    ixstart = ix + 1;
    ix++;
    s = x[ixstart];
    for (ixstart = 0; ixstart < 399; ixstart++) {
      ix++;
      s += x[ix];
    }

    iy++;
    y[iy] = s;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function: Optimization Algorithm' */
static real_T MATLAB_plus_proche(real_T tab[48], real_T val)
{
  real_T y[48];
  real_T mtmp;
  int32_T itmp;
  int32_T ixstart;
  int32_T ix;
  boolean_T exitg;

  /* %% Calcul l'indice le plus proche qui donne la valeur "val" dans "tab"   */
  for (ixstart = 0; ixstart < 48; ixstart++) {
    mtmp = tab[ixstart] - val;
    y[ixstart] = fabs(mtmp);
    tab[ixstart] = mtmp;
  }

  ixstart = 1;
  mtmp = y[0];
  itmp = 1;
  if (rtIsNaN(y[0])) {
    ix = 2;
    exitg = FALSE;
    while ((!exitg) && (ix < 49)) {
      ixstart = ix;
      if (!rtIsNaN(y[ix - 1])) {
        mtmp = y[ix - 1];
        itmp = ix;
        exitg = TRUE;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 48) {
    while (ixstart + 1 < 49) {
      if (y[ixstart] < mtmp) {
        mtmp = y[ixstart];
        itmp = ixstart + 1;
      }

      ixstart++;
    }
  }

  return itmp;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function: Optimization Algorithm' */
static real_T MATLAB_plus_proche_c(real_T tab[81], real_T val)
{
  real_T y[81];
  real_T mtmp;
  int32_T itmp;
  int32_T ixstart;
  int32_T ix;
  boolean_T exitg;

  /* %% Calcul l'indice le plus proche qui donne la valeur "val" dans "tab"   */
  for (ixstart = 0; ixstart < 81; ixstart++) {
    mtmp = tab[ixstart] - val;
    y[ixstart] = fabs(mtmp);
    tab[ixstart] = mtmp;
  }

  ixstart = 1;
  mtmp = y[0];
  itmp = 1;
  if (rtIsNaN(y[0])) {
    ix = 2;
    exitg = FALSE;
    while ((!exitg) && (ix < 82)) {
      ixstart = ix;
      if (!rtIsNaN(y[ix - 1])) {
        mtmp = y[ix - 1];
        itmp = ix;
        exitg = TRUE;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 81) {
    while (ixstart + 1 < 82) {
      if (y[ixstart] < mtmp) {
        mtmp = y[ixstart];
        itmp = ixstart + 1;
      }

      ixstart++;
    }
  }

  return itmp;
}

static real_T MATLAB_rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Start for root system: '<Root>' */
#define MDL_START

static void mdlStart(SimStruct *S)
{
  /* instance underlying S-Function data */
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  if defined(MATLAB_MEX_FILE)

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

#  endif

  MATLAB_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  real_T Sp_elec[401];
  static real_T f[2800];
  static real_T g[2800];
  real_T F[7];
  real_T G[7];
  real_T Sp[401];
  real_T alpha_min;
  real_T alpha_max;
  int32_T nm1d2;
  int32_T d_k;
  real_T ndbl;
  real_T apnd;
  real_T cdiff;
  int32_T ixstart;
  boolean_T exitg;
  real_T tmp[81];
  real_T tmp_0[48];
  real_T alpha_data[101];
  real_T S_data[101];
  int32_T alpha_sizes_idx;
  real_T u;

  /* MATLAB Function: '<Root>/MATLAB Function: Optimization Algorithm' incorporates:
   *  Inport: '<Root>/GBX'
   *  Inport: '<Root>/SOC'
   *  Inport: '<Root>/T'
   *  Inport: '<Root>/Tmax_elec'
   *  Inport: '<Root>/Tmax_therm'
   *  Inport: '<Root>/Tmin_elec'
   *  Inport: '<Root>/Tmin_therm'
   *  Inport: '<Root>/V'
   */
  /* MATLAB Function 'MATLAB Function: Optimization Algorithm': '<S1>:1' */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%% Optimization of torque repartition algorithm (in acceleration phase)%%%%%%%%%%%%%%%%%%%  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%          This algorithm minimizes the sum of instantanious consumptions during */
  /* %%%%%%%%%          a prediction horizon . We assume that the torque requested by the */
  /* %%%%%%%%%          driver will always be constant during a prediction horizon that we */
  /* %%%%%%%%%          estimate of 4 seconds (Corresponding N = 400 number of sampling */
  /* %%%%%%%%%          times). The speed is then a slope . Knowing the values of torque and */
  /* %%%%%%%%%          speed , we can express the consumption using the polynoms */
  /* %%%%%%%%%          interpolated from the engines look up tables. */
  /* %%%%%%%%%          Tq_requested = alpha*T_ICE + (1-alpha)*T_elec .  */
  /* %%%%%%%%%          alpha = 0 ===> Pure Electric Mode .   */
  /* %%%%%%%%%          alpha = 1 ===> Pure ICE Mode . */
  /* %%%%%%%%%          The minimization process is a computation of the final criteria with */
  /* %%%%%%%%%          all the possible values of alpha, and then select the minimum .  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%% Load of necessary variables  */
  /*  Done in the model explorer . Necessary variables declared as parameter  */
  /* %% Declaration of variables */
  /*  Determination of Prediction horizon */
  /*  Elec motor Speed Vector  */
  /*  Therm engine Speed Vector */
  /*  Sample time  */
  /*  Index Elec  */
  /*  Index Therm */
  /*  Polynom coefficient Therm */
  /*  Polynom coefficient Elec */
  /* '<S1>:1:38' */
  /*  Therm criteria   */
  /* '<S1>:1:39' */
  for (nm1d2 = 0; nm1d2 < 2800; nm1d2++) {
    f[nm1d2] = 0.0;
    g[nm1d2] = 0.0;
  }

  /*  Elec  criteria */
  /*  Sum of f  */
  /*  sum of g  */
  /*  Minimum of consumption  */
  /*  alpha optimal  */
  /*  Optimal alpha index  */
  /* '<S1>:1:45' */
  memset(&Sp[0], 0, 401U * sizeof(real_T));

  /*  Speed prediction to the wheels  */
  /* '<S1>:1:47' */
  Sp[0] = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] /
    9.5492965855137211;

  /* % Calcul des bornes de alpha  */
  /* '<S1>:1:53' */
  ndbl = 1.0 - *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] / *((const
    real_T **)ssGetInputPortSignalPtrs(S, 0))[0];
  alpha_min = *((const real_T **)ssGetInputPortSignalPtrs(S, 5))[0] / *((const
    real_T **)ssGetInputPortSignalPtrs(S, 0))[0];
  if ((ndbl >= alpha_min) || rtIsNaN(alpha_min)) {
    alpha_min = ndbl;
  }

  if ((0.0 >= alpha_min) || rtIsNaN(alpha_min)) {
    alpha_min = 0.0;
  }

  /* '<S1>:1:54' */
  ndbl = 1.0 - *((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0] / *((const
    real_T **)ssGetInputPortSignalPtrs(S, 0))[0];
  alpha_max = *((const real_T **)ssGetInputPortSignalPtrs(S, 4))[0] / *((const
    real_T **)ssGetInputPortSignalPtrs(S, 0))[0];
  if ((ndbl <= alpha_max) || rtIsNaN(alpha_max)) {
    alpha_max = ndbl;
  }

  if ((1.0 <= alpha_max) || rtIsNaN(alpha_max)) {
    alpha_max = 1.0;
  }

  if ((alpha_max < alpha_min) || (*((const real_T **)ssGetInputPortSignalPtrs(S,
         6))[0] == 0.0)) {
    /* '<S1>:1:58' */
    /* '<S1>:1:59' */
    ndbl = 0.0;

    /*  Use of electrical if no solutions or gear = 0  */
  } else {
    /* '<S1>:1:62' */
    if (rtIsNaN(alpha_min) || rtIsNaN(alpha_max)) {
      ixstart = 0;
      alpha_min = (rtNaN);
      apnd = alpha_max;
    } else if (alpha_max < alpha_min) {
      ixstart = -1;
      apnd = alpha_max;
    } else if (rtIsInf(alpha_min) || rtIsInf(alpha_max)) {
      ixstart = 0;
      alpha_min = (rtNaN);
      apnd = alpha_max;
    } else {
      ndbl = floor((alpha_max - alpha_min) / 0.01 + 0.5);
      apnd = ndbl * 0.01 + alpha_min;
      cdiff = apnd - alpha_max;
      u = fabs(alpha_max);
      if ((alpha_min >= u) || rtIsNaN(u)) {
        u = alpha_min;
      }

      if (fabs(cdiff) < 4.4408920985006262E-16 * u) {
        ndbl++;
        apnd = alpha_max;
      } else if (cdiff > 0.0) {
        apnd = (ndbl - 1.0) * 0.01 + alpha_min;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        nm1d2 = (int32_T)ndbl;
      } else {
        nm1d2 = 0;
      }

      ixstart = nm1d2 - 1;
    }

    alpha_sizes_idx = ixstart + 1;
    if (ixstart + 1 > 0) {
      alpha_data[0] = alpha_min;
      if (ixstart + 1 > 1) {
        alpha_data[ixstart] = apnd;
        nm1d2 = ((ixstart < 0) + ixstart) >> 1;
        for (d_k = 1; d_k < nm1d2; d_k++) {
          ndbl = (real_T)d_k * 0.01;
          alpha_data[d_k] = alpha_min + ndbl;
          alpha_data[ixstart - d_k] = apnd - ndbl;
        }

        if (nm1d2 << 1 == ixstart) {
          alpha_data[nm1d2] = (alpha_min + apnd) / 2.0;
        } else {
          ndbl = (real_T)nm1d2 * 0.01;
          alpha_data[nm1d2] = alpha_min + ndbl;
          alpha_data[nm1d2 + 1] = apnd - ndbl;
        }
      }
    }

    /* '<S1>:1:64' */
    for (nm1d2 = 0; nm1d2 < alpha_sizes_idx; nm1d2++) {
      S_data[nm1d2] = 0.0;
    }

    /*  Criteria to minimize   */
    /* % Calculus of the predicted speed vector   */
    /* '<S1>:1:67' */
    for (ixstart = 0; ixstart < 400; ixstart++) {
      /* '<S1>:1:67' */
      /* '<S1>:1:68' */
      Sp[1 + ixstart] = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] *
        0.01 + Sp[ixstart];

      /* '<S1>:1:67' */
    }

    /* '<S1>:1:71' */
    /*  Speed in Motor */
    /* '<S1>:1:72' */
    ndbl = MATLAB_ConstP.MATLABFunctionOptimiz[(int32_T)(*((const real_T **)
      ssGetInputPortSignalPtrs(S, 6))[0] + 1.0) - 1] * 3.72;
    for (nm1d2 = 0; nm1d2 < 401; nm1d2++) {
      Sp_elec[nm1d2] = Sp[nm1d2] * 10.0;
      Sp[nm1d2] *= ndbl;
    }

    /*  Speed in engine  */
    /* % Calculus of predicted consumption functions  */
    /* '<S1>:1:77' */
    ndbl = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] /
      (MATLAB_ConstP.MATLABFunctionOptimiz[(int32_T)(*((const real_T **)
         ssGetInputPortSignalPtrs(S, 6))[0] + 1.0) - 1] * 3.72);

    /*  Torque in engine  */
    /* '<S1>:1:78' */
    alpha_max = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] / 10.0;

    /*  Torque in Motor */
    /* '<S1>:1:81' */
    for (ixstart = 0; ixstart < 400; ixstart++) {
      /* '<S1>:1:81' */
      /*  Determination of corresponding  speed indexes  */
      /* '<S1>:1:83' */
      /* '<S1>:1:84' */
      /*  Extraction of Consumption Polynomials from the tables  */
      /* '<S1>:1:87' */
      memcpy(&tmp_0[0], MATLAB_ConstP.MATLABFunctionOpti_o, 48U * sizeof(real_T));
      nm1d2 = (int32_T)MATLAB_plus_proche(tmp_0, Sp[ixstart] *
        9.5492965855137211);
      for (d_k = 0; d_k < 7; d_k++) {
        F[d_k] = MATLAB_ConstP.MATLABFunctionOpt_d[(48 * d_k + nm1d2) - 1];
      }

      /* '<S1>:1:88' */
      memcpy(&tmp[0], MATLAB_ConstP.MATLABFunctionOptimi, 81U * sizeof(real_T));
      nm1d2 = (int32_T)MATLAB_plus_proche_c(tmp, Sp_elec[ixstart] *
        9.5492965855137211);

      /*  Expression of polynomials functions of Alpha */
      /* '<S1>:1:91' */
      for (d_k = 0; d_k < 7; d_k++) {
        /* '<S1>:1:91' */
        /* '<S1>:1:92' */
        /* '<S1>:1:93' */
        /* '<S1>:1:91' */
        G[d_k] = MATLAB_ConstP.MATLABFunctionOptim[(81 * d_k + nm1d2) - 1] *
          MATLAB_rt_powd_snf(alpha_max, 7.0 - (1.0 + (real_T)d_k));
        F[d_k] = MATLAB_rt_powd_snf(ndbl, 7.0 - (1.0 + (real_T)d_k)) * F[d_k];
      }

      /*  Kth Polynomial corresponding to Kth speed      */
      /* '<S1>:1:96' */
      for (nm1d2 = 0; nm1d2 < 7; nm1d2++) {
        f[ixstart + 400 * nm1d2] = F[nm1d2];
      }

      /* '<S1>:1:97' */
      for (nm1d2 = 0; nm1d2 < 7; nm1d2++) {
        g[ixstart + 400 * nm1d2] = -G[nm1d2];
      }

      /* '<S1>:1:81' */
    }

    /*  Sum of the polynomials : Final Criteria  */
    /* '<S1>:1:102' */
    MATLAB_sum(f, F);

    /* '<S1>:1:103' */
    MATLAB_sum(g, G);

    /* % Research of optimal alpha   */
    /*  Calculus of the values of the Criteria for the possible values of alpha  */
    /* '<S1>:1:108' */
    for (ixstart = 0; ixstart < alpha_sizes_idx; ixstart++) {
      /* '<S1>:1:108' */
      /* '<S1>:1:109' */
      for (nm1d2 = 0; nm1d2 < 7; nm1d2++) {
        /* '<S1>:1:109' */
        /* '<S1>:1:110' */
        S_data[ixstart] = (MATLAB_rt_powd_snf(alpha_data[ixstart], 7.0 - (1.0 +
                             (real_T)nm1d2)) * (*((const real_T **)
          ssGetInputPortSignalPtrs(S, 7))[0] * F[nm1d2]) + S_data[ixstart]) +
          (1.0 - *((const real_T **)ssGetInputPortSignalPtrs(S, 7))[0]) *
          G[nm1d2] * MATLAB_rt_powd_snf(1.0 - alpha_data[ixstart], 7.0 - (1.0 +
          (real_T)nm1d2));

        /* '<S1>:1:109' */
      }

      /* '<S1>:1:108' */
    }

    /* Selection of the minimum consumption and the corresponding alpha  */
    ixstart = 1;
    ndbl = S_data[0];
    nm1d2 = 0;
    if (alpha_sizes_idx > 1) {
      if (rtIsNaN(S_data[0])) {
        d_k = 2;
        exitg = FALSE;
        while ((!exitg) && (d_k <= alpha_sizes_idx)) {
          ixstart = d_k;
          if (!rtIsNaN(S_data[d_k - 1])) {
            ndbl = S_data[d_k - 1];
            nm1d2 = d_k - 1;
            exitg = TRUE;
          } else {
            d_k++;
          }
        }
      }

      if (ixstart < alpha_sizes_idx) {
        while (ixstart + 1 <= alpha_sizes_idx) {
          if (S_data[ixstart] < ndbl) {
            ndbl = S_data[ixstart];
            nm1d2 = ixstart;
          }

          ixstart++;
        }
      }
    }

    /* '<S1>:1:116' */
    ndbl = alpha_data[nm1d2];
  }

  /* Outport: '<Root>/alpha_opt' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function: Optimization Algorithm'
   */
  ((real_T *)ssGetOutputPortSignal(S, 0))[0] = ndbl;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
static void mdlTerminate(SimStruct *S)
{

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

  if (ssGetUserData(S) != (NULL) ) {
    rt_FREE(ssGetLocalBlockIO(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "MATLAB_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */
  ssSetZCCacheNeedsReset(S, 0);
  ssSetDerivCacheNeedsReset(S, 0);

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 1))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 0.0);
  ssSetOutputPortOffsetTime(S, 0, 1.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 8))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortSampleTime(S, 0, 0.0);
    ssSetInputPortOffsetTime(S, 0, 1.0);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 1 */
  {
    if (!ssSetInputPortVectorDimension(S, 1, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 1, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortSampleTime(S, 1, 0.0);
    ssSetInputPortOffsetTime(S, 1, 1.0);
    ssSetInputPortOverWritable(S, 1, 0);
    ssSetInputPortOptimOpts(S, 1, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 2 */
  {
    if (!ssSetInputPortVectorDimension(S, 2, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 2, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortSampleTime(S, 2, 0.0);
    ssSetInputPortOffsetTime(S, 2, 1.0);
    ssSetInputPortOverWritable(S, 2, 0);
    ssSetInputPortOptimOpts(S, 2, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 3 */
  {
    if (!ssSetInputPortVectorDimension(S, 3, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 3, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 3, 1);
    ssSetInputPortSampleTime(S, 3, 0.0);
    ssSetInputPortOffsetTime(S, 3, 1.0);
    ssSetInputPortOverWritable(S, 3, 0);
    ssSetInputPortOptimOpts(S, 3, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 4 */
  {
    if (!ssSetInputPortVectorDimension(S, 4, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 4, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 4, 1);
    ssSetInputPortSampleTime(S, 4, 0.0);
    ssSetInputPortOffsetTime(S, 4, 1.0);
    ssSetInputPortOverWritable(S, 4, 0);
    ssSetInputPortOptimOpts(S, 4, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 5 */
  {
    if (!ssSetInputPortVectorDimension(S, 5, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 5, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 5, 1);
    ssSetInputPortSampleTime(S, 5, 0.0);
    ssSetInputPortOffsetTime(S, 5, 1.0);
    ssSetInputPortOverWritable(S, 5, 0);
    ssSetInputPortOptimOpts(S, 5, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 6 */
  {
    if (!ssSetInputPortVectorDimension(S, 6, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 6, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 6, 1);
    ssSetInputPortSampleTime(S, 6, 0.0);
    ssSetInputPortOffsetTime(S, 6, 1.0);
    ssSetInputPortOverWritable(S, 6, 0);
    ssSetInputPortOptimOpts(S, 6, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 7 */
  {
    if (!ssSetInputPortVectorDimension(S, 7, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 7, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 7, 1);
    ssSetInputPortSampleTime(S, 7, 0.0);
    ssSetInputPortOffsetTime(S, 7, 1.0);
    ssSetInputPortOverWritable(S, 7, 0);
    ssSetInputPortOptimOpts(S, 7, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 0);

  /* Number of expected parameters */
#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif                                 /* MDL_CHECK_PARAMETERS */

    if (ssGetErrorStatus(S) != (NULL) ) {
      return;
    }
  } else {
    return;                            /* Parameter mismatch will be reported by Simulink */
  }

#endif                                 /* MATLAB_MEX_FILE */

  /* Options */
  ssSetOptions(S, (SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE |
                   SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED ));

#if SS_SFCN_FOR_SIM

  {
    ssSupportsMultipleExecInstances(S, true);
    ssHasStateInsideForEachSS(S, false);
  }

#endif

}

/* Function to initialize sample times. */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* task periods */
  ssSetSampleTime(S, 0, 0.0);

  /* task offsets */
  ssSetOffsetTime(S, 0, 1.0);
}

#if defined(MATLAB_MEX_FILE)
# include "fixedpoint.c"
# include "simulink.c"
#else
# undef S_FUNCTION_NAME
# define S_FUNCTION_NAME               MATLAB_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
