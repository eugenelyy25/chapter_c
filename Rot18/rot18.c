#include "rot18.h"

#define ROT13_SHIFT 13
#define ROT5_SHIFT 5
#define ALPHABET_SIZE 26
#define DIGIT_SIZE 10

void rot(char str[]){
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                //ASCII + (Zero-based Index)
                str[i] = 'A' + (str[i] - 'A' + ROT13_SHIFT) % ALPHABET_SIZE; 
                //rot13 transform uppercase, wrap 13
            } else {
               str[i] = 'a' + (str[i] - 'a' + ROT13_SHIFT) % ALPHABET_SIZE; 
                //rot13 transform lowercase, wrap 13
            }
        } else if (isdigit(str[i])) {
            str[i] = '0' + (str[i] - '0' + ROT5_SHIFT) % DIGIT_SIZE; 
            //rot5 transform digit, wrap 5
        }//ignore non alphanum
    }
}

void your_tests(void){

    char test1[] = "a";
    rot(test1);
    assert(strcmp(test1, "n") == 0);

    char test2[] = "b";
    rot(test2);
    assert(strcmp(test2, "o") == 0);

    char test3[] = "n";
    rot(test3);
    assert(strcmp(test3, "a") == 0);

    char test4[] = "0";
    rot(test4);
    assert(strcmp(test4, "5") == 0);

    char test5[] = "1";
    rot(test5);
    assert(strcmp(test5, "6") == 0);

    char test6[] = "5";
    rot(test6);
    assert(strcmp(test6, "0") == 0);

    char test7[] = "!";
    rot(test7);
    assert(strcmp(test7, "!") == 0);

    char test8[] = " \t\n";
    rot(test8);
    assert(strcmp(test8, " \t\n") == 0);

    char test9[] = "i want to go to kansas and live with aunt em and uncle henry well then what can be done";
    rot(test9);
    assert(strcmp(test9, "v jnag gb tb gb xnafnf naq yvir jvgu nhag rz naq hapyr urael jryy gura jung pna or qbar") == 0);
    rot(test9);
    assert(strcmp(test9, "i want to go to kansas and live with aunt em and uncle henry well then what can be done") == 0);
}