#include"Queue.h"
void Test()
{
	Queue qu;
	int ret = 0;
	QueueInit(&qu);
	QueuePush(&qu, 1);
	QueuePush(&qu, 2);
	QueuePush(&qu, 3);
	QueuePop(&qu);
	QueuePop(&qu);
	QueuePop(&qu);
	ret = QueueCountSize(&qu);
	printf("\n%d\n ", ret);
	/*QueuePop(&qu);*/
	/*QueuePop(&qu);*/
}
int main()
{
	Test();
	system("pause");
	return 0;
}