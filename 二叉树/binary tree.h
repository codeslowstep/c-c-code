#pragma once
#include<stdio.h>
#include<Windows.h>
typedef  int DateType;//假设二叉树一个结点中存放的元素是int 
typedef struct TreeNode//一个结点
{
	DateType node_element;//该结点中的元素
	struct TreeNode* left;//左树
	struct TreeNode* right;//右树

}TreeNode;
//二叉树的前序遍历(NLR) Node Left Right  二叉树的前序遍历又称先序遍历
void PreorderTravelsal(const TreeNode* root);
//中序遍历(LNR)
void InorderTraversal(const TreeNode* root);
//后序遍历(LRN)
void PostorderTraversal(const TreeNode* root);
//层序遍历，即一层从左向右遍历
void SequenceTraversal(const TreeNode* root);
//统计二叉树中的结点个数
int TreeSize(const TreeNode* root);