/*
1. Сформировать массив из 15 целых чисел. 
Найти среднее арифметическое положительных элементов.
*/
#include <iostream>
#include <ctime>

int main()
{
	const int amount = 15;
	int A[amount];

	std::srand(std::time(0));
	for (int i = 0; i < amount; ++i)
	{
		A[i] = std::rand() % 20 - 10;
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	int ans{};
	_asm
	{
		mov edx,0 // i = 0
		mov ecx,amount // for loop
		
		mov eax,0 // sum
		mov ebx,0 // количество положительных целых чисел

		lea edi,A

		repeat:
			cmp [edi][edx * 4], 0
				jl continue_

				add eax, [edi][edx * 4]
				inc ebx
			continue_:
				inc edx
		loop repeat
			cdq
			idiv ebx
			mov ans, eax;

	}
	std::cout << ans << std::endl;
	return 0;
}