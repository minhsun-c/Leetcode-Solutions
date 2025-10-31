/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int l = 0, r = numbersSize-1;
    while (l < r) {
        int x = numbers[l] + numbers[r];
        if (x == target) {
            ret[0] = l + 1;
            ret[1] = r + 1;
            break;
        }
        else if (x < target) l ++;
        else r--;
    }
    return ret;
}