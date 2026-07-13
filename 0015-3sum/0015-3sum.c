/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **ans = malloc(sizeof(int *) * 100000);
    int *sizes = malloc(sizeof(int) * 100000);
    *returnSize = 0;
    *returnColumnSizes = sizes;
    qsort(nums, numsSize, sizeof(int), cmp);
    int i=0, j, k, sum;
    int previ = INT_MIN;
    for (i=0; i<numsSize-2; i++) {
        if (nums[i] > 0) break;
        if (previ == nums[i]) continue;
        previ = nums[i];
        j = i+1;
        k = numsSize - 1;
        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                int *tmp = malloc(sizeof(int) * 3);
                tmp[0] = nums[i]; tmp[1] = nums[j]; tmp[2] = nums[k];
                ans[*returnSize] = tmp;
                sizes[*returnSize] = 3;
                (*returnSize) ++;
                j ++;
                while (j < k && nums[j] == tmp[1]) j ++;
                while (j < k && nums[k] == tmp[2]) k --;
            } else if (sum > 0) {
                k --;
            } else {
                j ++;
            }
        }
    }
    return ans;
}