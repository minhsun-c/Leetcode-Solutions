bool checkDivisibility(int n) {
    int sum = 0;
    int pdt = 1;
    int tmp = n;
    while (tmp) {
        sum += tmp%10;
        pdt *= tmp%10;
        tmp /= 10;
    }
    return n % (sum + pdt) == 0;
}