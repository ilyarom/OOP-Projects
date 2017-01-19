#include "stdafx.h"
#include "../People/CWorker.h"

struct Worker_
{
	const std::string name = "Vasya";
	const std::string surname = "Pupkin";
	const std::string middleName = "Vasilyevich";
	const std::string address = "Zelenaya 62 A";
	const std::string specialty = "Programming Engineer";
	CWorker worker;
	Worker_()
		: worker(name, surname, middleName, address, specialty)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Worker, Worker_)

BOOST_AUTO_TEST_CASE(can_get_person_name)
{
	BOOST_CHECK_EQUAL(worker.GetName(), name);
}

BOOST_AUTO_TEST_CASE(can_get_person_surname)
{
	BOOST_CHECK_EQUAL(worker.GetSurname(), surname);
}

BOOST_AUTO_TEST_CASE(can_get_person_middleName)
{
	BOOST_CHECK_EQUAL(worker.GetMiddleName(), middleName);
}

BOOST_AUTO_TEST_CASE(can_get_person_address)
{
	BOOST_CHECK_EQUAL(worker.GetAddress(), address);
}

BOOST_AUTO_TEST_CASE(can_get_worker_specialty)
{
	BOOST_CHECK_EQUAL(worker.GetSpecialty(), specialty);
}

BOOST_AUTO_TEST_SUITE_END()