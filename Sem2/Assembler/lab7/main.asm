.386
public @spacecutter@8
.model flat
.code
@spacecutter@8 PROC
	  cld
	lea edi, [edx]
	mov ax,  '  '
	push ecx
_loop:
	pop ecx
	repne scasw
	push ecx
	jne _exito

	push ecx
	push esi
	push edi
	dec edi
	dec edi
	mov esi, edi
	inc esi
	rep movsb
	pop edi
	pop esi 
	pop ecx	
	pop ecx
	inc ecx
	push ecx
	dec edi
	dec edi
	dec edi


	jmp _loop

_exito:
	pop ecx
	RET
@spacecutter@8 ENDP

end