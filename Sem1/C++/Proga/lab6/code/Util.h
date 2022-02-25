#ifndef CLION__UTIL_H_
#define CLION__UTIL_H_

#include <string>
#include <vector>

class Util {
 public:
  static std::vector<std::string> ParseString(std::string &line, const char &delimiter);

  template<class T>
  static T Min(T a, T b) {
    return ((a < b) ? a : b);
  }

  template<class T>
  static T Max(T a, T b) {
    return ((a > b) ? a : b);
  }
};

#endif //CLION__UTIL_H_
