/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_empc_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 16-May-2023 20:30:27
 */

#ifndef _CODER_EMPC_API_H
#define _CODER_EMPC_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void empc(real_T x[4], emxArray_real_T *z);

void empc_api(const mxArray *prhs, const mxArray **plhs);

void empc_atexit(void);

void empc_initialize(void);

void empc_terminate(void);

void empc_xil_shutdown(void);

void empc_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_empc_api.h
 *
 * [EOF]
 */
