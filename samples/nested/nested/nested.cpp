// nested.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// ���� ������ � private. ���� ������ public �� ��� ������ ��������� �����
class Enclosing
{
private:
	int x = 1;
	class Nested
	{
		int y = 2;
		void doNested(Enclosing e)
		{
			std::cout << "Do Nested " << e.x << std::endl; // ��� ����
		}
	};
	void doEnclosing(Nested n)
	{
		std::cout << "Do Enclosing " << n.y << std::endl;
	}
};

int main()
{
    return 0;
}

