//һ�������������ֳ����������ε����֣�����Ķ�������ż���Σ��ҳ������������ε�2������
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//������������Ԫ����a a a c c b d d e e
int* SeekTwoNumer(int* arr, int sz)
{
	int eor = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		eor ^= arr[i];
	}
	//������eor����a^b,������Ҫ�ֱ����a��b
	int rightone = eor & (~eor + 1);
	//��ȡeor���ұߵ��Ǹ�1�����λ��a��b�Ķ�����λֻ����1����1������һ��һ����0
	int tmp = 0;
	for (i = 0; i < sz; i++)
	{
		if ((rightone & arr[i]) == 0)//Ҫע������������ȼ�,��rightone & arr[i]������
		{
			tmp ^= arr[i];//tmpһ��Ϊa����b�е�һ��
		}
	}
	int first = tmp;
	int second = eor ^ first;
	int*ret=(int*)malloc(2 * sizeof(int));
	ret[0] = first;
	ret[1] = second;
	return ret;
}
int main()
{
	int arr[] = { 1,1,5,6,9,9,9,9,2,3,3,2 };
	int*ret=SeekTwoNumer(arr, sizeof(arr) / sizeof(arr[0]));
	printf("%d %d", ret[0], ret[1]);
	return 0;
}