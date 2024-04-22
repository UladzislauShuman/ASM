/*
2. Найти количество единиц в двоичном представлении целого положитель-ного числа.
*/
#include <iostream> 

int main()
{
    int n;
    std::cout << "n = ";
    std::cin >> n;

    int m{n};
    int res{};

    _asm {
        mov eax, n // eax = n
        mov edx, 0 // edx = 0

        fl1:
        // fl1
        cmp eax, 0 // сравнивается eax и 0
            jg itr // j(if) g(>) , смешаемся на itr
            jz end // j(if) z(0) , смешаемся на end
            itr :
        // jtr
        mov ebx, eax
            and ebx, 1 // ebx &= 1
            cmp ebx, 1 // сравниваем ebx и 1
                jz fl2 // j(if) z(0) , смешаемся на fl2

            back :
        // back
        shr eax, 1 // eax >> 1
            jmp fl1 // goto fl1

            fl2 :
        //fl2
        add edx, 1 //edx += 1
            jmp back //goto back

            end :
        // end 
        mov res, edx // res = edx
    }
    std::cout << "res = " << res << std::endl;

    res = 0;
    while (m > 0)
    {
        if (m % 2)
        {
            res++;
        }
        m /= 2;
    }

    std::cout << "proverka = " << res;
    return 0;
}


