/*
1. Вычислить значение выражения а^5+а^3+а для числа а, вводимого с консоли.
*/
#include <iostream>


int main()
{
	int a;
	std::cout << "a = "; std::cin >> a;
	
	int result = 0;
	_asm 
	{
		mov eax, a;
		
		mul eax; //a^2
		mul eax; //a^4
		mul a;	 //a^5

		mov ecx, eax;
		
		mov eax, a;
		mul eax;
		mul a;

		add ecx, eax;
		add ecx, a;
		mov result, ecx;

	}

	std::cout << "result = " << result << std::endl;
	std::cout << "proverka: " << std::pow(a, 5) + std::pow(a, 3) + a;

	return 0;
}