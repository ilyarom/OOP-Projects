#pragma once
//template <typename Base>
#include <string>
#include <iostream>
class IPerson
{
public:
	virtual  ~IPerson()
	{
		//std::cout << "Person destructor" << std::endl;
	};
	virtual std::string GetName() const = 0;
	virtual std::string GetSurname() const = 0;
	virtual std::string GetMiddleName() const = 0;
	virtual std::string GetAddress() const = 0;
};