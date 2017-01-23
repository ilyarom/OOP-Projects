// SmartPointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<int> x_ptr(new int(42));
	std::unique_ptr<int> y_ptr;
//	y_ptr = x_ptr; // комилятор не дает нам этого сделать
//	std::unique_ptr<int> z_ptr(x_ptr); // аналогично, компилятор запрещает нам такое
	y_ptr = std::move(x_ptr);
	std::cout << *y_ptr << std::endl; // x_ptr, в свою очередь, после данной операции начинает указывать на nullptr
	y_ptr.reset(); // сбрасываем права владения

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	std::shared_ptr<int> x1_ptr(new int(42));
	std::shared_ptr<int> y1_ptr(new int(50)); // аналог make_shared<int> y1_ptr(50)
	y1_ptr = x1_ptr;
	std::shared_ptr<int> z1_ptr(x1_ptr);
	std::cout << *x1_ptr << std::endl << *y1_ptr << std::endl << *z1_ptr << std::endl;

}

