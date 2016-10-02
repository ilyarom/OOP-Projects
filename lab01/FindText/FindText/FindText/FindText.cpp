// FindText.cpp: ���������� ����� ����� ��� ����������� ����������.
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
		cout << "������������ ����������. ������ ������� ������: <���������� �����> <������ ��� ������>" << "\n";
		return 1;
	}
	ifstream file(argv[1]);
	if (!file.is_open())
	{
		cout << "���������� ������� ����. ��������� ������������ �������� ������ ��� ��������� � ������� ������� �����." << "\n";
		return 1;
	}
	string strToFind = argv[2];
	if (strToFind.empty())
	{
		cout << "������ ������ �������� ��� ��������� ������ ��� ������." << "\n";
		return 1;
	}
	cout << "� ������ ����� ����� �������� ������ ����� �������� ����� (1 ��������), ������� �������� ������� ��� ������ ������ (2 ��������)" << "\n";
	bool strFinded = FindLines(file, strToFind);
	if (!strFinded)
	{
		cout << "Text not found" << "\n";
	}
	return 0;
}

