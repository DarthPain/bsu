#include <iostream>

int main() { 
  int a{},res{};
  std::cout << "Enter positive integer a<=5 or negative -3<=a<=3" << std::endl;
  do {
    std::cin >> a;
    if (fabs(a) > 5) {
      std::cout << "Wrong input, please try again!\n";
	}
  } while (fabs(a) > 5);
  _asm {

	  mov eax,a;
	  mov ecx,a;
	  imul eax; 
	  imul eax; 
	  mov ebx,eax; a4
	  imul eax;
	  add ecx,eax;
	  imul ebx;
	  add ecx,eax;
	  mov res,ecx;
  }
  std::cout << "Result of a12+a8+a = " << res << std::endl;
	
	
system("pause");
return 0;
}