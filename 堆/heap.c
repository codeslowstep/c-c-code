#include"heap.h"
void HeapInit(Heap* pheap)
{
	assert(pheap);
	pheap->capacity = pheap->heapsize = 0;
	pheap->pdata = NULL;
}
void Heapdestroy(Heap* pheap)
{
	assert(pheap);
	pheap->capacity = pheap->heapsize = 0;
	free(pheap->pdata);
	pheap->pdata = NULL;
}
void HeapPush(Heap* pheap, HeapDataType x)
{
	assert(pheap);
	if (pheap->capacity == pheap->heapsize)
	{
		int newcapacity = pheap->capacity == 0 ? 4 : 2 * pheap->capacity;
		HeapDataType* tmp = (HeapDataType*)realloc(pheap->pdata, newcapacity*sizeof(HeapDataType));
		assert(tmp);
		pheap->pdata = tmp;
		pheap->capacity = newcapacity;
	}
	pheap->pdata[pheap->heapsize++] = x;
	HeapAdjustUpByRecursion(pheap->pdata, pheap->heapsize - 1);
}
void HeapPop(Heap* pheap)
{
	assert(pheap != NULL && pheap->heapsize > 0);
	Swap(&pheap->pdata[0], &pheap->pdata[pheap->heapsize - 1]);
	pheap->heapsize--;
	HeapAdjustDownByRecursion(pheap->pdata, pheap->heapsize, 0);
}
bool HeapIsFull(Heap* pheap)
{
	assert(pheap);
	return pheap->capacity == pheap->heapsize;
}
bool HeapIsEmpty(Heap* pheap)
{
	assert(pheap);
	return pheap->heapsize == 0;
}
int HeapElementNum(Heap* pheap)
{
	assert(pheap);
	return pheap->heapsize;
}
void Swap(HeapDataType* p1, HeapDataType* p2)
{
	HeapDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void HeapAdjustDownByCycle(HeapDataType* pdata, int heapsize, int parent)
{
	int par = parent;
	int leftchild = par * 2 + 1;
	int rightchild = leftchild + 1;
	while (leftchild < heapsize)
	{
		int maxchild = rightchild<heapsize&& pdata[rightchild]>pdata[leftchild] ? rightchild : leftchild;
		if (pdata[maxchild] > pdata[par])
		{
			Swap(&pdata[maxchild], &pdata[par]);
			par = maxchild;
			leftchild = par * 2 + 1;
			rightchild = leftchild + 1;
		}
		else
			break;
	}
}
void HeapAdjustUpByCycle(HeapDataType* pdata, int child)
{
	int par = (child - 1) / 2;
	while (1)
	{
		if (pdata[par] >= pdata[child])
			break;
		else
		{
			Swap(&pdata[par], &pdata[child]);
			child = par;
			par = (child - 1) / 2;
		}
	}
}
void HeapAdjustDownByRecursion(HeapDataType* pdata, int heapsize, int parent)
{
	int par = parent;
	int leftchild = par * 2 + 1;
	int rightchild = leftchild + 1;
	if (leftchild < heapsize)
	{
		int maxchild = rightchild<heapsize&& pdata[rightchild]>pdata[leftchild] ? rightchild : leftchild;
		if (pdata[parent] >= pdata[maxchild])
			return;
		else
		{
			Swap(&pdata[parent], &pdata[maxchild]);
			HeapAdjustDownByRecursion(pdata, heapsize, maxchild);
		}
	}
	else
		return;
}
void HeapAdjustUpByRecursion(HeapDataType* pdata, int child)
{
	int par = (child - 1) / 2;
	if (pdata[par] >= pdata[child])
		return;
	else
	{
		Swap(&pdata[par], &pdata[child]);
		HeapAdjustUpByRecursion(pdata, par);
	}
}
void PrintArray(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void HeapPrint(Heap* pheap)
{
	assert(pheap);
	for (int i = 0; i < pheap->heapsize; i++)
	{
		printf("%d ", pheap->pdata[i]);
	}
	printf("\n");
}