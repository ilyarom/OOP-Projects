#include "stdafx.h"
#include "Solve4.h"
#include <math.h>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;



size_t GetNumOfRoots(const size_t &number, double a, double b, double c, double* roots)
{
	double descriminant = pow(b, 2) - 4 * a * c;

	if (descriminant == 0)
	{
		roots[number] = -b / (2 * a);

		return 1;
	}
	if (descriminant > 0)
	{
		roots[number] = (-b - sqrt(descriminant)) / (2 * a);
		roots[number + 1] = (-b + sqrt(descriminant)) / (2 * a);
		return 2;
	}
	return 0;
}

/*void Solve3(double b, double c, double d, CubicCoefficient &cubicCoefficients)
{
	//double discriminant1 = pow(b, 2) - (double(3) * c);
	//double discriminant2 = 2 * pow(b, 3) - double(9) * b * c + double(27) * d;
	//double discriminant = (pow(discriminant2, 2) - (4 * pow(discriminant1, 3))) / double(-27);
	double q = (double(3) * c - pow(b, 2)) / double(9);
	double r = (b * (double(2) * pow(b, 2) - double(9) * c) + double(27) * d) / double(54);
	double discriminant = pow(q, 3) + pow(r, 2);
	double s = r + sqrt(discriminant);
	double t = r - sqrt(discriminant);
	double term1 = sqrt(double(3)) * ((s - t) / double(2));
	double r13 = 2 * sqrt(q);
	cubicCoefficients.roots[0] = (-term1 + (r13 * cos(pow(q, 3) / double(3))));
	cubicCoefficients.roots[1]= (-term1 + (r13 * cos(pow(q, 3) + 2 * M_PI / double(3))));
	cubicCoefficients.roots[2] = (-term1 + (r13 * cos(pow(q, 3) + 4 * M_PI / double(3))));
	cubicCoefficients.numRoots = 3;
}
*/
void Solve3(double b, double c, double d, CubicCoefficient &cubicCoefficients)
{
	double q;
	double r;

	q = (pow(b, 2) - double(3) * c) / double(9), 2;
	r = (b * (double(2) * pow(b, 2) - double(9) * c) + double(27) * d) / double(54);
	b /= 3;

	if (pow(r, 2) < pow(q, 3))
	{
		cubicCoefficients.roots[0] = double(-2) * sqrt(q) * cos(acos(r / sqrt(pow(q, 3))) / double(3)) - b;
		cubicCoefficients.roots[1] = double(-2) * sqrt(q) * cos((acos(r / sqrt(pow(q, 3))) + 2 * M_PI) / double(3)) - b;
		cubicCoefficients.roots[2] = double(-2) * sqrt(q) * cos((acos(r / sqrt(pow(q, 3))) - 2 * M_PI) / double(3)) - b;
		cubicCoefficients.numRoots = 3;
		return;
	}
	if (pow(r, 2) > pow(q, 3))
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
		return;
	}

	cubicCoefficients.numRoots = 2;
	cubicCoefficients.roots[0] = -2 * cbrt(r) - b;
	cubicCoefficients.roots[1] = cbrt(r) - b;

	
}
EquationRoots4 Solve4(double a, double b, double c, double d, double e)
{
	if (a == 0) { throw invalid_argument("Argument 'a' must be not a zero"); };

	InputCoefficient inputCoefficients;
	CubicCoefficient cubicCoefficients;

	inputCoefficients.b = b / a;
	inputCoefficients.c = c / a;
	inputCoefficients.d = d / a;
	inputCoefficients.e = e / a;

	cubicCoefficients.p = inputCoefficients.c - ((3 * pow(inputCoefficients.b, 2)) / 8);
	cubicCoefficients.q = inputCoefficients.d + pow(inputCoefficients.b, 3) / 8 - (inputCoefficients.b * inputCoefficients.c) / 2;
	cubicCoefficients.r = inputCoefficients.e - (3 * pow(inputCoefficients.b, 4)) / 256 + (pow(inputCoefficients.b, 2) * inputCoefficients.c) / 16 - (inputCoefficients.d * inputCoefficients.b) / 4;

	Solve3(-cubicCoefficients.p / 2, -cubicCoefficients.r,
		(cubicCoefficients.r * cubicCoefficients.p - pow(cubicCoefficients.q, 2) / 4) / 2, cubicCoefficients);

	double roots[4];
	EquationRoots4 equationRoots;

	size_t numOfRoots1 = GetNumOfRoots(0, 1, -sqrt(2 * cubicCoefficients.roots[cubicCoefficients.numRoots - 1] - cubicCoefficients.p), (cubicCoefficients.q / (2 * sqrt(2 * cubicCoefficients.roots[cubicCoefficients.numRoots - 1] - cubicCoefficients.p))) + cubicCoefficients.roots[cubicCoefficients.numRoots - 1], roots);
	equationRoots.numRoots = numOfRoots1 + GetNumOfRoots(numOfRoots1, 1, sqrt(2 * cubicCoefficients.roots[cubicCoefficients.numRoots - 1] - cubicCoefficients.p), -(cubicCoefficients.q / (2 * sqrt(2 * cubicCoefficients.roots[cubicCoefficients.numRoots - 1] - cubicCoefficients.p))) + cubicCoefficients.roots[cubicCoefficients.numRoots - 1], roots); // складываем две резольвенты

	if (equationRoots.numRoots == 0) // pow((3 * c - pow(b, 2)) / double(9), 3) + ((27 * d) + b * ((9 * c) - (2 * pow(b, 2)))) < 0
	{
		throw invalid_argument("The equation have not real roots");
	}


	for (size_t i = 0; i != equationRoots.numRoots; ++i)
	{
		equationRoots.roots[i] = roots[i] - inputCoefficients.b / 4;
	}

	return equationRoots;
}

void ToString(const EquationRoots4 &equationRoots)
{
	cout << "Roots of the solve: ";

	for (size_t i = 0; i <= equationRoots.numRoots; ++i)
	{
		cout << equationRoots.roots[i] << ", ";
	}
	cout << "\n";
}