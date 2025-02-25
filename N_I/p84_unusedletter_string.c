#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define ALPHASIZE 26

int main(void)
{
    char s[100] =   "The Quick Brown Fox Leaps" \
                    "Over the Lazy Dog";
    bool used[ALPHASIZE] = {false};
    int i = 0;
    while(s[i]){
        char c = tolower(s[i]);
        if (islower(c)){
            used [c -'a'] = true;
        }
        i++;
    }
    for(i=0; i<ALPHASIZE; i++){
        if (!used[i]){
            printf("%c has not been used.\n", i + 'a');
        }
    }
     return 0;
}

/*
Initialising Strings (example):
char w[6] = "Hello";
w[0] = 'a';
w[1] = 'b';
w[2] = 'c';
w[3] = '\0';

"abc" -- length = 3, size = 4
because include the \0 null character

scanf("%s", w); -- reads string terminated by Space/EOF
*/