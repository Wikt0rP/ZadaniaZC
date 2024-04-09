#include <stdio.h>

int main()
{
    int array[10];
    int *p;

    for (int i = 0; i < 10; i++)
    {
        array[i] = i;
    }

    p = array;

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", *(p+i));
    }
    return 0;
}