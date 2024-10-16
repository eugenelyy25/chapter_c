#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LINE 500

char* nify(char s[]);

int main(void)
{
    char* s1 = nify("inconveniencing");
    char* s2 = nify("neill");
    assert(strcmp(s2, "Neill") == 0);
    assert(strcmp(s1, "iNcoNveNieNciNg") == 0);
    return 0;
}

// Local copy : Swaps all 'n' -> 'N'
char* nify(char s[])
{
    char t[LINE];
    strcpy(t, s);
    for (int i = 0; t[i]; i++) {
        if (t[i] == 'n') {
            t[i] = 'N';
        }
    }
    return t;
}

/*
/tmp/mz77lNBjTn.c: In function 'nify':
/tmp/mz77lNBjTn.c:29:12: warning: function returns address of local variable [-Wreturn-local-addr]
   29 |     return t;
      |            ^
/tmp/mz77lNBjTn.o
Segmentation fault
*/