/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int *cand;
int csize;
int **ret;
int *retsize;
int used;
int cap;
int buf[300];
int bsize;

void check_size() {
    if (used < cap) return;
    ret = (int **) realloc(ret, sizeof(int *) * cap * 2);
    retsize = (int *) realloc(retsize, sizeof(int) * cap * 2);
    cap = cap << 1; 
}

void store() {
    check_size();
    ret[used] = (int *) malloc(sizeof(int) * bsize);
    retsize[used] = bsize;
    memcpy(ret[used], buf, sizeof(int) * bsize);
    used ++;
}

void rec(int idx, int target) {
    if (target == 0) {
        store();
        return;
    } 
    for (int i=idx; i<csize; i++) {
        if (cand[i] > target) break;
        buf[bsize ++] = cand[i];
        rec(i, target - cand[i]);
        bsize --;
    }
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int** combinationSum(int* candidates, int candidatesSize, int target, 
                        int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    cap = 16;
    ret = (int **) malloc(sizeof(int *) * cap);
    retsize = (int *) malloc(sizeof(int) * cap);
    used = 0;
    cand = candidates;
    csize = candidatesSize;
    bsize = 0;

    rec(0, target);
    *returnColumnSizes = retsize;
    *returnSize = used;
    return ret;
}