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
//�ѵĲ���
void HeapPush(Heap* pheap, HeapDataType x);
//��ɾ��ͷ��Ԫ��
void HeapPop(Heap* pheap);
int Heapsize(Heap* pheap);

