#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MINSINHR 60
#define HRSINDAY 24 

void test(void);
int tme2mins(int h, int m);
int diff(int t1, int t2);

int main(void)
{
    test ();
    int h1, m1;
    int h2, m2;
    if (scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2) != 4){
        printf("PANIC!\n");
        exit(1);
        } 
    int t1 = tme2mins(h1, m1);
    int t2 = tme2mins(h2, m2);
    int d = diff(t1, t2);
    printf("Difference: %02d:%02d\n", d/60, d%60);
    return 0;
}

void test(void)
{
    assert(tme2mins(0, 0) == 0);
    assert(tme2mins(5, 15) == 315);
    assert(tme2mins(22, 20) == 22*60+20);

    assert(diff(240, 300) == 60);
    assert(diff(23*60, 60) == 120);
}

int tme2mins(int h, int m)
{
    return h*60 + m;
}

int diff(int t1, int t2)
{
    if(t1 < t2){
        return t2 - t1;
    }
    return t2 + (24*60 - t1);
}

/*
rk24286@LAPTOP-H6030QU6:~/github/chapter_c/E_E$ clang -Wfloat-equal -Wall -Wextra 1.19.1_timeflies_drneil.c -o 1.19.1_timeflies_drneil 
rk24286@LAPTOP-H6030QU6:~/github/chapter_c/E_E$ touch testcase.txt
rk24286@LAPTOP-H6030QU6:~/github/chapter_c/E_E$ mv testcase.txt 1.19.1_testcase.txt
rk24286@LAPTOP-H6030QU6:~/github/chapter_c/E_E$ ./1.19.1_timeflies_drneil < 1.19.1_testcase.txt
Difference: 12:00
*/