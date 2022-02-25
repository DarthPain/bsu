#include "Point.h"
Point::Point(double x, double y) : x(x), y(y) {}
double Point::GetX() const {
  return x;
}
void Point::SetX(double new_x) {
  Point::x = new_x;
}
double Point::GetY() const {
  return y;
}
void Point::SetY(double new_y) {
  Point::y = new_y;
}
bool Point::operator<(const Point &rhs) const {
  if (x < rhs.x)
    return true;
  if (rhs.x < x)
    return false;
  return y > rhs.y;
}
bool Point::operator>(const Point &rhs) const {
  return rhs < *this;
}
bool Point::operator<=(const Point &rhs) const {
  return !(rhs < *this);
}
bool Point::operator>=(const Point &rhs) const {
  return !(*this < rhs);
}
