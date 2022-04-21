#include"Stack.h"
void StackInit(Stack* ps)
{
	//��ʼʱջ����û��Ԫ�ص�
	ps->a = (Datetype*)malloc(5 * sizeof(Datetype));
	ps->capacity = 5;
	ps->top = 0;//��ʼ����ջ����λ��Ϊ0
	//��ջ������ָ��ջ�����һ��Ԫ�ص���һ��
}
void StackPush(Stack* ps, Datetype tmp)
{
	if (ps->top == ps->capacity)//����
	{
		Datetype*tmp=(Datetype*)realloc(ps->a, 2*ps->capacity*sizeof(Datetype));
		assert(tmp);
		ps->a = tmp;
	}
	ps->a[ps->top] = tmp;
	ps->top++;
}
void StackPop(Stack* ps)//��ջʱҲ�ѳ�ջ���Ǹ�Ԫ�ش�ӡ����
{
	if (ps->top == 0)
	{
		printf("û��Ԫ�ؿ��Գ�ջ\n");
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