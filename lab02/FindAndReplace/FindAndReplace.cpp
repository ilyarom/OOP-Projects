// FindAndReplace.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

string FindAndReplace(string const& subject, string const& search, string  const& replace)
{
	size_t pos = 0;
	string resSubject;
	resSubject = subject;
	pos = resSubject.find(search, pos);
	while (pos != string::npos)
	{
		resSubject.replace(pos, search.length(), replace);
		pos = pos + replace.length();
		pos = resSubject.find(search, pos - 1);
	}
	return resSubject;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 4)
	{
		cout << "������������ ����������. ������ ������� ������: <������� ������> <������ ��� ������> <������ ����������>" << "\n";
		return 1;
	}
	string subject = argv[1];
	string search = argv[2];
	string replace = argv[3];
	cout << FindAndReplace(subject, search, replace) << "\n";
    return 0;
}

