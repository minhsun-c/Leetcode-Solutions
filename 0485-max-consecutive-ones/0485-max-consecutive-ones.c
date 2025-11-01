#define MAX(a, b) (a > b ? a : b)
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max = 0;
    int cur = 0;
    for (int i=0; i<numsSize; i++) {
        if (!nums[i]) {
            max = MAX(max, cur);
            cur = 0;
        } else {
            cur ++;
        }
    }
    max = MAX(max, cur);
    return max;
}