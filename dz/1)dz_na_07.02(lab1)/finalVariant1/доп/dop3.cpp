/*
3. Найти номер старшего бита в двоичном представлении целого положи-тельного числа.
*/

#include <iostream> 

int main()
{
    int n;
    std::cout << "n = ";
    std::cin >> n;

    int res = 0;
    int m = n;

    _asm {
        mov edx,0 // xor edx, edx
        mov eax, n // eax = n
        fl1 :
        // fl1
        cmp eax, 1 //eax ? 1
            jg itr // j(if) g(>) ,то itr 
            jle end // j(if) l(<) e(=), то end 
            
            itr :
            // itr
        shr eax, 1 // eax >> 1
            add edx, 1 //edx += 1
            jmp fl1 // goto fl1
            
            end :
            // end
        mov res, edx // res = edx
    }
    std::cout <<"res = " << res << std::endl;

    res -= res;

    while (m != 1) {
        m >>= 1;
        res++;
    }
    std::cout << "proverka = " << res;

    return 0;
}
