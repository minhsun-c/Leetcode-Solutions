// 完全不知道在幹嘛

#define MOD 1000000007LL
#define MAXN 100005

static long long b1[MAXN + 2], b2[MAXN + 2];
static int N;

static void add(long long *b, int i, long long v) {
    for (; i <= N; i += i & (-i)) b[i] += v;
}

static long long sum(long long *b, int i) {
    long long s = 0;
    for (; i > 0; i -= i & (-i)) s += b[i];
    return s;
}

static void rangeAdd(int l, int r, long long v) {
    add(b1, l, v);
    add(b1, r + 1, -v);
    add(b2, l, v * (l - 1));
    add(b2, r + 1, -v * r);
}

static long long prefix(int i) {
    return sum(b1, i) * i - sum(b2, i);
}

static long long rangeSum(int l, int r) {
    return prefix(r) - prefix(l - 1);
}

int sumCounts(int* nums, int numsSize) {
    N = numsSize;
    memset(b1, 0, sizeof(long long) * (N + 2));
    memset(b2, 0, sizeof(long long) * (N + 2));

    static int last[100001];
    for (int i = 0; i <= 100000; i++) last[i] = -1;

    long long B = 0, ans = 0;
    for (int r = 0; r < numsSize; r++) {
        int p = last[nums[r]];
        int L = p + 2, R = r + 1;          /* 轉成 1-indexed */

        long long T = rangeSum(L, R);      /* 更新前的 Σd */
        B += 2 * T + (R - L + 1);
        ans = (ans + B) % MOD;

        rangeAdd(L, R, 1);
        last[nums[r]] = r;
    }
    return (int)ans;
}