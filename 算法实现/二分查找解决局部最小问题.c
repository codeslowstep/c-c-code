//����һ�����飬�ҵ�һ���ֲ���Сֵ��
//�ֲ���С�������±�i, ��i = 0, arr[i] < arr[i + 1], ��arr[i]�ֲ���С��
//��i = size - 1, arr[i] < arr[i - 1], ��arr[i]�ֲ���С��
//��0 < i < size - 1, arr[i] < arr[i + 1] && arr[i] < arr[i - 1], ��arr[i]�ֲ���С
#include<stdio.h>
#pragma warning(disable:4996)
int LocalMinimam(int* arr,int sz)
{
	if (sz == 1||arr[0] < arr[1])
		return arr[0];
	if (arr[sz - 1] < arr[sz - 2])
		return arr[sz - 1];
	//��������������Ļ������Ҷ����½�������
	int left = 0;
	int right = sz - 1;
	while (left<=right)
	{
		int mid = left + ((right - left) >> 1);//��ֹԽ��
		//�����(right-left)>>1��Ҫ����
		if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
			return arr[mid];
		if (arr[mid] > arr[mid - 1])//��left~��mid-1��һ�����ھֲ���С
		{
			right = mid - 1;
			continue;
		}
		if (arr[mid] > arr[mid + 1])//��mid+1��~rightһ�����ھֲ���С
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