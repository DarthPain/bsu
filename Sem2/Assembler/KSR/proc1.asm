.486 
.model flat

PUBLIC _proc1, _proc2

.data 
a real8 0.17

.code

; !!!!!!!!!NOT WORKING
jmp _ENDL
_proc1 PROC
;enter 0,0
push ebp
mov ebp,esp

		finit 
		fld a
		mov ebx, [ebp + 8]
		fld qword ptr [ebx]
		fst qword ptr [eax]
		fst qword ptr [eax+8]
		fst qword ptr [eax+16]


;leave
pop ebp
	ret
_proc1 ENDP

jmp _ENDL
_proc2 PROC
push ebp
mov ebp,esp

		mov eax, [ebp + 20]

		finit
		mov ebx, [ebp + 8]
		fld qword ptr [ebx]
		mov ebx, [ebp + 12]
		fld qword ptr [ebx]
		mov ebx, [ebp + 16]
		fld qword ptr [ebx]
		fstp qword ptr [eax]
		fstp qword ptr [eax + 8]
		fstp qword ptr [eax + 16]



pop ebp
	ret

_proc2 ENDP
_ENDL:
end