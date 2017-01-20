#pragma once
#include <string>
#include "IStudent.h"

class IAdvancedStudent : public IStudent
{
public:
	virtual ~IAdvancedStudent() {};
	virtual std::string GetThesisTheme() const = 0;
};