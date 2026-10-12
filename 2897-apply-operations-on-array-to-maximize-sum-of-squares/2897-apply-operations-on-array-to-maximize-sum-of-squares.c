#define LIMIT 1000000007ULL

int maxSum(int* nums, int numsSize, int k) {
    int cnt[31];
    memset(cnt, 0, sizeof(cnt));

    for (int i=0; i<numsSize; i++) {
        for (int shamt = 0; shamt < 31; shamt ++) {
            if (nums[i] & (1 << shamt)) {
                cnt[shamt] ++;
            }
        }
    }

    long long ans = 0;
    for (int i=0; i<k; i++) {
        long long tmp = 0;
        for (int shamt = 0; shamt < 31; shamt ++) {
            if (cnt[shamt] > 0) {
                tmp |= (1 << shamt);
                cnt[shamt] --;
            }
        }
        tmp %= LIMIT;
        ans += tmp * tmp;
        ans %= LIMIT;
    }
    return (int) ans;
}