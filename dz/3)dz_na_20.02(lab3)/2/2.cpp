/*
Найти наибольшую цифру в записи натурального числа.
*/

#include <iostream>

int main()
{
    int n;
    std::cout << "zad 2\nn = "; std::cin >> n;

    int ans{};
    _asm {
        mov eax, n
        mov ebx, 10
        mov ecx, ans

        begin:
            cmp eax,0
                jz end
                
                cdq
                idiv ebx
                cmp ecx,edx
                    jge begin
                    
                    mov ecx,edx
                    jmp begin
        end:
            mov ans, ecx
    }
    std::cout << "ans = " << ans;
    return 0;
}

