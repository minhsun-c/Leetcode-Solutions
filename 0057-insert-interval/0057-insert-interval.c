/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    // malloc
    int **ans = malloc(sizeof(int *) * (intervalsSize + 1));
    int *col = malloc(sizeof(int) * (intervalsSize + 1));

    // counter
    int i = 0;
    int used = 0;
    int lo = newInterval[0];
    int hi = newInterval[1];

    // left
    while (i < intervalsSize && intervals[i][1] < lo) {
        ans[used] = intervals[i];
        col[used] = 2;
        i ++;
        used ++;
    }

    // merged
    while (i < intervalsSize && intervals[i][0] <= hi) {
        lo = min(intervals[i][0], lo);
        hi = max(intervals[i][1], hi);
        i ++;
    }
    int *merged = malloc(sizeof(int) * 2);
    merged[0] = lo;
    merged[1] = hi;
    ans[used] = merged;
    col[used] = 2;
    used ++;

    // right
    while (i < intervalsSize) {
        ans[used] = intervals[i];
        col[used] = 2;
        i ++;
        used ++;
    }

    // return 
    *returnSize = used;
    *returnColumnSizes = col;
    return ans;
}