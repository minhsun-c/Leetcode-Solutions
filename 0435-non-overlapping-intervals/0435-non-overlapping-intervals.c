static int cmp(const void *a, const void *b) {
    const int *_a = *(const int * const *)a;
    const int *_b = *(const int * const *)b;

    return (_a[1] != _b[1]) ? _a[1] - _b[1] : _a[0] - _b[0];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int *), cmp);
    int last = INT_MIN;
    int cnt = 0;
    for (int i=0; i<intervalsSize; i++) {
        if (intervals[i][0] < last) {
            cnt ++;
        } else {
            last = intervals[i][1];
        }
    }
    return cnt;
}