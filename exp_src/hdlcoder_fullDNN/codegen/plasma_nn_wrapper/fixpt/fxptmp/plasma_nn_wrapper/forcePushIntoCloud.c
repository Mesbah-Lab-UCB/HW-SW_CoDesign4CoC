#include "forcePushIntoCloud.h"
#include "plasma_nn_wrapper_float_mex_data.h"
#include "plasma_nn_wrapper_float_mex_mexutil.h"
#include "rt_nonfinite.h"

void forcePushIntoCloud(const emlrtStack *sp)
{
  (void)sp;
  emlrtInitVarDataTables(emlrtLocationLoggingDataTables);
}
