/*
2.Дробь задается целым числителем и натуральным знаменателем. Сократить ее.
*/
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    int a, b;
    char slesh;
    std::cout << "a/b" << std::endl;
    std::string line;
    std::getline(std::cin, line);

    std::istringstream lineStream(line);
    lineStream >> a >> slesh >> b;
    
    int nod{};
    _asm
    {
        mov eax,a
        mov ebx,b

        begin:
        cmp edx,0
            jz end

            cdq
            idiv ebx
            mov eax,ebx
            mov ebx,edx

            jmp begin
        end:
            mov nod,eax
    }
    std::cout << a / nod << " / " << b / nod;
    return 0;
}

