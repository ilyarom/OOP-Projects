#include "stdafx.h"
#include "../WordFerequency/WordFerequency.h"

using namespace std;

WordFerequency CalculateWordArchive(istream &input)
{
	WordFerequency wordArchive;
	string word;
	while (input >> word)
	{
		transform(word.begin(), word.end(), word.begin(), tolower);
		++wordArchive[word];
	}
	return wordArchive;
}