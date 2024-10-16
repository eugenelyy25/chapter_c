#include <stdio.h>

struct dateofbirth {
    unsigned char day;
    unsigned short month;
    unsigned short year;
};

typedef struct dateofbirth dob;

typedef struct {
    char *name;  // You can change this to 'const char *' if the name should not be modified
    dob date;
} person;

void print_byval(person b);
void print_byref(const person *p);

int main(void) {
    person a = {"Grey", {17, 5, 1999}};
    print_byval(a);
    print_byref(&a);
}

void print_byval(person b) {
    printf("%s %hhu/%hi/%hu \n", b.name, b.date.day, b.date.month, b.date.year);  // Changed %hi to %hu
} // %hi ~ type:short, %hu ~ unsigned short

void print_byref(const person *p) {
    printf("%s %hhu/%hi/%hi \n", p->name, p->date.day, p->date.month, p->date.year);  // Changed %hi to %hu
}
