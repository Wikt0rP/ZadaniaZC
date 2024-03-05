#include <stdio.h>

//
// Created by Wiktor Prokopiszyn on 05/03/2024.
//
void zadanie1();
int main()
{
    zadanie1();
    return 0;
}
void zadanie1()
{
    int x = 10;
    int *pointer = &x;
    *pointer = 15;
    printf("%d\n", x);
    printf("%d", *pointer);
}