#pragma once
#define Initcapacity 3
#include<stdio.h>
#include<stdlib.h>//malloc��ͷ�ļ�
#include<assert.h>
typedef int SeqListDateType;
//����һ����̬��˳���
struct SeqList
{
	int size;//˳���ʵ��Ԫ�ظ���
	int capacity;//˳�������
	SeqListDateType* p_space;//ָ��ָ��̬���ٿռ�
};
typedef struct SeqList SeqL;
//��ӡ˳���
void SeqListPrint(const SeqL* tmp);
//��ַʵ�ֶԱ�����޸�
void SeqListPushHead(SeqL*tmp,SeqListDateType a);//ͷ��
void SeqListPushBack(SeqL* tmp, SeqListDateType a);//β��
void SeqListEraseHead(SeqL* tmp);//ͷɾ
void SeqListEraseBack(SeqL* tmp);//βɾ
void SeqListPushAssign(SeqL* tmp,int pos, SeqListDateType a);//ָ��λ�ò���
void SeqListEraseAssign(SeqL* tmp,int pos);//ָ��λ��ɾ��