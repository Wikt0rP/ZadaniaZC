//
// Created by Wiktor Prokopiszyn on 20/02/2024.
//

#include "zadanie4.h"
#include <stdio.h>
int main()
{
    zadanie4();
    return 0;
}
void zadanie4()
{
    for(int i = 1; i <= 120; i++)
    {
        if (i % 5 == 0 &  i % 7 != 0)
        {
            printf("Foo\n");
        }
        else if(i % 5 != 0 &  i % 7 == 0)
        {
            printf("Bar\n");
        }
        else if(i % 5 == 0 &  i % 7 == 0)
        {
            printf("FooBar\n");
        }
        else
        {
            printf("%d \n", i);
        }

    }
}