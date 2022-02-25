.486
.model flat

PUBLIC _task3

.data 
a dd ?
b real8 1.0
four real8 4.0
ln2 real8 ?
persarr dd ?
trash real8 ?
pers5 real8 0.00001
pers7 real8 0.0000001
pers9 real8 0.000000001

.code

_task3 PROC
push ebp
mov ebp,esp

		finit

		mov edx, [ebp + 8]; edx = &future Ln2
		mov eax, [ebp + 12]
		mov persarr, eax; persarr = &percision
		xor ecx, ecx ; ecx = K
		fldln2
		fadd st(0), st(0)
		fsub b
		fstp ln2
		fldz
		
	_series:
		inc ecx
		mov a, ecx
		fld1
		fild a
		fld st(0); st(0) = st(1) = k{ecx}
		fmul st(0),st(1)
		fmul st(0),st(1)
		fmul four
		fsubrp
		fdiv 
		faddp ; st(0), st(1)
		

		;PERCISION CALCULATION
		fld st(0) ; st(0) = st(1)
		fsub ln2
		fabs
		fcom pers9
		fstsw ax
		fwait
		sahf
		jc _less9
		fcom pers7
		fstsw ax
		fwait
		sahf
		jc _less7
		fcom pers5
		fstsw ax
		fwait
		sahf
		jc _less5
		mov eax, persarr
		mov [eax], ecx
	_less5:
		mov eax, persarr
		mov [eax + 4], ecx
	_less7:
		mov eax, persarr
		mov [eax + 8], ecx
	_less9:		
		fstp trash

		cmp ecx, 100000000
		jb _series

		fadd b
	    mov a, 2
		fild a
		fdiv
		mov edx, [ebp + 8]
		fst qword ptr [edx]




		




pop ebp
	ret
_task3 ENDP


end