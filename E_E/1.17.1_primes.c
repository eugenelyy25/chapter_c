#include <stdio.h>

int is_prime(int n);

int main(void){
    int num;

    do {
        printf("Enter a number: ");
        num = scanf ("%d", &num);
    }

    while (is_prime (1));//check input
        printf("%d\n", num);
        num = is_prime(num);

    if (is_prime (0)){
        printf("%d is not a prime number.", num);
        }
    return 0;
}

int is_prime(int n){
    int count = 0;
    for (int i = 1; i < n; i++){ //initialize input number
        if (n%i == 0){ //to check when number input divided has remainder
        count++;} //add the counter
    }
        if (count == 2){
            return 1; //when counter returns 2 is prime
        }
        else{
            return 0; //when counter returns more than 2 is not prime
        }
}
