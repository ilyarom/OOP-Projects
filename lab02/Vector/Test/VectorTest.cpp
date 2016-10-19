// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Vector/Vector.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(GetMinElement_function)

BOOST_AUTO_TEST_CASE(get_min_element)
{
	vector<double> Vector = { 0, 1, 2, 3 };
	GetMinElement(Vector);
	BOOST_CHECK(GetMinElement(Vector) == 0);
}

BOOST_AUTO_TEST_CASE(get_min_element_negative)
{
	vector<double> Vector = { 0, -1, 2, -3 };
	GetMinElement(Vector);
	BOOST_CHECK(GetMinElement(Vector) == -3);
}

BOOST_AUTO_TEST_CASE(get_min_element_fractional)
{
	vector<double> Vector = { 9.55, 1.54, 2.22, 3.22 };
	GetMinElement(Vector);
	BOOST_CHECK(GetMinElement(Vector) == 1.54);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(GetMaxElement_function)

BOOST_AUTO_TEST_CASE(get_max_element)
{
	vector<double> Vector = { 0, 1, 2, 3 };
	GetMaxElement(Vector);
	BOOST_CHECK(GetMaxElement(Vector) == 3);
}

BOOST_AUTO_TEST_CASE(get_max_element_negative)
{
	vector<double> Vector = { 0, -1, 2, -3 };
	GetMaxElement(Vector);
	BOOST_CHECK(GetMaxElement(Vector) == 2);
}

BOOST_AUTO_TEST_CASE(get_max_element_fractional)
{
	vector<double> Vector = { 0, 1.54, 2.22, 3.22 };
	GetMaxElement(Vector);
	BOOST_CHECK(GetMaxElement(Vector) == 3.22);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CalculateVector_function)

BOOST_AUTO_TEST_CASE(Calculate_empty_vector)
{
	vector<double> Vector = {};
	CalculateVector(Vector);
	vector <double> neededVector = {};
	BOOST_CHECK(Vector == neededVector);
}

BOOST_AUTO_TEST_CASE(Calculate_standart_vector)
{
	vector<double> Vector = {1, 2, 4, 5};
	CalculateVector(Vector);
	vector <double> neededVector = {5, 10, 20, 25};
	BOOST_CHECK(Vector == neededVector);
}

BOOST_AUTO_TEST_CASE(Calculate_standart_vector_negative)
{
	vector<double> Vector = {4, -1, -2, 1 };
	CalculateVector(Vector);
	vector <double> neededVector = {-8, -2, 2, 4};
	BOOST_CHECK(Vector == neededVector);
}

BOOST_AUTO_TEST_CASE(calculate_standart_vector_fractional)
{
	vector<double> Vector = { 0.1, 1.5, 2.5, 3.5 };
	CalculateVector(Vector);
	vector <double> neededVector = { 3.5, 52.5, 87.5, 122.5 };
	BOOST_CHECK(Vector == neededVector);
}
BOOST_AUTO_TEST_SUITE_END()