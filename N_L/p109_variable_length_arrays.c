#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define WORD 500

int main(void)
{
    printf("Please type a string:\n");
    char s[WORD];
    assert(scanf("%s", s) == 1);  // Checking if input is valid
    int n = strlen(s) + 1;
    char t[n];  // Using variable-length array
    // Deep copy: character by character
    strcpy(t, s);
    printf("%s %s\n", s, t);
    return 0;
}
