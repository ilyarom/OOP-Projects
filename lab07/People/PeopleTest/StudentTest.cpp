#include "stdafx.h"
#include "../People/CStudent.h"

struct Student_
{
	const std::string name = "Vasya";
	const std::string surname = "Pupkin";
	const std::string middleName = "Vasilyevich";
	const std::string address = "Zelenaya 62 A";
	const std::string universityName = "PGTU";
	const size_t studentTicketNumber = 118345;
	CStudent student;
	Student_()
		: student(name, surname, middleName, address, universityName, studentTicketNumber)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Student, Student_)

BOOST_AUTO_TEST_CASE(can_get_person_name)
{
	BOOST_CHECK_EQUAL(student.GetName(), name);
}

BOOST_AUTO_TEST_CASE(can_get_person_surname)
{
	BOOST_CHECK_EQUAL(student.GetSurname(), surname);
}

BOOST_AUTO_TEST_CASE(can_get_person_middleName)
{
	BOOST_CHECK_EQUAL(student.GetMiddleName(), middleName);
}

BOOST_AUTO_TEST_CASE(can_get_person_address)
{
	BOOST_CHECK_EQUAL(student.GetAddress(), address);
}

BOOST_AUTO_TEST_CASE(can_get_student_school_name)
{
	BOOST_CHECK_EQUAL(student.GetUniversityName(), universityName);
}

BOOST_AUTO_TEST_CASE(can_get_student_school_class)
{
	BOOST_CHECK_EQUAL(student.GetStudentTicketNumber(), studentTicketNumber);
}

BOOST_AUTO_TEST_SUITE_END()