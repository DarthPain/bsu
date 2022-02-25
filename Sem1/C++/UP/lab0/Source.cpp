#include <iostream>

int main() {
  // task1
  char name[100];

  std::cout << "What's your name ";
  std::cin >> name;
  std::cout << "Nice to meet you, " << name;

  // task2
  double x, y;
  char oper;

  std::cout << "\n\nTask 2 arithmetics\n";
  std::cout << "Enter number X = ";
  std::cin >> x;
  std::cout << "Enter number Y = ";
  std::cin >> y;
  std::cout << "Enter arithmetic operation for X and Y (+,-,*,/) ";
  std::cin >> oper;
  switch (oper) {
    case '+':
      std::cout << "X " << oper << " Y = " << x + y;
      break;
    case '-':
      std::cout << "X " << oper << " Y = " << x - y;
      break;
    case '*':
      std::cout << "X " << oper << " Y = " << x * y;
      break;
    case '/':
      y == 0 ? std::cout << "Division by 0 is forbidden"
             : std::cout << "X " << oper << " Y = " << x / y;
      break;
    default:
      std::cout << "Wrong operation. " << oper << " is not defined";
  }

  // task3
  // arithmetical
  int x3, y3;

  std::cout << "\n\nTask3 change values (1)";
  std::cout << "\nEnter number X = ";
  std::cin >> x3;
  std::cout << "Enter number Y = ";
  std::cin >> y3;
  x3 += y3;
  y3 = x3 - y3;
  x3 -= y3;
  std::cout << "Now X  = " << x3;
  std::cout << "\nNow Y = " << y3;

  // with extra variable
  double x32, y32, temp;

  std::cout << "\n\nTask3 change values (2)";
  std::cout << "\nEnter number X = ";
  std::cin >> x32;
  std::cout << "Enter number Y = ";
  std::cin >> y32;
  temp = x32;
  x32 = y32;
  y32 = temp;
  std::cout << "Now X  = " << x32;
  std::cout << "\nNow Y = " << y32;

  // task4
  double x4, y4;
  std::cout << "\n\nTask4 big formula";
  std::cout << "\nEnter number X = ";
  std::cin >> x4;
  std::cout << "Enter number Y = ";
  std::cin >> y4;
  if ((x4 - y4 * y4) != 0) {
    std::cout << "Result of equasion is "
              << (3 + x4 * x4 - y4 * y4 * y4) * (x4 + 3) * (x4 + 3) /
                     (x4 - y4 * y4);
  } else {
    std::cout << "division by zero, try different numbers";
  }

  // task5
  std::cout << "\n\nTask5 hour from the year begining\n";
  int time;
  std::cout << "Enter how many second passed since the year began ";
  std::cin >> time;
  std::cout << "It's " << time / 3600 << " hours passed";

  // task6
  double a;

  std::cout
      << "\n\nTask6 'a' to the power of X with limited number of operations\n";
  std::cout << "Enter 'a' value ";
  std::cin >> a;

  // a
  double a1 = a * a;  // 2(1)
  a1 *= a1;           // 4(2)
  std::cout << "a^4= " << a1 << "\n";

  // b
  double a2 = a * a;  // 2(1)
  a2 *= a2 * a2;      // 6(3)
  std::cout << "a^6= " << a2 << "\n";

  // v
  double a3 = a * a;  // 2(1)
  a3 *= a3 * a3;      // 6(3)
  a3 *= a;            // 7(4)
  std::cout << "a^7= " << a3 << "\n";

  // g
  double a4 = a * a;  // 2(1)
  a4 *= a4;           // 4(2)
  a4 *= a4;           // 8(3)
  std::cout << "a^8= " << a4 << "\n";

  // d
  double a5 = a * a;  // 2(1)
  a5 *= a5;           // 4(2)
  a5 *= a5;           // 8(3)
  a5 *= a;            // 9(4)
  std::cout << "a^9= " << a5 << "\n";

  // e
  double a6 = a * a;  // 2(1)
  double a61 = a6;    // save 2 (1)
  a6 *= a6;           // 4(2)
  a6 *= a6;           // 8(3)
  a6 *= a61;          // 10(4)
  std::cout << "a^10= " << a6 << "\n";

  // zg
  double a7 = a * a;  // 2(1)
  a7 *= a7;           // 4(2)
  double a71 = a7;    // save 4 (2)
  a7 *= a7;           // 8(3)
  a7 *= a;            // 9(4)
  a7 *= a71;          // 13(5)
  std::cout << "a^13= " << a7 << "\n";

  // z
  double a8 = a * a;  // 2(1)
  a8 *= a;            // 3(2)
  double a81 = a8;    // save 3(2)
  a8 *= a8;           // 6(3)
  double a82 = a8;    // save 6(3)
  a8 *= a81;          // 9(4)
  a8 *= a82;          // 15(5)
  std::cout << "a^15= " << a8 << "\n";

  // i
  double a9 = a * a;    // 2(1)
  a9 *= a9;             // 4(2)
  double a91 = a9 * a;  // 5 save (3)
  a9 *= a9;             // 8(4)
  a9 *= a9;             // 16(4)
  a9 *= a91;            // 21(5)
  std::cout << "a^21 = " << a9 << "\n";

  // k
  double a10 = a * a;  // 2(1)
  a10 *= a10;          // 4(2)
  double a101 = a10;   // save 4 (2)
  a10 *= a10;          // 8(3)
  double a102 = a10;   // save 8 (3)
  a10 *= a10;          // 16(4)
  a10 *= a101;         // 20(5)
  a10 *= a102;         // 28(6)
  std::cout << "a^28 = " << a10 << "\n";

  // l
  double a11 = a * a;  // 2(1)
  a11 *= a11;          // 4(2)
  a11 *= a11;          // 8(3)
  a11 *= a11;          // 16(4)
  a11 *= a11;          // 32(5)
  a11 *= a11;          // 64(6)
  std::cout << "a^64 = " << a11 << "\n";

  // task7
  double x7, x71;

  std::cout << "Enter 'x' value";
  std::cin >> x7;
  x71 = x7 * x7;  // 2
  std::cout << 4. * x71 * x7 + 3 * x71 + 2 * x7 + 1;
  std::cout << -4. * x71 * x7 + 3 * x71 - 2 * x7 + 1;

  return 0;
}
