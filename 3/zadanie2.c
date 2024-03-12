#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int rows, columns;
    printf("Podaj liczbę wierszy: ");
    scanf("%d", &rows);
    printf("Podaj liczbę kolumn: ");
    scanf("%d", &columns);


    //alokacja
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }

    //Generowanie liczb do macierzy
    srand(time(0));
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }

    //Wyświetlenie macierzy
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Zwolnienie zaalokowanej pamięci
    for(int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
