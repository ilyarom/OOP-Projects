#include "stdafx.h"
#include "Athlete.h"

CAthlete::CAthlete(std::string name, double height, double weight)
	: name(name)
	, height(height)
	, weight(weight)
{
}

/*bool isLessName(CAthlete const& left, CAthlete const& right)
{
	return left.name < right.name;
}*/

bool isLessHeight(CAthlete const& left, CAthlete const& right)
{
	return left.height < right.height;
}

bool isLessWeight(CAthlete const& left, CAthlete const& right)
{
	return left.weight < right.weight;
}