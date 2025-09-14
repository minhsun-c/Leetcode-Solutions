/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXLEN(n) (1 << (2 * n))
char **arr;
int len;

void push_arr(char *str) {
    int slen = strlen(str);
    arr[len] = (char *)malloc(1 + slen);
    strncpy(arr[len], str, slen + 1);
    len ++;
}

void rec(int n, int left, int right, char *str) {
    if (str == NULL)
        str = (char *)malloc(sizeof(char) * (2 * n + 1));
    if (left == right && left + right == 2 * n){
        str[left + right] = 0;
        push_arr(str);
        return;
    }
    if (left < n) {
        str[left + right] = '(';
        rec(n, left + 1, right, str);
    } 
    if (right < left) {
        str[left + right] = ')';
        rec(n, left, right + 1, str);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    arr = (char **) malloc(sizeof(char *) * MAXLEN(n));
    len = 0;
    rec(n, 0, 0, NULL);
    *returnSize = len;
    return arr;
}