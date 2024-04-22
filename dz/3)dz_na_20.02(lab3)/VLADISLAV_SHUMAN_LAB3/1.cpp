/*
1. Даны два натуральных числа a и n, выяснить является ли число a, числом
равным возведению некоторого другого числа в степень равную n.

a=27, n=3==> 27 = 3 в степени 3
a=16, n=4==> 16 = 2 в степени 4
a=27, n=4==> без вариантов

осталось: обратотать момент, когда нельзя найти 
*/
#include <iostream>

int main()
{
    int a; int n;
    std::cout << "zad1\na = "; std::cin >> a;
    std::cout << "n = "; std::cin >> n;

    int ans{-1};
    int count{};

    _asm {
    
    mov ebx, a;
    cmp ebx,1
        je endAllAnother
        jne beginLoopA
    
    beginLoopA:
        mov eax, a;
        
        beginB:
        cdq
        idiv ebx;
        add count, 1

        proverkaEAX:
            cmp eax,1
                jl izmenaEBXandCount //т.е. 0, то идём по новой
                je proverkaEDX // а что у нас в остатке?
                jg proverkaEDXandBeginB //надо ещё раз поделить

                proverkaEDXandBeginB:
                    cmp edx,0
                        je beginB
                        jne izmenaEBXandCount

                izmenaEBXandCount:
                    dec ebx
                    cmp ebx,1
                        je endAll
                    mov count,0
                    jmp beginLoopA
                    
                proverkaEDX:
                    cmp edx,0
                        je proverkaCount //если и с edx всё чисто,то что с count?
                        jne izmenaEBXandCount //если там он не пуст, то надо по новой 

                proverkaCount:
                    mov ecx,count
                    cmp ecx,n
                        je endAll //ура, мы нашли
                        jne izmenaEBXandCount //нашли, но не то которое надо

    endAllAnother:
        mov ebx,-1
        jmp endAll

    endAll:
        mov ans,ebx

    
    }
    if (ans == 1) {
        std::cout << "sorry, we have not found " << std::endl;
        return 0;
    }
   
    if (ans == -1) {
        std::cout << "ans = " << 1;
        return 0;
    }
    
    std::cout << "ans = " << ans;
    return 0;
}

