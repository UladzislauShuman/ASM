/*
4. Даны значения двух моментов времени, 
принадлежащих одним и тем же суткам:
часы, минуты и секунды для каждого из моментов времени. 

Известно, что второй момент времени наступил не раньше первого.
Определите, сколько секунд прошло между двумя моментами времени.

Программа на вход получает три целых числа — часы, минуты, секунды, 
задающие первый момент времени и три целых числа, 
задающих второй момент времени.

Выведите число секунд между этими моментами времени.
*/
#include <iostream>

int main()
{
	int hour1 = 1, minut1 = 57, second1 = 46; //01:57:46
	int hour2 = 2, minut2 = 0, second2 = 40;  //02:00:40
	int result;
	//int proverkaH, proverkaM;
	_asm
	{
		mov eax, hour2;
		sub eax, hour1;
		imul eax, eax, 3600;
		//mov proverkaH, eax;

		mov ecx, eax;
		mov eax, minut2;
		sub eax, minut1;
		imul eax, eax, 60;
		//mov proverkaM, eax;
		add ecx, eax;

		add ecx, second2;
		sub ecx, second1;

		mov result, ecx;
	}
	//std::cout << proverkaH << " " << proverkaM << std::endl;
	std::cout << "result: " << result << std::endl;
	std::cout << "proverka: " << (hour2 - hour1) * 3600 + (minut2 - minut1) * 60 + second2 - second1;

	return 0;
}