#include <iostream>
#include < string>

using namespace std;

int Partition(int  *a, int low, int high)
{
	if (a == NULL || low >= high)
		return -1;
	int v = a[low];
	int i = low, j = high + 1;
	while (true)
	{
		while (a[++i] <= v) if (i == high) break;
		while (a[--j] >= v) if (j == low) break;
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	swap(a[j], a[low]);
	return j;
}

void QuickSort(int * a, int low, int high)
{
	if (a == NULL || low >= high) return;
	int j = Partition(a, low, high);
	QuickSort(a, low, j);
	QuickSort(a, j+1, high);
}

int
main()
{
	int a[10] = {1,32,3,5,2,9,10,54,8,10};
	QuickSort(a, 0,9);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << endl;
	}

	system("pause");
	return 0;
}