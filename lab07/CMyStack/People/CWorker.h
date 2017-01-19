#pragma once

#include "CPersonImpl.h"
#include "IWorker.h"
#include <string>

class CWorker : public CPersonImpl<IWorker>
{
public:
	CWorker(const std::string& name, const std::string& surname, const std::string& middleName, const std::string& address, const std::string & specialty)
		: CPersonImpl<IWorker>(name, surname, middleName, address)
		, m_specialty(specialty)
	{}
	std::string GetSpecialty() const
	{
		return m_specialty;
	}
private:
	std::string m_specialty;
};
