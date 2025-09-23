#include <stdlib.h>

typedef struct { int to, next; unsigned char cost; } Edge;

int minReorder(int n, int **connections, int connectionsSize, int *connectionsColSize) {
    int m = connectionsSize;
    Edge *E = (Edge *)malloc(sizeof(Edge) * (2 * m));
    int  *head = (int *)malloc(sizeof(int) * n);
    int  *vis  = (int *)calloc(n, sizeof(int));
    int  *stack = (int *)malloc(sizeof(int) * n);
    int ei = 0;

    for (int i = 0; i < n; i++) head[i] = -1;

    // build: for a->b, store (a->b, cost=1) and (b->a, cost=0)
    for (int i = 0; i < m; i++) {
        int a = connections[i][0], b = connections[i][1];

        E[ei].to = b; E[ei].cost = 1; E[ei].next = head[a]; head[a] = ei++; // a->b needs flip when going out from 0
        E[ei].to = a; E[ei].cost = 0; E[ei].next = head[b]; head[b] = ei++; // b->a already toward 0
    }

    // iterative DFS from 0
    int top = 0, ans = 0;
    stack[top++] = 0;
    vis[0] = 1;

    while (top) {
        int u = stack[--top];
        for (int e = head[u]; e != -1; e = E[e].next) {
            int v = E[e].to;
            if (!vis[v]) {
                ans += E[e].cost;   // count flips only when original dir is u->v
                vis[v] = 1;
                stack[top++] = v;
            }
        }
    }

    free(E); free(head); free(vis); free(stack);
    return ans;
}
