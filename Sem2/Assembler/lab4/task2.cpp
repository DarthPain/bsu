#include <iostream>

int main() {
  int n;
  std::cout << "Enter array size(0<n<100): ";
  std::cin >> n;
  __int16 *arr = new __int16[n];
  std::cout << "Enter array elements:";
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  __asm {
	  mov	ebx,			arr;
	  xor	esi,			esi;
	  mov	ecx,			n;


  _loop:
	  cmp	[ebx][esi*2],	10;
	  js	_normal;

	  inc	esi;
	  cmp	esi,			n;
	  je	_end;
	  dec	esi;

	  mov	ax,				[ebx][esi*2];
	  push	esi;
	  push	ax;
	  mov	eax,				n;
	  dec	eax;
  _xchg_loop:
	  inc	esi;
	  mov	dx,				[ebx][esi*2];
	  mov	[ebx][esi*2-2],	dx;
	  cmp	esi, eax;
	  jnz	_xchg_loop;
	  pop	ax;
	  mov	[ebx][esi*2],	ax;
	  pop	esi;
	  dec	esi;

  _normal:
	  inc	esi;
	  loop _loop;


  _end:

  }


  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << std::endl;

  system("pause");
  return 0;
}