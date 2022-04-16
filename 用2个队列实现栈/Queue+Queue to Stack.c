#include"Queue+Queue to Stack.h"
QueueNode* CreateNewnode()
{
	QueueNode*tmp=(QueueNode*)malloc(sizeof(QueueNode));
	assert(tmp);
	return tmp;
}
void QueueInit(Queue* q)//队列的初始化
{
	assert(q);
	q->head = NULL;
	q->tail = NULL;
}
void QueueDestory(Queue* q)//队列的销毁
{
	//这种方法销毁队列包含了特殊情况
	//1.当队列为空，cur=NULL,不会进入循环，直接q->head=q->tail=NULL
	//2.只有一个结点时，使用cur销毁了这个结点，而且cur经过一轮循环之后=NULL
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
void QueuePush(Queue* q,QDateType x)//队尾入队列，相当于单链表的尾插   Push:尾插
{
	assert(q);
	QueueNode* newnode = CreateNewnode();
	newnode->date = x;
	newnode->next = NULL;
	//先判断head是否为空，为空就然head和tail都指向newnode
	if (!q->head)
	{
		q->head =q->tail= newnode;
	}
	else
	{
		q->tail->next = newnode;//插入newnode
		q->tail = newnode;//更新tail
	}
}
//队列：队尾插入，队头出，可以做到先进先出
//如果队列采用队头插入，队头出的话，就是栈，比如往队头插入12345,到了单链表中就是5 4 3 2 1
//此时若从队头出，就是5 4 3 2 1
void QueuePop(Queue* q)//队头出队列，相当于单链表的头删    Pop:头删
{
	assert(q);
	assert(!QueueIsEmpty(q));//函数的设计是为空返回true,前面加一个!就是断言不为空
	QueueNode* next = q->head->next;
	free(q->head);
	q->head = next;
	if (next == NULL)//就是只有一个元素
	{
		q->tail = NULL;//只有一个元素，就让tail为空指针即可，因为next已经是空指针了
	}
}
//Insert:指定位置插入      Erase:指定位置删除
QDateType GetQueueFront(const Queue* q)//取队头的数据
{
	assert(q);
	assert(q->head);
	//或者assert(!QueueIsEmpty(q))判断还有数据
	return q->head->date;
}
QDateType GetQueueBack(const Queue* q)//取队尾的数据
{
	assert(q);
	assert(q->tail);
	//或者assert(!QueueIsEmpty(q))判断还有数据
	return q->tail->date;
}
int GetQueueSize(const Queue* q)//计算队列有多少个数据
{
	//这个也是不用考虑特殊情况
	//q->head=NULL,count=0,直接 return
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
bool QueueIsEmpty(const Queue* q)//判断队列是否为空
{
	if (q->head == NULL)
		return true;
	return false;
}
Stack* StackCreated()
{
	Stack* tmp = (Stack*)malloc(sizeof(Stack));
	assert(tmp);
	//初始化栈中的2个队列
	QueueInit(&tmp->q1);
	QueueInit(&tmp->q2);
	return tmp;
}
//入栈，指定向q1进元素
void StackPush(Stack* ps, QDateType x)
{
	QueuePush(&ps->q1, x);
}
//出栈，将q1中的元素一次出队到q2,直到q1中仅剩一个元素，将该元素出队，然后再把q2中的所有元素转到q1
QDateType StackPop(Stack* ps)
{
	//没有元素，直接返回
	if (QueueIsEmpty(&ps->q1))
		return;
	while(GetQueueSize(&ps->q1) > 1)
	{
		//1.q1中的元素转到q2中
		QueuePush(&ps->q2, GetQueueFront(&ps->q1));
		//2.去除q1中的那个元素
		QueuePop(&ps->q1);
	}
	QDateType tmp = GetQueueFront(&ps->q1);
	QueuePop(&ps->q1);
	//然后再将q2中的数据转移到q1中
	while (!QueueIsEmpty(&ps->q2))
	{
		//1.q2中的元素转到q1中
		QueuePush(&ps->q1, GetQueueFront(&ps->q2));
		//2.去除q2中的那个元素
		QueuePop(&ps->q2);
	}
	return tmp;
}
//返回栈顶元素
QDateType StackTop(Stack* ps)
{
	//GetQueueBack中有断言，不用考虑特殊情况
	return GetQueueBack(&ps->q1);
}
//判断栈是否为空
bool StackIsEmpty(Stack* ps)
{
	if (QueueIsEmpty(&ps->q1))
		return true;
	return false;
}
//栈的销毁
void StackDestory(Stack* ps)
{
	QueueDestory(&ps->q1);
	QueueDestory(&ps->q2);
}
