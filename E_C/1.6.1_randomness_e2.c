#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int plus_cnt,minus_cnt,median,difference;
    plus_cnt = 0;
    minus_cnt = 0;
    median = RAND_MAX/2;
    
    for (int i=0;i<500;i++){
    double value=rand()%(RAND_MAX);
    difference=plus_cnt-minus_cnt;
    printf("itteration : %d values plus_cnt=%d,minus_cnt=%d,difference=%d, RAND_MAX=%f\n",i,plus_cnt,minus_cnt,difference,RAND_MAX);
    if (value < median) {
            minus_cnt++;}
    }
return 0;
}
