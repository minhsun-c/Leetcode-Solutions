/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double graph[40][40];
char op_list[40][10];
int op_used;

static int getid(char *str, int op) {
    for (int i=0; i<op_used; i++)
        if (strcmp(op_list[i], str) == 0)
            return i;
    if (!op) {
        strcpy(op_list[op_used], str);
        op_used ++;
        return op_used - 1;
    }
    return -1;
}

static void add_edge(int i, int j, double val) {
    graph[i][j] = val;
    graph[j][i] = 1.0 / val;
}

static double dfs_util(int u, int target, double acc, int *seen) {
    if (u == target) return acc;
    seen[u] = 1;

    for (int v = 0; v < op_used; ++v) {
        double w = graph[u][v];
        if (w != 0.0 && !seen[v]) {
            double res = dfs_util(v, target, acc * w, seen);
            if (res != -1.0) return res;
        }
    }
    return -1.0;
}

double dfs(int start, int end) {
    if (start == end) return 1.0; 
    int seen[40] = {0};
    return dfs_util(start, end, 1.0, seen);
}

double* calcEquation(char*** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char*** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    op_used = 0;
    memset(graph, 0, sizeof(graph));
    *returnSize = queriesSize;
    double *ret = (double *)malloc(sizeof(double) * queriesSize);

    for (int i=0; i<equationsSize; i++) {
        int id1 = getid(equations[i][0], 0);
        int id2 = getid(equations[i][1], 0);
        add_edge(id1, id2, values[i]);
    }

    for (int i=0; i<queriesSize; i++) {
        int id1 = getid(queries[i][0], 1);
        int id2 = getid(queries[i][1], 1);
        if (id1 == -1 || id2 == -1) ret[i] = -1.0;
        else ret[i] = dfs(id1, id2);
    }

    return ret;
}