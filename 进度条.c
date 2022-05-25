#include<stdio.h>    
#include<windows.h>
#include<string.h>    
int main()
{
    char bar[101];
    const char* arr = "|-\\/";
    memset(bar, 0, sizeof(bar));
    int i = 0;
    for (; i < 100; i++)
    {
        bar[i] = '#';
        if (i == 99)
        {
            printf("[%-100s][%%%d][%c]", bar, i + 1,arr[i%4]);
        }
        else
        {
            printf("[%-100s][%%%d][%c]\r", bar, i + 1,arr[i%4]);
        }
        fflush(stdout);
        Sleep(10);
    }
    return 0;
}