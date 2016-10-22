// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Vector/Vector.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(GetMinElement_function)

	BOOST_AUTO_TEST_CASE(get_min_element)
	{
		vector<double> Vector = { 0, 1, -5, 3.33 };
		GetMinElement(Vector);
		BOOST_CHECK(GetMinElement(Vector) == -5);
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(GetMaxElement_function)

	BOOST_AUTO_TEST_CASE(get_max_element)
	{
		vector<double> Vector = { 0, 1, -5.66, -5 };
		GetMaxElement(Vector);
		BOOST_CHECK(GetMaxElement(Vector) == 1);
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(isMinNull_function)

BOOST_AUTO_TEST_CASE(isMinNull_null)
{
	vector<double> Vector = { 0, 1, 2, 3 };
	double minElement = GetMinElement(Vector);
	BOOST_CHECK(isMinNull(minElement));
}

BOOST_AUTO_TEST_CASE(isMinNull_no_null)
{
	vector<double> Vector = { 0, -1, 2, -3 };
	double minElement = GetMinElement(Vector);
	BOOST_CHECK(!isMinNull(minElement));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(SortVector_function)

BOOST_AUTO_TEST_CASE(SortStandartVector)
{
	vector<double> Vector = { -1, 0.1, -2.65, 5 };
	SortVector(Vector);
	sampleVector = {-2.65, -1, 0.1, 5}
	BOOST_CHECK(Vector == sampleVector);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TransformVector_function)

	BOOST_AUTO_TEST_CASE(Transform_empty_vector)
	{
		vector<double> Vector = {};
		TransformVector(Vector);
		vector <double> sampleVector = {};
		BOOST_CHECK(Vector == sampleVector);
	}

	BOOST_AUTO_TEST_CASE(Transform_one_element_vector)
	{
		vector<double> Vector = {4};
		vector <double> sampleVector = Vector;
		TransformVector(Vector);
		BOOST_CHECK(Vector == sampleVector);
	}

	BOOST_AUTO_TEST_CASE(Transform_standart_vector)
	{
		vector<double> Vector = {1, 2, -4, 5.5};
		TransformVector(Vector);
		vector <double> sampleVector = {-7.5625, -2.75, -1.375, 5.5};
		BOOST_CHECK(Vector == sampleVector);
	}
BOOST_AUTO_TEST_SUITE_END()