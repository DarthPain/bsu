#include "Shape2d.h"

#include <utility>
std::string Shape2d::toString() {
  std::string out{};
  out = Shape::toString();
  out += "; Perimeter = " + ((perimeter() == 0) ? "0" : std::to_string(perimeter()));
  return out;
}
double Shape2d::perimeter() { return 0; }
double Shape2d::area() { return 0; }
Shape2d::Shape2d() : Shape() {}
Shape2d::Shape2d(int type_) : Shape(type_) {}
