#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

// abs
START_TEST(abs1) { ck_assert_int_eq(abs(17), s21_abs(17)); }
END_TEST

START_TEST(abs2) { ck_assert_int_eq(abs(-29), s21_abs(-29)); }
END_TEST

START_TEST(abs3) { ck_assert_int_eq(abs(987654321), s21_abs(987654321)); }
END_TEST

START_TEST(abs4) { ck_assert_int_eq(abs(-987654321), s21_abs(-987654321)); }
END_TEST

START_TEST(abs5) { ck_assert_int_eq(abs(0), s21_abs(0)); }
END_TEST

START_TEST(abs6) { ck_assert_int_eq(abs(+0), s21_abs(+0)); }
END_TEST

START_TEST(abs7) { ck_assert_int_eq(abs(-0), s21_abs(-0)); }
END_TEST

START_TEST(abs8) { ck_assert_int_eq(abs((int)S21_NAN), s21_abs((int)S21_NAN)); }
END_TEST

START_TEST(abs9) {
  ck_assert_int_eq(abs((int)S21_INFINITY), s21_abs((int)S21_INFINITY));
}
END_TEST

START_TEST(abs10) {
  ck_assert_int_eq(abs((int)S21_MIN_INFINITY), s21_abs((int)S21_MIN_INFINITY));
}
END_TEST

// fabs
START_TEST(fabs1) { ck_assert_double_eq(fabs(17.578), s21_fabs(17.578)); }
END_TEST

START_TEST(fabs2) { ck_assert_double_eq(fabs(-45.45), s21_fabs(-45.45)); }
END_TEST

START_TEST(fabs3) {
  ck_assert_double_eq(fabs(12345.6789), s21_fabs(12345.6789));
}
END_TEST

START_TEST(fabs4) {
  ck_assert_double_eq(fabs(-12345.6789), s21_fabs(-12345.6789));
}
END_TEST

START_TEST(fabs5) { ck_assert_double_eq(fabs(0), s21_fabs(0)); }
END_TEST

START_TEST(fabs6) { ck_assert_double_eq(fabs(+0), s21_fabs(+0)); }
END_TEST

START_TEST(fabs7) { ck_assert_double_eq(fabs(-0), s21_fabs(-0)); }
END_TEST

START_TEST(fabs8) {
  ck_assert_ldouble_nan(fabs((double)S21_NAN));
  ck_assert_ldouble_nan(s21_fabs((double)S21_NAN));
}
END_TEST

START_TEST(fabs9) {
  ck_assert_double_eq(fabs((double)S21_INFINITY),
                      s21_fabs((double)S21_INFINITY));
}
END_TEST

START_TEST(fabs10) {
  ck_assert_double_eq(fabs((double)S21_MIN_INFINITY),
                      s21_fabs((double)S21_MIN_INFINITY));
}
END_TEST

// epx
START_TEST(exp1) { ck_assert_double_eq(exp(7), s21_exp(7)); }
END_TEST

START_TEST(exp_2) {
  ck_assert_ldouble_nan(exp((double)S21_NAN));
  ck_assert_ldouble_nan(s21_exp((double)S21_NAN));
}
END_TEST

START_TEST(exp3) {
  ck_assert_ldouble_infinite(exp((double)S21_INFINITY));
  ck_assert_ldouble_infinite(s21_exp((double)S21_INFINITY));
}
END_TEST

START_TEST(exp4) {
  ck_assert_double_eq(exp(148871732219), s21_exp(148871732219));
}
END_TEST

START_TEST(exp5) { ck_assert_double_eq(exp(-18), s21_exp(-18)); }
END_TEST

// fmod
START_TEST(fmod1) {
  ck_assert_ldouble_eq(fmod(15.77, 4.3), s21_fmod(15.77, 4.3));
}
END_TEST

START_TEST(fmod2) {
  ck_assert_ldouble_eq(fmod(-13.55, 6.4), s21_fmod(-13.55, 6.4));
}
END_TEST

START_TEST(fmod3) {
  ck_assert_ldouble_eq(fmod(10.55, -3.4), s21_fmod(10.55, -3.4));
}
END_TEST

START_TEST(fmod4) {
  ck_assert_ldouble_eq(fmod(-15.58, -3.4), s21_fmod(-15.58, 3.4));
}
END_TEST

START_TEST(fmod5) {
  ck_assert_ldouble_eq(fmod(21.48, 5.69), s21_fmod(21.48, 5.69));
}
END_TEST

