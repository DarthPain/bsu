#include <iostream>
#include <vector>

int main() {

	// Task1 - Change |max| and |min|
  const int N = 100;
  std::vector<double> arr(N);
  int n;

  std::cout << "Enter number of element in array (1<n<100) ";
  while (true) {
    std::cin >> n;
    if (n <= 100 and n >= 1) {
      break;
    }
    std::cout << "Error! Please, enter 1<n<100\n";
  }

  // filling type for array
  int fill_type = 0;
  double min, max;
  std::cout
      << "Please, choose the way of filling array (1 - keyboard, 2 - random) ";
  while (true) {
    std::cin >> fill_type;
    switch (fill_type) {
      case 1:
        std::cout << "Please, enter " << n << " elements\n";
        for (int i = 0; i < n; ++i) {
          std::cin >> arr[i];
        }
        break;
      case 2:
        std::cout << "Please, enter MIN and MAX range elements\n";
        std::cout << "Enter MIN value ";
        std::cin >> min;
        std::cout << "Enter MAX value ";
        std::cin >> max;
        if (min < max) {
          for (int i = 0; i < n; ++i) {
            arr[i] = (max - min) * ((double)rand() / (double)RAND_MAX) + min;
          }
        } else {
          std::cout << "Wrong range\n";
          continue;
        }
        break;
      default:
        std::cout
            << "Error! Please, enter correct type (1 - keyboard, 2 - random) ";
        continue;
    }
    break;
  }

  // find |max| and |min|
  int ind_max = 0, ind_min = 0;
  for (int i = 0; i < n; ++i) {
    if (abs(arr[i]) > abs(arr[ind_max])) {
      ind_max = i;
    }
    if (abs(arr[i]) < abs(arr[ind_min])) {
      ind_min = i;
    }
  }

  std::cout << "Before exchange\n";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }

  arr[ind_max] += arr[ind_min];
  arr[ind_min] = arr[ind_max] - arr[ind_min];
  arr[ind_max] -= arr[ind_min];

  std::cout << "\nAfter exchange\n";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }

  system("pause");
  return 0;
}