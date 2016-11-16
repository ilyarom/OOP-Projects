// PrimeNumber.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	size_t n;
	cin >> n;
	if (n > 100000000)
	{
		cout << "”казанное число не должно превышать 100 миллионов." << "\n";
		return 1;
	}
	vector<bool> numbers(n + 1, true);
	numbers[1] = false;
    for (size_t i = 2; ((i*i) <= n); ++i)
	{
		if (numbers[i])
		{
			for (size_t j = (i*i); j <= n; j += i)
			{
				if (numbers[j])
				{
					numbers[j] = false;
				}
			}
				
		}
	}
	int b = 0;
	for (size_t i = 1; i <= n; ++i)
	{
		if (numbers[i])
		{
			++b;
		    cout << i << " ";
			if (i % 10 == 0)
			{
				cout << "\n";
			}
		}
	}
	cout << b << "\n";

    return 0;
}

