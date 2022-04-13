#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef  int DateType;
//队列与栈不同，满足先入先出，像一个管道
typedef struct QueueNode
{
	DateType a;
	struct QueueNode* next;
}Node;
typedef struct Queue
{
	//队列使用单链表的头插实现
	Node* head;
	Node* tail;
}Queue;
void QueueInit(Queue* ps);//初始化
void QueuePush(Queue* ps,DateType tmp);//入队
void QueuePop(Queue* ps);//出队
int QueueCountSize(const Queue* ps);//统计队列中的元素个数
void QueueDestory(Queue* ps);