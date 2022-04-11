#pragma once
#include<stdio.h>
#include<stdlib.h>//单链表节点都是malloc出来的
typedef  int DateType;
typedef struct SignleListNode
{
	DateType a;//一个结点的元素
	struct SignleListNode* next;//指向下一个节点的指针
}SListNode;
//单链表的打印
void SListNodePrint();
void SListNodePushHead(SListNode** pplist, DateType a);//头插
void SListNodePushBack(SListNode** pplist, DateType a);//尾插
void SListNodeEraseHead(SListNode** pplist);//头删
void SListNodeEraseBack(SListNode** pplist);//尾删
void SListNodePushAssign(SListNode*pos, DateType a);//指定位置插入
//给定一个结点的地址，在这个结点之前插入a
void SListNodeDelAssign(SListNode*pos,SListNode*plist);//指定位置删除
//给定一个结点的地址，删除这个结点
void DestorySList(SListNode** pplist);//销毁单链表
