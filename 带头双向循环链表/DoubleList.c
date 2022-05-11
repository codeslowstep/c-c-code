#include"DoubleList.h"
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL)
	{
		perror("malloc failed");
		exit(0);
	}
	head->next = head;
	head->prev = head;
	return head;
}
ListNode* BuyNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		exit(0);
	}
	newnode->data = x;
	return newnode;
}
// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	ListNode* next = pHead->next;
	ListNode* start = pHead;
	while (next != start)
	{
		free(pHead);
		pHead = next;
		next = next->next;
	}
	free(pHead);
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListInsert(pHead, x);
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead && pHead->next != pHead);
	ListErase(pHead->prev);
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->next, x);
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead && pHead->next != pHead);
	ListErase(pHead->next);
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* prev = pos->prev;
	//prev pos 
	ListNode* newnode = BuyNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos->next != pos);
	ListNode* next = pos->next;
	ListNode* prev = pos->prev;
	//prev   pos   next
	prev->next = next;
	next->prev = prev;
	free(pos);
}