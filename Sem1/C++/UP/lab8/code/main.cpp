#include <iostream>
#include "Containers.h"
#include "SharedPtr.h"

void dosmth(int *a, char *b) {
  SharedPtr<int> shared_ptr(a);
  SharedPtr<int> shared_ptr1(a);
  SharedPtr<char> shared_ptr2(b);
  SharedPtr<char> shared_ptr3(b);
  SharedPtr<char> shared_ptr4(b);
  std::cout << "SShare_ptr test: \n";
//  int *attempt_to_delete = shared_ptr.Get();
//  *attempt_to_delete = 198;
  *shared_ptr = 198;
  std::cout << "Now it's " << (*shared_ptr1.Get()) << "\n";
  shared_ptr.Release();
  shared_ptr3.Release();
}

void ReadNumbers(SharedPtr<Stack<int>> *tmp);

int main() {
//!BiList test
/*
  BiDirectionalList<int> list;
  list.PushBack(7);
  list.PushBack(8);
  list.PushFront(1);
  list.PushFront(0);
//  list.PopFront();
//  list.PopFront();
//  list.PopFront();
//  list.PopFront();
//  list.PopFront();
  std::cout << list.Size() << '\n';
  if (list.Front()) {
    std::cout << list.Front()->value << '\n';
    std::cout << list.Back()->value << '\n';
  } else { std::cout << "No elements\n"; }

  std::vector<int> vec = list.ToVector();
  for (const auto &item : vec) {
    std::cout << item << " ";
  }

  std::cout << "\n" << list.Find(7) << "\n";

  list.PushBack(7);
  list.PushBack(7);
  list.PushBack(7);

  vec = list.FindAll(7);
  for (const auto &item : vec) {
    std::cout << item << " ";
  }

  std::cout << "Element at [5].value = " << list[5]->value << " (7 expected)\n";

  list.InsertBefore(list[list.Find(1)],88888);
  std::cout << "Element before 1 is " << list[1]->value << "\n";

  list.InsertAfter(list[list.Find(0)],777777);
  std::cout << "Element before 0 is " << list[1]->value << "\n";

  list.Erase(list[list.Find(777777)]);
  std::cout << "Element before 0 is " << list[1]->value << "\n";

  BiDirectionalList<int> list1;
  BiDirectionalList<int> list2;
  list1.PushBack(1);
  list1.PushBack(2);
  list1.PushBack(3);
  list2.PushBack(1);
  list2.PushBack(2);
  list2.PushBack(3);
  std::cout << (list1 == list2) << '\n';
  */

//!Stack test
/*
  Stack<int> stack;
  stack.Push(7);
  stack.Push(8);
  stack.Push(9);
  stack.Pop();
  std::cout << stack.Get() << '\n';
  */

//!Shared_ptr test
  int *a = new int(7);
  char *b = new char('p');
  dosmth(a, b);
  std::cout << "Is a ok(198 , p - expected)? " << *a << " , " << *b << "\n";
  SharedPtr<Stack<int>> tmp{};
  ReadNumbers(&tmp);
  std::cout << "Is new stack empty: " << std::boolalpha << tmp->isEmpty();
  return 0;
}

void ReadNumbers(SharedPtr<Stack<int>> *tmp) {
  Stack<int> stack{};
  int a{3}, n{2};
  std::cout << "Enter number amount ";
  std::cin >> n;
  while (n-- > 0) {
  std::cin >> a;
  stack.Push(a);
  }
  (*tmp) = &stack;
}