#include <stdio.h>

void zadanie2()
{
    int grades[5][2]= {{5,1},
                       {3, 1},
                       {3,3},
                       {3, 1},
                       {4, 5}};

    float sumMath = 0, sumPhysics = 0, count=0;

    for ( int i = 0; i < 5; i++)
    {
        sumMath = sumMath + grades[i][0];
        sumPhysics = sumPhysics + grades[i][1];
        count++;
    }


    printf("Średnia matematyka: %f\n"
           "Średnia fizyka: %f\n", sumMath/count, sumPhysics/count);

}
int main()
{
    zadanie2();
    return 0;
}