START_TEST(fmod6) {
  ck_assert_ldouble_eq(fmod(-7.4, 0.7), s21_fmod(-7.4, 0.7));
}
END_TEST

START_TEST(fmod7) {
  ck_assert_ldouble_eq(fmod(12.134, -5.78), s21_fmod(12.134, -5.78));
}
END_TEST

START_TEST(fmod8) {
  ck_assert_ldouble_eq(fmod(-7.8, -0.8), s21_fmod(-7.8, -0.8));
}
END_TEST

START_TEST(fmod9) { ck_assert_ldouble_eq(fmod(30, 20), s21_fmod(30, 20)); }
END_TEST

START_TEST(fmod10) { ck_assert_ldouble_eq(fmod(-40, -20), s21_fmod(-40, -20)); }
END_TEST

START_TEST(fmod11) {
  ck_assert_ldouble_eq(fmod(20000, 32), s21_fmod(20000, 32));
}
END_TEST

START_TEST(fmod12) {
  ck_assert_ldouble_eq(fmod(-20000, 32), s21_fmod(-20000, 32));
}
END_TEST

START_TEST(fmod13) {
  ck_assert_ldouble_eq(fmod(-32, 20000), s21_fmod(-32, 20000));
}
END_TEST

START_TEST(fmod14) { ck_assert_ldouble_eq(fmod(0, 10), s21_fmod(0, 10)); }
END_TEST

START_TEST(fmod15) {
  ck_assert_ldouble_nan(fmod(14.33, 0));
  ck_assert_ldouble_nan(s21_fmod(14.33, 0));
}
END_TEST

START_TEST(fmod16) {
  ck_assert_double_nan(fmod(0, 0));
  ck_assert_double_nan(s21_fmod(0, 0));
}
END_TEST

START_TEST(fmod17) {
  ck_assert_ldouble_nan(fmod(NAN, NAN));
  ck_assert_ldouble_nan(s21_fmod(NAN, NAN));
}
END_TEST

START_TEST(fmod18) {
  ck_assert_double_nan(fmod(7.4, NAN));
  ck_assert_double_nan(s21_fmod(7.4, NAN));
}
END_TEST

START_TEST(fmod19) {
  ck_assert_ldouble_nan(fmod(NAN, 8.2));
  ck_assert_ldouble_nan(s21_fmod(NAN, 8.2));
}
END_TEST

START_TEST(fmod20) {
  ck_assert_double_nan(fmod(INFINITY, INFINITY));
  ck_assert_double_nan(s21_fmod(INFINITY, INFINITY));
}
END_TEST

START_TEST(fmod21) {
  ck_assert_double_nan(fmod(INFINITY, 0));
  ck_assert_double_nan(s21_fmod(INFINITY, 0));
}
END_TEST

START_TEST(fmod22) {
  ck_assert_double_nan(fmod(-INFINITY, 0));
  ck_assert_double_nan(s21_fmod(-INFINITY, 0));
}
END_TEST

START_TEST(fmod23) {
  ck_assert_ldouble_eq(fmod(14, INFINITY), s21_fmod(14, INFINITY));
}
END_TEST

START_TEST(fmod24) {
  ck_assert_ldouble_eq(fmod(21, -INFINITY), s21_fmod(21, -INFINITY));
}
END_TEST

START_TEST(fmod25) {
  ck_assert_ldouble_eq(fmod(10, S21_MIN_INFINITY),
                       s21_fmod(10, S21_MIN_INFINITY));
}
END_TEST

// pow

START_TEST(pow1) {
  ck_assert_ldouble_nan(pow(S21_NAN, 387));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, 387));
}
END_TEST

START_TEST(pow2) {
  ck_assert_ldouble_eq(pow(4, S21_INFINITY), s21_pow(4, S21_INFINITY));
}
END_TEST

START_TEST(pow3) { ck_assert_ldouble_eq(pow(-9, 387), s21_pow(-9, 387)); }
END_TEST

START_TEST(pow4) {
  ck_assert_ldouble_nan(pow(S21_NAN, S21_INFINITY));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_INFINITY));
}
END_TEST

START_TEST(pow5) {
  ck_assert_ldouble_nan(pow(S21_INFINITY, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_INFINITY, S21_NAN));
}
END_TEST

START_TEST(pow6) {
  ck_assert_ldouble_eq(pow(14, S21_MIN_INFINITY),
                       s21_pow(14, S21_MIN_INFINITY));
}
END_TEST

START_TEST(pow7) {
  ck_assert_ldouble_eq(pow(1, S21_MIN_INFINITY), s21_pow(1, S21_MIN_INFINITY));
}
END_TEST

