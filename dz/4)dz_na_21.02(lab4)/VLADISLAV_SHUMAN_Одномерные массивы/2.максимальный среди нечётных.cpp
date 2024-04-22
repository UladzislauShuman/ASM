/*
2. Сформировать массив из 10 целых чисел. 
Найти максимальный среди элементов с четными индексами.
*/

#include <iostream>
#include <ctime>

int main()
{
	const int amount = 10;
	int A[amount];

	std::srand(std::time(0));
	for (int i = 0; i < amount; ++i)
	{
		A[i] = std::rand() % 100;
		if (i % 2 == 0) {
			std::cout << "    ";
		}
		std::cout << A[i] << std::endl;
	}
	std::cout << std::endl;
	
	int max{};
	_asm
	{
		mov edx, 0
		mov ebx, max
		mov ecx, 0

		lea edi, A

		begin:
			cmp [edi][ecx * 4],ebx
				jle proverka_ecx

			mov ebx, [edi][ecx * 4]
			jmp proverka_ecx
			
		proverka_ecx:
			add ecx,2
			cmp ecx,amount
				jge end
			jmp begin
		end:
			mov max,ebx
	}
	std::cout << "max " << max;
	return 0;
}