/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int slot_cmp(int *list, int *ins) {
    if (list[0] != ins[0]) 
        return list[0] - ins[0];
    return list[1] - ins[1];
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    // find the spot : after intervals[mid_id]
    int mid_id = -1;
    for (int i=0; i<intervalsSize; i++) {
        int cmp_rst = slot_cmp(intervals[i], newInterval);
        if (cmp_rst < 0) 
            mid_id ++;
        else
            break;
    }
    printf("mid: %d\n", mid_id);

    // check <--  
    int l_min = mid_id;
    for (int i=mid_id; i>=0; i--) {
        printf("left: [%d, %d]\n", intervals[i][0], intervals[i][1]);
        if (newInterval[0] <= intervals[i][0]) {
            l_min --;
        } else if (intervals[i][0] <= newInterval[0] && newInterval[0] <= intervals[i][1]) {
            newInterval[0] = intervals[i][0];
            l_min --;
        } else
            break;
    }

    // check -->
    int start = mid_id < 0 ? 0 : mid_id;     
    int r_max = start;                         
    for (int i = start; i < intervalsSize; i++) {
        if (newInterval[1] >= intervals[i][1]) {
            r_max ++;
        } else if (intervals[i][0] <= newInterval[1] && newInterval[1] <= intervals[i][1]) {
            newInterval[1] = intervals[i][1];
            r_max ++;
        } else
            break;
    }

    printf("l_min: %d, r_max: %d\n", l_min, r_max);

    printf("[0] = %d\n", newInterval[0]);
    printf("[1] = %d\n", newInterval[1]);

    // merge 0 .. l_min | inserted | r_max .. (size-1)
    int **ans = malloc(sizeof(int *) * (intervalsSize + 1));
    int id = 0;
    *returnColumnSizes = malloc(sizeof(int) * (intervalsSize + 1));
    for (int i=0; i<=l_min; i++) {
        ans[id] = intervals[i];
        (*returnColumnSizes)[id] = 2;
        id ++;
    }
    ans[id] = newInterval;
    (*returnColumnSizes)[id] = 2;
    id ++;
    for (int i=r_max; i >= 0 && i<intervalsSize; i++) {
        ans[id] = intervals[i];
        (*returnColumnSizes)[id] = 2;
        id ++;
    }

    // return
    *returnSize = id;
    return ans;
}