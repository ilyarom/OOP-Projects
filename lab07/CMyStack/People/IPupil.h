#pragma once
#include <string>
#include "IPerson.h"

class IPupil : public IPerson
{
	virtual std::string GetSchoolName() const = 0;
	virtual std::string GetSchoolClass() const = 0;
};