#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
#include<windows.h>
typedef int HeapDataType;
typedef struct Heap
{
	HeapDataType* data;
	int size;
	int capacity;
}Heap;
void HeapInit(Heap* pheap);
void Heapdestroy(Heap* pheap);
bool HeapIsEmpty(Heap* pheap);
bool HeapIsFull(Heap* pheap);
//堆的插入
void HeapPush(Heap* pheap, HeapDataType x);
//堆删除头部元素
void HeapPop(Heap* pheap);
int Heapsize(Heap* pheap);

