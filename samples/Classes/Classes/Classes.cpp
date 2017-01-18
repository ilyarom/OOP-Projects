// Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Classes.h"


A::A()
{
	std::cout << "constructor a\n";
};

A::A(const A &a)
{
	std::cout << "copy constructor a\n";
}


A::~A()
{
	std::cout << "destructor a\n";
}

void A::DoSomething()
{
	std::cout << "Do something a\n";
}

void A::DoSomethingWithMyClass(const A &a)
{
	std::cout << "Do something with exemplar of class a\n";
}

A A::ReturnMe()
{
	std::cout << "Function return object a\n";
	A aa;
	return aa;
}

B::B()
{
	std::cout << "constructor B\n";
};

B::B(const B &b)
{
	std::cout << "copy constructor B\n";
}

B::~B()
{
	std::cout << "destructor B\n";
}

void B::DoSomething()
{
	std::cout << "Do something B\n";
}

void B::DoSomethingWithMyClass(const B &b)
{
	std::cout << "Do something with exemplar of class b\n";
}

B B::ReturnMe()
{
	std::cout << "Function return object b\n";
	B bb;
	return bb;
}