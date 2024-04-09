#include <stdio.h>

union Data
{
    int number;
    float decimal;
    char letter;

};

int main( )
{

   union Data data;

    data.number = 10;
    printf( "Int : %d\n", data.number);

    data.decimal = 32.45;
    printf( "Float : %f\n", data.decimal);

    data.letter = 'A';
    printf( "Char : %c\n", data.letter);

    return 0;
}
