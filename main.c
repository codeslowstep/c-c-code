#include"SListNode.h"
void Test()
{
	SListNode* plist = NULL;//单链表的头指针
	//单链表初始化时只有一个头指针
	SListNodePushHead(&plist, 1);
	SListNodePushHead(&plist, 1);
	SListNodePushHead(&plist, 1);
	SListNodePushBack(&plist, 3);
	SListNodePushBack(&plist, 4);
	SListNodePushBack(&plist, 5);
	/*SListNodePushHead(&plist, 1);*/
	//SListNodeEraseHead(&plist);
	SListNodeEraseBack(&plist);
	DestorySList(&plist);
	SListNodePrint(plist);
}
int main()
{
	Test();
	system("pause");
	return 0;
}