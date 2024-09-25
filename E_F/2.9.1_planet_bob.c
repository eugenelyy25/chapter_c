#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool is_prime(int num);
int letter_value(char c);
void test(void);

int main(void)
{
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    char consonants[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    int count = 1;

    // Consonant-Vowel-Consonant pattern
    for (int i = 0; i < (int)(sizeof(consonants) / sizeof(consonants[0])); i++) {
        for (int j = 0; j < (int)(sizeof(vowels) / sizeof(vowels[0])); j++) {
            char first = consonants[i];
            char middle = vowels[j];
            char last = consonants[i];
            int sum = letter_value(first) + letter_value(middle) + letter_value(last);
            if (is_prime(sum)) {
                printf("%d %c%c%c\n", count++, first, middle, last);
            }
        }
    }
    // Vowel-Consonant-Vowel pattern
    for (int i = 0; i < (int)(sizeof(vowels) / sizeof(vowels[0])); i++) {
        for (int j = 0; j < (int)(sizeof(consonants) / sizeof(consonants[0])); j++) {
            char first = vowels[i];
            char middle = consonants[j];
            char last = vowels[i];
            int sum = letter_value(first) + letter_value(middle) + letter_value(last);
            if (is_prime(sum)) {
                printf("%d %c%c%c\n", count++, first, middle, last);
            }
        }
    }
    test(); // assertion test
    return 0;
}

bool is_prime(int num)
{
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int letter_value(char c)
{
    return c - 'a' + 1;
}

void test(void)
{
    // Test is_prime function
    assert(is_prime(2) == true);
    assert(is_prime(3) == true);
    assert(is_prime(4) == false);
    assert(is_prime(5) == true);
    assert(is_prime(1) == false);
    assert(is_prime(0) == false);

    // Test letter_value function
    assert(letter_value('a') == 1);
    assert(letter_value('b') == 2);
    assert(letter_value('z') == 26);

    // Test valid name generation
    char test_name1[] = "aca";
    char test_name2[] = "aka";
    char test_name3[] = "bab";
    assert(is_prime(letter_value(test_name1[0]) + letter_value(test_name1[1]) + letter_value(test_name1[2])) == true);
    assert(is_prime(letter_value(test_name2[0]) + letter_value(test_name2[1]) + letter_value(test_name2[2])) == true);
    assert(is_prime(letter_value(test_name3[0]) + letter_value(test_name3[1]) + letter_value(test_name3[2])) == true);
}