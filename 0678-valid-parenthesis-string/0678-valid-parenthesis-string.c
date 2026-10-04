bool dp[101][51];

int min(int a, int b) {
    return a < b ? a : b;
}

bool checkValidString(char* s) {
    memset(dp, 0, sizeof(dp));
    int sl = strlen(s);

    if (s[0] == ')' || s[sl-1] == '(') 
        return false;

    dp[0][0] = true;

    for (int i=1; i<=sl; i++) {
        int kmax = min(min(i, sl-i), 50);
        for (int k=0; k<=kmax; k++) {
            if (s[i-1] == '(') {
                if (k >= 1) dp[i][k] = dp[i-1][k-1];
            }
            else if (s[i-1] == ')') {
                if (k+1 <= 50) dp[i][k] = dp[i-1][k+1];
            }
            else 
                dp[i][k] = (k >= 1 && dp[i-1][k-1]) ||
                    (k+1 <= 50 && dp[i-1][k+1]) || dp[i-1][k];
        }
    }
    return dp[sl][0];
}