#include<stdio.h>
#include<assert.h>
#include<stdlib.h>//后面需要断言
//使用顺序表实现栈，顺序表采用可以扩容的
typedef int Datetype;
typedef struct Stack
{
	int top;//栈顶的位置
	Datetype* a;//一块指针开辟空间
	int capacity;//容量
}Stack;
void StackInit(Stack* ps);
void StackPush(Stack* ps,Datetype tmp);//入栈
void StackPop(Stack* ps);//pop出栈
int StackElementSize(Stack* ps);//统计栈中的元素个数
void StackDestory(Stack* ps);//销毁栈