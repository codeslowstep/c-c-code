#pragma once
#include<stdio.h>
#include<stdlib.h>//������ڵ㶼��malloc������
typedef  int DateType;
typedef struct SignleListNode
{
	DateType a;//һ������Ԫ��
	struct SignleListNode* next;//ָ����һ���ڵ��ָ��
}SListNode;
//������Ĵ�ӡ
void SListNodePrint();
void SListNodePushHead(SListNode** pplist, DateType a);//ͷ��
void SListNodePushBack(SListNode** pplist, DateType a);//β��
void SListNodeEraseHead(SListNode** pplist);//ͷɾ
void SListNodeEraseBack(SListNode** pplist);//βɾ
void SListNodePushAssign(SListNode*pos, DateType a);//ָ��λ�ò���
//����һ�����ĵ�ַ����������֮ǰ����a
void SListNodeDelAssign(SListNode*pos,SListNode*plist);//ָ��λ��ɾ��
//����һ�����ĵ�ַ��ɾ��������
void DestorySList(SListNode** pplist);//���ٵ�����
