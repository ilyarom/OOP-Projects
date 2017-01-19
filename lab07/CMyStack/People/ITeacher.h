#pragma once
#include <string>
#include "IPerson.h"

class ITeacher : public IPerson
{
	virtual std::string GetSubjectName() const = 0;
};