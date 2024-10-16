#include "crushit.h"
#include "mydefs.h"

bool initialise(state* s, const char* str) {
    /*if (s == NULL || str == NULL) {
        return false;
    }

    FILE *file = fopen(str, "r");
    if (file) {
        // Read from file
        for (int i = 0; i < MAXROWS; i++) {
            if (fgets(s->board[i], WIDTH + 1, file) == NULL) {
                fclose(file);
                return true;
            }
        }
        fclose(file);
    } else {*/
        // Read from string
        int len = strlen(str);
        if (len % WIDTH != 0) {
            return false;
        }
        for (int i = 0; i < len; i++) {
            if (str[i] < 'A' || str[i] > 'Z') {
                return false;
            }
        }
        for (int i = 0; i < len / WIDTH; i++) {
            strncpy(s->board[i], str + i * WIDTH, WIDTH);
        }
        return true;
    }
//}

bool tostring(const state* s, char* str) {
    if (s == NULL || str == NULL) {
        return false;
    }

    int index = 0;
    for (int i = 0; i < MAXROWS; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (s->board[i][j] != '.') {
                str[index++] = s->board[i][j];
            }
        }
    }
    str[index] = '\0';
    return true;
}

bool matches(state* s) {
    if (s == NULL) {
        return false;
    }

    bool foundMatch = false;
    // Temporary board to mark matches
    char tempBoard[MAXROWS][WIDTH];
    for (int i = 0; i < MAXROWS; i++) {
        for (int j = 0; j < WIDTH; j++) {
            tempBoard[i][j] = s->board[i][j];
        }
    }

    // Check for horizontal matches
    for (int i = 0; i < MAXROWS; i++) {
        for (int j = 0; j < WIDTH - 2; j++) {
            if (s->board[i][j] != '.' && s->board[i][j] == s->board[i][j + 1] && s->board[i][j] == s->board[i][j + 2]) {
                foundMatch = true;
                tempBoard[i][j] = tempBoard[i][j + 1] = tempBoard[i][j + 2] = '.';
                // Continue checking for longer matches
                int k = j + 3;
                while (k < WIDTH && s->board[i][k] == s->board[i][j]) {
                    tempBoard[i][k] = '.';
                    k++;
                }
            }
        }
    }

    // Check for vertical matches
    for (int j = 0; j < WIDTH; j++) {
        for (int i = 0; i < MAXROWS - 2; i++) {
            if (s->board[i][j] != '.' && s->board[i][j] == s->board[i + 1][j] && s->board[i][j] == s->board[i + 2][j]) {
                foundMatch = true;
                tempBoard[i][j] = tempBoard[i + 1][j] = tempBoard[i + 2][j] = '.';
                // Continue checking for longer matches
                int k = i + 3;
                while (k < MAXROWS && s->board[k][j] == s->board[i][j]) {
                    tempBoard[k][j] = '.';
                    k++;
                }
            }
        }
    }

    // Update the board with matches
    for (int i = 0; i < MAXROWS; i++) {
        for (int j = 0; j < WIDTH; j++) {
            s->board[i][j] = tempBoard[i][j];
        }
    }

    return foundMatch;
}

bool dropblocks(state* s) {
    if (s == NULL) {
        return false;
    }

    for (int j = 0; j < WIDTH; j++) {
        for (int i = MAXROWS - 1; i >= 0; i--) {
            if (s->board[i][j] == '.') {
                int k = i - 1;
                while (k >= 0 && s->board[k][j] == '.') {
                    k--;
                }
                if (k >= 0) {
                    s->board[i][j] = s->board[k][j];
                    s->board[k][j] = '.';
                }
            }
        }
    }

    return true;
}

void test(void) {
    
    // Code to generate the string 'str'
    char str[100]; // Replace with your actual string generation code
    strcpy(str, "...DBCDAACDAABDAABC.ABCD.BC...");
    strcpy(str, "ABCDBCDAACDAABDAABCAABCDABCDA");
    strcpy(str, "ABCDBCDAACDAABDAABCAABCDABCD+A");

    // Print the generated string for debugging
    printf("Generated string: %s\n", str);
    printf("Generated string: %s, Length: %zu\n", str, strlen(str));
    printf("Generated string: %s, Last character: %c\n", str, str[strlen(str) - 1]);

   for (int i = 0; i < strlen(str); i++) {
    printf("Character at index %d: %c (ASCII value: %d)\n", i, str[i], str[i]);
    }
    printf("Length of generated string: %zu\n", strlen(str));


    // Assertion
    if (strcmp(str, "...DBCDAACDAABDAABC.ABCD.BC...") == 0) {
        printf("Assertion passed\n");
    }
    if (strcmp(str, "ABCDBCDAACDAABDAABCAABCDABCDA") == 0) {
        printf("Assertion passed\n");
    }
    if (strcmp(str, "ABCDBCDAACDAABDAABCAABCDABCD+A") == 0) {
        printf("Assertion passed\n");

    } else {
        printf("Assertion failed\n");
    }
}
