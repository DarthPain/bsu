#include <iostream>
#include <cmath>
double function_7_1(double t) { return (1 / (1 + sqrt(2 * t))); }
double function_7_2(double t) { return (exp(t) * sin(t)); }
double function_7_3(double t) { return (1 / (3 + 2 * cos(t))); }
double integrate_left(double bot, double top, int precision, double (*function)(double));
const int BORDER_BOTTOM = 0;
const int BORDER_TOP_1 = 1;
const double BORDER_TOP_2 = M_PI / 4.;
const double BORDER_TOP_3 = M_PI / 6.;
const int PRECISION = 7;

int main() {
  std::cout << "Hello, World!" << std::endl;
  double (*function)(double x);
  function = &function_7_1;
  std::cout << integrate_left(BORDER_BOTTOM, BORDER_TOP_1, PRECISION, function) << "\n";
  function = &function_7_2;
  std::cout << integrate_left(BORDER_BOTTOM, BORDER_TOP_2, PRECISION, function) << "\n";
  function = &function_7_3;
  std::cout << integrate_left(BORDER_BOTTOM, BORDER_TOP_3, PRECISION, function) << "\n";
  return 0;
}

double integrate_left(double bot, double top, int precision, double (*function)(double)) {
  double h = (top - bot);
  double tmp{0};
  int n = 4;
  double eps{1};
  double s1{(*function)(bot) * h};
  double s2{((*function)(bot) + (*function)(bot + h / 2.)) * h / 2.};
  for (int i = 0; i < precision; ++i) {
    eps /= 10;
  }
  while (std::abs(s2 - s1) > eps) {
    s1 = s2;
    tmp = 0;
    for (int i = 1; i <= n; ++i) {
      tmp += (*function)(bot + (i * h - h) / n);
    }
    s2 = (h / n) * tmp;
    n *= 2;
  }

  return s2;
}