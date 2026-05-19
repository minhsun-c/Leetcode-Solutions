char* reverseWords(char* s) {
    int sl = strlen(s);
    char *ans = malloc(sl + 1);
    ans[0] = 0;

    int cur_len = 0;
    for (int i=sl-1; i>=0; i--) {
        if (s[i] == ' ') {
            if (cur_len > 0) {
                strcat(ans, &s[i+1]);
                strcat(ans, " ");
                cur_len = 0;
            }
            s[i] = 0;
        } else {
            cur_len ++;
        }
    }

    if (cur_len > 0) strcat(ans, &s[0]);
    char *last = &ans[strlen(ans) - 1];
    if (*last == ' ') *last = 0;
    return ans;
}