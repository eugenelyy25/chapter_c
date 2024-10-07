#define SMALLSTR20

void print_card(char s[BIGSTR], card c) {
    // Note the +1 below: zero pips not used, but makes easier coding
    char pipnames[PERSUIT + 1][SMALLSTR] = {
        "Zero", "One", "Two", "Three",
        "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Jack",
        "Queen", "King"
    };
    char suitnames[SUITS][SMALLSTR] = {
        "Hearts", "Diamonds", "Spades", "Clubs"
    };
    snprintf(s, BIGSTR, "%s of %s", pipnames[c.pips], suitnames[c.st]);
}