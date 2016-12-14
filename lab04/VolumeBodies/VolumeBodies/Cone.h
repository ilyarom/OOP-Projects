#pragma once
#include "Body.h"

class CCone
    : public CBody
{
public:
    CCone(double density, double baseRadius, double height);
    virtual double GetVolume() const override;
	double GetHeight() const;
	double GetRadius() const;

protected:
    void AppendProperties(std::ostream & strm) const override;

private:
	double m_height;
	double m_baseRadius;
	double m_density;
};