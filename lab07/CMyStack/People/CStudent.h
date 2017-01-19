#pragma once
#include "CStudentImpl.h"
#include "IStudent.h"
#include <string>

class CStudent : public CStudentImpl<IStudent>
{
public:
	CStudent(const std::string& name, const std::string& surname, const std::string& middleName, const std::string& address, const std::string& universityName, size_t studentTicketNumber)
		: CStudentImpl<IStudent>(name, surname, middleName, address, universityName, studentTicketNumber)
	{}
};
