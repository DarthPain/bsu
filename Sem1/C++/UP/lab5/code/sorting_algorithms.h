#ifndef CLION__SORTING_ALGORITHMS_H_
#define CLION__SORTING_ALGORITHMS_H_

#endif //CLION__SORTING_ALGORITHMS_H_

#include <iostream>

const int N = 10;

template<class T>
void change(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template<class T>
void selectSort(std::array<T, N> &arr) {
  int i, j, ind_min, comparison{0}, exchange{0};
  for (i = 0; i < N; ++i) {
    ind_min = i;
    for (j = i + 1; j < N; ++j) {
      comparison++;
      if (arr[j] < arr[ind_min]) {
        ind_min = j;
      }
    }
    change(arr[ind_min], arr[i]);
    exchange++;
  }
  std::cout << "Selection sort: Comparisons " << comparison << ", exchanges " << exchange << "\n";
}

template<typename T>
void insertionSort(std::array<T, N> &arr) {
  int j, comparison{0}, exchange{0};
  for (int i = 1; i < N; i++) {
    for (j = i; j > 0 && arr.at(j - 1) > arr.at(j); j--) {
      comparison++;
      exchange++;
      change(arr.at(j - 1), arr.at(j));
    }
  }
  std::cout << "Selection sort: Comparisons " << comparison << ", exchanges " << exchange << "\n";
}

//@TODO do it later,please!
template<typename T>
void shellSort(std::array<T, N> &arr) {
  int j, comparison{0}, exchange{0};
  for (int i = 1; i < N; i++) {
    for (j = i; j > 0 && arr.at(j - 1) > arr.at(j); j--) {
      comparison++;
      exchange++;
      change(arr.at(j - 1), arr.at(j));
    }
  }
  std::cout << "Selection sort: Comparisons " << comparison << ", exchanges " << exchange << "\n";
}