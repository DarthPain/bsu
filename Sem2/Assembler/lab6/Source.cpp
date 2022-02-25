#include <iostream>

extern "C" int __cdecl p1(int**, int);
extern "C" int __stdcall p2(int**,int);
extern "C" int __fastcall p3(int**,int);

int main() {
  int n{}, result{};
  std::cout << "Enter matrix size (NxN, 1 < N <= 10) " << std::endl;
  while (n <= 0 || n >= 11) {
    std::cin >> n;
  }

  int** arr = new int*[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = new int[n];
  }

  std::cout << "Enter array elements: " << std::endl;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> arr[i][j];
    }
  }

  // output matrix
  std::cout << std::endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
  if (n > 1) {
    std::cout << "\n(CDECL)The least element in matrix is " << p1(arr, n)
              << std::endl;
    std::cout << "\n(STDCALL)The least element in matrix is " << p2(arr,n)
			  << std::endl; 
	std::cout << "\n(FASTCALL)The least element in matrix is " << p3(arr,n)
		      << std::endl;
  } else {
    std::cout << "No such elements!\n";
  }

  for (int i = 0; i < n; ++i) {
    delete[] arr[i];
  }
  delete[] arr;
  system("pause");
  return 0;
}