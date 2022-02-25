#ifndef CLION__SHAPE2D_H_
#define CLION__SHAPE2D_H_

#include "Shape.h"

class Shape2d : public Shape {
 public:

  Shape2d();
  explicit Shape2d(int type_);

  virtual double perimeter();
  virtual double area();

  std::string toString() override;

};

#endif //CLION__SHAPE2D_H_
