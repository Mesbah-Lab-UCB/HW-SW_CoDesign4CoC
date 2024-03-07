#include "plasma_nn_wrapper.h"
#include "custom_mex_logger.h"
#include "plasma_nn.h"
#include "plasma_nn_wrapper_float_mex_data.h"
#include "plasma_nn_wrapper_float_mex_mexutil.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  real_T xoffset[3];
  real_T gain[3];
  real_T ymin;
} struct_T;
#endif

#ifndef typedef_b_struct_T
#define typedef_b_struct_T
typedef struct {
  real_T ymin;
  real_T gain[2];
  real_T xoffset[2];
} b_struct_T;
#endif

static emlrtRSInfo emlrtRSI = {3, "plasma_nn_wrapper",
                               "/home/kimberlychan/Desktop/DNN_Generality/"
                               "matlab/hdlcoder_fullDNN/plasma_nn_wrapper.m"};

static emlrtRSInfo b_emlrtRSI = {1, "plasma_nn_wrapper",
                                 "/home/kimberlychan/Desktop/DNN_Generality/"
                                 "matlab/hdlcoder_fullDNN/plasma_nn_wrapper.m"};

static emlrtRSInfo c_emlrtRSI = {56, "plasma_nn",
                                 "/home/kimberlychan/Desktop/DNN_Generality/"
                                 "matlab/hdlcoder_fullDNN/plasma_nn.m"};

static emlrtRSInfo d_emlrtRSI = {59, "plasma_nn",
                                 "/home/kimberlychan/Desktop/DNN_Generality/"
                                 "matlab/hdlcoder_fullDNN/plasma_nn.m"};

static emlrtRSInfo e_emlrtRSI = {62, "plasma_nn",
                                 "/home/kimberlychan/Desktop/DNN_Generality/"
                                 "matlab/hdlcoder_fullDNN/plasma_nn.m"};

static emlrtRSInfo f_emlrtRSI = {65, "plasma_nn",
                                 "/home/kimberlychan/Desktop/DNN_Generality/"
                                 "matlab/hdlcoder_fullDNN/plasma_nn.m"};

static emlrtRSInfo g_emlrtRSI = {68, "plasma_nn",
                                 "/home/kimberlychan/Desktop/DNN_Generality/"
                                 "matlab/hdlcoder_fullDNN/plasma_nn.m"};

static emlrtRSInfo h_emlrtRSI = {71, "plasma_nn",
                                 "/home/kimberlychan/Desktop/DNN_Generality/"
                                 "matlab/hdlcoder_fullDNN/plasma_nn.m"};

static emlrtRSInfo i_emlrtRSI = {77, "plasma_nn",
                                 "/home/kimberlychan/Desktop/DNN_Generality/"
                                 "matlab/hdlcoder_fullDNN/plasma_nn.m"};

static real_T emlrt_update_log_1(real_T in,
                                 emlrtLocationLoggingDataType table[],
                                 int32_T b_index);

