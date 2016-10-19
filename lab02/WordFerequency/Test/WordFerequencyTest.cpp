// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../WordFerequency/WordFerequency.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(CalculateWordArchive_function)
BOOST_AUTO_TEST_CASE(check_standart_map)
{
	WordFerequency sample = { { "hello", 2 },{ "is", 1 }, {"james", 2}, {"my", 1}, {"name", 1} };
	std::istringstream test("hello my name is james hello james");
	BOOST_CHECK(sample == CalculateWordArchive(test));
}
BOOST_AUTO_TEST_CASE(check_empty_map)
{
	WordFerequency sample = {};
	std::istringstream test("");
	BOOST_CHECK(sample == CalculateWordArchive(test));
}
BOOST_AUTO_TEST_CASE(check_register)
{
	WordFerequency sample = { { "HELLO", 1 },{ "hello", 1 }};
	std::istringstream test("hello HELLO\n");
	BOOST_CHECK(sample == CalculateWordArchive(test));
}
BOOST_AUTO_TEST_SUITE_END()