int getSum(int a, int b) {
    int sum, carry;
    unsigned int x = (unsigned int) a;
    unsigned int y = (unsigned int) b;
    while (y) {
        sum = x ^ y;
        carry = (x & y) << 1;
        x = sum;
        y = carry;
    }
    return x;
}