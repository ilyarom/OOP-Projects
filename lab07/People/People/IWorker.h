#pragma once
#include <string>
#include "IPerson.h"

class IWorker : public IPerson
{
public:
	virtual ~IWorker() {};
	virtual std::string GetSpecialty() const = 0;
};