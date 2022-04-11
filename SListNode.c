#include"SListNode.h"
void SListNodePrint(SListNode* plist)
{
	//�β�plist��ʵ��plist�Ŀ�����ֱ��ʹ��
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
void SListNodePushHead(SListNode**pplist,DateType a)//ͷ��,���ַ������Բ��ÿ���ԭ����plist�Ƿ�Ϊ��ָ��
{
	//*pplist��Ч��plist
	//ͷ��֮��ͷָ���ָ��Ҫ�ı䣬����Ҫ����ͷָ��ĵ�ַ��������
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	tmp->a = a;
	tmp->next = *pplist;
	*pplist = tmp;
}
void SListNodePushBack(SListNode** pplist, DateType a)//β��
{
	//*pplist��Ч��plist
	//β��Ĳ���Ҳ�п��ܵ���ͷָ��ı䣬����ҲҪ����ͷָ��ĵ�ַ��������
	if (*pplist == NULL)
	{
		SListNodePushHead(pplist,a);
	}
	else
	{
		//plist��=NULL��plist���ܸı���,����ԭ���������ƻ�
		//���ȴ���һ���ڵ�
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
void SListNodeEraseHead(SListNode** pplist)//ͷɾ
{
	//*pplist��Ч��plist,ʹ�ö���ָ���Ŀ�������ܹ���ʵ�ĸı�plist
	//ͷɾ��Ȼ����ͷָ���ָ��ı�
	if (!*pplist)
		return;
	if ((*pplist)->next == NULL)//ֻ��һ���ڵ�
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	SListNode*tmp = (*pplist)->next;
	free(*pplist);
	*pplist = tmp;
}
void SListNodeEraseBack(SListNode** pplist)//βɾ
{
	//βɾҲ���п��ܸı�ͷָ���
	//*pplist��Ч��plist
	if (!*pplist)
		return;
	if ((*pplist)->next == NULL)//ֻ��һ�����
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	SListNode* p1= *pplist;//��ʼָ���һ�����
	SListNode* p2 = (*pplist)->next;//��ʼָ��ڶ������
	while (p2->next != NULL)
	{
		p2 = p2->next;
		p1 = p1->next;
	}
	//�����Ժ�p1һ��ָ�����ڶ�����㣬p2һ��ָ�����һ�����
	free(p2);
	p2 = NULL;
	p1->next = NULL;
	return;
}
void SListNodePushAssign(SListNode* pos, DateType a)//ָ��λ�ò���
//����һ�����ĵ�ַ����������֮ǰ����a
{
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	tmp->a = a;
	tmp->next = pos;
	pos = tmp;
}
void SListNodeDelAssign(SListNode* pos,SListNode*plist)//ָ��λ��ɾ��
//����һ�����ĵ�ַ��ɾ��������
{
	//��Ҫ���ҵ�������ǰ��һ�����ĵ�ַ
	SListNode* seek = plist;
	while (seek->next != pos)
	{
		seek = seek->next;
	}
	//seek��Ϊǰһ�����ĵ�ַ
	seek->next = pos->next;
	free(pos);
	pos = NULL;
}
void DestorySList(SListNode** pplist)
{
	//*pplist�ȼ���plist
	while (*pplist != NULL)
	{
		SListNodeEraseBack(pplist);
	}
}