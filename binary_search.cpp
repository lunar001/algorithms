#include <iostream>
#include <string>
using namespace std;
int BinarySearch(const int * a, int length, int key)
{
	if (a == NULL)
		return -1;
	if (length == 0)
		return -1;
	int low = 0; 
	int high = length - 1;
	int mid = low + (high - low) / 2;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (a[mid] == key)
			return mid;
		else if (a[mid] < key)
			low = mid + 1;
		else
			high = mid -1;
	}
	return -1;
}

int LowerBinarySearch(const int * a, int length, int key)
{
	if (a == NULL || length <= 0)
		return -1;
	int low = 0;
	int high = length - 1;
	int mid ;
	int result = -1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (a[mid] == key)
		{
			result = mid;
			high = mid - 1;
		}
		else if (a[mid] > key)
			high = mid - 1;
		else if (a[mid] < key)
			low = mid + 1;
	}
	return result;
}
int UpperBinarySearch(const int * a, int length, int key)
{
	if (a == NULL || length <= 0)
		return -1;
	int low = 0;
	int high = length - 1;
	int mid;
	int result =-1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (a[mid] == key)
		{
			result = mid;
			low = mid + 1;
		}
		else if (a[mid] < key)
			low = mid + 1;
		else if (a[mid] > key)
			high = mid - 1;
	}
	return result;
}


int
main()
{
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << BinarySearch(a, 10, 10) << endl;
	int c[10] = {0,2,2,2,2,2,2,2,2,2};
	cout << LowerBinarySearch(c, 10, 0) << endl;
	cout << UpperBinarySearch(c, 10, 0) << endl;
	system("pause");

	return 0;
}