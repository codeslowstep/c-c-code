#include<stdio.h>
#pragma warning(disable:4996)
int Fib(int n)//斐波那契数 1 1 2 3 5
{
	if (n == 1 || n == 2)
		return 1;
	int first = 1,second=1,sum=0;
	while (n >= 3)//n=3,循环一次。n=4,循环2次
	{
		sum = first + second;
		int tmp = first;//保存原本的first
		first = second;//first右移
		second = tmp + second;//second右移
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