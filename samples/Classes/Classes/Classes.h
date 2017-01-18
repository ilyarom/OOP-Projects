#pragma once

#include <iostream>

class A
{
public:
	A();
	A(const A &a);
	~A();
	void DoSomething();
	void DoSomethingWithMyClass(const A &a);
	A ReturnMe();
private:
	std::string m_something = "something\n";
};

class B: public A
{
public:
	B();
	B(const B &b);
	~B();
	void DoSomething();
	void DoSomethingWithMyClass(const B &b);
	B ReturnMe();
private:
	std::string m_something = "something\n";
};