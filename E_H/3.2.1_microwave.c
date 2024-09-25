#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int min_buttons_presses(int cooking_time);
void test(void);

int main (void)
{
    int time_required;

    printf("Type the time required:\n ");
    scanf("%d", &time_required);
    printf("Number of button presses = %d\n", min_buttons_presses(time_required));
    test(); //assertion test
    return 0;
}

int min_buttons_presses(int cooking_time)
{
    int button_times [] = {600, 60, 10}; //initialize buttons array 10m,1m,10s
    int presses = 0; //initialize counter for no. button press
    int i;

    for (i=0; i < 6; i++){
        if (cooking_time == 0) { //no cooking time
            break;
        }
        else{
            presses = presses + cooking_time / button_times[i];
            cooking_time = cooking_time % button_times[i];
        }
    } 
    return presses;
}

void test(void)
{
    assert(min_buttons_presses(25) == 3);
    assert(min_buttons_presses(705) == 7);
}