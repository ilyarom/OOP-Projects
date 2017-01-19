#include "stdafx.h"
#include "../People/CPupil.h"

struct Pupil_
{
	const std::string name = "Vasya";
	const std::string surname = "Pupkin";
	const std::string middleName = "Vasilyevich";
	const std::string address = "Zelenaya 62 A";
	const std::string schoolName = "22";
	const std::string schoolClass = "7A";
	CPupil pupil;
	Pupil_()
		: pupil(name, surname, middleName, address, schoolName, schoolClass)
	{}
};
	
BOOST_FIXTURE_TEST_SUITE(Pupil, Pupil_)

BOOST_AUTO_TEST_CASE(can_get_person_name)
{
	BOOST_CHECK_EQUAL(pupil.GetName(), name);
}

BOOST_AUTO_TEST_CASE(can_get_person_surname)
{
	BOOST_CHECK_EQUAL(pupil.GetSurname(), surname);
}

BOOST_AUTO_TEST_CASE(can_get_person_middleName)
{
	BOOST_CHECK_EQUAL(pupil.GetMiddleName(), middleName);
}

BOOST_AUTO_TEST_CASE(can_get_person_address)
{
	BOOST_CHECK_EQUAL(pupil.GetAddress(), address);
}

BOOST_AUTO_TEST_CASE(can_get_pupil_school_name)
{
	BOOST_CHECK_EQUAL(pupil.GetSchoolName(), schoolName);
}

BOOST_AUTO_TEST_CASE(can_get_pupil_school_class)
{
	BOOST_CHECK_EQUAL(pupil.GetSchoolClass(), schoolClass);
}

BOOST_AUTO_TEST_SUITE_END()