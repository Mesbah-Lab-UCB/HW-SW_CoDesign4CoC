#include "plasma_nn.h"
#include "custom_mex_logger.h"
#include "plasma_nn_wrapper_float_mex_data.h"
#include "plasma_nn_wrapper_float_mex_mexutil.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

static void emlrt_update_log_5(const real_T in_data[], const int32_T in_size[1],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static void emlrt_update_log_6(const boolean_T in[3],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static void emlrt_update_log_5(const real_T in_data[], const int32_T in_size[1],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  real_T localMax;
  real_T localMin;
  int32_T i;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;
    for (i = 0; i < in_size[0]; i++) {

      if (in_data[i] < localMin) {
        localMin = in_data[i];
      }
      if (in_data[i] > localMax) {
        localMax = in_data[i];
      }
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < in_size[0])) {
      if (in_data[i] != muDoubleScalarFloor(in_data[i])) {
        b_table[0U].IsAlwaysInteger = false;
      }
      i++;
    }
  }
}

static void emlrt_update_log_6(const boolean_T in[3],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  boolean_T localMax;
  boolean_T localMin;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = (b_table[0U].SimMin > 0.0);
    localMax = (b_table[0U].SimMax > 0.0);

    if ((int32_T)in[0] < (int32_T)localMin) {
      localMin = in[0];
    }
    if ((int32_T)in[0] > (int32_T)localMax) {
      localMax = in[0];
    }

    if ((int32_T)in[1] < (int32_T)localMin) {
      localMin = in[1];
    }
    if ((int32_T)in[1] > (int32_T)localMax) {
      localMax = in[1];
    }

    if ((int32_T)in[2] < (int32_T)localMin) {
      localMin = in[2];
    }
    if ((int32_T)in[2] > (int32_T)localMax) {
      localMax = in[2];
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;
  }
}

void poslin_apply(const emlrtStack *sp, const real_T n[3], real_T a[3])
{
  emlrtStack st;
  real_T b_tmp_data[3];
  int32_T partialTrueCount;
  int32_T trueCount;
  int8_T tmp_data[3];
  boolean_T bv[3];
  st.prev = sp;
  st.tls = sp->tls;

  emlrt_update_log_2(n, emlrtLocationLoggingDataTables, 14);
  st.site = &j_emlrtRSI;
  c_custom_mex_logger(&st, 10U, n);
  covrtLogFcn(&emlrtCoverageInstance, 1U, 2U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 2U);
  a[0] = muDoubleScalarMax(0.0, n[0]);
  a[1] = muDoubleScalarMax(0.0, n[1]);
  a[2] = muDoubleScalarMax(0.0, n[2]);
  emlrt_update_log_2(a, emlrtLocationLoggingDataTables, 15);
  bv[0] = muDoubleScalarIsNaN(n[0]);
  bv[1] = muDoubleScalarIsNaN(n[1]);
  bv[2] = muDoubleScalarIsNaN(n[2]);
  emlrt_update_log_6(bv, emlrtLocationLoggingDataTables, 17);
  trueCount = 0;
  if (bv[0]) {
    trueCount = 1;
  }
  if (bv[1]) {
    trueCount++;
  }
  if (bv[2]) {
    trueCount++;
  }
  partialTrueCount = 0;
  if (bv[0]) {
    tmp_data[0] = 1;
    partialTrueCount = 1;
  }
  if (bv[1]) {
    tmp_data[partialTrueCount] = 2;
    partialTrueCount++;
  }
  if (bv[2]) {
    tmp_data[partialTrueCount] = 3;
  }
  for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++) {
    b_tmp_data[partialTrueCount] = rtNaN;
  }
  emlrt_update_log_5(b_tmp_data, *(int32_T(*)[1]) & trueCount,
                     emlrtLocationLoggingDataTables, 16);
  for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++) {
    a[tmp_data[partialTrueCount] - 1] = rtNaN;
  }
  st.site = &j_emlrtRSI;
  c_custom_mex_logger(&st, 11U, a);
}