START_TEST(pow8) {
  ck_assert_ldouble_eq(pow(S21_MIN_INFINITY, 14),
                       s21_pow(S21_MIN_INFINITY, 14));
}
END_TEST

START_TEST(pow9) {
  ck_assert_ldouble_eq(pow(0.5, S21_MIN_INFINITY),
                       s21_pow(0.5, S21_MIN_INFINITY));
}
END_TEST

START_TEST(pow10) {
  ck_assert_ldouble_eq(pow(S21_MIN_INFINITY, -29),
                       s21_pow(S21_MIN_INFINITY, -29));
}
END_TEST

START_TEST(pow11) { ck_assert_ldouble_eq(pow(6, 0), s21_pow(6, 0)); }
END_TEST

START_TEST(pow12) {
  ck_assert_ldouble_infinite(pow(0, -7));
  ck_assert_ldouble_infinite(s21_pow(0, -7));
}
END_TEST

START_TEST(pow13) {
  ck_assert_ldouble_eq(pow(S21_INFINITY, S21_INFINITY),
                       s21_pow(S21_INFINITY, S21_INFINITY));
}
END_TEST

START_TEST(pow14) {
  ck_assert_ldouble_eq(pow(1, S21_INFINITY), s21_pow(1, S21_INFINITY));
}
END_TEST

START_TEST(pow15) {
  ck_assert_ldouble_eq(pow(0.2, S21_INFINITY), s21_pow(0.2, S21_INFINITY));
}
END_TEST

START_TEST(pow16) {
  ck_assert_ldouble_eq(pow(1, S21_NAN), s21_pow(1, S21_NAN));
}
END_TEST

START_TEST(pow17) {
  ck_assert_ldouble_eq(pow(S21_MIN_INFINITY, 0), s21_pow(S21_MIN_INFINITY, 0));
}
END_TEST

START_TEST(pow18) {
  ck_assert_ldouble_eq(pow(0, 0), pow(0, 0));
  ck_assert_ldouble_eq(pow(0, 0), s21_pow(0, 0));
}
END_TEST

START_TEST(pow19) {
  ck_assert_ldouble_nan(pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
}
END_TEST

START_TEST(pow20) {
  ck_assert_ldouble_nan(pow(S21_NAN, -1));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -1));
}
END_TEST

START_TEST(pow21) { ck_assert_ldouble_eq(pow(0, -1), s21_pow(0, -1)); }
END_TEST

START_TEST(pow22) {
  ck_assert_ldouble_eq(pow(S21_NAN, 0), s21_pow(S21_NAN, 0));
}
END_TEST

START_TEST(pow23) {
  ck_assert_ldouble_infinite(pow(S21_MIN_INFINITY, S21_INFINITY));
  ck_assert_ldouble_infinite(s21_pow(S21_MIN_INFINITY, S21_INFINITY));
}
END_TEST

// sqrt

START_TEST(sqrt1) {
  int success = 0;
  if (abs(sqrt(4.44) - s21_sqrt(4.44)) < EPS) success = 1;
  ck_assert_int_eq(success, 1);
}
END_TEST

START_TEST(sqrt2) {
  int success = 0;
  if (abs(sqrt(10036224) - s21_sqrt(10036224)) < EPS) success = 1;
  ck_assert_ldouble_eq(1, success);
}
END_TEST

START_TEST(sqrt3) {
  ck_assert_ldouble_nan(sqrt(-17.546));
  ck_assert_ldouble_nan(s21_sqrt(-17.546));
}
END_TEST

