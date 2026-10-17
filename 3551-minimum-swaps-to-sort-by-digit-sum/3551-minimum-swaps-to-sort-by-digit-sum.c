struct node {
    int ori;
    int val;
    int idx;
};

int dsum(int a) {
    int s = 0;
    while (a) {
        s += a % 10;
        a /= 10;
    }
    return s;
}

int cmp(const void *a, const void *b) {
    struct node *_a = (struct node *) a;
    struct node *_b = (struct node *) b;
    if (_a -> val == _b -> val)
        return _a -> ori - _b -> ori;
    return _a -> val - _b -> val;
}

int minSwaps(int* nums, int numsSize) {
    struct node arr[numsSize];    
    for (int i=0; i<numsSize; i++){
        arr[i].ori = nums[i];
        arr[i].val = dsum(nums[i]);
        arr[i].idx = i;
    }
    int cycles = 0;
    qsort(arr, numsSize, sizeof(struct node), cmp);

    char vis[numsSize];
    memset(vis, 0, sizeof(vis));

    for (int i=0; i<numsSize; i++) {
        if (vis[i]) continue;
        cycles ++;
        int cur = i;
        while (!vis[cur]) {
            vis[cur] = 1;
            cur = arr[cur].idx;
        }
    }

    return numsSize - cycles;
    // Each cycle require k - 1 swap.
    // => (k1 - 1) + (k2 - 1) + ... + (kn - 1)
    // => k1 + k2 + ... + kn = numsSize
}