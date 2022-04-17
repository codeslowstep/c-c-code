#include"binary tree.h"
//NLF
//Preorder Traversal:ǰ�����   Traversal:����
void PreorderTraversal(const TreeNode* root)
{
	if (root==NULL)
	{
		printf("NULL ");
		return;
	}
	//ǰ�����NLR
	printf("%d ", root->node_element);//Node
	PreorderTraversal( root->left);//Left
	PreorderTraversal(root->right);//Right
}
//Inorder Traversal:�������
void InorderTraversal(const TreeNode* root)
{
	if (!root)
	{
		printf("NULL ");
		return;
	}
	InorderTraversal(root->left);
	printf("%d ", root->node_element);
	InorderTraversal(root->right);
}
//Postorder Traversal:�������
void PostorderTraversal(const TreeNode* root)
{
	if (!root)
	{
		printf("NULL ");
		return;
	}
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
	printf("%d ", root->node_element);
}
//Sequence Traversal:�������,���������Ҫʹ�ö���
void SequenceTraversal(const TreeNode* root)
{
	if (!root)
	{
		printf("NULL ");
		return;
	}

}
int TreeSize(const TreeNode* root)
{
	if (root == NULL)
		return 0;
	return TreeSize(root->left) + TreeSize(root->right) + 1;
}