/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_plasma_nn_wrapper_wrapper_fixpt_fil_api.c
 *
 * Code generation for function '_coder_plasma_nn_wrapper_wrapper_fixpt_fil_api'
 *
 */

/* Include files */
#include "_coder_plasma_nn_wrapper_wrapper_fixpt_fil_api.h"
#include "plasma_nn_wrapper_wrapper_fixpt_fil.h"
#include "plasma_nn_wrapper_wrapper_fixpt_fil_data.h"
#include "plasma_nn_wrapper_wrapper_fixpt_fil_mexutil.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x1_1,
                                 const char_T *identifier);

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x1_1,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(x1_1), &thisId);
  emlrtDestroyArray(&x1_1);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void d_plasma_nn_wrapper_wrapper_fix(const mxArray *const prhs[3], int32_T nlhs,
                                     const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T x1_1;
  real_T x1_2;
  real_T x1_3;
  real_T y1_1;
  real_T y1_2;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  x1_1 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "x1_1");
  x1_2 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "x1_2");
  x1_3 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "x1_3");
  /* Invoke the target function */
  plasma_nn_wrapper_wrapper_fixpt_fil(&st, x1_1, x1_2, x1_3, &y1_1, &y1_2);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(y1_1);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(y1_2);
  }
}

/* End of code generation (_coder_plasma_nn_wrapper_wrapper_fixpt_fil_api.c) */
