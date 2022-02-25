#include "Shape.h"

#include <utility>
Shape::Shape() : type(TYPES_BASIC) {
  ++id_base;
  id = id_base;
}
Shape::Shape(int type_) : type(type_) {
  ++id_base;
  id = id_base;
}
std::string Shape::toString() {
  std::string out{};
  out = "Id = " + std::to_string(id) + "; Type = " + std::to_string(type);
  return out;
}
long long int Shape::getId() const {
  return id;
}
int Shape::getType() const {
  return type;
}
void Shape::setType(int type_) {
  type = type_;
}

