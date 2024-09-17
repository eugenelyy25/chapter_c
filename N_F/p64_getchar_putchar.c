#include <stdio.h>

int main(void)
{
    char c;

    do {
        c = getchar();
        putchar(c);
        putchar(c);
    } while (c != '!');

    putchar('\n');

    return 0;
}

/*
input: abc123!
output: aaabbcc112233!!

need CTRL+C to TERMINATE because of special character
*/