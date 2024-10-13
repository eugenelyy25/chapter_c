#include "bingrid.h"

bool str2board(board* brd, char* str)
{
    int len = strlen(str);
    if (len == 0) {
        return false;
    }
    int size = sqrt(len);
    if (size * size != len || size % 2 != 0) {
        return false;
    }
    brd->sz = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            brd->b2d[i][j] = str[i * size + j];
        }
    }
    return true;
}

void board2str(char* str, board* brd)
{
    int size = brd->sz;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            str[i * size + j] = brd->b2d[i][j];
        }
    }
    str[size * size] = '\0'; // Null-terminate the string
}

bool solve_board(board* brd)
{
    int size = brd->sz;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", brd->b2d[i][j]);
        }
        printf("\n");
    }
    return true; // Placeholder
}

void test(void)
{
    board b;
    char str[5]; // Allocate enough space for the string (4 characters + null terminator)

    if (!str2board(&b, "1001")) {
        fprintf(stderr, "Failed to convert string to board\n");
        return;
    }

    // Debugging: print the board
    printf("Board contents:\n");
    for (int i = 0; i < b.sz; i++) {
        for (int j = 0; j < b.sz; j++) {
            printf("%c", b.b2d[i][j]);
        }
        printf("\n");
    }

    board2str(str, &b);
    printf("Converted string: %s\n", str);

    if (strcmp(str, "1001") != 0) {
        fprintf(stderr, "Assertion failed: strcmp(str, \"1001\") == 0\n");
    } else {
        printf("Test passed\n");
    }
}
