#pragma once
#include <string>
#include "IPerson.h"

class ITeacher : public IPerson
{
public:
	virtual ~ITeacher() {};
	virtual std::string GetSubjectName() const = 0;
};