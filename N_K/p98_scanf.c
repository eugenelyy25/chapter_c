#include <stdio.h>

int main(void)
{
    int i;
    int* p = &i; //may swap between *p and &i
    printf("Please Type a number: ");
    scanf("%i", &i);
    printf("%i\n", i);
    printf("Please Type a number: ");
    scanf("%i", p);
    printf("%i\n", i);

    return 0;
}

/*
Case: y=x (y equivalent to x)
float x=5, y=8, *p;
 p=&x;
 y=*p;

 Summary: 
 dereference operator * is inverse 
 of address operator &
*/

