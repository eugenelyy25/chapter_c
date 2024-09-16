#include <stdio.h>
#include <assert.h>

int numfactors(int f);

int main(void)
{
    assert(numfactors(17) == 2);
    assert(numfactors(12) == 6);
    assert(numfactors(6) == 4);
    assert(numfactors(0) == 0); // often place inside test()
    return 0; //can be called from main()
}

int numfactors(int k)
{
    int count = 0;

    for(int i=1; i <= k; i++){
        if( (k%i)==0){
            count++;
        }
    }
    return count;
}
//will have no output if no error