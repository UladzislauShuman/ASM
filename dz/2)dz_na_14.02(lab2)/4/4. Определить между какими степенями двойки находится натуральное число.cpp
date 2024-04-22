/*
4. Определить между какими степенями двойки находится натуральное число
*/
#include <iostream>

int main()
{
    int n;
    std::cout << "n = ";
    std::cin >> n;

    
    int niz{}, last{};
    int temp;
    _asm {
        mov ebx, 0 
        mov eax, n
        fl1 :

        cmp eax, 1
            jg itr
            jle end 

            itr :
        shr eax, 1
            add ebx, 1 
            jmp fl1 

        end :
        mov niz, ebx
        mov last, ebx

        mov eax , 1
        mov ecx, niz
        shl eax , cl
        mov ebx , eax
        mov eax , n

        cdq
        idiv ebx

        cmp edx,0
            jnz konec
            jz endFull
        konec:
            add last , 1
        endFull:
    }
    std::cout << "2^" << niz << " < " << n << " < 2^" << last;
    return 0;
}

