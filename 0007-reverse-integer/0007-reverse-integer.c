int reverse(int x){
    long long sum = 0;
    while (x) {
        sum *= 10;
        sum += x % 10;
        x /= 10;
    }

    if (sum > INT_MAX || sum < INT_MIN) return 0;
    return sum;
}