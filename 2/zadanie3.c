#include <math.h>
#include <printf.h>

//
// Created by Wiktor Prokopiszyn on 05/03/2024.
//
typedef struct
{
    int x;
    int y;
}Point;
typedef struct
{
    Point a;
    Point b;
    Point c;
    Point d;
}Rectangle;
void zadanie3Rect(Rectangle *a)
{
    //Pole A----B
    //      |
    //      |
    //      C---D

    int dx = a->b.x - a->a.x;
    int dy = a->b.y - a->a.y;
    int lenght = sqrt(dx*dx+dy*dy);

    int dx2 = a->a.x - a->c.x;
    int dy2 = a->a.y - a->c.y;
    int hight = sqrt(dx2*dx2+dy2*dy2);

    printf("Pole: %d \n", lenght*hight);
    printf("Obw: %d\n", 2*lenght+2*hight);
}
void zadanie3(Point *p1)
{
    p1->y*=10;
    p1->x*=10;
}
int main()
{ Point p1 = {3,4};
    Rectangle r = {.a={1,2}, .b={3,2},
            .c={1,-1}, .d={3,-1}};
    zadanie3Rect(&r);
    zadanie3(&p1);
    printf("%d | %d \n", p1.x, p1.y);
    return 0;
}