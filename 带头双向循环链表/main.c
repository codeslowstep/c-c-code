#include"DoubleList.h"
void Test1()
{
	ListNode* head = ListCreate();
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPushBack(head, 5);
	ListPrint(head);
	//ListPopBack(head);
	//ListPrint(head);
	//ListPopBack(head);
	//ListPrint(head);
	//ListPopBack(head);
	//ListPrint(head);
	//ListPopBack(head);
	//ListPrint(head);
	//ListPopBack(head);
	//ListPrint(head);
	//ListPopBack(head);
	//ListPrint(head);
	ListPopFront(head);
	ListPrint(head);
	ListPopFront(head);
	ListPrint(head);
	ListPopFront(head);
	ListPrint(head);
	ListPopFront(head);
	ListPrint(head);
	ListPopFront(head);
	ListPrint(head);
	ListPopFront(head);
	ListPrint(head);
}
void Test2()
{
	ListNode* head = ListCreate();
	ListPushFront(head, 1);
	ListPushFront(head, 2);
	ListPushFront(head, 3);
	ListPushFront(head, 4);
	ListPushFront(head, 5);
	ListPrint(head);
	ListPopFront(head);
	ListPrint(head);
	ListPopFront(head);
	ListPrint(head);
	ListPopFront(head);
	ListPrint(head);
	ListPopFront(head);
	ListPrint(head);
}
int main()
{
	Test2();
	system("pause");
	return 0;
}