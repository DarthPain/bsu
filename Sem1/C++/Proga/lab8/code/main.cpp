#include <iostream>
#include "StackOnList.h"
#include "StackOnArray.h"
#include "FunctionsStack.h"
#include "gtest/gtest.h"

/*int main() {
  StackOnList<int> stack{};
  stack.Push(7);
  stack.Push(6);
  stack.Push(5);
  stack.Push(4);
  stack.Push(3);
  stack.Push(2);
  stack.Push(1);
  stack.Push(0);
  std::cout << stack.Top()->value_ << "\n";
  StackOnList<int> stack2(stack);
  std::cout << stack2.Size();*//*

  return 0;
}*/

TEST (StackOnList_test, all_tests) {
  StackOnList<int> stack{};
  stack.Push(7);
  stack.Push(1);
  stack.Push(0);
  EXPECT_EQ(0, stack.Top()->value_);
  stack.Pop();
  EXPECT_EQ(1, stack.Top()->value_);
  StackOnList<int> stack2(stack);
  EXPECT_EQ(2, stack2.Size());
  EXPECT_EQ(stack == stack2, true);
  stack2.Pop();
  stack2.Push(1);
  EXPECT_EQ(stack == stack2, true);
}

TEST (Polish_test, solve_expresion_polish) {
  std::string original{"33 + 4 * 2 / (5 - 1) * 2"};
  std::string polish = FunctionsStack::BackPolishMake(original);
  EXPECT_EQ(37, FunctionsStack::BackPolishSolve(polish));

  original = "3 + 4 * 2 / (5 - 1) * 2";
  polish = FunctionsStack::BackPolishMake(original);
  EXPECT_EQ(7, FunctionsStack::BackPolishSolve(polish));

  original = "3 + (4 * 2 / (5 - 1)) * 2";
  polish = FunctionsStack::BackPolishMake(original);
  EXPECT_EQ(7, FunctionsStack::BackPolishSolve(polish));

  original = "3 + ((4 * 2) / (5 - 1)) * 2";
  polish = FunctionsStack::BackPolishMake(original);
  std::cout << polish << "\n";
  EXPECT_EQ(7, FunctionsStack::BackPolishSolve(polish));

  original = "-3 + 4 * 2 / (5 - 1) * 2";
  polish = FunctionsStack::BackPolishMake(original);
  EXPECT_EQ(1, FunctionsStack::BackPolishSolve(polish));

  original = "-3 + -4 * 2 / (5 - 1) * 2";
  polish = FunctionsStack::BackPolishMake(original);
  EXPECT_EQ(-7, FunctionsStack::BackPolishSolve(polish));

  original = "3 + 4 * 2 / (5 - 1) * 24";
  polish = FunctionsStack::BackPolishMake(original);
  EXPECT_EQ(51, FunctionsStack::BackPolishSolve(polish));

  original = "(1 + 2) * 4 + 3";
  polish = FunctionsStack::BackPolishMake(original);
  EXPECT_EQ(15, FunctionsStack::BackPolishSolve(polish));

}

TEST (Polish_test, solve_logic_polish) {
  std::string original{"3 > 7"};
  std::string polish = FunctionsStack::BackPolishMake(original);
  EXPECT_EQ(0, FunctionsStack::BackPolishSolve(polish));

  original = "3 < 7";
  polish = FunctionsStack::BackPolishMake(original);
  EXPECT_EQ(1, FunctionsStack::BackPolishSolve(polish));

  original = "3 <= 7";
  polish = FunctionsStack::BackPolishMake(original);
  //EXPECT_EQ(1, FunctionsStack::BackPolishSolve(polish));
}

TEST (Min_max_test, solve_min_max) {
  std::string original{"8"};
  EXPECT_EQ(8, FunctionsStack::Formula(original));

  original = "max(4, min(3, 5))";
  EXPECT_EQ(4, FunctionsStack::Formula(original));

  original = "max(min(3, 5), 4)";
  EXPECT_EQ(4, FunctionsStack::Formula(original));

  original = "min(min(3, 5), max(2, max(3, 4)))";
  EXPECT_EQ(3, FunctionsStack::Formula(original));

  original = "min(max(2, max(3, 4)), min(3, 5))";
  EXPECT_EQ(3, FunctionsStack::Formula(original));

  original = "min(min(5,4),max(8,7))";
  EXPECT_EQ(4, FunctionsStack::Formula(original));

}