#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../VolumeBodies/Cone.h"
#include <math.h>


struct Cone_
{
    const double expectedBaseRadius = 10;
    const double expectedHeight = 30;
    const double expectedDensity = 2;
    const double expectedVolume = 3138.4510609362032;
    const CCone cone;
    Cone_()
        : cone(expectedDensity, expectedBaseRadius, expectedHeight)
    {}
};

struct ErrorCone_
{
	const double expectedBaseRadius = 10;
	const double expectedHeight = -2;
	const double expectedDensity = 1;
	const double error = -1;
	const CCone cone;
	ErrorCone_()
		: cone(expectedDensity, expectedBaseRadius, expectedHeight)
	{}
};
// Конус
BOOST_FIXTURE_TEST_SUITE(Cone, Cone_)
    // является объемным телом
    BOOST_AUTO_TEST_CASE(is_a_body)
    {
        BOOST_CHECK_NO_THROW(static_cast<const CBody*>(&cone));
    }
    // имеет радиус
    BOOST_AUTO_TEST_CASE(has_a_baseRadius)
    {
        BOOST_CHECK_EQUAL(cone.GetRadius(), expectedBaseRadius);
    }
    // имеет высоту
    BOOST_AUTO_TEST_CASE(has_a_height)
    {
        BOOST_CHECK_EQUAL(cone.GetHeight(), expectedHeight);
    }
    // имеет плотность
    BOOST_AUTO_TEST_CASE(has_a_density)
    {
        BOOST_CHECK_EQUAL(static_cast<const CBody &>(cone).GetDensity(), expectedDensity);
    }
    // имеет объем
    BOOST_AUTO_TEST_CASE(has_a_volume)
    {
        BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cone).GetVolume(), expectedVolume, 0.01);
    }
    // имеет массу
    BOOST_AUTO_TEST_CASE(has_a_mass)
    {
        BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cone).GetMass(), expectedVolume * expectedDensity, 0.01);
    }
    // имеет строковое представление
    BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
    {
        const auto expectedString = R"(Cone:
	density = 2
	volume = 3141.592654
	mass = 6283.185307
	base radius = 10
	height = 30
)";
        BOOST_CHECK_EQUAL(static_cast<const CBody &>(cone).ToString(), expectedString);
    }
BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(ErrorCone, ErrorCone_)
// является объемным телом
BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK_NO_THROW(static_cast<const CBody*>(&cone));
}
// имеет радиус
BOOST_AUTO_TEST_CASE(has_a_baseRadius)
{
	BOOST_CHECK_EQUAL(cone.GetRadius(), expectedBaseRadius);
}
// имеет высоту
BOOST_AUTO_TEST_CASE(has_not_a_height)
{
	BOOST_CHECK_EQUAL(cone.GetHeight(), error);
}
// имеет плотность
BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(cone).GetDensity(), expectedDensity);
}
// имеет объем
BOOST_AUTO_TEST_CASE(has_not_a_volume)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(cone).GetVolume(), error);
}
// имеет массу
BOOST_AUTO_TEST_CASE(has_not_a_mass)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(cone).GetMass(), -1);
}
// имеет строковое представление
BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = "Error. Values must be greater than 0";
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(cone).ToString(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()