#include "sorting_algorithms.h"


template <typename T>
void change(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <class T>
void selectSort(std::array<T, N> &arr, int &comparison, int &exchange) {
  int i,j, ind_min;
  T elem_min;
  for (i = 0; i < N; ++i) {
    ind_min = i;
    elem_min = arr[i];

	for (j = i + 1; j < N; ++j) {
      comparison++;
      if (arr[j] < elem_min) {
        ind_min = j;
        elem_min = arr[j];
      }
    }

	change(arr[ind_min], arr[i]);
    exchange++;

  }
}