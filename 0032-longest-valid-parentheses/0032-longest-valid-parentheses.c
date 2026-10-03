int max(const int a, const int b) {
    return a > b ? a : b;
}

int longestValidParentheses(char* s) {
    int sl = strlen(s);
    int stack[sl + 1]; // index of '('
    int top = 1;
    stack[0] = -1;
    int best = 0;

    for (int i=0; i<sl; i++) {
        if (s[i] == '(') {
            stack[top] = i;
            top ++;
        } else {
            top --;
            if (top == 0) {
                top = 0;
                stack[top] = i;
                top ++;
            } else {
                best = max(best, i - stack[top - 1]);
            }
        }
    }
    return best;
}