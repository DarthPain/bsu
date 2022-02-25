/*#include <iostream>

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
	  mov ebx,arr;
	  xor esi,esi;
	  mov ecx,n;
	  mov eax,n;
	  mov edx,n;

  _loop:
	  cmp [ebx][esi*2],10;
	  js _normal;
	  push [ebx][esi*2];
	  dec eax;
	  dec ecx;
	  push esi;
	  push eax;
	  mov [ebx + esi*2],0;
  _xch_loop:
	  inc esi;
	  cmp esi,edx;
	  je _out;
	  mov eax,[ebx + esi*2];
	  xchg [ebx + esi*2-2],eax;
	  mov [ebx + esi*2],0;
	  jmp _xch_loop;
  _out:
	  dec edx;
	  pop eax;
	  pop esi;
	  dec esi;

  _normal:
	  inc esi;
	  loop _loop;
	  
      cmp eax,n;
	  je _end;

	  mov esi,n;
  _fill_back:
	  pop [ebx][esi*2];
	  dec esi;
	  cmp eax,esi;
	  jne _fill_back;

  _end:




  }

  std::cerr << "HERE" << std::endl;

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ", ";
  }

  system("pause");
  return 0;
}*/

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
	  cmp	byte ptr [ebx][esi*2],	10;
	  js	_normal;

	  inc	esi;
	  cmp	esi,			n;
	  je	_end;
	  dec	esi;

	  mov	al,				byte ptr [ebx][esi*2];
	  push	esi;
	  push	al;
	  mov	eax,				n;
	  dec	eax;
  _xchg_loop:
	  inc	esi;
	  mov	dl,				byte ptr [ebx][esi*2];
	  mov	byte ptr [ebx][esi*2-2],	dl;
	  cmp	esi, eax;
	  jnz	_xchg_loop;
	  pop	al;
	  mov	byte ptr [ebx][esi*2],	al;
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

  system("pause");
  return 0;
}