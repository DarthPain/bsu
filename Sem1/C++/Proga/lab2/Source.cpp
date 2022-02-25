#include <cmath>
#include <iostream>
using namespace std;

int main() {
  // task1 Quadratic equasions
  double a, b, c, discr, x1, x2;

  cout << "Here you should enter A,B,C values to solve quadratic equation "
       << "of view: Ax^2 + Bx + C = 0\n";
  std::cout << "Enter A value ";
  std::cin >> a;
  std::cout << "Enter B value ";
  std::cin >> b;
  std::cout << "Enter C value ";
  std::cin >> c;

  // is equasion quadratic
  if (a == 0) {
    if (b == 0) {
      if (c == 0) {
        std::cout << "Infinit number of solutions";
      } else {
        std::cout << "No solutions in any given number field";
      }
    }
    std::cout << "Equasion is not quadratic, solution for \" " << b << "x + "
              << c << " = 0 \" is x = " << -c / b;
  } else {
    discr = b * b - 4. * a * c;

    // is there real roots
    if (discr >= 0) {
      x1 = (-b + sqrt(discr)) / (2. * a);
      x2 = (-b - sqrt(discr)) / (2. * a);

      std::cout << "Solutions for:\" " << a << "x^2 + " << b << "x + " << c
                << " = 0 \" are: \n";
      std::cout << "x1 = " << x1;
      std::cout << "\nx2 = " << x2;
    } else {
      std::cout << "There are no real solution for \" " << a << "x^2 + " << b
                << "x + " << c << " = 0 \" , Imaginary solutions are:\n";

      std::cout << "x1 = " << -b / (2. * a) << " + "
                << sqrt(abs(discr)) / (2. * a) << "i\n";
      std::cout << "x2 = " << -b / (2. * a) << " - "
                << sqrt(abs(discr)) / (2. * a) << "i";
    }
  }

  // task2
  int day, month, year;
  std::cout << "\n\nPlease, enter day, month and year to know the date of the "
               "following day\n";
  std::cout << "Enter day ";
  std::cin >> day;
  std::cout << "Enter month ";
  std::cin >> month;
  std::cout << "Enter year ";
  std::cin >> year;

  // data reality
  if (day > 0 && day < 32 && month > 0 && month < 13) {
    // for each Dec with year change
    if (day == 31 && month == 12) {
      std::cout << "Next day is 1.1." << ++year << "\n";
    } else if (day <= 29 && month != 2) {
      std::cout << "Next day is " << ++day << "." << month << "." << year
                << "\n";
    } else
        // for Feb at both types of years
        if (day == 28 && month == 2 && ((year / 4 == 0) && (year / 100 != 0))) {
      std::cout << "Next day is " << ++day << "." << month << "." << year
                << "\n";
    } else /* if it's extended year */ if (day == 28 && month == 2 &&
                                           !((year / 4 == 0) &&
                                             (year / 100 != 0))) {
      std::cout << "Next day is 1." << ++month << "." << year << "\n";
    } else
        // for each month except for Dec with month change
        if ((day == 30 &&
             ((month == 4) || (month == 6) || (month == 9) || (month == 11))) ||
            ((day = 31) && month != 2)) {
      std::cout << "Next day is 1." << ++month << "." << year << "\n";
    } else {
      std::cout << "Wrong data format";
    }
  } else {
    std::cout << "Wrong data format";
  }

  // task3 calculator
  int x, y;
  char oper;
  std::cout << "\n\nCalculator\n";
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

  system("pause");
  return 0;
}