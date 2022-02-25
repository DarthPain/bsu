#include <iostream>
#include <cmath>

int main() {
	//Task1

  double x = 0, y = 0, z = 0;
  std::cout << "Enter X,Y,Z: ";
  std::cin >> x >> y >> z;
  if (z >= y) {
    if (z >= x) {
      x += z;
      z = x -z;
      x -= z;
    } else {
      y += z;
      z = y - z;
      y -= z;
	}
  } else if (y >= x) {
    x += y;
    y = x - y;
    x -= y;
  }
  if (y <= z) {
    y += z;
    z = y -z;
    y -= z;
  }

  std::cout << "x, y, z = " << x << ", " << y << ", " << z << std::endl;
  

  //Task2
  double M = 0;
  int m = 0;
  double n = 0;
  std::cout << "Enter \"M\" - mass and \"m\" - measurment size (1 - kilogramm, 2 - milligramm, 3 - gramm, 4 - tonn, 5 - centner): ";
  std::cin >> M >> m;
  switch (m) {
    case 1:
      n = 1;
      break;
    case 2:
      n = 1e-6;
      break;
    case 3:
      n = 1e-3;
      break;
    case 4:
      n = 1e3;
      break;
    case 5:
      n = 1e2;
      break;
    default:
      std::cout << "Wrong data format!";
      break;
  }
  std::cout << "Mass in kilo's = " << M * n << std::endl;

  //Task3
        double x = 0, y = 0, s = 0;
        std::cout << "Enter X,Y: ";
        std::cin >> x >> y;
        if (1 < x * y && x * y < 10) {
          s = exp(-x);
		} else if (12 < x * y && x * y < 40) {
          s = pow(abs(x + 4*y), 1. / 3);
        } else {
          s = x * x * y;
        }
        std::cout << "S = " << s << std::endl;


  system("pause");
  return 0;
}