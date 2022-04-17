#include"binary tree.h"
//NLF
//Preorder Traversal:前序遍历   Traversal:遍历
void PreorderTraversal(const TreeNode* root)
{
	if (root==NULL)
	{
		printf("NULL ");
		return;
	}
	//前序遍历NLR
	printf("%d ", root->node_element);//Node
	PreorderTraversal( root->left);//Left
	PreorderTraversal(root->right);//Right
}
//Inorder Traversal:中序遍历
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
//Postorder Traversal:后序遍历
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
//Sequence Traversal:层序遍历,层序遍历需要使用队列
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