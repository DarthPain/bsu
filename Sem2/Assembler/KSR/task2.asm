.486
.model flat

PUBLIC _task2

.data 
a dd ?
b real8 8.0
pi real8 ?
persarr dd ?
trash real8 ?
pers5 real8 0.00001
pers7 real8 0.0000001
pers9 real8 0.000000001

.code

_task2 PROC
push ebp
mov ebp,esp

		finit

		mov edx, [ebp + 8]; edx = &future Pi
		mov ebx, [ebp + 12]
		mov persarr, ebx; persarr = &percision
		mov ecx, 1 ; ebx = K
		fld1
		fldpi
		fmul st(0), st(0)
		fdiv b
		fstp pi
		
	_series:
		inc ecx
		mov ebx, ecx
		add ebx, ebx
		dec ebx
		mov a, ebx
		fld1
		fild a
		fdiv 
		fmul st(0), st(0)
		faddp ;st(0), st(1)
		

		;PERCISION CALCULATION
		fld st(0) ; st(0) = st(1)
		fsub pi
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
		mov ebx, persarr
		mov [ebx], ecx
	_less5:
		mov ebx, persarr
		mov [ebx + 4], ecx
	_less7:
		mov ebx, persarr
		mov [ebx + 8], ecx
	_less9:		
		fstp trash

		cmp ecx, 1000000000
		jb _series

	    mov a, 8
		fild a
		fmul st(0), st(1)
		fsqrt
		fst qword ptr [edx]




		




pop ebp
	ret
_task2 ENDP


end