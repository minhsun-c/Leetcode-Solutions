typedef struct { int s, e; } Pair;

static int cmp_pair_end_then_start(const void *a, const void *b) {
    const Pair *A = a, *B = b;
    if (A->e != B->e) return (A->e > B->e) - (A->e < B->e);
    return (A->s > B->s) - (A->s < B->s);
}

int eraseOverlapIntervals(int **intervals, int n, int *intervalsColSize) {
    Pair *v = malloc((size_t)n * sizeof(*v));
    for (int i = 0; i < n; ++i) { v[i].s = intervals[i][0]; v[i].e = intervals[i][1]; }

    qsort(v, n, sizeof *v, cmp_pair_end_then_start);

    int last = INT_MIN, removed = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i].s < last) removed++;
        else last = v[i].e;
    }
    free(v);
    return removed;
}
