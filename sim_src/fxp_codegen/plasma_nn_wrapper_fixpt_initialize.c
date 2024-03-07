/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * plasma_nn_wrapper_fixpt_initialize.c
 *
 * Code generation for function 'plasma_nn_wrapper_fixpt_initialize'
 *
 */

/* Include files */
#include "plasma_nn_wrapper_fixpt_initialize.h"
#include "_coder_plasma_nn_wrapper_fixpt_mex.h"
#include "plasma_nn_wrapper_fixpt_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

static emlrtMCInfo emlrtMCI = {
    -1, /* lineNo */
    -1, /* colNo */
    "", /* fName */
    ""  /* pName */
};

/* Function Declarations */
static const mxArray *
fimath(const emlrtStack *sp, const char_T *b, const char_T *c, const char_T *d,
       const char_T *e, const char_T *f, const char_T *g, const char_T *h,
       const char_T *i, const char_T *j, const char_T *k, const char_T *l,
       const char_T *m, const char_T *n, real_T o, const char_T *p, real_T q,
       const char_T *r, real_T s, const char_T *t, real_T u, const char_T *v,
       real_T w, const char_T *x, real_T y, const char_T *ab, real_T bb,
       const char_T *cb, real_T db, const char_T *eb, real_T fb,
       const char_T *gb, real_T hb, const char_T *ib, real_T jb,
       const char_T *kb, real_T lb, const char_T *mb, boolean_T nb,
       const char_T *ob, real_T pb, const char_T *qb, real_T rb,
       emlrtMCInfo *location);

static const mxArray *numerictype(const emlrtStack *sp, const char_T *b,
                                  real_T c, const char_T *d, real_T e,
                                  const char_T *f, real_T g, const char_T *h,
                                  real_T i, const char_T *j, real_T k,
                                  emlrtMCInfo *location);

static void plasma_nn_wrapper_fixpt_once(const emlrtStack *sp);

/* Function Definitions */
static const mxArray *
fimath(const emlrtStack *sp, const char_T *b, const char_T *c, const char_T *d,
       const char_T *e, const char_T *f, const char_T *g, const char_T *h,
       const char_T *i, const char_T *j, const char_T *k, const char_T *l,
       const char_T *m, const char_T *n, real_T o, const char_T *p, real_T q,
       const char_T *r, real_T s, const char_T *t, real_T u, const char_T *v,
       real_T w, const char_T *x, real_T y, const char_T *ab, real_T bb,
       const char_T *cb, real_T db, const char_T *eb, real_T fb,
       const char_T *gb, real_T hb, const char_T *ib, real_T jb,
       const char_T *kb, real_T lb, const char_T *mb, boolean_T nb,
       const char_T *ob, real_T pb, const char_T *qb, real_T rb,
       emlrtMCInfo *location)
{
  const mxArray *pArrays[42];
  const mxArray *b_m;
  pArrays[0] = emlrtCreateString((const char_T *)b);
  pArrays[1] = emlrtCreateString((const char_T *)c);
  pArrays[2] = emlrtCreateString((const char_T *)d);
  pArrays[3] = emlrtCreateString((const char_T *)e);
  pArrays[4] = emlrtCreateString((const char_T *)f);
  pArrays[5] = emlrtCreateString((const char_T *)g);
  pArrays[6] = emlrtCreateString((const char_T *)h);
  pArrays[7] = emlrtCreateString((const char_T *)i);
  pArrays[8] = emlrtCreateString((const char_T *)j);
  pArrays[9] = emlrtCreateString((const char_T *)k);
  pArrays[10] = emlrtCreateString((const char_T *)l);
  pArrays[11] = emlrtCreateString((const char_T *)m);
  pArrays[12] = emlrtCreateString((const char_T *)n);
  pArrays[13] = emlrtCreateDoubleScalar(o);
  pArrays[14] = emlrtCreateString((const char_T *)p);
  pArrays[15] = emlrtCreateDoubleScalar(q);
  pArrays[16] = emlrtCreateString((const char_T *)r);
  pArrays[17] = emlrtCreateDoubleScalar(s);
  pArrays[18] = emlrtCreateString((const char_T *)t);
  pArrays[19] = emlrtCreateDoubleScalar(u);
  pArrays[20] = emlrtCreateString((const char_T *)v);
  pArrays[21] = emlrtCreateDoubleScalar(w);
  pArrays[22] = emlrtCreateString((const char_T *)x);
  pArrays[23] = emlrtCreateDoubleScalar(y);
  pArrays[24] = emlrtCreateString((const char_T *)ab);
  pArrays[25] = emlrtCreateDoubleScalar(bb);
  pArrays[26] = emlrtCreateString((const char_T *)cb);
  pArrays[27] = emlrtCreateDoubleScalar(db);
  pArrays[28] = emlrtCreateString((const char_T *)eb);
  pArrays[29] = emlrtCreateDoubleScalar(fb);
  pArrays[30] = emlrtCreateString((const char_T *)gb);
  pArrays[31] = emlrtCreateDoubleScalar(hb);
  pArrays[32] = emlrtCreateString((const char_T *)ib);
  pArrays[33] = emlrtCreateDoubleScalar(jb);
  pArrays[34] = emlrtCreateString((const char_T *)kb);
  pArrays[35] = emlrtCreateDoubleScalar(lb);
  pArrays[36] = emlrtCreateString((const char_T *)mb);
  pArrays[37] = emlrtCreateLogicalScalar(nb);
  pArrays[38] = emlrtCreateString((const char_T *)ob);
  pArrays[39] = emlrtCreateDoubleScalar(pb);
  pArrays[40] = emlrtCreateString((const char_T *)qb);
  pArrays[41] = emlrtCreateDoubleScalar(rb);
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &b_m, 42, &pArrays[0],
                               (const char_T *)"fimath", true, location);
}

