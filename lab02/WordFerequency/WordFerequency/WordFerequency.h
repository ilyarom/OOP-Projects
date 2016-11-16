#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <algorithm> 
#include <sstream>
#include <map>

using WordFerequency = std::map<std::string, std::size_t>;

WordFerequency CalculateWordArchive(std::istream &input);