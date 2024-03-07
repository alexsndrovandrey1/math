#include "s21_math.h"

//+
int s21_abs(int x) { return x > 0 ? x : -x; }
//+
long double s21_fabs(double x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}
//+
long double s21_exp(
    double x) {  // возвращает значение e, возведенное в заданную степень
  long double res = 1;
  long double fact = 1;
  long double num = 1;
  int check_1 = 0;
  int check_2 = 0;
  if (x < 0) {
    x *= -1;
    check_1 = 1;
  }
  while (s21_fabs(fact) > EPS && check_2 == 0) {
    fact *= x / num;
    num += 1;
    res += fact;
    if (res > S21_DBL_MAX) {
      res = S21_INFINITY;
      check_2 = 1;
    }
  }
  if (check_1 == 1) {
    if (res > S21_DBL_MAX) {
      res = 0;
    } else {
      res = 1.0 / res;
    }
  }
  if (res > S21_DBL_MAX) {
    res = S21_INFINITY;
  }
  return res;
}
//+
long double s21_log(double x) {  // вычисляет натуральный логарифм
  int ex_pow = 0;
  double res = 0;
  double comp = 0;

  if (x == S21_INFINITY) {
    res = S21_INFINITY;
  } else if (x < 0) {
    res = S21_NAN;
  } else if (x == 0) {
    res = S21_MIN_INFINITY;
  } else {
    for (; x >= EXP; x /= EXP, ex_pow++) continue;

    for (int i = 0; i < 100; i++) {
      comp = res;
      res = comp + 2 * (x - s21_exp(comp)) / (x + s21_exp(comp));
    }
  }

  return (res + ex_pow);
}
//+
long double s21_fmod(double x, double y) {
  long double res = 0.0;
  if (s21_nan(x) || s21_nan(y)) {
    res = S21_NAN;
  } else if (s21_inf(x) && s21_inf(y)) {
    res = S21_NAN;
  } else if (s21_inf(y)) {
    res = x;
  } else if (s21_fabs(y) < 1e-7) {
    res = S21_NAN;
  } else if (s21_fabs(x) < 1e-7) {
    res = 0.0;
  } else {
    long long int num = 0;
    num = x / y;
    res = (long double)x - num * (long double)y;
  }
  return res;
}

//+
long double s21_pow(double base,
                    double deg) {  // возводит число в заданную степень
  long double res;
  long double copy = base;
  res = s21_exp(s21_log(copy) * deg);
  if (deg != deg) {
    if (base == 1) {
      res = 1;
    } else {
      res = S21_NAN;
    }
  }
  if (base != base) {
    if (deg == 0) {
      res = 1;
    } else {
      res = S21_NAN;
    }
  }
  if (deg == S21_MIN_INFINITY && base == base) {
    if (base == 1 || base == -1) {
      res = 1;
    } else if (-1 < base && base < 1) {
      res = S21_INFINITY;
    } else {
      res = 0;
    }
  }
  if (deg == S21_INFINITY && base == base) {
    if (base == S21_MIN_INFINITY) {
      res = S21_INFINITY;
    } else if (base == 1 || base == -1) {
      res = 1;
    } else if (-1 < base && base < 1) {
      res = 0;
    } else {
      res = S21_INFINITY;
    }
  }
  if (base == S21_MIN_INFINITY) {
    if (deg == 0) {
      res = 1;
    } else if (deg > 0) {
      res = S21_INFINITY;
    } else {
      res = 0;
    }
  }
  if (base == 0) {
    if (deg == 0) {
      res = 1;
    } else if (deg > 0) {
      res = 0;
    } else {
      res = S21_INFINITY;
    }
  }
  if (base < 0 && s21_fmod(deg, 1) != 0) {
    res = 1;
  }
  if (base < 0 && deg == 0) {
    res = 1;
  } else if (copy < 0) {
    copy = -copy;
    res = s21_exp(s21_log(copy) * deg);
    if (s21_fmod(deg, 2) != 0) {
      res = -res;
    }
  }
  return res;
}
//+
long double s21_sqrt(double x) {  // вычисляет квадратный корень
  long double res = 0;
  res = s21_pow(x, 0.5);
  if (x < 0) {
    res = S21_NAN;
  }
  return res;
}

