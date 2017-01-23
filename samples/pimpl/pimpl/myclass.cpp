#include "stdafx.h"
#include "myclass.h"
#include "myclassimpl.h"
#include <iostream>

MyClass::MyClass()
	:myClassImpl(new MyClassImpl)
{
	std::cout << "My class constructor\n";
}

MyClass::~MyClass()
{
	std::cout << "My class destructor\n";
	delete myClassImpl;
}

int MyClass::doSomething(int arg)
{
	return myClassImpl->doSomething(arg);
}