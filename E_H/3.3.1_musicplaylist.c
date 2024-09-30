#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define MAX_SIZE 100

void swap(int array[], int i, int j); // Function to swap two elements
void shuffle(int array[], int n); // Function to shuffle the array
void test(void); // Function to verify the shuffle
void verify_array(int array[], int n); // Helper function to verify an array

int main(void) {
    int num_songs;
    
    printf("How many songs required? ");
    scanf("%d", &num_songs);
    
    int songs[MAX_SIZE];
    for (int i = 0; i < num_songs; i++) {
        songs[i] = i + 1;
    }
    
    test();
    
    shuffle(songs, num_songs);
    
    for (int i = 0; i < num_songs; i++) {
        printf("%d \n", songs[i]);
    }
    return 0;
}

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void shuffle(int array[], int n) {
    srand(time(0)); //seed rand. NumGen
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(array, i, j);
    }
}

void verify_array(int array[], int n) {
    int original[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        original[i] = array[i]; //copy all elements from input[] to original[]
    }
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            found += (array[i] == original[j]); 
            //verify if element present in original array
        }
        assert(found == 1); //assert each element found only once
    }
}

void test(void) {
    int test_case1[] = {1, 2, 3, 4, 5};
    int test_case2[] = {5, 4, 3, 2, 1};
    int test_case3[] = {2, 3, 1, 5, 4};
    int n = sizeof(test_case1) / sizeof(test_case1[0]); //alternatively int n = 5; 

    verify_array(test_case1, n);
    verify_array(test_case2, n);
    verify_array(test_case3, n);
}