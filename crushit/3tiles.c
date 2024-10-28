#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#define MAXROWS 20
#define WIDTH 5
#define HEIGHT 6
struct st {
   char board[MAXROWS][WIDTH];
};
typedef struct st state;


bool initialise(state* s, const char* str)
{
}

bool tostring(const state* s, char* str)
{
}

bool matches(state* s)
{
}

bool dropblocks(state* s)
{
}

void test(void)
{
}

int main(void)
{
   test();
   return 0;
}