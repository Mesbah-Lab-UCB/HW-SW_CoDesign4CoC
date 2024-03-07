#include "custom_mex_logger.h"
#include "plasma_nn_wrapper_float_mex_data.h"
#include "plasma_nn_wrapper_float_mex_emxutil.h"
#include "plasma_nn_wrapper_float_mex_types.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include <string.h>

#ifndef typedef_emxArray_struct1_T_1x15
#define typedef_emxArray_struct1_T_1x15
typedef struct {
  struct1_T data[15];
  int32_T size[2];
} emxArray_struct1_T_1x15;
#endif

static emxArray_struct1_T *pIndexMap;

static boolean_T pIndexMap_not_empty;

static uint32_T pBufferLen;

static emxArray_struct0_T *pBuffers;

static boolean_T pBuffers_not_empty;

static boolean_T pInit_not_empty;

static emxArray_boolean_T *pEnabled;

static emlrtRSInfo l_emlrtRSI = {
    1, "generic_logger_struct",
    "/usr/local/MATLAB/R2021a/toolbox/coder/float2fixed/custom_logger/"
    "custom_mex_logger.p"};

static emlrtRSInfo m_emlrtRSI = {13, "nullAssignment",
                                 "/usr/local/MATLAB/R2021a/toolbox/eml/eml/"
                                 "+coder/+internal/nullAssignment.m"};

static emlrtRSInfo n_emlrtRSI = {
    1, "indexMapper",
    "/usr/local/MATLAB/R2021a/toolbox/coder/float2fixed/custom_logger/"
    "custom_mex_logger.p"};

static emlrtRSInfo p_emlrtRSI = {
    1, "buffers",
    "/usr/local/MATLAB/R2021a/toolbox/coder/float2fixed/custom_logger/"
    "custom_mex_logger.p"};

static emlrtRSInfo q_emlrtRSI = {
    1, "custom_mex_logger",
    "/usr/local/MATLAB/R2021a/toolbox/coder/float2fixed/custom_logger/"
    "custom_mex_logger.p"};

static emlrtRSInfo s_emlrtRSI = {
    1, "generic_logger_struct_impl",
    "/usr/local/MATLAB/R2021a/toolbox/coder/float2fixed/custom_logger/"
    "custom_mex_logger.p"};

static emlrtRSInfo t_emlrtRSI = {
    1, "generic_logger_impl_val",
    "/usr/local/MATLAB/R2021a/toolbox/coder/float2fixed/custom_logger/"
    "custom_mex_logger.p"};

static emlrtMCInfo emlrtMCI = {1, 1, "generic_logger_struct",
                               "/usr/local/MATLAB/R2021a/toolbox/coder/"
                               "float2fixed/custom_logger/custom_mex_logger.p"};

static emlrtBCInfo emlrtBCI = {-1,
                               -1,
                               1,
                               1,
                               "",
                               "indexMapper",
                               "/usr/local/MATLAB/R2021a/toolbox/coder/"
                               "float2fixed/custom_logger/custom_mex_logger.p",
                               0};

static emlrtRTEInfo emlrtRTEI = {85, 27, "validate_inputs",
                                 "/usr/local/MATLAB/R2021a/toolbox/eml/eml/"
                                 "+coder/+internal/nullAssignment.m"};

static emlrtBCInfo b_emlrtBCI = {
    -1,
    -1,
    1,
    1,
    "",
    "generic_logger_struct",
    "/usr/local/MATLAB/R2021a/toolbox/coder/float2fixed/custom_logger/"
    "custom_mex_logger.p",
    0};

static emlrtBCInfo c_emlrtBCI = {
    -1,
    -1,
    1,
    1,
    "",
    "buffers",
    "/usr/local/MATLAB/R2021a/toolbox/coder/float2fixed/custom_logger/"
    "custom_mex_logger.p",
    0};

static emlrtECInfo emlrtECI = {-1, 1, 1, "buffers",
                               "/usr/local/MATLAB/R2021a/toolbox/coder/"
                               "float2fixed/custom_logger/custom_mex_logger.p"};

static emlrtDCInfo emlrtDCI = {1, 1, "buffers",
                               "/usr/local/MATLAB/R2021a/toolbox/coder/"
                               "float2fixed/custom_logger/custom_mex_logger.p",
                               1};

static emlrtRTEInfo c_emlrtRTEI = {
    1, 1, "custom_mex_logger",
    "/usr/local/MATLAB/R2021a/toolbox/coder/float2fixed/custom_logger/"
    "custom_mex_logger.p"};

static emlrtRTEInfo d_emlrtRTEI = {17, 9, "nullAssignment",
                                   "/usr/local/MATLAB/R2021a/toolbox/eml/eml/"
                                   "+coder/+internal/nullAssignment.m"};

static emlrtRSInfo v_emlrtRSI = {
    1, "generic_logger_struct",
    "/usr/local/MATLAB/R2021a/toolbox/coder/float2fixed/custom_logger/"
    "custom_mex_logger.p"};

static void b_buffers(const emlrtStack *sp, uint32_T idx,
                      const char_T arg_Class_data[],
                      const int32_T arg_Class_size[2],
                      const real_T arg_Dims_data[], boolean_T arg_Varsize,
                      const emxArray_uint8_T *arg_Data, uint32_T arg_DataSize);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_boolean_T *y);

static void b_generic_logger_impl_val(const emlrtStack *sp, uint32_T idx_in,
                                      real_T val_in);

static uint32_T b_indexMapper(const emlrtStack *sp, uint32_T staticIdx);

static void b_parse_struct(char_T fieldNamesStr_data[],
                           int32_T fieldNamesStr_size[2]);

static boolean_T buffers(const emlrtStack *sp, uint32_T idx);

static void c_buffers(const emlrtStack *sp, uint32_T idx,
                      const uint8_T arg_data[], const int32_T arg_size[2]);

static void c_generic_logger_impl_val(const emlrtStack *sp, uint32_T idx_in,
                                      const real_T val_in[2]);

static uint32_T c_indexMapper(const emlrtStack *sp, uint32_T staticIdx,
                              const char_T fieldNames_data[]);

static boolean_T customCoderEnableLog(const emlrtStack *sp, uint32_T buffId);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_boolean_T *ret);

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *a__output_of_horzcat_,
                             const char_T *identifier, emxArray_boolean_T *y);

static const mxArray *f2fCustomCoderEnableLogState(const emlrtStack *sp,
                                                   emlrtMCInfo *location);

static void generic_logger_impl_val(const emlrtStack *sp, uint32_T idx_in,
                                    const real_T val_in[3]);

static const mxArray *horzcat(const emlrtStack *sp, const mxArray *b,
                              const mxArray *c, emlrtMCInfo *location);

static boolean_T indexMapper(const emlrtStack *sp, uint32_T staticIdx);

static void parse_struct(char_T fieldNamesStr_data[],
                         int32_T fieldNamesStr_size[2]);

