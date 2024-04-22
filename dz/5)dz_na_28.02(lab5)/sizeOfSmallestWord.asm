.586
.model flat

public _sizeOfSmallestWord@8
.data
	temp dd 0
	probel db '  '
.code 

;extern "C" int _stdcall sizeOfSmallestWord(char* str, int sizeOfStr)
_sizeOfSmallestWord@8 proc

mov temp,0

mov esi, [esp + 4]
mov ecx, dword ptr[esp+8]
mov ebx,[esp+8] ; min length
mov al,' '
cykl:
mov ah,[esi]
cmp ah, al
	jne dalee
sravnenie:
	cmp ebx,temp
		jle _continue
	mov ebx,temp
	
_continue:
	mov temp, 0
	inc esi
	jmp loopCykl

dalee:
	add temp,1
	inc esi

loopCykl:
loop cykl

cmp ebx,temp
	jge end1
	jl end2

end1:
	mov eax,temp
	jmp _end
end2:
	mov eax,ebx
_end:
ret 8
_sizeOfSmallestWord@8 endp

end