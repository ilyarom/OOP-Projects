// WordFerequency.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "WordFerequency.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");	
	WordFerequency wordArchive;
	wordArchive = CalculateWordArchive(cin);
	for (auto it = wordArchive.begin(); it != wordArchive.end(); ++it)
	{
		cout << (*it).first << " -> " << (*it).second << endl;
	}
    return 0;
}

