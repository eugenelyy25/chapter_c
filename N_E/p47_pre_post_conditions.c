#include <stdio.h>
#include <assert.h>

int numfactors(int f);

int main(void)
{
    int n = 12;
    printf("Number of factors in %i is %i\n", n, numfactors(n));
    return 0;
}

int numfactors(int k)
{
    int count = 0;

    assert(k >= 1); //Avoid trying zero
    for(int i=1; i<=k; i++){
        if((k%i)==0){
            count++;
        }
    }
    assert(count <= k); //assert states some test to be true, otherwise appear eeror
    return count;
}
//preconditions check input to functions
//postconditions check returns from functions
//assert is safer, ensure correct answer return