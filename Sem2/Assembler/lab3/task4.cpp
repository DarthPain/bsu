#include <iostream>

int main() {
  int num{}, den{}, n{}, d{};
  char sgn{};
  std::cout << "Enter fraction as num/dem:\nnum= ";
  std::cin >> num;
  std::cout << "den= ";
  do {
    std::cin >> den;
    if (den == 0) {
      std::cout << "Wrong input: division by 0\nTry again. den = ";
    }
  } while (den == 0);
  sgn = ((num * den >= 0) ? ' ' : '-');
  d = abs(den);
  n = abs(num);

  _asm {

	  mov eax,n;
	  mov ebx,d;

  _loop_basic:
	  sub ebx,eax;
      jz _end;
	  js _loop_exchange;
      jmp _loop_basic;
  _loop_exchange: 
	  add ebx,eax;
	  xchg eax,ebx;
	  jmp _loop_basic
  _end:
	  mov ecx,eax;
	  mov eax,n;
	  xor edx,edx;
	  div ecx;
	  mov n,eax;
	  mov eax,d;
	  xor edx,edx;
	  div ecx;
	  mov d,eax;
  }

  std::cout << "Shortened fraction of " << num << "/" << den << " is " << sgn
            << n << "/" << d << std::endl;
  system("pause");
  return 0;
}