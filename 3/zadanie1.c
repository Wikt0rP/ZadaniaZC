//
// Created by Wiktor Prokopiszyn on 12/03/2024.
//
#include <stdio.h>
#include <stdlib.h>


void Pascal(int n)
{
    int **arr = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc((i + 1) * sizeof(int));
        arr[i][0]= arr[i][i] = 1;

        for(int j = 1; j < i; j++)
        {
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
        free(arr[i]);
    }
    free(arr);
}
int main()
{
    int n;
    printf("Podaj wysokość trójkąta Pascal'a: \n");
    scanf("%d", &n);

    Pascal(n);
    return 0;
}

