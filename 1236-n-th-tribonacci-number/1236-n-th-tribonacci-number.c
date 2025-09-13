int tribonacci(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    int arr[40] = {0, 1, 1};
    for (int i=3; i<=n; i++) arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    return arr[n];
}