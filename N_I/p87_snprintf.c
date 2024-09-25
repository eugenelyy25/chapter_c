#define FIRSTCARD "1 of Hearts"
void test(void)
{
    int n=0;
    char str[BIGSTR];
    card d[DECK];
    init_deck(d);
    // Direct Assignment
    print_card(str, d[0]);
    // 1st element initialised correctly
    assert(strcmp(str, FIRSTCARD)==0);
    for(int i=0; i<1000; i++){
        shuffle_deck(d);
        print_card(str, d[0]);
        // Happens 1 time in 52?
        if(strcmp(str, FIRSTCARD)==0){
            n++;
        }
    }
    // Is this a reasonable test ?
    assert((n > 10) && (n < 30));
}