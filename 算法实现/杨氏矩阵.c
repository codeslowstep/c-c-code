#include<stdio.h>
#include<string.h>
#include<math.h>
#pragma warning (disable:4996)
void Find(int(*arr)[5], int target)
{
    //���м�Ԫ�ؿ�ʼ��
    int left = 0;
    int right = 4;
    int up = 0;
    int down = 4;//���������к����к�
    while (left<=right&&up<=down)
    {
        int tmp = arr[(left + right) / 2][(up + down) / 2];
        if ((left == right && up == down && left == up) && target == tmp)
        {
            printf("��Ҫ�ҵ�Ԫ���ڵ�%d�У���%d��\n", (left + right) / 2 + 1, (up + down) / 2 + 1);
            return;
        }
        if ((left == right && up == down && left == up) && target != tmp)
        {
            printf("�Ҳ���\n");
            return;
        }
        if (target == tmp)
        {
            printf("��Ҫ�ҵ�Ԫ���ڵ�%d�У���%d��\n", (left + right) / 2 + 1, (up + down)/2 + 1);
            return;
        }
        if (target > tmp)
        {
            if (left + 1 != right)
            {
                left = (left + right) / 2;
            }
            else
            {
                left +=1;
            }
            if (up + 1 != down)
            {
                up = (up + down) / 2;
            }
            else
            {
                up += 1;
            }
        }
        else
        {
            if (right - 1 != left)
            {
                right = (left + right) / 2;
            }
            else
            {
                right -= 1;
            }
            if(down-1!=up)
            {
                down = (up + down) / 2;
            }
            else
            {
                down -= 1;
            }
        }
    }
    printf("�Ҳ���\n");
}
int main()
{
    int arr[5][5] = {
        {1,2,3,4,5},
        {2,3,4,5,6},
        {3,4,5,6,7},
        {4,5,6,7,8},
        {5,6,7,8,9}
    };
    int m = 1;
    Find(arr, m);
    return 0;
}