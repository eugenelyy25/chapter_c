#include <stdio.h>
#include <ctype.h>
#include <assert.h>

void test(void);
int isvowel(char ch);

int main(void)
{
    char ch;
    printf("Enter characters:\n");

    while ((ch = getchar()) != '\n') { //Read characters
        if (isvowel(ch)) {
            putchar(toupper(ch)); //Convert vowel to uppercase
        } else {
            putchar(tolower(ch)); //Convert non-vowel to lowercase
        }
    }
    test (); //assertion test
    printf("\n");

    return 0;
}

int isvowel(char ch) 
{
    ch = tolower(ch); //take char,converts to lowercase,checks a,e,i,o,u
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void test(void) 
{
    assert(isvowel('a') == 1);
    assert(isvowel('e') == 1);
    assert(isvowel('i') == 1);
    assert(isvowel('o') == 1);
    assert(isvowel('u') == 1);
    assert(isvowel('A') == 1);
    assert(isvowel('E') == 1);
    assert(isvowel('I') == 1);
    assert(isvowel('O') == 1);
    assert(isvowel('U') == 1);
    assert(isvowel('b') == 0);
    assert(isvowel('c') == 0);
    assert(isvowel('D') == 0);
    assert(isvowel('F') == 0);
    assert(isvowel('G') == 0);
}