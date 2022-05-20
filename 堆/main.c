#include"heap.h"
void Test1()
{
	Heap heaptest;
	HeapInit(&heaptest);
	HeapPush(&heaptest, 65);
	HeapPush(&heaptest, 43);
	HeapPush(&heaptest, 34);
	HeapPush(&heaptest, 5);
	HeapPush(&heaptest, 15);
	HeapPush(&heaptest, 21);
	HeapPrint(&heaptest);
	Heapdestroy(&heaptest);
}

int main()
{
	//Test1();
	//HeapSortTest2();
	HeapSortTest1();
	system("pause");
	return 0;
}