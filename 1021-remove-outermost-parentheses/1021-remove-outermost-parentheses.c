char* removeOuterParentheses(char* s) {
    int sl = strlen(s);
    char *ans = malloc(sl + 1);

    int top = 0;
    int len = 0;
    for (int i=0; i<sl; i++) {
        if (top == 0 && s[i] == '(') 
            top ++;
        else if (top == 1 && s[i] == ')') 
            top --;
        else {
            if (s[i] == '(') {
                top ++;
            } else {
                top --;
            }
            ans[len] = s[i];
            len ++;
        }
    }
    ans[len] = 0;
    return ans;
}