#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../VolumeBodies/Parallelepiped.h"
#include <math.h>


struct Parallelepiped_
{
    const double expectedWidth = 5;
    const double expectedHeight = 10;
    const double expectedDepth = 20;
    const double expectedDensity = 2;
    const double expectedVolume = 1000;
    const CParallelepiped parallelepiped;
    Parallelepiped_()
        : parallelepiped(expectedDensity, expectedWidth, expectedHeight, expectedDepth)
    {}
};

struct ErrorParallelepiped_
{
	const double expectedWidth = -5;
	const double expectedHeight = 10;
	const double expectedDepth = -20;
	const double expectedDensity = -2;
	const double expectedVolume = -1;
	const double error = -1;
	const CParallelepiped parallelepiped;
	ErrorParallelepiped_()
		: parallelepiped(expectedDensity, expectedWidth, expectedHeight, expectedDepth)
	{}
};
// —фера
BOOST_FIXTURE_TEST_SUITE(parallelepiped, Parallelepiped_)
    // €вл€етс€ объемным телом
    BOOST_AUTO_TEST_CASE(is_a_body)
    {
        BOOST_CHECK(static_cast<const CBody*>(&parallelepiped));
    }
    // имеет ширину
    BOOST_AUTO_TEST_CASE(has_a_width)
    {
        BOOST_CHECK_EQUAL(parallelepiped.GetWidth(), expectedWidth);
    }
    // имеет высоту
    BOOST_AUTO_TEST_CASE(has_a_height)
    {
        BOOST_CHECK_EQUAL(parallelepiped.GetHeight(), expectedHeight);
    }
    // имеет глубину
    BOOST_AUTO_TEST_CASE(has_a_depth)
    {
        BOOST_CHECK_EQUAL(parallelepiped.GetDepth(), expectedDepth);
    }
    // имеет плотность
    BOOST_AUTO_TEST_CASE(has_a_density)
    {
        BOOST_CHECK_EQUAL(static_cast<const CBody &>(parallelepiped).GetDensity(), expectedDensity);
    }
    // имеет объем
    BOOST_AUTO_TEST_CASE(has_a_volume)
    {
        BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(parallelepiped).GetVolume(), expectedVolume, 1e-7);
    }
    // имеет массу
    BOOST_AUTO_TEST_CASE(has_a_mass)
    {
        BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(parallelepiped).GetMass(), expectedVolume * expectedDensity, 1e-7);
    }
    // имеет строковое представление
    BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
    {
        const auto expectedString = R"(Parallelepiped:
	density = 2
	volume = 1000
	mass = 2000
	width = 5
	height = 10
	depth = 20
)";
        BOOST_CHECK_EQUAL(static_cast<const CBody &>(parallelepiped).ToString(), expectedString);
    }
BOOST_AUTO_TEST_SUITE_END()

// —фера
BOOST_FIXTURE_TEST_SUITE(ErrorParallelepiped, ErrorParallelepiped_)
// €вл€етс€ объемным телом
BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CBody*>(&parallelepiped));
}
// имеет ширину
BOOST_AUTO_TEST_CASE(has_not_a_width)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetWidth(), error);
}
// имеет высоту
BOOST_AUTO_TEST_CASE(has_a_height)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetHeight(), expectedHeight);
}
// имеет глубину
BOOST_AUTO_TEST_CASE(has_not_a_depth)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetDepth(), error);
}
// имеет плотность
BOOST_AUTO_TEST_CASE(has_not_a_density)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(parallelepiped).GetDensity(), error);
}
// имеет объем
BOOST_AUTO_TEST_CASE(has_not_a_volume)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(parallelepiped).GetVolume(), error);
}
// имеет массу
BOOST_AUTO_TEST_CASE(has_not_a_mass)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(parallelepiped).GetMass(), error);
}
// имеет строковое представление
BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = "Error. Values must be greater than 0";
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(parallelepiped).ToString(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()