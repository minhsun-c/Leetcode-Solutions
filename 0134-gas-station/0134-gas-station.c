int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int start = 0;
    int cur = 0;
    int total = 0;
    for (int i=0; i<gasSize; i++) {
        int diff = gas[i] - cost[i];
        total += diff;
        cur += diff;

        if (cur < 0) {
            start = i + 1;
            cur = 0;
        }
    }
    
    if (total < 0) return -1;
    return start;
}