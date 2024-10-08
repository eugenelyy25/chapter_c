#include <stdio.h>
#include <string.h>
#include <assert.h>

char getCode(char c);
void soundex(const char name[], char code[]);
void test(void);

int main(void) {
    test();
    printf("All tests passed!\n");
    return 0;
}

char getCode(char c) {
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0';
    }
}

void soundex(const char name[], char code[]) {
    int i, j = 1;
    char prevCode = '0';

    code[0] = name[0]; // First letter remains the same
    for (i = 1; name[i] != '\0' && j < 4; i++) {
        char currentCode = getCode(name[i]);
        if (currentCode == '0' || currentCode == prevCode) continue;
        if (name[i] == 'H' || name[i] == 'W') continue;
        code[j++] = currentCode;
        prevCode = currentCode;
    }
    while (j < 4) code[j++] = '0'; // Pad with zeros if necessary
    code[j] = '\0'; // Null-terminate the string
}

void test(void) {
    char code[5]; // 4 characters + null terminator

    soundex("Washington", code);
    assert(strcmp(code, "W252") == 0);

    soundex("Wu", code);
    assert(strcmp(code, "W000") == 0);

    soundex("DeSmet", code);
    assert(strcmp(code, "D253") == 0);

    soundex("Gutierrez", code);
    assert(strcmp(code, "G362") == 0);

    soundex("Pfister", code);
    assert(strcmp(code, "P236") == 0);

    soundex("Jackson", code);
    assert(strcmp(code, "J250") == 0);

    soundex("Tymczak", code);
    assert(strcmp(code, "T522") == 0);

    soundex("Ashcraft", code);
    assert(strcmp(code, "A261") == 0);
}