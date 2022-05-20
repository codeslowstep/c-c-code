#include"heap.h"
void HeapSortTest1()
{
	//从小到大排序
	int arr[] = { 10,54,32,44,7,65,8,9,5,45,67,33 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int tmp = sz;
	while (sz > 0)
	{
		for (int i = (sz - 1 - 1) / 2; i >= 0; i--)
		{
			HeapAdjustDownByRecursion(arr, sz, i);
		}
		Swap(&arr[0], &arr[sz - 1]);
		sz--;
	}
	PrintArray(arr, tmp);
}
static void HeapAdjustUpToSmall(int* arr, int child)
{
	int par = (child - 1) / 2;
	if (arr[par] <= arr[child])
		return;
	else
	{
		Swap(&arr[par], &arr[child]);
		HeapAdjustUpToSmall(arr, par);
	}
}
void HeapSortTest2()
{
	//从大到小排序
	int arr[] = { 10,54,32,44,7,65,8,9,5,45,67,33 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int tmp = sz;
	while (sz > 0)
	{
		for (int i = 0; i < sz; i++)
		{
			HeapAdjustUpToSmall(arr, i);
		}
		Swap(&arr[0], &arr[sz - 1]);
		sz--;
	}
	PrintArray(arr, tmp);
}