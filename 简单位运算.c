#include<stdio.h>
#include<windows.h>
//ָ������λ��Ϊ0
#define BITZERO(x,n) x&=(~(1<<(n-1)))
//ָ������λ��Ϊ1
#define BITONE(x,n) x|=(1<<(n-1))
//��ӡ����
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
	//��16������ֱ�Ӵ油�룬���ǰ�16����ֱ��ת��Ϊ2���Ƶ��ɲ������
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