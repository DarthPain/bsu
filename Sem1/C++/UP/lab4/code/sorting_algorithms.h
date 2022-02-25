#pragma once

#include <iostream>


const int N = 10000;

template <typename T>
void change(T &a, T &b);

template <class T>
void selectSort(std::array<T, N> &arr, int &comparison, int &exchange);

