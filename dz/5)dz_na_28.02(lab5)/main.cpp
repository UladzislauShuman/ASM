#include <iostream>
#include "show.h"
/*
1.Поменять местами максимальный элемент целочисленного массива и последний.

2.Найти сумму цифр целого числа.
Подсчитать количество четных цифр. 
Определить,является ли число симметричным. 

3. Дробь задается целым числителем и натуральным знаменателем. Сократить ее
*/

/*
1*.Строка представляет собой слова, разделенные пробелами. Найти длину самого короткого
слова

2*.Стока представляет собой слова, разделенные пробелами. Определить вхождение
заданного слова в строку.

3*.Для матрицы из 0 и 1 - найти строку и столбец с максимальным количеством подряд 
идущих единиц
*/

//1
extern "C" void _stdcall maxElementChangeWithLast(int* arr, int n);
//2
extern "C" int _stdcall sumOfNumbersInNum( int n, int& amountOfCzitnye);
extern "C" bool _stdcall isSimmetrical(int n);
//3
extern "C" void _stdcall reduceFraction(int& a, int& b);

//1*
extern "C" int _stdcall sizeOfSmallestWord(char* str, int sizeOfStr);
//2*
extern "C" bool _stdcall isWordHere(char* str,int sizeOfStr, char* word, int sizeOfWord);
//3*
extern "C" int _stdcall MaxAmountOfOneInLine(int* arr, int line, int height, int& amountIn);
extern "C" int _stdcall MaxAmountOfOneInColumn(int* arr, int line, int height, int& amountIn);

int main()
{
	int n = 15;
	int* arr = new int[n] {1, 2, 3, 4, 15, -4, 8, 9, 1, 1, -5, 10, 0, 0, 0};
	
	std::cout << "zad 1:\n";
	show(arr, n);
	maxElementChangeWithLast(arr, n);
	show(arr, n);
	
	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

	std::cout << "zad 2:\n";
	int n1 = 12321; // 9
	int chiotnye1 = 0;
	std::cout << "n1 = " << n1 << std::endl;
	std::cout << "sumOfNumbersInNum(n1) = " << sumOfNumbersInNum(n1,chiotnye1) << std::endl;
	std::cout << "isSimmetrical(n1) = " << isSimmetrical(n1) << std::endl;
	std::cout << "chiotnye = " << chiotnye1 << std::endl;
	
	std::cout << "-------------------------\nlets try smth else\n-------------------------\n";

	int n2 = 21345; //15
	int chiotnye2 = 0;
	std::cout << "n2 = " << n2 << std::endl;
	std::cout << "sumOfNumbersInNum(n2) = " << sumOfNumbersInNum(n2,chiotnye2) << std::endl;
	std::cout << "isSimmetrical(n2) = " << isSimmetrical(n2) << std::endl;
	std::cout << "chiotnye = " << chiotnye2 << std::endl;

	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

	std::cout << "zad 3:\n";
	int a = 9; int b = 6;
	std::cout << "a = " << a << " , b = " << b << std::endl;
	std::cout << a << " / " << b << " = ";
	reduceFraction(a, b);
	std::cout << a << " / " << b << std::endl;
	
	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

	std::cout << "zad 1*:\n";
	
	char str[] = "mama pop less housemusic";
	int sizeOfstr = 24;
	std::cout << "str = ";
	show(str, sizeOfstr);
	std::cout << "sizeOfSmallestWord(str,sizeOfstr) = " << sizeOfSmallestWord(str,sizeOfstr) << "\n";
	std::cout << "-------------------------\nlets try smth else\n-------------------------\n";
	
	char str1[] = "Perekis";
	sizeOfstr = 7;
	std::cout << "str1 = ";
	show(str1, sizeOfstr);
	std::cout << "sizeOfSmallestWord(str1,sizeOfstr) = " << sizeOfSmallestWord(str1, sizeOfstr) << "\n";
	std::cout << "-------------------------\nlets try smth else\n-------------------------\n";
	
	char str2[] = "Per pop shy";
	sizeOfstr = 11;
	std::cout << "str2 = ";
	show(str2, sizeOfstr);
	std::cout << "sizeOfSmallestWord(str2,sizeOfstr) = " << sizeOfSmallestWord(str2, sizeOfstr) << "\n";
	
	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

	std::cout << "zad 2*:\n";
	
	char _str[] = " nuty i da ";
	char _word[] = "da";
	bool result = isWordHere(_str,11, _word, 2);
	std::cout << "result = " << result << std::endl;

	char _word1[] = "nuty";
	bool result1 = isWordHere(_str, 11, _word1, 4);
	std::cout << "result1 = " << result1 << std::endl;
	
	char _word2[] = "nu";
	result = isWordHere(_str, 11, _word2, 2);
	std::cout << "result2 = " << result << std::endl;

	char _word3[] = "aga";
	result = isWordHere(_str, 11, _word3, 3);
	std::cout << "result3 = " << result << std::endl;

	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

	std::cout << "zad 3*:\n";
	//              line
	int matrx[] = { 0,1,1,1,
				    1,1,0,0,   // height
				    0,1,0,0 };
	int line = 4;
	int height = 3;
	int index{};
	int ans{};
	std::cout << "in line: " << std::endl;
	index = MaxAmountOfOneInLine(matrx, line, height,ans);
	std::cout << "ans = " << ans << ", index = " << index << std::endl;
	
	std::cout << "in Column: " << std::endl;
	index = MaxAmountOfOneInColumn(matrx, line, height,ans);
	std::cout << "ans = " << ans << ", index = " << index << std::endl;

	return 0;
}