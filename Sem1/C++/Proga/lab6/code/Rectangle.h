#ifndef CLION__RECTANGLE_H_
#define CLION__RECTANGLE_H_

#include "Point.h"

class Rectangle {
 private:
  Point left_up;
  Point right_bottom;

 public:
  Rectangle(const Point &current_left_up, const Point &current_right_bottom);
  Rectangle();

  double Area();

  static double IntersectionArea(Rectangle&,Rectangle&);


};

#endif //CLION__RECTANGLE_H_
