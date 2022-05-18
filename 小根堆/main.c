#include"smallheap.h"
void HeapTest()
{
	Heap theap;
	HeapInit(&theap);
	int arr[] = { 10,5,6,9,18,31,52,72,42,1,23 };
	//int arr[] = { 10,5,6};
	//int arr[] = { 10,5,6,9,52 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
	{
		HeapPush(&theap, arr[i]);
	}
	printf("----------------------------\n");
	printf("堆中元素个数为%d,现堆中元素是	",theap.size);
	for (int i = 0; i < theap.size; i++)
	{
		printf("%d ", theap.data[i]);
	}
	printf("\n");
	printf("----------------------------\n");
	HeapPop(&theap);
	printf("----------------------------\n");
	printf("堆中元素个数为%d,现堆中元素是	", theap.size);
	for (int i = 0; i < theap.size; i++)
	{
		printf("%d ", theap.data[i]);
	}
	HeapPop(&theap);
	printf("\n----------------------------\n");
	printf("堆中元素个数为%d,现堆中元素是	", theap.size);
	for (int i = 0; i < theap.size; i++)
	{
		printf("%d ", theap.data[i]);
	}
	HeapPop(&theap);
	printf("\n----------------------------\n");
	printf("堆中元素个数为%d,现堆中元素是	", theap.size);
	for (int i = 0; i < theap.size; i++)
	{
		printf("%d ", theap.data[i]);
	}
	HeapPop(&theap);
	printf("\n----------------------------\n");
	printf("堆中元素个数为%d,现堆中元素是	", theap.size);
	for (int i = 0; i < theap.size; i++)
	{
		printf("%d ", theap.data[i]);
	}
	HeapPop(&theap);
	printf("\n----------------------------\n");
	printf("堆中元素个数为%d,现堆中元素是	", theap.size);
	for (int i = 0; i < theap.size; i++)
	{
		printf("%d ", theap.data[i]);
	}
	HeapPop(&theap);
	printf("\n----------------------------\n");
	printf("堆中元素个数为%d,现堆中元素是	", theap.size);
	for (int i = 0; i < theap.size; i++)
	{
		printf("%d ", theap.data[i]);
	}
	HeapPop(&theap);
	printf("\n----------------------------\n");
	printf("堆中元素个数为%d,现堆中元素是	", theap.size);
	for (int i = 0; i < theap.size; i++)
	{
		printf("%d ", theap.data[i]);
	}
	HeapPop(&theap);
	printf("\n----------------------------\n");
	printf("堆中元素个数为%d,现堆中元素是	", theap.size);
	for (int i = 0; i < theap.size; i++)
	{
		printf("%d ", theap.data[i]);
	}
	HeapPop(&theap);
	printf("\n----------------------------\n");
	printf("堆中元素个数为%d,现堆中元素是	", theap.size);
	for (int i = 0; i < theap.size; i++)
	{
		printf("%d ", theap.data[i]);
	}
	Heapdestroy(&theap);
}
int main()
{
	HeapTest();
	system("pause");
	return 0;
}