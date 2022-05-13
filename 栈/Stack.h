#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int Datatype;
typedef struct Stack
{
	Datatype* a;
	int top;
	//top总是等于栈中元素的数量，且为栈中最后一个元素的下标加1
	int capacity;
}Stack;
//generate生成
Stack* StackGenerate();
void StackInit(Stack* st);
void StackPush(Stack* st,Datatype x);
void StackPop(Stack* st);
Datatype StackTopElement(Stack* st);
bool StackIsEmpty(Stack* st);
void StackDestory(Stack* st);
