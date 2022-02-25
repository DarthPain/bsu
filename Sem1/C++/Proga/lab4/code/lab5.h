#ifndef CLION_INPUT_H
#define CLION_INPUT_H

#endif //CLION_INPUT_H

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "iodata.h"


void Task1();

void Task2();

void Task3();

void Task4();

void Task5();

void Task6();

template<class T>
T Max(T a);

template<class T>
T Max(T a, T b);

template<class T>
T Max(T a, T b, T c);

template<class T>
T Max(std::vector<T> vec);

template<class T>
int MaxInd(std::vector<T> vec, int ind_now);

bool Palindrome(std::string line, int ind_begin, int ind_end);

int NumRoot(int number);

template<class T>
void BubbleSort(std::vector<T> &vec);

double graph_parabola_X_top(double x);

double graph_parabola_X_bot(double x);

double graph_circle_top(double x);

double graph_circle_bot(double x);

double graph_lin(double x);

double graph_tan(double x);

bool IsInsideArea(double x, double y);