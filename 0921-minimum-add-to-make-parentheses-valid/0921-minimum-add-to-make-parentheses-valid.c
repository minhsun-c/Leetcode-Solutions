int minAddToMakeValid(char* s) {
    int ans = 0;
    int top = 0;
    for (char *c = s; *c; c++) {
        if (*c == '(') top ++;
        else {
            top --;
            while (top < 0) { ans ++; top ++; }
        }
    }
    return ans + top;
}