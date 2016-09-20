// replace.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 5)
	{
		cout << "������������ ����������. ������ ������� ������: <���������� �����> <�������� ����> <������ ��� ������> <������ ����������>" << "\n";
		return 1;
	}
	ifstream filetoin(argv[1]);
	ofstream filetoout(argv[2]);
	if (!filetoin.is_open())
	{
		cout << "���������� ������� ����. ��������� ������������ �������� ������ ��� ��������� � ������� ������� �����." << "\n";
		return 1;
	}
	string strToFind = argv[3];
	string strToReplace = argv[4];
	if (strToFind.empty())
	{
		cout << "������ ������ �������� ��� ��������� ������ ��� ������." << "\n";
		return 1;
	}
	string line;
	int strPos;
	while (getline(filetoin, line))
	{
		strPos = line.find(strToFind);
		if (strPos != string::npos)
		{
			line.replace(strPos, strToFind.length(), strToReplace);
		}
		filetoout << line << "\n";
	};
	return 0;
}

