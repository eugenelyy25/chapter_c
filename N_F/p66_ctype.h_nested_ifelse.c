#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int c;
    while ((c = getchar()) != EOF) { //nested if else
        if (islower(c)) {
            putchar(toupper(c));
        } else {
            putchar(c);
        }
    }
    putchar('\n');
    return 0;
}
