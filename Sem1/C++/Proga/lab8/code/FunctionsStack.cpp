#include "FunctionsStack.h"
int FunctionsStack::Formula(std::string &s) {
  StackOnList<char> stack{};
  for (const auto &item : s) {
    if (item != ',' && item != ' ') {
      stack.Push(item);
    }
  }
  while (stack.Size() != 1) {
    SolveOne(stack);
  }
  return stack.Top()->value_ - 48;
}

void FunctionsStack::SolveOne(StackOnList<char> &stack) {
  int brackets{};
  while (stack.Top()->value_ == ')') {
    stack.Pop();
    ++brackets;
  }
  int d1 = stack.Pop();
  while (stack.Top()->value_ == ')') { SolveOne(stack); }
  int d2 = stack.Pop();
  int result{};
  stack.Pop();
  char operation = stack.Pop();
  stack.Pop();
  stack.Pop();
  if (operation == 'x') {
    result = (d1 > d2) ? d1 : d2;
  } else { result = (d1 < d2) ? d1 : d2; }
  stack.Push(result);
  for (int i = 0; i < brackets - 1; ++i) {
    stack.Push(')');
  }
}

std::string FunctionsStack::BackPolishMake(std::string &s) {
  std::string polish{};
  StackOnList<char> stack{};
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == ' ') { continue; }
    if (isOperation(s[i])) {
      polish.push_back(' ');
      if (stack.Top() != nullptr && stack.Top()->value_ != '('
          && (OperationPriority(stack.Top()->value_) <= OperationPriority(s[i]))) {
        polish.push_back(stack.Pop());
        polish.push_back(' ');
      }
      stack.Push(s[i]);
    } else if (s[i] == ')') {
      while (stack.Top()->value_ != '(') {
        polish.push_back(' ');
        polish.push_back(stack.Pop());
      }
      stack.Pop();
    } else if (isNumber(s[i])) {
      polish.push_back(s[i]);
    }
  }
  while (stack.Top() != nullptr) {
    polish.push_back(' ');
    polish.push_back(stack.Pop());
  }

  return polish;
}

int FunctionsStack::BackPolishSolve(std::string &s) {
  StackOnList<int> stack{};
  std::string word{};
  if (s[s.length() - 1] != ' ') { s.push_back(' '); }
  int result{};
  while (s.length() > 0) {
    word = GetWord(s);
    if (isOperation(word)) {
      result = PerformOperation(stack.Pop(), stack.Pop(), word);
    } else {
      result = std::stoi(word);
    }
    stack.Push(result);
    if (s == " ") { break; }
  }

  return stack.Pop();
}
std::string FunctionsStack::GetWord(std::string &s, const char &delim) {
  std::string word = s.substr(0, s.find(delim));
  s = s.substr(s.find(delim) + 1);
  if (word.empty()) { return GetWord(s, delim); }
  return word;
}
int FunctionsStack::PerformOperation(int pop, int pop_1, std::string &operation) {
  int result{};
  if (operation == "*") {
    result = pop * pop_1;
  } else if (operation == "/") {
    result = pop / pop_1;
  } else if (operation == "%") {
    result = pop % pop_1;
  } else if (operation == "+") {
    result = pop + pop_1;
  } else if (operation == "-") {
    result = pop - pop_1;
  } else if (operation == "<<") {
    result = pop << pop_1;
  } else if (operation == ">>") {
    result = pop >> pop_1;
  } else if (operation == "<") {
    result = pop < pop_1;
  } else if (operation == ">") {
    result = pop > pop_1;
  } else if (operation == "<=") {
    result = pop <= pop_1;
  } else if (operation == ">=") {
    result = pop >= pop_1;
  } else if (operation == "==") {
    result = pop == pop_1;
  } else if (operation == "!=") {
    result = pop != pop_1;
  } else if (operation == "&") {
    result = pop & pop_1;
  } else if (operation == "^") {
    result = pop ^ pop_1;
  } else if (operation == "|") {
    result = pop | pop_1;
  }

  return result;
}

bool FunctionsStack::isNumber(char &symbol) {
  std::string digits = "0123456789";
  return digits.find(symbol) != std::string::npos;
}

bool FunctionsStack::isOperation(char &symbol) {
  std::string operations = "(*/%+-<<>><<=>>===!=&^|&&||";
  return (operations.find(symbol) != std::string::npos);
}
bool FunctionsStack::isOperation(std::string &word) {
  std::string operations = "(/*%+-<<>><<=>>===!=&^|&&||";
  return (operations.find(word) != std::string::npos);
}

// redundant
int FunctionsStack::OperationPriority(char &operation) {
  int result{0};
  std::string mult{"*/%"};
  std::string plus{"+-"};
  std::string bitshift{"<<>>"};
  std::string comparison{">=<="};
  std::string equality{"!=="};
  std::string binand{"&"};
  std::string binxor{"^"};
  std::string binor{"|"};
  std::string logand{"&&"};
  std::string logor{"||"};
  if (mult.find(operation) != std::string::npos) {
    result = 5;
  } else if (plus.find(operation) != std::string::npos) {
    result = 6;
  } else if (comparison.find(operation) != std::string::npos) {
    //! comparison first because of how find works e.g. > contains in >>
    result = 8;
  } else if (bitshift.find(operation) != std::string::npos) {
    result = 7;
  } else if (equality.find(operation) != std::string::npos) {
    result = 9;
  } else if (binand.find(operation) != std::string::npos) {
    result = 10;
  } else if (binxor.find(operation) != std::string::npos) {
    result = 11;
  } else if (binor.find(operation) != std::string::npos) {
    result = 12;
  } else if (logand.find(operation) != std::string::npos) {
    result = 13;
  } else if (logor.find(operation) != std::string::npos) {
    result = 14;
  }
  return result;
}

//!new ones
bool FunctionsStack::isNumber(std::string &word) {
  std::string digits = "0123456789";
  bool flag = true;
  for (const auto &symbol : word) {
    if (digits.find(symbol) == std::string::npos) {
      flag = false;
    }
  }
  return flag;
}

int FunctionsStack::OperationPriority(std::string &operation) {
  int result{0};
  std::string mult{"/*%"};
  std::string plus{"+-"};
  std::string bitshift{"<<>>"};
  std::string comparison{">=<="};
  std::string equality{"!=="};
  std::string binand{"&"};
  std::string binxor{"^"};
  std::string binor{"|"};
  std::string logand{"&&"};
  std::string logor{"||"};
  if (mult.find(operation) != std::string::npos) {
    result = 5;
  } else if (plus.find(operation) != std::string::npos) {
    result = 6;
  } else if (comparison.find(operation) != std::string::npos) {
    //! comparison first because of how find works e.g. > contains in >>
    result = 8;
  } else if (bitshift.find(operation) != std::string::npos) {
    result = 7;
  } else if (equality.find(operation) != std::string::npos) {
    result = 9;
  } else if (binand.find(operation) != std::string::npos) {
    result = 10;
  } else if (binxor.find(operation) != std::string::npos) {
    result = 11;
  } else if (binor.find(operation) != std::string::npos) {
    result = 12;
  } else if (logand.find(operation) != std::string::npos) {
    result = 13;
  } else if (logor.find(operation) != std::string::npos) {
    result = 14;
  }
  return result;
}


