#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void nify(char s[]);

int main(void)
{
    char s[] = "neill";  // Correct: Using a mutable array
    nify(s);
    printf("%s\n", s);  // This will print "Neill"
    return 0;
}

/*
int main(void)
{
    nify("neill");  // Error: modifying a string literal
    return 0;
}
*/

// In-Place : Swaps all 'n' -> 'N'
void nify(char s[])
{
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'n') {
            s[i] = 'N';
        }
    }
}
