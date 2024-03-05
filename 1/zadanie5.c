//
// Created by Wiktor Prokopiszyn on 20/02/2024.
//

#include "zadanie5.h"
#include <stdio.h>
int main()
{
    zadanie5();
    return 0;
}
void zadanie5()
{
    int liczba = 0, suma = 0;
    printf("Podaj liczbe\n ");
    scanf("%d", &liczba);
    if (liczba < 0)
    {
        liczba = 0;
    }
    else{

    }
    for(int i = 0; i < liczba; i++)
    {
        if(i % 3 == 0 && i % 5 == 0 )
        {
            suma = suma + i;
            continue;
        }
        else if (i % 3 == 0)
        {
            suma = suma + i;
        }
        else if (i % 5 == 0)
        {
            suma = suma + i;
        }
        else
        {
            continue;
        }
    }
    printf("Suma wynosi: %d", suma);
}