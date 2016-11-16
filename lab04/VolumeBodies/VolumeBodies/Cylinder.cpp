#include "stdafx.h"
#include "Cylinder.h"


CCylinder::CCylinder(double density, double baseRadius, double height)
	: CBody("Cylinder", density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
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
	else
	{
		strm << "Error. Values must be greater than 0";
	}
}

