//Refer back p45_call_by_value.c

#include <stdio.h>

void changex(int x);

int main(void)
{
    int x = 1;

    changex(x);
    printf("%i\n", x); 
    //% means its a reference (E.g. scanf %d)
    return 0;
}

void changex(int x)
{
    x = x + 1; //local copies will remain the same
}

/*
c* (pointers) ~ an address (E.g. 0xffeb0004) int *p
cannot change value v in main() since a copy made
E.g scanf("%i", &v); v: variable, &v: address/location in memory 
*/
