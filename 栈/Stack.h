#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int Datatype;
typedef struct Stack
{
	Datatype* a;
	int top;
	//top���ǵ���ջ��Ԫ�ص���������Ϊջ�����һ��Ԫ�ص��±��1
	int capacity;
}Stack;
//generate����
Stack* StackGenerate();
void StackInit(Stack* st);
void StackPush(Stack* st,Datatype x);
void StackPop(Stack* st);
Datatype StackTopElement(Stack* st);
bool StackIsEmpty(Stack* st);
void StackDestory(Stack* st);
