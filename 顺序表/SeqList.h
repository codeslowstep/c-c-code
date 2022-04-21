#pragma once
#define Initcapacity 3
#include<stdio.h>
#include<stdlib.h>//malloc的头文件
#include<assert.h>
typedef int SeqListDateType;
//创建一个动态的顺序表
struct SeqList
{
	int size;//顺序表实际元素个数
	int capacity;//顺序表容量
	SeqListDateType* p_space;//指针指向动态开辟空间
};
typedef struct SeqList SeqL;
//打印顺序表
void SeqListPrint(const SeqL* tmp);
//传址实现对本体的修改
void SeqListPushHead(SeqL*tmp,SeqListDateType a);//头插
void SeqListPushBack(SeqL* tmp, SeqListDateType a);//尾插
void SeqListEraseHead(SeqL* tmp);//头删
void SeqListEraseBack(SeqL* tmp);//尾删
void SeqListPushAssign(SeqL* tmp,int pos, SeqListDateType a);//指定位置插入
void SeqListEraseAssign(SeqL* tmp,int pos);//指定位置删除