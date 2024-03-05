//
// Created by Wiktor Prokopiszyn on 20/02/2024.
//

#include <stdio.h>
#include "zadanie1.h"
int main()
{
    zadanie1();
    return 0;
}
void zadanie1()
{
    char name[30];
    printf("Podaj swoje imię: ");
    scanf("%s", name);
    printf("\nWitaj %s", name);
}