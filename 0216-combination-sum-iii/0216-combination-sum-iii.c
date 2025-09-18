/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAXSIZE 1e8

int **arr;
int used;
int *buf;
int buf_len;

void rec(int k, int left, int cur) {
    if (k == 0 && left == 0) {
        arr[used] = (int *)malloc(sizeof(int)*buf_len);
        memcpy(arr[used], buf, sizeof(int)*buf_len);
        used ++;
        return;
    }
    else if (k == 0 || left <= 0) return;
    
    for (int i=cur; i<=9; i++) {
        if (left < i) return;
        buf[k-1] = i;
        rec(k-1, left-i, i+1);
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    arr = (int **)malloc(sizeof(int *) * MAXSIZE);
    used = 0;
    buf = (int *)malloc(sizeof(int) * k);
    buf_len = k;
    rec(k, n, 1);
    *returnSize = used;
    *returnColumnSizes = (int *)malloc(sizeof(int) * used);
    for (int i=0; i<used; i++) (*returnColumnSizes)[i] = k;
    return arr;
}