#include "show.h"

void show(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void show(char* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i];
	}
	std::cout << std::endl;
}