static void b_buffers(const emlrtStack *sp, uint32_T idx,
                      const char_T arg_Class_data[],
                      const int32_T arg_Class_size[2],
                      const real_T arg_Dims_data[], boolean_T arg_Varsize,
                      const emxArray_uint8_T *arg_Data, uint32_T arg_DataSize)
{
  static const char_T valClass[5] = {'u', 'i', 'n', 't', '8'};
  emlrtStack b_st;
  emlrtStack st;
  struct0_T S;
  struct0_T expl_temp;
  real_T d;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  uint32_T varargin_2;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInitStruct_struct0_T(sp, &S, &c_emlrtRTEI, true);
  if (!pBuffers_not_empty) {
    S.Class.size[0] = 1;
    S.Class.size[1] = 5;
    for (i = 0; i < 5; i++) {
      S.Class.data[i] = valClass[i];
    }
    S.Dims.size[0] = 1;
    S.Dims.size[1] = 2;
    S.Dims.data[0] = 1.0;
    S.Dims.data[1] = 1.0;
    S.Varsize = false;
    S.NumericType.size[0] = 1;
    S.NumericType.size[1] = 0;
    S.Fimath.size[0] = 1;
    S.Fimath.size[1] = 0;
    i = S.Data->size[0] * S.Data->size[1];
    S.Data->size[0] = 1;
    S.Data->size[1] = 1;
    emxEnsureCapacity_uint8_T(sp, S.Data, i, &c_emlrtRTEI);
    S.Data->data[0] = 0U;
    S.DataSize = 1U;
    i = pBuffers->size[0] * pBuffers->size[1];
    pBuffers->size[0] = 1;
    pBuffers->size[1] = 1;
    emxEnsureCapacity_struct0_T(sp, pBuffers, i, &c_emlrtRTEI);
    emxCopyStruct_struct0_T(sp, &pBuffers->data[0], &S, &c_emlrtRTEI);
    pBuffers_not_empty = true;
  }
  if ((real_T)idx > pBuffers->size[1]) {
    st.site = &p_emlrtRSI;
    emxCopyStruct_struct0_T(&st, &S, &pBuffers->data[0], &c_emlrtRTEI);
    d = (real_T)idx - (real_T)pBuffers->size[1];
    if (d < 4.294967296E+9) {
      if (d >= 0.0) {
        varargin_2 = (uint32_T)d;
      } else {
        varargin_2 = 0U;
      }
    } else {
      varargin_2 = MAX_uint32_T;
    }
    b_st.site = &o_emlrtRSI;
    if (varargin_2 > 2147483647U) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &b_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
          "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
    }
    i = pBuffers->size[1];
    loop_ub = (int32_T)varargin_2;
    i1 = pBuffers->size[0] * pBuffers->size[1];
    pBuffers->size[1] += (int32_T)varargin_2;
    emxEnsureCapacity_struct0_T(sp, pBuffers, i1, &c_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      emxCopyStruct_struct0_T(sp, &pBuffers->data[i + i1], &S, &c_emlrtRTEI);
    }
    pBuffers_not_empty = true;
  }
  emxFreeStruct_struct0_T(&S);
  emxInitStruct_struct0_T(sp, &expl_temp, &c_emlrtRTEI, true);
  expl_temp.Class.size[0] = 1;
  expl_temp.Class.size[1] = arg_Class_size[1];
  loop_ub = arg_Class_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&expl_temp.Class.data[0], &arg_Class_data[0],
           loop_ub * sizeof(char_T));
  }
  expl_temp.Dims.size[0] = 1;
  expl_temp.Dims.size[1] = 2;
  expl_temp.Dims.data[0] = arg_Dims_data[0];
  expl_temp.Dims.data[1] = arg_Dims_data[1];
  expl_temp.Varsize = arg_Varsize;
  expl_temp.NumericType.size[0] = 1;
  expl_temp.NumericType.size[1] = 0;
  expl_temp.Fimath.size[0] = 1;
  expl_temp.Fimath.size[1] = 0;
  i = expl_temp.Data->size[0] * expl_temp.Data->size[1];
  expl_temp.Data->size[0] = 1;
  expl_temp.Data->size[1] = arg_Data->size[1];
  emxEnsureCapacity_uint8_T(sp, expl_temp.Data, i, &c_emlrtRTEI);
  loop_ub = arg_Data->size[1];
  for (i = 0; i < loop_ub; i++) {
    expl_temp.Data->data[i] = arg_Data->data[i];
  }
  expl_temp.DataSize = arg_DataSize;
  i = pBuffers->size[1];
  if (((int32_T)idx < 1) || ((int32_T)idx > pBuffers->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i, &c_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  emxCopyStruct_struct0_T(sp, &pBuffers->data[(int32_T)idx - 1], &expl_temp,
                          &c_emlrtRTEI);
  emxFreeStruct_struct0_T(&expl_temp);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_boolean_T *y)
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void b_generic_logger_impl_val(const emlrtStack *sp, uint32_T idx_in,
                                      real_T val_in)
{
  static const char_T valClass[6] = {'d', 'o', 'u', 'b', 'l', 'e'};
  emlrtStack st;
  emxArray_uint8_T *S_Data;
  real_T S_Dims_data[2];
  int32_T S_Class_size[2];
  int32_T bytes_size[2];
  int32_T i;
  char_T S_Class_data[6];
  uint8_T bytes_data[24];
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (idx_in > 1U) {
    st.site = &t_emlrtRSI;
    if (!buffers(&st, idx_in)) {
      S_Class_size[0] = 1;
      S_Class_size[1] = 6;
      for (i = 0; i < 6; i++) {
        S_Class_data[i] = valClass[i];
      }
      emxInit_uint8_T(sp, &S_Data, 2, &c_emlrtRTEI, true);
      S_Dims_data[0] = 1.0;
      S_Dims_data[1] = 1.0;
      i = S_Data->size[0] * S_Data->size[1];
      S_Data->size[0] = 1;
      S_Data->size[1] = 1;
      emxEnsureCapacity_uint8_T(sp, S_Data, i, &c_emlrtRTEI);
      S_Data->data[0] = 0U;
      st.site = &t_emlrtRSI;
      b_buffers(&st, idx_in, S_Class_data, S_Class_size, S_Dims_data, false,
                S_Data, 1U);
      emxFree_uint8_T(&S_Data);
    }
    bytes_size[0] = 1;
    bytes_size[1] = 8;
    memcpy((void *)&bytes_data[0], (void *)&val_in,
           (uint32_T)((size_t)8 * sizeof(uint8_T)));
    st.site = &t_emlrtRSI;
    c_buffers(&st, idx_in, bytes_data, bytes_size);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static uint32_T b_indexMapper(const emlrtStack *sp, uint32_T staticIdx)
{
  emlrtStack st;
  emxArray_struct1_T_1x15 r;
  struct1_T S;
  real_T d;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  uint32_T actualIdx;
  uint32_T qY;
  st.prev = sp;
  st.tls = sp->tls;
  if (!pIndexMap_not_empty) {
    S.ActualIndex = 0U;
    S.FieldNames.size[0] = 1;
    S.FieldNames.size[1] = 0;
    i = pIndexMap->size[0] * pIndexMap->size[1];
    pIndexMap->size[0] = 1;
    pIndexMap->size[1] = 1;
    emxEnsureCapacity_struct1_T(sp, pIndexMap, i, &c_emlrtRTEI);
    pIndexMap->data[0] = S;
    pIndexMap_not_empty = true;
    pBufferLen = 1U;
  }
  actualIdx = pBufferLen + 1U;
  if (pBufferLen + 1U < pBufferLen) {
    actualIdx = MAX_uint32_T;
  }
  if ((real_T)staticIdx > pIndexMap->size[1]) {
    d = (real_T)staticIdx - (real_T)pIndexMap->size[1];
    if (d < 4.294967296E+9) {
      if (d >= 0.0) {
        qY = (uint32_T)d;
      } else {
        qY = 0U;
      }
    } else {
      qY = MAX_uint32_T;
    }
    st.site = &n_emlrtRSI;
    repmat(&st, pIndexMap->data[0], qY, r.data, r.size);
    i = pIndexMap->size[1];
    loop_ub = r.size[1];
    i1 = pIndexMap->size[0] * pIndexMap->size[1];
    pIndexMap->size[1] += r.size[1];
    emxEnsureCapacity_struct1_T(sp, pIndexMap, i1, &c_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      pIndexMap->data[i + i1] = r.data[i1];
    }
    pIndexMap_not_empty = true;
  }
  i = pIndexMap->size[1];
  if (((int32_T)staticIdx < 1) || ((int32_T)staticIdx > pIndexMap->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)staticIdx, 1, i, &emlrtBCI,
                                  (emlrtCTX)sp);
  }
  pIndexMap->data[(int32_T)staticIdx - 1].ActualIndex = actualIdx;
  qY = pBufferLen + 1U;
  if (pBufferLen + 1U < pBufferLen) {
    qY = MAX_uint32_T;
  }
  pBufferLen = qY;
  return actualIdx;
}

static void b_parse_struct(char_T fieldNamesStr_data[],
                           int32_T fieldNamesStr_size[2])
{
  static const char_T cv[8] = {'s', 't', 'r', 'u', 'c', 't', ' ', '('};
  static const char_T fieldId[7] = {'x', 'o', 'f', 'f', 's', 'e', 't'};
  int32_T i;
  fieldNamesStr_size[0] = 1;
  fieldNamesStr_size[1] = 26;
  for (i = 0; i < 8; i++) {
    fieldNamesStr_data[i] = cv[i];
  }
  fieldNamesStr_data[12] = ',';
  fieldNamesStr_data[8] = 'y';
  fieldNamesStr_data[13] = 'g';
  fieldNamesStr_data[9] = 'm';
  fieldNamesStr_data[14] = 'a';
  fieldNamesStr_data[10] = 'i';
  fieldNamesStr_data[15] = 'i';
  fieldNamesStr_data[11] = 'n';
  fieldNamesStr_data[16] = 'n';
  fieldNamesStr_data[17] = ',';
  for (i = 0; i < 7; i++) {
    fieldNamesStr_data[i + 18] = fieldId[i];
  }
  fieldNamesStr_data[25] = ')';
}

static boolean_T buffers(const emlrtStack *sp, uint32_T idx)
{
  static const char_T valClass[5] = {'u', 'i', 'n', 't', '8'};
  struct0_T S;
  int32_T i;
  boolean_T out;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (!pBuffers_not_empty) {
    emxInitStruct_struct0_T(sp, &S, &c_emlrtRTEI, true);
    S.Class.size[0] = 1;
    S.Class.size[1] = 5;
    for (i = 0; i < 5; i++) {
      S.Class.data[i] = valClass[i];
    }
    S.Dims.size[0] = 1;
    S.Dims.size[1] = 2;
    S.Dims.data[0] = 1.0;
    S.Dims.data[1] = 1.0;
    S.Varsize = false;
    S.NumericType.size[0] = 1;
    S.NumericType.size[1] = 0;
    S.Fimath.size[0] = 1;
    S.Fimath.size[1] = 0;
    i = S.Data->size[0] * S.Data->size[1];
    S.Data->size[0] = 1;
    S.Data->size[1] = 1;
    emxEnsureCapacity_uint8_T(sp, S.Data, i, &c_emlrtRTEI);
    S.Data->data[0] = 0U;
    S.DataSize = 1U;
    i = pBuffers->size[0] * pBuffers->size[1];
    pBuffers->size[0] = 1;
    pBuffers->size[1] = 1;
    emxEnsureCapacity_struct0_T(sp, pBuffers, i, &c_emlrtRTEI);
    emxCopyStruct_struct0_T(sp, &pBuffers->data[0], &S, &c_emlrtRTEI);
    pBuffers_not_empty = true;
    emxFreeStruct_struct0_T(&S);
  }
  if ((real_T)idx <= pBuffers->size[1]) {
    i = pBuffers->size[1];
    if (((int32_T)idx < 1) || ((int32_T)idx > pBuffers->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i, &b_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (pBuffers->data[(int32_T)idx - 1].DataSize > 1U) {
      out = true;
    } else {
      out = false;
    }
  } else {
    out = false;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return out;
}

static void c_buffers(const emlrtStack *sp, uint32_T idx,
                      const uint8_T arg_data[], const int32_T arg_size[2])
{
  static const char_T valClass[5] = {'u', 'i', 'n', 't', '8'};
  emxArray_uint8_T *r;
  struct0_T S;
  real_T d;
  real_T x;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T unnamed_idx_1;
  uint32_T qY;
  uint32_T size;
  uint32_T y;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (!pBuffers_not_empty) {
    emxInitStruct_struct0_T(sp, &S, &c_emlrtRTEI, true);
    S.Class.size[0] = 1;
    S.Class.size[1] = 5;
    for (i = 0; i < 5; i++) {
      S.Class.data[i] = valClass[i];
    }
    S.Dims.size[0] = 1;
    S.Dims.size[1] = 2;
    S.Dims.data[0] = 1.0;
    S.Dims.data[1] = 1.0;
    S.Varsize = false;
    S.NumericType.size[0] = 1;
    S.NumericType.size[1] = 0;
    S.Fimath.size[0] = 1;
    S.Fimath.size[1] = 0;
    i = S.Data->size[0] * S.Data->size[1];
    S.Data->size[0] = 1;
    S.Data->size[1] = 1;
    emxEnsureCapacity_uint8_T(sp, S.Data, i, &c_emlrtRTEI);
    S.Data->data[0] = 0U;
    S.DataSize = 1U;
    i = pBuffers->size[0] * pBuffers->size[1];
    pBuffers->size[0] = 1;
    pBuffers->size[1] = 1;
    emxEnsureCapacity_struct0_T(sp, pBuffers, i, &c_emlrtRTEI);
    emxCopyStruct_struct0_T(sp, &pBuffers->data[0], &S, &c_emlrtRTEI);
    pBuffers_not_empty = true;
    emxFreeStruct_struct0_T(&S);
  }
  i = pBuffers->size[1];
  if (((int32_T)idx < 1) || ((int32_T)idx > pBuffers->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i, &c_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  size = pBuffers->data[(int32_T)idx - 1].DataSize;
  i = pBuffers->size[1];
  if (((int32_T)idx < 1) || ((int32_T)idx > pBuffers->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i, &c_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  y = pBuffers->data[(int32_T)idx - 1].DataSize;
  d = (real_T)y + (real_T)arg_size[1];
  if (d < 4.294967296E+9) {
    y = (uint32_T)d;
  } else {
    y = MAX_uint32_T;
  }
  if ((real_T)y > pBuffers->data[(int32_T)idx - 1].Data->size[1]) {
    x = (real_T)pBuffers->data[(int32_T)idx - 1].Data->size[1] * 2.0;
    if (d < 4.294967296E+9) {
      y = (uint32_T)d;
    } else {
      y = MAX_uint32_T;
    }
    i = pBuffers->size[1];
    if (!(x < y)) {
      y = (uint32_T)x;
    }
    x = (real_T)y - (real_T)pBuffers->data[(int32_T)idx - 1].Data->size[1];
    if (x < 4.294967296E+9) {
      if (x >= 0.0) {
        y = (uint32_T)x;
      } else {
        y = 0U;
      }
    } else {
      y = MAX_uint32_T;
    }
    if ((real_T)y != (int32_T)y) {
      emlrtIntegerCheckR2012b(y, &emlrtDCI, (emlrtCTX)sp);
    }
    emxInit_uint8_T(sp, &r, 2, &c_emlrtRTEI, true);
    unnamed_idx_1 = (int32_T)y;
    i1 = pBuffers->size[1];
    i2 = r->size[0] * r->size[1];
    r->size[0] = 1;
    emxEnsureCapacity_uint8_T(sp, r, i2, &c_emlrtRTEI);
    i2 = pBuffers->size[1];
    if (((int32_T)idx < 1) || ((int32_T)idx > pBuffers->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i2, &c_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i2 = r->size[0] * r->size[1];
    r->size[1] = pBuffers->data[(int32_T)idx - 1].Data->size[1] + (int32_T)y;
    emxEnsureCapacity_uint8_T(sp, r, i2, &c_emlrtRTEI);
    i2 = pBuffers->size[1];
    if (((int32_T)idx < 1) || ((int32_T)idx > pBuffers->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i2, &c_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    loop_ub = pBuffers->data[(int32_T)idx - 1].Data->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      if (((int32_T)idx < 1) || ((int32_T)idx > i)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i, &c_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      r->data[i2] = pBuffers->data[(int32_T)idx - 1].Data->data[i2];
    }
    for (i2 = 0; i2 < unnamed_idx_1; i2++) {
      if (((int32_T)idx < 1) || ((int32_T)idx > i)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i, &c_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      r->data[i2 + pBuffers->data[(int32_T)idx - 1].Data->size[1]] = 0U;
    }
    i = pBuffers->size[1];
    if (((int32_T)idx < 1) || ((int32_T)idx > pBuffers->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i, &c_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = pBuffers->data[(int32_T)idx - 1].Data->size[0] *
        pBuffers->data[(int32_T)idx - 1].Data->size[1];
    pBuffers->data[(int32_T)idx - 1].Data->size[0] = 1;
    emxEnsureCapacity_uint8_T(sp, pBuffers->data[(int32_T)idx - 1].Data, i,
                              &c_emlrtRTEI);
    if (((int32_T)idx < 1) || ((int32_T)idx > i1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i1, &c_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = pBuffers->data[(int32_T)idx - 1].Data->size[0] *
        pBuffers->data[(int32_T)idx - 1].Data->size[1];
    pBuffers->data[(int32_T)idx - 1].Data->size[1] = r->size[1];
    emxEnsureCapacity_uint8_T(sp, pBuffers->data[(int32_T)idx - 1].Data, i,
                              &c_emlrtRTEI);
    if (((int32_T)idx < 1) || ((int32_T)idx > i1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i1, &c_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    loop_ub = r->size[1];
    for (i = 0; i < loop_ub; i++) {
      if (((int32_T)idx < 1) || ((int32_T)idx > i1)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i1, &c_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      pBuffers->data[(int32_T)idx - 1].Data->data[i] = r->data[i];
    }
    emxFree_uint8_T(&r);
  }
  i = pBuffers->size[1];
  if (((int32_T)idx < 1) || ((int32_T)idx > pBuffers->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i, &c_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (d < 4.294967296E+9) {
    y = (uint32_T)d;
  } else {
    y = MAX_uint32_T;
  }
  qY = y - 1U;
  if (y - 1U > y) {
    qY = 0U;
  }
  if (size > qY) {
    i = -1;
    i1 = -1;
  } else {
    i = pBuffers->data[(int32_T)idx - 1].Data->size[1];
    if (((int32_T)size < 1) || ((int32_T)size > i)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)size, 1, i, &c_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = (int32_T)size - 2;
    i1 = pBuffers->data[(int32_T)idx - 1].Data->size[1];
    if (((int32_T)qY < 1) || ((int32_T)qY > i1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)qY, 1, i1, &c_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = (int32_T)qY - 1;
  }
  loop_ub = i1 - i;
  if (loop_ub != arg_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(loop_ub, arg_size[1], &emlrtECI,
                                    (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < loop_ub; i1++) {
    pBuffers->data[(int32_T)idx - 1].Data->data[(i + i1) + 1] = arg_data[i1];
  }
  i = pBuffers->size[1];
  if (((int32_T)idx < 1) || ((int32_T)idx > pBuffers->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i, &c_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (d < 4.294967296E+9) {
    y = (uint32_T)d;
  } else {
    y = MAX_uint32_T;
  }
  pBuffers->data[(int32_T)idx - 1].DataSize = y;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void c_generic_logger_impl_val(const emlrtStack *sp, uint32_T idx_in,
                                      const real_T val_in[2])
{
  static const char_T valClass[6] = {'d', 'o', 'u', 'b', 'l', 'e'};
  emlrtStack st;
  emxArray_uint8_T *S_Data;
  real_T val_flat_data[2];
  int32_T S_Class_size[2];
  int32_T bytes_size[2];
  int32_T i;
  char_T S_Class_data[6];
  uint8_T bytes_data[24];
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (idx_in > 1U) {
    st.site = &t_emlrtRSI;
    if (!buffers(&st, idx_in)) {
      S_Class_size[0] = 1;
      S_Class_size[1] = 6;
      for (i = 0; i < 6; i++) {
        S_Class_data[i] = valClass[i];
      }
      emxInit_uint8_T(sp, &S_Data, 2, &c_emlrtRTEI, true);
      val_flat_data[0] = 2.0;
      val_flat_data[1] = 1.0;
      i = S_Data->size[0] * S_Data->size[1];
      S_Data->size[0] = 1;
      S_Data->size[1] = 1;
      emxEnsureCapacity_uint8_T(sp, S_Data, i, &c_emlrtRTEI);
      S_Data->data[0] = 0U;
      st.site = &t_emlrtRSI;
      b_buffers(&st, idx_in, S_Class_data, S_Class_size, val_flat_data, false,
                S_Data, 1U);
      emxFree_uint8_T(&S_Data);
    }
    val_flat_data[0] = val_in[0];
    val_flat_data[1] = val_in[1];
    bytes_size[0] = 1;
    bytes_size[1] = 16;
    memcpy((void *)&bytes_data[0], (void *)&val_flat_data[0],
           (uint32_T)((size_t)16 * sizeof(uint8_T)));
    st.site = &t_emlrtRSI;
    c_buffers(&st, idx_in, bytes_data, bytes_size);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static uint32_T c_indexMapper(const emlrtStack *sp, uint32_T staticIdx,
                              const char_T fieldNames_data[])
{
  emlrtStack st;
  emxArray_struct1_T_1x15 r;
  struct1_T S;
  real_T d;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  uint32_T actualIdx;
  uint32_T qY;
  st.prev = sp;
  st.tls = sp->tls;
  if (!pIndexMap_not_empty) {
    S.ActualIndex = 0U;
    S.FieldNames.size[0] = 1;
    S.FieldNames.size[1] = 0;
    i = pIndexMap->size[0] * pIndexMap->size[1];
    pIndexMap->size[0] = 1;
    pIndexMap->size[1] = 1;
    emxEnsureCapacity_struct1_T(sp, pIndexMap, i, &c_emlrtRTEI);
    pIndexMap->data[0] = S;
    pIndexMap_not_empty = true;
    pBufferLen = 1U;
  }
  actualIdx = pBufferLen + 1U;
  if (pBufferLen + 1U < pBufferLen) {
    actualIdx = MAX_uint32_T;
  }
  if ((real_T)staticIdx > pIndexMap->size[1]) {
    d = (real_T)staticIdx - (real_T)pIndexMap->size[1];
    if (d < 4.294967296E+9) {
      if (d >= 0.0) {
        qY = (uint32_T)d;
      } else {
        qY = 0U;
      }
    } else {
      qY = MAX_uint32_T;
    }
    st.site = &n_emlrtRSI;
    repmat(&st, pIndexMap->data[0], qY, r.data, r.size);
    i = pIndexMap->size[1];
    loop_ub = r.size[1];
    i1 = pIndexMap->size[0] * pIndexMap->size[1];
    pIndexMap->size[1] += r.size[1];
    emxEnsureCapacity_struct1_T(sp, pIndexMap, i1, &c_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      pIndexMap->data[i + i1] = r.data[i1];
    }
    pIndexMap_not_empty = true;
  }
  i = pIndexMap->size[1];
  if (((int32_T)staticIdx < 1) || ((int32_T)staticIdx > pIndexMap->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)staticIdx, 1, i, &emlrtBCI,
                                  (emlrtCTX)sp);
  }
  pIndexMap->data[(int32_T)staticIdx - 1].ActualIndex = actualIdx;
  i = pIndexMap->size[1];
  if (((int32_T)staticIdx < 1) || ((int32_T)staticIdx > pIndexMap->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)staticIdx, 1, i, &emlrtBCI,
                                  (emlrtCTX)sp);
  }
  pIndexMap->data[(int32_T)staticIdx - 1].FieldNames.size[0] = 1;
  i = pIndexMap->size[1];
  if (((int32_T)staticIdx < 1) || ((int32_T)staticIdx > pIndexMap->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)staticIdx, 1, i, &emlrtBCI,
                                  (emlrtCTX)sp);
  }
  pIndexMap->data[(int32_T)staticIdx - 1].FieldNames.size[1] = 26;
  i = pIndexMap->size[1];
  i1 = pIndexMap->size[1];
  if (((int32_T)staticIdx < 1) || ((int32_T)staticIdx > pIndexMap->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)staticIdx, 1, i1, &emlrtBCI,
                                  (emlrtCTX)sp);
  }
  i1 = pIndexMap->size[1];
  if (((int32_T)staticIdx < 1) || ((int32_T)staticIdx > pIndexMap->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)staticIdx, 1, i1, &emlrtBCI,
                                  (emlrtCTX)sp);
  }
  for (i1 = 0; i1 < 26; i1++) {
    if (((int32_T)staticIdx < 1) || ((int32_T)staticIdx > i)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)staticIdx, 1, i, &emlrtBCI,
                                    (emlrtCTX)sp);
    }
    pIndexMap->data[(int32_T)staticIdx - 1].FieldNames.data[i1] =
        fieldNames_data[i1];
  }
  qY = pBufferLen + 3U;
  if (pBufferLen + 3U < pBufferLen) {
    qY = MAX_uint32_T;
  }
  pBufferLen = qY;
  return actualIdx;
}

static boolean_T customCoderEnableLog(const emlrtStack *sp, uint32_T buffId)
{
  emlrtStack b_st;
  emlrtStack st;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  int32_T k;
  int32_T nxin;
  int32_T nxout;
  boolean_T out;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (!pInit_not_empty) {
    pInit_not_empty = true;
    k = pEnabled->size[0] * pEnabled->size[1];
    pEnabled->size[0] = 1;
    pEnabled->size[1] = 1;
    emxEnsureCapacity_boolean_T(sp, pEnabled, k, &c_emlrtRTEI);
    pEnabled->data[0] = false;
    y = NULL;
    iv[0] = 1;
    iv[1] = pEnabled->size[1];
    m = emlrtCreateLogicalArray(2, &iv[0]);
    emlrtInitLogicalArray(pEnabled->size[1], m, &pEnabled->data[0]);
    emlrtAssign(&y, m);
    st.site = &v_emlrtRSI;
    emlrt_marshallIn(&st,
                     horzcat(&st, y,
                             f2fCustomCoderEnableLogState(&st, &emlrtMCI),
                             &emlrtMCI),
                     "<output of horzcat>", pEnabled);
    st.site = &l_emlrtRSI;
    b_st.site = &m_emlrtRSI;
    if (1 > pEnabled->size[1]) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
                                    "MATLAB:subsdeldimmismatch",
                                    "MATLAB:subsdeldimmismatch", 0);
    }
    nxin = pEnabled->size[1];
    nxout = pEnabled->size[1] - 1;
    for (k = 0; k < nxout; k++) {
      pEnabled->data[k] = pEnabled->data[k + 1];
    }
    k = pEnabled->size[0] * pEnabled->size[1];
    if (1 > nxout) {
      pEnabled->size[1] = 0;
    } else {
      pEnabled->size[1] = nxin - 1;
    }
    emxEnsureCapacity_boolean_T(&st, pEnabled, k, &d_emlrtRTEI);
  }
  if ((real_T)buffId > pEnabled->size[1]) {
    out = false;
  } else {
    k = pEnabled->size[1];
    if (((int32_T)buffId < 1) || ((int32_T)buffId > pEnabled->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)buffId, 1, k, &b_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    out = pEnabled->data[(int32_T)buffId - 1];
  }
  return out;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_boolean_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"logical",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_boolean_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret->data[0], 1, false);
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *a__output_of_horzcat_,
                             const char_T *identifier, emxArray_boolean_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_horzcat_), &thisId, y);
  emlrtDestroyArray(&a__output_of_horzcat_);
}

static const mxArray *f2fCustomCoderEnableLogState(const emlrtStack *sp,
                                                   emlrtMCInfo *location)
{
  const mxArray *m;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 0, NULL,
                               (const char_T *)"f2fCustomCoderEnableLogState",
                               true, location);
}

static void generic_logger_impl_val(const emlrtStack *sp, uint32_T idx_in,
                                    const real_T val_in[3])
{
  static const char_T valClass[6] = {'d', 'o', 'u', 'b', 'l', 'e'};
  emlrtStack st;
  emxArray_uint8_T *S_Data;
  real_T val_flat_data[3];
  real_T S_Dims_data[2];
  int32_T S_Class_size[2];
  int32_T bytes_size[2];
  int32_T i;
  char_T S_Class_data[6];
  uint8_T bytes_data[24];
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (idx_in > 1U) {
    st.site = &l_emlrtRSI;
    if (!buffers(&st, idx_in)) {
      S_Class_size[0] = 1;
      S_Class_size[1] = 6;
      for (i = 0; i < 6; i++) {
        S_Class_data[i] = valClass[i];
      }
      emxInit_uint8_T(sp, &S_Data, 2, &c_emlrtRTEI, true);
      S_Dims_data[0] = 3.0;
      S_Dims_data[1] = 1.0;
      i = S_Data->size[0] * S_Data->size[1];
      S_Data->size[0] = 1;
      S_Data->size[1] = 1;
      emxEnsureCapacity_uint8_T(sp, S_Data, i, &c_emlrtRTEI);
      S_Data->data[0] = 0U;
      st.site = &l_emlrtRSI;
      b_buffers(&st, idx_in, S_Class_data, S_Class_size, S_Dims_data, false,
                S_Data, 1U);
      emxFree_uint8_T(&S_Data);
    }
    val_flat_data[0] = val_in[0];
    val_flat_data[1] = val_in[1];
    val_flat_data[2] = val_in[2];
    bytes_size[0] = 1;
    bytes_size[1] = 24;
    memcpy((void *)&bytes_data[0], (void *)&val_flat_data[0],
           (uint32_T)((size_t)24 * sizeof(uint8_T)));
    st.site = &l_emlrtRSI;
    c_buffers(&st, idx_in, bytes_data, bytes_size);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static const mxArray *horzcat(const emlrtStack *sp, const mxArray *b,
                              const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 2, &pArrays[0],
                               (const char_T *)"horzcat", true, location);
}

static boolean_T indexMapper(const emlrtStack *sp, uint32_T staticIdx)
{
  struct1_T S;
  int32_T i;
  boolean_T actualIdx;
  if (!pIndexMap_not_empty) {
    S.ActualIndex = 0U;
    S.FieldNames.size[0] = 1;
    S.FieldNames.size[1] = 0;
    i = pIndexMap->size[0] * pIndexMap->size[1];
    pIndexMap->size[0] = 1;
    pIndexMap->size[1] = 1;
    emxEnsureCapacity_struct1_T(sp, pIndexMap, i, &c_emlrtRTEI);
    pIndexMap->data[0] = S;
    pIndexMap_not_empty = true;
    pBufferLen = 1U;
  }
  if ((real_T)staticIdx > pIndexMap->size[1]) {
    actualIdx = false;
  } else {
    i = pIndexMap->size[1];
    if (((int32_T)staticIdx < 1) || ((int32_T)staticIdx > pIndexMap->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)staticIdx, 1, i, &b_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (pIndexMap->data[(int32_T)staticIdx - 1].ActualIndex != 0U) {
      actualIdx = true;
    } else {
      actualIdx = false;
    }
  }
  return actualIdx;
}

static void parse_struct(char_T fieldNamesStr_data[],
                         int32_T fieldNamesStr_size[2])
{
  static const char_T cv[8] = {'s', 't', 'r', 'u', 'c', 't', ' ', '('};
  static const char_T fieldId[7] = {'x', 'o', 'f', 'f', 's', 'e', 't'};
  int32_T i;
  fieldNamesStr_size[0] = 1;
  fieldNamesStr_size[1] = 26;
  for (i = 0; i < 8; i++) {
    fieldNamesStr_data[i] = cv[i];
  }
  for (i = 0; i < 7; i++) {
    fieldNamesStr_data[i + 8] = fieldId[i];
  }
  fieldNamesStr_data[15] = ',';
  fieldNamesStr_data[20] = ',';
  fieldNamesStr_data[16] = 'g';
  fieldNamesStr_data[21] = 'y';
  fieldNamesStr_data[17] = 'a';
  fieldNamesStr_data[22] = 'm';
  fieldNamesStr_data[18] = 'i';
  fieldNamesStr_data[23] = 'i';
  fieldNamesStr_data[19] = 'n';
  fieldNamesStr_data[24] = 'n';
  fieldNamesStr_data[25] = ')';
}

void b_custom_mex_logger(const emlrtStack *sp, uint32_T idx_in,
                         const real_T val_in[2])
{
  static const int32_T iv[2] = {1, 16};
  static const char_T valClass[6] = {'d', 'o', 'u', 'b', 'l', 'e'};
  emlrtStack b_st;
  emlrtStack st;
  emxArray_uint8_T *S_Data;
  struct1_T S;
  real_T S_Dims_data[2];
  int32_T S_Class_size[2];
  int32_T i;
  uint32_T actualIdx;
  char_T S_Class_data[6];
  uint8_T y[16];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &q_emlrtRSI;
  if (customCoderEnableLog(&st, idx_in)) {
    st.site = &q_emlrtRSI;
    if (!indexMapper(&st, idx_in)) {
      st.site = &q_emlrtRSI;
      actualIdx = b_indexMapper(&st, idx_in);
    } else {
      st.site = &q_emlrtRSI;
      if (!pIndexMap_not_empty) {
        S.ActualIndex = 0U;
        S.FieldNames.size[0] = 1;
        S.FieldNames.size[1] = 0;
        i = pIndexMap->size[0] * pIndexMap->size[1];
        pIndexMap->size[0] = 1;
        pIndexMap->size[1] = 1;
        emxEnsureCapacity_struct1_T(&st, pIndexMap, i, &c_emlrtRTEI);
        pIndexMap->data[0] = S;
        pIndexMap_not_empty = true;
        pBufferLen = 1U;
      }
      i = pIndexMap->size[1];
      if (((int32_T)idx_in < 1) || ((int32_T)idx_in > pIndexMap->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)idx_in, 1, i, &emlrtBCI, &st);
      }
      actualIdx = pIndexMap->data[(int32_T)idx_in - 1].ActualIndex;
    }
    st.site = &q_emlrtRSI;
    if (!buffers(&st, actualIdx)) {
      S_Class_size[0] = 1;
      S_Class_size[1] = 6;
      for (i = 0; i < 6; i++) {
        S_Class_data[i] = valClass[i];
      }
      emxInit_uint8_T(sp, &S_Data, 2, &c_emlrtRTEI, true);
      S_Dims_data[0] = 2.0;
      S_Dims_data[1] = 1.0;
      i = S_Data->size[0] * S_Data->size[1];
      S_Data->size[0] = 1;
      S_Data->size[1] = 1;
      emxEnsureCapacity_uint8_T(sp, S_Data, i, &c_emlrtRTEI);
      S_Data->data[0] = 0U;
      st.site = &q_emlrtRSI;
      b_buffers(&st, actualIdx, S_Class_data, S_Class_size, S_Dims_data, false,
                S_Data, 1U);
      emxFree_uint8_T(&S_Data);
    }
    st.site = &q_emlrtRSI;
    memcpy((void *)&y[0], (void *)&val_in[0],
           (uint32_T)((size_t)16 * sizeof(uint8_T)));
    st.site = &q_emlrtRSI;
    if (actualIdx > 1U) {
      b_st.site = &l_emlrtRSI;
      c_buffers(&b_st, actualIdx, y, iv);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void buffers_free(void)
{
  emxFree_struct0_T(&pBuffers);
}

void buffers_init(const emlrtStack *sp)
{
  emxInit_struct0_T(sp, &pBuffers, 2, &c_emlrtRTEI, false);
  pBuffers_not_empty = false;
}

void c_custom_mex_logger(const emlrtStack *sp, uint32_T idx_in,
                         const real_T val_in[3])
{
  static const int32_T iv[2] = {1, 24};
  static const char_T valClass[6] = {'d', 'o', 'u', 'b', 'l', 'e'};
  emlrtStack b_st;
  emlrtStack st;
  emxArray_uint8_T *S_Data;
  struct1_T S;
  real_T S_Dims_data[2];
  int32_T S_Class_size[2];
  int32_T i;
  uint32_T actualIdx;
  char_T S_Class_data[6];
  uint8_T y[24];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &q_emlrtRSI;
  if (customCoderEnableLog(&st, idx_in)) {
    st.site = &q_emlrtRSI;
    if (!indexMapper(&st, idx_in)) {
      st.site = &q_emlrtRSI;
      actualIdx = b_indexMapper(&st, idx_in);
    } else {
      st.site = &q_emlrtRSI;
      if (!pIndexMap_not_empty) {
        S.ActualIndex = 0U;
        S.FieldNames.size[0] = 1;
        S.FieldNames.size[1] = 0;
        i = pIndexMap->size[0] * pIndexMap->size[1];
        pIndexMap->size[0] = 1;
        pIndexMap->size[1] = 1;
        emxEnsureCapacity_struct1_T(&st, pIndexMap, i, &c_emlrtRTEI);
        pIndexMap->data[0] = S;
        pIndexMap_not_empty = true;
        pBufferLen = 1U;
      }
      i = pIndexMap->size[1];
      if (((int32_T)idx_in < 1) || ((int32_T)idx_in > pIndexMap->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)idx_in, 1, i, &emlrtBCI, &st);
      }
      actualIdx = pIndexMap->data[(int32_T)idx_in - 1].ActualIndex;
    }
    st.site = &q_emlrtRSI;
    if (!buffers(&st, actualIdx)) {
      S_Class_size[0] = 1;
      S_Class_size[1] = 6;
      for (i = 0; i < 6; i++) {
        S_Class_data[i] = valClass[i];
      }
      emxInit_uint8_T(sp, &S_Data, 2, &c_emlrtRTEI, true);
      S_Dims_data[0] = 3.0;
      S_Dims_data[1] = 1.0;
      i = S_Data->size[0] * S_Data->size[1];
      S_Data->size[0] = 1;
      S_Data->size[1] = 1;
      emxEnsureCapacity_uint8_T(sp, S_Data, i, &c_emlrtRTEI);
      S_Data->data[0] = 0U;
      st.site = &q_emlrtRSI;
      b_buffers(&st, actualIdx, S_Class_data, S_Class_size, S_Dims_data, false,
                S_Data, 1U);
      emxFree_uint8_T(&S_Data);
    }
    st.site = &q_emlrtRSI;
    memcpy((void *)&y[0], (void *)&val_in[0],
           (uint32_T)((size_t)24 * sizeof(uint8_T)));
    st.site = &q_emlrtRSI;
    if (actualIdx > 1U) {
      b_st.site = &l_emlrtRSI;
      c_buffers(&b_st, actualIdx, y, iv);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void customCoderEnableLog_free(void)
{
  emxFree_boolean_T(&pEnabled);
}

void customCoderEnableLog_init(const emlrtStack *sp)
{
  emxInit_boolean_T(sp, &pEnabled, 2, &c_emlrtRTEI, false);
}

void custom_mex_logger(const emlrtStack *sp, uint32_T idx_in, real_T val_in)
{
  static const int32_T iv[2] = {1, 8};
  static const char_T valClass[6] = {'d', 'o', 'u', 'b', 'l', 'e'};
  emlrtStack b_st;
  emlrtStack st;
  emxArray_uint8_T *S_Data;
  struct1_T S;
  real_T S_Dims_data[2];
  int32_T S_Class_size[2];
  int32_T i;
  uint32_T actualIdx;
  char_T S_Class_data[6];
  uint8_T y[8];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &l_emlrtRSI;
  if (customCoderEnableLog(&st, idx_in)) {
    st.site = &l_emlrtRSI;
    if (!indexMapper(&st, idx_in)) {
      st.site = &l_emlrtRSI;
      actualIdx = b_indexMapper(&st, idx_in);
    } else {
      st.site = &l_emlrtRSI;
      if (!pIndexMap_not_empty) {
        S.ActualIndex = 0U;
        S.FieldNames.size[0] = 1;
        S.FieldNames.size[1] = 0;
        i = pIndexMap->size[0] * pIndexMap->size[1];
        pIndexMap->size[0] = 1;
        pIndexMap->size[1] = 1;
        emxEnsureCapacity_struct1_T(&st, pIndexMap, i, &c_emlrtRTEI);
        pIndexMap->data[0] = S;
        pIndexMap_not_empty = true;
        pBufferLen = 1U;
      }
      i = pIndexMap->size[1];
      if (((int32_T)idx_in < 1) || ((int32_T)idx_in > pIndexMap->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)idx_in, 1, i, &emlrtBCI, &st);
      }
      actualIdx = pIndexMap->data[(int32_T)idx_in - 1].ActualIndex;
    }
    st.site = &l_emlrtRSI;
    if (!buffers(&st, actualIdx)) {
      S_Class_size[0] = 1;
      S_Class_size[1] = 6;
      for (i = 0; i < 6; i++) {
        S_Class_data[i] = valClass[i];
      }
      emxInit_uint8_T(sp, &S_Data, 2, &c_emlrtRTEI, true);
      S_Dims_data[0] = 1.0;
      S_Dims_data[1] = 1.0;
      i = S_Data->size[0] * S_Data->size[1];
      S_Data->size[0] = 1;
      S_Data->size[1] = 1;
      emxEnsureCapacity_uint8_T(sp, S_Data, i, &c_emlrtRTEI);
      S_Data->data[0] = 0U;
      st.site = &l_emlrtRSI;
      b_buffers(&st, actualIdx, S_Class_data, S_Class_size, S_Dims_data, false,
                S_Data, 1U);
      emxFree_uint8_T(&S_Data);
    }
    st.site = &l_emlrtRSI;
    memcpy((void *)&y[0], (void *)&val_in,
           (uint32_T)((size_t)8 * sizeof(uint8_T)));
    st.site = &l_emlrtRSI;
    if (actualIdx > 1U) {
      b_st.site = &l_emlrtRSI;
      c_buffers(&b_st, actualIdx, y, iv);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void d_custom_mex_logger(const emlrtStack *sp, uint32_T idx_in,
                         const real_T val_in_xoffset[3],
                         const real_T val_in_gain[3], real_T val_in_ymin)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  struct1_T S;
  int32_T tmp_size[2];
  int32_T i;
  uint32_T fieldIdx;
  uint32_T qY;
  char_T tmp_data[26];
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &q_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (customCoderEnableLog(&st, idx_in)) {
    st.site = &q_emlrtRSI;
    b_st.site = &l_emlrtRSI;
    if (!indexMapper(&b_st, idx_in)) {
      parse_struct(tmp_data, tmp_size);
      b_st.site = &l_emlrtRSI;
      fieldIdx = c_indexMapper(&b_st, idx_in, tmp_data);
    } else {
      b_st.site = &l_emlrtRSI;
      if (!pIndexMap_not_empty) {
        S.ActualIndex = 0U;
        S.FieldNames.size[0] = 1;
        S.FieldNames.size[1] = 0;
        i = pIndexMap->size[0] * pIndexMap->size[1];
        pIndexMap->size[0] = 1;
        pIndexMap->size[1] = 1;
        emxEnsureCapacity_struct1_T(&b_st, pIndexMap, i, &c_emlrtRTEI);
        pIndexMap->data[0] = S;
        pIndexMap_not_empty = true;
        pBufferLen = 1U;
      }
      i = pIndexMap->size[1];
      if (((int32_T)idx_in < 1) || ((int32_T)idx_in > pIndexMap->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)idx_in, 1, i, &emlrtBCI, &b_st);
      }
      fieldIdx = pIndexMap->data[(int32_T)idx_in - 1].ActualIndex;
    }
    b_st.site = &l_emlrtRSI;
    c_st.site = &s_emlrtRSI;
    generic_logger_impl_val(&c_st, fieldIdx, val_in_xoffset);
    qY = fieldIdx + 1U;
    if (fieldIdx + 1U < fieldIdx) {
      qY = MAX_uint32_T;
    }
    c_st.site = &s_emlrtRSI;
    generic_logger_impl_val(&c_st, qY, val_in_gain);
    fieldIdx = qY + 1U;
    if (qY + 1U < qY) {
      fieldIdx = MAX_uint32_T;
    }
    c_st.site = &s_emlrtRSI;
    b_generic_logger_impl_val(&c_st, fieldIdx, val_in_ymin);
  }
}

void e_custom_mex_logger(const emlrtStack *sp, uint32_T idx_in,
                         real_T val_in_ymin, const real_T val_in_gain[2],
                         const real_T val_in_xoffset[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  struct1_T S;
  int32_T tmp_size[2];
  int32_T i;
  uint32_T fieldIdx;
  uint32_T qY;
  char_T tmp_data[26];
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &q_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (customCoderEnableLog(&st, idx_in)) {
    st.site = &q_emlrtRSI;
    b_st.site = &l_emlrtRSI;
    if (!indexMapper(&b_st, idx_in)) {
      b_parse_struct(tmp_data, tmp_size);
      b_st.site = &l_emlrtRSI;
      fieldIdx = c_indexMapper(&b_st, idx_in, tmp_data);
    } else {
      b_st.site = &l_emlrtRSI;
      if (!pIndexMap_not_empty) {
        S.ActualIndex = 0U;
        S.FieldNames.size[0] = 1;
        S.FieldNames.size[1] = 0;
        i = pIndexMap->size[0] * pIndexMap->size[1];
        pIndexMap->size[0] = 1;
        pIndexMap->size[1] = 1;
        emxEnsureCapacity_struct1_T(&b_st, pIndexMap, i, &c_emlrtRTEI);
        pIndexMap->data[0] = S;
        pIndexMap_not_empty = true;
        pBufferLen = 1U;
      }
      i = pIndexMap->size[1];
      if (((int32_T)idx_in < 1) || ((int32_T)idx_in > pIndexMap->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)idx_in, 1, i, &emlrtBCI, &b_st);
      }
      fieldIdx = pIndexMap->data[(int32_T)idx_in - 1].ActualIndex;
    }
    b_st.site = &l_emlrtRSI;
    c_st.site = &s_emlrtRSI;
    b_generic_logger_impl_val(&c_st, fieldIdx, val_in_ymin);
    qY = fieldIdx + 1U;
    if (fieldIdx + 1U < fieldIdx) {
      qY = MAX_uint32_T;
    }
    c_st.site = &s_emlrtRSI;
    c_generic_logger_impl_val(&c_st, qY, val_in_gain);
    fieldIdx = qY + 1U;
    if (qY + 1U < qY) {
      fieldIdx = MAX_uint32_T;
    }
    c_st.site = &s_emlrtRSI;
    c_generic_logger_impl_val(&c_st, fieldIdx, val_in_xoffset);
  }
}

void f_custom_mex_logger(const emlrtStack *sp, emxArray_struct0_T *data,
                         emxArray_struct1_T *bufferInfo)
{
  static const char_T valClass[5] = {'u', 'i', 'n', 't', '8'};
  emlrtStack st;
  struct0_T S;
  struct1_T b_S;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &q_emlrtRSI;
  emxInitStruct_struct0_T(&st, &S, &c_emlrtRTEI, true);
  if (!pBuffers_not_empty) {
    S.Class.size[0] = 1;
    S.Class.size[1] = 5;
    for (i = 0; i < 5; i++) {
      S.Class.data[i] = valClass[i];
    }
    S.Dims.size[0] = 1;
    S.Dims.size[1] = 2;
    S.Dims.data[0] = 1.0;
    S.Dims.data[1] = 1.0;
    S.Varsize = false;
    S.NumericType.size[0] = 1;
    S.NumericType.size[1] = 0;
    S.Fimath.size[0] = 1;
    S.Fimath.size[1] = 0;
    i = S.Data->size[0] * S.Data->size[1];
    S.Data->size[0] = 1;
    S.Data->size[1] = 1;
    emxEnsureCapacity_uint8_T(&st, S.Data, i, &c_emlrtRTEI);
    S.Data->data[0] = 0U;
    S.DataSize = 1U;
    i = pBuffers->size[0] * pBuffers->size[1];
    pBuffers->size[0] = 1;
    pBuffers->size[1] = 1;
    emxEnsureCapacity_struct0_T(&st, pBuffers, i, &c_emlrtRTEI);
    emxCopyStruct_struct0_T(&st, &pBuffers->data[0], &S, &c_emlrtRTEI);
    pBuffers_not_empty = true;
  }
  i = data->size[0] * data->size[1];
  data->size[0] = 1;
  data->size[1] = pBuffers->size[1];
  emxEnsureCapacity_struct0_T(&st, data, i, &c_emlrtRTEI);
  loop_ub = pBuffers->size[1];
  for (i = 0; i < loop_ub; i++) {
    emxCopyStruct_struct0_T(&st, &data->data[i], &pBuffers->data[i],
                            &c_emlrtRTEI);
  }
  emxCopyStruct_struct0_T(&st, &S, &pBuffers->data[0], &c_emlrtRTEI);
  i = pBuffers->size[0] * pBuffers->size[1];
  pBuffers->size[0] = 1;
  pBuffers->size[1] = 1;
  emxEnsureCapacity_struct0_T(&st, pBuffers, i, &c_emlrtRTEI);
  emxCopyStruct_struct0_T(&st, &pBuffers->data[0], &S, &c_emlrtRTEI);
  pBuffers_not_empty = true;
  st.site = &q_emlrtRSI;
  emxFreeStruct_struct0_T(&S);
  if (!pIndexMap_not_empty) {
    b_S.ActualIndex = 0U;
    b_S.FieldNames.size[0] = 1;
    b_S.FieldNames.size[1] = 0;
    i = pIndexMap->size[0] * pIndexMap->size[1];
    pIndexMap->size[0] = 1;
    pIndexMap->size[1] = 1;
    emxEnsureCapacity_struct1_T(&st, pIndexMap, i, &c_emlrtRTEI);
    pIndexMap->data[0] = b_S;
    pIndexMap_not_empty = true;
    pBufferLen = 1U;
  }
  i = bufferInfo->size[0] * bufferInfo->size[1];
  bufferInfo->size[0] = 1;
  bufferInfo->size[1] = pIndexMap->size[1];
  emxEnsureCapacity_struct1_T(&st, bufferInfo, i, &c_emlrtRTEI);
  loop_ub = pIndexMap->size[1];
  for (i = 0; i < loop_ub; i++) {
    bufferInfo->data[i] = pIndexMap->data[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void indexMapper_free(void)
{
  emxFree_struct1_T(&pIndexMap);
}

void indexMapper_init(const emlrtStack *sp)
{
  emxInit_struct1_T(sp, &pIndexMap, 2, &c_emlrtRTEI, false);
  pIndexMap_not_empty = false;
}

void pInit_not_empty_init(void)
{
  pInit_not_empty = false;
}
