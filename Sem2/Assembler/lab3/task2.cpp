#include <iostream>

int main() {
  int x{25}, y{}, count{};
  int result[20];


  _asm {
	  mov eax,x;
	  mov ebx,y;
	  xor ecx,ecx;
	  xor esi,esi;
	  
  _loop:
	  mov result[esi*4],eax;
	  inc esi;
	  mov result[esi*4],ebx;
	  inc esi;
	  add ecx,2;
	  add ebx,2;
	  add eax,-3;
	  js _end;
	  jmp _loop;
	  _end:
	  mov count,ecx;


  }

  std::cout << "Printing results of 50=2x+3y\n";
  for (int i = 0; i < count; i+=2) {
    std::cout << "50 = 2*" << result[i] << " + 3*" << result[1+i] << std::endl;
  }


  system("pause");
  return 0;
}