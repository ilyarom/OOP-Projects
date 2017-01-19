#pragma once
#include <string>
#include "IPerson.h"

class IWorker : public IPerson
{
	virtual std::string GetSpecialty() const = 0;
};