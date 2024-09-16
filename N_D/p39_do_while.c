//Simple do while countdown
#include <stdio.h>

int main(void)
{
    int n = 9;

    /*This program always prints at least one
    number, even if n initialized to 0*/
    do{
        printf("%i ", n);
        n--;
    }while(n > 0);
    printf("\n");
    return 0;
}
//do-while always executes 1 time