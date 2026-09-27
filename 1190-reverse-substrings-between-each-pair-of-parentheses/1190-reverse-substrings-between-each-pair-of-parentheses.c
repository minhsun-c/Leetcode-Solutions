char* reverseParentheses(char* s) {
    char *stack = malloc(2005);
    int top = 0;

    int lp[2005];
    int lp_idx = 0;

    int sl = strlen(s);
    int l, r, tmp;
    for (int i=0; i<sl; i++) {
        if (s[i] == '(') {
            lp[lp_idx] = top;
            lp_idx ++;
        } else if (s[i] == ')') {
            l = lp[lp_idx - 1];
            r = top - 1;
            while (l < r) {
                tmp = stack[l];
                stack[l] = stack[r];
                stack[r] = tmp;
                l ++; r --;
            }
            lp_idx --;
                
        } else {
            stack[top] = s[i];
            top ++;
            stack[top] = 0;
        }
    }
    return stack;
}