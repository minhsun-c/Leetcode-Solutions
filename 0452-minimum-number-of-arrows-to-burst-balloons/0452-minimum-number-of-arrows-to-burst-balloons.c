static inline int cmp(const void *a, const void *b) {
    const int *_a = *(const int * const *)a;
    const int *_b = *(const int * const *)b;
    long long diff1 =  _a[1] - (long long ) _b[1];
    long long diff0 =  _a[0] - (long long ) _b[0];
    int df1 = (diff1 > 0) ? 1 : (diff1 == 0) ? 0 : -1;
    int df0 = (diff0 > 0) ? 1 : (diff0 == 0) ? 0 : -1;
    return (df1) ? df1 : df0;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int *), cmp);
    int last = INT_MIN;
    int pass = 1;
    int cnt = 0;
    for (int i=0; i<pointsSize; i++) {
        if (pass && points[i][0] == INT_MIN) {
            cnt ++;
            last = points[i][1];
            pass = 0;
        }
        else if (points[i][0] > last) {
            cnt ++;
            last = points[i][1];
        }
    }
    return cnt;
}