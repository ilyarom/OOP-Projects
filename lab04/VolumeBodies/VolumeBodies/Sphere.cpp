#include "stdafx.h"
#include "Sphere.h"

CSphere::CSphere(double density, double radius)
    : CBody("Sphere", density)
    , CSolidBody(0, radius)
{
}

double CSphere::GetVolume()const
{
    return (4 / double(3)) * pow(GetRadius(), 3) * M_PI;
}

void CSphere::AppendProperties(std::ostream & strm) const
{
    strm << "\tradius = " << GetRadius() << std::endl;
}
