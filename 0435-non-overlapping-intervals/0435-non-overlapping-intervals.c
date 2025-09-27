static int cmp(const void *a, const void *b) {
    const int *A = *(const int * const *)a;
    const int *B = *(const int * const *)b;

    if (A[1] != B[1]) return (A[1] > B[1]) - (A[1] < B[1]); // avoid subtraction overflow
    return (A[0] > B[0]) - (A[0] < B[0]);
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