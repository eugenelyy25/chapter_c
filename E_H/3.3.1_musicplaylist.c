#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void swap(int array[], int i, int j);
void shuffle(int array[], int n);
void test(void);

int *songs;
int num_songs;

int main(void)
{
    // Step 1: Get user input
    printf("How many songs required? ");
    scanf("%d", &num_songs);

    // Step 2: Generate list of songs
    songs = (int *)malloc(num_songs * sizeof(int));
    for (int i = 0; i < num_songs; i++) {
        songs[i] = i + 1;
    }

    // Step 3: Shuffle the list
    shuffle(songs, num_songs);

    // Step 4: Output the shuffled list
    printf("Output:\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%d ", songs[i]);
    }
    printf("\n");

    // Step 5: Run the test
    test();

    // Free the allocated memory
    free(songs);

    return 0;
}

// Function to swap two elements without using pointers
void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// Function to shuffle the array without using pointers
void shuffle(int array[], int n)
{
    srand(time(0)); // Seed the random number generator
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(array, i, j);
    }
}

// Test function to verify the shuffle
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void swap(int array[], int i, int j);
void shuffle(int array[], int n);
void test(void);

int *songs;
int num_songs;

int main(void)
{
    // Step 1: Get user input
    printf("How many songs required? ");
    scanf("%d", &num_songs);

    // Step 2: Generate list of songs
    songs = (int *)malloc(num_songs * sizeof(int));
    for (int i = 0; i < num_songs; i++) {
        songs[i] = i + 1;
    }

    // Step 3: Shuffle the list
    shuffle(songs, num_songs);

    // Step 4: Output the shuffled list
    printf("Output:\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%d ", songs[i]);
    }
    printf("\n");

    // Step 5: Run the test
    test();

    // Free the allocated memory
    free(songs);

    return 0;
}

// Function to swap two elements without using pointers
void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// Function to shuffle the array without using pointers
void shuffle(int array[], int n)
{
    srand(time(0)); // Seed the random number generator
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(array, i, j);
    }
}

// Test function to verify the shuffle
void test(void)
{
    int original[num_songs];
    for (int i = 0; i < num_songs; i++) {
        original[i] = songs[i];
    }

    shuffle(songs, num_songs);

    // Check that all original elements are present in the shuffled array
    int found[num_songs];
    for (int i = 0; i < num_songs; i++) {
        found[i] = 0;
    }

    for (int i = 0; i < num_songs; i++) {
        for (int j = 0; j < num_songs; j++) {
            if (songs[i] == original[j]) {
                found[j] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < num_songs; i++) {
        assert(found[i] == 1);
    }
}

