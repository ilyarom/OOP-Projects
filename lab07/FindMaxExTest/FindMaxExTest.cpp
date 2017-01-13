// FindMaxExTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Athlete.h"
#include "../FindMaxEx/FindMaxEx.h"

/*class CTest 
{
	public:
		CTest() = default;
		CTest(const CTest &value)
		{

		}
		~CTest()
		{

		}
		CTest& operator =(CTest const &a)
		{
			//throw std::exception("assign");
			try
			{
				m_x = a.m_x;
				return *this;
			}
			catch (...)
			{
				throw;
			}
		}
		CTest & operator [](size_t index)
		{
			try
			{
				return m_item[index];
			}
			catch (...)
			{
				throw;
			}
		}
	private:
		double m_x;
		double m_y;
		CTest * m_item;
};*/


const CAthlete Athlete1("Lionel Messi", 169, 66);
const CAthlete Athlete2("Cristiano Ronaldo", 185, 85);
const CAthlete Athlete3("Gareth Bale", 183, 74);
const CAthlete Athlete4("Antoine Griezmann", 176, 67);

std::vector<CAthlete> emptyVec;
std::vector<CAthlete> players = { Athlete1, Athlete2, Athlete3, Athlete4 };

CAthlete maxParamAthlete = {"", 0, 0};

double maxHeight = 185;
double maxWeight = 85;

BOOST_AUTO_TEST_SUITE(FindMaxEx_)

/*BOOST_AUTO_TEST_CASE(can_process_test)
{
	CTest test1;
	CTest test2;
	BOOST_CHECK(test1 = test2);
}*/

BOOST_AUTO_TEST_CASE(can_process_empty_vector)
{
	BOOST_CHECK(emptyVec.empty());
	BOOST_CHECK(!FindMaxEx(emptyVec, maxParamAthlete, isLessHeight));
	BOOST_CHECK(!FindMaxEx(emptyVec, maxParamAthlete, isLessName));
}

BOOST_AUTO_TEST_CASE(check_filled_vector_an_empty)
{
	BOOST_CHECK(!players.empty());
}

BOOST_AUTO_TEST_CASE(can_find_max_height_athlete)
{
	BOOST_CHECK(FindMaxEx(players, maxParamAthlete, isLessHeight));
	BOOST_CHECK_EQUAL(maxParamAthlete.height, maxHeight);
}

BOOST_AUTO_TEST_CASE(can_find_max_athlet_by_weight)
{
	BOOST_CHECK(FindMaxEx(players, maxParamAthlete, isLessWeight));
	BOOST_CHECK_EQUAL(maxParamAthlete.weight, maxWeight);
}

BOOST_AUTO_TEST_CASE(can_find_name_of_max_weight_player)
{
	BOOST_CHECK(FindMaxEx(players, maxParamAthlete, isLessHeight));
	BOOST_CHECK_EQUAL(maxParamAthlete.name, "Cristiano Ronaldo");
}

BOOST_AUTO_TEST_SUITE_END()
