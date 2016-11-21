#include "stdafx.h"
#include "Controle.h"

using namespace std;

int main()
{
    vector<shared_ptr<CBody>> bodies;
    CControle controle(bodies, cin, cout);
	cout << "Enter Help for get tips\n";
    while (!cin.eof() && !cin.fail())
    {
        cout << "> ";
		controle.HandleCommand();
    }

    return 0;
}
