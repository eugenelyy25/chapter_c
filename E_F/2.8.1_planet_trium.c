#include <stdio.h>

int main(void)
{
    char non_vowels[] = "bcdfghjklmnpqrstvwxyz";
    char vowels[] = "aeiou";
    int count = 1;

    for (int i = 0; i < 21; i++) { //21 non-vowels
        for (int j = 0; j < 5; j++) { //5 vowels
            for (int k = 0; k < 21; k++) { //21 non-vowels
                printf("%d %c%c%c\n", count, non_vowels[i], vowels[j], non_vowels[k]);
                count++;
            }
        }
    }
    return 0;
}