START_TEST(sqrt4) {
  ck_assert_ldouble_nan(sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
}
END_TEST

START_TEST(sqrt5) {
  ck_assert_ldouble_infinite(sqrt(S21_INFINITY));
  ck_assert_ldouble_infinite(s21_sqrt(S21_INFINITY));
}
END_TEST

// sin

START_TEST(sin1) {
  ck_assert_ldouble_nan(sin(S21_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
}
END_TEST

START_TEST(sin2) {
  ck_assert_ldouble_nan(sin(S21_INFINITY));
  ck_assert_ldouble_nan(s21_sin(S21_INFINITY));
}
END_TEST

START_TEST(sin3) {
  int success = 0;
  if (abs(s21_sin(-789) - sin(-789)) <= EPS) success = 1;
  ck_assert_int_eq(success, 1);
}
END_TEST

START_TEST(sin4) {
  int success = 0;
  if (abs(s21_sin(97756) - sin(97756)) <= EPS) success = 1;
  ck_assert_int_eq(success, 1);
}
END_TEST

// cos
START_TEST(cos1) {
  int success = 0;
  if (abs(s21_cos(97756) - cos(97756)) <= EPS) success = 1;
  ck_assert_int_eq(success, 1);
}
END_TEST

START_TEST(cos2) {
  int success = 0;
  if (abs(s21_cos(-97756) - cos(-97756)) <= EPS) success = 1;
  ck_assert_int_eq(success, 1);
}
END_TEST

START_TEST(cos3) {
  ck_assert_ldouble_nan(cos(S21_INFINITY));
  ck_assert_ldouble_nan(s21_cos(S21_INFINITY));
}
END_TEST

// td
START_TEST(tan1) {
  ck_assert_ldouble_nan(tan(S21_INFINITY));
  ck_assert_ldouble_nan(s21_tan(S21_INFINITY));
}
END_TEST

START_TEST(tan2) {
  int success = 0;
  if (abs(s21_tan(-46) - tan(-46)) <= EPS) success = 1;
  ck_assert_int_eq(success, 1);
}
END_TEST

START_TEST(tan3) {
  int success = 0;
  if (abs(s21_tan(65) - tan(65)) <= EPS) success = 1;
  ck_assert_int_eq(success, 1);
}
END_TEST

START_TEST(tan4) {
  int success = 0;
  if (abs(s21_tan(S21_PI / 2) - tan(S21_PI / 2)) <= EPS) success = 1;
  ck_assert_int_eq(success, 1);
}
END_TEST

// log
START_TEST(log1) {
  ck_assert_ldouble_eq_tol(log(1.6e-9), s21_log(1.6e-9), 1e-6);
}
END_TEST

START_TEST(log_2) {
  ck_assert_ldouble_eq_tol(log(1.1e-80), s21_log(1.1e-80), 1e-6);
}
END_TEST

START_TEST(log3) {
  ck_assert_ldouble_eq_tol(log(1.21e-33), s21_log(1.21e-33), 1e-6);
}
END_TEST

START_TEST(log4) {
  ck_assert_ldouble_eq_tol(log(2.1e-44), s21_log(2.1e-44), 1e-6);
}
END_TEST

START_TEST(log5) {
  ck_assert_double_infinite(log(0));
  ck_assert_ldouble_infinite(s21_log(0));
}
END_TEST

START_TEST(log6) {
  ck_assert_double_eq_tol(log(54321567.984e-15), s21_log(54321567.984e-15),
                          1e-6);
}
END_TEST

START_TEST(log7) {
  ck_assert_double_eq_tol(log(13246.432e-27), s21_log(13246.432e-27), 1e-6);
}
END_TEST

START_TEST(log8) {
  ck_assert_ldouble_eq_tol(log(45632178.000034), s21_log(45632178.000034),
                           1e-6);
}
END_TEST

START_TEST(log9) { ck_assert_ldouble_eq_tol(log(0.3), s21_log(0.3), 1e-6); }
END_TEST

START_TEST(log_10) { ck_assert_ldouble_eq_tol(log(1.0), s21_log(1.0), 1e-6); }
END_TEST

START_TEST(log11) {
  ck_assert_ldouble_eq_tol(log(S21_PI), s21_log(S21_PI), 1e-6);
}
END_TEST

START_TEST(log12) {
  ck_assert_ldouble_eq_tol(log(S21_PI / 8), s21_log(S21_PI / 8), 1e-6);
}
END_TEST

START_TEST(log13) { ck_assert_ldouble_eq_tol(log(100), s21_log(100), 1e-6); }
END_TEST

START_TEST(log14) { ck_assert_ldouble_eq_tol(log(35), s21_log(35), 1e-6); }
END_TEST

START_TEST(log15) {
  ck_assert_ldouble_eq_tol(log(S21_PI), s21_log(S21_PI), 1e-6);
}
END_TEST

START_TEST(log16) {
  ck_assert_ldouble_nan(log(S21_NAN));
  ck_assert_ldouble_nan(s21_log(S21_NAN));
}
END_TEST

START_TEST(log17) {
  ck_assert_ldouble_infinite(log(S21_INFINITY));
  ck_assert_ldouble_infinite(s21_log(S21_INFINITY));
}
END_TEST

START_TEST(log18) {
  ck_assert_ldouble_nan(log(S21_MIN_INFINITY));
  ck_assert_double_nan(s21_log(S21_MIN_INFINITY));
}
END_TEST

// atan
START_TEST(atan1) {
  ck_assert_ldouble_eq(atan(S21_INFINITY), s21_atan(S21_INFINITY));
}
END_TEST

START_TEST(atan_2) {
  ck_assert_ldouble_eq_tol(atan(-0.456), s21_atan(-0.456), 1e-6);
}
END_TEST

START_TEST(atan3) { ck_assert_ldouble_eq(atan(-0), s21_atan(-0)); }
END_TEST

START_TEST(atan4) {
  ck_assert_ldouble_eq_tol(atan(-7000.6), s21_atan(-7000.6), 1e-6);
}
END_TEST

START_TEST(atan5) {
  int success = 0;
  if (abs(atan(14) - s21_atan(14)) < EPS) success = 1;
  ck_assert_int_eq(1, success);
}
END_TEST

// asin

START_TEST(asin1) { ck_assert_ldouble_eq_tol(asin(0.2), s21_asin(0.2), 1e-6); }
END_TEST

START_TEST(asin2) { ck_assert_ldouble_eq(asin(1), s21_asin(1)); }
END_TEST

START_TEST(asin3) { ck_assert_ldouble_eq(asin(-1), s21_asin(-1)); }
END_TEST

START_TEST(asin4) {
  ck_assert_ldouble_nan(asin(-1796896565));
  ck_assert_ldouble_nan(s21_asin(-1796896565));
}
END_TEST

START_TEST(asin5) {
  ck_assert_ldouble_nan(asin(S21_INFINITY));
  ck_assert_ldouble_nan(s21_asin(S21_INFINITY));
}
END_TEST

// acos
START_TEST(acos1) {
  ck_assert_ldouble_nan(acos(15));
  ck_assert_ldouble_nan(s21_acos(15));
}
END_TEST

START_TEST(acos2) {
  ck_assert_ldouble_nan(acos(S21_INFINITY));
  ck_assert_ldouble_nan(s21_acos(S21_INFINITY));
}
END_TEST

START_TEST(acos3) { ck_assert_ldouble_eq(acos(-1), s21_acos(-1)); }
END_TEST

START_TEST(acos4) { ck_assert_ldouble_eq(acos(0), s21_acos(0)); }
END_TEST

START_TEST(acos5) { ck_assert_ldouble_eq(acos(1), s21_acos(1)); }
END_TEST

START_TEST(acos6) {
  int success = 0;
  if (abs(acos(-0.465) - s21_acos(-0.465)) < EPS) success = 1;
  ck_assert_ldouble_eq(1, success);
}
END_TEST

START_TEST(acos7) {
  int success = 0;
  if (abs(acos(0.456) - s21_acos(0.456)) < EPS) success = 1;
  ck_assert_ldouble_eq(1, success);
}
END_TEST

// ceil

START_TEST(ceil1) {
  double x = .0;
  ck_assert_ldouble_eq_tol(s21_ceil(x), ceil(x), 6);
}
END_TEST

START_TEST(ceil2) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_ceil(x), ceil(x), 6);
}
END_TEST

START_TEST(ceil3) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(s21_ceil(x), ceil(x), 6);
}
END_TEST

