typedef struct {
    int to;
    double w;
} Edge;

typedef struct {
    Edge *edges;
    int n, cap;
} Adj;

// ----- simple string -> id map (linear search; fine for typical constraints) -----
static const char **names = NULL;
static int names_n = 0;
static int names_cap = 0;

static int find_id(const char *s) {
    for (int i = 0; i < names_n; ++i) {
        if (strcmp(names[i], s) == 0) return i;
    }
    return -1;
}

static int get_or_add_id(const char *s) {
    int id = find_id(s);
    if (id >= 0) return id;
    if (names_n == names_cap) {
        names_cap = names_cap ? names_cap * 2 : 32;
        names = (const char **)realloc(names, names_cap * sizeof(*names));
    }
    names[names_n] = s; // safe to store pointer to input string during call
    return names_n++;
}

// ----- adjacency list helpers -----
static void add_edge(Adj *G, int u, int v, double w) {
    if (G[u].n == G[u].cap) {
        G[u].cap = G[u].cap ? G[u].cap * 2 : 4;
        G[u].edges = (Edge *)realloc(G[u].edges, G[u].cap * sizeof(Edge));
    }
    G[u].edges[G[u].n++] = (Edge){ .to = v, .w = w };
}

static double dfs_eval(Adj *G, int u, int target, int *vis, double acc, int *found) {
    if (u == target) { *found = 1; return acc; }
    vis[u] = 1;
    for (int i = 0; i < G[u].n; ++i) {
        int v = G[u].edges[i].to;
        if (!vis[v]) {
            double res = dfs_eval(G, v, target, vis, acc * G[u].edges[i].w, found);
            if (*found) return res;
        }
    }
    return -1.0;
}

double* calcEquation(char*** equations, int equationsSize, int* equationsColSize,
                     double* values, int valuesSize,
                     char*** queries, int queriesSize, int* queriesColSize,
                     int* returnSize) {

    (void)equationsColSize; (void)queriesColSize; // unused (always 2)
    *returnSize = queriesSize;

    // reset global map for each call
    names_n = 0;
    names_cap = 0;
    free(names);
    names = NULL;

    // 1) Map variables to ids
    for (int i = 0; i < equationsSize; ++i) {
        int a = get_or_add_id(equations[i][0]);
        int b = get_or_add_id(equations[i][1]);
        (void)a; (void)b;
    }
    int N = names_n;

    // 2) Build graph
    Adj *G = (Adj *)calloc(N, sizeof(Adj));
    for (int i = 0; i < equationsSize; ++i) {
        int a = find_id(equations[i][0]);
        int b = find_id(equations[i][1]);
        double k = values[i];
        add_edge(G, a, b, k);
        add_edge(G, b, a, 1.0 / k);
    }

    // 3) Answer queries
    double *ans = (double *)malloc(sizeof(double) * queriesSize);
    int *vis = (int *)malloc(sizeof(int) * N);

    for (int q = 0; q < queriesSize; ++q) {
        const char *C = queries[q][0];
        const char *D = queries[q][1];
        int u = find_id(C);
        int v = find_id(D);

        if (u < 0 || v < 0) {
            ans[q] = -1.0;                 // unknown variable
        } else if (u == v) {
            ans[q] = 1.0;                  // x/x = 1.0 (if x exists)
        } else {
            memset(vis, 0, sizeof(int) * N);
            int found = 0;
            ans[q] = dfs_eval(G, u, v, vis, 1.0, &found);
            if (!found) ans[q] = -1.0;
        }
    }

    // 4) Cleanup (graph)
    for (int i = 0; i < N; ++i) free(G[i].edges);
    free(G);
    free(vis);

    // Note: we don't free `names` here because the judge may call this once.
    // If you embed this in your own program, free(names) when done.
    return ans;
}
