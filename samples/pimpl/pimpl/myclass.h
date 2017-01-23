#pragma once
#include "stdafx.h"
#include <iostream>

class MyClassImpl;

class MyClass
{
public:
	MyClass();
	~MyClass();
	int doSomething(int arg);
private:
	MyClassImpl * myClassImpl;
};