START_TEST(ceil4) {
  double x = INFINITY;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(ceil5) {
  double x = -INFINITY;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(ceil6) {
  double x = s21_my_nan;
  ck_assert_ldouble_nan(s21_ceil(x));
}
END_TEST

START_TEST(ceil7) {
  double x = 4.447;
  ck_assert_ldouble_eq_tol(s21_ceil(x), ceil(x), 6);
}
END_TEST

START_TEST(ceil8) {
  double x = 4.473232789076;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(ceil9) {
  double x = 473232789076.5;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(ceil10) {
  double x = -4.473232789076;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(ceil11) {
  double x = -473232789076.5;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(ceil12) {
  ck_assert_ldouble_infinite(s21_ceil(INFINITY));
  ck_assert_ldouble_infinite(ceil(INFINITY));
}
END_TEST

START_TEST(ceil13) {
  ck_assert_ldouble_nan(s21_ceil(s21_my_nan));
  ck_assert_ldouble_nan(ceil(s21_my_nan));
}
END_TEST

START_TEST(ceil14) { ck_assert_ldouble_eq(s21_ceil(0), ceil(0)); }
END_TEST

START_TEST(ceil15) {
  double x = 87435471375471154.3414313413;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}

START_TEST(ceil16) {
  double x = -87435471375471154.3414313413;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}

START_TEST(ceil17) { ck_assert_ldouble_eq(ceil(0.76), s21_ceil(0.76)); }
END_TEST

START_TEST(ceil18) { ck_assert_ldouble_eq(ceil(-12234), s21_ceil(-12234)); }
END_TEST

START_TEST(ceil19) { ck_assert_ldouble_eq(ceil(11234), s21_ceil(11234)); }
END_TEST

START_TEST(ceil20) { ck_assert_ldouble_eq(ceil(1), s21_ceil(1)); }
END_TEST

START_TEST(ceil21) { ck_assert_ldouble_eq(ceil(1.722), s21_ceil(1.722)); }
END_TEST

START_TEST(ceil22) { ck_assert_int_eq(ceil(-1.557), s21_ceil(-1.557)); }
END_TEST

START_TEST(ceil23) { ck_assert_int_eq(floor(-0.733), s21_floor(-0.733)); }
END_TEST

START_TEST(ceil24) { ck_assert_ldouble_eq(ceil(144.7), s21_ceil(144.7)); }
END_TEST
START_TEST(ceil25) { ck_assert_ldouble_eq(ceil(0.745), s21_ceil(0.745)); }
END_TEST
START_TEST(ceil26) { ck_assert_ldouble_eq(ceil(INFINITY), s21_ceil(INFINITY)); }
END_TEST
START_TEST(ceil27) {
  ck_assert_ldouble_eq(ceil(-INFINITY), s21_ceil(-INFINITY));
}
END_TEST

START_TEST(ceil28) {
  double x = 0.3;
  int i = _i;
  ck_assert_ldouble_eq_tol(ceil(x * i), s21_ceil(x * i), 1e-6);
}
END_TEST

START_TEST(ceil29) {
  double x = 0.1;
  int i = _i;
  ck_assert_ldouble_eq_tol(ceil(-x * i), s21_ceil(-x * i), 1e-6);
}
END_TEST

START_TEST(ceil30) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq(ceil(x), s21_ceil(x));
}
END_TEST

START_TEST(ceil31) {
  double x = 9999999999999999.999999;
  ck_assert_ldouble_eq(ceil(x), s21_ceil(x));
}
END_TEST

START_TEST(ceil32) { ck_assert_ldouble_eq(ceil(-0.1), s21_ceil(-0.1)); }
END_TEST

START_TEST(ceil33) {
  ck_assert_ldouble_eq(ceil(12345.6789), s21_ceil(12345.6789));
}
END_TEST

START_TEST(ceil34) { ck_assert_ldouble_eq(ceil(-457.99), s21_ceil(-457.99)); }
END_TEST

START_TEST(ceil35) { ck_assert_ldouble_eq(ceil(-50), s21_ceil(-50)); }
END_TEST

START_TEST(ceil36) {
  ck_assert_ldouble_infinite(ceil(S21_INFINITY));
  ck_assert_ldouble_infinite(s21_ceil(S21_INFINITY));
}
END_TEST

START_TEST(ceil37) {
  ck_assert_double_nan(ceil(S21_NAN));
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
}
END_TEST

START_TEST(ceil38) {
  ck_assert_ldouble_infinite(ceil(S21_MIN_INFINITY));
  ck_assert_ldouble_infinite(s21_ceil(S21_MIN_INFINITY));
}

// floor
START_TEST(floor1) { ck_assert_ldouble_eq(ceil(-0.1), s21_ceil(-0.1)); }
END_TEST

START_TEST(floor2) {
  ck_assert_ldouble_eq(ceil(12345.9789), s21_ceil(12345.9789));
}
END_TEST

START_TEST(floor3) {
  ck_assert_ldouble_eq(ceil(-599.878787), s21_ceil(-599.878787));
}
END_TEST

START_TEST(floor4) { ck_assert_ldouble_eq(ceil(0), s21_ceil(0)); }
END_TEST

START_TEST(floor5) {
  ck_assert_ldouble_infinite(ceil(S21_INFINITY));
  ck_assert_ldouble_infinite(s21_ceil(S21_INFINITY));
}
END_TEST

START_TEST(floor6) {
  ck_assert_double_nan(ceil(S21_NAN));
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
}
END_TEST

START_TEST(floor7) {
  ck_assert_ldouble_infinite(ceil(-INFINITY));
  ck_assert_ldouble_infinite(s21_ceil(-INFINITY));
}
END_TEST

START_TEST(floor8) { ck_assert_ldouble_eq(floor(-2.902), s21_floor(-2.902)); }
END_TEST

START_TEST(floor9) { ck_assert_ldouble_eq(floor(+0), s21_floor(+0)); }
END_TEST

START_TEST(floor10) { ck_assert_ldouble_eq(floor(-0), s21_floor(-0)); }
END_TEST

START_TEST(floor11) {
  ck_assert_ldouble_eq(floor(-INFINITY), s21_floor(-INFINITY));
}
END_TEST

Suite *test_suite(void) {
  Suite *s = suite_create("Library tests");

  TCase *tc_let = tcase_create("leatrice");
  suite_add_tcase(s, tc_let);
  tcase_add_test(tc_let, abs1);
  tcase_add_test(tc_let, abs2);
  tcase_add_test(tc_let, abs3);
  tcase_add_test(tc_let, abs4);
  tcase_add_test(tc_let, abs5);
  tcase_add_test(tc_let, abs6);
  tcase_add_test(tc_let, abs7);
  tcase_add_test(tc_let, abs8);
  tcase_add_test(tc_let, abs9);
  tcase_add_test(tc_let, abs10);
  tcase_add_test(tc_let, fabs1);
  tcase_add_test(tc_let, fabs2);
  tcase_add_test(tc_let, fabs3);
  tcase_add_test(tc_let, fabs4);
  tcase_add_test(tc_let, fabs5);
  tcase_add_test(tc_let, fabs6);
  tcase_add_test(tc_let, fabs7);
  tcase_add_test(tc_let, fabs8);
  tcase_add_test(tc_let, fabs9);
  tcase_add_test(tc_let, fabs10);
  tcase_add_test(tc_let, exp1);
  tcase_add_test(tc_let, exp_2);
  tcase_add_test(tc_let, exp3);
  tcase_add_test(tc_let, exp4);
  tcase_add_test(tc_let, exp5);
  tcase_add_test(tc_let, fmod1);
  tcase_add_test(tc_let, fmod2);
  tcase_add_test(tc_let, fmod3);
  tcase_add_test(tc_let, fmod4);
  tcase_add_test(tc_let, fmod5);
  tcase_add_test(tc_let, fmod6);
  tcase_add_test(tc_let, fmod7);
  tcase_add_test(tc_let, fmod8);
  tcase_add_test(tc_let, fmod9);
  tcase_add_test(tc_let, fmod10);
  tcase_add_test(tc_let, fmod11);
  tcase_add_test(tc_let, fmod12);
  tcase_add_test(tc_let, fmod13);
  tcase_add_test(tc_let, fmod14);
  tcase_add_test(tc_let, fmod15);
  tcase_add_test(tc_let, fmod16);
  tcase_add_test(tc_let, fmod17);
  tcase_add_test(tc_let, fmod18);
  tcase_add_test(tc_let, fmod19);
  tcase_add_test(tc_let, fmod20);
  tcase_add_test(tc_let, fmod21);
  tcase_add_test(tc_let, fmod22);
  tcase_add_test(tc_let, fmod23);
  tcase_add_test(tc_let, fmod24);
  tcase_add_test(tc_let, fmod25);
  tcase_add_test(tc_let, pow1);
  tcase_add_test(tc_let, pow2);
  tcase_add_test(tc_let, pow3);
  tcase_add_test(tc_let, pow4);
  tcase_add_test(tc_let, pow5);
  tcase_add_test(tc_let, pow6);
  tcase_add_test(tc_let, pow7);
  tcase_add_test(tc_let, pow8);
  tcase_add_test(tc_let, pow9);
  tcase_add_test(tc_let, pow10);
  tcase_add_test(tc_let, pow11);
  tcase_add_test(tc_let, pow12);
  tcase_add_test(tc_let, pow13);
  tcase_add_test(tc_let, pow14);
  tcase_add_test(tc_let, pow15);
  tcase_add_test(tc_let, pow16);
  tcase_add_test(tc_let, pow17);
  tcase_add_test(tc_let, pow18);
  tcase_add_test(tc_let, pow19);
  tcase_add_test(tc_let, pow20);
  tcase_add_test(tc_let, pow21);
  tcase_add_test(tc_let, pow22);
  tcase_add_test(tc_let, pow23);
  tcase_add_test(tc_let, sqrt1);
  tcase_add_test(tc_let, sqrt2);
  tcase_add_test(tc_let, sqrt3);
  tcase_add_test(tc_let, sqrt4);
  tcase_add_test(tc_let, sqrt5);
  tcase_add_test(tc_let, sin1);
  tcase_add_test(tc_let, sin2);
  tcase_add_test(tc_let, sin3);
  tcase_add_test(tc_let, sin4);
  tcase_add_test(tc_let, cos1);
  tcase_add_test(tc_let, cos2);
  tcase_add_test(tc_let, cos3);
  tcase_add_test(tc_let, tan1);
  tcase_add_test(tc_let, tan2);
  tcase_add_test(tc_let, tan3);
  tcase_add_test(tc_let, tan4);
  tcase_add_test(tc_let, log1);
  tcase_add_test(tc_let, log_2);
  tcase_add_test(tc_let, log3);
  tcase_add_test(tc_let, log4);
  tcase_add_test(tc_let, log5);
  tcase_add_test(tc_let, log6);
  tcase_add_test(tc_let, log7);
  tcase_add_test(tc_let, log8);
  tcase_add_test(tc_let, log9);
  tcase_add_test(tc_let, log_10);
  tcase_add_test(tc_let, log11);
  tcase_add_test(tc_let, log12);
  tcase_add_test(tc_let, log13);
  tcase_add_test(tc_let, log14);
  tcase_add_test(tc_let, log15);
  tcase_add_test(tc_let, log16);
  tcase_add_test(tc_let, log17);
  tcase_add_test(tc_let, log18);
  tcase_add_test(tc_let, atan1);
  tcase_add_test(tc_let, atan_2);
  tcase_add_test(tc_let, atan3);
  tcase_add_test(tc_let, atan4);
  tcase_add_test(tc_let, atan5);
  tcase_add_test(tc_let, asin1);
  tcase_add_test(tc_let, asin2);
  tcase_add_test(tc_let, asin3);
  tcase_add_test(tc_let, asin4);
  tcase_add_test(tc_let, asin5);
  tcase_add_test(tc_let, acos1);
  tcase_add_test(tc_let, acos2);
  tcase_add_test(tc_let, acos3);
  tcase_add_test(tc_let, acos4);
  tcase_add_test(tc_let, acos5);
  tcase_add_test(tc_let, acos6);
  tcase_add_test(tc_let, acos7);
  tcase_add_test(tc_let, ceil1);
  tcase_add_test(tc_let, ceil2);
  tcase_add_test(tc_let, ceil3);
  tcase_add_test(tc_let, ceil4);
  tcase_add_test(tc_let, ceil5);
  tcase_add_test(tc_let, ceil6);
  tcase_add_test(tc_let, ceil7);
  tcase_add_test(tc_let, ceil8);
  tcase_add_test(tc_let, ceil9);
  tcase_add_test(tc_let, ceil10);
  tcase_add_test(tc_let, ceil11);
  tcase_add_test(tc_let, ceil12);
  tcase_add_test(tc_let, ceil13);
  tcase_add_test(tc_let, ceil14);
  tcase_add_test(tc_let, ceil15);
  tcase_add_test(tc_let, ceil16);
  tcase_add_test(tc_let, ceil17);
  tcase_add_test(tc_let, ceil18);
  tcase_add_test(tc_let, ceil19);
  tcase_add_test(tc_let, ceil20);
  tcase_add_test(tc_let, ceil21);
  tcase_add_test(tc_let, ceil22);
  tcase_add_test(tc_let, ceil23);
  tcase_add_test(tc_let, ceil24);
  tcase_add_test(tc_let, ceil25);
  tcase_add_test(tc_let, ceil26);
  tcase_add_test(tc_let, ceil27);
  tcase_add_test(tc_let, ceil28);
  tcase_add_test(tc_let, ceil29);
  tcase_add_test(tc_let, ceil30);
  tcase_add_test(tc_let, ceil31);
  tcase_add_test(tc_let, ceil32);
  tcase_add_test(tc_let, ceil33);
  tcase_add_test(tc_let, ceil34);
  tcase_add_test(tc_let, ceil35);
  tcase_add_test(tc_let, ceil36);
  tcase_add_test(tc_let, ceil37);
  tcase_add_test(tc_let, ceil38);
  tcase_add_test(tc_let, floor1);
  tcase_add_test(tc_let, floor2);
  tcase_add_test(tc_let, floor3);
  tcase_add_test(tc_let, floor4);
  tcase_add_test(tc_let, floor5);
  tcase_add_test(tc_let, floor6);
  tcase_add_test(tc_let, floor7);
  tcase_add_test(tc_let, floor8);
  tcase_add_test(tc_let, floor9);
  tcase_add_test(tc_let, floor10);
  tcase_add_test(tc_let, floor11);
  return s;
}

int main() {
  int success = 0;
  Suite *s;
  SRunner *runner;
  s = test_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  success = srunner_ntests_failed(runner);
  srunner_free(runner);
  if (success == 0) {
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
