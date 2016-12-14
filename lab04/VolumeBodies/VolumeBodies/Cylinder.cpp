#include "stdafx.h"
#include "Cylinder.h" 
#include <algorithm>


CCylinder::CCylinder(double density, double baseRadius, double height)
	: CBody("Cylinder", density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
	if (density < 0 || baseRadius < 0 || height < 0)
	{
		throw std::invalid_argument("invalid args");
	}
}

double CCylinder::GetHeight() const
{
	if (m_height > 0)
	{
		return m_height;
	}
	return -1;
}

double CCylinder::GetRadius() const
{
	if (m_baseRadius > 0)
	{
		return m_baseRadius;
	}
	return -1;
}

double CCylinder::GetVolume() const
{
	if ((GetRadius() != -1) && (GetHeight() != -1))
	{
		return M_PI * pow(GetRadius(), 2) * GetHeight();
	}
	return -1;
   
}

void CCylinder::AppendProperties(std::ostream & strm) const
{
	if ((GetRadius() != -1) && (GetHeight() != -1))
	{
		strm << "\tbase radius = " << GetRadius() << std::endl
			<< "\theight = " << GetHeight() << std::endl;
	}
}

