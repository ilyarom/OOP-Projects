#pragma once


struct CAthlete
{
	CAthlete(std::string name, double height, double weight);
	std::string name;
	double height;
	double weight;
};

 

bool isLessWeight(CAthlete const& left, CAthlete const& right);
bool isLessHeight(CAthlete const& left, CAthlete const& right);
bool isLessName(CAthlete const& left, CAthlete const& right);