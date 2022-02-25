#ifndef CLION_DATE_H
#define CLION_DATE_H

#endif //CLION_DATE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


class Date {
 private:
  int day;
  int month;
  int year;

  bool isValidMonth(int current_month);

  bool isValidDayOfMonth(int current_day);

  int monthMaxDay();

  int dayFromYearBeginning();

  int nextLeap(int current_year);

  Date(int day, int month, int year);

 public:

  Date();

  int getDay() const;

  void setDay(int current_day);

  int getMonth() const;

  void setMonth(int current_month);

  int getYear() const;

  void setYear(int current_year);

  bool isLeap();

  Date nextDay();

  Date previousDay();

  short weekNumber();

  int daysTillYourBirthday(Date birthday_date);

  int duration(Date date);

  std::string toString();

  static std::vector<Date> ReadFromFile(std::string &);
};