static void emlrt_update_log_3(const real_T in[2],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static void emlrt_update_log_4(const struct_T *in,
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static void emlrt_update_log_7(const b_struct_T *in,
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static void emlrt_update_log_8(const real_T in[9],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static void emlrt_update_log_9(const real_T in[6],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static real_T emlrt_update_log_1(real_T in,
                                 emlrtLocationLoggingDataType table[],
                                 int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  real_T localMax;
  real_T localMin;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;

    if (in < localMin) {
      localMin = in;
    }
    if (in > localMax) {
      localMax = in;
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    if (in != muDoubleScalarFloor(in)) {
      b_table[0U].IsAlwaysInteger = false;
    }
  }
  return in;
}

static void emlrt_update_log_3(const real_T in[2],
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
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < 2)) {
      if (in[i] != muDoubleScalarFloor(in[i])) {
        b_table[0U].IsAlwaysInteger = false;
      }
      i++;
    }
  }
}

static void emlrt_update_log_4(const struct_T *in,
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

    if (in->xoffset[0] < localMin) {
      localMin = in->xoffset[0];
    }
    if (in->xoffset[0] > localMax) {
      localMax = in->xoffset[0];
    }

    if (in->xoffset[1] < localMin) {
      localMin = in->xoffset[1];
    }
    if (in->xoffset[1] > localMax) {
      localMax = in->xoffset[1];
    }

    if (in->xoffset[2] < localMin) {
      localMin = in->xoffset[2];
    }
    if (in->xoffset[2] > localMax) {
      localMax = in->xoffset[2];
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < 3)) {
      if (in->xoffset[i] != muDoubleScalarFloor(in->xoffset[i])) {
        b_table[0U].IsAlwaysInteger = false;
      }
      i++;
    }
    localMin = b_table[1U].SimMin;
    localMax = b_table[1U].SimMax;

    if (in->gain[0] < localMin) {
      localMin = in->gain[0];
    }
    if (in->gain[0] > localMax) {
      localMax = in->gain[0];
    }

    if (in->gain[1] < localMin) {
      localMin = in->gain[1];
    }
    if (in->gain[1] > localMax) {
      localMax = in->gain[1];
    }

    if (in->gain[2] < localMin) {
      localMin = in->gain[2];
    }
    if (in->gain[2] > localMax) {
      localMax = in->gain[2];
    }
    b_table[1U].SimMin = localMin;
    b_table[1U].SimMax = localMax;

    i = 0;
    while (b_table[1U].IsAlwaysInteger && (i < 3)) {
      if (in->gain[i] != muDoubleScalarFloor(in->gain[i])) {
        b_table[1U].IsAlwaysInteger = false;
      }
      i++;
    }
    localMin = b_table[2U].SimMin;
    localMax = b_table[2U].SimMax;

    if (in->ymin < localMin) {
      localMin = in->ymin;
    }
    if (in->ymin > localMax) {
      localMax = in->ymin;
    }
    b_table[2U].SimMin = localMin;
    b_table[2U].SimMax = localMax;

    if (in->ymin != muDoubleScalarFloor(in->ymin)) {
      b_table[2U].IsAlwaysInteger = false;
    }
  }
}

static void emlrt_update_log_7(const b_struct_T *in,
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

    if (in->ymin < localMin) {
      localMin = in->ymin;
    }
    if (in->ymin > localMax) {
      localMax = in->ymin;
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    if (in->ymin != muDoubleScalarFloor(in->ymin)) {
      b_table[0U].IsAlwaysInteger = false;
    }
    localMin = b_table[1U].SimMin;
    localMax = b_table[1U].SimMax;

    if (in->gain[0] < localMin) {
      localMin = in->gain[0];
    }
    if (in->gain[0] > localMax) {
      localMax = in->gain[0];
    }

    if (in->gain[1] < localMin) {
      localMin = in->gain[1];
    }
    if (in->gain[1] > localMax) {
      localMax = in->gain[1];
    }
    b_table[1U].SimMin = localMin;
    b_table[1U].SimMax = localMax;

    i = 0;
    while (b_table[1U].IsAlwaysInteger && (i < 2)) {
      if (in->gain[i] != muDoubleScalarFloor(in->gain[i])) {
        b_table[1U].IsAlwaysInteger = false;
      }
      i++;
    }
    localMin = b_table[2U].SimMin;
    localMax = b_table[2U].SimMax;

    if (in->xoffset[0] < localMin) {
      localMin = in->xoffset[0];
    }
    if (in->xoffset[0] > localMax) {
      localMax = in->xoffset[0];
    }

    if (in->xoffset[1] < localMin) {
      localMin = in->xoffset[1];
    }
    if (in->xoffset[1] > localMax) {
      localMax = in->xoffset[1];
    }
    b_table[2U].SimMin = localMin;
    b_table[2U].SimMax = localMax;

    i = 0;
    while (b_table[2U].IsAlwaysInteger && (i < 2)) {
      if (in->xoffset[i] != muDoubleScalarFloor(in->xoffset[i])) {
        b_table[2U].IsAlwaysInteger = false;
      }
      i++;
    }
  }
}

static void emlrt_update_log_8(const real_T in[9],
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
    for (i = 0; i < 9; i++) {

      if (in[i] < localMin) {
        localMin = in[i];
      }
      if (in[i] > localMax) {
        localMax = in[i];
      }
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < 9)) {
      if (in[i] != muDoubleScalarFloor(in[i])) {
        b_table[0U].IsAlwaysInteger = false;
      }
      i++;
    }
  }
}

