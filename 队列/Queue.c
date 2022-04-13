#include"Queue.h"
Node* CreatedNewnode()
{
	return (Node*)malloc(sizeof(Node));
}
void QueueInit(Queue* ps)//��ʼ��
{
	ps->head = NULL;
	ps->tail = NULL;
}
void QueuePush(Queue* ps, DateType tmp)//���
{
	if (!ps->head)//û��Ԫ��
	{
		Node* accept = CreatedNewnode();
		assert(accept);
		ps->head = accept;
		ps->tail = accept;
		accept = NULL;
		ps->head->a = tmp;
		ps->head->next = NULL;
		return;
	}
	//��1��Ԫ��
	if (ps->head->next == NULL)
	{
		Node* recive = CreatedNewnode();
		assert(recive);
		recive->a=tmp;
		recive->next = ps->head;
		ps->head = recive;
		ps->tail =recive->next;//�����ٴν���ͷ���ʱ��tailһ��ָ��β
		return;
	}
	Node* recive2 = CreatedNewnode();
	assert(recive2);
	recive2->a = tmp;
	recive2->next = ps->head;
	ps->head = recive2;
	//���һ�����������Ĳ���
}
void QueuePop(Queue* ps)
{
	assert(ps->tail);
	//�Ȱ�������������
	if (ps->head->next == NULL)//ֻ��һ��Ԫ��
	{
		printf("%d ", ps->tail->a);
		ps->head = NULL;
		ps->tail = NULL;
		return;
	}
	//�����ҵ���ǰβ��ǰһ��
	Node*tmp = ps->head;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	//������tmp����tail��ǰ��һ��
	printf("%d ", ps->tail->a);
	free(ps->tail);
	ps->tail = tmp;
	ps->tail->next = NULL;
}
int QueueCountSize(const Queue* ps)//ͳ�ƶ����е�Ԫ�ظ���
{
	Node* tmp = ps->head;
	int count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return count;
}
void QueueDestory(Queue* ps)
{
	//��������
	if (!ps->head)
		return;
	if (ps->head->next == NULL)
	{
		free(ps->head);
		ps->head = NULL;
		ps->tail = NULL;
	}
	Node* first=ps->head;
	Node* second = first->next;
	while (second->next != NULL)
	{
		free(first);
		first = second;
		second = second->next;
	}
	free(first);
	free(second);
	first = NULL;
	second = NULL;
	ps->head = NULL;
	ps->tail = NULL;
}