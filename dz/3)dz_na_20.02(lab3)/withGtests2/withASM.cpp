#include "withASM.h"

int ASMfunction(int n)
{
    std::cout << "zad 3\nn = "; std::cin >> n;

    int ans{};
    _asm {
        Mov eax, n //eax = n
        Mov ebx, 10// ebx = 10
        Mov ecx, ans//

        Begin :
        Cmp eax, 0
            Jz end

            cdq
            Idiv ebx
            Cmp edx, 3
            Jz begin
            Cmp edx, 6
            Jz begin

            Imul ecx, ebx
            Add ecx, edx
            Jmp begin

            End :
        Mov ans, ecx
    }
    // получается число в обратной запяси
    // чтобы эту проблему решить, воспользуемся кодом ранее
    _asm {
        mov eax, ans
        mov ebx, 10
        mov ecx, 0
        Begin1 :
        cmp eax, 0
            jz End1
            imul ecx, ebx
            cdq
            idiv ebx
            add ecx, edx
            jmp Begin1
            End1 :
        mov ans, ecx
    }

    //std::cout << "ans = " << ans;
    return ans;
}
