

int minFlips(int a, int b, int c){
    int cnt = 0;
    for (uint mask = 1 << 30; mask; mask >>= 1) {
        if (c & mask) cnt += (!(a & mask) && !(b & mask));
        else cnt += !!(a & mask) + !!(b & mask);
    }
    return cnt;
}