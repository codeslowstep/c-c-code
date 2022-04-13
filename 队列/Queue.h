#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef  int DateType;
//������ջ��ͬ�����������ȳ�����һ���ܵ�
typedef struct QueueNode
{
	DateType a;
	struct QueueNode* next;
}Node;
typedef struct Queue
{
	//����ʹ�õ������ͷ��ʵ��
	Node* head;
	Node* tail;
}Queue;
void QueueInit(Queue* ps);//��ʼ��
void QueuePush(Queue* ps,DateType tmp);//���
void QueuePop(Queue* ps);//����
int QueueCountSize(const Queue* ps);//ͳ�ƶ����е�Ԫ�ظ���
void QueueDestory(Queue* ps);