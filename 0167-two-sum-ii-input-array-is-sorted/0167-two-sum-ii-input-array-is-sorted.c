/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *ans = malloc(sizeof(int) * 2);
    *returnSize = 2;

    int i = 0, j = numbersSize - 1;
    int sum;
    while (i < j) {
        sum = numbers[i] + numbers[j];
        if (sum == target) {
            ans[0] = i + 1;
            ans[1] = j + 1;
            break;
        } else if (sum > target) j --;
        else i++;
    }

    return ans;
}