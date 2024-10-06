#include "rot18.h"
#define ALPHAHALF1 'a' + 12

void rot13(char str[], int a);
void rot5(char str[],int a);

//Function to loop through each letter of string array and apply rot18 encryption
void rot(char str[])
{   int len = strlen(str); // Find length of inputted string without null character
    for(int i = 0; i < len; i++){
        //if character is a letter apply rot13 function
        if(isalpha(str[i])){ 
            rot13(str, i); 
        }
        else{
            //if character is a digit apply rot5 function
            if(isdigit(str[i])){
                rot5(str, i);
            }
        }//if character is neither a letter or digit leave as is
    }
}

//Funtion to apply rot13 encryption on characters that are alphabets
void rot13(char str[], int a)
{   
    char b = tolower(str[a]);
    if(b <= ALPHAHALF1){ // check if the letter is in the first half of alphabet
            str[a] += 13;
    }
    else{
        str[a] -= 13; // if the letter is in the second half of the alphabet and would cross 'z' wrap around
    }
}

//Function to apply rot 5 encryption on characters that are digits
void rot5(char str[], int a)
{   
    char x = str[a];
    if (x <= '4') { // Check if the digit is in the first half of 0-9
        str[a] += 5;
    } else { // If the digit is in the second half, wrap around
        str[a] -= 5;
    }
}


void your_tests(void)
{
    char t1[] = "a";  // test that 'a' should become 'n' for lowercase rot13 non-wrap
    rot13(t1, 0);
    assert(t1[0] == 'n');

    char t2[] = "n";  // test that 'n' should become 'a' for lowercase rot13 with wrap
    rot13(t2, 0);
    assert(t2[0] == 'a');

    char t3[] = "A";  // test that'A' should become 'N' for uppercase rot13 non-wrap
    rot13(t3, 0);
    assert(t3[0] == 'N');

    char t4[] = "N";  // test that 'N' should become 'A' for uppercase rot13 with wrap
    rot13(t4, 0);
    assert(t4[0] == 'A');

    char t5[] = "0";  // test that '0' should become '5' for rot5 non wrap
    rot5(t5, 0);
    assert(t5[0] == '5');

    char t6[] = "5";  // test that '5' should become '0' for rot5 with wrap
    rot5(t6, 0);
    assert(t6[0] == '0');

    char t7[] = "Hello, World!"; // test that running rot function twice return original
    rot(t7);
    printf("%s\n",t7);
    rot(t7);
    printf("%s\n",t7);
    assert(strcmp(t7, "Hello, World!") == 0);

    
    printf("All test have passed\n");
}

/*
FLAGS (10)
-Wall -Wextra -pedantic -std=c99 -Wvla -Wfloat-equal -g3 -fsanitize=address -fsanitize=undefined (Compiled)
                                        
GOTO + TABS + INDENT (7)
followed house-style;
goto or break (not used)
tabs (used: Ln29,Col13)
indent (next line, non-spaced; space: Ln40, Col19)
                    
BRACE (5)
functions, for(), if(), else()
                         
NAMES (3)
int len = strlen(str)
(int i = 0; i < len; i++)
(isalpha(str[i]))		from ctype.h
(isdigit(str[i]))		from ctype.h
void rot13(char str[], int a)	uses a as argument
char b = tolower(str[a]);	uses b as char type 
(b <= ALPHAHALF1)		could use clearer definition or just maintain 'a' + 12
void rot5(char str[], int a)	uses a as argument
char x = str[a];		uses x as char type
(x <= '4')			first half of digits
                           
REPC (3)
void rot13(char str[], int a);	could've been inside void rot(char str[]) -> rot13(str, i); 
void rot5(char str[],int a);	could've been inside void rot(char str[]) -> rot5(str, i);
                           
LLEN (3)
Code lines within 60 characters. But comments makes it longer.
                           
MAIN (5)
                         
CAPS (5)
#define used & capitalized
                           
FLEN including main(), excluding test function (5)
functions line within 20lines.
                    
MAGIC (3)
str[a] += 13;
str[a] -= 13;
str[a] += 5;
str[a] -= 5;
(2 magic numbers: 5, 13)
                         
BRIEF (3)
Well documented (functions, statements).
Long-Line Comments.
Test comments should be redacted, as its already asserted.

                           
Are all functions thoroughly tested using a test function? (15)
most test and edge cases covered.
clever to include rot(t7) twice, flipping character back to original
no need for printf("All test have passed.\n"); obsolete
included lowercase alphabet(first-middle)
included uppercase alphabet(first-middle)
included number case
included mixed case
               
Does the program work correctly? (5)
code execution successful
*/