#include <stdio.h>
#include <string.h>

#define SMALLSTR 20
void print_card(chars[BIGSTR], card c)
{
    char pipstr[SMALLSTR];
    char suitstr[SNALLSTR];
    switch(c.pips){
        case 11:
        strcpy(pipstr, "Jack");
        break;
        case 12:
        strcpy(pipstr, "Queen");
        break;
        case 13:
        strcpy(pipstr, "King");
        break;
        default:
        snprintf(pipstr, SMALLSTR, "%2i", c.pips);
    }
    switch(c.st){
        case hearts:
        strcpy(suitstr, "Hearts");
        break;
        case diamonds:
        strcpy(suitstr, "Diamonds");
        break;
        case spades:
        strcpy(suitstr, "Spades");
        break;
        default:
        strcpy(suitstr, "Clubs");
    }
    snprintf(s, BIGSTR, "%s of %s", pipstr, suitstr);
}