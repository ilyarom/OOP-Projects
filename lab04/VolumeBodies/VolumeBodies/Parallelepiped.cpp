#include "stdafx.h"
#include "Parallelepiped.h"


CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
    : CBody("Parallelepiped", density)
    , m_width(width)
	, m_height(height)
    , m_depth(depth)
{
}

double CParallelepiped::GetWidth() const
{
	if (m_width > 0)
	{
		return m_width;
	}
	return -1;
   
}

double CParallelepiped::GetDepth() const
{
	if (m_depth > 0)
	{
		return m_depth;
	}
	return -1;
}

double CParallelepiped::GetHeight() const
{
	if (m_height > 0)
	{
		return m_height;
	}
}

double CParallelepiped::GetVolume() const
{
	if ((GetWidth() != -1) && (GetHeight() != -1) && (GetDepth() != -1))
	{
		return GetWidth() * GetDepth() * GetHeight();
	}
    
}

void CParallelepiped::AppendProperties(std::ostream & strm) const
{
	if ((GetWidth() != -1) && (GetHeight() != -1) && (GetDepth() != -1))
	{
		strm << "\twidth = " << GetWidth() << std::endl
			<< "\theight = " << GetHeight() << std::endl
			<< "\tdepth = " << GetDepth() << std::endl;
	}
	else
	{
		strm << "Error. Values must be greater than 0";
	}
}

