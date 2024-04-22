.586
.model flat

public _isWordHere@16
.data
	_str dd 0
	_word dd 0
	temp dd 1

.code 
;isWordHere(char* str,int sizeOfStr, char* word, int sizeOfWord);
_isWordHere@16 proc
mov temp,1

xor eax,eax
xor ebx,ebx
xor esi,esi
xor edi,edi


mov esi, [esp + 4] ;заносим предложение
mov eax, [esp + 8] ;размер предложения
mov _str,eax

mov edi, [esp + 12] ;заносим слово
mov eax, dword ptr[esp + 16] ;размер слова
mov _word,eax

mov eax,_str
cmp eax,_word ; сравниваем размер предложения и слова
	jl _endZero

;делаем счётчик ЕСХ
mov ebx, _str
sub ebx, _word
mov ecx, ebx
inc ecx

xor edx,edx
xor eax,eax



beginProbel:
	mov ah,[esi]
	mov al,' '
	cmp ah,al ; является ли элемент пробелом?
		je proverkaSlowa
	cmp temp,1
		je prygaem
	inc esi
	inc temp
	mov edx,_str
	cmp temp, edx
		jg _endZero
	jmp beginProbel

proverkaSlowa:
	inc esi
	inc temp
	
	prygaem:

	mov edx,_str
	cmp temp, edx
		jg _endZero

	mov ecx, temp
	mov ebx, _str
	sub ebx, ecx
	add ebx,1
	cmp ebx,_word
		jl _endZero
	xor ebx,ebx
	mov edx,0
	mov ecx, _word
	cykl:
		xor ebx,ebx
		mov ebx,[esi][edx*1]
		cmp bl,[edi][edx*1]
			jne konecCykl
		add edx,1
	loop cykl
	jmp _lastCheck
	konecCykl:
		inc esi
		inc temp
		jmp beginProbel

_lastCheck:
	add temp, edx
	dec temp
	mov eax,_str
	cmp temp, eax
		je _endOne
	xor eax,eax
	mov ah,[esi][edx*1]
	mov al,' '
	cmp ah,al 
		je _endOne
_endZero:
	mov eax,0
	jmp _end
_endOne:
	mov eax,1
_end:
mov temp,1
ret 16
_isWordHere@16 endp

end