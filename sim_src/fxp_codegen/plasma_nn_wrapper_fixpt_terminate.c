/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * plasma_nn_wrapper_fixpt_terminate.c
 *
 * Code generation for function 'plasma_nn_wrapper_fixpt_terminate'
 *
 */

/* Include files */
#include "plasma_nn_wrapper_fixpt_terminate.h"
#include "_coder_plasma_nn_wrapper_fixpt_mex.h"
#include "plasma_nn_wrapper_fixpt_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void plasma_nn_wrapper_fixpt_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
  emlrtDestroyArray(&eml_mx);
  emlrtDestroyArray(&b_eml_mx);
  emlrtDestroyArray(&c_eml_mx);
}

void plasma_nn_wrapper_fixpt_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (plasma_nn_wrapper_fixpt_terminate.c) */
