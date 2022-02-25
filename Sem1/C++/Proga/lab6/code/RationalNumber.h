#ifndef CLION__RATIONALNUMBER_H_
#define CLION__RATIONALNUMBER_H_

#include <iostream>
#include <cmath>
#include<string>

class RationalNumber {
 private:
  int numerator;
  unsigned int denominator;

  void Simplify();
  int gcd(int, int);
 public:
  RationalNumber(int new_numerator = 1, unsigned int new_denominator = 1);

  static RationalNumber Sum(RationalNumber &, RationalNumber &);
  static RationalNumber Subtraction(RationalNumber &, RationalNumber &);
  static RationalNumber Multiplication(RationalNumber &, RationalNumber &);
  static RationalNumber Division(RationalNumber &, RationalNumber &);

  int GetNumerator() const;
  void SetNumerator(int new_numerator);
  unsigned int GetDenominator() const;
  void SetDenominator(unsigned int new_denominator);

  std::string ToString();

};

#endif //CLION__RATIONALNUMBER_H_
