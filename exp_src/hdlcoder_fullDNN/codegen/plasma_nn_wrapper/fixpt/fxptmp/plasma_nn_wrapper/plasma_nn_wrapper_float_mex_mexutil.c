#include "plasma_nn_wrapper_float_mex_mexutil.h"
#include "plasma_nn_wrapper_float_mex_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

void emlrtInitVarDataTables(emlrtLocationLoggingDataType dataTables[70])
{
  int32_T i;
  for (i = 0; i < 70; i++) {
    dataTables[i].SimMin = rtInf;
    dataTables[i].SimMax = rtMinusInf;
    dataTables[i].OverflowWraps = 0;
    dataTables[i].Saturations = 0;
    dataTables[i].IsAlwaysInteger = true;
    dataTables[i].HistogramTable = (emlrtLocationLoggingHistogramType *)NULL;
  }
}

void emlrt_update_log_2(const real_T in[3],
                        emlrtLocationLoggingDataType table[], int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  real_T localMax;
  real_T localMin;
  int32_T i;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;

    if (in[0] < localMin) {
      localMin = in[0];
    }
    if (in[0] > localMax) {
      localMax = in[0];
    }

    if (in[1] < localMin) {
      localMin = in[1];
    }
    if (in[1] > localMax) {
      localMax = in[1];
    }

    if (in[2] < localMin) {
      localMin = in[2];
    }
    if (in[2] > localMax) {
      localMax = in[2];
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < 3)) {
      if (in[i] != muDoubleScalarFloor(in[i])) {
        b_table[0U].IsAlwaysInteger = false;
      }
      i++;
    }
  }
}
