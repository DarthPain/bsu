.486
.model flat

PUBLIC _task5

.data 
neg1 real8 -1.0
a real8 0.5


.code

_task5 PROC
push ebp
mov ebp,esp

		finit
		mov eax, [ebp + 8]; eax = &x
		fld1 ;  st(1) = 1
		fld qword ptr [eax]; st(0) = x || st(1) = 1

		xor ecx,ecx ; Integer power of X

	_compare:
		fcom st(1)
		fstsw ax
		fwait
		sahf
		jc _less1
		fadd neg1 ; ~ dec x
		inc ecx
		jmp _compare
	_less1:
		fcom neg1
		fstsw ax 
		fwait
		sahf
		jc _lessNeg1
		jmp _end_compare
	_lessNeg1:
		fsub neg1 ; ~ x + 1
		dec ecx
		jmp _compare
	_end_compare:
		 
		 f2xm1   ; st(0) = 2^x - 1 || st(1) = 1
		 fsub neg1  ; st(0) = 2^x || st(1) = 1
		 fdiv  ; st(0) = 0.5^x




		 fld1 ; st(0) = 1 || st(1) = 0.5^x
		 cmp ecx, 0
		 jg _int_powerP
		 neg ecx
	_int_powerN:
		 fdiv a
		 loop _int_powerN
		 jmp _res

	_int_powerP:
		fmul a
		loop _int_powerP
 

	_res:
		fmul ; st(0) = 0.5^x

		mov eax, [ebp + 12]; eax = &result
		fst qword ptr [eax]; res = ...
pop ebp
	ret
_task5 ENDP


end