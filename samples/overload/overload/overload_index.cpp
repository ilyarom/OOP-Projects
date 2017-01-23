// overload.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Array
{
public:
	Array(int size)
		:m_size(size)
	{
		numbers = new int[size];
		for (int i = 0; i < m_size; i++)
		{
			numbers[i] = i;
		}
	}
	~Array()
	{
		delete [] numbers;
	}
	void printData()
	{
		for (int i = 0; i < m_size; i++)
		{
			std::cout << numbers[i] << "\n";
		}
	}
	int &operator [](const int iter)
	{
		return numbers[iter];
	}
private:
	int * numbers;
	int m_size;
};

int main()
{
	Array arr(10);
	arr.printData();
	return 0;
}