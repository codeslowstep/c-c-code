#include"Stack.h"
void StackInit(Stack* ps)
{
	//初始时栈中是没有元素的
	ps->a = (Datetype*)malloc(5 * sizeof(Datetype));
	ps->capacity = 5;
	ps->top = 0;//初始设置栈顶的位置为0
	//即栈顶总是指向栈中最后一个元素的下一个
}
void StackPush(Stack* ps, Datetype tmp)
{
	if (ps->top == ps->capacity)//扩容
	{
		Datetype*tmp=(Datetype*)realloc(ps->a, 2*ps->capacity*sizeof(Datetype));
		assert(tmp);
		ps->a = tmp;
	}
	ps->a[ps->top] = tmp;
	ps->top++;
}
void StackPop(Stack* ps)//出栈时也把出栈的那个元素打印出来
{
	if (ps->top == 0)
	{
		printf("没有元素可以出栈\n");
		return;
	}
	printf("%d ", ps->a[ps->top - 1]);
	ps->top--;
}
int StackElementSize(Stack* ps)
{
	return ps->top;
}
void StackDestory(Stack* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}