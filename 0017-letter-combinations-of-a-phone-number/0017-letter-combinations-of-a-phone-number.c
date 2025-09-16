/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char **arr;
int used;
int sz[8] = {3, 3, 3, 3, 3, 4, 3, 4}; 
char keys[8][4] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void push(char *digits, int cur, int len, char *buf) {
    if (!len) return;
    if (cur == len) {
        arr[used] = (char *)malloc(sizeof(char)*5);
        strncpy(arr[used], buf, cur+1);
        arr[used][cur] = 0;
        used ++;
        return;
    }
    int cnt = sz[digits[cur] - '2'];
    for (int i=0; i<cnt; i++) {
        buf[cur] = keys[digits[cur] - '2'][i];
        push(digits, cur + 1, len, buf);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits);
    arr = (char **) malloc(sizeof(char *) * 256);
    used = 0;
    char *buf = (char *)malloc(sizeof(char) * 5);
    push(digits, 0, len, buf);
    *returnSize = used;
    return arr;
}