#include "plasma_nn_wrapper_float_mex_initialize.h"
#include "_coder_plasma_nn_wrapper_float_mex_mex.h"
#include "custom_mex_logger.h"
#include "plasma_nn_wrapper_float_mex_data.h"
#include "rt_nonfinite.h"

static void c_plasma_nn_wrapper_float_mex_o(const emlrtStack *sp);

static void c_plasma_nn_wrapper_float_mex_o(const emlrtStack *sp)
{
  emlrtStack st;
  mex_InitInfAndNan();
  st.prev = sp;
  st.tls = sp->tls;
  pInit_not_empty_init();

  covrtAllocateInstanceData(&emlrtCoverageInstance);

  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/kimberlychan/Desktop/DNN_Generality/matlab/"
                  "hdlcoder_fullDNN/plasma_nn_wrapper.m",
                  0U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "plasma_nn_wrapper", 0, -1, 135);

  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 59, -1, 131);

  covrtScriptStart(&emlrtCoverageInstance, 0U);

  covrtAllocateInstanceData(&emlrtCoverageInstance);

  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/kimberlychan/Desktop/DNN_Generality/matlab/"
                  "hdlcoder_fullDNN/plasma_nn.m",
                  1U, 4U, 4U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "plasma_nn", 0, -1, 2790);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 1U, "mapminmax_apply", 2879, -1,
               3039);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 2U, "poslin_apply", 3077, -1, 3148);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 3U, "mapminmax_reverse", 3211, -1,
               3375);

  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 353, -1, 2786);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 2922, -1, 3035);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 3110, -1, 3144);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 3U, 3256, -1, 3371);

  covrtScriptStart(&emlrtCoverageInstance, 1U);
  st.site = NULL;
  indexMapper_init(&st);
  st.site = NULL;
  buffers_init(&st);
  st.site = NULL;
  customCoderEnableLog_init(&st);
}

void plasma_nn_wrapper_float_mex_initialize(void)
{
  emlrtStack st = {NULL, NULL, NULL};
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    c_plasma_nn_wrapper_float_mex_o(&st);
  }
}
