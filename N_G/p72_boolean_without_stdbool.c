#include <stdio.h>
#include <assert.h>

typedef enum bool {false , true} bool; //without stdbool

int main(void)
{
    bool b = true;
    if (b) {
        printf("It ’s true!\n");
    }
    else {
        printf("It ’s false!\n");
    }
    return 0;
}