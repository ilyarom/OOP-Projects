#include "stdafx.h"
#include "Body.h"

CBody::CBody(const std::string & type, double density)
    : m_density(density)
    , m_type(type)
{
}

CBody::~CBody()
{
}

double CBody::GetDensity()const
{
	if (m_density > 0)
	{
		return m_density;
	}
	return -1;
}

double CBody::GetMass()const
{
	if ((GetVolume() != -1) && (GetDensity() != -1))
	{
		return GetVolume() * GetDensity();
	}
	return -1;
}

std::string CBody::ToString()const
{
    std::ostringstream strm;
	if ((GetDensity() != -1) && (GetVolume() != -1))
	{
		strm << m_type << ":" << std::endl << std::setprecision(10)
			<< "\tdensity = " << GetDensity() << std::endl
			<< "\tvolume = " << GetVolume() << std::endl
			<< "\tmass = " << GetMass() << std::endl;
	}
    AppendProperties(strm);
    return strm.str();
}
