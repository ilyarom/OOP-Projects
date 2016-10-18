#include "stdafx.h"
#include "FindAndReplace.h"

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 4)
	{
		cout << "Недостаточно аргументов. Формат входных данных: <искомая строка> <строка для поиска> <строка заменитель>" << "\n";
		return 1;
	}
	string subject = argv[1];
	string search = argv[2];
	if (search == "")
	{
		cout << "Строка для поиска не может быть пустой" << "\n";
		return 1;
	}
	string replace = argv[3];
	cout << FindAndReplace(subject, search, replace) << "\n";
	return 0;
}
