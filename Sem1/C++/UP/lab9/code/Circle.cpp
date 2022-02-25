#include "Circle.h"
#include <cmath>
Circle::Circle() : Shape3d(TYPES_CIRCLE), radius(0) {}
Circle::Circle(double radius_) : Shape3d(TYPES_CIRCLE), radius(std::abs(radius_)) {}
double Circle::perimeter() { return (2 * M_PI * radius); }
double Circle::area() { return (M_PI * radius * radius); }
double Circle::getRadius() const { return radius; }
void Circle::setRadius(double radius_) { radius = std::abs(radius_); }
std::string Circle::toString() {
  return Shape3d::toString() + "; Radius = " +  ((radius == 0) ? "0" : std::to_string(radius));
}
