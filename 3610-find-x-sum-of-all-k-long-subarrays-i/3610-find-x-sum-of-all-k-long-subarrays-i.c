#include <stdlib.h>
#include <string.h>

static inline int calc_xsum_bucketed(const int *freq, int k, int x, int window_sum, int distinct) {
    if (distinct <= x) return window_sum;            // big win on many cases

    // Bucket by frequency (1..k); values are in [1..50].
    // buckets[f][*] holds values with frequency f, stored in descending value order.
    int buckets[51][51];       // [freq][index] -> value
    int bsz[51] = {0};

    for (int v = 50; v >= 1; --v) {
        int f = freq[v];
        if (f > 0) {
            if (f > k) f = k;  // freq cannot exceed k but guard anyway
            buckets[f][bsz[f]++] = v;  // pushing in descending v
        }
    }

    int taken = 0;
    long long sum = 0;
    for (int f = k; f >= 1 && taken < x; --f) {
        for (int i = 0; i < bsz[f] && taken < x; ++i) {
            int v = buckets[f][i];     // values already in descending order
            sum += (long long)v * f;   // keep all occurrences of this value
            ++taken;                   // count one distinct element
        }
    }
    return (int)sum;
}

int* findXSum(int* nums, int numsSize, int k, int x, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int *ret = (int *)malloc(sizeof(int) * (*returnSize));
    if (!ret) return NULL;

    // freq[v] for v in [1..50]
    int freq[51] = {0};

    int window_sum = 0;
    int distinct = 0;

    // initialize first window [0..k-1]
    for (int i = 0; i < k; ++i) {
        int v = nums[i];                // 1..50
        window_sum += v;
        if (freq[v]++ == 0) ++distinct;
    }

    // process all windows
    for (int i = 0; i < *returnSize; ++i) {
        ret[i] = calc_xsum_bucketed(freq, k, x, window_sum, distinct);

        // slide window: remove nums[i], add nums[i+k]
        if (i + k < numsSize) {
            int out = nums[i];
            int in  = nums[i + k];

            // remove out
            window_sum -= out;
            if (--freq[out] == 0) --distinct;

            // add in
            window_sum += in;
            if (freq[in]++ == 0) ++distinct;
        }
    }

    return ret;
}
