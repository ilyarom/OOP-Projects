// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../FindAndReplace/FindAndReplace.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(FindAndReplace_function)
BOOST_AUTO_TEST_CASE(check_empty_subject)
{
	string subject = "";
	string search = "FindMe";
	string replace = "InsertMe";
	BOOST_CHECK(FindAndReplace(subject, search, replace) == "");
}
BOOST_AUTO_TEST_CASE(check_empty_search)
{
	string subject = "Subject";
	string search = "";
	string replace = "InsertMe";
	BOOST_CHECK(FindAndReplace(subject, search, replace) == "Subject");
}
BOOST_AUTO_TEST_CASE(check_empty_replace)
{
	string subject = "Subject";
	string search = "Sub";
	string replace = "";
	BOOST_CHECK(FindAndReplace(subject, search, replace) == "ject");
}
BOOST_AUTO_TEST_CASE(check_standart_data)
{
	string subject = "Subject";
	string search = "ject";
	string replace = "sub";
	BOOST_CHECK(FindAndReplace(subject, search, replace) == "Subsub");
}
BOOST_AUTO_TEST_CASE(check_double_replace)
{
	string subject = "subject";
	string search = "sub";
	string replace = "subsub";
	BOOST_CHECK(FindAndReplace(subject, search, replace) == "subsubject");
}
BOOST_AUTO_TEST_CASE(check_double_search)
{
	string subject = "subsubject";
	string search = "subsub";
	string replace = "sub";
	BOOST_CHECK(FindAndReplace(subject, search, replace) == "subject");
}

BOOST_AUTO_TEST_CASE(check_double_search3)
{
	BOOST_CHECK(FindAndReplace("mama", "ma", "mama") == "mamamama");
}

BOOST_AUTO_TEST_CASE(check_double_search4)
{
	BOOST_CHECK(FindAndReplace("maa", "ma", "m") == "ma");
}

BOOST_AUTO_TEST_SUITE_END()