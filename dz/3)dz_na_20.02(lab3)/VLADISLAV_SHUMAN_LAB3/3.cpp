/*
Пользователь вводит любое целое число. 
Необходимо из этого целого числа удалить
все цифры 3 и 6 и вывести обратно на экран
*/

#include <iostream>

int main()
{
    int n;
    std::cout << "zad 3\nn = "; std::cin >> n;
    int countOfZero{};
    int ans{};
    
    _asm {
        Mov eax, n //eax = n
        Mov ebx, 10// ebx = 10
        Mov ecx, ans//

        beginZeroOnStart:
            Cmp eax, 0
                Je End
            cdq
            Idiv ebx
            Cmp edx, 0
                Jne EndZeroOnStart
            inc countOfZero
            jmp beginZeroOnStart 
        EndZeroOnStart:
            mov eax,n
        
        Begin :
        Cmp eax, 0
            Jz End

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
        //добавляю нули в конец
        mov ans, ecx
        
        mov ecx, countOfZero
        mov eax,1

        beginLast:
            cmp ecx,0
                je endLast
            mul ebx
            add ecx, -1
            jmp beginLast
        endLast:
        imul eax,ans
        mov ans,eax
    }

    std::cout << "ans = " << ans;
   
    return 0;
}

