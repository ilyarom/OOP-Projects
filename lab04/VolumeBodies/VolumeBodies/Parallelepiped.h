#pragma once
#include "Body.h"

class CParallelepiped
    : public CBody
{
public:
    CParallelepiped(double width, double height, double depth, double density);

    double GetWidth() const;
    double GetDepth() const;
	double GetHeight() const;
    virtual double GetVolume() const override;
protected:
    void AppendProperties(std::ostream & strm) const override;
private:
    double m_width;
    double m_depth;
	double m_height;
};

