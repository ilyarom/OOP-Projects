#pragma once
#include "Body.h"
#include "SolidBody.h"

class CSphere final
    : public CBody
    , public CSolidBody
{
public:
    CSphere(double density, double radius);

    virtual double GetVolume() const override;

protected:
    void AppendProperties(std::ostream & strm) const override;
};
