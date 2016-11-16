#include "stdafx.h"
#include "Controle.h"

using namespace std;

int main()
{
    vector<shared_ptr<CBody>> bodies;
    CControle controle(bodies, cin, cout);
    while (!cin.eof() && !cin.fail())
    {
        cout << "> ";
        if (!controle.HandleCommand())
        {
            cout << "Unknown command\n";
        }
    }

	controle.PrintAllBodies(bodies, cout);
	controle.FindLargestWeightBody(bodies, cout);
	controle.FindSmallestWeightBodyInWater(bodies, cout);

    return 0;
}
