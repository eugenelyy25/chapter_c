#include "crossword.h"

// Converts a size and string into a crossword structure. It should validate the input and populate the crossword grid
bool str2crossword(int sz, char* ip, crossword* cw) {
    if (sz <= 0 || sz > GRID || ip == NULL || cw == NULL || (int)strlen(ip) != sz * sz) {
        return false;
    }
    cw->sz = sz;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            char ch = ip[i * sz + j];
            if (ch == ' ' || ch == '.' || ch == 'X' || ch == '*') {
                cw->arr[i][j] = ch;
            } else {
                return false;
            }
        }
    }
    return true;
}


// Generates a string of across and down clue numbers.
void getcluestring(const crossword* c, char* str) {
    int clue_num = 1;
    char temp[BIGSTR] = "";
    char across[BIGSTR] = "A-";
    char down[BIGSTR] = "D-";

    for (int i = 0; i < c->sz; i++) {
        for (int j = 0; j < c->sz; j++) {
            if (c->arr[i][j] != 'X' && c->arr[i][j] != '*') {
                bool is_across = (j == 0 || c->arr[i][j-1] == 'X' || c->arr[i][j-1] == '*') && (j < c->sz - 1 && c->arr[i][j+1] != 'X' && c->arr[i][j+1] != '*');
                bool is_down = (i == 0 || c->arr[i-1][j] == 'X' || c->arr[i-1][j] == '*') && (i < c->sz - 1 && c->arr[i+1][j] != 'X' && c->arr[i+1][j] != '*');
                if (is_across || is_down) {
                    sprintf(temp, "%d-", clue_num++);
                    if (is_across) strcat(across, temp);
                    if (is_down) strcat(down, temp);
                }
            }
        }
    }
    // Remove trailing '-'
    if (across[strlen(across) - 1] == '-') across[strlen(across) - 1] = '\0';
    if (down[strlen(down) - 1] == '-') down[strlen(down) - 1] = '\0';

    sprintf(str, "%s|%s", across, down);
}

// Calculates the percentage of empty squares that are shared between two clues.
int getchecked(crossword c) {
    int total_empty = 0;
    int checked = 0;

    for (int i = 0; i < c.sz; i++) {
        for (int j = 0; j < c.sz; j++) {
            if (c.arr[i][j] != 'X' && c.arr[i][j] != '*') {
                total_empty++;
                bool is_across = (j > 0 && c.arr[i][j-1] != 'X' && c.arr[i][j-1] != '*') || (j < c.sz - 1 && c.arr[i][j+1] != 'X' && c.arr[i][j+1] != '*');
                bool is_down = (i > 0 && c.arr[i-1][j] != 'X' && c.arr[i-1][j] != '*') || (i < c.sz - 1 && c.arr[i+1][j] != 'X' && c.arr[i+1][j] != '*');
                if (is_across && is_down) {
                    checked++;
                }
            }
        }
    }
    return total_empty == 0 ? 0 : (checked * 100) / total_empty;
}

void test(void) {
    // Add your test cases here
}
