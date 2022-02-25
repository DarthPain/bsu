.486
.model flat


PUBLIC _p1, _p2@8, @p3@8

.code
jmp _abs_end


_p1 PROC

	  push	ebp						;
	  mov	ebp,	esp				; PROLOG


	  push	esi						;
	  push	edi						;
	  mov	edi,	[ebp+8]			; edi = &arr
	  xor	eax,	eax				; eax - lowest elem
	  xor	edx,	edx				; edx - compare elem
      mov   ecx,	[ebp+12]		; - rows

	  xor	esi,	esi				;
	  mov	ebx,	[edi]
	  mov	eax,	[ebx][esi*4 + 4]; eax = &Arr[0][1] as a starting point

	  mov	ebx,	[ebp+12]		;
	  inc	ebx						;

  _extern1:
	  push	ecx						; save 'rows' ecx
	  mov	ecx,	[ebp+12]		; - columns
	  xor	esi,	esi				;
	  dec	ebx						;
	  push	ebx						;
  _intern1:
	  pop	ebx						;
	  cmp	ebx,	ecx				;
	  push	ebx						;
	  jz	_gr1						;  // diagonal
	  mov	ebx,	[edi]			;
	  mov	edx,	[ebx][esi*4]	; edx = &current elem N
	  mov	ebx,	eax				;
	  cmp	ebx,	edx				;	compare N and eax(least) elem
	  js	_gr1						; if eax > edx
	  mov	eax,	edx				; 
  _gr1:								; else nothing
	  inc	esi						;
	  loop	_intern1					;
	  pop	ebx						;
	  pop	ecx						;
	  add	edi,	4				;
	  loop	_extern1					;
	  pop	edi						;
	  pop	esi						;


	  pop	ebp						;EPILOG
	  RET							;

_p1 ENDP



_p2@8 PROC

	  push	ebp						;
	  mov	ebp,	esp				; PROLOG


	  push	esi						;
	  push	edi						;
	  mov	edi,	[ebp+8]			; edi = &arr
	  xor	eax,	eax				; eax - lowest elem
	  xor	edx,	edx				; edx - compare elem
      mov   ecx,	[ebp+12]		; - rows

	  xor	esi,	esi				;
	  mov	ebx,	[edi]
	  mov	eax,	[ebx][esi*4 + 4]; eax = &Arr[0][1] as a starting point

	  mov	ebx,	[ebp+12]		;
	  inc	ebx						;

  _extern2:
	  push	ecx						; save 'rows' ecx
	  mov	ecx,	[ebp+12]		; - columns
	  xor	esi,	esi				;
	  dec	ebx						;
	  push	ebx						;
  _intern2:
	  pop	ebx						;
	  cmp	ebx,	ecx				;
	  push	ebx						;
	  jz	_gr2						;  // diagonal
	  mov	ebx,	[edi]			;
	  mov	edx,	[ebx][esi*4]	; edx = &current elem N
	  mov	ebx,	eax				;
	  cmp	ebx,	edx				;	compare N and eax(least) elem
	  js	_gr2						; if eax > edx
	  mov	eax,	edx				; 
  _gr2:								; else nothing
	  inc	esi						;
	  loop	_intern2					;
	  pop	ebx						;
	  pop	ecx						;
	  add	edi,	4				;
	  loop	_extern2					;
	  pop	edi						;
	  pop	esi						;

	  pop	ebp						;EPILOG
	  RET	8						;

_p2@8 ENDP





@p3@8 PROC
		
	  local	arr:dword
	  local	n:dword
	  mov	arr,	ecx
	  mov	n,		edx

	  push	esi						;
	  push	edi						;
	  mov	edi,	arr				; edi = &arr
	  xor	eax,	eax				; eax - lowest elem
	  xor	edx,	edx				; edx - compare elem
      mov   ecx,	n				; - rows

	  xor	esi,	esi				;
	  mov	ebx,	[edi]
	  mov	eax,	[ebx][esi*4 + 4]; eax = &Arr[0][1] as a starting point

	  mov	ebx,	n				;
	  inc	ebx						;

  _extern3:
	  push	ecx						; save 'rows' ecx
	  mov	ecx,	n				; - columns
	  xor	esi,	esi				;
	  dec	ebx						;
	  push	ebx						;
  _intern3:
	  pop	ebx						;
	  cmp	ebx,	ecx				;
	  push	ebx						;
	  jz	_gr3						;  // diagonal
	  mov	ebx,	[edi]			;
	  mov	edx,	[ebx][esi*4]	; edx = &current elem N
	  mov	ebx,	eax				;
	  cmp	ebx,	edx				;	compare N and eax(least) elem
	  js	_gr3						; if eax > edx
	  mov	eax,	edx				; 
  _gr3:								; else nothing
	  inc	esi						;
	  loop	_intern3					;
	  pop	ebx						;
	  pop	ecx						;
	  add	edi,	4				;
	  loop	_extern3					;
	  pop	edi						;
	  pop	esi						;
	  RET



@p3@8 ENDP





_abs_end:
end