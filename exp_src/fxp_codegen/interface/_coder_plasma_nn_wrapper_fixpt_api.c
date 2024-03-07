/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_plasma_nn_wrapper_fixpt_api.c
 *
 * Code generation for function '_coder_plasma_nn_wrapper_fixpt_api'
 *
 */

/* Include files */
#include "_coder_plasma_nn_wrapper_fixpt_api.h"
#include "plasma_nn_wrapper_fixpt.h"
#include "plasma_nn_wrapper_fixpt_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static int32_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId);

static int8_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x1_3,
                                 const char_T *identifier);

static int8_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static int32_T e_emlrt_marshallIn(const mxArray *src);

static int32_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *x1_1,
                                const char_T *identifier);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const int32_T u);

static int8_T f_emlrt_marshallIn(const mxArray *src);

/* Function Definitions */
static int32_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  int32_T y;
  emlrtCheckFiR2012b((emlrtCTX)sp, parentId, u, false, 0U, (void *)&dims,
                     eml_mx, b_eml_mx);
  y = e_emlrt_marshallIn(emlrtAlias(u));
  emlrtDestroyArray(&u);
  return y;
}

static int8_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x1_3,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  int8_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(x1_3), &thisId);
  emlrtDestroyArray(&x1_3);
  return y;
}

static int8_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  int8_T y;
  emlrtCheckFiR2012b((emlrtCTX)sp, parentId, u, false, 0U, (void *)&dims,
                     eml_mx, c_eml_mx);
  y = f_emlrt_marshallIn(emlrtAlias(u));
  emlrtDestroyArray(&u);
  return y;
}

static int32_T e_emlrt_marshallIn(const mxArray *src)
{
  const mxArray *mxInt;
  int32_T ret;
  mxInt = emlrtImportFiIntArrayR2008b(src);
  ret = *(int32_T *)emlrtMxGetData(mxInt);
  emlrtDestroyArray(&mxInt);
  emlrtDestroyArray(&src);
  return ret;
}

static int32_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *x1_1,
                                const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  int32_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(x1_1), &thisId);
  emlrtDestroyArray(&x1_1);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const int32_T u)
{
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  b_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = u;
  emlrtAssign(&b_y, m);
  emlrtAssign(&y, emlrtCreateFIR2013b((emlrtCTX)sp, eml_mx, b_eml_mx,
                                      (const char_T *)"simulinkarray", b_y,
                                      true, false));
  return y;
}

static int8_T f_emlrt_marshallIn(const mxArray *src)
{
  const mxArray *mxInt;
  int8_T ret;
  mxInt = emlrtImportFiIntArrayR2008b(src);
  ret = *(int8_T *)emlrtMxGetData(mxInt);
  emlrtDestroyArray(&mxInt);
  emlrtDestroyArray(&src);
  return ret;
}

void plasma_nn_wrapper_fixpt_api(const mxArray *const prhs[3], int32_T nlhs,
                                 const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  int32_T x1_1;
  int32_T x1_2;
  int32_T y1_1;
  int32_T y1_2;
  int8_T x1_3;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  x1_1 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "x1_1");
  x1_2 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "x1_2");
  x1_3 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "x1_3");
  /* Invoke the target function */
  plasma_nn_wrapper_fixpt(&st, x1_1, x1_2, x1_3, &y1_1, &y1_2);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, y1_1);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(&st, y1_2);
  }
}

/* End of code generation (_coder_plasma_nn_wrapper_fixpt_api.c) */
