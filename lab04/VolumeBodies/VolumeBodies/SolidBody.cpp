#include "stdafx.h"
#include "SolidBody.h"


CSolidBody::CSolidBody(double height, double radius)
    : m_height(height)
	, m_radius(radius)
{
}

double CSolidBody::GetHeight() const
{
    return m_height;
}

double CSolidBody::GetRadius() const
{
	return m_radius;
}

CSolidBody::~CSolidBody()
{
}