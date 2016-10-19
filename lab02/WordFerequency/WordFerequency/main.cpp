// WordFerequency.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "WordFerequency.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");	
	WordFerequency WordArchive;
	WordArchive = CalculateWordArchive(cin);
	for (auto it = WordArchive.begin(); it != WordArchive.end(); ++it)
	{
		cout << (*it).first << " -> " << (*it).second << endl;
	}
    return 0;
}

