int differenceOfSums(int n, int m) {
    int sum = 0;
    for (int i=1; i<=n; i++) {
        if (i % m) sum += i;
        else sum -= i;
    }
    return sum;
}