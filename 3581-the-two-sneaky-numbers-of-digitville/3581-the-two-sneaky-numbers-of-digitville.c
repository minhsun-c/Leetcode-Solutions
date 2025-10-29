/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int n = numsSize - 2;

    int seen[n];
    memset(seen, 0, n*sizeof(int));
    int *ret = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    int k = 0;


    for (int i=0; i<numsSize; i++) {
        int x = nums[i];
        seen[x] ++;
        if (seen[x] == 2) {
            ret[k] = x;
            k ++;
            if (k == 2) break;
        }
    }

    return ret;
}
