.586
.model flat

public _sumOfNumbersInNum@8

.data
	temp dd 0
	count dd 0
	two dd 2
.code

_sumOfNumbersInNum@8 proc
		mov eax, [esp+4]
		mov ebx, 10
		mov ecx, 0
		mov count, 0
		mov temp, 0
	begin:
		cmp eax, 0
			jz _end
			cdq
			idiv ebx
			add ecx, edx

			mov temp, eax
			mov eax, edx
			
			cdq
			idiv two
			mov eax, temp
			cmp edx, 0
				jz chotnoe
				jnz begin

			chotnoe:
				add count,1
				jmp begin
	_end:
		mov eax,ecx
		xor ecx,ecx
		mov ecx, [esp+8]
		mov ebx,count
		mov [ecx],ebx
		
ret 8
_sumOfNumbersInNum@8 endp

end