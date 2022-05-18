#include"smallheap.h"
void HeapInit(Heap* pheap)
{
	assert(pheap);
	pheap->capacity = pheap->size = pheap->data = 0;
}
void Heapdestroy(Heap* pheap)
{
	assert(pheap);
	free(pheap->data);
	pheap->capacity = pheap->size = pheap->data = 0;
}
bool HeapIsEmpty(Heap* pheap)
{
	assert(pheap);
	return pheap->size == 0;
}
bool HeapIsFull(Heap* pheap)
{
	assert(pheap);
	return pheap->capacity == pheap->size;
}
static void Swap(HeapDataType* p1, HeapDataType*p2)
{
	HeapDataType tmp = *p1;
	*p1 =* p2;
	*p2 = tmp;
}
//堆向上调整
static void HeapAdjustUp(Heap* pheap)
{
	//此时堆中最后一个元素下标为size-1
	int child = pheap->size - 1;
	int parent = (child - 1) / 2;
	while (1)
	{
		//一定会跳出循环，最差情况是parent=child=0
		if (pheap->data[parent] > pheap->data[child])
		{
			Swap(&(pheap->data[parent]), &(pheap->data[child]));
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//堆的插入
void HeapPush(Heap* pheap, HeapDataType x)
{
	assert(pheap);
	if (HeapIsFull(pheap))
	{
		if (pheap->capacity == 0)
		{
			HeapDataType*tmp = (HeapDataType*)malloc(4 * sizeof(HeapDataType));
			assert(tmp);
			pheap->data = tmp;
			pheap->capacity = 4;
		}
		else
		{
			HeapDataType* tmp = (HeapDataType*)realloc(pheap->data,2 * sizeof(HeapDataType)*pheap->capacity);
			assert(tmp);
			pheap->data = tmp;
			pheap->capacity *= 2;
		}
	}
	pheap->data[pheap->size++] = x;
	HeapAdjustUp(pheap);
}
//删除堆中元素后向下调整
static void HeapAdjustDown(Heap* pheap)
{
	int parent = 0;
	int leftchild = parent * 2 + 1;
	int rightchild = leftchild + 1;
	while (leftchild < pheap->size)//存在左孩子，不一定有右孩子
	{
		//找到左右孩子中最小的孩子的下标
		int minchild = rightchild < pheap->size&& pheap->data[rightchild] < pheap->data[leftchild]\
			? rightchild : leftchild;
		//如果父大于最小的孩子，就将父与最小的孩子交换
		if (pheap->data[minchild] < pheap->data[parent])
		{
			Swap(&(pheap->data[minchild]), &(pheap->data[parent]));
			parent = minchild;
			leftchild = parent * 2 + 1;
			rightchild = leftchild + 1;
			//进入下一次循环
		}
		else
		{
			break;
		}
	}
}
//堆删除头部元素
void HeapPop(Heap* pheap)
{
	assert(pheap);
	if (HeapIsEmpty(pheap))
	{
		return;
	}
	else
	{
		int tmp = pheap->data[0];//记录原始的堆中最小数据
		//最后一个数据与原始最小数据交换
		Swap(&(pheap->data[0]), &(pheap->data[pheap->size - 1]));
		pheap->size--;//将最小数据从堆中分离
		HeapAdjustDown(pheap);
	}
}
int Heapsize(Heap* pheap)
{
	assert(pheap);
	return pheap->size;
}
