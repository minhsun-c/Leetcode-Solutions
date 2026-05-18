static inline int val(char c) {
    switch(c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    }
    return 0;
}

int romanToInt(char* s) {
    int sum = 0;
    int prev = val(s[0]), next;
    for (int i=1; s[i]; i++) {
        next = val(s[i]);
        if (prev < next) {
            // IV -> V - I
            sum -= prev;
        } else {
            sum += prev;
        }
        prev = next;
    }
    return sum + next;
}