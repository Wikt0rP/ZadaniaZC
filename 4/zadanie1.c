
#include <stdio.h>

unsigned long long factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    printf("Podaj liczbę do obliczenia silni: ");
    int n;
    scanf("%d", &n);
    printf("%llu", factorial(n));

    return 0;
}