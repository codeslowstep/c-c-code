#include"binary tree.h"
//					A
//			B 	         	C
//		D	    E      F        G
//					1
//			2				3
//		4		5		6		7
//���������ĸ߶�Ϊh,�����������Ľ����Ϊ2^h-1
//����һ����ͼ��ʾ�Ķ�����(��������)
void Test()
{
	//������һ��������
	TreeNode root,  B,  C,  D,  E,  F,  G;
	//������
	D.left = NULL;
	D.right = NULL;
	D.node_element = 4;
	E.left = NULL;
	E.right = NULL;
	E.node_element = 5;
	F.left = NULL;
	F.right = NULL;
	F.node_element = 6;
	G.left = NULL;
	G.right = NULL;
	G.node_element = 7;
	//�ڶ���
	B.left = &D;
	B.right = &E;
	B.node_element = 2;
	C.left = &F;
	C.right = &G;
	C.node_element = 3;
	//��һ��
	root.left = &B;
	root.right =&C;
	root.node_element = 1;
	/*PreorderTraversal(&root);*/
	//ǰ����������ӡ�����1  2   4  NULL NULL 5 NULL NULL 
	//3  6  NULL  NULL 7 NULL NULL
	/*InorderTraversal(&root);*/
	//�������(LNR)Ԥ�ƽ��
	//NULL 4 NULL 2  NULL 5 NULL 1  NULL 6 NULL 3  NULL 7 NULL
	/*PostorderTraversal(&root);*/
	//�������Ԥ�ƽ��
	//NULL NULL 4  NULL NULL 5   2   NULL NULL 6  NULL  NULL  7   3    1
	int size = TreeSize(&root);
	printf("%d ", size);
}
int main()
{
	Test();
	system("pause");
	return 0;
}