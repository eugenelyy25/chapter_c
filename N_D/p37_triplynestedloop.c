// Triples of integers that sum to N
#include <stdio.h>

#define N 7

int main(void)
{
	int  cnt = 0, i, j, k;
	
	for(i = 0; i <= N; i++){
		for(j = 0; j <= N; j++){
			for(k = 0; k <= N; k++){
				if(i + j + k == N){
				++cnt;
				printf("%3i%3i%3i\n", i , j , k);
				}
			}
		}
	}
	printf("\nCount: %i\n", cnt);
	return 0;
}

/*Output
0 0 7
0 1 6
0 2 5
0 3 4
0 4 3
0 5 2
0 6 1
0 7 0
etc
4 3 0
5 0 2
5 1 1
5 2 0
6 0 1
6 1 0
7 0 0
Count: 36
*/