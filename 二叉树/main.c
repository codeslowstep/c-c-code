#include"binary tree.h"
//					A
//			B 	         	C
//		D	    E      F        G
//					1
//			2				3
//		4		5		6		7
//满二叉树的高度为h,则满二叉树的结点数为2^h-1
//创造一个上图所示的二叉树(满二叉树)
void Test()
{
	//先制造一个二叉树
	TreeNode root,  B,  C,  D,  E,  F,  G;
	//第三层
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
	//第二层
	B.left = &D;
	B.right = &E;
	B.node_element = 2;
	C.left = &F;
	C.right = &G;
	C.node_element = 3;
	//第一层
	root.left = &B;
	root.right =&C;
	root.node_element = 1;
	/*PreorderTraversal(&root);*/
	//前序遍历理想打印结果：1  2   4  NULL NULL 5 NULL NULL 
	//3  6  NULL  NULL 7 NULL NULL
	/*InorderTraversal(&root);*/
	//中序遍历(LNR)预计结果
	//NULL 4 NULL 2  NULL 5 NULL 1  NULL 6 NULL 3  NULL 7 NULL
	/*PostorderTraversal(&root);*/
	//后序遍历预计结果
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