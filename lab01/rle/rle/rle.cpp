// rle.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	string mode = argv[1];
	ifstream filetoin(argv[2]);
	ofstream filetoout(argv[3]);
	setlocale(LC_ALL, "rus");
	if (argc != 4)
	{
		filetoout << "������������ ����������. ������ ������� ������: <�������� ������> <�����>" << "\n";
		return 1;
	}
	if (!filetoin.is_open() || !filetoout.is_open())
	{
		filetoout << "���������� ������� ���� �� ������. ��������� ������������ �������� ������ ��� ��������� � ������� ������ ����� � ������." << "\n";
		return 1;
	}
	string inputString;
	char lastSymbol;
	if (mode.empty())
	{
		filetoout << "������� ������� ������� ������. ������ ������� ������: <�������� ������> <�����>" << "\n";
		return 1;
	}
	int lenSameSymbols = 1;
	if (mode == "pack")
	{
		while (!filetoin.eof())
		{
			getline(filetoin, inputString);
			for (int i = 0; i < inputString.length(); ++i)
			{
				if (inputString[i] == inputString[i + 1] || lastSymbol == inputString[i] && lenSameSymbols <= 255)
				{
					lenSameSymbols = lenSameSymbols + 1;
				}
				else
				{
					filetoout << lenSameSymbols << ",'" << inputString[i] << "',";
					lenSameSymbols = 1;
				};
				lastSymbol = 0;
			}
			if (!filetoin.eof())
			{
				lastSymbol = inputString[inputString.length()];
			}
		}
	}
	else if (mode == "unpack")
	{
		bool SymbolMode = false;
		bool NumberMode = true;
		bool SymbolReaded = false;
		string AssemblyString = "";
		int decNumber;
		while (!filetoin.eof())
		{
			getline(filetoin, inputString);
			for (int i = 0; i < inputString.length(); ++i)
			{
				cout << inputString[i] << "\n";
				SymbolReaded = false;
				if (inputString[i] == ',' || (filetoin.eof() && i == inputString.length() - 1))
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
							filetoout << "������� ������� ����� � ������������������ ��������" << "\n";
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
								filetoout << AssemblyString[1];
							}
							AssemblyString = "";
						}
						else
						{
							filetoout << "��� �������� ������� ��������� ���� ������." << "\n";
							return 1;
						}
					}
				}
				if (!SymbolReaded)
				{
					AssemblyString = AssemblyString + inputString[i];
				}
			}
		}
	}
	else
	{
		filetoout << "������� ������ �����. ����� ����� ��������� �������� pack � unpack" << "\n";
		return 1;
	}
    return 0;
}

