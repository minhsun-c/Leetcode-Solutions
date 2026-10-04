bool checkValidString(char* s) {
    int hi = 0, lo = 0;
    int sl = strlen(s);
    for (char *c = s; *c; c++) {
        if (*c == '(') {
            hi ++; lo ++;
        } else if (*c == ')') {
            hi --; lo --;
        } else {
            hi ++; lo --;
        }
        if (hi < 0) return false;
        if (lo < 0) lo = 0;
    }
    return lo == 0;
}