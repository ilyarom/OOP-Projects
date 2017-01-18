#pragma once

template <class T, class Less>
bool FindMaxEx(std::vector<T> const& arr, T & maxValue, Less const& less = bool operator < (T, T))
{
	if (arr.empty())
	{
		return false;
	}
	const T *max = &arr[0];
	for (T const& element : arr)
	{
		if (less(*max, element))
		{
			max = &element;
		}
	}
	maxValue = *max;
	return true;
}