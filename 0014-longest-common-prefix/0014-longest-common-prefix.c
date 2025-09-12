char* longestCommonPrefix(char** strs, int strsSize) {
    int len = strlen(strs[0]);
    char pf;
    for (int i=0; i<len; i++) {
        for (int j=0; j<strsSize; j++) {
            if (strs[j][i] == 0) {
                return strs[j];
            } 
            if (j == 0) pf = strs[j][i];
            else if (strs[j][i] != pf) {
                strs[j][i] = 0;
                return strs[j];
            }
        }
    }
    return strs[0];
}