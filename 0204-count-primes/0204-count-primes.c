int countPrimes(int n) {
    if (n <= 2) return 0;
    int arr[n];
    memset(arr, 0, sizeof(arr));
    for (int i=3; i<n; i+=2) {
        if (arr[i]) continue;
        for (int j=i+i; j<n; j+=i) {arr[j] = 1;}
    }
    int cnt = 1;
    for (int i=3; i<n; i+=2) cnt += !arr[i];
    return cnt;
}