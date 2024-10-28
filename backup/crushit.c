#include "crushit.h"
#include "mydefs.h"


bool initialise(state* s, const char* str) {
    if (s == NULL || str == NULL) {
        return false;
    }

    int len = strlen(str);

    if (len < HEIGHT * WIDTH) {
        return false;
    }

    int index = 0;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            char c = str[index++];
            if (!isalpha(c) || !isupper(c)) {
                return false;
            }
            s->board[i][j] = c;
        }
    }

    return true;
}

bool tostring(const state* s, char* str) {
    if (s == NULL || str == NULL) {
        return false;
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            str[i * WIDTH + j] = s->board[i][j];
        }
    }
    str[HEIGHT * WIDTH] = '\0';
    return true;
}

bool matches(state* s) {
    if (s == NULL) {
        return false;
    }

    bool foundMatch = false;
    bool toRemove[MAXROWS][WIDTH] = { false };

    // Check for horizontal matches
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH - 2; j++) {
            if (s->board[i][j] != '.' && s->board[i][j] == s->board[i][j+1] && s->board[i][j] == s->board[i][j+2]) {
                toRemove[i][j] = toRemove[i][j+1] = toRemove[i][j+2] = true;
                foundMatch = true;
            }
        }
    }

    // Check for vertical matches
    for (int j = 0; j < WIDTH; j++) {
        for (int i = 0; i < HEIGHT - 2; i++) {
            if (s->board[i][j] != '.' && s->board[i][j] == s->board[i+1][j] && s->board[i][j] == s->board[i+2][j]) {
                toRemove[i][j] = toRemove[i+1][j] = toRemove[i+2][j] = true;
                foundMatch = true;
            }
        }
    }

    // Remove matched tiles
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (toRemove[i][j]) {
                s->board[i][j] = '.';
            }
        }
    }

    return foundMatch;
}

bool dropblocks(state* s) {
    if (s == NULL) {
        return false;
    }

    bool dropped = false;

    for (int j = 0; j < WIDTH; j++) {
        int emptyRow = HEIGHT - 1;
        for (int i = HEIGHT - 1; i >= 0; i--) {
            if (s->board[i][j] != '.') {
                if (i != emptyRow) {
                    s->board[emptyRow][j] = s->board[i][j];
                    s->board[i][j] = '.';
                    dropped = true;
                }
                emptyRow--;
            }
        }
    }

    return dropped;
}

void test(void) {
    state s;
    char outputStr[HEIGHT * WIDTH + 1];

    assert(initialise(&s, "BBBBBDDAACCDAABCAAACDABBCCCCAAA") == true);
    tostring(&s, outputStr);
    // printf("Initial Board:\n%s\n\n", outputStr);

    // Loop for matches and drops until no changes are detected
    bool anyChange = false;
    do {
        anyChange = false;
        if (matches(&s)) {
            // printf("Matches found and removed:\n");
            tostring(&s, outputStr);
            // printf("%s\n\n", outputStr);
            anyChange = true;
        }

        if (dropblocks(&s)) {
            // printf("After dropping blocks:\n");
            tostring(&s, outputStr);
            // printf("%s\n\n", outputStr);
            anyChange = true;
        }
    } while (anyChange); // Repeat while changes are still happening
}