#include"Stack.h"
Stack* StackGenerate()
{
	Stack* tmp = (Stack*)malloc(sizeof(Stack));
	assert(tmp != NULL);
	return tmp;
}
void StackInit(Stack* st)
{
	st->a = NULL;
	st->capacity = st->top = 0;
}
void StackPush(Stack* st,Datatype x)
{
	if (st->capacity == st->top)
	{
		st->a == NULL ? (st->a = (Datatype*)malloc(4 * sizeof(Datatype)), st->capacity = 4) : \
			(st->a = (Datatype*)malloc(2 * sizeof(Datatype) * st->capacity), st->capacity *= 2);
	}
	st->a[st->top++] = x;
}
void StackPop(Stack* st)
{
	assert(st->top> 0);
	st->top--;
}
Datatype StackTopElement(Stack* st)
{
	assert(st->top > 0);
	return st->a[st->top - 1];
}
bool StackIsEmpty(Stack* st)
{
	return st->top == 0;
}
void StackDestory(Stack* st)
{
	free(st->a);
	st->a = NULL;
	st->capacity = st->top = 0;
	free(st);
}