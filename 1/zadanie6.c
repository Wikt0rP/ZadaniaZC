//
// Created by Wiktor Prokopiszyn on 20/02/2024.
//
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int Random();
void Kamien(int historia[256][2], int i);
void Historia(int historia[256][2], int i);

void zadanie6()
{
    int gramy = 0, i = 0;
    int historia[256][2];
    while (gramy == 0)
    {
        Kamien(historia, i);
        i++;
        if(i >= 256)
        {
            i = 0;
        }

        printf("\n//// WYBIERZ ////\n"
               "1 - Wyjdź \n"
               "2 - Historia \n"
               "0 - Graj dalej\n");

        scanf("%d", &gramy);

        if (gramy == 2)
        {
            Historia(historia, i);
            gramy = 0;
        }
    }
}

void Kamien(int historia[128][2], int i)
{
    int wybor;
    int losowa = Random();
    //1 - kamien 2 - papier 3 - nozyce

    printf("\n"
           "Wybierz \n"
           "1 - kamien \n"
           "2 - papier \n"
           "3 - nozyce\n");

    scanf("%d", &wybor);

    if(wybor != 1 && wybor != 2 && wybor != 3)
    {
        printf("Nieprawidłowe dane wejściowe. Wprowadź 1, 2 lub 3.\n");
        return;
    }

    int wynikStarcia = wybor-losowa;
    historia[i][0] = wybor;
    historia[i][1] = losowa;
    /*
     * 1 -2 = -1 | 1 -3 = -2
     * 2 -3 = -1 | 2 -1 = 1
     * 3 -1 = 2  | 3 -2 = 1
     *
     * dla -1, 2 - wygrywasz
     * dla -2, 1 - przegrywasz
     * dla 0    - remis
     */
    switch (wynikStarcia)
    {
        case -1:
        case 2:
            printf("Przegrałeś: \n"
                   "Twój wybór: %d\n"
                   "Wybor przeciwnika: %d\n"
                   "1 - kamien \n"
                   "2 - papier \n"
                   "3 - nozyce\n", wybor, losowa);
            break;
        case -2:
        case 1:
            printf("Wygrałeś: \n"
                   "Twój wybór: %d\n"
                   "Wybor przeciwnika: %d\n"
                   "1 - kamien \n"
                   "2 - papier \n"
                   "3 - nozyce\n", wybor, losowa);
            break;
        case 0:
            printf("Remis: \n"
                   "Twój wybór: %d\n"
                   "Wybor przeciwnika: %d\n"
                   "1 - kamien \n"
                   "2 - papier \n"
                   "3 - nozyce\n", wybor, losowa);
            break;
        default:
            printf("error");
            break;
    }
}

int Random()
{
    srand(time(0));
    int random_number = rand() % 3 + 1;
    return random_number;
}

void Historia(int historia[128][2], int i)
{
    printf("Historia gry:\n");
    for(int j = 0; j < i; j++)
    {
        printf("////////////////////////////\n"
               "RUNDA %d\n"
               "///////////////////////////\n", j+1);

        int a = historia[j][0] - historia[j][1];

        switch (a)
        {
            case -1:
            case 2:
                printf("Przegrałeś: \n"
                       "Twój wybór: %d\n"
                       "Wybor przeciwnika: %d\n"
                       "1 - kamien \n"
                       "2 - papier \n"
                       "3 - nozyce\n", historia[j][0], historia[j][1]);
                break;
            case -2:
            case 1:
                printf("Wygrałeś: \n"
                       "Twój wybór: %d\n"
                       "Wybor przeciwnika: %d\n"
                       "1 - kamien \n"
                       "2 - papier \n"
                       "3 - nozyce\n", historia[j][0], historia[j][1]);
                break;
            case 0:
                printf("Remis: \n"
                       "Twój wybór: %d\n"
                       "Wybor przeciwnika: %d\n"
                       "1 - kamien \n"
                       "2 - papier \n"
                       "3 - nozyce\n \n", historia[j][0], historia[j][1]);
                break;
            default:
                printf("error");
                break;
        }
        printf("\n");
    }
}




int main()
{
    zadanie6();
    return 0;
}
