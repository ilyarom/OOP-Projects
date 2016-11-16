#pragma once
#include "Body.h"

class CSphere final
    : public CBody
{
public:
    CSphere(double density, double radius);

    virtual double GetVolume() const override;
	double GetRadius() const;

protected:
    void AppendProperties(std::ostream & strm) const override;
private:
	double m_radius;
};


