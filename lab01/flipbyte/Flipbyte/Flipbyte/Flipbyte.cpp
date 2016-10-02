// Flipbyte.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
 
size_t CountIterations(int number)
{
	int i = 0;
	while (number != 0)
	{
		number = number >> 1;
		++i;
	}
	return i;
}

int Reverse(size_t i, int number)
{
	int j = 7;
	int resNumber = 0;
	while (i > 0)
	{
		if (number % 2 == 1)
		{
			resNumber = resNumber + (1 << j);
		}
		number = (number >> 1);
		--i;
		--j;
	}
	return resNumber;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 2)
	{
		cout << "Некорректно введены входные данные, на вход указывается входной байт" << "\n";
		return 1;
	}
	string inputString = argv[1];
	if (inputString.empty())
	{
		cout << "Пустой ввод. На вход должен указываться входной байт" << "\n";
		return 1;
	}
	int number = atoi(inputString.c_str());
	if (!(number >= 0 && number <= 255) || (inputString != "0" && number == 0))
	{
		cout << "Входные данные должны быть числом от 0 до 255" << "\n";
		return 1;
	}
	int i = CountIterations(number);
	cout << Reverse(i, number) << "\n";
	return 0;
}