#ifndef CLION__POINT_H_
#define CLION__POINT_H_

#include <iostream>

class Point {
 private:
  double x;
  double y;

 public:
  Point(double x = 0, double y = 0);

  double GetX() const;
  void SetX(double new_x);
  double GetY() const;
  void SetY(double new_y);
  bool operator<(const Point &rhs) const;
  bool operator>(const Point &rhs) const;
  bool operator<=(const Point &rhs) const;
  bool operator>=(const Point &rhs) const;
};

#endif //CLION__POINT_H_
