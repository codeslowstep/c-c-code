//一个数组中有两种出现了奇数次的数字，其余的都出现了偶数次，找出出现了奇数次的2种数字
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//假设这个数组的元素是a a a c c b d d e e
int* SeekTwoNumer(int* arr, int sz)
{
	int eor = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		eor ^= arr[i];
	}
	//出来是eor就是a^b,现在需要分别求出a与b
	int rightone = eor & (~eor + 1);
	//提取eor最右边的那个1，这个位置a和b的二进制位只能有1个是1，另外一个一定是0
	int tmp = 0;
	for (i = 0; i < sz; i++)
	{
		if ((rightone & arr[i]) == 0)//要注意运算符的优先级,把rightone & arr[i]括起来
		{
			tmp ^= arr[i];//tmp一定为a或者b中的一个
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