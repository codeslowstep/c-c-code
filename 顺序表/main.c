#include"SeqList.h"

void Test()
{
	SeqL seqlisttest;
	seqlisttest.capacity = Initcapacity;
	seqlisttest.size = 0;
	seqlisttest.p_space = calloc(Initcapacity, sizeof(SeqListDateType));//À≥–Ú±Ì≥ı ºªØ
	/*SeqListPushHead(&seqlisttest, 10);
	SeqListPushHead(&seqlisttest, 2);
	SeqListPushHead(&seqlisttest, 3);
	SeqListPushHead(&seqlisttest, 2);
	SeqListPushHead(&seqlisttest, 5);*/
	SeqListPushBack(&seqlisttest, 4);
	SeqListPushBack(&seqlisttest, 5);
	SeqListPushBack(&seqlisttest, 6);
	SeqListPushBack(&seqlisttest, 7);
	SeqListEraseAssign(&seqlisttest, 3);
	SeqListPrint(&seqlisttest);
}
int main()
{
	Test();
	system("pause");
	return 0;
}