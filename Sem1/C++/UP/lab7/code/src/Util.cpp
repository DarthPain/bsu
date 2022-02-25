#include "Util.h"
#pragma once

static vector<string> ParseString(string &line, const char &delimiter) {
  vector<string> result;
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


