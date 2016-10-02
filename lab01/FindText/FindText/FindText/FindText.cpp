// FindText.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

bool FindLines(ifstream & file, string const & strToFind)
{
	bool strFinded = false;
	int currentLine = 1;
	string line;
	while (getline(file, line))
	{
		if (line.find(strToFind) != string::npos)
		{
			cout << currentLine << "\n";
			strFinded = true;
		}
		++currentLine;
	};
	return strFinded;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 3)
	{
		cout << "Недостаточно аргументов. Формат входных данных: <именование файла> <строка для поиска>" << "\n";
		return 1;
	}
	ifstream file(argv[1]);
	if (!file.is_open())
	{
		cout << "Невозможно открыть файл. Проверьте правильность вводимых данных или убедитесь в наличии данного файла." << "\n";
		return 1;
	}
	string strToFind = argv[2];
	if (strToFind.empty())
	{
		cout << "Задано пустое значение для параметра строки для поиска." << "\n";
		return 1;
	}
	cout << "В данный поток будут выведены номера строк входного файла (1 аргумент), которые содержат искомую для поиска строку (2 аргумент)" << "\n";
	bool strFinded = FindLines(file, strToFind);
	if (!strFinded)
	{
		cout << "Text not found" << "\n";
	}
	return 0;
}

