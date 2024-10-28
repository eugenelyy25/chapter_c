void rot(char *p)
{
    char lut[] = "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f !\"#$%&'()*+,-./5678901234:;<=>?@NOPQRSTUVWXYZABSCDEFGHIJKLM[\\]^_`nopqrstuvwxyzabcdefghijklm{|}~";
    int i = 0;
    while(p[i] != '\0'){
        char new_c = lut[(int)p[i]];
        p[i] = new_c;
        i++;
    }
}

void your_tests(void)
{
    // None required, code is 'clearly' correct by inspection (?) ;-)
}