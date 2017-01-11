#include "stdafx.h"
#include "Solve4.h"
#include <math.h>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;

// 

void CEquationRoots4::Solve2(const size_t &number, double a, double b, double c, double *roots, size_t &resolvent)
{
	double descriminant = pow(b, 2) - 4 * a * c;

	if (descriminant == 0)
	{
		roots[number] = -b / (2 * a);
		resolvent = 1;
		return;
	}
	else if (descriminant > 0)
	{
		roots[number] = (-b - sqrt(descriminant)) / (2 * a);
		roots[number + 1] = (-b + sqrt(descriminant)) / (2 * a);
		resolvent = 2;
		return;
	}
	resolvent = 0;
}

void IntrodutionCoefficientsSolve3(double &q, double &r, double &b, const double c, const double d)
{
	q = (pow(b, 2) - double(3) * c) / double(9), 2;
	r = (b * (double(2) * pow(b, 2) - double(9) * c) + double(27) * d) / double(54);
	b /= 3;
}

void CalculationRootsIfPredeterminedRatioGreater(CubicCoefficient &cubicCoefficients, double q, double r, double b)
{
	cubicCoefficients.roots[0] = double(-2) * sqrt(q) * cos(acos(r / sqrt(pow(q, 3))) / double(3)) - b;
	cubicCoefficients.roots[1] = double(-2) * sqrt(q) * cos((acos(r / sqrt(pow(q, 3))) + 2 * M_PI) / double(3)) - b;
	cubicCoefficients.roots[2] = double(-2) * sqrt(q) * cos((acos(r / sqrt(pow(q, 3))) - 2 * M_PI) / double(3)) - b;
	cubicCoefficients.numRoots = 3;
}

void CalculationRootsIfPredeterminedRatioSmaller(CubicCoefficient &cubicCoefficients, double c, double b, double r, double q)
{
	cubicCoefficients.numRoots = 1;
	if (q == 0)
	{
		cubicCoefficients.roots[0] = -cbrt(c - pow(c, 3) / 27) - b;
	}
	else if (q > 0)
	{
		cubicCoefficients.roots[0] = -2 * ((r > 0) - (r < 0)) * sqrt(q) * cosh(acosh(abs(r) / sqrt(pow(q, 3))) / 3) - b;
	}
	else if (q < 0)
	{
		cubicCoefficients.roots[0] = -2 * ((r > 0) - (r < 0)) * sqrt(abs(q)) * cosh(asinh(abs(r) / sqrt(pow(abs(q), 3))) / 3) - b;
	}
}

void CalculationStandartRoots(CubicCoefficient &cubicCoefficients, double r, double b)
{
	cubicCoefficients.numRoots = 2;
	cubicCoefficients.roots[0] = -2 * cbrt(r) - b;
	cubicCoefficients.roots[1] = cbrt(r) - b;
}

void CEquationRoots4::Solve3(double b, double c, double d, CubicCoefficient &cubicCoefficients)
{
	double q;
	double r;

	// impl func
	IntrodutionCoefficientsSolve3(q, r, b, c, d);

	if (pow(r, 2) < pow(q, 3))
	{
		// impl func
		CalculationRootsIfPredeterminedRatioGreater(cubicCoefficients, q, r, b);
		return;
	}
	if (pow(r, 2) > pow(q, 3))
	{
		
		// impl func
		CalculationRootsIfPredeterminedRatioSmaller(cubicCoefficients, c, b, r, q);
		return;
	}

	// impl func
	CalculationStandartRoots(cubicCoefficients, r, b);

	
}

InputCoefficient CEquationRoots4::Assignation(double a, double b, double c, double d, double e)
{
	InputCoefficient inputCoefficients;
	inputCoefficients.b = b / a;
	inputCoefficients.c = c / a;
	inputCoefficients.d = d / a;
	inputCoefficients.e = e / a;
	return inputCoefficients;
}

CubicCoefficient IntrodutionCoefficientsSolve4(InputCoefficient inputCoefficients)
{
	CubicCoefficient cubicCoefficients;
	cubicCoefficients.p = inputCoefficients.c - ((3 * pow(inputCoefficients.b, 2)) / 8);
	cubicCoefficients.q = inputCoefficients.d + pow(inputCoefficients.b, 3) / 8 - (inputCoefficients.b * inputCoefficients.c) / 2;
	cubicCoefficients.r = inputCoefficients.e - (3 * pow(inputCoefficients.b, 4)) / 256 + (pow(inputCoefficients.b, 2) * inputCoefficients.c) / 16 - (inputCoefficients.d * inputCoefficients.b) / 4;
	return cubicCoefficients;
}

CEquationRoots4 CEquationRoots4::Solve4(double a, double b, double c, double d, double e)
{
	if (a == 0) { throw invalid_argument("Argument 'a' must be not a zero"); };

	

	// implement func
	m_inputCoefficients = Assignation(a, b, c, d, e);

	// impl func
	m_cubicCoefficients = IntrodutionCoefficientsSolve4(m_inputCoefficients);

	Solve3(-m_cubicCoefficients.p / 2, -m_cubicCoefficients.r,
		(m_cubicCoefficients.r * m_cubicCoefficients.p - pow(m_cubicCoefficients.q, 2) / 4) / 2, m_cubicCoefficients);

	double roots[4];
	CEquationRoots4 equationRoots;

	// rename
	Solve2(0, 1, -sqrt(2 * m_cubicCoefficients.roots[m_cubicCoefficients.numRoots - 1] - m_cubicCoefficients.p), (m_cubicCoefficients.q / (2 * sqrt(2 * m_cubicCoefficients.roots[m_cubicCoefficients.numRoots - 1] - m_cubicCoefficients.p))) + m_cubicCoefficients.roots[m_cubicCoefficients.numRoots - 1], roots, equationRoots.resolvent1);
	Solve2(equationRoots.resolvent1, 1, sqrt(2 * m_cubicCoefficients.roots[m_cubicCoefficients.numRoots - 1] - m_cubicCoefficients.p), -(m_cubicCoefficients.q / (2 * sqrt(2 * m_cubicCoefficients.roots[m_cubicCoefficients.numRoots - 1] - m_cubicCoefficients.p))) + m_cubicCoefficients.roots[m_cubicCoefficients.numRoots - 1], roots, equationRoots.resolvent2);
	equationRoots.numRoots = equationRoots.resolvent1 + equationRoots.resolvent2;

	if (equationRoots.numRoots == 0) // pow((3 * c - pow(b, 2)) / double(9), 3) + ((27 * d) + b * ((9 * c) - (2 * pow(b, 2)))) < 0
	{
		throw runtime_error("The equation have not real roots");
	}

	// for_each/transform

//	double k = inputCoefficients.b / 4;

/*	std::transform(begin(roots), end(roots), begin(equationRoots.roots), [k](double val) {
		return val - k;
	});*/



	//transform(begin(equationRoots.roots), end(equationRoots.roots), );
	for (size_t i = 0; i != equationRoots.numRoots; ++i)
	{
		equationRoots.roots[i] = roots[i] - m_inputCoefficients.b / 4;
	}

	return equationRoots;
}

void ToString(const EquationRoots4 &equationRoots)
{
	cout << "Roots of the solve: ";

	//std::copy
	//copy(it->second.begin(), it->second.end(), ostream_iterator<double>(cout, " "));
	for (size_t i = 0; i <= equationRoots.numRoots; ++i)
	{
		cout << equationRoots.roots[i] << ", ";
	}
	cout << "\n";
}