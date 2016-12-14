#include "stdafx.h"
#include "Cone.h"



CCone::CCone(double density, double baseRadius, double height)
	: CBody("Cone", density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
}

double CCone::GetHeight() const
{
	if (m_height > 0)
	{
		return m_height;
	}
	return -1;
}

double CCone::GetRadius() const
{
	if (m_baseRadius > 0)
	{
		return m_baseRadius;
	}
	return -1;
}

double CCone::GetVolume() const
{
	if ((GetRadius() > 0) && (GetHeight() > 0))
	{
		return M_PI * pow(GetRadius(), 2) * GetHeight() * 1 / double(3);
	}
	return -1;
}

void CCone::AppendProperties(std::ostream & strm) const
{
	if ((GetRadius() != -1) && (GetHeight() != -1))
	{
		strm << "\tbase radius = " << GetRadius() << std::endl
			<< "\theight = " << GetHeight() << std::endl;
	}
}
