#pragma once

#include "CStudentImpl.h"
#include "IStudent.h"
#include <string>

class CAdvancedStudent : public CStudentImpl<IStudent>
{
public:
	CAdvancedStudent(const std::string& name, const std::string& surname, const std::string& middleName, const std::string& address, const std::string& universityName, size_t studentTicketNumber, std::string thesisTheme)
		: CStudentImpl<IStudent>(name, surname, middleName, address, universityName, studentTicketNumber)
		, m_thesisTheme(thesisTheme)
	{}
	std::string GetThesisTheme() const
	{
		return m_thesisTheme;
	}
private:
	std::string m_thesisTheme;
};
