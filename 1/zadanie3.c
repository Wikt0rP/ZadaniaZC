//
// Created by Wiktor Prokopiszyn on 20/02/2024.
//

#include "zadanie3.h"
#include <stdio.h>

int main()
{
    zadanie3();
    return 0;
}
int Silnia(int liczba);

void zadanie3()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for(int i = 0; i < 10; i++)
    {
        int wynik = 0;
        wynik = Silnia(array[i]);
        printf("Silnia z %d wynosi: %d \n",array[i], wynik);
    }
}

int Silnia(int liczba)
{
    int wynik = 1;
    if (liczba == 0)
    {
        return 1;
    }
    if (liczba > 0)
    {
        for(int i = 1; i <= liczba; i++)
        {
            wynik = wynik * i;
        }
        return wynik;
    }
}


