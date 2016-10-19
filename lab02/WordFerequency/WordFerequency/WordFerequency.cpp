#include "stdafx.h"
#include "..\WordFerequency\WordFerequency.h"

using namespace std;

WordFerequency CalculateWordArchive(istream &input)
{
	WordFerequency wordArchive;
	string word;
	while (!input.eof())
	{
		word = "";
	    input >> word;
		auto search = wordArchive.count(word);
		if (search)
		{
			wordArchive[word]++;
		}
		else if (!input.eof())
		{
			wordArchive.insert(pair<string, size_t>(word, 1));
		}
	}
	return wordArchive;
}