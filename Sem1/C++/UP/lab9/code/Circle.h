#ifndef CLION__CIRCLE_H_
#define CLION__CIRCLE_H_
#include "Shape3d.h"
class Circle : public Shape3d {
 protected:
  double radius;

 public:
  Circle();
  explicit Circle(double radius_);

  virtual double getRadius() const;
  virtual void setRadius(double radius_);

  double perimeter() override;
  double area() override;

  std::string toString() override;
};

#endif //CLION__CIRCLE_H_
