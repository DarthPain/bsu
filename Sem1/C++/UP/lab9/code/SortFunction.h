#ifndef CLION__SORTFUNCTION_H_
#define CLION__SORTFUNCTION_H_
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "Shape3d.h"
#include "old/Containers.h"

enum SortType {
  SORTTYPE_PERIMETER,
  SORTTYPE_VOLUME
};

class SortFunction {
 private:
  static std::string wordFromString(std::string &line, char delim);
  static bool isFigure(std::string line);
  static Shape3d *toFigure(std::string &line);
  static std::vector<std::string> ReadInfo(std::string &path);
  static void WriteInfo(std::string &path, BiDirectionalList<Shape3d *> &figures);
  static BiDirectionalList<Shape3d *> Sort(std::vector<std::string> &objects);

 public:
  static void SortAll(std::string &file_in, std::string &file_out);

  static bool isNumber(std::string &line);
};

#endif //CLION__SORTFUNCTION_H_
