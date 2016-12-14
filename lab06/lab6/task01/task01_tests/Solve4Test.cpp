#include "stdafx.h"
#include "../Solve4.h"

using namespace std;

void CheckEqualEquations(EquationRoots4 sampleEquation, EquationRoots4 resultRoots)
{
	for (size_t i = 0; i < sampleEquation.numRoots; ++i)
	{
		BOOST_CHECK_CLOSE_FRACTION(resultRoots.roots[i], sampleEquation.roots[i], 1e-3);
	}
}

BOOST_AUTO_TEST_SUITE(check_function_GetNumOfRoots)

BOOST_AUTO_TEST_CASE(can_find_appropriate_descriminant)
{
	double roots[4];
	BOOST_CHECK_EQUAL(GetNumOfRoots(0, 1, -1, 1, roots), 0);
	BOOST_CHECK_EQUAL(GetNumOfRoots(1, 1, -2, 1, roots), 1);
	BOOST_CHECK_EQUAL(roots[1], 1);
	BOOST_CHECK_EQUAL(GetNumOfRoots(2, 4, -5, 1, roots), 2);
	BOOST_CHECK_EQUAL(roots[2], 0.25);
	BOOST_CHECK_EQUAL(roots[3], 1);

}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(check_function_Solve3)

BOOST_AUTO_TEST_CASE(can_solve_equation_with_real_roots)
{
	CubicCoefficient sampleEquation;

	sampleEquation.numRoots = 3;
	sampleEquation.roots[0] = -5;
	sampleEquation.roots[1] = -0.38196601125;
	sampleEquation.roots[2] = -2.6180339887498953;

	CubicCoefficient resultRoots;
	Solve3(8, 16, 5, resultRoots);

	cout << resultRoots.roots[0] << "\n";
	cout << resultRoots.roots[1] << "\n";
	cout << resultRoots.roots[2] << "\n";
}


BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(check_function_Solve4)
BOOST_AUTO_TEST_CASE(can_solve_equation_with_real_roots)
{
	EquationRoots4 sampleEquation;

	sampleEquation.numRoots = 4;
	sampleEquation.roots[0] = -4;
	sampleEquation.roots[1] = 5;
	sampleEquation.roots[2] = -6;
	sampleEquation.roots[3] = 3;

	EquationRoots4 resultRoots = Solve4(3, 6, -123, -126, 1080);

	CheckEqualEquations(sampleEquation, resultRoots);

}

BOOST_AUTO_TEST_CASE(can_solve_equation_with_real_roots_fractional)
{
	EquationRoots4 sampleEquation;

	sampleEquation.numRoots = 4;
	sampleEquation.roots[0] = -2.236067977;
	sampleEquation.roots[1] = 2.236067977;
	sampleEquation.roots[2] = -3.732050807;
	sampleEquation.roots[3] = -0.26794919;

	EquationRoots4 resultRoots = Solve4(1, 4, -4, -20, -5);

	CheckEqualEquations(sampleEquation, resultRoots);

}

BOOST_AUTO_TEST_CASE(can_not_solve_equation_if_a_equal_an_zero)
{
	BOOST_REQUIRE_THROW(Solve4(0, 4, 3, 2, 1), invalid_argument);
}

BOOST_AUTO_TEST_CASE(can_not_solve_equation_if_real_roots_do_not_exist)
{
	BOOST_REQUIRE_THROW(Solve4(5, 4, 3, 2, 1), runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()