// rle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 3)
	{
		cout << "Недостаточно аргументов. Формат входных данных: <исходная строка> <режим>" << "\n";
		return 1;
	}
	string inputString = argv[1];
	string mode = argv[2];
	if (inputString.empty() || mode.empty())
	{
		cout << "Неверно введены входные данные. Формат входных данных: <исходная строка> <режим>" << "\n";
		return 1;
	}
	int lenSameSymbols = 1;
	if (mode == "pack")
	{
		for (int i = 0; i < inputString.length(); ++i)
		{
			if (inputString[i] == inputString[i + 1])
			{
				lenSameSymbols = lenSameSymbols + 1;
			}
			else
			{
				cout << lenSameSymbols << ",'" << inputString[i] << "',";
				lenSameSymbols = 1;
			};
		}
	}
	else if (mode == "unpack")
	{
		bool SymbolMode = false;
		bool NumberMode = true;
		bool SymbolReaded = false;
		string AssemblyString = "";
		int decNumber;
		for (int i = 0; i < inputString.length(); ++i)
		{
			SymbolReaded = false;
			if (inputString[i] == ',' || i == inputString.length() - 1)
			{
				if (i == inputString.length() - 1)
				{
					AssemblyString = AssemblyString + inputString[i];
				}
				SymbolReaded = true;
				if (NumberMode)
				{
					SymbolMode = true;
					NumberMode = false;
					decNumber = atoi(AssemblyString.c_str());
					if (decNumber == 0)
					{
						cout << "Неверно указано число в последовательности символов" << "\n";
						return 1;
					}
					AssemblyString = "";
				}
				else
				{
					NumberMode = true;
					SymbolMode = false;
					if ((AssemblyString.length() == 3) && (AssemblyString[0] == '\'') && (AssemblyString[2] == '\''))
					{
						for (int j = 0; j < decNumber; ++j)
						{
							cout << AssemblyString[1];
						}
					}
					else
					{
						cout << "При указании символа ожидается один символ." << "\n";
						return 1;
					}
				}
				AssemblyString = "";
			}
			if (!SymbolReaded)
			{
				AssemblyString = AssemblyString + inputString[i];
			}
		}
	}
	else
	{
		cout << "Неверно указан режим. Режим может принимать значения pack и unpack" << "\n";
		return 1;
	}
    return 0;
}

