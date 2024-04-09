#include <stdio.h>

int sum (int a, int b)
{
    return a + b;
}

int sub (int a, int b)
{
    return a - b;
}

int mul (int a, int b)
{
    return a * b;
}

int main()
{
    int (*p) (int, int);
    int a = 10, b = 5;
    char operation;

    printf("Twoje liczby to: %d i %d\n", a, b);
    printf("Wybierz operacje: +, -, *\n");
    scanf("%c", &operation);

    switch (operation)
    {
        case '+':
            p = sum;
            break;
        case '-':
            p = sub;
            break;
        case '*':
            p = mul;
            break;
        default:
            printf("Nieznana operacja\n");
            return 1;
    }

    int wynik = p(a, b);
    printf("Wynik: %d\n", wynik);
    return 0;
}