#pragma once
#include "CPersonImpl.h"
#include "IPupil.h"
#include <string>

class CPupil : public CPersonImpl<IPupil>
{
public:
	CPupil(const std::string& name, const std::string& surname, const std::string& middleName, const std::string& address, const std::string & schoolName, const std::string & schoolClass)
		: CPersonImpl<IPupil>(name, surname, middleName, address)
		, m_schoolName(schoolName)
		, m_schoolClass(schoolClass)
	{}
	std::string GetSchoolName() const
	{
		return m_schoolName;
	}
	std::string GetSchoolClass() const
	{
		return m_schoolClass;
	}
private:
	std::string m_schoolName;
	std::string m_schoolClass;
};