// multimatrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
void ReadMatrixFile(ifstream & MatrixFile, int matrix[3][3])
{
	size_t i = 0;
	for (size_t j = 0; i != 3; ++j)
	{
		MatrixFile >> matrix[i][j];
		if (j == 2)
		{
			++i;
			j = -1;
		}
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 3)
	{
		cout << "Недостаточно аргументов. Формат входных данных: <файл номер 1> <файл номер 2>" << "\n";
		return 1;
	}
	ifstream matrixfile1(argv[1]);
	ifstream matrixfile2(argv[2]);
	if (!matrixfile1.is_open() || !matrixfile2.is_open())
	{
		cout << "Невозможно открыть файл. Проверьте правильность вводимых данных или убедитесь в наличии данного файла." << "\n";
		return 1;
	};
	int Arr1[3][3];
	int Arr2[3][3];
	ReadMatrixFile(matrixfile1, Arr1);
	ReadMatrixFile(matrixfile2, Arr2);
	int ResArr[3][3];
	size_t i = 0;
	for (size_t j = 0; i != 3; ++j)
	{
		ResArr[i][j] = Arr1[i][0] * Arr2[0][j] + Arr1[i][1] * Arr2[1][j] + Arr1[i][2] * Arr2[2][j];
		cout << ResArr[i][j] << " ";
		if (j == 2)
		{
			++i;
			j = -1;
			cout << "\n";
		}
	}
    return 0;
};

