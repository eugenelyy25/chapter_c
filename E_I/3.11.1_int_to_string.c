#include <stdio.h>
#include <string.h>
#include <assert.h>

// Function prototypes
void intToStr(int num, char str[]);
void test(void);

int main(void) {
    test();
    return 0;
}

void intToStr(int num, char str[]) {
    int i = 0;
    int isNegative = 0;

    // Handle negative numbers
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    // Process each digit
    do {
        str[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    // Add negative sign if needed
    if (isNegative) {
        str[i++] = '-';
    }

    // Null-terminate the string
    str[i] = '\0';

    // Reverse the string
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void test(void) {
    char str[100];  // Fixed: Declare str as a char array

    intToStr(12345, str);
    assert(strcmp(str, "12345") == 0);

    intToStr(-12345, str);
    assert(strcmp(str, "-12345") == 0);

    intToStr(0, str);
    assert(strcmp(str, "0") == 0);

    intToStr(1, str);
    assert(strcmp(str, "1") == 0);

    intToStr(-1, str);
    assert(strcmp(str, "-1") == 0);

    printf("All tests passed!\n");
}