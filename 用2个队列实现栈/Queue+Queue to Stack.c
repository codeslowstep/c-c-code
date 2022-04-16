#include"Queue+Queue to Stack.h"
QueueNode* CreateNewnode()
{
	QueueNode*tmp=(QueueNode*)malloc(sizeof(QueueNode));
	assert(tmp);
	return tmp;
}
void QueueInit(Queue* q)//���еĳ�ʼ��
{
	assert(q);
	q->head = NULL;
	q->tail = NULL;
}
void QueueDestory(Queue* q)//���е�����
{
	//���ַ������ٶ��а������������
	//1.������Ϊ�գ�cur=NULL,�������ѭ����ֱ��q->head=q->tail=NULL
	//2.ֻ��һ�����ʱ��ʹ��cur�����������㣬����cur����һ��ѭ��֮��=NULL
	assert(q);
	QueueNode* cur = q->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->head = q->tail = NULL;
}
void QueuePush(Queue* q,QDateType x)//��β����У��൱�ڵ������β��   Push:β��
{
	assert(q);
	QueueNode* newnode = CreateNewnode();
	newnode->date = x;
	newnode->next = NULL;
	//���ж�head�Ƿ�Ϊ�գ�Ϊ�վ�Ȼhead��tail��ָ��newnode
	if (!q->head)
	{
		q->head =q->tail= newnode;
	}
	else
	{
		q->tail->next = newnode;//����newnode
		q->tail = newnode;//����tail
	}
}
//���У���β���룬��ͷ�������������Ƚ��ȳ�
//������в��ö�ͷ���룬��ͷ���Ļ�������ջ����������ͷ����12345,���˵������о���5 4 3 2 1
//��ʱ���Ӷ�ͷ��������5 4 3 2 1
void QueuePop(Queue* q)//��ͷ�����У��൱�ڵ������ͷɾ    Pop:ͷɾ
{
	assert(q);
	assert(!QueueIsEmpty(q));//�����������Ϊ�շ���true,ǰ���һ��!���Ƕ��Բ�Ϊ��
	QueueNode* next = q->head->next;
	free(q->head);
	q->head = next;
	if (next == NULL)//����ֻ��һ��Ԫ��
	{
		q->tail = NULL;//ֻ��һ��Ԫ�أ�����tailΪ��ָ�뼴�ɣ���Ϊnext�Ѿ��ǿ�ָ����
	}
}
//Insert:ָ��λ�ò���      Erase:ָ��λ��ɾ��
QDateType GetQueueFront(const Queue* q)//ȡ��ͷ������
{
	assert(q);
	assert(q->head);
	//����assert(!QueueIsEmpty(q))�жϻ�������
	return q->head->date;
}
QDateType GetQueueBack(const Queue* q)//ȡ��β������
{
	assert(q);
	assert(q->tail);
	//����assert(!QueueIsEmpty(q))�жϻ�������
	return q->tail->date;
}
int GetQueueSize(const Queue* q)//��������ж��ٸ�����
{
	//���Ҳ�ǲ��ÿ����������
	//q->head=NULL,count=0,ֱ�� return
	assert(q);
	int count = 0;
	QueueNode* cur = q->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		cur = next;
		count++;
	}
	return count;
}
bool QueueIsEmpty(const Queue* q)//�ж϶����Ƿ�Ϊ��
{
	if (q->head == NULL)
		return true;
	return false;
}
Stack* StackCreated()
{
	Stack* tmp = (Stack*)malloc(sizeof(Stack));
	assert(tmp);
	//��ʼ��ջ�е�2������
	QueueInit(&tmp->q1);
	QueueInit(&tmp->q2);
	return tmp;
}
//��ջ��ָ����q1��Ԫ��
void StackPush(Stack* ps, QDateType x)
{
	QueuePush(&ps->q1, x);
}
//��ջ����q1�е�Ԫ��һ�γ��ӵ�q2,ֱ��q1�н�ʣһ��Ԫ�أ�����Ԫ�س��ӣ�Ȼ���ٰ�q2�е�����Ԫ��ת��q1
QDateType StackPop(Stack* ps)
{
	//û��Ԫ�أ�ֱ�ӷ���
	if (QueueIsEmpty(&ps->q1))
		return;
	while(GetQueueSize(&ps->q1) > 1)
	{
		//1.q1�е�Ԫ��ת��q2��
		QueuePush(&ps->q2, GetQueueFront(&ps->q1));
		//2.ȥ��q1�е��Ǹ�Ԫ��
		QueuePop(&ps->q1);
	}
	QDateType tmp = GetQueueFront(&ps->q1);
	QueuePop(&ps->q1);
	//Ȼ���ٽ�q2�е�����ת�Ƶ�q1��
	while (!QueueIsEmpty(&ps->q2))
	{
		//1.q2�е�Ԫ��ת��q1��
		QueuePush(&ps->q1, GetQueueFront(&ps->q2));
		//2.ȥ��q2�е��Ǹ�Ԫ��
		QueuePop(&ps->q2);
	}
	return tmp;
}
//����ջ��Ԫ��
QDateType StackTop(Stack* ps)
{
	//GetQueueBack���ж��ԣ����ÿ����������
	return GetQueueBack(&ps->q1);
}
//�ж�ջ�Ƿ�Ϊ��
bool StackIsEmpty(Stack* ps)
{
	if (QueueIsEmpty(&ps->q1))
		return true;
	return false;
}
//ջ������
void StackDestory(Stack* ps)
{
	QueueDestory(&ps->q1);
	QueueDestory(&ps->q2);
}
