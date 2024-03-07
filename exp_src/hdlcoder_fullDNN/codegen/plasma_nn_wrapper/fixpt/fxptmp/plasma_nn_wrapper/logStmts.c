#include "logStmts.h"
#include "custom_mex_logger.h"
#include "plasma_nn_wrapper_float_mex_data.h"
#include "rt_nonfinite.h"

static emlrtRSInfo k_emlrtRSI = {1, "logStmts",
                                 "/usr/local/MATLAB/R2021a/toolbox/coder/"
                                 "float2fixed/custom_logger/logStmts.p"};

void logStmts(const emlrtStack *sp)
{
  emlrtStack st;
  real_T b_s_gain[3];
  real_T s_xoffset[3];
  real_T b_s_xoffset[2];
  real_T s_gain[2];
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &k_emlrtRSI;
  custom_mex_logger(&st, 0U, 0.0);
  s_gain[0] = 0.0;
  s_gain[1] = 0.0;
  st.site = &k_emlrtRSI;
  b_custom_mex_logger(&st, 0U, s_gain);
  s_xoffset[0] = 0.0;
  s_xoffset[1] = 0.0;
  s_xoffset[2] = 0.0;
  st.site = &k_emlrtRSI;
  c_custom_mex_logger(&st, 0U, s_xoffset);
  s_xoffset[0] = 0.0;
  b_s_gain[0] = 0.0;
  s_xoffset[1] = 0.0;
  b_s_gain[1] = 0.0;
  s_xoffset[2] = 0.0;
  b_s_gain[2] = 0.0;
  st.site = &k_emlrtRSI;
  d_custom_mex_logger(&st, 0U, s_xoffset, b_s_gain, 0.0);
  s_gain[0] = 0.0;
  b_s_xoffset[0] = 0.0;
  s_gain[1] = 0.0;
  b_s_xoffset[1] = 0.0;
  st.site = &k_emlrtRSI;
  e_custom_mex_logger(&st, 0U, 0.0, s_gain, b_s_xoffset);
}
