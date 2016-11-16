#pragma once
#include "Body.h"
#include "SolidBody.h"

class CParallelepiped final
    : public CBody
    , public CSolidBody
{
public:
    CParallelepiped(double width, double height, double depth, double density);

    double GetWidth() const;
    double GetDepth() const;
    virtual double GetVolume() const override;
protected:
    void AppendProperties(std::ostream & strm) const override;
private:
    double m_width;
    double m_depth;
};

