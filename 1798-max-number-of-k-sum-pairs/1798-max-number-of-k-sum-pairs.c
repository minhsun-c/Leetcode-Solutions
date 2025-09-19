#define SWAP(x, y) {x = x ^ y; y = x ^ y; x = x ^ y;}
int rmlarger(int *nums, int size, int k) {
    int l = 0, r = size - 1;
    while (r >= 0 && l < r) {
        while (l < r && nums[r] >= k) {r --; size --;}
        if (l < r && nums[l] >= k) {
            SWAP(nums[l], nums[r]);
            r --; size --;
        }
        l ++;
    }
    return size;
}

int cmp(const void *a, const void *b) {
    int _a = *((int *)a);
    int _b = *((int *)b);
    return _a > _b;
}

void qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));

int maxOperations(int* nums, int numsSize, int k){
    numsSize = rmlarger(nums, numsSize, k);
    qsort(nums, numsSize, sizeof(int), cmp);
    int cnt = 0;
    int l = 0, r = numsSize - 1;
    int sum;
    while (l < r) {
        sum = nums[l] + nums[r];
        if (sum == k) {
            cnt ++;
            l ++; r --;
        }
        else if (sum > k) {
            r --;
        }
        else {
            l ++;
        }
    }
    return cnt;
}