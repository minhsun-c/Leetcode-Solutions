void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    if (!k) return;

    int cnt = 0;
    int start = 0;
    int cur_id = 0, nx_id;
    int prev = nums[0], next;
    while (1) {
        nx_id = (cur_id + k) % numsSize;
        next = nums[nx_id];
        nums[nx_id] = prev;
        prev = next;
        cur_id = nx_id;
        cnt ++;
        if (cnt == numsSize) return;
        if (cur_id == start) {
            cur_id = start + 1;
            start ++;
            prev = nums[cur_id];
        }
    }
}