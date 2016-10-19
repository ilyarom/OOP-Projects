#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm> 
#include <vector>
#include <functional>
#include <math.h>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;

double GetMinElement(std::vector<double> &numbers);

double GetMaxElement(std::vector<double> &numbers);

void CalculateVector(vector<double> &numbers);