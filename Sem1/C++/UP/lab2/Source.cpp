#include <iostream>

std::pair<double, double> solveQuadratic(double a, double b, double c);
void SayFollowingDay();
void AsianCalendar();

int main() {
  
  // Task1 chess
  int x1, x2, y1, y2;
  std::cout << "Enter starting field position (0 < n,m <= 8): ";
  while (true) {
    std::cin >> x1 >> y1;
    if (!((0 < x1) && (x1 <= 8) && (0 < y1) && (y1 <= 8))) {
      std::cout << "Wrong indexes, try again\n";
      continue;
    }
    break;
  }
  std::cout << "Enter final field position (0 < n,m <= 8) ";
  while (true) {
    std::cin >> x2 >> y2;
    if (!((0 < x2) && (x2 <= 8) && (0 < y2) && (y2 <= 8))) {
      std::cout << "Wrong indexes, try again";
      continue;
    }
    break;
  }

  if ((abs(x1 - x2) == 1 && abs(y1 - y2) == 2) ||
      (abs(x1 - x2) == 2 && abs(y1 - y2) == 1)) {
    std::cout << "It's possible to reach final field in one move\n";
  } else {
    std::cout << "Impossible\n";
  }

          std::cout << std::endl;

  // Task2 geometry
  double a = 0, b = 0, c = 0, d = 0, e = 0;
  std::cout << "Please, enter a,b,c,d,e for ó1=Cx2+Dx+F and y2=Ax+B\n";
  std::cout << "Enter A: ";
  std::cin >> a;
  std::cout << "Enter B: ";
  std::cin >> b;
  std::cout << "Enter C: ";
  std::cin >> c;
  std::cout << "Enter D: ";
  std::cin >> d;
  std::cout << "Enter E: ";
  std::cin >> e;

  std::cout << "Solving :\" " << c << "x^2 + " << d << "x + " << e << " = " << a
            << "x + " << b << " \"\n";

  std::pair<double, double> roots = solveQuadratic(c, d - a, e - b);
  std::cout << std::endl;
  if (isnan(roots.second) && isnan(roots.first)) {
    std::cout << "Can't find point for imaginary numbers\n";
  } else {
    /*std::cout << c << "x^2 + " << d << "x + " << e << " = "
              << c * roots.first * roots.first + d * roots.first + e << "\n";
    std::cout << c << "x^2 + " << d << "x + " << e << " = "
              << c * roots.second * roots.second + d * roots.second + e << "\n";
    std::cout << a << "x + " << b << " = " << a*roots.first + b << " \n";
    std::cout << a << "x + " << b << " = " << a*roots.second + b << " \n";*/
    if (roots.first != roots.second) {    
    std::cout << "We have two points: (" << roots.first << ", "
              << a * roots.first + b << ") and (" << roots.first << ", "
              << a * roots.second + b << ")\n";
	} else {
      std::cout << "We have one point: (" << roots.first << ", "
                << a * roots.first + b << ")\n";
	}
  }

          std::cout << std::endl;
  //Task3
  int number = 0;
  std::cout << "Enter number n (100 < n < 999): ";
  while (true) {
    std::cin >> number;
    if (!(100 <= number && number <= 999)) {
      std::cout << "Wrong number, try again\n";
      continue;
    }
    break;
  }

  switch (number / 100) {
      case 1: 
		  std::cout << "One hundred ";
		  break;
      case 2:
        std::cout << "Two hundreds ";
        break;
      case 3:
        std::cout << "Three hundreds ";
        break;
      case 4:
        std::cout << "Four hundreds ";
        break;
      case 5:
        std::cout << "Five hundreds ";
        break;
      case 6:
        std::cout << "Six hundreds ";
        break;
      case 7:
        std::cout << "Seven hundreds ";
        break;
      case 8:
        std::cout << "Eight hundreds ";
        break;
      case 9:
        std::cout << "Nine hundreds ";
        break;
    default:
        std::cout << "Error, somehow?!";
      break;
  }

  bool is_teen = false;
    switch ((number % 100) / 10) {
    case 1:
      is_teen = true;
	  //FOR TEENs
      switch ((number % 100) % 10) {
        case 1:
          std::cout <<  "eleven";
          break;
        case 2:
          std::cout << "twelve ";
          break;
        case 3:
          std::cout << "therteen ";
          break;
        case 4:
          std::cout << "forteen ";
          break;
        case 5:
          std::cout << "fifteen ";
          break;
        case 6:
          std::cout << "sixteen ";
          break;
        case 7:
          std::cout << "seventeen ";
          break;
        case 8:
          std::cout << "eighteen ";
          break;
        case 9:
          std::cout << "ninteen ";
          break;
        default:
          std::cout << "Error, somehow?!";
          break;
      }
      break;
    case 2:
      std::cout << "twenty ";
      break;
    case 3:
      std::cout << "thirty ";
      break;
    case 4:
      std::cout << "forty ";
      break;
    case 5:
      std::cout << "fifty ";
      break;
    case 6:
      std::cout << "sixty ";
      break;
    case 7:
      std::cout << "seventy ";
      break;
    case 8:
      std::cout << "eighty ";
      break;
    case 9:
      std::cout << "ninety ";
      break;
    case 0:
      std::cout << "and ";
      break;
    default:
      std::cout << "Error, somehow?!";
      break;
  }

	if (!is_teen) {
    switch ((number % 100) % 10) {
      case 1:
        std::cout << "one";
        break;
      case 2:
        std::cout << "two";
        break;
      case 3:
        std::cout << "three ";
        break;
      case 4:
        std::cout << "four ";
        break;
      case 5:
        std::cout << "five ";
        break;
      case 6:
        std::cout << "six ";
        break;
      case 7:
        std::cout << "seven ";
        break;
      case 8:
        std::cout << "eight ";
        break;
      case 9:
        std::cout << "nine ";
        break;
      case 0:
        break;
      default:
        std::cout << "Error, somehow?!";
        break;
    }
  }
        std::cout << std::endl;
        std::cout << std::endl;


		//Task 4 Asian calendar
        AsianCalendar();
        std::cout << std::endl;

		//Task5 the following day
        SayFollowingDay();

  
  system("pause");
  return 0;
}

