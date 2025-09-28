void dec2bin(char *str, int *len, int n) {
    printf("%d\n", n);
    int mask = 1 << 30;
    int get1 = 0;
    while (mask) {
        if ((n & mask) == 0) {
            if (get1) {
                str[*len] = '0';
                (*len) ++;
            }
        } else {
            get1 = 1;
            str[*len] = '1';
            (*len) ++;
        }
        mask >>= 1;
    }
}
char* convertDateToBinary(char* date) {
    char *str = (char *) malloc(sizeof(char) * 100);
    int len = 0;
    date[4] = 0;
    date[7] = 0;
    dec2bin(str, &len, atoi(date));
    str[len ++] = '-';
    dec2bin(str, &len, atoi(date + 5));
    str[len ++] = '-';
    dec2bin(str, &len, atoi(date + 8));
    str[len] = 0;
    return str;
}