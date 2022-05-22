#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
//另外一个测试用例
BTNode* BinaryTreeCreate2(BTDataType* a, int n, int* pi)
{

	BTNode* NodeE = (BTNode*)malloc(sizeof(BTNode));
	assert(NodeE);
	NodeE->_data = 'E';
	NodeE->_left = NULL;
	NodeE->_right = NULL;
	BTNode* NodeD = (BTNode*)malloc(sizeof(BTNode));
	assert(NodeD);
	NodeD->_data = 'D';
	NodeD->_left = NodeD->_right = NULL;
	BTNode* NodeF = (BTNode*)malloc(sizeof(BTNode));
	assert(NodeF);
	NodeF->_data = 'F';
	NodeF->_left = NodeF->_right = NULL;
	BTNode* NodeG = (BTNode*)malloc(sizeof(BTNode));
	assert(NodeG);
	NodeG->_data = 'G';
	NodeG->_left = NodeG->_right = NULL;
	BTNode* NodeB = (BTNode*)malloc(sizeof(BTNode));
	assert(NodeB);
	NodeB->_data = 'B';
	NodeB->_left = NodeD;
	NodeB->_right = NodeE;
	BTNode* NodeC = (BTNode*)malloc(sizeof(BTNode));
	NodeC->_data = 'C';
	NodeC->_left = NodeF;
	NodeC->_right = NodeG;
	BTNode* NodeA = (BTNode*)malloc(sizeof(BTNode));
	NodeA->_data = 'A';
	NodeA->_left = NodeB;
	NodeA->_right = NodeC;
	return NodeA;
}
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	BTNode* NodeH = (BTNode*)malloc(sizeof(BTNode));
	assert(NodeH);
	NodeH->_data = 'H';
	NodeH->_left = NodeH->_right = NULL;
	BTNode* NodeE = (BTNode*)malloc(sizeof(BTNode));
	assert(NodeE);
	NodeE->_data = 'E';
	NodeE->_left =NULL;
	NodeE->_right = NodeH;
	BTNode* NodeD = (BTNode*)malloc(sizeof(BTNode));
	assert(NodeD);
	NodeD->_data = 'D';
	NodeD->_left = NodeD->_right = NULL;
	BTNode* NodeF = (BTNode*)malloc(sizeof(BTNode));
	assert(NodeF);
	NodeF->_data = 'F';
	NodeF->_left = NodeF->_right = NULL;
	BTNode* NodeG = (BTNode*)malloc(sizeof(BTNode));
	assert(NodeG);
	NodeG->_data = 'G';
	NodeG->_left = NodeG->_right = NULL;
	BTNode* NodeB = (BTNode*)malloc(sizeof(BTNode));
	assert(NodeB);
	NodeB->_data = 'B';
	NodeB->_left = NodeD;
	NodeB->_right = NodeE;
	BTNode* NodeC = (BTNode*)malloc(sizeof(BTNode));
	NodeC->_data = 'C';
	NodeC->_left = NodeF;
	NodeC->_right = NodeG;
	BTNode* NodeA = (BTNode*)malloc(sizeof(BTNode));
	NodeA->_data = 'A';
	NodeA->_left = NodeB;
	NodeA->_right = NodeC;
	return NodeA;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;
	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));
	free(*root);
	*root = NULL;
	return;
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k >= 1);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* pleft = BinaryTreeFind(root->_left, x);
	if (pleft != NULL)
		return pleft;
	return BinaryTreeFind(root->_right, x);
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}
//二叉树的层序遍历需要使用队列
typedef struct QueueNode
{
	BTNode* data;
	struct QueueNode* next;
}QNode;
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;
void QueuePush(Queue* pq,BTNode* x)
{
	if (pq->head == NULL)
	{
		pq->head = pq->tail = (QNode*)malloc(sizeof(QNode));
		pq->head->data = x;
		pq->head->next = NULL;
	}
	else
	{
		QNode*newnode= (QNode*)malloc(sizeof(QNode));
		newnode->data = x;
		newnode->next = NULL;
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
//队列尾入头出
void QueuePop(Queue* pq)
{
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}
void QueueDestory(Queue* pq)
{
	while (pq->head != NULL)
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
	pq->tail = NULL;
}
BTNode* QueueTop(Queue* pq)
{
	assert(pq->head);
	return pq->head->data;
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
		return;
	Queue help;
	help.head = help.tail = NULL;
	QueuePush(&help,root);
	while (help.head != NULL)
	{
		printf("%c ", help.head->data->_data);
		if (help.head->data->_left)
		{
			QueuePush(&help, help.head->data->_left);
		}
		if (help.head->data->_right)
		{
			QueuePush(&help, help.head->data->_right);
		}
		QueuePop(&help);
	}
	QueueDestory(&help);
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
		return true;
	if (root->_left == NULL && root->_right == NULL)
		return true;
	if (root->_left!=NULL&&root->_left->_left == NULL && root->_left->_right == NULL\
		&& root->_right == NULL)
		return true;
	if (root->_left != NULL && root->_left->_left == NULL && root->_left->_right == NULL \
		&& root->_right != NULL && root->_right->_left == NULL && root->_right->_right == NULL)
		return true;
	if (root->_right != NULL && root->_left == NULL)
		return false;
	return BinaryTreeComplete(root->_left) && BinaryTreeComplete(root->_right);
}
int main()
{
	BTNode*pb=BinaryTreeCreate(0, 0, 0);
	printf("叶子结点的个数是%d\n", BinaryTreeLeafSize(pb));
	printf("整个二叉树的结点个数是%d\n", BinaryTreeSize(pb));
	printf("第1层的结点个数是%d\n", BinaryTreeLevelKSize(pb, 1));
	printf("第2层的结点个数是%d\n", BinaryTreeLevelKSize(pb, 2));
	printf("第3层的结点个数是%d\n", BinaryTreeLevelKSize(pb, 3));
	printf("第4层的结点个数是%d\n", BinaryTreeLevelKSize(pb, 4));
	printf("第5层的结点个数是%d\n", BinaryTreeLevelKSize(pb, 5));
	printf("前序遍历的结果是:\n");
	BinaryTreePrevOrder(pb);
	printf("\n中序遍历的结果是:\n");
	BinaryTreeInOrder(pb);
	printf("\n后序遍历的结果是:\n");
	BinaryTreePostOrder(pb);
	printf("\n层序遍历的结果是:\n");
	BinaryTreeLevelOrder(pb);
	int ret = BinaryTreeComplete(pb);
	if (ret)
	{
		printf("\n这个二叉树是完全二叉树\n");
	}
	else
	{
		printf("\n这个二叉树不是是完全二叉树\n");
	}
	BinaryTreeDestory(&pb);
	system("pause");
	return 0;
}