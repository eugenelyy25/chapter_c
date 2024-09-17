#include <stdio.h>

int main(void) {
    float time1, time2;
    float hours1, minutes1, hours2, minutes2;
    
    //Input Time
    printf("Enter two times: ");
    scanf("%f:%f %f:%f", &hours1, &minutes1, &hours2, &minutes2);
    
    time1 = hours1 + minutes1/60;
    time2 = hours2 + minutes2/60;
    
    float difference = time2 - time1;
    if (difference < 0)
    {
        difference = difference + 24;
    }
    
    //Convert difference to hours, minutes, and seconds
    int hours = (int)difference;
    float minutesFloat = (difference - hours) * 60;
    int minutes = (int)minutesFloat;
    float seconds = (minutesFloat - minutes) * 60;
    
    printf("Difference is: %d:%d\n", hours, minutes);
    return 0;
}