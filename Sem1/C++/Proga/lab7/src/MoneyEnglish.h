#ifndef CLION__MONEYENGLISH_H_
#define CLION__MONEYENGLISH_H_

#include <cmath>
#include <ostream>

class MoneyEnglish {
 private:
  long long int pound;
  int shilling;
  double penny;
  double RoundPenny();
  MoneyEnglish(long long int new_pound, int new_shilling, double new_penny, bool is_neg);
  MoneyEnglish Validate();

 public:
  MoneyEnglish(long long int new_pound, int new_shilling, double new_penny);
  MoneyEnglish();

  long long int GetPound() const;
  void SetPound(long long int new_pound);
  int GetShilling() const;
  void SetShilling(int new_shilling);
  double GetPenny() const;
  void SetPenny(double new_penny);

  bool operator<(const MoneyEnglish &rhs) const;
  bool operator>(const MoneyEnglish &rhs) const;
  bool operator<=(const MoneyEnglish &rhs) const;
  bool operator>=(const MoneyEnglish &rhs) const;

  bool operator==(const MoneyEnglish &rhs) const;
  bool operator!=(const MoneyEnglish &rhs) const;

  MoneyEnglish operator-();
  MoneyEnglish operator+(MoneyEnglish &);
  MoneyEnglish &operator+=(MoneyEnglish &);
  MoneyEnglish operator-(MoneyEnglish &);
  MoneyEnglish &operator-=(MoneyEnglish &);

  MoneyEnglish &operator=(const MoneyEnglish &);

  friend std::ostream &operator<<(std::ostream &os, const MoneyEnglish &english);

};

#endif //CLION__MONEYENGLISH_H_
