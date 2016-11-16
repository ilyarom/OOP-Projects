#pragma once
#include "Body.h"
#include "SolidBody.h"

class CCone final
    : public CBody
    , public CSolidBody
{
public:
    CCone(double density, double radius, double height);

    double GetVolume() const override;

protected:
    void AppendProperties(std::ostream & strm) const override;
};

