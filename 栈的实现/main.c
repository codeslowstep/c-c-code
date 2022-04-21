#include"Stack.h"
void Test()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPush(&st, 3);
	int ret = StackElementSize(&st);
	printf("\n%d", ret);
}
int main()
{
	Test();
	system("pause");
	return 0;
}