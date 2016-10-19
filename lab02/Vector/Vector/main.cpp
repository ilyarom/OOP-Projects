// Vector.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Vector.h"

 
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	vector <double> numbers;
	double number;
	size_t i = 0;
	while (!cin.eof())
	{
		cin >> number;
		++i;
	    numbers.push_back(number);
	}
	CalculateVector(numbers);
	for (i = 0; i < numbers.size(); ++i)
	{
		cout << numbers[i] << "\n";
	}
    return 0;
}

