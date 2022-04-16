#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
//队列先进先出，栈是先进后出
typedef int QDateType;
typedef struct QueueNode//队列的结点
{
	QDateType date;//结点中的元素
	struct QueueNode* next;//指向下一个结点的指针
}QueueNode;
typedef  struct Queue
{
	QueueNode* head;
	QueueNode* tail;//创建一个队列，只需要记录其头结点和尾结点即可
}Queue;
void QueueInit(Queue* q);//队列的初始化
void QueueDestory(Queue* q);//队列的销毁
void QueuePush(Queue* q, QDateType x);//队尾入队列，相当于单链表的尾插   Push:尾插
void QueuePop(Queue* q);//队头出队列，相当于单链表的头删    Pop:头删
//Insert:指定位置插入      Erase:指定位置删除
QDateType GetQueueFront(const Queue*q);//取队头的数据
QDateType GetQueueBack(const Queue* q);//取队尾的数据
int GetQueueSize(const Queue* q);//计算队列有多少个数据
bool QueueIsEmpty(const Queue* q);//判断队列是否为空
//栈的组成，由两个队列组成
typedef struct
{
	Queue q1;
	Queue q2;
}Stack;
//创建一个栈
Stack* StackCreated();
//入栈，指定向q1进元素
void StackPush(Stack* ps, QDateType x);
//出栈，将q1中的元素一次出队到q2,直到q1中仅剩一个元素，将该元素出队，然后再把q2中的所有元素转到q1
QDateType StackPop(Stack* ps);