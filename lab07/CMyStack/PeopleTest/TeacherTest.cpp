#include "stdafx.h"
#include "../People/CTeacher.h"

struct Teacher_
{
	const std::string name = "Vasya";
	const std::string surname = "Pupkin";
	const std::string middleName = "Vasilyevich";
	const std::string address = "Zelenaya 62 A";
	const std::string subjectName = "OOP";
	CTeacher teacher;
	Teacher_()
		: teacher(name, surname, middleName, address, subjectName)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Teacher, Teacher_)

BOOST_AUTO_TEST_CASE(can_get_person_name)
{
	BOOST_CHECK_EQUAL(teacher.GetName(), name);
}

BOOST_AUTO_TEST_CASE(can_get_person_surname)
{
	BOOST_CHECK_EQUAL(teacher.GetSurname(), surname);
}

BOOST_AUTO_TEST_CASE(can_get_person_middleName)
{
	BOOST_CHECK_EQUAL(teacher.GetMiddleName(), middleName);
}

BOOST_AUTO_TEST_CASE(can_get_person_address)
{
	BOOST_CHECK_EQUAL(teacher.GetAddress(), address);
}

BOOST_AUTO_TEST_CASE(can_get_teacher_subject_name)
{
	BOOST_CHECK_EQUAL(teacher.GetSubjectName(), subjectName);
}


BOOST_AUTO_TEST_SUITE_END()