#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

int main() {
  double x, y, z, s;
  double a, b;

  /* x = x * M_PI / 180;
   y = y * M_PI / 180;
   z = z * M_PI / 180; */

  int t_n;
  std::cout << "Choose task number (1,2,3) ";
  std::cin >> t_n;

  switch (t_n) {
    case 1:
      // Task1
      std::cout << "Enter X, Y, Z\n";
      std::cin >> x >> y >> z;
      if (((abs(x - y) * z + x * x) != 0) && (abs(x)) <= 1) {
        s = 5 * atan(x) - (1. / 4) * acos(x) * (x + 3 * abs(x - y) + x * x) /
                              (abs(x - y) * z + x * x);
        std::cout << "Value is " << s << '\n';
      } else {
        std::cout << "Division by 0!\n";
      }

      break;

    case 2:
      // Task2
      std::cout << "Enter X, Y, Z\n";
      std::cin >> x >> y >> z;
      if ((z + x * x) != 0) {
        a = sqrt(abs(x)) * (x - y * y * y / (z + x * x));
        std::cout << "a = " << a << '\n';
      } else {
        std::cout << "Division by 0!";
      }
      b = x - x * x / 3. + pow(x, 5) / 5.;
      std::cout << "b = " << b << '\n';

      break;

    case 3:
      std::cout << "Enter X, Y, Z\n";
      std::cin >> x >> y >> z;
      if (z == - x*x/4.) {
        if ((1. + (y + sqrt(abs(-x))) * (x + pow(y, 1 / 3.) / (z + x * x / 4.))) != 0) {
          std::cout << "A = " << log(abs(1. + (y + sqrt(abs(-x))) * (x + pow(y, 1 / 3.) / (z + x * x / 4.))));
		} else {
          std::cout << "For A : Log of 0!";
		}
      } else {
        std::cout << "For A : Division by 0!";
	  }

      if (x != y && sin(z)*sin(z) != -tan(z)) {
            if (y + pow(x - 1, 1. / 3) >= 0) {
          std::cout << "B = " << sqrt(sqrt(y + pow(x - 1, 1. / 3))) / (abs(x - y) * (sin(z) * sin(z) + tan(z)));
        } else {
          std::cout << "For B : sqrt of negative!";
        }
      } else {
        std::cout << "For B : Division by 0!";
      }


      break;

    default:
      std::cout << "Wrong task number";
      break;
  }
  system("pause");
  return 0;
}