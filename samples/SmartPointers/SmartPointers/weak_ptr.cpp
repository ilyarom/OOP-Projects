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

	/*Как видно, объект foo ссылается на bar и наоборот.
	Образован цикл, из-за которого не вызовутся деструкторы объектов.
	Для того чтобы разорвать этот цикл, достаточно в классе Bar заменить shared_ptr на weak_ptr.
	Почему образован цикл? Давайте разберемся.
	При выходе из блока (в данном случае функции main()) уничтожаются локальные объекты. 
	Локальным объектом является foo. При уничтожении foo счетчик ссылок на его ресурс уменьшится на единицу. 
	Однако, ресурс освобожден не будет, так как на него есть ссылка со стороны ресурса bar.
	А на bar есть ссылка со стороны того же ресурса foo.*/

	//ПРАВИЛЬНЫЙ ПРИМЕР///////////////////////////////////
	std::cout << "======================\n";

	std::shared_ptr<Foo> ptr = std::make_shared<Foo>();
	std::weak_ptr<Foo> w(ptr);

	if (std::shared_ptr<Foo> foo = w.lock())
	{
		foo->doSomething();
	}

	/*weak_ptr не позволяет работать с ресурсом напрямую, но зато обладает методом lock(), который генерирует shared_ptr().*/

	return 0;
}