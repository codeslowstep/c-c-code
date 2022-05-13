#include<stdio.h>
#include<windows.h>
//指定比特位置为0
#define BITZERO(x,n) x&=(~(1<<(n-1)))
//指定比特位置为1
#define BITONE(x,n) x|=(1<<(n-1))
//打印反码
void PrintBit(int x)
{
	int num = sizeof(x) * 8 - 1;
	while (num >= 0)
	{
		if (num + 1 != 32 && (num +1)% 4 == 0)
			printf(" ");
		if ((x & (1 << num)) == 0)
			printf("0");
		else
			printf("1");
		num--;
	}
	printf("\n");
}
int main()
{
	int a = -1;
	//以16进制是直接存补码，就是把16进制直接转化为2进制当成补码存入
	PrintBit(a);
	BITZERO(a, 1);
	BITZERO(a, 2);
	BITZERO(a, 3);
	PrintBit(a);
	BITONE(a, 1);
	PrintBit(a);
	system("pause");
	return 0;
}