static void emlrt_update_log_9(const real_T in[6],
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
    for (i = 0; i < 6; i++) {

      if (in[i] < localMin) {
        localMin = in[i];
      }
      if (in[i] > localMax) {
        localMax = in[i];
      }
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < 6)) {
      if (in[i] != muDoubleScalarFloor(in[i])) {
        b_table[0U].IsAlwaysInteger = false;
      }
      i++;
    }
  }
}

void plasma_nn_wrapper(const emlrtStack *sp, real_T x1_1, real_T x1_2,
                       real_T x1_3, real_T *y1_1, real_T *y1_2)
{
  static const real_T a[9] = {
      0.49902993150899227,  0.30123670628984067,   0.12516802593384807,
      -0.51296840185120363, 0.68814909306292171,   0.93273495397189421,
      -0.20278058006334571, -0.012676887330512976, -0.53291115347939677};
  static const real_T b_a[9] = {
      -0.87688876060151988, -0.97592909102828584, -0.42784037693397464,
      -0.41598287445587623, 0.812045397237656,    -0.394086581450269,
      -0.82893851267054686, 0.36119144972618322,  -0.34331363106923984};
  static const real_T c_a[9] = {
      0.68310892499344122, -0.891383630888253,   -0.46518593413825315,
      0.59640738468320253, -0.69108040695498785, -0.15627377539294085,
      -0.0668709056167851, -0.93983815940534676, -0.27695001718227807};
  static const real_T d_a[9] = {
      0.13686895098509511,  0.14953500000556086,  0.9828640319601023,
      -0.34659893472624792, -0.21976798459184171, 0.41177204033841952,
      -0.27628215335070005, 0.043059695577947421, 0.86464350458194472};
  static const real_T e_a[9] = {
      -0.048011828460824413, -0.26031264445228586, 0.719831665796645,
      0.51326664840066072,   -0.2897277570203991,  0.66735876398802407,
      -0.943842793623423,    0.83945422718018547,  0.41119555922502266};
  static const real_T f_a[6] = {0.26657965612375722, 0.28736193113682429,
                                0.94406392829578678, -0.87078421100392522,
                                0.42868402720802762, -0.82590948979324841};
  b_struct_T b_s;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  struct_T s;
  real_T dv1[9];
  real_T b[3];
  real_T dv[3];
  real_T x1[3];
  real_T a6[2];
  real_T b_y1[2];
  real_T d;
  real_T d1;
  real_T d2;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;

  emlrtInitVarDataTables(emlrtLocationLoggingDataTables);

  emlrt_update_log_1(x1_1, emlrtLocationLoggingDataTables, 0);

  emlrt_update_log_1(x1_2, emlrtLocationLoggingDataTables, 1);

  emlrt_update_log_1(x1_3, emlrtLocationLoggingDataTables, 2);
  st.site = &b_emlrtRSI;
  custom_mex_logger(&st, 2U, x1_1);
  st.site = &b_emlrtRSI;
  custom_mex_logger(&st, 3U, x1_2);
  st.site = &b_emlrtRSI;
  custom_mex_logger(&st, 4U, x1_3);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
  x1[0] = x1_1;
  x1[1] = x1_2;
  x1[2] = x1_3;
  emlrt_update_log_2(x1, emlrtLocationLoggingDataTables, 3);
  st.site = &emlrtRSI;

  dv[0] = x1_1;
  dv[1] = x1_2;
  dv[2] = x1_3;
  emlrt_update_log_2(dv, emlrtLocationLoggingDataTables, 25);
  b_st.site = &j_emlrtRSI;
  c_custom_mex_logger(&b_st, 15U, x1);
  covrtLogFcn(&emlrtCoverageInstance, 1U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 0U);
  dv[0] = -1.0;
  dv[1] = -1.0;
  dv[2] = -1.0;
  emlrt_update_log_2(dv, emlrtLocationLoggingDataTables, 26);
  dv[0] = 1.0;
  dv[1] = 1.0;
  dv[2] = 1.0;
  emlrt_update_log_2(dv, emlrtLocationLoggingDataTables, 27);
  emlrt_update_log_1(-1.0, emlrtLocationLoggingDataTables, 28);
  dv[0] = 0.80831931814668234;
  dv[1] = -0.14695061016227484;
  dv[2] = 0.066291221258295743;
  emlrt_update_log_2(dv, emlrtLocationLoggingDataTables, 29);
  memcpy(&dv1[0], &a[0], 9U * sizeof(real_T));
  emlrt_update_log_8(dv1, emlrtLocationLoggingDataTables, 30);
  dv[0] = -0.9323715336664522;
  dv[1] = 0.31764178540904275;
  dv[2] = 0.06429245746966103;
  emlrt_update_log_2(dv, emlrtLocationLoggingDataTables, 31);
  memcpy(&dv1[0], &b_a[0], 9U * sizeof(real_T));
  emlrt_update_log_8(dv1, emlrtLocationLoggingDataTables, 32);
  dv[0] = -0.69411239089475951;
  dv[1] = 0.075852120666890815;
  dv[2] = -0.32220275539283172;
  emlrt_update_log_2(dv, emlrtLocationLoggingDataTables, 33);
  memcpy(&dv1[0], &c_a[0], 9U * sizeof(real_T));
  emlrt_update_log_8(dv1, emlrtLocationLoggingDataTables, 34);
  dv[0] = -0.95725927982871428;
  dv[1] = 0.721991483820615;
  dv[2] = 0.10789315145848197;
  emlrt_update_log_2(dv, emlrtLocationLoggingDataTables, 35);
  memcpy(&dv1[0], &d_a[0], 9U * sizeof(real_T));
  emlrt_update_log_8(dv1, emlrtLocationLoggingDataTables, 36);
  dv[0] = -0.8986549269428743;
  dv[1] = -0.96981738542255647;
  dv[2] = -0.76552307618084381;
  emlrt_update_log_2(dv, emlrtLocationLoggingDataTables, 37);
  memcpy(&dv1[0], &e_a[0], 9U * sizeof(real_T));
  emlrt_update_log_8(dv1, emlrtLocationLoggingDataTables, 38);
  b_y1[0] = -0.26583101460229;
  b_y1[1] = -0.271965328045613;
  emlrt_update_log_3(b_y1, emlrtLocationLoggingDataTables, 39);
  emlrt_update_log_9(f_a, emlrtLocationLoggingDataTables, 40);
  emlrt_update_log_1(-1.0, emlrtLocationLoggingDataTables, 41);
  b_y1[0] = 1.0;
  b_y1[1] = 1.0;
  emlrt_update_log_3(b_y1, emlrtLocationLoggingDataTables, 42);
  b_y1[0] = -1.0;
  b_y1[1] = -1.0;
  emlrt_update_log_3(b_y1, emlrtLocationLoggingDataTables, 43);
  emlrt_update_log_1(1.0, emlrtLocationLoggingDataTables, 44);
  b_st.site = &c_emlrtRSI;

  dv[0] = x1_1;
  dv[1] = x1_2;
  dv[2] = x1_3;
  emlrt_update_log_2(dv, emlrtLocationLoggingDataTables, 7);

  s.xoffset[0] = -1.0;
  s.gain[0] = 1.0;
  s.xoffset[1] = -1.0;
  s.gain[1] = 1.0;
  s.xoffset[2] = -1.0;
  s.gain[2] = 1.0;
  s.ymin = -1.0;
  emlrt_update_log_4(&s, emlrtLocationLoggingDataTables, 8);
  c_st.site = &j_emlrtRSI;
  c_custom_mex_logger(&c_st, 7U, x1);
  s.xoffset[0] = -1.0;
  s.gain[0] = 1.0;
  s.xoffset[1] = -1.0;
  s.gain[1] = 1.0;
  s.xoffset[2] = -1.0;
  s.gain[2] = 1.0;
  c_st.site = &j_emlrtRSI;
  d_custom_mex_logger(&c_st, 8U, s.xoffset, s.gain, -1.0);
  covrtLogFcn(&emlrtCoverageInstance, 1U, 1U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 1U);
  x1[0] = x1_1 - -1.0;
  x1[1] = x1_2 - -1.0;
  x1[2] = x1_3 - -1.0;
  emlrt_update_log_2(x1, emlrtLocationLoggingDataTables, 11);
  emlrt_update_log_2(x1, emlrtLocationLoggingDataTables, 12);
  x1[0] = (x1_1 - -1.0) + -1.0;
  x1[1] = (x1_2 - -1.0) + -1.0;
  x1[2] = (x1_3 - -1.0) + -1.0;
  emlrt_update_log_2(x1, emlrtLocationLoggingDataTables, 13);
  c_st.site = &j_emlrtRSI;
  c_custom_mex_logger(&c_st, 9U, x1);
  emlrt_update_log_2(x1, emlrtLocationLoggingDataTables, 45);
  b[0] = 0.80831931814668234;
  b[1] = -0.14695061016227484;
  b[2] = 0.066291221258295743;
  emlrt_update_log_2(b, emlrtLocationLoggingDataTables, 48);
  for (i = 0; i < 3; i++) {
    dv[i] =
        (a[i] * ((x1_1 - -1.0) + -1.0) + a[i + 3] * ((x1_2 - -1.0) + -1.0)) +
        a[i + 6] * ((x1_3 - -1.0) + -1.0);
  }
  emlrt_update_log_2(dv, emlrtLocationLoggingDataTables, 49);
  b[0] = dv[0] + 0.80831931814668234;
  b[1] = dv[1] + -0.14695061016227484;
  b[2] = dv[2] + 0.066291221258295743;
  emlrt_update_log_2(b, emlrtLocationLoggingDataTables, 47);
  b_st.site = &d_emlrtRSI;
  poslin_apply(&b_st, b, x1);
  emlrt_update_log_2(x1, emlrtLocationLoggingDataTables, 46);
  b[0] = -0.9323715336664522;
  b[1] = 0.31764178540904275;
  b[2] = 0.06429245746966103;
  emlrt_update_log_2(b, emlrtLocationLoggingDataTables, 52);
  d = x1[0];
  d1 = x1[1];
  d2 = x1[2];
  for (i = 0; i < 3; i++) {
    dv[i] = (b_a[i] * d + b_a[i + 3] * d1) + b_a[i + 6] * d2;
  }
  emlrt_update_log_2(dv, emlrtLocationLoggingDataTables, 53);
  b[0] = dv[0] + -0.9323715336664522;
  b[1] = dv[1] + 0.31764178540904275;
  b[2] = dv[2] + 0.06429245746966103;
  emlrt_update_log_2(b, emlrtLocationLoggingDataTables, 51);
  b_st.site = &e_emlrtRSI;
  poslin_apply(&b_st, b, x1);
  emlrt_update_log_2(x1, emlrtLocationLoggingDataTables, 50);
  b[0] = -0.69411239089475951;
  b[1] = 0.075852120666890815;
  b[2] = -0.32220275539283172;
  emlrt_update_log_2(b, emlrtLocationLoggingDataTables, 56);
  d = x1[0];
  d1 = x1[1];
  d2 = x1[2];
  for (i = 0; i < 3; i++) {
    dv[i] = (c_a[i] * d + c_a[i + 3] * d1) + c_a[i + 6] * d2;
  }
  emlrt_update_log_2(dv, emlrtLocationLoggingDataTables, 57);
  b[0] = dv[0] + -0.69411239089475951;
  b[1] = dv[1] + 0.075852120666890815;
  b[2] = dv[2] + -0.32220275539283172;
  emlrt_update_log_2(b, emlrtLocationLoggingDataTables, 55);
  b_st.site = &f_emlrtRSI;
  poslin_apply(&b_st, b, x1);
  emlrt_update_log_2(x1, emlrtLocationLoggingDataTables, 54);
  b[0] = -0.95725927982871428;
  b[1] = 0.721991483820615;
  b[2] = 0.10789315145848197;
  emlrt_update_log_2(b, emlrtLocationLoggingDataTables, 60);
  d = x1[0];
  d1 = x1[1];
  d2 = x1[2];
  for (i = 0; i < 3; i++) {
    dv[i] = (d_a[i] * d + d_a[i + 3] * d1) + d_a[i + 6] * d2;
  }
  emlrt_update_log_2(dv, emlrtLocationLoggingDataTables, 61);
  b[0] = dv[0] + -0.95725927982871428;
  b[1] = dv[1] + 0.721991483820615;
  b[2] = dv[2] + 0.10789315145848197;
  emlrt_update_log_2(b, emlrtLocationLoggingDataTables, 59);
  b_st.site = &g_emlrtRSI;
  poslin_apply(&b_st, b, x1);
  emlrt_update_log_2(x1, emlrtLocationLoggingDataTables, 58);
  b[0] = -0.8986549269428743;
  b[1] = -0.96981738542255647;
  b[2] = -0.76552307618084381;
  emlrt_update_log_2(b, emlrtLocationLoggingDataTables, 64);
  d = x1[0];
  d1 = x1[1];
  d2 = x1[2];
  for (i = 0; i < 3; i++) {
    dv[i] = (e_a[i] * d + e_a[i + 3] * d1) + e_a[i + 6] * d2;
  }
  emlrt_update_log_2(dv, emlrtLocationLoggingDataTables, 65);
  b[0] = dv[0] + -0.8986549269428743;
  b[1] = dv[1] + -0.96981738542255647;
  b[2] = dv[2] + -0.76552307618084381;
  emlrt_update_log_2(b, emlrtLocationLoggingDataTables, 63);
  b_st.site = &h_emlrtRSI;
  poslin_apply(&b_st, b, x1);
  emlrt_update_log_2(x1, emlrtLocationLoggingDataTables, 62);
  a6[0] = -0.26583101460229;
  a6[1] = -0.271965328045613;
  emlrt_update_log_3(a6, emlrtLocationLoggingDataTables, 67);
  d = x1[0];
  d1 = x1[1];
  d2 = x1[2];
  for (i = 0; i < 2; i++) {
    b_y1[i] = (f_a[i] * d + f_a[i + 2] * d1) + f_a[i + 4] * d2;
  }
  emlrt_update_log_3(b_y1, emlrtLocationLoggingDataTables, 68);
  a6[0] = b_y1[0] + -0.26583101460229;
  a6[1] = b_y1[1] + -0.271965328045613;
  emlrt_update_log_3(a6, emlrtLocationLoggingDataTables, 66);
  b_st.site = &i_emlrtRSI;

  b_y1[0] = a6[0];
  b_y1[1] = a6[1];
  emlrt_update_log_3(b_y1, emlrtLocationLoggingDataTables, 18);

  b_s.ymin = -1.0;
  b_s.gain[0] = 1.0;
  b_s.xoffset[0] = -1.0;
  b_s.gain[1] = 1.0;
  b_s.xoffset[1] = -1.0;
  emlrt_update_log_7(&b_s, emlrtLocationLoggingDataTables, 19);
  c_st.site = &j_emlrtRSI;
  b_custom_mex_logger(&c_st, 12U, a6);
  b_s.gain[0] = 1.0;
  b_s.xoffset[0] = -1.0;
  b_s.gain[1] = 1.0;
  b_s.xoffset[1] = -1.0;
  c_st.site = &j_emlrtRSI;
  e_custom_mex_logger(&c_st, 13U, -1.0, b_s.gain, b_s.xoffset);
  covrtLogFcn(&emlrtCoverageInstance, 1U, 3U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 3U);
  b_y1[0] = a6[0] - -1.0;
  b_y1[1] = a6[1] - -1.0;
  emlrt_update_log_3(b_y1, emlrtLocationLoggingDataTables, 22);
  emlrt_update_log_3(b_y1, emlrtLocationLoggingDataTables, 23);
  b_y1[0] = (a6[0] - -1.0) + -1.0;
  b_y1[1] = (a6[1] - -1.0) + -1.0;
  emlrt_update_log_3(b_y1, emlrtLocationLoggingDataTables, 24);
  c_st.site = &j_emlrtRSI;
  b_custom_mex_logger(&c_st, 14U, b_y1);
  emlrt_update_log_3(b_y1, emlrtLocationLoggingDataTables, 69);
  b_st.site = &j_emlrtRSI;
  b_custom_mex_logger(&b_st, 16U, b_y1);
  emlrt_update_log_3(b_y1, emlrtLocationLoggingDataTables, 4);
  *y1_1 = emlrt_update_log_1((a6[0] - -1.0) + -1.0,
                             emlrtLocationLoggingDataTables, 5);
  *y1_2 = emlrt_update_log_1((a6[1] - -1.0) + -1.0,
                             emlrtLocationLoggingDataTables, 6);
  st.site = &b_emlrtRSI;
  custom_mex_logger(&st, 5U, *y1_1);
  st.site = &b_emlrtRSI;
  custom_mex_logger(&st, 6U, *y1_2);
}
