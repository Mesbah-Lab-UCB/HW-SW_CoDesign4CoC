/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_dnn_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 18-May-2023 18:03:10
 */

#ifndef _CODER_DNN_API_H
#define _CODER_DNN_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
real_T dnn(real_T x1[4]);

void dnn_api(const mxArray *prhs, const mxArray **plhs);

void dnn_atexit(void);

void dnn_initialize(void);

void dnn_terminate(void);

void dnn_xil_shutdown(void);

void dnn_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_dnn_api.h
 *
 * [EOF]
 */
