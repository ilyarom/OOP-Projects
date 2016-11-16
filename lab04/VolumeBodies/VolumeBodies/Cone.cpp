#include "stdafx.h"
#include "Cone.h"



CCone::CCone(double density, double baseRadius, double height)
    : CBody("Cone", density)
    , CSolidBody(height, baseRadius)
{
}

double CCone::GetVolume() const
{
    return M_PI * pow(GetRadius(), 2) * GetHeight() * 1 / double(3);
}

void CCone::AppendProperties(std::ostream & strm) const
{
    strm << "\tbase radius = " << GetRadius() << std::endl
        << "\theight = " << GetHeight() << std::endl;
}
