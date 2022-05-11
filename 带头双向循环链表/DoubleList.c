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
// ˫����������
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
// ˫�������ӡ
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
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListInsert(pHead, x);
}
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead && pHead->next != pHead);
	ListErase(pHead->prev);
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->next, x);
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead && pHead->next != pHead);
	ListErase(pHead->next);
}
// ˫���������
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
// ˫��������pos��ǰ����в���
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
// ˫������ɾ��posλ�õĽڵ�
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