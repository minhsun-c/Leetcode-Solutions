int smallestNumber(int n) {
    int set = 0;
    for (int i=1<<10; i; i>>=1) {
        if (set) n |= i;
        else if (n & i) set = 1;
    }
    return n;
}