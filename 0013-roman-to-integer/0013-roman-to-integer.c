static inline int sym_v(char c)
{
    switch(c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
    return 0;
}

int romanToInt(char* s) {
    int sum = 0;
    int prev = INT_MAX, cur;
    for (int i=0; s[i]; i++) {
        cur = sym_v(s[i]);
        if (cur > prev) sum += cur - 2*prev;
        else sum += cur;
        prev = cur;
    }
    return sum;
}