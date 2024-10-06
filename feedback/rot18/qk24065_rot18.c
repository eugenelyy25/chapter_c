#include "rot18.h"

void rot(char str[]) {
    // your code here
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (isalpha(str[i])) {
            if (islower(str[i])) 
            {
                str[i] = ((str[i] - 'a' + 13) % 26) + 'a';
            } else if (isupper(str[i])) {
                str[i] = ((str[i] - 'A' + 13) % 26) + 'A';
            }
        } else if (isdigit(str[i])) {
            str[i] = ((str[i] - '0' + 5) % 10) + '0';
        }
    }
}


void your_tests(void) {
    // your tests here
    char str[100];
    
    strcpy(str, "");
    rot(str);
    assert(strcmp(str, "") == 0);

    strcpy(str, "9876543210");
    rot(str);
    assert(strcmp(str, "4321098765") == 0);

    strcpy(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    rot(str);
    assert(strcmp(str, "NOPQRSTUVWXYZABCDEFGHIJKLM") == 0);
    
    strcpy(str, "aBcDeF123");
    rot(str);
    assert(strcmp(str, "nOpQrS678") == 0);
    
    printf("All tests passed.\n");
}

/*
FLAGS (10)
-Wall -Wextra -pedantic -std=c99 -Wvla -Wfloat-equal -g3 -fsanitize=address -fsanitize=undefined (Compiled)
	                                           
GOTO + TABS + INDENT (8)
followed house-style;
goto or break (not used)
tabs (not used)
indent (1 spaces: functions, statements; next line: statements)
                  
BRACE (5)
functions, for(), if(), else if()
                         
NAMES (4)
(int i = 0; str[i] != '\0'; i++)
(isalpha(str[i]))				from ctype.h
(islower(str[i]))				from ctype.h
str[i] = ((str[i] - 'a' + 13) % 26) + 'a';	clever
(isupper(str[i])				from ctype.h
str[i] = ((str[i] - 'A' + 13) % 26) + 'A'; 	clever
(isdigit(str[i]))				from ctype.h
char str[100]					not necessary 100				                          
REPC (4)
Visually fine.

                            
LLEN (4)
some lines above 60 characters, Ln35 
                           
MAIN (5)
                       
CAPS (2)
No #define
                           
FLEN including main(), excluding test function (5)
functions line within 20lines.
                   
MAGIC (2)
str[i] = ((str[i] - 'a' + 13) % 26) + 'a'
str[i] = ((str[i] - 'A' + 13) % 26) + 'A'
str[i] = ((str[i] - '0' + 5) % 10) + '0'
(4 magic numbers: 5, 10, 13, 26)
                          
BRIEF (3)
Not much comments.
Remove unnecessary default comments. [// your code here, // your tests here]
                           
Are all functions thoroughly tested using a test function? (15)
special characters not tested 
// could have:
    strcpy(str, "Special chars: !@#$%^&*()");
    rot(str);
    assert(strcmp(str, "Special chars: !@#$%^&*()") == 0);

didn't include flipping back to original test case.
included empty case
included number case
included alphabet case
included mixed case
no need for printf("All tests passed.\n"); obsolete

             
Does the program work correctly? (5)
code execution successful  
*/