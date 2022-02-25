#include <iostream>

int main() {
  int n{}, result{};
  std::cout << "Enter matrix size (NxN, 1 < N <= 10) " << std::endl;
  while (n <= 0 || n >= 11) 
  {
    std::cin >> n;
  }

  int** arr = new int*[n];
  for (int i = 0; i < n; ++i)
  {
    arr[i] = new int[n];
  }

  std::cout << "Enter array elements: " << std::endl;
  

  for (int i = 0; i < n; ++i) 
  {
    for (int j = 0; j < n; ++j)
	{
      std::cin >> arr[i][j];
	}
  }

  //output matrix
  std::cout << std::endl;
  for (int i = 0; i < n; ++i) 
  {
	for (int j = 0; j < n; ++j) 
	{
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
  if (n > 1) {
  __asm 
  {
    
	  push	esi						;
	  push	edi						;
	  mov	edi,	arr				; edi = &arr
	  xor	eax,	eax				; eax - lowest elem
	  xor	edx,	edx				; edx - compare elem
         mov  ecx,	n				; - rows

	  xor	esi,	esi				;
	  mov	ebx,	[edi]
	  mov	eax,	[ebx][esi*4 + 4]; eax = &Arr[0][1] as a starting point

	  mov	ebx,	n				;
	  inc	ebx						;

  _extern:
	  push	ecx						; save 'rows' ecx
	  mov	ecx,	n				; - columns
	  xor	esi,	esi				;
	  dec	ebx						;
	  push	ebx						;
  _intern:
	  pop	ebx						;
	  cmp	ebx,	ecx				;
	  push	ebx						;
	  jz	_gr						;//diagonal
	  mov	ebx,	[edi]			;
	  mov	edx,	[ebx][esi*4]	; edx = &current elem N
	  mov	ebx,	eax				;
	  cmp	ebx,	edx				;	compare N and eax(least) elem
	  js	_gr						; if eax > edx
	  mov	eax,	edx				; 
  _gr:								; else nothing
	  inc	esi						;
	  loop	_intern					;
	  pop	ebx						;
	  pop	ecx						;
	  add	edi,	4				;
	  loop	_extern					;
	  pop	edi						;
	  pop	esi						;

	  mov	ebx,	eax				;
	  mov	result,	ebx				;
  }

  std::cout << "\nThe least element in matrix is " << result << std::endl;
} else 
  {
    std::cout << "No such elements!\n";
  }


  for (int i = 0; i < n; ++i) {
    delete[] arr[i];
  }
  delete[] arr;
  system("pause");
  return 0;
}

/*#include <iostream>

int main() {
  int n{}, result{};
  std::cout << "Enter matrix size (NxN, 1 < N <= 10) " << std::endl;
  while (n <= 0 || n >= 11) 
  {
    std::cin >> n;
  }

  int** arr = new int*[n];
  for (int i = 0; i < n; ++i)
  {
    arr[i] = new int[n];
  }

  std::cout << "Enter array elements: " << std::endl;
  

  for (int i = 0; i < n; ++i) 
  {
    for (int j = 0; j < n; ++j)
	{
      std::cin >> arr[i][j];
	}
  }

  //output matrix
  std::cout << std::endl;
  for (int i = 0; i < n; ++i) 
  {
	for (int j = 0; j < n; ++j) 
	{
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
  if (n > 1) {
  __asm 
  {
    
	  push	esi						;
	  push	edi						;
	  mov	edi,	arr				; edi = &arr
	  xor	eax,	eax				; eax - lowest elem
	  xor	edx,	edx				; edx - compare elem
      mov	ecx,	n				; - rows

	  xor	esi,	esi				;
	  mov	ebx,	[edi]
	  mov	eax,	[ebx][esi*4 + 4]; eax = &Arr[0][1] as a starting point

  _extern:
	  push	ecx						; save 'rows' ecx
	  mov	ecx,	1				; - columns
	  xor	esi,	esi				;
  _intern:
	  ;cmp	ecx,	?				; main diagonal
	  ;je _gr						;
	  mov	ebx,	[edi]			;
	  mov	edx,	[ebx][esi*4]	; edx = &current elem N
	  mov	ebx,	eax				;
	  cmp	ebx,	edx				;	compare N and eax(least) elem
	  js	_gr						; if eax > edx
	  mov	eax,	edx				; 
  _gr:								; else nothing
	  inc	esi						;
	  ;loop	_intern					;
	  inc	ecx						; //alternative loop
	  cmp	ecx,	n				;
	  je	_intern					;
	  pop	ecx						;
	  add	edi,	4				;
	  loop	_extern					;
	  pop	edi						;
	  pop	esi						;

	  mov	ebx,	eax				;
	  mov	result,	ebx				;
  }

  std::cout << "\nThe least element in matrix is " << result << std::endl;
} else 
  {
    std::cout << "No such elements!\n";
  }


  for (int i = 0; i < n; ++i) {
    delete[] arr[i];
  }
  delete[] arr;
  system("pause");
  return 0;
}*/