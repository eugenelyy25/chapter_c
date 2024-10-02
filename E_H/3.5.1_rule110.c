#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define WIDTH 31
#define STEPS 15

void print_line(int line[], int width);
void generate_next_line(int current_line[], int next_line[], int width);
void test(void);

int main(void) {
    int current_line[WIDTH] = {0};
    int next_line[WIDTH] = {0};
    char choice;

    printf("Enter 'r' for a random initial line or 'c' for a single 'on' cell in the center: ");
    scanf(" %c", &choice);

    if (choice == 'r') {
        srand(time(NULL));
        for (int i = 0; i < WIDTH; i++) {
            current_line[i] = rand() % 2;
        }
    } else if (choice == 'c') {
        current_line[WIDTH / 2] = 1;
    } else {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    print_line(current_line, WIDTH);

    for (int step = 0; step < STEPS; step++) {
        generate_next_line(current_line, next_line, WIDTH);
        print_line(next_line, WIDTH);

        for (int i = 0; i < WIDTH; i++) {
            current_line[i] = next_line[i];
        }
    }

    test();

    return 0;
}

void print_line(int line[], int width) {
    for (int i = 0; i < width; i++) {
        printf("%d", line[i]);
    }
    printf("\n");
}

void generate_next_line(int current_line[], int next_line[], int width) {
    for (int i = 0; i < width; i++) {
        int left = (i == 0) ? 0 : current_line[i - 1];
        int center = current_line[i];
        int right = (i == width - 1) ? 0 : current_line[i + 1];

         // Apply Rule 110 conditions directly
        if ((left == 1 && center == 1 && right == 0) || // 110
            (left == 1 && center == 0 && right == 1) || // 101
            (left == 0 && center == 1 && right == 1) || // 011
            (left == 0 && center == 1 && right == 0) || // 010
            (left == 0 && center == 0 && right == 1))   // 001
        {
            next_line[i] = 1;
        } else {
            //111, 100, 000
            next_line[i] = 0;
        }
    }
}

void test(void) {
    int current_line[WIDTH] = {0};
    int next_line[WIDTH] = {0};
    current_line[WIDTH / 2] = 1;

    generate_next_line(current_line, next_line, WIDTH);
    assert(next_line[WIDTH / 2 - 1] == 1);
    assert(next_line[WIDTH / 2] == 1);
    assert(next_line[WIDTH / 2 + 1] == 1);
}