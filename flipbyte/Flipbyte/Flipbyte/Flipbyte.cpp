// Flipbyte.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int iPow(int i)
{
	int result = 1;
	for (int k = 0; k <= i; ++k)
	{
		result = result * 2;
	}
	return result;
}

string dec2binRev(int decNumber) //����������� ����� �� 10-����� ������� ���������� � 2-�����. �������� �������� ����� �������������, �������� ���� ����������
{
	bool firstNull = true;
	int dividend = decNumber;
	int remainder = 0;
	string reversedBinNumber = "";
	while (!(dividend == 0 || dividend == 1))
	{
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
	reversedBinNumber = reversedBinNumber + to_string(dividend);
	return reversedBinNumber;
}

int bin2dec(string reversedBinNumber) // ��������� ����� �� 2-����� ������� ���������� � 10-�����
{
	int maxDegree = reversedBinNumber.length() - 1;
	int sum = 0;
	int j = 0;
	for (int i = maxDegree; i >= 0; --i)
	{
		if (reversedBinNumber[j] == '1')
		{
			sum = sum + iPow(i);
		};
	}
	return sum;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 2)
	{
		cout << "����������� ������� ������� ������, �� ���� ����������� ������� ����. ����� ������ ���� �� 0 �� 255" << "\n";
		return 1;
	}
	string inputString = argv[1];
	if (inputString.empty())
	{
		cout << "����������� ������� ������� ������, �� ���� ����������� ������� ����. ����� ������ ���� �� 0 �� 255" << "\n";
		return 1;
	}
	int decNumber = atoi(inputString.c_str());
	if (decNumber == 0 && inputString != "0")
	{
		cout << "����������� ������� ������� ������, �� ���� ����������� ������� ����. ����� ������ ���� �� 0 �� 255" << "\n";
		return 1;
	}
	cout << decNumber << "\n";
	if (!(decNumber >= 0 && decNumber <= 255))
	{
		cout << "����������� ������� ������� ������, �� ���� ����������� ������� ����. ����� ������ ���� �� 0 �� 255" << "\n";
		return 1;
	}
	string reversedBinNumber;
	reversedBinNumber = dec2binRev(decNumber);
	decNumber = bin2dec(reversedBinNumber);
	cout << decNumber << "\n";
	return 0;
}


