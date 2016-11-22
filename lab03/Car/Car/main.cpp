// Car.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Car.h"
#include "Driver.h"

using namespace std;

int main()
{
    CCar car;
    CDriver controller(car, cin, cout);
    while (!cin.eof() || !cin.fail())
    {
        cout << "> ";
        if (!controller.HandleCommand())
        {
            cout << "Unknown command!" << endl;
        }
    }
    return 0;
}

