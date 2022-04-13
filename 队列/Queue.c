#include"Queue.h"
Node* CreatedNewnode()
{
	return (Node*)malloc(sizeof(Node));
}
void QueueInit(Queue* ps)//初始化
{
	ps->head = NULL;
	ps->tail = NULL;
}
void QueuePush(Queue* ps, DateType tmp)//入队
{
	if (!ps->head)//没有元素
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
	//有1个元素
	if (ps->head->next == NULL)
	{
		Node* recive = CreatedNewnode();
		assert(recive);
		recive->a=tmp;
		recive->next = ps->head;
		ps->head = recive;
		ps->tail =recive->next;//这样再次进行头插的时候tail一定指向尾
		return;
	}
	Node* recive2 = CreatedNewnode();
	assert(recive2);
	recive2->a = tmp;
	recive2->next = ps->head;
	ps->head = recive2;
	//最后一部分是正常的插入
}
void QueuePop(Queue* ps)
{
	assert(ps->tail);
	//先把特殊情况处理掉
	if (ps->head->next == NULL)//只有一个元素
	{
		printf("%d ", ps->tail->a);
		ps->head = NULL;
		ps->tail = NULL;
		return;
	}
	//遍历找到当前尾的前一个
	Node*tmp = ps->head;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	//出来后tmp就是tail的前面一个
	printf("%d ", ps->tail->a);
	free(ps->tail);
	ps->tail = tmp;
	ps->tail->next = NULL;
}
int QueueCountSize(const Queue* ps)//统计队列中的元素个数
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
	//遍历销毁
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