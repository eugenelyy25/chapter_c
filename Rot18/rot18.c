#include "rot18.h"

void rot(char str[]){
    // your code here
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                //ASCII + (Zero-based Index)
                str[i] = 'A' + (str[i] - 'A' + 13) % 26; 
                //rot13 transform uppercase, wrap 13
            } else {
               str[i] = 'a' + (str[i] - 'a' + 13) % 26; 
                //rot13 transform lowercase, wrap 13
            }
        } else if (isdigit(str[i])) {
            str[i] = '0' + (str[i] - '0' + 5) % 10; 
            //rot5 transform digit, wrap 5
        }//ignore non alphanum
    }
}

// any other functions here

void your_test(void){
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
}