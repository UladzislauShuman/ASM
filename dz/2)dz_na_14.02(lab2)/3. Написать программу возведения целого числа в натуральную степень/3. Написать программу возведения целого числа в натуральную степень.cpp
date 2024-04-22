/*
3. Написать программу возведения целого числа в натуральную степень.
*/

#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::cout << "a^n" << std::endl;
    int a, n;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream lineStream(line);

    char stepen;
    lineStream >> a >> stepen >> n;

    int ans;
    _asm
    {
        mov eax,1
        mov ebx,n
    begin:
        cmp ebx,0
            jz end
            imul eax, a
            sub ebx,1
            jmp begin
    end:
        mov ans,eax
    }

    std::cout << ans;
    return 0;
}

