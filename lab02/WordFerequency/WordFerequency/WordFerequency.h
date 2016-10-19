#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <algorithm> 
#include <sstream>
#include <map>

typedef std::map<std::string, std::size_t> WordFerequency;

WordFerequency CalculateWordArchive(std::istream &input);