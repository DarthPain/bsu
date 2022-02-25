#ifndef CLION__SECTOR_H_
#define CLION__SECTOR_H_
#include "Circle.h"
#include <cmath>
class Sector : public Circle {
 protected:
  double angle;

 public:

  Sector();
  //explicit Sector(double radius_);
  Sector(double radius_, double angle_ = 2. * M_PI);

  double perimeter() override;
  std::string toString() override;
  double area() override;

};

#endif //CLION__SECTOR_H_
