/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* grayCode(int n, int* returnSize) {
    int *arr = (int *)malloc(sizeof(int) * (1 << n));
    (*returnSize) = 1 << n;
    arr[0] = 0; arr[1] = 1;
    int idx = 2, mask;
    for (int round = 1; round<n; round++) {
        mask = 1 << round;
        for (int j = idx - 1; j >= 0; j--, idx++) 
            arr[idx] = arr[j] ^ mask;
    }
    return arr;
}