int v[] = {5000, 1000, 500, 100, 50, 10, 5, 1};
char sym[] = {'0', 'M', 'D', 'C', 'L', 'X', 'V', 'I'};

char* intToRoman(int num) {
    char *str = (char *)malloc(50);
    int vidx = 0, idx = 0;
    for (int base = 1000; base; base /= 10) {
        int n = num / base;
        if (n == 9) {
            str[idx ++] = sym[vidx + 1];
            str[idx ++] = sym[vidx - 1];
        } else if (n == 4) {
            str[idx ++] = sym[vidx + 1];
            str[idx ++] = sym[vidx];
        } else if (n >= 5) {
            str[idx ++] = sym[vidx];
            for (n = n-5; n; n--) str[idx ++] = sym[vidx + 1];
        } else {
            for (; n; n--) str[idx ++] = sym[vidx + 1];
        }
        num %= base;
        vidx += 2;
    }
    str[idx] = '\0';
    return str;
}