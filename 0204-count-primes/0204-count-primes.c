int countPrimes(int n) {
    if (n <= 2) return 0;
    int arr[n];
    memset(arr, 0, sizeof(arr));
    for (int i=2; i<n; i++) {
        if (arr[i]) continue;
        for (int j=i+i; j<n; j+=i) {arr[j] = 1;}
    }
    int cnt = 0;
    for (int i=2; i<n; i++) cnt += !arr[i];
    return cnt;
}