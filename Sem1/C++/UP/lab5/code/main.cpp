#include "iodata.h"
#include <chrono>
#include <ctime>
using namespace std::chrono;

int main() {
  /*
  std::array<int, N> my_array{};
  ReadArray(my_array);
  std::cout << std::endl;
  std::cout << "\n Sorting array and calculating everything: ";
  auto start = system_clock::now();
  selectSort(my_array, comp, exch);
  auto end = system_clock::now();
  auto elapsed_seconds = duration_cast<seconds>(end - start).count();
  auto elapsed_milliseconds = duration_cast<milliseconds>(end - start).count();
  std::time_t end_time = system_clock::to_time_t(end);
  std::cout << "\nAlgorithm execution time: " << elapsed_seconds << "s\n"
            << "Algorithm execution time: " << elapsed_milliseconds << "ms\n";

  std::cout << "\nComparisons " << comp << ", exchanges " << exch << "\n";
  //PrintArray(my_array);
*/



  std::array<int, N> my_array{};
  std::string file_path_input{"../data/input_10_random_1.txt"};
  ReadArrayFile(my_array, file_path_input);
  //PrintArray(my_array);
  /*ReadArray(my_array);
  PrintArrayFile(my_array, "../data/input_10000_random_1.txt");*/

  std::cout << "\n Sorting array and calculating everything: ";
  auto start = system_clock::now();
  insertionSort(my_array);
  //selectSort(my_array);
  auto end = system_clock::now();
  auto elapsed_seconds = duration_cast<seconds>(end - start).count();
  auto elapsed_milliseconds = duration_cast<milliseconds>(end - start).count();
  std::time_t end_time = system_clock::to_time_t(end);
  std::cout << "\nAlgorithm execution time: " << elapsed_seconds << "s\n"
            << "Algorithm execution time: " << elapsed_milliseconds << "ms\n";
  //PrintArray(my_array);

  std::string file_path_output{"../data/output_10_random_1.txt"};
  PrintArrayFile(my_array, file_path_output);

  return 0;
}