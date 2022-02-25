#include "Date.h"
#include "RationalNumber.h"
#include "Rectangle.h"
#include "Util.h"

int main() {
//!Date tests
  Date date;
  date.setYear(2125);
  date.setMonth(2);
  date.setDay(28);
  std::cout << date.toString() << " \n";
  std::cout << date.getYear() << " isLeap = " << date.isLeap() << std::endl;

  Date date_next = date.nextDay();
  std::cout << "\nNext day is " << date_next.toString() << std::endl;
  Date date_prev = date.previousDay();
  std::cout << "Previous day is " << date_prev.toString() << std::endl;

  std::cout << "\n" << date.toString() << " ";
  std::cout << "\nWeek number is " << date.weekNumber() << "\n";

  Date date_birth;
  std::cout << "\n" << date.toString() << " ";
  date_birth.setYear(2128);
  date_birth.setMonth(2);
  date_birth.setDay(27);
  std::cout << "\n" << date_birth.toString() << " ";
  std::cout << "Your birthday is in " << date.daysTillYourBirthday(date_birth) << " days\n";

  Date date_duration;
  date_duration.setYear(2128);
  date_duration.setMonth(1);
  date_duration.setDay(1);
  std::cout << "\n" << date_duration.toString() << " ";
  std::cout << "Duration is  " << date.duration(date_duration) << " days\n";

//!RationalNumber tests
  RationalNumber number1{2, 0};
  RationalNumber number2{3, 6};
  std::cout << number1.ToString() << " + " << number2.ToString() << " = "
            << RationalNumber::Sum(number1, number2).ToString() << "\n";

  std::cout << number1.ToString() << " - " << number2.ToString() << " = "
            << RationalNumber::Subtraction(number1, number2).ToString() << "\n";

  std::cout << number1.ToString() << " * " << number2.ToString() << " = "
            << RationalNumber::Multiplication(number1, number2).ToString() << "\n";

  std::cout << number1.ToString() << " / " << number2.ToString() << " = "
            << RationalNumber::Division(number1, number2).ToString() << "\n";

//!Rectangle tests
  Rectangle rect1{Point{0, 0}, Point{10, -7}};
  Rectangle rect2{Point{1, -1}, Point{5, -17}};
  std::cout << "Intersection area of 2 rectangles = " << Rectangle::IntersectionArea(rect1, rect2);
  std::cout << "Is (0,0) < (1,-7) == " << (Point{0, 0} < Point{1, -7});

//!Date file tests
  std::vector<Date> vec{};
  std::string path{"../input.txt"};
  vec = Date::ReadFromFile(path);
  for (Date item : vec) {
    std::cout << item.toString() << " Next day is " << item.nextDay().toString() << "\n";
  }
  std::cout << "\n\n\n";
  for (int i = 0; i < vec.size() - 1; ++i) {
    std::cout << "Duration between " << vec.at(i).toString() << " and " << vec.at(i + 1).toString() << " == "
              << vec.at(i).duration(vec.at(i + 1)) << "\n";
  }

  return 0;
}