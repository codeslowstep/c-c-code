#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
//�����Ƚ��ȳ���ջ���Ƚ����
typedef int QDateType;
typedef struct QueueNode//���еĽ��
{
	QDateType date;//����е�Ԫ��
	struct QueueNode* next;//ָ����һ������ָ��
}QueueNode;
typedef  struct Queue
{
	QueueNode* head;
	QueueNode* tail;//����һ�����У�ֻ��Ҫ��¼��ͷ����β��㼴��
}Queue;
void QueueInit(Queue* q);//���еĳ�ʼ��
void QueueDestory(Queue* q);//���е�����
void QueuePush(Queue* q, QDateType x);//��β����У��൱�ڵ������β��   Push:β��
void QueuePop(Queue* q);//��ͷ�����У��൱�ڵ������ͷɾ    Pop:ͷɾ
//Insert:ָ��λ�ò���      Erase:ָ��λ��ɾ��
QDateType GetQueueFront(const Queue*q);//ȡ��ͷ������
QDateType GetQueueBack(const Queue* q);//ȡ��β������
int GetQueueSize(const Queue* q);//��������ж��ٸ�����
bool QueueIsEmpty(const Queue* q);//�ж϶����Ƿ�Ϊ��
//ջ����ɣ��������������
typedef struct
{
	Queue q1;
	Queue q2;
}Stack;
//����һ��ջ
Stack* StackCreated();
//��ջ��ָ����q1��Ԫ��
void StackPush(Stack* ps, QDateType x);
//��ջ����q1�е�Ԫ��һ�γ��ӵ�q2,ֱ��q1�н�ʣһ��Ԫ�أ�����Ԫ�س��ӣ�Ȼ���ٰ�q2�е�����Ԫ��ת��q1
QDateType StackPop(Stack* ps);