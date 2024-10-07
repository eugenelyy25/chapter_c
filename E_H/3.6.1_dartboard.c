#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 19
#define ITERATIONS 5000000

int calculate_cost(int board[]);
void swap(int board[], int i, int j);

int main(void) {
    int board[N];
    int best_board[N];
    int best_cost;

    //Initialize the board with the trivial monotonic sequence
    for (int i = 0; i < N; i++) {
        board[i] = i + 1;
        best_board[i] = board[i];
    }
    best_cost = calculate_cost(board);
    srand(time(NULL));

    for (int iter = 0; iter < ITERATIONS; iter++) {
        int i = rand() % N;
        int j = rand() % N;

        swap(board, i, j);
        int current_cost = calculate_cost(board);

        if (current_cost < best_cost) {
            best_cost = current_cost;
            for (int k = 0; k < N; k++) {
                best_board[k] = board[k];
            }
        } else {
            swap(board, i, j); //Unswap if no improvement
        }
    }
    printf("Total = %d : ", best_cost);
    for (int i = 0; i < N; i++) {
        printf("%d ", best_board[i]);
    }
    printf("\n");
    return 0;
}
// Function to calculate the cost of the board
int calculate_cost(int board[]) {
    int cost = 0;
    for (int i = 0; i < N - 1; i++) {
        cost += abs(board[i] - board[i + 1]);
    }
    return cost;
}
// Function to swap two positions on the board
void swap(int board[], int i, int j) {
    int temp = board[i];
    board[i] = board[j];
    board[j] = temp;
}