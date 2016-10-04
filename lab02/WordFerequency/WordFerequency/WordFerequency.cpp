// WordFerequency.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <map>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	map <string, size_t> WordArchive;
	string word;
	while (!cin.eof())
	{
		word = "";
		cin >> word;
		auto search = WordArchive.count(word);
		if (search)
		{
			WordArchive[word]++;
		}
		else if (!cin.eof())
		{
			WordArchive.insert(pair<string, size_t>(word, 1));
		}
	}
	for (auto it = WordArchive.begin(); it != WordArchive.end(); ++it)
	{
		cout << (*it).first << " : " << (*it).second << endl;
	}
    return 0;
}

