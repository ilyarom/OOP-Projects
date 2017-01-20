#pragma once

#include "CPersonImpl.h"
#include "ITeacher.h"
#include <string>
#include <iostream>


class CTeacher : public CPersonImpl<ITeacher>
{
public:
	CTeacher(const std::string& name, const std::string& surname, const std::string& middleName,const std::string& address, const std::string & subjectName)
		: CPersonImpl<ITeacher>(name, surname, middleName ,address)
		, m_subjectName(subjectName)
	{}
	std::string GetSubjectName() const
	{
		return m_subjectName;
	}
private:
	std::string m_subjectName;
};
