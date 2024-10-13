#include <stdio.h>
#include <string.h>
#include <assert.h>

void strmerge(char s1[], char s2[], char s3[]);

void test(void);

int main(void) {
    test();
    return 0;
}

void strmerge(char s1[], char s2[], char s3[]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int overlap = 0;

    // Find the overlap
    for (int i = 1; i <= len1 && i <= len2; i++) {
        if (strncmp(s1 + len1 - i, s2, i) == 0) {
            overlap = i;
        }
    }

    // Copy s1 to s3
    for (int i = 0; i < len1; i++) {
        s3[i] = s1[i];
    }

    // Concatenate s2 to s3, skipping the overlapping part
    for (int i = overlap; i < len2; i++) {
        s3[len1 + i - overlap] = s2[i];
    }

    // Null-terminate the result
    s3[len1 + len2 - overlap] = '\0';
}

void test(void) {
    char s1[100], s2[100], s3[200];  // Allocate enough space for the strings

    strcpy(s1, "hello");
    strcpy(s2, "lo world");
    strmerge(s1, s2, s3);
    assert(strcmp(s3, "hello world") == 0);

    strcpy(s1, "abc");
    strcpy(s2, "def");
    strmerge(s1, s2, s3);
    assert(strcmp(s3, "abcdef") == 0);

    strcpy(s1, "abc");
    strcpy(s2, "abc");
    strmerge(s1, s2, s3);
    assert(strcmp(s3, "abc") == 0);

    strcpy(s1, "abcd");
    strcpy(s2, "cdef");
    strmerge(s1, s2, s3);
    assert(strcmp(s3, "abcdef") == 0);

    printf("All tests passed!\n");
}