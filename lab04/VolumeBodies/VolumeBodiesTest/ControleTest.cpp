#include "stdafx.h"
#include "../VolumeBodies/Controle.h"
#include "../VolumeBodies/Body.h"
#include <sstream>
#include <boost/optional.hpp>

using namespace std;
using boost::optional;
using boost::none;


struct ControleDependencies
{
    stringstream input;
    stringstream output;
	vector<shared_ptr<CBody>> bodies;
};

struct ControleFixture : ControleDependencies
{
    CControle controle;

    ControleFixture()
        : controle(bodies, input, output)
    {
    }


    void VerifyCommandHandling(const string& command, const string& expectedOutput)
    {
        output = stringstream();
        input = stringstream();
        BOOST_CHECK(input << command);
        BOOST_CHECK(controle.HandleCommand());
        BOOST_CHECK(input.eof());
        BOOST_CHECK_EQUAL(output.str(), expectedOutput);
    }
};

BOOST_FIXTURE_TEST_SUITE(Controle, ControleFixture)

	BOOST_AUTO_TEST_CASE(can_create_cone)
	{
		VerifyCommandHandling("Cone 2 5 10", "");
	}

	BOOST_AUTO_TEST_CASE(can_create_parallelepiped)
	{
		VerifyCommandHandling("Parallelepiped 2 5 10 5", "");
	}


	BOOST_AUTO_TEST_CASE(can_create_cylinder)
	{
		VerifyCommandHandling("Cylinder 2 5 10", "");
	}

    BOOST_AUTO_TEST_CASE(can_create_sphere)
    {
        VerifyCommandHandling("Sphere 5 10", "");
    }

	BOOST_AUTO_TEST_CASE(can_find_largest_weight_body)
	{
		string expectedOutput = R"(Body with max weight is Sphere:
	density = 5
	volume = 4188.790205
	mass = 20943.95102
	radius = 10
)";
		VerifyCommandHandling("Cylinder 2 5 10", "");
		VerifyCommandHandling("Sphere 5 10", "");
		VerifyCommandHandling("Parallelepiped 2 5 10 5", "");
		controle.FindLargestWeightBody(output);
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}

	BOOST_AUTO_TEST_CASE(can_not_find_largest_weight_body)
	{
		string expectedOutput = "Error. Bodies are not exist\n";
		controle.FindLargestWeightBody(output);
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}

	BOOST_AUTO_TEST_CASE(can_find_smallest_weight_body_in_water)
	{
		string expectedOutput = R"(Body with smallest weight in water is Sphere:
	density = 5
	volume = 4188.790205
	mass = 20943.95102
	radius = 10
)";
		VerifyCommandHandling("Sphere 5 10", "");
		VerifyCommandHandling("Cylinder 2 -5 10", "");
		VerifyCommandHandling("Parallelepiped 2 5 10 5", "");
		controle.FindSmallestWeightBodyInWater(output);
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}

	BOOST_AUTO_TEST_CASE(can_not_find_smallest_weight_body_in_water)
	{
		string expectedOutput = "Error. Bodies are not exist\n";
		controle.FindSmallestWeightBodyInWater(output);
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}

	BOOST_AUTO_TEST_CASE(can_print_needed_bodies)
	{
		string expectedOutput = R"(Sphere:
	density = 5
	volume = 4188.790205
	mass = 20943.95102
	radius = 10
Cylinder:
	density = 2
	volume = 785.3981634
	mass = 1570.796327
	base radius = 5
	height = 10
)";
		VerifyCommandHandling("Sphere 5 10", "");
		VerifyCommandHandling("Cylinder 2 5 10", "");
		controle.PrintBodies(output);
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}

BOOST_AUTO_TEST_SUITE_END()