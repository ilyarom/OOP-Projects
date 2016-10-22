#include "stdafx.h"
#include "Vector.h"

using namespace std;
using boost::transform;
using namespace std::placeholders;
using namespace boost::phoenix::placeholders;

double GetMinElement(std::vector<double> &numbers)
{
	return *min_element(numbers.begin(), numbers.end());
}

double GetMaxElement(std::vector<double> &numbers)
{
	return *max_element(numbers.begin(), numbers.end());
}

bool isMinNull(double minElement)
{
	if (minElement == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SortVector(vector<double> &numbers)
{
	sort(numbers.begin(), numbers.end());
}

void TransformVector(vector<double> &numbers)
{
	if (numbers.size() != 0)
	{
		double minElement = GetMinElement(numbers);
		double maxElement = GetMaxElement(numbers);
		if (!isMinNull(minElement))
		{
			boost::transform(numbers, numbers.begin(), arg1 * maxElement / minElement);
		}
		else
		{
			return;
		}
	}
	SortVector(&numbers);
}