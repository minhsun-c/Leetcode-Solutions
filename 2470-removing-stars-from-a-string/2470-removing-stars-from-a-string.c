char* removeStars(char* s) {
    int len = strlen(s);
    char stack[len + 1];
    int top = 0;
    for (int i=0; i<len; i++) {
        if (s[i] == '*') {
            stack[top--] = 0;
        } else {
            stack[top++] = s[i];
        }
    }
    stack[top] = 0;
    strcpy(s, stack);
    return s;
}