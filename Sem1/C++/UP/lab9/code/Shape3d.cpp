#include "Shape3d.h"

#include <utility>
double Shape3d::volume() { return 0; }
double Shape3d::surfaceArea() { return 0; }
std::string Shape3d::toString() {
  std::string out{};
  out = Shape2d::toString();
  out += "; Volume = " + ((volume() == 0) ? "0" : std::to_string(volume()));
  return out;
}
Shape3d::Shape3d(int type_) : Shape2d(type_) {}
Shape3d::Shape3d() : Shape2d() {}
