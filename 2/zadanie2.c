#include <stdio.h>

//
// Created by Wiktor Prokopiszyn on 05/03/2024.
//
void zadanie2(float* a)
{
    *a = *a * 10;
}
int main (){
    float b = 12.3;
    printf("Przed wykonaniem kodu: %f\n", b);
    zadanie2(&b);
    printf("Po wykonaniu kodu: %f", b);
}
