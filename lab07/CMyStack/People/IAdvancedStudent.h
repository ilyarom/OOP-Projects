#pragma once
#include <string>
#include "IStudent.h"

class IAdvancedStudent : public IStudent
{
	virtual std::string GetThesisTheme() const = 0;
};