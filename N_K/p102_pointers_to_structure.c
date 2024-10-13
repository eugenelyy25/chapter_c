// pointer replaces passed value (copied) in structure
void print_deck(card d[DECK], int n) {
    char str[BIGSTR];
    for (int i = 0; i < n; i++) {
        print_card(str, &d[i]);
        printf("%s\n", str);
    }
    printf("\n");
}

#define SMALLSTR 20

void print_card(char s[BIGSTR], const card* p) {
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
    snprintf(s, BIGSTR, "%s of %s", pipnames[p->pips], suitnames[p->st]);
    // "->" operator used for elements
}
