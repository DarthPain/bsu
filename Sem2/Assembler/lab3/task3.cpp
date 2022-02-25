#include <iostream>
#include <iomanip>

int main() {
  int fib[50], count{2};

  __asm {
	  xor eax,eax;
	  not eax;
	  shr eax,1;
	  mov ecx,2;
	  xor esi,esi;
	  mov fib[esi*4],0;
	  inc esi;
	  mov fib[esi*4],1;
	  inc esi; 
	  push 1;
	  push 0;
  _loop:
	  pop fib[esi*4];
	  pop ebx;
	  add fib[esi*4],ebx;
	  cmp fib[esi * 4],eax;
      jns _end;
	  push fib[esi*4];
	  push ebx;
	  inc esi;
      inc ecx;
	  jmp _loop;
  _end:

      mov count, ecx;
	  ;mov rest,eax;
  }
  //std::cout << rest << std::endl;
  std::cout << "Fibonachi numbers that suit int: \n";
  for (int i = 0; i < count; ++i) {
    std::cout << i+1 << ":" << std::setw(15) << std::setfill(' ') << fib[i] << std::endl;
  }

  system("pause");
  return 0;
}