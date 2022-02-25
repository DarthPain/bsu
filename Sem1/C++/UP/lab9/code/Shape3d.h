#ifndef CLION__SHAPE3D_H_
#define CLION__SHAPE3D_H_
#include "Shape2d.h"
class Shape3d : public Shape2d {
 public:

  Shape3d();
  explicit Shape3d(int type_);

  virtual double volume();
  virtual double surfaceArea();

  std::string toString() override;

};

#endif //CLION__SHAPE3D_H_
