#pragma once
#include <string>
#include "IPerson.h"

class IStudent : public IPerson
{
	virtual std::string GetUniversityName() const = 0;
	virtual size_t GetStudentTicketNumber() const = 0;
};