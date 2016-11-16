#include "stdafx.h"
#include "Parallelepiped.h"


CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
    : CBody("Parallelepiped", density)
    , CSolidBody(height, 0)
    , m_width(width)
    , m_depth(depth)
{
}

double CParallelepiped::GetWidth() const
{
    return m_width;
}

double CParallelepiped::GetDepth() const
{
    return m_depth;
}

double CParallelepiped::GetVolume() const
{
    return m_width * m_depth * GetHeight();
}

void CParallelepiped::AppendProperties(std::ostream & strm) const
{
    strm << "\twidth = " << GetWidth() << std::endl
        << "\theight = " << GetHeight() << std::endl
        << "\tdepth = " << GetDepth() << std::endl;
}

