
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <functional>

template <typename T>
class CSort
{
public:
	CSort() = default;
	bool isNeedSort(const T& lhs, const T& rhs)
	{
		return lhs < rhs;
	}
	void Sort(vector <T> &arr)
	{
		for (int i = 0; i < arr.size() - 1; ++i)
		{
			if (isNeedSort(arr[i], arr[i + 1]))
			{
				swap(arr[i], arr[i + 1]);
			}
		}
	}

};

int main()
{

}
