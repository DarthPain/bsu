#include "Util.h"

std::vector<std::string> Util::ParseString(std::string &line, const char &delimiter) {
  std::vector<std::string> result;
  if (line.at(line.length() - 1) != delimiter) { line += delimiter; }

  for (int i = 0; i < line.length(); ++i) {
    if (line.at(i) == delimiter) {
      result.push_back(line.substr(0, i));
      line = line.substr(i + 1);
      i = 0;
    }
  }
  return result;
}
