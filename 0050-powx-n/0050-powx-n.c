#define ABS(n) ((((long long) n >> 31) ^ (long long) n) - ((long long) n >> 31))

double myPow(double x, int n) {
    if (x == 0 || x == 1) return x;
    int sign = !!(n & (1U << 31));
    long long nl = ABS(n);
    if (sign) x = 1 / x;
    double ans = 1;
    for (; nl; nl >>= 1, x *= x) {
        if (nl & 1) ans = ans * x;
    }
    return ans;
}