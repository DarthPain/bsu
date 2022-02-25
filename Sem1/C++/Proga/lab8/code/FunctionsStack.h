#ifndef CLION__FUNCTIONSSTACK_H_
#define CLION__FUNCTIONSSTACK_H_

#include <string>
#include "StackOnList.h"
class FunctionsStack {
 public:
  static int Formula(std::string &s);
  static int BackPolishSolve(std::string &s);
  static std::string BackPolishMake(std::string &s);

 private:
  static void SolveOne(StackOnList<char> &stack);
  static std::string GetWord(std::string &s, const char &delim = ' ');

  static bool isNumber(std::string& word);
  static int OperationPriority(std::string &operation);
  static int PerformOperation(int pop, int pop_1, std::string &operation);
  static bool isNumber(char &symbol);
  static bool isOperation(char &symbol);
  static bool isOperation(std::string &word);
  static int OperationPriority(char &operation);

};

#endif //CLION__FUNCTIONSSTACK_H_
