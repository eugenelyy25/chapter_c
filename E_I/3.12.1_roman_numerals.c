#include <stdio.h>
#include <string.h>
#include <assert.h>

int roman_to_int(char s[]);
void test(void);

int main(void) {
    test();
    return 0;
}

int roman_to_int(char s[]) {
    // Declare roman_values with enough size to handle ASCII characters
    int roman_values[1000] = {0};
    
    // Initialize only the Roman numeral characters
    roman_values['I'] = 1;
    roman_values['V'] = 5;
    roman_values['X'] = 10;
    roman_values['L'] = 50;
    roman_values['C'] = 100;
    roman_values['D'] = 500;
    roman_values['M'] = 1000;

    int i = 0, num = 0;
    int length = strlen(s);
    while (i < length) {
        if (i + 1 < length && roman_values[(int)s[i]] < roman_values[(int)s[i + 1]]) {
            num += roman_values[(int)s[i + 1]] - roman_values[(int)s[i]];
            i += 2;
        } else {
            num += roman_values[(int)s[i]];
            i++;
        }
    }
    return num;
}

void test(void) {
    assert(roman_to_int("MCMXCIX") == 1999);
    assert(roman_to_int("MCMLXVII") == 1967);
    assert(roman_to_int("MCDXCI") == 1491);
    printf("All tests passed!\n");
}
