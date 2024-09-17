#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int c;
    while ((c = getchar()) != EOF){
            putchar(toupper(c));
            /*toupper() returns non-lowercase chars unaltered*/
        }
    putchar('\n');
    return 0;
}
/*Input: Hello World!
Output: HELLO WORLD!*/