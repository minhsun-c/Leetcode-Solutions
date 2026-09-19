int countSubstrings(char* s) {
    int count = 0;
    int dp[1000][1000];
    memset(dp, 0, sizeof(dp));
    int sl = (int) strlen(s);

    for (int len=1; len<=sl; len++) {
        for (int l=0; l + len - 1 < sl; l++) {
            int r = l + len - 1;
            // [l .. r] -> s[l] == s[r] && dp[l+1][r-1]
            if (s[l] == s[r] && (len <= 2 || dp[l+1][r-1])) {
                dp[l][r] = 1;
                count ++;
            }
        }
    }
    return count;
}