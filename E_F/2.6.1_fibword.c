#include <stdio.h>
#include <math.h>
#include <assert.h>

#define PHI 1.61803398875 //Define the golden ratio

void test(void);
int fibword_phi(int n);

int main(void) 
{
    int n;
    printf("Enter the number of digits to print: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("%d", fibword_phi(i));
    }
    test(); //assertion test
    printf("\n");

    return 0;
}

int fibword_phi(int n) 
{
    //Calculate the nth digit using the given formula
    int nth_digit = 2 + floor(n * PHI) - floor((n + 1) * PHI);
    
    //Return 1 if the nth digit is 1, otherwise 0
    return nth_digit == 1;
}

void test(void)
{
    assert(fibword_phi(1) == 0);  // S1: 0
    assert(fibword_phi(2) == 1);  // S2: 01
    assert(fibword_phi(3) == 0);  // S3: 010
    assert(fibword_phi(4) == 0);  // S4: 0100
    assert(fibword_phi(5) == 1);  // S5: 01001
    assert(fibword_phi(6) == 0);  // S6: 010010
    assert(fibword_phi(7) == 1);  // S7: 0100101
    assert(fibword_phi(8) == 0);  // S8: 01001010
    assert(fibword_phi(9) == 0);  // S9: 010010100
    assert(fibword_phi(10) == 1); // S10: 0100101001
}