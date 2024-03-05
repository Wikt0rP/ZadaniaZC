#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
//
// Created by Wiktor Prokopiszyn on 05/03/2024.
//
typedef struct
{
    char studentName[128];
    double grade;
}Student;

void sortStudentsByGrade(Student* students, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(students[j].grade < students[j+1].grade)
            {
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}
int main()
{
    srand(time(0));

    char names[128][10] = {"Maciek", "Andrzej", "Kuba", "Wiktor", "Kamil", "Krzysiek", "Piotrek", "Kasia", "Ania", "Basia"};
    Student students[100];

    for (int a = 0; a < 100; a++)
    {
        strcpy(students[a].studentName, names[a%10]);
        double x = 1 + (rand() / (double)RAND_MAX) * 4;
        students[a].grade = x;
        //printf("%s: %.2f\n", students[a].studentName, students[a].grade);
    }

    sortStudentsByGrade(students, 100);

    printf("\nPosortowani studenci:\n");
    for (int a = 0; a < 100; a++)
    {
        printf("%s: %.2f\n", students[a].studentName, students[a].grade);
    }
    return 0;
}

