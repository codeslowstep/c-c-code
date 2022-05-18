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
//�����ϵ���
static void HeapAdjustUp(Heap* pheap)
{
	//��ʱ�������һ��Ԫ���±�Ϊsize-1
	int child = pheap->size - 1;
	int parent = (child - 1) / 2;
	while (1)
	{
		//һ��������ѭ������������parent=child=0
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
//�ѵĲ���
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
//ɾ������Ԫ�غ����µ���
static void HeapAdjustDown(Heap* pheap)
{
	int parent = 0;
	int leftchild = parent * 2 + 1;
	int rightchild = leftchild + 1;
	while (leftchild < pheap->size)//�������ӣ���һ�����Һ���
	{
		//�ҵ����Һ�������С�ĺ��ӵ��±�
		int minchild = rightchild < pheap->size&& pheap->data[rightchild] < pheap->data[leftchild]\
			? rightchild : leftchild;
		//�����������С�ĺ��ӣ��ͽ�������С�ĺ��ӽ���
		if (pheap->data[minchild] < pheap->data[parent])
		{
			Swap(&(pheap->data[minchild]), &(pheap->data[parent]));
			parent = minchild;
			leftchild = parent * 2 + 1;
			rightchild = leftchild + 1;
			//������һ��ѭ��
		}
		else
		{
			break;
		}
	}
}
//��ɾ��ͷ��Ԫ��
void HeapPop(Heap* pheap)
{
	assert(pheap);
	if (HeapIsEmpty(pheap))
	{
		return;
	}
	else
	{
		int tmp = pheap->data[0];//��¼ԭʼ�Ķ�����С����
		//���һ��������ԭʼ��С���ݽ���
		Swap(&(pheap->data[0]), &(pheap->data[pheap->size - 1]));
		pheap->size--;//����С���ݴӶ��з���
		HeapAdjustDown(pheap);
	}
}
int Heapsize(Heap* pheap)
{
	assert(pheap);
	return pheap->size;
}
