#ifndef CLION__IODATA_H_
#define CLION__IODATA_H_

#endif //CLION__IODATA_H_

#include "sorting_algorithms.h"
#include <array>
#include <string>
#include <fstream>

template<typename T>
void ReadArray(std::array<T, N> &array) {
  int f_w = 0;
  std::cout << "\nArray of " << N << " elements\nEnter 1 to fill array from keyboard, 2 - random: ";
  std::cin >> f_w;
  switch (f_w) {
    case 1:
      for (int i = 0; i < N; ++i) {
        std::cin >> array[i];
      }
      break;
    case 2:
      for (int i = 0; i < N; ++i) {
        array[i] = rand() % 2000 - 1000;
      }
      break;
    default:std::cout << "Wrong number!Try again!\n";
  }
}

template<typename T>
void ReadArrayFile(std::array<T, N> &array, std::string &file_path) {
  std::ifstream fin;
  fin.open(file_path);
  std::string line{};
  if (fin.is_open()) {
    std::cout << "File is open!\n";
    int i = 0;
    while (!fin.eof()) {
      std::getline(fin, line, ' ');
      array[i] = std::stoi(line);
      ++i;
    }
  } else {
    std::cout << "Wrong address!";
  }
  fin.close();
  std::cout << "File is closed!\n";
}

template<typename T>
void PrintArrayFile(std::array<T, N> &array, std::string file_path) {
  std::ofstream fout;
  fout.open(file_path);
  for (int i = 0; i < N; ++i) {
    fout << array[i] << " ";
  }
  fout.close();
}

template<typename T>
void PrintArray(std::array<T, N> &array) {
  for (int i = 0; i < N; ++i) {
    std::cout << array[i] << ' ';
  }
}