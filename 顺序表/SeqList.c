#include"SeqList.h"
void SeqListPushHead(SeqL* tmp,SeqListDateType a)//头插
{
	//先检查能否头插
	if (tmp->capacity == tmp->size)
	{
		//扩容
		SeqListDateType*p=(SeqListDateType*)realloc(tmp->p_space, 2 * tmp->capacity * sizeof(SeqListDateType));
		assert(p);
		tmp->p_space = p;
		tmp->capacity *= 2;
	}
	//从最后一个元素开始往后移
	int i = 0;
	for (i = tmp->size - 1; i >= 0; i--)
	{
		tmp->p_space[i + 1] = tmp->p_space[i];
	}
	tmp->p_space[0] = a;
	//插入完成，size++
	tmp->size++;
}
void SeqListPushBack(SeqL* tmp, SeqListDateType a)//尾插
{
	//检查能否尾插
	if (tmp->capacity == tmp->size)
	{
		//扩容
		SeqListDateType* p = (SeqListDateType*)realloc(tmp->p_space, 2 * tmp->capacity * sizeof(SeqListDateType));
		assert(p);
		tmp->p_space = p;
		tmp->capacity *= 2;
	}
	tmp->p_space[tmp->size] = a;
	//插入完成，size++
	tmp->size++;
}
void SeqListPrint(const SeqL* tmp)
{
	int i = 0;
	for (i = 0; i < tmp->size; i++)
	{
		printf("%d ", tmp->p_space[i]);
	}
}

void SeqListEraseHead(SeqL* tmp)//头删
{
	if (tmp->size > 0)
	{
		int i = 0;
		//从下标为1开始依次往前移动
		for (i = 1; i < tmp->size; i++)
		{
			tmp->p_space[i - 1] = tmp->p_space[i];
		}
		tmp->size--;
	}
	else
		return;
}
void SeqListEraseBack(SeqL* tmp)//尾删
{
	if (tmp->size > 0)
		tmp->size--;
	else
		return;
}
void SeqListPushAssign(SeqL* tmp, int pos, SeqListDateType a)//指定位置插入
{
	if (tmp->size == tmp->capacity)
	{
		SeqListDateType *p=(SeqListDateType*)realloc(tmp->p_space, 2 * tmp->capacity * sizeof(SeqListDateType));
		assert(p);
		tmp->p_space = p;
		tmp->capacity *= 2;
	}
	if (pos == 1)
	{
		SeqListPushHead(tmp, a);
	}
	else if (pos == tmp->size)
	{
		SeqListPushBack(tmp, a);
	}
	else if (pos<1 || pos>tmp->size)
	{
		return;
	}
	else
	{
		int i=0;
		for (i = tmp->size - 1; i >= pos; i--)
		{
			tmp->p_space[i + 1] = tmp->p_space[i];
		}
		tmp->p_space[pos] = a;
		tmp->size++;
	}
}
void SeqListEraseAssign(SeqL* tmp, int pos)//指定位置删除
{
	if (tmp->size == 0)
		return;
	else
	{
		if (pos == 1)
		{
			SeqListEraseHead(tmp);
		}
		else if (pos == tmp->size)
		{
			SeqListEraseBack(tmp);
		}
		else
		{
			int i = 0;
			for (i = pos; i < tmp->size; i++)
			{
				tmp->p_space[i - 1] = tmp->p_space[i];
			}
			tmp->size--;
		}
	}
}