/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int temp[rowIndex + 1];
    int *ret = (int *)malloc(sizeof(int) * (rowIndex + 1));
    *returnSize = rowIndex + 1;
    ret[0] = temp[0] = temp[rowIndex] = 1;

    for (int i=1; i<=rowIndex; i++) {
        ret[0] = ret[i] = 1;
        for (int j=1; j<i; j++) {
            ret[j] = temp[j-1] + temp[j];
        }
        memcpy(temp, ret, sizeof(int)*(i+1));
    }
    return ret;
}