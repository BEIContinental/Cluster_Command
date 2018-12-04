#ifndef __c1_AxleSplitHEVv5_h__
#define __c1_AxleSplitHEVv5_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
#ifndef typedef_SFc1_AxleSplitHEVv5InstanceStruct
#define typedef_SFc1_AxleSplitHEVv5InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_STATE_3;
  uint8_T c1_tp_STATE_5;
  uint8_T c1_tp_STATE_22;
  uint8_T c1_tp_STATE_4;
  uint8_T c1_tp_STATE_1;
  uint8_T c1_tp_STATE_21;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_AxleSplitHEVv5;
  uint8_T c1_is_c1_AxleSplitHEVv5;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  rtwCAPI_ModelMappingInfo c1_testPointMappingInfo;
  void *c1_testPointAddrMap[1];
} SFc1_AxleSplitHEVv5InstanceStruct;

#endif                                 /*typedef_SFc1_AxleSplitHEVv5InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_AxleSplitHEVv5_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_AxleSplitHEVv5_get_check_sum(mxArray *plhs[]);
extern void c1_AxleSplitHEVv5_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
