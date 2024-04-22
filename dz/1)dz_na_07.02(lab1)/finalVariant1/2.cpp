/*
2. Вычислить значение выражения (а4-2)/(а-4).
*/
#include <iostream>

int main()
{
    int a, result;
    std::cout << "a = "; std::cin >> a;

    _asm
    {
        mov eax, a;

        mul eax;
        mul eax;
        sub eax, 2;

        mov ecx, eax;
        
        mov eax, a;
        sub eax, 4;

        mov ebx, eax;
        mov eax, ecx;

        cdq;
        idiv ebx;

        mov result, eax;
    }

    std::cout << "result = " << result << std::endl;
    std::cout << "proverka: " << (std::pow(a, 4) - 2) / (a - 4);
    return 0;
}

