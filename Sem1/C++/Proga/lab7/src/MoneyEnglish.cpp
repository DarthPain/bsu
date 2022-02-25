#include <iostream>
#include "MoneyEnglish.h"
MoneyEnglish::MoneyEnglish(long long int new_pound, int new_shilling, double new_penny) : MoneyEnglish(new_pound,
                                                                                                       new_shilling,
                                                                                                       new_penny,
                                                                                                       false) {
}

MoneyEnglish::MoneyEnglish(long long int new_pound, int new_shilling, double new_penny, bool is_neg) {
  if (is_neg) {
    pound = new_pound;
    shilling = new_shilling;
    penny = new_penny;
  } else {
    try {
      if (new_pound < 0 || new_shilling < 0 || new_penny < 0) { throw 1; }
    } catch (...) {
      std::cout << "Wrong money input!";
      exit(7);
    }
    SetPound(new_pound);
    SetShilling(new_shilling);
    SetPenny(new_penny);
  }
}
MoneyEnglish::MoneyEnglish() : pound(0), shilling(0), penny(0) {}

long long int MoneyEnglish::GetPound() const {
  return pound;
}
void MoneyEnglish::SetPound(long long int new_pound) {
  try {
    if (abs(new_pound) > 1000000000) { throw 1; }
    pound = new_pound;
  } catch (...) {
    std::cout << "Wrong pound value!";
    exit(7);
  }
  Validate();
}
int MoneyEnglish::GetShilling() const {
  return shilling;
}
void MoneyEnglish::SetShilling(int new_shilling) { //Exception throw if(shilling > 20)
  try {
    if (abs(new_shilling) >= 20) { throw 1; }
    shilling = new_shilling;
  } catch (int) {
    std::cout << "Can't give shilling 20 and more!";
    exit(1);
  } catch (...) {
    std::cout << "Wrong shilling input";
    exit(2);
  }
  Validate();
}
double MoneyEnglish::GetPenny() const {
  return penny;
}
void MoneyEnglish::SetPenny(double new_penny) { //Exception throw if(penny > 12)
  try {
    if (abs(new_penny) >= 12) { throw 1; }
    MoneyEnglish::penny = new_penny;
    RoundPenny();
  } catch (int) {
    std::cout << "Can't give penny 12 and more!";
    exit(1);
  } catch (...) {
    std::cout << "Wrong penny input";
    exit(2);
  }
  Validate();

}
bool MoneyEnglish::operator<(const MoneyEnglish &rhs) const {
  if (pound < rhs.pound) { return true; }
  if (rhs.pound < pound) { return false; }
  if (shilling < rhs.shilling) { return true; }
  if (rhs.shilling < shilling) { return false; }
  return penny < rhs.penny;
}
bool MoneyEnglish::operator>(const MoneyEnglish &rhs) const {
  return rhs < *this;
}
bool MoneyEnglish::operator<=(const MoneyEnglish &rhs) const {
  return !(rhs < *this);
}
bool MoneyEnglish::operator>=(const MoneyEnglish &rhs) const {
  return !(*this < rhs);
}
bool MoneyEnglish::operator==(const MoneyEnglish &rhs) const {
  return pound == rhs.pound &&
      shilling == rhs.shilling &&
      penny == rhs.penny;
}
bool MoneyEnglish::operator!=(const MoneyEnglish &rhs) const {
  return !(rhs == *this);
}
double MoneyEnglish::RoundPenny() {
  double penny_double{abs(penny) - trunc((abs(penny)))};
  if (0 <= penny_double && penny_double < .125) {
    penny = trunc(penny);
  } else if (.125 <= penny_double && penny_double < .375) {
    penny = trunc(penny) + ((penny < 0) ? -.25 : .25);
  } else if (.375 <= penny_double && penny_double < .625) {
    penny = trunc(penny) + ((penny < 0) ? -.5 : .5);
  } else if (.625 <= penny_double && penny_double < .875) {
    penny = trunc(penny) + ((penny < 0) ? -.75 : .75);
  } else {
    penny = trunc(penny) + ((penny < 0) ? -1 : 1);
  }
  return 0;
}
MoneyEnglish MoneyEnglish::operator-() {
  return MoneyEnglish{-pound, -shilling, -penny, true};
}
MoneyEnglish MoneyEnglish::operator+(MoneyEnglish &second_money) {
  double penny_sum{penny + second_money.penny};
  int shilling_sum{shilling + second_money.shilling + (abs(penny_sum) >= 12 ? ((penny_sum < 0) ? -1 : 1) : 0)};
  return MoneyEnglish{pound + second_money.pound + ((abs(shilling_sum) >= 20) ? ((shilling_sum < 0) ? -1 : 1) : 0),
                      ((abs(shilling_sum) >= 20) ? (shilling_sum + ((shilling_sum < 0) ? 20 : -20)) : shilling_sum),
                      (abs(penny_sum) >= 12) ? (penny_sum + ((penny_sum < 0) ? 12 : -12)) : penny_sum,
                      true};
}
MoneyEnglish &MoneyEnglish::operator+=(MoneyEnglish &second_money) {
  double penny_sum{penny + second_money.penny};
  int shilling_sum{shilling + second_money.shilling + (abs(penny_sum) >= 12 ? ((penny_sum < 0) ? -1 : 1) : 0)};
  (*this) = MoneyEnglish(pound + second_money.pound + ((abs(shilling_sum) >= 20) ? ((shilling_sum < 0) ? -1 : 1) : 0),
                         ((abs(shilling_sum) >= 20) ? (shilling_sum + ((shilling_sum < 0) ? 20 : -20)) : shilling_sum),
                         (abs(penny_sum) >= 12) ? (penny_sum + ((penny_sum < 0) ? 12 : -12)) : penny_sum,
                         true);
  return (*this);
}
MoneyEnglish MoneyEnglish::operator-(MoneyEnglish &second_money) {
  return operator+(-second_money).Validate();
}
MoneyEnglish &MoneyEnglish::operator-=(MoneyEnglish &second_money) {
  operator+=(-second_money);
  (*this) = (*this).Validate();
  return (*this);
}

MoneyEnglish &MoneyEnglish::operator=(const MoneyEnglish &money_new) {
  if (&money_new != this) {
    pound = money_new.pound;
    shilling = money_new.shilling;
    penny = money_new.penny;
  }
  return (*this);
}

std::ostream &operator<<(std::ostream &os, const MoneyEnglish &english) {
  if (english.pound < 0 || english.shilling < 0 || english.penny < 0) { os << "- "; }
  if (english.pound != 0) { os << abs(english.pound) << "pd. "; }
  if (english.shilling != 0) { os << abs(english.shilling) << "sh. "; }
  if (english.penny != 0) { os << abs(english.penny) << "p. "; }
  if (english.pound == 0 && english.shilling == 0 && english.penny == 0) { os << "0p. "; }
  return os;
}

MoneyEnglish MoneyEnglish::Validate() {
  if (pound > 0) {
    if (penny < 0) {
      shilling -= 1;
      penny += 12;
    }
    if (shilling < 0) {
      pound -= 1;
      shilling += 20;
    }
  }

  if (pound < 0 && (penny > 0 || shilling > 0)) {
    if (penny > 0) {
      shilling += 1;
      penny -= 12;
    }
    if (shilling > 0) {
      pound += 1;
      shilling -= 20;
    }
  }

  return (*this);
}