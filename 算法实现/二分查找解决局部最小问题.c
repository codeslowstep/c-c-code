//给定一个数组，找到一个局部最小值。
//局部最小：对于下标i, 若i = 0, arr[i] < arr[i + 1], 则arr[i]局部最小。
//若i = size - 1, arr[i] < arr[i - 1], 则arr[i]局部最小。
//若0 < i < size - 1, arr[i] < arr[i + 1] && arr[i] < arr[i - 1], 则arr[i]局部最小
#include<stdio.h>
#pragma warning(disable:4996)
int LocalMinimam(int* arr,int sz)
{
	if (sz == 1||arr[0] < arr[1])
		return arr[0];
	if (arr[sz - 1] < arr[sz - 2])
		return arr[sz - 1];
	//不是这两种情况的话，左右都是下降的趋势
	int left = 0;
	int right = sz - 1;
	while (left<=right)
	{
		int mid = left + ((right - left) >> 1);//防止越界
		//这里的(right-left)>>1需要括号
		if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
			return arr[mid];
		if (arr[mid] > arr[mid - 1])//则left~（mid-1）一定存在局部最小
		{
			right = mid - 1;
			continue;
		}
		if (arr[mid] > arr[mid + 1])//则（mid+1）~right一定存在局部最小
		{
			left = mid + 1;
			continue;
		}
	}
	return -1;
}
int main()
{
	int arr[] = {9,1,1,5,4,5,8,6,3,5};
	int ret=LocalMinimam(arr, sizeof(arr) / sizeof(arr[0]));
	printf("%d", ret);
	return 0;
}