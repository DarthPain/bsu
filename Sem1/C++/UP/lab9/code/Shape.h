#ifndef CLION__SHAPE_H_
#define CLION__SHAPE_H_
#include <string>

enum types{
  TYPES_BASIC,
  TYPES_CIRCLE,
  TYPES_SECTOR
};

class Shape {
 protected:
  static long long int id_base;
  long long int id;
  int type;

 public:
  Shape();
  explicit Shape(int type_);

  virtual std::string toString();
  virtual long long int getId() const;
  virtual int getType() const;
  virtual void setType(int type_);


};

#endif //CLION__SHAPE_H_
