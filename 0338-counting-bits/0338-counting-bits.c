/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int *arr = (int *)malloc(sizeof(int)*(n+1));
    for (int i=0, j; i<=n; i++) {
        j = i;
        int cnt = 0;
        while(j) {
            cnt += (j & 1);
            j >>= 1;
        }
        arr[i] = cnt;
    }
    *returnSize = n + 1;
    return arr;
}