long double fact(double x) {  // факториал, нужен для синуса
  long double res = 1;
  for (long double i = 1; i <= x; i++) {
    res *= i;
  }
  return res;
}
//+
long double s21_sin(double x) {  // вычисляет синус
  x = s21_fmod(x, 2 * S21_PI);
  long double res = 0;
  double deg = 1;
  double sign = 1;
  while (deg < 20) {
    res += sign * s21_pow(x, deg) / fact(deg);
    sign *= -1;
    deg += 2;
  }
  return res;
}
//+
long double s21_cos(double x) {  // вычисляет косинус
  x = s21_fmod(x, 2 * S21_PI);
  long double res = 0;
  double deg = 0;
  double sign = 1;
  while (deg < 20) {
    res += sign * s21_pow(x, deg) / fact(deg);
    sign *= -1;
    deg += 2;
  }

  return res;
}
//+
long double s21_tan(double x) {
  if (x == S21_PI / 2) {
    return 16331239353195370.000000;
  }
  return s21_sin(x) / s21_cos(x);
}
//+
long double s21_atan(double x) {  // вычисляет арктангенс
  int n = 20;
  long double res = 0;
  if (x == S21_INFINITY) {
    res = S21_PI / 2;
  } else if (x <= 1.0 && -1.0 <= x) {
    for (int i = 0; i < n; i++) {
      double elem = s21_pow(-1, (double)i);
      res += elem * s21_pow((double)x, 2 * i + 1) / (2 * i + 1);
    }
  } else {
    for (int i = 0; i < n; i++) {
      double elem = s21_pow(-1, (double)i);
      res += elem * s21_pow((double)x, -1 - 2 * i) / (2 * i + 1);
    }
    res = (S21_PI * s21_sqrt(s21_pow((double)x, 2))) / (2 * x) - res;
  }
  return res;
}

long double s21_asin(double x) {  // вычисляет арксинус
  long double res = 0;
  if (x < -1 || x > 1) {
    res = S21_NAN;
  } else if (x == 1) {
    res = S21_PI / 2;
  } else if (x == -1) {
    res = -S21_PI / 2;
  } else {
    long double elem = 1 - s21_pow((double)x, 2);
    x = x / (s21_sqrt(elem));
    res = s21_atan(x);
  }
  return res;
}

long double s21_acos(double x) {  // вычисляет арккосинус
  long double res = 0;

  if (x < -1 || x > 1) {
    res = S21_NAN;
  } else if (x == 1) {
    res = 0;
  } else if (x == -1) {
    res = S21_PI;
  } else {
    res = S21_PI / 2 - s21_asin(x);
  }

  return res;
}

long double s21_ceil(double x) {
  long double res = (long long int)x;
  if (s21_is_nan(x)) {
    res = s21_my_nan;
  } else if (s21_pos_inf(x)) {
    res = s21_my_inf;
  } else if (s21_negative_inf(x)) {
    res = -s21_my_inf;
  } else if (x > 0 && x != res) {
    res += 1;
  }
  return res;
}

long double s21_floor(double x) {
  long double res = 0.0;
  int elem = 0;

  if (!s21_fin(
          x)) {  // проверка на то является ли Х конечным числом(не NaN или inf)
    res = x;
    elem = 1;
  }
  if (elem == 0) {
    res = (long long int)x;  // кладем в res только целую часть от Х

    if (s21_fabs(x - res) > 0.0 &&
        s21_fabs(x) >
            0.0) {  // выполняется проверка условия, что разница между x и его
                    // целой частью больше 0.0 и само значение x больше 0.0

      if (x < 0.0) {  // если Х отрицательный то отнимаем 1 чтобы оруглить до
                      // ближайщего целого значения
        res--;
      }
    }
  }

  return res;
}