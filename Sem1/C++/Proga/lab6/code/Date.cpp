#include "Date.h"
#include "Util.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

Date::Date() {
  day = 1;
  month = 1;
  year = 2019;
}

int Date::getDay() const {
  return day;
}

void Date::setDay(int current_day) {
  if (isValidDayOfMonth(current_day)) {
    day = current_day;
  } else { std::cout << "Wrong day for this month!(day now is" << day << ")\n"; }
}

int Date::getMonth() const {
  return month;
}

void Date::setMonth(int current_month) {
  if (isValidMonth(current_month)) {
    month = current_month;
  } else { std::cout << "Wrong month!(month now is" << month << ")\n"; }
}

int Date::getYear() const {
  return year;
}

void Date::setYear(int current_year) {
  year = current_year;
}

bool Date::isValidMonth(int current_month) {
  return ((current_month < 13) && (current_month > 0));
}

bool Date::isValidDayOfMonth(int current_day) {
  return (0 < current_day && current_day <= monthMaxDay());
}

bool Date::isLeap() {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

Date Date::nextDay() {
  Date date(day, month, year);
  if (day == 31 && month == 12) {
    date.day = 1;
    date.month = 1;
    date.year += 1;
  } else if (day == monthMaxDay()) {
    date.month += 1;
    date.day = 1;
  } else {
    date.day += 1;
  }

  return date;
}

Date Date::previousDay() {
  Date date(day, month, year);
  if (day == 1 && month == 1) {
    date.month = 12;
    date.day = 31;
    date.year -= 1;
  } else if (day == 1) {
    date.month -= 1;
    date.day = date.monthMaxDay();
  } else {
    date.day -= 1;
  }

  return date;
}

int Date::monthMaxDay() {
  int max_day = 28;
  if (month == 4 || month == 6 || month == 9 || month == 11) {
    max_day = 30;
  } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
    max_day = 31;
  } else if (isLeap()) {
    max_day = 29;
  }
  return max_day;
}

short Date::weekNumber() {
  return dayFromYearBeginning() / 7 + 1;
}

int Date::dayFromYearBeginning() {
  int sum_days = 0;
  for (int i = 1; i < month - 1; ++i) {
    sum_days += Date(1, month - i, year).monthMaxDay();
  }
  sum_days += day;
  return sum_days;
}

//Days before next birthday cant'n exceed 365 days except for 2.29
int Date::daysTillYourBirthday(Date birthday_date) {
  int to_birthday{0};

  if (birthday_date.day == 29 && birthday_date.month == 2) {
    to_birthday += 365 * (nextLeap(year) - year);
  }
  birthday_date.year = year;
  if (birthday_date.dayFromYearBeginning() < dayFromYearBeginning()) {
    birthday_date.year = year + 1;
    to_birthday += (isLeap() ? 366 : 365);
  }
  to_birthday -= abs(dayFromYearBeginning() - birthday_date.dayFromYearBeginning());

  return abs(to_birthday);
}

int Date::duration(Date date) {
  int days = 0;
  int direction = (date.year - year > 0) ? -1 : 1;
  for (; abs(date.year - year) > 1; date.year += direction) {
    days += (date.isLeap()) ? 366 : 365;
  }
  days += ((direction == -1) ? ((isLeap()) ? 366 - (dayFromYearBeginning() - date.dayFromYearBeginning()) : 365) : abs(
      dayFromYearBeginning() - date.dayFromYearBeginning()));
  return days;
}

int Date::nextLeap(int current_year) {
  while (!(current_year % 4 == 0 && (current_year % 100 != 0 || current_year % 400 == 0))) {
    current_year++;
  }
  return current_year;
}

std::string Date::toString() {
  return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
}
std::vector<Date> Date::ReadFromFile(std::string &path) {
  std::vector<Date> vec{};
  std::fstream fin{};
  fin.open(path);
  if (fin.is_open()) {
    std::string line{};
    std::vector<std::string> dates{};
    std::vector<std::string> current_value{};
    while (!fin.eof()) {
      std::getline(fin, line);
      dates = Util::ParseString(line, ';');
      for (std::string &datum : dates) {
        current_value = Util::ParseString(datum, '.');
        vec.push_back(Date{std::stoi(current_value.at(0)),
                           std::stoi(current_value.at(1)),
                           std::stoi(current_value.at(2))});
      }

    }

  } else { std::cout << "File is unreachable"; }

  fin.close();
  return vec;
}


