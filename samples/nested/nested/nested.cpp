// nested.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// Весь прикол в private. Если делаем public то это просто публичный класс
class Enclosing
{
private:
	int x = 1;
	class Nested
	{
		int y = 2;
		void doNested(Enclosing e)
		{
			std::cout << "Do Nested " << e.x << std::endl; // все норм
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

