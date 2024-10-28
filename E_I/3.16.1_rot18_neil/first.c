char rot_az(char c);
char rot_AZ(char c);
char rot_09(char c);

void rot(char c[])
{
    int n = 0;
    while(c[n]){
        char d1 = rot_az(c[n]);
        char d2 = rot_AZ(d1);
        c[n]    = rot_09(d2);
        n++;
    }
}

char rot_AZ(char c)
{
    if( (c < 'A') || (c > 'Z')){
        return c;
    }
    // 26 (e.g.)
    int r = 1 + ('Z' - 'A');
    int r_2 = r/2;
    // Original Number 0..25 (e.g.)
    int d1 = c - 'A';
    // Rot number 0..25 (e.g.)
    int dr = (d1+r_2)%r;
    return dr+'A';
}
char rot_az(char c)
{
    if( (c < 'a') || (c > 'z')){
        return c;
    }
    // 26 (e.g.)
    int r = 1 + ('z' - 'a');
    int r_2 = r/2;
    // Original Number 0..25 (e.g.)
    int d1 = c - 'a';
    // Rot number 0..25 (e.g.)
    int dr = (d1+r_2)%r;
    return dr+'a';
}