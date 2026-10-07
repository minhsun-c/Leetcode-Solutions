static char *S;
static int N;
static char **res;
static int rcnt;
static char buf[32];

static int seen(const char *t) {
    for (int i = 0; i < rcnt; i++)
        if (strcmp(res[i], t) == 0) 
            return 1;
    return 0;
}

static void dfs(int i, int open, int l, int r, int blen) {
    if (open < 0 || l < 0 || r < 0) return;

    if (i == N) {
        if (open == 0 && l == 0 && r == 0) {
            buf[blen] = '\0';
            if (!seen(buf)) {
                res[rcnt] = malloc(blen + 1);
                strcpy(res[rcnt++], buf);
            }
        }
        return;
    }

    if (S[i] == '(') {
        if (l > 0) 
            dfs(i+1, open, l-1, r, blen);        
        buf[blen] = S[i];
        dfs(i+1, open+1, l, r, blen+1);                  
    } else if (S[i] == ')') {
        if (r > 0) 
            dfs(i+1, open, l, r-1, blen);        
        buf[blen] = S[i];
        dfs(i+1, open-1, l, r, blen+1);               
    } else {
        buf[blen] = S[i];                                  
        dfs(i+1, open, l, r, blen+1);
    }
}

char** removeInvalidParentheses(char *s, int *returnSize) {
    S = s;
    N = strlen(s);

    int l = 0, r = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == '(') l++;
        else if (s[i] == ')') { 
            if (l > 0) l--; 
            else r++; 
        }
    }

    res = malloc(sizeof(char *) * 5000);
    rcnt = 0;
    dfs(0, 0, l, r, 0);

    *returnSize = rcnt;
    return res;
}