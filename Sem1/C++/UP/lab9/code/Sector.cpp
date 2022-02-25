#include "Sector.h"
#include <cmath>
double Sector::perimeter() {
  return Circle::perimeter() * angle / (M_PI * 2.) + 2 * radius;
}
double Sector::area() {
  return Circle::area() * angle / (M_PI * 2.);
}
Sector::Sector() : Circle(), angle(0) {
  radius = 0;
  type = TYPES_SECTOR;
}
//Sector::Sector(double radius_) : Circle(radius_), angle(2. * M_PI) { type = TYPES_SECTOR; }
Sector::Sector(double radius_, double angle_) : Circle(radius_), angle(std::abs(angle_)) { type = TYPES_SECTOR;}
std::string Sector::toString() {
  return Circle::toString() + "; Angle(Rad) = " + ((angle == 0) ? "0" : std::to_string(angle));
}
