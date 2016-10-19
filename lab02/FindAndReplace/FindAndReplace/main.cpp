#include "stdafx.h"
#include "FindAndReplace.h"

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 4)
	{
		cout << "Not enough arguments.The format of the input data : <search string> <string for searching> <string replacer>" << "\n";
		return 1;
	}
	string subject = argv[1];
	string search = argv[2];
	if (search == "")
	{
		cout << "Search term can't be empty" << "\n";
		return 1;
	}
	string replace = argv[3];
	cout << FindAndReplace(subject, search, replace) << "\n";
	return 0;
}
