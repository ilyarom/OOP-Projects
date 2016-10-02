// Invert.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;
void ReadMatrixFile(ifstream & MatrixFile, double matrix[3][3])
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

double ReadMinor(double matrix[3][3], const size_t FrizedI, const size_t FrizedJ)
{
	size_t i = 0;
	size_t k = 0;
	double minor[4];
	for (size_t j = 0; i != 3; ++j)
	{
		if (i != FrizedI && j != FrizedJ)
		{
			minor[k] = matrix[i][j];
			++k;
		}
		if (j == 2)
		{
			++i;
			j = -1;
		}
	}
	if ((FrizedI + FrizedJ) % 2 == 0)
	{
		return minor[0] * minor[3] - minor[1] * minor[2];
	}
	else
	{
		return -(minor[0] * minor[3] - minor[1] * minor[2]);
	}
}

void CalculateCofactorMatrix(double matrix[3][3], double Determinant, double CofactorMatrix[3][3])
{
	size_t i = 0;
	for (size_t j = 0; i != 3; ++j)
	{
		CofactorMatrix[i][j] = ReadMinor(matrix, i, j);
		if (j == 2)
		{
			++i;
			j = -1;
		}
	}
}


double CalculateDeterminant(double matrix[3][3])
{
	size_t i = 0;
	double Determinant;
	Determinant = ((matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) + (matrix[0][2] * matrix[1][0] * matrix[2][1]) - (matrix[0][2] * matrix[1][1] * matrix[2][0]) - (matrix[0][1] * matrix[1][0] * matrix[2][2]) - (matrix[0][0] * matrix[1][2] * matrix[2][1]));
	return Determinant;
}

void GetInverseMatrix(double CofactorMatrix[3][3], double InverseMatrix[3][3], double Determinant)
{
	size_t i = 0;
	for (size_t j = 0; i != 3; ++j)
	{
		InverseMatrix[i][j] = CofactorMatrix[j][i] / Determinant;
		cout << setprecision(3) << InverseMatrix[i][j] << " ";
		if (j == 2)
		{
			++i;
			j = -1;
			cout << "\n";
		}
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 2)
	{
		cout << "Недостаточно аргументов. Формат входных данных: <файл номер 1> <файл номер 2>" << "\n";
		return 1;
	}
	ifstream MatrixFile(argv[1]);
	if (!MatrixFile.is_open())
	{
		cout << "Невозможно открыть файл. Проверьте правильность вводимых данных или убедитесь в наличии данного файла." << "\n";
		return 1;
	};
	double Matrix[3][3];
	double CofactorMatrix[3][3];
	ReadMatrixFile(MatrixFile, Matrix);
	double Determinant = CalculateDeterminant(Matrix);
	if (Determinant == 0)
	{
		cout << "Определитель равен нулю. Обратной матрицы не существует" << "\n";
		return 1;
	}
	CalculateCofactorMatrix(Matrix, Determinant, CofactorMatrix);
	double InverseMatrix[3][3];
	GetInverseMatrix(CofactorMatrix, InverseMatrix, Determinant);
    return 0;
}

