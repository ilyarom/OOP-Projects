// Flipbyte.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

string dec2binRev(int decNumber) //Преобразует число из 10-ичной системы счистления в 2-ичную. Выходное двоичное число реверсируется, передние нули обрезаются
{
	bool firstNull = true;
	int dividend = decNumber;
	int remainder = 0;
	string reversedBinNumber = "";
	while (true)
	{
		if (dividend == 0 || dividend == 1)
		{
			reversedBinNumber = reversedBinNumber + to_string(dividend);
			break;
		}
		remainder = dividend % 2;
		if (remainder == 1 && firstNull)
		{
			firstNull = false;
		}
		if (!firstNull)
		{
			reversedBinNumber = reversedBinNumber + to_string(remainder);
		}
		dividend = dividend / 2;
	}
	return reversedBinNumber;
}

int bin2dec(string reversedBinNumber) // Переводит число из 2-ичной системы счистления в 10-ичную
{
	int maxDegree = reversedBinNumber.length() - 1;
	int sum = 0;
	int j = 0;
	for (int i = maxDegree; i >= 0; --i)
	{
		if (reversedBinNumber[j] == '1')
		{
			sum = sum + (pow(2, i));
		};
	}
	return sum;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 2)
	{
		cout << "Некорректно введены входные данные, на вход указывается входной байт. Число должно быть от 0 до 2551" << "\n";
		return 1;
	}
	string inputString = argv[1];
	if (inputString.empty())
	{
		cout << "Некорректно введены входные данные, на вход указывается входной байт. Число должно быть от 0 до 2552" << "\n";
		return 1;
	}
	int decNumber = atoi(inputString.c_str());
	if (!(decNumber >= 0 && decNumber <= 255))
	{
		cout << "Некорректно введены входные данные, на вход указывается входной байт. Число должно быть от 0 до 2553" << "\n";
		return 1;
	}
	cin >> decNumber;
	string reversedBinNumber;
	reversedBinNumber = dec2binRev(decNumber);
	cout << reversedBinNumber << "\n";
	decNumber = bin2dec(reversedBinNumber);
	cout << decNumber << "\n";
	return 0;
}


