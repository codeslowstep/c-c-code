#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include<assert.h>
typedef int HeapDataType;
typedef struct Heap
{
	HeapDataType* pdata;
	int capacity;
	int heapsize;
}Heap;
void HeapInit(Heap* pheap);
void Heapdestroy(Heap* pheap);
void HeapPush(Heap* pheap, HeapDataType x);
void HeapPrint(Heap* pheap);
void HeapPop(Heap* pheap);
bool HeapIsFull(Heap* pheap);
bool HeapIsEmpty(Heap* pheap);
int HeapElementNum(Heap* pheap);
void HeapAdjustDownByCycle(HeapDataType* pdata, int heapsize, int parent);
void HeapAdjustUpByCycle(HeapDataType* pdata, int child);
void HeapAdjustDownByRecursion(HeapDataType* pdata, int heapsize, int parent);
void HeapAdjustUpByRecursion(HeapDataType* pdata, int child);
void Swap(HeapDataType* p1, HeapDataType* p2);
void HeapSortTest1();
void HeapSortTest2();
void PrintArray(int* arr, int sz);