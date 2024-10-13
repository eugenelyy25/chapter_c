#include <stdio.h>
#include <ctype.h>
#include <assert.h>

void test(void);
int is_palindrome(char phrase[]);

int main(void) {
    test();
    
    char phrase[100];  // Declare an array to hold the input
    printf("Enter a phrase: ");
    
    fgets(phrase, sizeof(phrase), stdin);  // Read the input into the array

    if (is_palindrome(phrase)) {
        printf("The phrase is a palindrome.\n");
    } else {
        printf("The phrase is not a palindrome.\n");
    }

    return 0;
}

int is_palindrome(char phrase[]) {
    int left = 0, right = 0;
    
    // Find the length of the phrase
    while (phrase[right] != '\0') {
        right++;
    }
    right--;  // Adjust for the null terminator

    while (left < right) {
        // Skip non-alphabetic characters
        while (left < right && !isalpha(phrase[left])) {
            left++;
        }
        while (left < right && !isalpha(phrase[right])) {
            right--;
        }
        // Compare characters
        if (tolower(phrase[left]) != tolower(phrase[right])) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

void test(void) {
    assert(is_palindrome("kayak"));
    assert(is_palindrome("A man, a plan, a canal: Panama!"));
    assert(is_palindrome("Madam, in Eden I’m Adam,"));
    assert(is_palindrome("Level, madam, level!"));
    printf("All tests passed!\n");
}
