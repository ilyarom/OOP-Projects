// FindText.cpp: определяет точку входа для консольного приложения.
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
		cout << "Некорректно введены входные данные, сначала указывается имя файла, далее через пробел строка, которую нужно найти" << "\n";
		return 1;
	}
	ifstream file(argv[1]);
	if (!file.good())
	{
		cout << "Некорректно введены входные данные, сначала указывается имя файла, далее через пробел строка, которую нужно найти" << "\n";
		return 1;
	}
	string strToFind = string(argv[2]);
	if (strToFind.length() == 0)
	{
		cout << "Некорректно введены входные данные, сначала указывается имя файла, далее через пробел строка, которую нужно найти" << "\n";
		return 1;
	}
	int i = 0;
	bool strFinded = false;
	int currentLine = 1;
	string line;
	while (getline(file, line))
	{
		for (int j = 0; j < line.length(); ++j)
		{
			if (line[j] == strToFind[i])
			{
				++i;
				if (i == strToFind.length())
				{
					cout << currentLine << "\n";
					strFinded = true;
				}
			}
			else
			{
				i = 0;
			}
		}
		++currentLine;
		i = 0;
	}
	if (!strFinded)
	{
		cout << "Text not found" << "\n";
		return 1;
	}
	return 0;
}

