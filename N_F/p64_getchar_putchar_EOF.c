// Outputs characters twice
#include <stdio.h>

int main(void)
{
    char c; // char or int?

    while ((c = getchar()) != EOF) {
        putchar(c);
        putchar(c);
    }
    
    putchar('\n');

    return 0;
}
//EOF end-of-file is defined inside stdio.h
//CTRL+D to TERMINATE