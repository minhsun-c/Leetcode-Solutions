void rotate(int* nums, int numsSize, int k) {
    if (k == 0) return;
    k = k % numsSize;
    int last = 0;
    int idx = 0;
    int prev = nums[0], next;
    for (int i=0; i<numsSize; i++) {
        int n_id = (idx + k) % numsSize;
        next = nums[n_id];
        nums[n_id] = prev;
        prev = next;
        idx = n_id;
        if (idx == last && idx < k - 1) {
            last ++;
            idx ++;
            prev = nums[idx];
        }
    }
}