#pragma once
#include "Body.h"

class CCylinder final
    : public CBody
{
public:
    CCylinder(double density, double radius, double height);

    double GetVolume() const override;
	double GetHeight() const;
	double GetRadius() const;

protected:
    void AppendProperties(std::ostream & strm) const override;

private:
	double m_height;
	double m_baseRadius;
};

