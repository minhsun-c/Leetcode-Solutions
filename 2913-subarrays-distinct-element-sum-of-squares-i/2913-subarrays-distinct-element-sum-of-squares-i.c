int sumCounts(int* nums, int numsSize) {
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        int seen[101] = {0};
        int cnt = 0;
        for (int j = i; j < numsSize; j++) {
            if (seen[nums[j]]++ == 0) cnt++;   
            res += cnt * cnt;
        }
    }
    return res;
}