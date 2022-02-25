#pragma once
#include <iomanip>
#include <iostream>

extern "C" void _cdecl task2(double* result, int* percision);

extern "C" void _cdecl task3(double* result, int* percision);

extern "C" void _cdecl task4(double* result);

extern "C" void _cdecl task5(double* x, double* result);

void task2C() {
  std::cout << "Task2 Pi calculation\n";
  double* pi = new double(0);
  int* percision = new int[3];
  percision[0] = 0;
  percision[1] = 0;
  percision[2] = 0;
  task2(pi, percision);
  std::cout << "Pi aprocsimation is " << std::setprecision(12) << *pi
            << std::endl;
  std::cout << "Series members required to get 5 digits is " << percision[0]
            << std::endl;
  std::cout << "Series members required to get 7 digits is " << percision[1]
            << std::endl;
  std::cout << "Series members required to get 9 digits is " << percision[2]
            << std::endl;
}

void task3C() {
  std::cout << "\nTask3 Ln2 calculation\n";
  double* ln2 = new double(0.0);
  int* percision1 = new int[3];
  percision1[0] = 0;
  percision1[1] = 0;
  percision1[2] = 0;
  task3(ln2, percision1);
  std::cout << "Ln2 aprocsimation is " << std::setprecision(12) << *ln2
            << std::endl;
  std::cout << "Series members required to get 5 digits is " << percision1[0]
            << std::endl;
  std::cout << "Series members required to get 7 digits is " << percision1[1]
            << std::endl;
  std::cout << "Series members required to get 9 digits is " << percision1[2]
            << std::endl;
}

void task4C() {
  std::cout << "\nTask4 Integral calculation\n";
  double* integral = new double(0.0);
  task4(integral);
  std::cout << "Integral [0,2Pi] 'x*cos(x)' = " << std::setprecision(12)
            << *integral << std::endl;
}

void task5C() {
  std::cout << "\nTask5  0.5^x calculation\n";
  double *x = new double(-5.7), *res = new double(0);
  std::cout << "Enter x for '0.5^x' : ";
  std::cin >> *x;
  task5(x, res);
  std::cout << "0.5^" << *x << " = " << std::setprecision(12) << *res
            << std::endl;
}