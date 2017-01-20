#include "stdafx.h"
#include "../People/CAdvancedStudent.h"

struct AdvancedStudent_
{
	const std::string name = "Vasya";
	const std::string surname = "Pupkin";
	const std::string middleName = "Vasilyevich";
	const std::string address = "Zelenaya 62 A";
	const std::string universityName = "PGTU";
	const size_t studentTicketNumber = 118345;
	const std::string thesisTheme = "Radionuklidnaya diagnostica vospalitelnyh zabolevaniy";
	CAdvancedStudent advancedStudent;
	AdvancedStudent_()
		: advancedStudent(name, surname, middleName, address, universityName, studentTicketNumber, thesisTheme)
	{}
};

BOOST_FIXTURE_TEST_SUITE(AdvancedStudent, AdvancedStudent_)

BOOST_AUTO_TEST_CASE(can_get_person_name)
{
	BOOST_CHECK_EQUAL(advancedStudent.GetName(), name);
}

BOOST_AUTO_TEST_CASE(can_get_person_surname)
{
	BOOST_CHECK_EQUAL(advancedStudent.GetSurname(), surname);
}

BOOST_AUTO_TEST_CASE(can_get_person_middleName)
{
	BOOST_CHECK_EQUAL(advancedStudent.GetMiddleName(), middleName);
}

BOOST_AUTO_TEST_CASE(can_get_person_address)
{
	BOOST_CHECK_EQUAL(advancedStudent.GetAddress(), address);
}

BOOST_AUTO_TEST_CASE(can_get_advanced_student_university_name)
{
	BOOST_CHECK_EQUAL(advancedStudent.GetUniversityName(), universityName);
}

BOOST_AUTO_TEST_CASE(can_get_advanced_student_ticket_number)
{
	BOOST_CHECK_EQUAL(advancedStudent.GetStudentTicketNumber(), studentTicketNumber);
}

BOOST_AUTO_TEST_CASE(can_get_advanced_student_thesis_theme)
{
	BOOST_CHECK_EQUAL(advancedStudent.GetThesisTheme(), thesisTheme);
}

BOOST_AUTO_TEST_SUITE_END()