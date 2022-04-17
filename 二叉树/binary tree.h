#pragma once
#include<stdio.h>
#include<Windows.h>
typedef  int DateType;//���������һ������д�ŵ�Ԫ����int 
typedef struct TreeNode//һ�����
{
	DateType node_element;//�ý���е�Ԫ��
	struct TreeNode* left;//����
	struct TreeNode* right;//����

}TreeNode;
//��������ǰ�����(NLR) Node Left Right  ��������ǰ������ֳ��������
void PreorderTravelsal(const TreeNode* root);
//�������(LNR)
void InorderTraversal(const TreeNode* root);
//�������(LRN)
void PostorderTraversal(const TreeNode* root);
//�����������һ��������ұ���
void SequenceTraversal(const TreeNode* root);
//ͳ�ƶ������еĽ�����
int TreeSize(const TreeNode* root);