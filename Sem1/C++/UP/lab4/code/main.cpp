#include <iostream>
#include <array>
#include "sorting_algorithms.h"
#include "iodata.h"


#include "sorting_algorithms.cpp"
#include "iodata.cpp"
#pragma warning(disable : 4996)
#include <chrono>
#include <ctime>
using namespace std::chrono;


int main() {
  long long sum = 0;
  std::array<int, N> my_array;
  int comp = 0, exch = 0;
  std::cout << "Enter array(10 elements) ";
  ReadArray(my_array);
  std::cout << '\n';
  PrintArray(my_array);
  std::cout << "\n Sorting array and calculating everything: ";
  auto start = system_clock::now();
  selectSort(my_array, comp, exch);
  auto end = system_clock::now();
  auto elapsed_seconds = duration_cast<seconds>(end - start).count();
  auto elapsed_milliseconds = duration_cast<milliseconds>(end - start).count();
  std::time_t end_time = system_clock::to_time_t(end);
  std::cout << "Calculations are finished on " << std::ctime(&end_time)
            << "Algorithm execution time: " << elapsed_seconds << "s\n"
            << "Algorithm execution time: " << elapsed_milliseconds << "ms\n";

  std::cout << "\nComparisons " << comp << ", exchanges " << exch << "\n";
  PrintArray(my_array);

  system("pause");
	return 0;
}