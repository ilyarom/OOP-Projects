#pragma once

class CRoundBody
{
public:
    CRoundBody(double radius);

    double GetRadius() const;
    
    virtual ~CRoundBody();

private:
    double m_radius;
};
