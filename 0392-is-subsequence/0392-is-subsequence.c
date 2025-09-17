#define MAX(x, y) (x > y ? x : y)

bool isSubsequence(char* s, char* t) {
    int slen = strlen(s);
    int tlen = strlen(t);
    int dp[slen + 1][tlen + 1];
    for (int i=0; i<=slen; i++) {
        for (int j=0; j<=tlen; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else  dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[slen][tlen] == slen;
}