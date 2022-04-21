#include"SeqList.h"
void SeqListPushHead(SeqL* tmp,SeqListDateType a)//ͷ��
{
	//�ȼ���ܷ�ͷ��
	if (tmp->capacity == tmp->size)
	{
		//����
		SeqListDateType*p=(SeqListDateType*)realloc(tmp->p_space, 2 * tmp->capacity * sizeof(SeqListDateType));
		assert(p);
		tmp->p_space = p;
		tmp->capacity *= 2;
	}
	//�����һ��Ԫ�ؿ�ʼ������
	int i = 0;
	for (i = tmp->size - 1; i >= 0; i--)
	{
		tmp->p_space[i + 1] = tmp->p_space[i];
	}
	tmp->p_space[0] = a;
	//������ɣ�size++
	tmp->size++;
}
void SeqListPushBack(SeqL* tmp, SeqListDateType a)//β��
{
	//����ܷ�β��
	if (tmp->capacity == tmp->size)
	{
		//����
		SeqListDateType* p = (SeqListDateType*)realloc(tmp->p_space, 2 * tmp->capacity * sizeof(SeqListDateType));
		assert(p);
		tmp->p_space = p;
		tmp->capacity *= 2;
	}
	tmp->p_space[tmp->size] = a;
	//������ɣ�size++
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

void SeqListEraseHead(SeqL* tmp)//ͷɾ
{
	if (tmp->size > 0)
	{
		int i = 0;
		//���±�Ϊ1��ʼ������ǰ�ƶ�
		for (i = 1; i < tmp->size; i++)
		{
			tmp->p_space[i - 1] = tmp->p_space[i];
		}
		tmp->size--;
	}
	else
		return;
}
void SeqListEraseBack(SeqL* tmp)//βɾ
{
	if (tmp->size > 0)
		tmp->size--;
	else
		return;
}
void SeqListPushAssign(SeqL* tmp, int pos, SeqListDateType a)//ָ��λ�ò���
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
void SeqListEraseAssign(SeqL* tmp, int pos)//ָ��λ��ɾ��
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