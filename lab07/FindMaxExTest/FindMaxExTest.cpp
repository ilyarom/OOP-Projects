// FindMaxExTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Athlete.h"
#include "../FindMaxEx/FindMaxEx.h"


CAthlete Athlete1("Lionel Messi", 169, 66);
CAthlete Athlete2("Cristiano Ronaldo", 185, 85);
CAthlete Athlete3("Gareth Bale", 183, 74);
CAthlete Athlete4("Antoine Griezmann", 176, 67);

std::vector<CAthlete> emptyVec;
std::vector<CAthlete> players = { Athlete1, Athlete2, Athlete3, Athlete4 };

CAthlete maxParamAthlete;

double maxHeight = 185;
double maxWeight = 85;

BOOST_AUTO_TEST_SUITE(FindMaxEx_)

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
