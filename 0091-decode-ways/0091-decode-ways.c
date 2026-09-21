bool valid(char c1, char c2) {
    if (c1 == '0') 
        return false;
    int n;
    if (c2 == '\0') 
        n = (c1 - '0');
    else 
        n = (c1 - '0') * 10 + (c2 - '0');
    return 1 <= n && n <= 26;
}

int numDecodings(char* s) {
    int sl = (int) strlen(s);
    int dp[sl + 1]; // dp[i+1] -> s[0 .. i] 's number of decoding
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = valid(s[0], '\0');
    for (int i=2; i<=sl; i++) {
        dp[i] += valid(s[i-1],   '\0') * dp[i-1];
        dp[i] += valid(s[i-2], s[i-1]) * dp[i-2];
    }
    return dp[sl];
}