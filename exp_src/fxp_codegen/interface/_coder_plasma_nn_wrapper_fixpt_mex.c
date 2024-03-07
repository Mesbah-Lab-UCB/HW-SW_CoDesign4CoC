/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_plasma_nn_wrapper_fixpt_mex.c
 *
 * Code generation for function '_coder_plasma_nn_wrapper_fixpt_mex'
 *
 */

/* Include files */
#include "_coder_plasma_nn_wrapper_fixpt_mex.h"
#include "_coder_plasma_nn_wrapper_fixpt_api.h"
#include "plasma_nn_wrapper_fixpt_data.h"
#include "plasma_nn_wrapper_fixpt_initialize.h"
#include "plasma_nn_wrapper_fixpt_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&plasma_nn_wrapper_fixpt_atexit);
  /* Module initialization. */
  plasma_nn_wrapper_fixpt_initialize();
  /* Dispatch the entry-point. */
  plasma_nn_wrapper_fixpt_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  plasma_nn_wrapper_fixpt_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

void plasma_nn_wrapper_fixpt_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                         int32_T nrhs, const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        23, "plasma_nn_wrapper_fixpt");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 23,
                        "plasma_nn_wrapper_fixpt");
  }
  /* Call the function. */
  plasma_nn_wrapper_fixpt_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

/* End of code generation (_coder_plasma_nn_wrapper_fixpt_mex.c) */
