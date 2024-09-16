#include <stdio.h>

void fnc1(int x); //function doesn't change x value in main(), only a copy of variable

int main(void)
{
    int x = 1;

    fnc1(x);
    printf("%i\n", x);
}

void fnc1(int x) //void: function no return value
{
    x = x + 1;
}