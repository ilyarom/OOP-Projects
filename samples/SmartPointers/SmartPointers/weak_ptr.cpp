#include "stdafx.h"
#include <iostream>
#include <memory>

class Bar;

class Foo
{
public:
	Foo() { std::cout << "Foo()" << std::endl; }
	~Foo() { std::cout << "~Foo()" << std::endl; }

	void doSomething()
	{
		std::cout << "something\n";
	}

	std::shared_ptr<Bar> bar;
};


class Bar
{
public:
	Bar() { std::cout << "Bar()" << std::endl; }
	~Bar() { std::cout << "~Bar()" << std::endl; }

	//std::shared_ptr<Foo> foo;
	std::weak_ptr<Foo> foo;
};


int main()
{
	auto foo = std::make_shared<Foo>();

	foo->bar = std::make_shared<Bar>();
	foo->bar->foo = foo;

	/*��� �����, ������ foo ��������� �� bar � ��������.
	��������� ����, ��-�� �������� �� ��������� ����������� ��������.
	��� ���� ����� ��������� ���� ����, ���������� � ������ Bar �������� shared_ptr �� weak_ptr.
	������ ��������� ����? ������� ����������.
	��� ������ �� ����� (� ������ ������ ������� main()) ������������ ��������� �������. 
	��������� �������� �������� foo. ��� ����������� foo ������� ������ �� ��� ������ ���������� �� �������. 
	������, ������ ���������� �� �����, ��� ��� �� ���� ���� ������ �� ������� ������� bar.
	� �� bar ���� ������ �� ������� ���� �� ������� foo.*/

	//���������� ������///////////////////////////////////
	std::cout << "======================\n";

	std::shared_ptr<Foo> ptr = std::make_shared<Foo>();
	std::weak_ptr<Foo> w(ptr);

	if (std::shared_ptr<Foo> foo = w.lock())
	{
		foo->doSomething();
	}

	/*weak_ptr �� ��������� �������� � �������� ��������, �� ���� �������� ������� lock(), ������� ���������� shared_ptr().*/

	return 0;
}