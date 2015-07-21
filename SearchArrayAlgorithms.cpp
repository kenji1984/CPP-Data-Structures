#include <iostream>

using namespace std;

template <typename Type>
int SearchArray(Type array[], Type target, int size, int low, int high);

template <typename Type>
int SearchArray(Type array[], Type target, int size);

int main() {
	int SIZE = 1000000;
	int array[SIZE];
	for(int i = 0; i < SIZE; i++)
	{
		array[i] = i*2;
	}
	
	int size = sizeof(array) / sizeof(int);
	
	clock_t start = clock();
	cout << SearchArray(array, 953824, size) << endl;
	cout << "Took " << clock() - start << " milliseconds." << endl;
}


template <typename Type>
int SearchArray(Type array[], Type target, int size, int low, int high)
{
	
	if(!size) return -1;
	
	if(target < array[0] || target > array[size - 1]) return -1;
	
	if(array[low] == target) return low;
	if(low == high) return -1;
	
	else if(array[low] < target)
	{
		return SearchArray(array, target, size, low + ((high + 1 - low) / 2), high);
	}
	else 
	{
		return SearchArray(array, target, size, low / 2, low);
	}
}


template<typename Type>
int SearchArray(Type array[], Type target, int size)
{
	return SearchArray(array, target, size, 0, size - 1);
}


/*
template <typename Type>
int SearchArray(Type array[], Type target, int size, int low, int high)
{
	if(!size) return -1;
	
	if(target < array[0] || target > array[size - 1]) return -1;
	
	if(array[low] == target) return low;
	if(low == high) return -1;
	
	else if(array[low] < target)
	{
		return SearchArray(array, target, size, low + ((high + 1 - low) / 2), high);
	}
	else 
	{
		return SearchArray(array, target, size, low / 2, low);
	}
}*/