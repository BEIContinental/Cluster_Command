#ifndef __c4_AxleSplitHEVv5_h__
#define __c4_AxleSplitHEVv5_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc4_AxleSplitHEVv5InstanceStruct
#define typedef_SFc4_AxleSplitHEVv5InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  uint8_T c4_tp_WAKEUP;
  uint8_T c4_tp_RUNNING;
  uint8_T c4_tp_STOP;
  uint8_T c4_tp_START;
  boolean_T c4_isStable;
  uint8_T c4_is_active_c4_AxleSplitHEVv5;
  uint8_T c4_is_c4_AxleSplitHEVv5;
  uint8_T c4_is_RUNNING;
  real_T c4_k;
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
} SFc4_AxleSplitHEVv5InstanceStruct;

#endif                                 /*typedef_SFc4_AxleSplitHEVv5InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_AxleSplitHEVv5_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_AxleSplitHEVv5_get_check_sum(mxArray *plhs[]);
extern void c4_AxleSplitHEVv5_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
