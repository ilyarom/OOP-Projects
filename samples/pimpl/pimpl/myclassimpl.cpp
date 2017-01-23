#include "stdafx.h"
#include "myclassimpl.h"

MyClassImpl::MyClassImpl()
{
	std::cout << "My classImpl constructor\n";
}

MyClassImpl::~MyClassImpl()
{
	std::cout << "My classImpl destructor\n";
}

int MyClassImpl::doSomething(int arg)
{
	return arg;
}