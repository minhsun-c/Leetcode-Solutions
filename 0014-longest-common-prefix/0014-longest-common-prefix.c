char* longestCommonPrefix(char** strs, int strsSize) {
    int size = 0;
    int flag = 1;
    while (flag) {
        char p = strs[0][size];
        if (!p) break;
        for (int i=1; i<strsSize; i++) {
            char target = strs[i][size];
            if (!target || target != p) {
                flag = 0;
                break;
            } 
        }
        if (flag) size ++;
    }
    if (size == 0) return "\0";
    char *ans = malloc(size + 1);
    strncpy(ans, strs[0], size);
    ans[size] = 0;
    return ans;
}