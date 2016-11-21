#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../VolumeBodies/Cylinder.h"
#include <math.h>


struct Cylinder_
{
    const double expectedRadius = 42.8;
    const double expectedHeight = 124.0;
    const double expectedDensity = 3.8;
    const double expectedVolume = 713607.0;
    const CCylinder cylinder;
    Cylinder_()
        : cylinder(expectedDensity, expectedRadius, expectedHeight)
    {}
};

struct ErrorCylinder_
{
	const double expectedRadius = -5;
	const double expectedHeight = 2;
	const double expectedDensity = 4;
	const double expectedVolume = -1;
	const CCylinder cylinder;
	ErrorCylinder_()
		: cylinder(expectedDensity, expectedRadius, expectedHeight)
	{}
};
// Цилиндр
BOOST_FIXTURE_TEST_SUITE(Cylinder, Cylinder_)
// является объемным телом
BOOST_AUTO_TEST_CASE(is_a_body)
{
    BOOST_CHECK(static_cast<const CBody*>(&cylinder));
}
// имеет радиус
BOOST_AUTO_TEST_CASE(has_a_radius)
{
    BOOST_CHECK_EQUAL(cylinder.GetRadius(), expectedRadius);
}
// имеет высоту
BOOST_AUTO_TEST_CASE(has_a_height)
{
    BOOST_CHECK_EQUAL(cylinder.GetHeight(), expectedHeight);
}
// имеет плотность
BOOST_AUTO_TEST_CASE(has_a_density)
{
    BOOST_CHECK_EQUAL(static_cast<const CBody &>(cylinder).GetDensity(), expectedDensity);
}
// имеет объем
BOOST_AUTO_TEST_CASE(has_a_volume)
{
    BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cylinder).GetVolume(), expectedVolume, 1e-7);
}
// имеет массу
BOOST_AUTO_TEST_CASE(has_a_mass)
{
    BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cylinder).GetMass(), expectedVolume * expectedDensity, 1e-7);
}
// имеет строковое представление
BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Cylinder:
	density = 3.8
	volume = 713606.9907
	mass = 2711706.565
	base radius = 42.8
	height = 124
)";
    BOOST_CHECK_EQUAL(static_cast<const CBody &>(cylinder).ToString(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(ErrorCylinder, ErrorCylinder_)
// является объемным телом
BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CBody*>(&cylinder));
}
// имеет радиус
BOOST_AUTO_TEST_CASE(has_not_a_radius)
{
	BOOST_CHECK_EQUAL(cylinder.GetRadius(), -1);
}
// имеет высоту
BOOST_AUTO_TEST_CASE(has_a_height)
{
	BOOST_CHECK_EQUAL(cylinder.GetHeight(), expectedHeight);
}
// имеет плотность
BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(cylinder).GetDensity(), expectedDensity);
}
// имеет объем
BOOST_AUTO_TEST_CASE(has_not_a_volume)
{
	BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cylinder).GetVolume(), -1, 1e-7);
}
// имеет массу
BOOST_AUTO_TEST_CASE(has_not_a_mass)
{
	BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cylinder).GetMass(), -1, 1e-7);
}
// имеет строковое представление
BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = "Error. Values must be greater than 0";
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(cylinder).ToString(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()