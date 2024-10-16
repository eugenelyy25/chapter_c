#include <stdio.h>
#include <string.h>

#define BIGSTR 50   // Define BIGSTR for the maximum string size for a card description
#define PERSUIT 13  // 13 different ranks (pip values) per suit in a deck
#define SUITS 4     // 4 suits (Hearts, Diamonds, Spades, Clubs)
#define DECK 52     // 52 cards in a standard deck
#define SMALLSTR 20 // Define SMALLSTR for small strings

// Define the card structure
typedef struct {
    int pips;  // Rank or value of the card (1 to 13)
    int st;    // Suit of the card (0 to 3, corresponding to Hearts, Diamonds, Spades, Clubs)
} card;

// Function prototypes
void print_deck(card d[DECK], int n);
void print_card(char s[BIGSTR], const card* p);

// Main function to test the code
int main() {
    // Example deck of 2 cards
    card deck[DECK] = {
        {1, 0},  // Ace of Hearts
        {13, 2}  // King of Spades
    };

    // Print the deck (only 2 cards in this case)
    print_deck(deck, 2);

    return 0;
}

// Function to print the entire deck
void print_deck(card d[DECK], int n) {
    char str[BIGSTR];
    for (int i = 0; i < n; i++) {
        print_card(str, &d[i]);
        printf("%s\n", str);
    }
    printf("\n");
}

// Function to print a single card
void print_card(char s[BIGSTR], const card* p) {
    // +1 because we use indices 1-13 for pips
    char pipnames[PERSUIT + 1][SMALLSTR] = {
        "Zero", "One", "Two", "Three",
        "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Jack",
        "Queen", "King"
    };
    char suitnames[SUITS][SMALLSTR] = {
        "Hearts", "Diamonds", "Spades", "Clubs"
    };
    snprintf(s, BIGSTR, "%s of %s", pipnames[p->pips], suitnames[p->st]);
}
