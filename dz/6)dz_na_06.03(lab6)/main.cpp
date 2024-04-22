#include <iostream>
#include <cmath>
extern "C" float* _fastcall zad1(float* x, float* y);
extern "C" float* _fastcall zad2(float* x, float* y);
extern "C" float* _fastcall zad3(float* x, float* y);

extern "C" float* _fastcall Z1(int n, float* delta);
extern "C" float* _fastcall Z2(int n, float* delta);
int main()
{
	const float pi = 3.14159;
	float x = 0.5, y = -0.75;
	
	float result{};
	std::cout << "zad1\n";
	std::cout << "C++ = " << x * x * tan(x / y) + y * y * (1 / tan(x / y)) << std::endl;
	std::cout << "ASM = " << * zad1(&x, &y) << std::endl;
	
	std::cout << "\nzad2\n";
	std::cout << "C++ = " << (x*y + y*log(x)/log(2))/atan(x/y) << std::endl;
	std::cout << "ASM = " << *zad2(&x, &y) << std::endl;

	std::cout << "\nzad3\n";
	std::cout << "C++ = " << (abs(x-y))*(cos((x/y)+(y/x))) << std::endl;
	std::cout << "ASM = " << *zad3(&x, &y) << std::endl;

	float delta{};
	float* ptrDelta = &delta;
	int n;
	float* resPtr = nullptr;

	std::cout << "z1)(ln2) n = ";
	std::cin >> n;
	_asm
	{
		xor ecx,ecx
		xor edx,edx
		mov ecx, n
		mov edx, ptrDelta
		call Z1
		mov resPtr, eax
		
	}
	std::cout << "ans = " << *resPtr << ", delta = " << delta << std::endl;
	std::cout << "C++: " << std::log(2) << std::endl;

	std::cout << "z2)(integral) n = ";
	std::cin >> n;
	float* resPtr1 = nullptr;
	float ans{};
	_asm
	{
		xor ecx,ecx
		xor edx,edx
		mov ecx, n
		mov edx, ptrDelta
		call Z2
		mov resPtr1, eax
	}
	std::cout << "ans = " << *resPtr1 << ", delta = " << delta << std::endl;
	std::cout << "C++: " << pow(2 * pi, 3) / 3 << std::endl;


	

	return 0;
}