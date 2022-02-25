#include <iostream>
#include <vector>

void sort(std::vector<double> &arr, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (arr[i] > arr[j]) {
        arr[j] += arr[i];
        arr[i] = arr[j] - arr[i];
        arr[j] -= arr[i];
      }
    }
  }
}

int main() {
  //Task 3 - square of negative and then sort

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
            arr[i] =
                (max - min) * ((double)rand() / (double)RAND_MAX) +
                             min;
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

  std::cout << "Array: ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }


  for (int i = 0; i < n; ++i) {
    if (arr[i] < 0) {
      arr[i] *= arr[i];
    }
  }

  std::cout << "\nAfter squaring negatives\n";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }

  // sort
  sort(arr, n);

  std::cout << "\nAfter sort\n";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }

  system("pause");
  return 0;
}
