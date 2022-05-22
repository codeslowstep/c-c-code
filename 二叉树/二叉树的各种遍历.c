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
//����һ����������
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
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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
// ����������
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
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k >= 1);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// ����������ֵΪx�Ľڵ�
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
// ������ǰ����� 
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
// �������������
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
// �������������
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
//�������Ĳ��������Ҫʹ�ö���
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
//����β��ͷ��
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

// �������
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
// �ж϶������Ƿ�����ȫ������
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
	printf("Ҷ�ӽ��ĸ�����%d\n", BinaryTreeLeafSize(pb));
	printf("�����������Ľ�������%d\n", BinaryTreeSize(pb));
	printf("��1��Ľ�������%d\n", BinaryTreeLevelKSize(pb, 1));
	printf("��2��Ľ�������%d\n", BinaryTreeLevelKSize(pb, 2));
	printf("��3��Ľ�������%d\n", BinaryTreeLevelKSize(pb, 3));
	printf("��4��Ľ�������%d\n", BinaryTreeLevelKSize(pb, 4));
	printf("��5��Ľ�������%d\n", BinaryTreeLevelKSize(pb, 5));
	printf("ǰ������Ľ����:\n");
	BinaryTreePrevOrder(pb);
	printf("\n��������Ľ����:\n");
	BinaryTreeInOrder(pb);
	printf("\n��������Ľ����:\n");
	BinaryTreePostOrder(pb);
	printf("\n��������Ľ����:\n");
	BinaryTreeLevelOrder(pb);
	int ret = BinaryTreeComplete(pb);
	if (ret)
	{
		printf("\n�������������ȫ������\n");
	}
	else
	{
		printf("\n�����������������ȫ������\n");
	}
	BinaryTreeDestory(&pb);
	system("pause");
	return 0;
}