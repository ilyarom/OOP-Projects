#include "stdafx.h"
#include "../WordFerequency/WordFerequency.h"

using namespace std;

WordFerequency CalculateWordArchive(istream &input)
{
	WordFerequency WordArchive;
	string word;
	while (!input.eof())
	{
		word = "";
		input >> word;
		auto search = WordArchive.count(word);
		if (search)
		{
			WordArchive[word]++;
		}
		else if (!input.eof())
		{
			WordArchive.insert(pair<string, size_t>(word, 1));
		}
	}
	return WordArchive;
}