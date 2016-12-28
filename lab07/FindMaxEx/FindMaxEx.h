#pragma once

template <class T, class Less>
bool FindMaxEx(std::vector<T> const& arr, T & maxValue, Less const& less)
{
	if (arr.empty())
	{
		return false;
	}
	try
	{
		maxValue = arr[0];
	}
	catch (...)
	{
		throw;
	}
	for (T const& element : arr)
	{
		if (less(maxValue, element))
		{
			try
			{
				maxValue = element;
			}
			catch (...)
			{
				throw;
			}
		}
	}
	return true;
}