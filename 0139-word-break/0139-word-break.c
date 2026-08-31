char **dict;
int dictsize;

bool in_dict(char *s, int begin, int end) {
    char tmp[305];
    strncpy(tmp, s+begin, end-begin+1);
    tmp[end-begin+1] = 0;
    for (int i=0; i<dictsize; i++) {
        if (strcmp(tmp, dict[i]) == 0) 
            return true;
    }
    return false;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    dict = wordDict;
    dictsize = wordDictSize;

    size_t sl = strlen(s);
    bool dp[sl + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = true;

    // dp[0 .. j-1] , s[j .. i]
    for (int i=1; i<=sl; i++) {
        for (int j=0; j<i; j++) {
            if (dp[j] && in_dict(s, j+1-1, i-1)) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[sl];
}