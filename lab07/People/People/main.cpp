#include "stdafx.h"
#include "IPupil.h"
#include "CStudent.h"
#include <iostream>

class A
{
public:
	virtual ~A()
	{
		std::cout << "destructor A" << std::endl;
	}
};

class B : public A
{
public:
	~B()
	{
		std::cout << "destructor B\n";
	}
};

void DoSomethingWithPerson(IPerson & person)
{
	std::cout << person.GetName() << std::endl;
}

int main()
{
	CStudent s("ivan", "petrov", "sergeevich", "addr", "university", 4);
	A * p = new B;
	delete p;
	return 0;
}