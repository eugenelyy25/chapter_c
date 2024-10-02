#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define WIDTH 31
#define STEPS 15

void print_line(int line[], int width);
void generate_next_line(int current_line[], int next_line[], int width, int rule);
void test(void);

int main(void) {
    int current_line[WIDTH] = {0};
    int next_line[WIDTH] = {0};
    char choice;
    int rule = 110; // Example rule value

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
        generate_next_line(current_line, next_line, WIDTH, rule);
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

void generate_next_line(int current_line[], int next_line[], int width, int rule) {
    for (int i = 0; i < width; i++) {
        int left = (i == 0) ? 0 : current_line[i - 1];
        int center = current_line[i];
        int right = (i == width - 1) ? 0 : current_line[i + 1];

        next_line[i] = 0;

        switch (rule) {
            case 110:
                if ((left == 1 && center == 1 && right == 0) || // 110
                    (left == 1 && center == 0 && right == 1) || // 101
                    (left == 0 && center == 1 && right == 1) || // 011
                    (left == 0 && center == 1 && right == 0) || // 010
                    (left == 0 && center == 0 && right == 1))   // 001
                {
                    next_line[i] = 1;
                }
                break;
            case 30:
                if ((left == 1 && center == 0 && right == 0) || // 100
                    (left == 0 && center == 1 && right == 1) || // 011
                    (left == 0 && center == 1 && right == 0) || // 010
                    (left == 0 && center == 0 && right == 1))   // 001
                {
                    next_line[i] = 1;
                }
                break;
            case 90:
                if ((left == 1 && center == 0 && right == 1) || // 101
                    (left == 1 && center == 0 && right == 0) || // 100
                    (left == 0 && center == 1 && right == 1) || // 011
                    (left == 0 && center == 0 && right == 1))   // 001
                {
                    next_line[i] = 1;
                }
                break;
            case 124:
                if ((left == 1 && center == 1 && right == 0) || // 110
                    (left == 1 && center == 0 && right == 1) || // 101
                    (left == 1 && center == 0 && right == 0) || // 100
                    (left == 0 && center == 1 && right == 1) || // 011
                    (left == 0 && center == 1 && right == 0))   // 010
                {
                     next_line[i] = 1;
                }
                break;
        }
    }
}

void test(void) {
    int current_line[WIDTH] = {0};
    int next_line[WIDTH] = {0};
    int rule = 110; // Example rule value
    current_line[WIDTH / 2] = 1;

    generate_next_line(current_line, next_line, WIDTH, rule);
    assert(next_line[WIDTH / 2 - 1] == 1);
    assert(next_line[WIDTH / 2] == 1);
    assert(next_line[WIDTH / 2 + 1] == 1);
}
