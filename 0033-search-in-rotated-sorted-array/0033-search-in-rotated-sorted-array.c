int search(int* nums, int numsSize, int target) {
    int op = target < nums[0]; // 0: incre, 1: decre
    int prev;
    if (op == 0) {
        prev = nums[0];
        for (int i=0; i<numsSize; i++) {
            if (nums[i] == target) return i;
            if (nums[i] < prev) return -1;
            prev = nums[i];
        }
    } else {
        prev = nums[numsSize-1];
        for (int i=numsSize-1; i>=0; i--) {
            if (nums[i] == target) return i;
            if (nums[i] > prev) return -1;
            prev = nums[i];
        }
    }
    return -1;
}