/*
1. Ввести целое число n и вывести 2^n, используя битовые операции.
*/

#include <iostream>

int main()
{
	int n;
	std::cout << "n = "; std::cin >> n;
	
	int ans = 1;
	if (n >= 0 and n <= 32)
	{
		_asm
		{
			mov eax, 1;
			mov ecx, n;
			SHL eax, cl;
			mov ans, eax;
		}
		std::cout << "ans = " << ans << std::endl;
	}
	else 
	{
		std::cout << "sorry, i cant";
	}

	return 0;
}
