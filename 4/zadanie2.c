#include <stdio.h>

int binarySearch(int array[], int left, int right, int x)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == x)
        {
            return mid;
        }

        if (array[mid] > x)
        {
            return binarySearch(array, left, mid - 1, x);
        }
        else
        {
            return binarySearch(array, mid + 1, right, x);
        }
    }

    return -1;
}

int main(void)
{
    int array[] = {2, 3, 4, 10, 40, 50, 100};
    int n = sizeof(array) / sizeof(array[0]);
    int x;

    printf("Podaj liczbę do wyszukania: ");
    scanf("%d", &x);

    int result = binarySearch(array, 0, n - 1, x);
    if (result == -1)
    {
        printf("Element nie jest obecny w tablicy\n");
    }
    else
    {
        printf("Element jest obecny na indeksie %d\n", result);
        printf("Tablica: ");

        for (int i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
    }

    return 0;
}