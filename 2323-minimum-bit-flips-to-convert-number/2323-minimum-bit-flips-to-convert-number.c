int countbits(int n) {
    int cnt = 0;
    while (n) {
        cnt += (n & 1);
        n >>= 1;
    }
    return cnt;
}

int minBitFlips(int start, int goal) {
    return countbits(start ^ goal);
}