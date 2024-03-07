#include "_coder_plasma_nn_wrapper_float_mex_mex.h"
#include "_coder_plasma_nn_wrapper_float_mex_api.h"
#include "plasma_nn_wrapper_float_mex_data.h"
#include "plasma_nn_wrapper_float_mex_initialize.h"
#include "plasma_nn_wrapper_float_mex_terminate.h"
#include "rt_nonfinite.h"

void customFetchLoggedData_mexFunction(int32_T nlhs, mxArray *plhs[4],
                                       int32_T nrhs)
{
  emlrtStack st = {NULL, NULL, NULL};
  const mxArray *outputs[4];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        21, "customFetchLoggedData");
  }
  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 21,
                        "customFetchLoggedData");
  }

  customFetchLoggedData_api(nlhs, outputs);

  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void forcePushIntoCloud_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = {NULL, NULL, NULL};
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        18, "forcePushIntoCloud");
  }
  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "forcePushIntoCloud");
  }

  forcePushIntoCloud_api();
}

void logStmts_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = {NULL, NULL, NULL};
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        8, "logStmts");
  }
  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 8,
                        "logStmts");
  }

  logStmts_api();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  static const char_T *emlrtEntryPoints[4] = {"plasma_nn_wrapper", "logStmts",
                                              "customFetchLoggedData",
                                              "forcePushIntoCloud"};
  emlrtStack st = {NULL, NULL, NULL};
  mexAtExit(&plasma_nn_wrapper_float_mex_atexit);

  plasma_nn_wrapper_float_mex_initialize();
  st.tls = emlrtRootTLSGlobal;

  switch (emlrtGetEntryPointIndexR2016a(
      &st, nrhs, &prhs[0], (const char_T **)&emlrtEntryPoints[0], 4)) {
  case 0:
    plasma_nn_wrapper_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 1:
    logStmts_mexFunction(nlhs, nrhs - 1);
    break;
  case 2:
    customFetchLoggedData_mexFunction(nlhs, plhs, nrhs - 1);
    break;
  case 3:
    forcePushIntoCloud_mexFunction(nlhs, nrhs - 1);
    break;
  }

  plasma_nn_wrapper_float_mex_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

void plasma_nn_wrapper_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                                   const mxArray *prhs[3])
{
  emlrtStack st = {NULL, NULL, NULL};
  const mxArray *outputs[2];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        17, "plasma_nn_wrapper");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "plasma_nn_wrapper");
  }

  plasma_nn_wrapper_api(prhs, nlhs, outputs);

  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}
