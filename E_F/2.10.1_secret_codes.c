#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

int secret(int a);
void encode(char text[]);
void test(void);

int main(void) 
{
    char text[256];
    printf("Enter text to encode: ");
    scanf("%[^\n]%*c", text); //Read until newline encountered

    
    printf("Original: %s\n", text);
    encode(text);
    printf("Encoded: %s\n", text);

    test(); //assertion test

    return 0;
}

int secret(int a) {
    if (isalpha(a)) {
        if (islower(a)) {
            return 'z' - (a - 'a');
        } else {
            return 'Z' - (a - 'A');
        }
    }
    return a; //Non-letters are returned unaffected
}

void encode(char text[]) {
    size_t length = strlen(text);
    for (size_t i = 0; i < length; i++) {
        text[i] = secret(text[i]);
    }
}

void test(void) 
{
    assert(secret('a') == 'z');
    assert(secret('b') == 'y');
    assert(secret('c') == 'x');
    assert(secret('A') == 'Z');
    assert(secret('B') == 'Y');
    assert(secret('C') == 'X');
    assert(secret('1') == '1'); //Non-letter chars remain the same
    assert(secret('!') == '!'); //Non-letter chars remain the same

    char testStr1[] = "abc XYZ";
    encode(testStr1);
    assert(strcmp(testStr1, "zyx CBA") == 0);

    char testStr2[] = "The Quick Brown Fox Jumps Over the Lazy Dog !";
    encode(testStr2);
    assert(strcmp(testStr2, "Gsv Jfrxp Yildm Ulc Qfnkh Levi gsv Ozab Wlt !") == 0);
}