#include <stdlib.h>

typedef struct Edge {
    int to;
    unsigned char cost;  // 1 if original edge is u->v (needs flip when going away from 0), else 0
    int next;
} Edge;

static Edge *E;
static int *head;
static unsigned char *vis;
static int ei;

static void add_edge(int u, int v, int c) {
    E[ei].to = v;
    E[ei].cost = (unsigned char)c;
    E[ei].next = head[u];
    head[u] = ei++;
}

static int dfs(int u) {
    vis[u] = 1;
    int ans = 0;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].to;
        if (!vis[v]) {
            ans += E[e].cost;   // count flip if original direction was u->v
            ans += dfs(v);
        }
    }
    return ans;
}

int minReorder(int n, int **connections, int connectionsSize, int *connectionsColSize) {
    int m = connectionsSize;

    E = (Edge *)malloc(sizeof(Edge) * (2 * m));
    head = (int *)malloc(sizeof(int) * n);
    vis = (unsigned char *)calloc(n, sizeof(unsigned char));
    ei = 0;
    for (int i = 0; i < n; i++) head[i] = -1;

    // For edge a->b, store (a->b,1) and (b->a,0)
    for (int i = 0; i < m; i++) {
        int a = connections[i][0];
        int b = connections[i][1];
        add_edge(a, b, 1);
        add_edge(b, a, 0);
    }

    int ans = dfs(0);

    free(E);
    free(head);
    free(vis);
    return ans;
}
