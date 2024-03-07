#include "_coder_plasma_nn_wrapper_float_mex_api.h"
#include "customFetchLoggedData.h"
#include "forcePushIntoCloud.h"
#include "logStmts.h"
#include "plasma_nn_wrapper.h"
#include "plasma_nn_wrapper_float_mex_data.h"
#include "plasma_nn_wrapper_float_mex_emxutil.h"
#include "plasma_nn_wrapper_float_mex_types.h"
#include "rt_nonfinite.h"

static emlrtRTEInfo e_emlrtRTEI = {
    1, 1, "_coder_plasma_nn_wrapper_float_mex_api", ""};

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const emxArray_struct0_T *u);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x1_1,
                                 const char_T *identifier);

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp,
                                          const emxArray_struct1_T *u);

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[690]);

static const mxArray *emlrt_marshallOut(const real_T u);

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const emxArray_struct0_T *u)
{
  static const char_T *sv[7] = {"Class",  "Dims", "Varsize", "NumericType",
                                "Fimath", "Data", "DataSize"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T b_i;
  int32_T b_j1;
  int32_T c_i;
  int32_T i;
  uint8_T *b_pData;
  y = NULL;
  iv[0] = 1;
  iv[1] = u->size[1];
  emlrtAssign(&y,
              emlrtCreateStructArray(2, &iv[0], 7, (const char_T **)&sv[0]));
  emlrtCreateField(y, (const char_T *)"Class");
  emlrtCreateField(y, (const char_T *)"Dims");
  emlrtCreateField(y, (const char_T *)"Varsize");
  emlrtCreateField(y, (const char_T *)"NumericType");
  emlrtCreateField(y, (const char_T *)"Fimath");
  emlrtCreateField(y, (const char_T *)"Data");
  emlrtCreateField(y, (const char_T *)"DataSize");
  i = 0;
  for (b_j1 = 0; b_j1 < u->size[1U]; b_j1++) {
    b_y = NULL;
    iv[0] = 1;
    iv[1] = u->data[b_j1].Class.size[1];
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtCTX)sp, u->data[b_j1].Class.size[1], m,
                             &u->data[b_j1].Class.data[0]);
    emlrtAssign(&b_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"Class", b_y, 0);
    c_y = NULL;
    iv[0] = 1;
    iv[1] = 2;
    m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    pData[0] = u->data[b_j1].Dims.data[0];
    pData[1] = u->data[b_j1].Dims.data[1];
    emlrtAssign(&c_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"Dims", c_y, 1);
    d_y = NULL;
    m = emlrtCreateLogicalScalar(u->data[b_j1].Varsize);
    emlrtAssign(&d_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"Varsize", d_y, 2);
    e_y = NULL;
    iv[0] = 1;
    iv[1] = 0;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtCTX)sp, 0, m, NULL);
    emlrtAssign(&e_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"NumericType", e_y, 3);
    f_y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtCTX)sp, 0, m, NULL);
    emlrtAssign(&f_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"Fimath", f_y, 4);
    g_y = NULL;
    iv[0] = 1;
    iv[1] = u->data[b_j1].Data->size[1];
    m = emlrtCreateNumericArray(2, &iv[0], mxUINT8_CLASS, mxREAL);
    b_pData = (uint8_T *)emlrtMxGetData(m);
    b_i = 0;
    for (c_i = 0; c_i < u->data[b_j1].Data->size[1]; c_i++) {
      b_pData[b_i] = u->data[b_j1].Data->data[c_i];
      b_i++;
    }
    emlrtAssign(&g_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"Data", g_y, 5);
    h_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)emlrtMxGetData(m) = u->data[b_j1].DataSize;
    emlrtAssign(&h_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"DataSize", h_y, 6);
    i++;
  }
  return y;
}

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

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp,
                                          const emxArray_struct1_T *u)
{
  static const char_T *sv[2] = {"ActualIndex", "FieldNames"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  int32_T b_j1;
  int32_T i;
  y = NULL;
  iv[0] = 1;
  iv[1] = u->size[1];
  emlrtAssign(&y,
              emlrtCreateStructArray(2, &iv[0], 2, (const char_T **)&sv[0]));
  emlrtCreateField(y, (const char_T *)"ActualIndex");
  emlrtCreateField(y, (const char_T *)"FieldNames");
  i = 0;
  if (0 < u->size[1U]) {
    iv[0] = 1;
  }
  for (b_j1 = 0; b_j1 < u->size[1U]; b_j1++) {
    b_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)emlrtMxGetData(m) = u->data[b_j1].ActualIndex;
    emlrtAssign(&b_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"ActualIndex", b_y, 0);
    c_y = NULL;
    iv[1] = u->data[b_j1].FieldNames.size[1];
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtCTX)sp, u->data[b_j1].FieldNames.size[1], m,
                             &u->data[b_j1].FieldNames.data[0]);
    emlrtAssign(&c_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"FieldNames", c_y, 1);
    i++;
  }
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

static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[690])
{
  static const int32_T iv[2] = {1, 690};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 690, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
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

void customFetchLoggedData_api(int32_T nlhs, const mxArray *plhs[4])
{
  emlrtStack st = {NULL, NULL, NULL};
  emxArray_struct0_T *data;
  emxArray_struct1_T *dataInfo;
  real_T numLoggedExpr;
  char_T dataExprIdMapping[690];
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_struct0_T(&st, &data, 2, &e_emlrtRTEI, true);
  emxInit_struct1_T(&st, &dataInfo, 2, &e_emlrtRTEI, true);

  customFetchLoggedData(&st, data, dataInfo, dataExprIdMapping, &numLoggedExpr);

  plhs[0] = b_emlrt_marshallOut(&st, data);
  emxFree_struct0_T(&data);
  if (nlhs > 1) {
    plhs[1] = c_emlrt_marshallOut(&st, dataInfo);
  }
  emxFree_struct1_T(&dataInfo);
  if (nlhs > 2) {
    plhs[2] = d_emlrt_marshallOut(&st, dataExprIdMapping);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(numLoggedExpr);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void forcePushIntoCloud_api(void)
{
  emlrtStack st = {NULL, NULL, NULL};
  st.tls = emlrtRootTLSGlobal;

  forcePushIntoCloud(&st);
}

void logStmts_api(void)
{
  emlrtStack st = {NULL, NULL, NULL};
  st.tls = emlrtRootTLSGlobal;

  logStmts(&st);
}

void plasma_nn_wrapper_api(const mxArray *const prhs[3], int32_T nlhs,
                           const mxArray *plhs[2])
{
  emlrtStack st = {NULL, NULL, NULL};
  real_T x1_1;
  real_T x1_2;
  real_T x1_3;
  real_T y1_1;
  real_T y1_2;
  st.tls = emlrtRootTLSGlobal;

  x1_1 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "x1_1");
  x1_2 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "x1_2");
  x1_3 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "x1_3");

  plasma_nn_wrapper(&st, x1_1, x1_2, x1_3, &y1_1, &y1_2);

  plhs[0] = emlrt_marshallOut(y1_1);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(y1_2);
  }
}
