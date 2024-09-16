#include <stdio.h>

int Hailstone(int n);

int main(void) {
    int start;

    printf("Input a number: ");
    scanf("%d", &start);

    while (start != 1) { //loop terminates when start = 1
        start = Hailstone(start);
        printf("%d\n", start);
    }
    return 0;
}

int Hailstone(int n) {
    if (n % 2 == 0) { //if n is even, divide 2
        return n / 2;
    } else {
        return (3 * n) + 1; //if n is odd, multiply 3 add 1
    }
}
/*int Hailstone(int n)
type of function_name of function(specifies argument taken int n)*/