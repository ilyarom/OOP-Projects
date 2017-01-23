// lvalue_rvalue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>  


class MyString
{
public:
	~MyString()
	{
		if (m_data != nullptr)
		{
			delete[] m_data;
		}
	}
	MyString(const MyString& str)
	{
		m_data = new char[m_size + 1];
		m_size = str.m_size;
		std::cout << "Copy data in copy constructor";
		std::copy(str.m_data, str.m_data + m_size, m_data);
		m_data[m_size] = 0;
	}
	MyString operator=(const MyString& rhs)
	{
		if (this != &rhs)
		{
			if (m_data != nullptr)
			{
				delete m_data;
			}
			m_data = new char[m_size + 1];
			m_size = rhs.m_size;
			std::cout << "Copy data in = operator";
			std::copy(rhs.m_data, rhs.m_data + m_size, m_data);
			m_data[m_size] = 0;
		}
		return *this;
	}

	MyString(MyString&& str)
	{
		m_data = new char[m_size + 1];
		m_size = str.m_size;
		std::cout << "Move data in copy constructor";
		str.m_data = nullptr;
		str.m_size = 0;
	}
	MyString operator=(MyString&& rhs)
	{
		if (this != &rhs)
		{
			if (m_data != nullptr)
			{
				delete m_data;
			}
			m_data = rhs.m_data;
			m_size = rhs.m_size;
			std::cout << "Move data in = operator";
			rhs.m_data = nullptr;
			rhs.m_size = 0;
		}
		return *this;
	}
private:
	char *m_data;
	int m_size;

};


int main()
{
    return 0;
}

