#include <iostream>
#include <cmath>

int main() { 
  unsigned int m{}, n{}, i{}, res{};
  std::cout << "Please, enter m,n(POSITIVE INTEGERS, also note that m <= digit number of n) for processing: ";
  std::cin >> m >> n;
  while (m == 0 || n == 0 || (n / pow(10, m) < 1)) {
    std::cout << "Wrong input data, try again: ";
    std::cin >> m >> n;
  }

  __asm {
	  mov ecx,m
	  mov eax,n
	  mov ebx,10
	  //loop
	  looper:
	  xor edx,edx
	  div ebx
	  adc res,edx
	  dec ecx
	  jecxz endoftheworld
	  jmp looper
	  endoftheworld:

  }

  std::cout << "Sum of m last digits of n is " << res << std::endl;

  system("pause");
  return 0;
}