.586
.model flat

public _isSimmetrical@4

.code

_isSimmetrical@4 proc

mov eax, [esp+4]
mov ebx, 10
mov ecx, 0
Begin1:
	cmp eax,0
		jz End1
		imul ecx, ebx
		cdq
		idiv ebx
		add ecx, edx
		jmp Begin1
	End1:
		mov eax,ecx
		cmp eax,[esp+4]
			je one1
			jne zero1
		one1:
			mov eax, 1
			jmp endFull
		zero1:
			mov eax,0
		endFull:
ret 4
_isSimmetrical@4 endp

end