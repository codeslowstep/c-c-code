#include"SListNode.h"
void SListNodePrint(SListNode* plist)
{
	//形参plist是实参plist的拷贝，直接使用
	if (plist != NULL)
	{
		while (plist->next)
		{
			printf("%d->", plist->a);
			plist = plist->next;
		}
		printf("%d->", plist->a);
		printf("NULL\n");
	}
	else
	{
		printf("NULL\n");
		return;
	}
}
void SListNodePushHead(SListNode**pplist,DateType a)//头插,这种方法可以不用考虑原来的plist是否为空指针
{
	//*pplist等效于plist
	//头插之后，头指针的指向要改变，所以要传入头指针的地址或者引用
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	tmp->a = a;
	tmp->next = *pplist;
	*pplist = tmp;
}
void SListNodePushBack(SListNode** pplist, DateType a)//尾插
{
	//*pplist等效于plist
	//尾插的操作也有可能导致头指针改变，所以也要传入头指针的地址或者引用
	if (*pplist == NULL)
	{
		SListNodePushHead(pplist,a);
	}
	else
	{
		//plist！=NULL，plist不能改变了,否则原来的链表被破坏
		//首先创建一个节点
		SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
		tmp->a = a;
		tmp->next = NULL;
		SListNode* src= *pplist;
		while (src->next)
		{
			src = src->next;
		}
		src->next = tmp;
	}
}
void SListNodeEraseHead(SListNode** pplist)//头删
{
	//*pplist等效于plist,使用二级指针的目的在于能够真实的改变plist
	//头删必然导致头指针的指向改变
	if (!*pplist)
		return;
	if ((*pplist)->next == NULL)//只有一个节点
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	SListNode*tmp = (*pplist)->next;
	free(*pplist);
	*pplist = tmp;
}
void SListNodeEraseBack(SListNode** pplist)//尾删
{
	//尾删也是有可能改变头指针的
	//*pplist等效于plist
	if (!*pplist)
		return;
	if ((*pplist)->next == NULL)//只有一个结点
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	SListNode* p1= *pplist;//初始指向第一个结点
	SListNode* p2 = (*pplist)->next;//初始指向第二个结点
	while (p2->next != NULL)
	{
		p2 = p2->next;
		p1 = p1->next;
	}
	//出来以后p1一定指向倒数第二个结点，p2一定指向最后一个结点
	free(p2);
	p2 = NULL;
	p1->next = NULL;
	return;
}
void SListNodePushAssign(SListNode* pos, DateType a)//指定位置插入
//给定一个结点的地址，在这个结点之前插入a
{
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	tmp->a = a;
	tmp->next = pos;
	pos = tmp;
}
void SListNodeDelAssign(SListNode* pos,SListNode*plist)//指定位置删除
//给定一个结点的地址，删除这个结点
{
	//需要先找到这个结点前面一个结点的地址
	SListNode* seek = plist;
	while (seek->next != pos)
	{
		seek = seek->next;
	}
	//seek即为前一个结点的地址
	seek->next = pos->next;
	free(pos);
	pos = NULL;
}
void DestorySList(SListNode** pplist)
{
	//*pplist等价于plist
	while (*pplist != NULL)
	{
		SListNodeEraseBack(pplist);
	}
}