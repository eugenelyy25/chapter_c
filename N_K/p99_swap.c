#include <stdio.h>

void swap(int* p, int* q);

int main(void)
{
    int a = 3, b = 7;

    // 3 7 printed
    printf("%i %i\n", a, b);
    swap(&a, &b);
    // 7 3 printed
    printf("%i %i\n", a, b);
    return 0;
}

void swap(int* p, int* q)
{
    int tmp;

    tmp = *p; //p takes a value, then stores in tmp
    *p = *q; //q takes b value, then stores in *p
    *q = tmp; //q takes tmp value
}