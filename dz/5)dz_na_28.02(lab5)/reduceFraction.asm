.586
.model flat

public _reduceFraction@8

.data

	nod dd 0

.code

_reduceFraction@8 proc
mov edi,[esp+4]
mov eax,[edi]
mov edi,[esp+8]
mov ebx,[edi]

begin1:
	cmp edx,0
		jz end1

		cdq
		idiv ebx
		mov eax,ebx
		mov ebx,edx

		jmp begin1
	end1:
		mov nod,eax

		mov edi,[esp+4]
		mov eax,[edi]
		cdq
		idiv nod
		mov [edi],eax

		mov edi,[esp+8]
		mov eax,[edi]
		cdq
		idiv nod
		mov [edi],eax

ret 8
_reduceFraction@8 endp

end