static const mxArray *numerictype(const emlrtStack *sp, const char_T *b,
                                  real_T c, const char_T *d, real_T e,
                                  const char_T *f, real_T g, const char_T *h,
                                  real_T i, const char_T *j, real_T k,
                                  emlrtMCInfo *location)
{
  const mxArray *pArrays[10];
  const mxArray *m;
  pArrays[0] = emlrtCreateString((const char_T *)b);
  pArrays[1] = emlrtCreateDoubleScalar(c);
  pArrays[2] = emlrtCreateString((const char_T *)d);
  pArrays[3] = emlrtCreateDoubleScalar(e);
  pArrays[4] = emlrtCreateString((const char_T *)f);
  pArrays[5] = emlrtCreateDoubleScalar(g);
  pArrays[6] = emlrtCreateString((const char_T *)h);
  pArrays[7] = emlrtCreateDoubleScalar(i);
  pArrays[8] = emlrtCreateString((const char_T *)j);
  pArrays[9] = emlrtCreateDoubleScalar(k);
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 10, &pArrays[0],
                               (const char_T *)"numerictype", true, location);
}

static void plasma_nn_wrapper_fixpt_once(const emlrtStack *sp)
{
  mex_InitInfAndNan();
  emlrtAssignP(&c_eml_mx, NULL);
  emlrtAssignP(&b_eml_mx, NULL);
  emlrtAssignP(&eml_mx, NULL);
  emlrtAssignP(&c_eml_mx, numerictype(sp, "WordLength", 3.0, "FractionLength",
                                      0.0, "BinaryPoint", 0.0, "Slope", 1.0,
                                      "FixedExponent", 0.0, &emlrtMCI));
  emlrtAssignP(&b_eml_mx,
               numerictype(sp, "WordLength", 22.0, "FractionLength", 20.0,
                           "BinaryPoint", 20.0, "Slope", 9.5367431640625E-7,
                           "FixedExponent", -20.0, &emlrtMCI));
  emlrtAssignP(
      &eml_mx,
      fimath(sp, "RoundMode", "floor", "RoundingMethod", "Floor",
             "OverflowMode", "wrap", "OverflowAction", "Wrap", "ProductMode",
             "FullPrecision", "SumMode", "FullPrecision", "ProductWordLength",
             32.0, "SumWordLength", 32.0, "MaxProductWordLength", 128.0,
             "MaxSumWordLength", 128.0, "ProductFractionLength", 30.0,
             "ProductFixedExponent", -30.0, "SumFractionLength", 30.0,
             "SumFixedExponent", -30.0, "SumSlopeAdjustmentFactor", 1.0,
             "SumBias", 0.0, "ProductSlopeAdjustmentFactor", 1.0, "ProductBias",
             0.0, "CastBeforeSum", true, "SumSlope", 9.3132257461547852E-10,
             "ProductSlope", 9.3132257461547852E-10, &emlrtMCI));
}

void plasma_nn_wrapper_fixpt_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 3U, (const char_T *)"ForceOff");
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, (const char_T *)"fixed_point_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    plasma_nn_wrapper_fixpt_once(&st);
  }
}

/* End of code generation (plasma_nn_wrapper_fixpt_initialize.c) */
