#ifndef __c2_AxleSplitHEVv5_h__
#define __c2_AxleSplitHEVv5_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc2_AxleSplitHEVv5InstanceStruct
#define typedef_SFc2_AxleSplitHEVv5InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_Start;
  uint8_T c2_tp_Starter;
  uint8_T c2_tp_StarterAndTQI;
  uint8_T c2_tp_Stall;
  uint8_T c2_tp_Running;
  uint8_T c2_tp_Idle;
  uint8_T c2_tp_IdleTransOn;
  uint8_T c2_tp_Force_tracking;
  uint8_T c2_tp_Standard_force_tracking;
  uint8_T c2_tp_InjectionInhibed;
  boolean_T c2_isStable;
  uint8_T c2_is_active_c2_AxleSplitHEVv5;
  uint8_T c2_is_c2_AxleSplitHEVv5;
  uint8_T c2_is_Start;
  uint8_T c2_is_Running;
  uint8_T c2_is_Force_tracking;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
} SFc2_AxleSplitHEVv5InstanceStruct;

#endif                                 /*typedef_SFc2_AxleSplitHEVv5InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_AxleSplitHEVv5_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_AxleSplitHEVv5_get_check_sum(mxArray *plhs[]);
extern void c2_AxleSplitHEVv5_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
