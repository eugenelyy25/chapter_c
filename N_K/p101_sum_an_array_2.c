#include <stdio.h>

#define NUM 5

int sum(int a[]);

int main(void)
{
    int n[NUM] = {10, 12, 6, 7, 2};

    printf("%i\n", sum(n));
    return 0;
}

int sum(int a[])
{
    int tot = 0;

    for(int i = 0; i < NUM; i++) {
        tot += *(a + i); //*(a + i) not normally used
    }
    return tot;
}
/*
Difficult to read pointers
*/
