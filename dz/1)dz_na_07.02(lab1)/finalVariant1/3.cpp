/*
3. Найти целочисленное решение уравнения ах+b=0 , если оно существует.
*/
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    int a, b;
    int result1;
    int result2;
    std::string line;
    std::cout << "write your Ax + B = 0\n(in the same view)\n";
    std::getline(std::cin, line);
  
    std::istringstream lineStream(line);
    lineStream >> a;

    char znak;
    lineStream >> znak;
    lineStream >> znak;
   
    lineStream >> b;

    if (znak == '-') { b *= -1; }

    if (a != 0 and b != 0)
    {
        std::cout << "you have a solution of equation: ";
        int znakInt =-( b / abs(b));
        b = abs(b);
        _asm
        {
            mov eax, b;
            
            cdq
            idiv a;  
            
            mov result1, eax;
            mov result2, edx;
        }
        std::cout << znakInt*(result1+(double)result2/a) << std::endl;
        std::cout << "proverka: " << (double)(-b) / a;
    }
    else 
    {
        if (a == 0 and b == 0)
        {
            std::cout << "infinity solutions";
        }
        else
        {
            if (a == 0 and b != 0)
            {
                std::cout << "no solutions";
            }
        }
    }
    
    
    return 0;
}
