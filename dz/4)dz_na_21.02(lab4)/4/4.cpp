/*
4. В заданном массиве найти максимальный элемент.
Элементы, стоящие после
максимального элемента заменить нулями.
*/
#include <iostream>
#include <ctime>

void showArray(const int& amount, int* array)
{
	for (int i = 0; i < amount; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}
int main()
{
	const int amount = 15;
	int A[amount];

	std::srand(std::time(0));
	for (int i = 0; i < amount; ++i)
	{
		A[i] = std::rand() % 20;
	}

	showArray(amount, A);

	_asm
	{
		mov ecx,amount
		mov edx,0//i
		mov ebx,0//index
		lea edi,A
		mov eax,[edi][0]

		repeat:
			cmp eax,[edi][edx*4]
				jg continue_

			mov eax, [edi][edx * 4]
			mov ebx,edx
		continue_:
			inc edx
		loop repeat
		
		mov edx,ebx
		inc edx
		
		begin:
			cmp edx,amount
				jge end
			mov [edi][edx*4],0
			inc edx
			jmp begin
		end:
		
	}

	showArray(amount, A);
	return 0;
}