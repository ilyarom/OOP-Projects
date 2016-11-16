#include "stdafx.h"
#include "Controle.h"

using namespace std;

int main()
{
    vector<shared_ptr<CBody>> bodies;
    CControle controle(bodies, cin, cout);
    while (!cin.eof() && !cin.fail())
    {
		cout << "Enter Help for get tips";
        cout << "> ";
        if (!controle.HandleCommand())
        {
            cout << "Unknown command\n";
        }
    }

    return 0;
}
