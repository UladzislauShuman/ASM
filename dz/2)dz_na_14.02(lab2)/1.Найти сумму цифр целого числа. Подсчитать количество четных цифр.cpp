/*
1.Найти сумму цифр целого числа. Подсчитать количество четных цифр
*/

#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int ans{};
	int count{};
	int temp{};
	int two{ 2 };

	_asm
	{
		mov eax, n
		mov ebx, 10
		mov ecx, ans
	begin:
		cmp eax, 0
			jz end
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
	end:
		mov ans,ecx
	}

	std::cout << ans<<" "<<count;
	return 0;
}