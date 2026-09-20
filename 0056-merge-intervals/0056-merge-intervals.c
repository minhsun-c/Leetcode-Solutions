/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b) {
    const int a1 = (*(const int **) a)[0];
    const int a2 = (*(const int **) a)[1];
    const int b1 = (*(const int **) b)[0];
    const int b2 = (*(const int **) b)[1];
    if (a1 != b1) return a1 - b1;
    return a2 - b2;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    // init 
    int **mg = malloc(sizeof(int *) * intervalsSize);
    int gid = 0;
    *returnColumnSizes = malloc(sizeof(int) * intervalsSize);

    // sort
    qsort(intervals, intervalsSize, sizeof(int) * 2, cmp);

    // merge
    int prev0 = intervals[0][0], prev1 = intervals[0][1];
    for (int i=1; i<intervalsSize; i++) {
        if (prev0 <= intervals[i][0] && intervals[i][0] <= prev1) {
            // merged
            prev1 = max(prev1, intervals[i][1]);
        } else {
            // split
            (*returnColumnSizes)[gid] = 2;
            mg[gid] = malloc(sizeof(int) * 2);
            mg[gid][0] = prev0;
            mg[gid][1] = prev1;
            prev0 = intervals[i][0];
            prev1 = intervals[i][1]; 
            gid ++;
        }
    }

    (*returnColumnSizes)[gid] = 2;
    mg[gid] = malloc(sizeof(int) * 2);
    mg[gid][0] = prev0;
    mg[gid][1] = prev1;
    gid ++;

    // return
    *returnSize = gid;
    return mg;
}