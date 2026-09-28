int maxDepth(char* s) {
    int max = 0;
    int cur = 0;
    for (char *c = s; *c; c++) {
        if (*c == '(') {
            cur ++;
            if (cur > max) max = cur;
        } else if (*c == ')') {
            cur --;
        }
    }
    return max;
}