#define HF(a, b) ((a & b) + ((a ^ b) >> 1))
int mySqrt(int x) {
    if (x == 0 || x == 1) return x;
    int l = 1, r = x;
    long long sq, mid;
    while (l <= r) {
        mid = HF(l, r);
        sq = mid * mid;
        if (sq == x) return mid;
        else if (sq < x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}