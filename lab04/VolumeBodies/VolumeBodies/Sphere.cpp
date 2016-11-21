#include "stdafx.h"
#include "Sphere.h"

CSphere::CSphere(double density, double radius)
    : CBody("Sphere", density)
    , m_radius(radius)
{
}

double CSphere::GetRadius() const
{
	if (m_radius > 0)
	{
		return m_radius;
	}
	return -1;
}

double CSphere::GetVolume()const
{
	if (GetRadius() > 0)
	{
		return (4 / double(3)) * pow(GetRadius(), 3) * M_PI;
	}
	return -1;
}

void CSphere::AppendProperties(std::ostream & strm) const
{
	if (GetRadius() != -1)
	{
		strm << "\tradius = " << GetRadius() << std::endl;
	}
	else
	{
		strm << "Error. Values must be greater than 0";
	}
}
