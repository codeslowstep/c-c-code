#include<stdio.h>
#pragma warning(disable:4996)
int Fib(int n)//쳲������� 1 1 2 3 5
{
	if (n == 1 || n == 2)
		return 1;
	int first = 1,second=1,sum=0;
	while (n >= 3)//n=3,ѭ��һ�Ρ�n=4,ѭ��2��
	{
		sum = first + second;
		int tmp = first;//����ԭ����first
		first = second;//first����
		second = tmp + second;//second����
		n--;
	}
	return sum;
}
int main()
{
	int ret = Fib(10);
	printf("%d", ret);
	return 0;
}