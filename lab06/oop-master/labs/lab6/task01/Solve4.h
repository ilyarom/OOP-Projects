#define _USE_MATH_DEFINES
#include <iostream>
#include <Math.h>
#include <amp.h>

struct EquationRoots4
{
	size_t numRoots;
	double roots[4];
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

size_t GetNumOfRoots(const size_t &number, double a, double b, double c, double* roots);
void Solve3(double b, double c, double d, CubicCoefficient &cubicCoefficients);
EquationRoots4 Solve4(double a, double b, double c, double d, double e);
void ToString(const EquationRoots4 &roots);
