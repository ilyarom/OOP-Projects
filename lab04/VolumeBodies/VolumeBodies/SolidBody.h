pragma once

class CSolidBody
{
public:
    CSolidBody(double height, double radius);

    double GetHeight() const;
	double GetRadius() const;

    virtual ~CSolidBody();

private:
    double m_height;
	double m_radius;
};
