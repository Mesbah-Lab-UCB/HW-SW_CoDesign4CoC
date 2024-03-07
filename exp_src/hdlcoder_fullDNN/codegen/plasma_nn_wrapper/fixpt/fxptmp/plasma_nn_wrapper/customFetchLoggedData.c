#include "customFetchLoggedData.h"
#include "custom_mex_logger.h"
#include "plasma_nn_wrapper_float_mex_data.h"
#include "plasma_nn_wrapper_float_mex_types.h"
#include "rt_nonfinite.h"
#include <string.h>

static emlrtRSInfo u_emlrtRSI = {
    1, "customFetchLoggedData",
    "/usr/local/MATLAB/R2021a/toolbox/coder/float2fixed/custom_logger/"
    "customFetchLoggedData.p"};

void customFetchLoggedData(const emlrtStack *sp, emxArray_struct0_T *data,
                           emxArray_struct1_T *dataInfo,
                           char_T dataExprIdMapping[690], real_T *numLoggedExpr)
{
  static const char_T cv[690] = {
      'p', 'l', 'a', 's', 'm', 'a', '_', 'n', 'n', '_', 'w', 'r', 'a', 'p',
      'p', 'e', 'r', ',', '/', 'h', 'o', 'm', 'e', '/', 'k', 'i', 'm', 'b',
      'e', 'r', 'l', 'y', 'c', 'h', 'a', 'n', '/', 'D', 'e', 's', 'k', 't',
      'o', 'p', '/', 'D', 'N', 'N', '_', 'G', 'e', 'n', 'e', 'r', 'a', 'l',
      'i', 't', 'y', '/', 'm', 'a', 't', 'l', 'a', 'b', '/', 'h', 'd', 'l',
      'c', 'o', 'd', 'e', 'r', '_', 'f', 'u', 'l', 'l', 'D', 'N', 'N', '/',
      'p', 'l', 'a', 's', 'm', 'a', '_', 'n', 'n', '_', 'w', 'r', 'a', 'p',
      'p', 'e', 'r', '.', 'm', '$', '$', 'i', 'n', 'p', 'u', 't', 's', '$',
      '$', '<', '>', 'x', '1', '_', '1', ',', '2', '<', '>', 'x', '1', '_',
      '2', ',', '3', '<', '>', 'x', '1', '_', '3', ',', '4', '$', '$', 'o',
      'u', 't', 'p', 'u', 't', 's', '$', '$', '<', '>', 'y', '1', '_', '1',
      ',', '5', '<', '>', 'y', '1', '_', '2', ',', '6', ';', 'm', 'a', 'p',
      'm', 'i', 'n', 'm', 'a', 'x', '_', 'a', 'p', 'p', 'l', 'y', ',', '/',
      'h', 'o', 'm', 'e', '/', 'k', 'i', 'm', 'b', 'e', 'r', 'l', 'y', 'c',
      'h', 'a', 'n', '/', 'D', 'e', 's', 'k', 't', 'o', 'p', '/', 'D', 'N',
      'N', '_', 'G', 'e', 'n', 'e', 'r', 'a', 'l', 'i', 't', 'y', '/', 'm',
      'a', 't', 'l', 'a', 'b', '/', 'h', 'd', 'l', 'c', 'o', 'd', 'e', 'r',
      '_', 'f', 'u', 'l', 'l', 'D', 'N', 'N', '/', 'p', 'l', 'a', 's', 'm',
      'a', '_', 'n', 'n', '.', 'm', '$', '$', 'i', 'n', 'p', 'u', 't', 's',
      '$', '$', '<', '>', 'x', ',', '7', '<', '>', 's', 'e', 't', 't', 'i',
      'n', 'g', 's', ',', '8', '$', '$', 'o', 'u', 't', 'p', 'u', 't', 's',
      '$', '$', '<', '>', 'y', ',', '9', ';', 'p', 'o', 's', 'l', 'i', 'n',
      '_', 'a', 'p', 'p', 'l', 'y', ',', '/', 'h', 'o', 'm', 'e', '/', 'k',
      'i', 'm', 'b', 'e', 'r', 'l', 'y', 'c', 'h', 'a', 'n', '/', 'D', 'e',
      's', 'k', 't', 'o', 'p', '/', 'D', 'N', 'N', '_', 'G', 'e', 'n', 'e',
      'r', 'a', 'l', 'i', 't', 'y', '/', 'm', 'a', 't', 'l', 'a', 'b', '/',
      'h', 'd', 'l', 'c', 'o', 'd', 'e', 'r', '_', 'f', 'u', 'l', 'l', 'D',
      'N', 'N', '/', 'p', 'l', 'a', 's', 'm', 'a', '_', 'n', 'n', '.', 'm',
      '$', '$', 'i', 'n', 'p', 'u', 't', 's', '$', '$', '<', '>', 'n', ',',
      '1', '0', '$', '$', 'o', 'u', 't', 'p', 'u', 't', 's', '$', '$', '<',
      '>', 'a', ',', '1', '1', ';', 'm', 'a', 'p', 'm', 'i', 'n', 'm', 'a',
      'x', '_', 'r', 'e', 'v', 'e', 'r', 's', 'e', ',', '/', 'h', 'o', 'm',
      'e', '/', 'k', 'i', 'm', 'b', 'e', 'r', 'l', 'y', 'c', 'h', 'a', 'n',
      '/', 'D', 'e', 's', 'k', 't', 'o', 'p', '/', 'D', 'N', 'N', '_', 'G',
      'e', 'n', 'e', 'r', 'a', 'l', 'i', 't', 'y', '/', 'm', 'a', 't', 'l',
      'a', 'b', '/', 'h', 'd', 'l', 'c', 'o', 'd', 'e', 'r', '_', 'f', 'u',
      'l', 'l', 'D', 'N', 'N', '/', 'p', 'l', 'a', 's', 'm', 'a', '_', 'n',
      'n', '.', 'm', '$', '$', 'i', 'n', 'p', 'u', 't', 's', '$', '$', '<',
      '>', 'y', ',', '1', '2', '<', '>', 's', 'e', 't', 't', 'i', 'n', 'g',
      's', ',', '1', '3', '$', '$', 'o', 'u', 't', 'p', 'u', 't', 's', '$',
      '$', '<', '>', 'x', ',', '1', '4', ';', 'p', 'l', 'a', 's', 'm', 'a',
      '_', 'n', 'n', ',', '/', 'h', 'o', 'm', 'e', '/', 'k', 'i', 'm', 'b',
      'e', 'r', 'l', 'y', 'c', 'h', 'a', 'n', '/', 'D', 'e', 's', 'k', 't',
      'o', 'p', '/', 'D', 'N', 'N', '_', 'G', 'e', 'n', 'e', 'r', 'a', 'l',
      'i', 't', 'y', '/', 'm', 'a', 't', 'l', 'a', 'b', '/', 'h', 'd', 'l',
      'c', 'o', 'd', 'e', 'r', '_', 'f', 'u', 'l', 'l', 'D', 'N', 'N', '/',
      'p', 'l', 'a', 's', 'm', 'a', '_', 'n', 'n', '.', 'm', '$', '$', 'i',
      'n', 'p', 'u', 't', 's', '$', '$', '<', '>', 'x', '1', ',', '1', '5',
      '$', '$', 'o', 'u', 't', 'p', 'u', 't', 's', '$', '$', '<', '>', 'y',
      '1', ',', '1', '6'};
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  memcpy(&dataExprIdMapping[0], &cv[0], 690U * sizeof(char_T));
  st.site = &u_emlrtRSI;
  f_custom_mex_logger(&st, data, dataInfo);
  *numLoggedExpr = (real_T)dataInfo->size[1] - 1.0;
}
