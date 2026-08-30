int __help(int n) {
    int a = n / 100;
    int b = n / 10 % 10;
    int c = n % 10;
    return (a < b && b > c) || (a > b && b < c);
}

int wav(int n) {
    int cnt = 0;
    while (n >= 100) {
        cnt += __help(n % 1000);
        n /= 10;
    }
    return cnt;
}

int totalWaviness(int num1, int num2) {
    int cnt = 0;
    for (int i=num1; i<=num2; i++) 
        cnt += wav(i);
    return cnt;
}