#pragma once
#include <string>
#include <iostream>
#include "IPerson.h"

class IStudent : public IPerson
{
public:
	virtual ~IStudent()
	{
		//std::cout << "IStudent destructor" << std::endl;
	};
	virtual std::string GetUniversityName() const = 0;
	virtual size_t GetStudentTicketNumber() const = 0;
};