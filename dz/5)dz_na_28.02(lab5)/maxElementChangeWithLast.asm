.586 ; процессор
.model flat ; модель памяти

public _maxElementChangeWithLast@8

.code 

_maxElementChangeWithLast@8 proc
;ecx = arr , edx = n
mov edi,[esp+4]
mov ecx,[esp+8]
mov edx,0 ; i

mov eax,dword ptr[edi][edx * 4] ;max
mov ebx,0 ; index of max

metka:
	cmp eax, dword ptr[edi][edx * 4]
		jge continue_
	mov eax,dword ptr[edi][edx*4]
	mov ebx,edx
	continue_:
		inc edx
loop metka

	mov ecx,dword ptr[edi][0]
	mov [edi],eax
	mov [edi][ebx * 4], ecx

ret 8
_maxElementChangeWithLast@8 endp

end