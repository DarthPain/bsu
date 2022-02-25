#include <iostream>

int main() {
  int x = -10, res1{}, res2{}, res3{}, test{};

  std::cout << "Please, enter x for formulae: ";
  std::cin >> x;

  _asm {
    // formula 1
		xor eax,eax
		mov eax, x
		imul eax ; eax = x2
		mov res1, eax ; res = x2
		mov ecx, eax ; ecx = x2
		mov ebx,ecx ; ebx = x2
		add res1, 2 ; res = x2 +2
		xor edx,edx ; edx = 0
		mov eax,1 ; eax = 1
		div ecx ; eax = 1/x2
		adc res1,eax ; res = x2 + 2 + Z(1/x2)
		mov eax, ecx ; eax = x2
		imul x ; eax = x3
		mov ecx,eax ; ecx = x3
		mov eax,-8 ; eax = -8 
		cdq
		idiv ecx ; eax = -8/x3
		adc res1, eax ; res = x2 + 2 + Z(1/x2) - Z(8/x3)

          // formula 2
		mov eax,ebx ; eax = x2
		mov test,3 ; test = 3
		mul test ; eax = 3x2
		add eax,ecx ; eax = 3x2 + x3
		mov test,4 ; test = 4
		imul test ; eax = 4(x3 + 3x2)
		sub eax,x ; 
		sub eax,3 ; eax = 4(x3 + 3x2) - x - 3
		mov res2,eax ; res2 = |^|
		mov eax,x ; eax = x
		mov test,2
		imul test ; eax = 2x
		mov test,eax ; test = 2x
		mov eax,res2 ;
		cdq
		idiv test;
		mov res2,eax

        // formula 3
		mov eax,test ;
		imul test ;
		sub eax,1
		mov res3,eax

  }

  test = x * x + 2 + 1 / (x * x) - 8 / (x * x * x);

  std::cout << "Assembler result " << res1 << std::endl;
  std::cout << "Real C++ result " << test << std::endl;

  test = (4 * (x * x * x + 3 * x * x) - x - 3) / (2 * x);

  std::cout << "\nAssembler result " << res2 << std::endl;
  std::cout << "Real C++ result " << test << std::endl;

  test = (4*x-1)*(4*x+1)/4;

  std::cout << "\nAssembler result " << res3 << std::endl;
  std::cout << "Real C++ result " << test << std::endl;

  system("pause");
  return 0;
}