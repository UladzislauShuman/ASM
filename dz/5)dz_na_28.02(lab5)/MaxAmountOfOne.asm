;extern "C" int _stdcall MaxAmountOfOne(int* arr, int line, int height);
.586
.model flat

public _MaxAmountOfOneInLine@16
public _MaxAmountOfOneInColumn@16

.data
	_line dd 0
	_height dd 0
	max dd 0
	_zero dd 0
	_size dd 0

	numberOfLine dd 0
	index dd 0

	indexLine dd 0
	indexColumn dd 0
	currentAmount dd 0
	numberOfColumn dd 0
.code


_MaxAmountOfOneInLine@16 proc
mov max,0
mov numberOfLine,0
mov index,-1
;заношу данные 
mov esi,dword ptr[esp+4]

mov eax,[esp+8]
mov _line,eax

mov eax,[esp+12]
mov _height,eax

mov _size,eax
mov eax,_line
imul eax,_size
mov _size,eax
xor eax,eax

; [esi][heightIndex*_line + lineIndex] - как буду обращаться к элементам
mov ebx,0
beginStroka:

	mov eax,index
	inc eax
	mov index,eax

	mov edx,0
	mov ecx,0
	edinichki:
		mov edx,[esi][ebx*4]
		cmp edx, 0
			jz dalee
		inc ecx
		dalee:
		inc ebx
		
		mov eax,ebx
		cdq
		idiv _line
		cmp edx,0
			je endEdinichki
		jmp edinichki
	endEdinichki:
		cmp ecx,max
			jl dalee2 ; ecx < max?
		mov max,ecx
		mov eax,index
		mov numberOfLine,eax

		dalee2:
		cmp ebx,_size
			je endStroka
		jmp beginStroka
endStroka:
	mov eax,numberOfLine
	mov ecx, [esp + 16]
	mov ebx,max
	mov [ecx], ebx

ret 16
_MaxAmountOfOneInLine@16 endp

_MaxAmountOfOneInColumn@16 proc
mov indexLine, 0
mov max, 0
mov numberOfColumn, 0

mov esi,dword ptr[esp+4]

mov eax,[esp+8]
mov _line,eax

mov eax,[esp+12]
mov _height,eax

mov _size,eax
mov eax,_line
imul eax,_size
mov _size,eax
xor eax,eax

;проверка будет такая
;line -- количество столбцов
;т.е. -- будет индекс, что варируется
; от 0 до line - 1
; чтобы идти по столбцу, нам надо прибовлять на 4

; [esi][indexLine + 0*line]
begin_zero_to_line:
	mov eax, indexLine
	cmp eax, _line
		je end_zero_to_line
	
	mov indexColumn, 0
	xor ecx,ecx
	begin_current_column:
		xor edx,edx
		mov edx, indexColumn
		imul edx, _line
		add edx, indexLine
		
		mov ebx, [esi][edx*4]
		cmp ebx,0
			je dalee
		inc ecx
		dalee:

		mov eax,indexColumn 
		inc eax
		mov indexColumn,eax

		cmp eax,_height
			je end_current_column
		jmp begin_current_column

	end_current_column:
		cmp ecx,max
			jl dalee2
		mov max,ecx
		
		mov eax,indexLine
		mov numberOfColumn,eax
		
		dalee2:
		mov eax,IndexLine
		inc eax
		mov IndexLine, eax
		jmp begin_zero_to_line

end_zero_to_line:
	mov eax, numberOfColumn
	mov ecx, [esp + 16]
	mov ebx,max
	mov [ecx], ebx

ret 16
_MaxAmountOfOneInColumn@16 endp

end