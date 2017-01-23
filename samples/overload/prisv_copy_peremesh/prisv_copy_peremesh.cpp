// prisv_copy_peremesh.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


class CMyString
{
public:
	CMyString(std::string)
	{
	}
	CMyString& operator =(CMyString& other)
	{
		if (this != std::addressof(other))
		{
			CMyString tmpCopy(other);
			std::swap(m_pChars, other.m_pChars);
		}
		return *this;
	}
	CMyStack& operator =(CMyStack &&stack)
    {
        if (std::addressof(stack) != this)
        {
            m_top = stack.m_top;
            m_size = stack.m_size;
            stack.m_top = nullptr;
            stack.m_size = 0;
        }

        return *this;
    }
private:
	char * m_pChars;
	size_t m_length;
};