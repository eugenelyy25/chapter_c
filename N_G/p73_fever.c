#include <stdio.h>
#include <assert.h>

// Argument 1, temperature
// Argument 2, scale (0=>Celsius , 1=>Fahrenheit)
int fvr(double t, int s);

int main(void)
{
    assert(fvr(37.5, 0) == 1);  // 37.5°C is not fever
    assert(fvr(36.5, 0) == 0);  // 36.5°C is not fever
    assert(fvr(96.5, 1) == 0);  // 96.5°F is not fever
    assert(fvr(99.5, 1) == 1);  // 99.5°F is not fever
    /*
    printf("37.5°C: %s\n", fvr(37.5, 0) == 1 ? "Fever":"No Fever");
    printf("36.5°C: %s\n", fvr(36.5, 0) == 1 ? "Fever":"No Fever");
    printf("96.5°F: %s\n", fvr(96.5, 1) == 1 ? "Fever":"No Fever");
    printf("99.5°F: %s\n", fvr(99.5, 1) == 1 ? "Fever":"No Fever");*/
    return 0;
}

int fvr(double t, int s)
{
    if (s == 0) { // Celsius
        return t >= 38.0 ? 1:0; // Fever if 38°C or higher
    } else { // Fahrenheit
        return t >= 100.4 ? 1:0; // Fever if 100.4°F or higher
    }
}