#define _USE_MATH_DEFINES
#include <iostream>
#include <Math.h>
#include <amp.h>
#include <algorithm>
#include <vector>

struct EquationRoots4
{
	size_t numRoots;
	double roots[4];
	size_t resolvent1;
	size_t resolvent2;
};

struct InputCoefficient
{
	double b;
	double c;
	double d;
	double e;
};

struct CubicCoefficient
{
	double p;
	double q;
	double r;
	double roots[3];
	size_t numRoots;
};



void ToString(const EquationRoots4 &roots);

class CEquationRoots4
{
public:
	CEquationRoots4();
	size_t numRoots;
	double roots[4];
	size_t resolvent1;
	size_t resolvent2;
	void Solve2(const size_t &number, double a, double b, double c, double *roots, size_t &resolvent);
	void Solve3(double b, double c, double d, CubicCoefficient &cubicCoefficients);
	InputCoefficient Assignation(double a, double b, double c, double d, double e);
	CEquationRoots4 Solve4(double a, double b, double c, double d, double e);

private:
	CubicCoefficient m_cubicCoefficients;
	InputCoefficient m_inputCoefficients;
};
