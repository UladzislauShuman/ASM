/*
3. Сформировать массив из 15 целых чисел. 
Поменять местами первый и
минимальный элементы.
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
		mov edx,0 // i
		mov ecx,amount 
		lea edi,A
		mov eax,[edi][edx * 4] //min
		mov ebx,0 // index of min

		repeat:
			cmp eax, [edi][edx * 4]
				jle continue_
				mov eax,[edi][edx*4]
				mov ebx,edx
		continue_:
			inc edx
		loop repeat

		mov ecx,[edi][0]
		mov [edi][0],eax
		mov [edi][ebx * 4],ecx
	}

	showArray(amount, A);
	return 0;
}