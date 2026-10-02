/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define CATALAN_8 1430

char **res;
int size;
char buf[17];

void gen(int n, int pos, int open, int close) {
    if (pos == 2 * n) {
        buf[pos] = 0;
        res[size] = malloc(sizeof(char) * (pos + 1));
        memcpy(res[size], buf, pos + 1);
        size ++;
        return;
    }

    if (open < n) {
        buf[pos] = '(';
        gen(n, pos + 1, open + 1, close);
    }
    if (close < open) {
        buf[pos] = ')';
        gen(n, pos + 1, open, close + 1);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    res = malloc(sizeof(char *) * CATALAN_8);
    size = 0;

    gen(n, 0, 0, 0);

    *returnSize = size;
    return res;
}