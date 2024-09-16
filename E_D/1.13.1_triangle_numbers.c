#include <stdio.h>

int integerSqrt(int x);
int isTriangular(int num);

int main(void) {
    int num = 21;
    if (isTriangular(num))
        printf("The number is a triangular number\n");
    else
        printf("The number is NOT a triangular number\n");
    return 0;
}

int integerSqrt(int x) { //To compute the integer square root
    if (x < 0) return -1;  //Square root of negative number is not defined

    int left = 0, right = x, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        int square = mid * mid;

        if (square == x) return mid;
        if (square < x) left = mid + 1;
        else right = mid - 1;
    }
    return right; //Return the integer part of the square root
}

#define TRUE 1 //Define TRUE/FALSE values
#define FALSE 0

int isTriangular(int num) { //Returns true if num is triangular
    if (num < 0) return FALSE;

    // Considering the equation n*(n+1)/2 = num
    // The equation is: a(n^2) + bn + c = 0
    int c = -2 * num;
    int b = 1, a = 1;
    int d = b * b - 4 * a * c;

    if (d < 0) return FALSE;

    int sqrt_d = integerSqrt(d); //Find the integer square root of d

    //Check if sqrt_d * sqrt_d is exactly d
    if (sqrt_d * sqrt_d != d) return FALSE;

    //Find roots of the equation
    double root1 = (-b + sqrt_d) / (2.0 * a);
    double root2 = (-b - sqrt_d) / (2.0 * a);

    //Checking if root1 is a natural number
    if (root1 > 0 && (int)root1 == root1) return TRUE;

    //Checking if root2 is a natural number
    if (root2 > 0 && (int)root2 == root2) return TRUE;

    return FALSE;
}