#include <stdio.h>

int main(void)
{
    int i = 5;
    int* p = &i; //p is pointing at i
    printf("%i\n", *p);
    i = 17;
    printf("%i\n", *p);
    *p = 99;
    printf("%i\n", i);

    return 0;
}
/*
if *p not placed, you print p address base 16(0F ....)
*/