#include<stdio.h>
#include<assert.h>
#include<stdlib.h>//������Ҫ����
//ʹ��˳���ʵ��ջ��˳�����ÿ������ݵ�
typedef int Datetype;
typedef struct Stack
{
	int top;//ջ����λ��
	Datetype* a;//һ��ָ�뿪�ٿռ�
	int capacity;//����
}Stack;
void StackInit(Stack* ps);
void StackPush(Stack* ps,Datetype tmp);//��ջ
void StackPop(Stack* ps);//pop��ջ
int StackElementSize(Stack* ps);//ͳ��ջ�е�Ԫ�ظ���
void StackDestory(Stack* ps);//����ջ