#include "RationalNumber.h"

int RationalNumber::GetNumerator() const {
  return numerator;
}
void RationalNumber::SetNumerator(int new_numerator) {
  RationalNumber::numerator = new_numerator;
}
unsigned int RationalNumber::GetDenominator() const {
  return denominator;
}
void RationalNumber::SetDenominator(unsigned int new_denominator) {
  if (new_denominator != 0) {
    RationalNumber::denominator = new_denominator;
  } else {
    std::cout << "0 as denominator is forbidden(default value = 1)\n";
    denominator = 1;
  }
}
void RationalNumber::Simplify() {
  int greatest_common_denominator = {gcd(abs(numerator), denominator)};
  numerator /= greatest_common_denominator;
  denominator /= greatest_common_denominator;
}
int RationalNumber::gcd(int a, int b) {
  return ((b == 0) ? a : gcd(b, a % b));
}
std::string RationalNumber::ToString() {
  return ((denominator == 1 || numerator == 0) ? std::to_string(numerator) : std::string{
      std::to_string(numerator) + "/" + std::to_string(denominator)});
}
RationalNumber::RationalNumber(int new_numerator, unsigned int new_denominator) {
  numerator = new_numerator;
  SetDenominator(new_denominator);
  Simplify();

}
RationalNumber RationalNumber::Sum(RationalNumber &a, RationalNumber &b) {
  RationalNumber result{};
  result.numerator = a.numerator * b.denominator + a.denominator * b.numerator;
  result.denominator = a.denominator * b.denominator;
  result.Simplify();
  return result;
}
RationalNumber RationalNumber::Subtraction(RationalNumber &a, RationalNumber &b) {
  RationalNumber result{};
  result.numerator = a.numerator * b.denominator - a.denominator * b.numerator;
  result.denominator = a.denominator * b.denominator;
  result.Simplify();
  return result;
}
RationalNumber RationalNumber::Multiplication(RationalNumber &a, RationalNumber &b) {
  RationalNumber result{};
  result.numerator = a.numerator * b.numerator;
  result.denominator = a.denominator * b.denominator;
  result.Simplify();
  return result;
}
RationalNumber RationalNumber::Division(RationalNumber &a, RationalNumber &b) {
  RationalNumber result{};
  result.numerator = a.numerator * b.denominator;
  result.denominator = a.denominator * b.numerator;
  result.Simplify();
  return result;
}

