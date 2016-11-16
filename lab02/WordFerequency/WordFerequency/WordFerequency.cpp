#include "stdafx.h"
#include "..\WordFerequency\WordFerequency.h"

using namespace std;

WordFerequency CalculateWordArchive(istream &input)
{
	WordFerequency wordArchive;
	string word;
	while (input >> word)
	{
		++wordArchive[word];
	}
	return wordArchive;
}