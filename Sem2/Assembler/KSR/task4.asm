.486
.model flat

PUBLIC _task4

.data 
a real8 ?
twopi real8 ?
x real8 ?
two real8 2.0
trash real8 ?
zero real8 0.0
epsilon real8 0.001

.code

_task4 PROC
push ebp
mov ebp,esp

		finit

		mov edx, [ebp + 8]; edx = &future integral
		fldpi
		fmul two
		fstp twopi
		
		mov eax, 1 ; divisor for [0,2Pi]
		
		shl eax, 1
		mov dword ptr a, eax
		fld twopi
		fild a
		fdivp st(1), st(0) ; step size

		fld twopi ; left to go

		fldz ;  first x entry
		fldz ; current result [0 at first]
		fst x

		
	_this_integral:
		
		fld st(0)
		fld st(0) ; st(0) = st(1) = st(2) =  x
		fcos  ; st(0) = cos(x) || st(1) = x = st(2)
		fmulp ; st(0) = x*cos(x) || st(1) = x
		fxch
		fadd st(0), st(4) ; st(0) = {x += step size}
		; st(0) = current x || st(1) = last x*cos(x)
		fst x
		fld st(0) ; st(0) = st(1) = x
		fst x ; save current x
		fcos  ; st(0) = cos(x) || st(1) = x
		fmulp ; st(0) = x*cos(x) || st() = x*cos(x) [old]
		faddp 
		fdiv two
		fmul st(0), st(3)
		fxch st(2)
		fsub st(0), st(3)
		fcom zero
		fstsw ax
		fwait
		sahf
		jc _next_integral
		jz _next_integral
		fxch st(2)
		faddp st(1),st(0)
		fld x
		jmp _this_integral

	_next_integral:
		fxch st(2)
		faddp st(1), st(0)
		fxch st(3)
		fstp trash
		fld st(2)
		fsub st(0), st(3) ; current result - last result
		fcom epsilon
		fstsw ax
		fwait
		sahf
		fadd st(0), st(3)
		jc _end_integral
		jz _end_integral
		jmp _this_integral

	_end_integral:

		


		












		mov edx, [ebp + 8]
		fst qword ptr [edx]




		




pop ebp
	ret
_task4 ENDP


end