std::pair<double, double> solveQuadratic(double a, double b, double c) {
  double discr, x1, x2;
  std::pair<double, double> roots(NAN, NAN);

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
      return (std::pair<double, double>{x1, x2});
    } else {
      std::cout << "There are no real solution for \" " << a << "x^2 + " << b
                << "x + " << c << " = 0 \" , Imaginary solutions are:\n";

      std::cout << "x1 = " << -b / (2. * a) << " + "
                << sqrt(abs(discr)) / (2. * a) << "i\n";
      std::cout << "x2 = " << -b / (2. * a) << " - "
                << sqrt(abs(discr)) / (2. * a) << "i\n";
    }
  }
  return (roots);
}


void AsianCalendar() {
  const int INITIAL_YEAR = 1984;
  int year = 0;
  std::cout << "Please, enter year ";
  std::cin >> year;
  std::cout << "\nIt's the year of ";
  switch(abs(year - INITIAL_YEAR) % 60 / 12) { 
  case 0:
      std::cout << "Green ";
      break;
  case 1:
    std::cout << "Red ";
    break;
  case 2:
    std::cout << "Yellow ";
    break;
  case 3:
    std::cout << "White ";
    break;
  case 4:
    std::cout << "Black ";
    break;
  default: 
	        std::cout << "\nError, somehow?!";
	  break;
  }

    switch (abs(year - INITIAL_YEAR) % 60 % 12) {
    case 0:
      std::cout << "Rat!";
      break;
    case 1:
      std::cout << "Cow!";
      break;
    case 2:
      std::cout << "Tiger!";
      break;
    case 3:
      std::cout << "Rabbit!";
      break;
    case 4:
      std::cout << "Dragon!";
      break;
    case 5:
      std::cout << "Snake!";
      break;
    case 6:
      std::cout << "Horse!";
      break;
    case 7:
      std::cout << "Sheep!";
      break;
    case 8:
      std::cout << "Monkey!";
      break;
    case 9:
      std::cout << "Chicken!";
      break;
    case 10:
      std::cout << "Dog!";
      break;
    case 11:
      std::cout << "Pig!";
      break;
    default:
      std::cout << "\nError, somehow?!";
      break;
  }



}


void SayFollowingDay() {
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
    } else /* if it's extended year */ if (day == 29 && month == 2 &&
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
}