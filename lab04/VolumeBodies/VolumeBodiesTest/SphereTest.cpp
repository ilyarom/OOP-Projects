#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../VolumeBodies/Sphere.h"
#include <math.h>


struct Sphere_
{
    const double expectedRadius = 10;
    const double expectedDensity = 3;
    const double expectedVolume = 4188.79020;
    const CSphere sphere;
    Sphere_()
        : sphere(expectedDensity, expectedRadius)
    {}
};

struct ErrorSphere_
{
	const double expectedRadius = -10;
	const double expectedDensity = -3.33;
	const double expectedVolume = -1;
	const double error = -1;
	const CSphere sphere;
	ErrorSphere_()
		: sphere(expectedDensity, expectedRadius)
	{}
};
// Сфера
BOOST_FIXTURE_TEST_SUITE(Sphere, Sphere_)
    // является объемным телом
    BOOST_AUTO_TEST_CASE(is_a_body)
    {
        BOOST_CHECK(static_cast<const CBody*>(&sphere));
    }
    // имеет радиус
    BOOST_AUTO_TEST_CASE(has_a_radius)
    {
        BOOST_CHECK_EQUAL(sphere.GetRadius(), expectedRadius);
    }
    // имеет плотность
    BOOST_AUTO_TEST_CASE(has_a_density)
    {
        BOOST_CHECK_EQUAL(static_cast<const CBody &>(sphere).GetDensity(), expectedDensity);
    }
    // имеет объем
    BOOST_AUTO_TEST_CASE(has_a_volume)
    {
        BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(sphere).GetVolume(), expectedVolume, 1e-7);
    }
    // имеет массу
    BOOST_AUTO_TEST_CASE(has_a_mass)
    {
        BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(sphere).GetMass(), expectedVolume * expectedDensity, 1e-7);
    }
    // имеет строковое представление
    BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
    {
        const auto expectedString = R"(Sphere:
	density = 3
	volume = 4188.790205
	mass = 12566.37061
	radius = 10
)";
        BOOST_CHECK_EQUAL(static_cast<const CBody &>(sphere).ToString(), expectedString);
    }
BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(ErrorSphere, ErrorSphere_)
// является объемным телом
BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CBody*>(&sphere));
}
// имеет радиус
BOOST_AUTO_TEST_CASE(has_not_a_radius)
{
	BOOST_CHECK_EQUAL(sphere.GetRadius(), error);
}
// имеет плотность
BOOST_AUTO_TEST_CASE(has_not_a_density)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(sphere).GetDensity(), error);
}
// имеет объем
BOOST_AUTO_TEST_CASE(has_not_a_volume)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(sphere).GetVolume(), error);
}
// имеет массу
BOOST_AUTO_TEST_CASE(has_not_a_mass)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(sphere).GetMass(), error);
}
// имеет строковое представление
BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = "Error. Values must be greater than 0";
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(sphere).ToString(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()