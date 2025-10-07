/*
F(n): fill 2 x n
G(n): fill 2 x (n-1), with an extra block

F(n) = F(n-1) + F(n-2) + 2G(n-1)
G(n) = G(n-1) + F(n-2)

-> F(n) = 2F(n-1) + F(n-3)
*/

#define MOD 1000000007

int numTilings(int n) {
    if (n <= 1) return 1;
    if (n == 2) return 2;

    long long f0 = 1, f1 = 1, f2 = 2, fn;
    for (int i = 3; i <= n; i++) {
        fn = (2 * f2 + f0) % MOD;
        f0 = f1;
        f1 = f2;
        f2 = fn;
    }
    return f2;
}

