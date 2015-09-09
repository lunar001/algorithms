#include <iostream>

using namespace std;
void Merge(int * a, int low, int mid, int high)
{
	if (a == NULL)
		return;
	if (low >= high) return;
	int length = high - low + 1;
	int * aux = new int[length];
	int i = low; int j = mid + 1;
	for (int k = low; k <= high; k++)
		aux[k - low] = a[k];
	for (int k = low; k <= high; k++)
	{
		if (i > mid) a[k] = aux[(j++) - low];
		else if (j > high) a[k] = aux[(i++) - low];
		else if (aux[i-low] < aux[j-low]) a[k] = aux[(i++) - low];
		else a[k] = aux[(j++) - low];
	}
	delete[] aux;
 }
void MergeSort(int * a, int low, int high)
{
	if (low >= high)
		return;
	int mid = low + (high - low) / 2;
	MergeSort(a, low, mid);
	MergeSort(a, mid +1, high);
	Merge(a, low, mid, high);
}
int
main()
{
	int a[7] = {1,2,3,4,8,5,9};
	MergeSort(a, 0, 6);
	for (int i = 0; i < 7; i++)
		cout << a[i] << endl;
	system("pause");
}