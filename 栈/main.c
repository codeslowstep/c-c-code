#include"Stack.h"
void StackTest()
{
	Stack* st = StackGenerate();
	StackInit(st);
	StackPush(st, 1);
	StackPush(st, 2);
	printf("%d ", StackTopElement(st));
	StackPop(st);
	printf("%d ", StackTopElement(st));
	StackPop(st);
	StackPush(st, 3);
	StackPush(st, 4);
	printf("%d ", StackTopElement(st));
	StackPop(st);
	printf("%d ", StackTopElement(st));
	StackPop(st);
}
int main()
{
	StackTest();
	system("pause");
	return 0;
}