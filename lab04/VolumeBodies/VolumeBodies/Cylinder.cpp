#include "stdafx.h"
#include "Cylinder.h"


CCylinder::CCylinder(double density, double baseRadius, double height)
    : CBody("Cylinder", density)
    , CSolidBody(height, baseRadius)
{
}

double CCylinder::GetVolume() const
{
    return M_PI * pow(GetRadius(), 2) * GetHeight();
}

void CCylinder::AppendProperties(std::ostream & strm) const
{
    strm << "\tradius = " << GetRadius() << std::endl
        << "\theight = " << GetHeight() << std::endl;
}

