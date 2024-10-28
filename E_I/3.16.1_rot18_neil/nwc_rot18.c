char rot_gen(char c, char low, char up);

void rot(char c[])
{
    int n = 0;
    while(c[n]){
        char d1 = rot_gen(c[n], 'a', 'z');
        char d2 = rot_gen(d1,   '0', '9');
        c[n]    = rot_gen(d2,   'A', 'Z');
        n++;
    }
}

char rot_gen(char c, char low, char up)
{
    if( (c < low) || (c > up)){
        return c;
    }
    // 26 (e.g.)
    int r = 1 + (up-low);
    int r2 = r/2;
    // Original Number 0..25 (e.g.)
    int d1 = c - low;
    // Rot number 0..25 (e.g.)
    int dr = (d1+r2)%r;
    return dr+low;
}