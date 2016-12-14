#include "stdafx.h"
#include "Rational.h"
#include <utility>
#include <stdexcept>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator must not be equal to zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
//////////////////////////////////////////////////////////////////////////
double CRational::ToDouble() const
{
	return double(GetNumerator()) / GetDenominator();
}

std::pair<int, CRational> CRational::ToCompoundFraction() const 
{
	std::pair<int, CRational> pair = std::make_pair(int(ToDouble()), CRational(m_numerator % m_denominator, m_denominator));
	return pair;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////

CRational const CRational::operator+() const
{
	return *this;
}

CRational const CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
//////////////////////////////////////////////////////////////////////////
CRational const operator+(const CRational &first, const CRational &second)
{
	return CRational(first.GetNumerator() * second.GetDenominator() + second.GetNumerator() * first.GetDenominator(), 
			first.GetDenominator() * second.GetDenominator());
}


//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////
CRational const operator-(const CRational &first, const CRational &second)
{
	return first + (-second);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
//////////////////////////////////////////////////////////////////////////
CRational CRational::operator+=(const CRational &second)
{
	if (second.GetNumerator() == 0)
    {
		return *this;
	}
	m_numerator = m_numerator * second.GetDenominator() + second.GetNumerator() * m_denominator;
	m_denominator = m_denominator * second.GetDenominator();
	Normalize();
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////
CRational CRational::operator-=(const CRational &second)
{
	return *this += (second);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////
CRational const operator*(const CRational &first, const CRational &second)
{
	return CRational(first.GetNumerator() * second.GetNumerator(), first.GetDenominator() * second.GetDenominator());
}


//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////
CRational const operator/(const CRational &first, const CRational &second)
{
	return CRational(first.GetNumerator() * second.GetDenominator(), first.GetDenominator() * second.GetNumerator());
}



//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////
CRational CRational::operator*=(const CRational &second)
{
	*this = *this * second;
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////
CRational CRational::operator/=(const CRational &second)
{
	return *this *= (1 / second);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////
bool const operator==(const CRational &first, const CRational &second)
{
	return (first.GetNumerator() == second.GetNumerator() &&
		(first.GetDenominator() == second.GetDenominator()));
}

bool const operator!=(const CRational &first, const CRational &second)
{
	return !(first == second);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////
bool const operator<(const CRational &first, const CRational &second)
{
	return first.GetNumerator() * second.GetDenominator() < second.GetNumerator() * first.GetDenominator();
}

bool const operator<=(const CRational &first, const CRational &second)
{
	return !(first > second);
}

bool const operator>(const CRational &first, const CRational &second)
{
	return first.GetNumerator() * second.GetDenominator() > second.GetNumerator() * first.GetDenominator();
}

bool const operator>=(const CRational &first, const CRational &second)
{
	return !(first < second);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// TODO: 15. Реализовать дополнительное задание
//////////////////////////////////////////////////////////////////////////
