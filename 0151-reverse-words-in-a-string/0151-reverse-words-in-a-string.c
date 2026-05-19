char* reverseWords(char* s) {
    int sl = strlen(s);
    char *ans = malloc(sl + 1);
    int len = 0;
    
    int i = sl - 1;
    int first = 1;
    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') i --;

        int end = i;
        while (i >= 0 && s[i] != ' ') i --;
        int start = i + 1;
        

        if (start < 0 || end < 0 || start > end) continue;

        if (!first) {
            memcpy(ans + len, " ", 1);
            len += 1;
        }
        memcpy(ans + len, s + start, end - start + 1);
        len += (end - start + 1);
        first = 0;
    }
    ans[len] = 0;
    return ans;
}