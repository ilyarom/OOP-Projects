// unary_binary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

class Number
{
public:
	Number(int number)
		:value(number)
	{}
	Number operator+()
	{
		return *this;
	}
	Number operator-()
	{
		return Number(-value);
	}

	Number operator-(const Number& rhs)
	{
		return (*this).value - rhs.value;
	}
	Number operator=(const Number& rhs)
	{
		if ((*this).value != rhs.value)
		{
			(*this).value = rhs.value;
		}
		return (*this);
	}

	Number operator++()
	{
		return Number(value++);
	}
	Number operator--()
	{
		return Number(value--);
	}
	int GetValue() const
	{
		return value;
	}
	void SetValue(int number)
	{
		value = number;
	}
private:
	int value;
};

Number const operator+(const Number& lhs, const Number& rhs)
{
	return Number(lhs.GetValue() + rhs.GetValue());
}

Number const operator-(const Number& lhs, const Number& rhs)
{
	return Number(lhs.GetValue() - rhs.GetValue());
}

std::ostream& operator << (std::ostream& output, const Number& number)
{
	output << number.GetValue();
	return output;
}

std::istream& operator >> (std::istream& input, Number& number)
{
	int num;
	input >> num;
	number.SetValue(num);
	return input;
}


int main()
{
	Number number(3);
	std::cout << ++number << "\n";
	std::cin >> number;
	std::cout << number << "\n";
    return 0;
}

