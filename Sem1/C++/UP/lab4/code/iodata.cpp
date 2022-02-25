#include "sorting_algorithms.h"
#include "iodata.h"


template <typename T>
void ReadArray(std::array<T, N> &array) {
  int f_w = 0;
  std::cout << "Array of " << N << " elements\nEnter 1 to fill array from keyboard, 2 - random: ";
  std::cin >> f_w;
  switch (f_w)
  {
	case 1:
    for (int i = 0; i < N; ++i) {
      std::cin >> array[i];
    } 
    break;
    case 2:
    for (int i = 0; i < N; ++i) {
      array[i] = rand()%2000 - 1000;
    }
    break;
    default:
      std::cout << "Wrong!";
  }

}

template <typename T>
void PrintArray(std::array<T, N> array) {
  for (int i = 0; i < N; ++i) {
    std::cout << array[i] << ' ';
  }
}
