#define GETNODE(x) ((x) & 0x7fffffff)
#define REAL(x) ((x) | 0x80000000)
#define ISREAL(x) (!!((x) & 0x80000000))

typedef struct {
    uint32_t link[50000];
    int used;
    int visited;
} info_t;

info_t *infos;
int size;

void create_map(int n) {
    infos = (info_t *)malloc(sizeof(info_t) * n);
    size = n;
    for (int i=0; i<n; i++) {
        infos[i].used = 0;
        infos[i].visited = 0;
    }
}

void free_map() {
    free(infos);
}

void add_link(int **connections, int connectionsSize) {
    for (int i=0; i<connectionsSize; i++) {
        int from = connections[i][0];
        int to = connections[i][1];
        int idx1 = infos[from].used ++;
        int idx2 = infos[to].used ++;
        infos[from].link[idx1] = to;
        infos[to].link[idx2] = REAL(from);
    }
}

int dfs(int idx) {
    if (infos[idx].visited) return 0;
    infos[idx].visited = 1;
    int count = 0, target, node;
    for (int i=0; i<infos[idx].used; i++) {
        target = infos[idx].link[i];
        node = GETNODE(target);
        if (ISREAL(target)) {
            count += dfs(node);
        } else {
            count += !infos[node].visited;
            count += dfs(node);
        }
    }
    return count;
}

int minReorder(int n, int **connections, int connectionsSize, int *connectionsColSize) {
    create_map(n);
    add_link(connections, connectionsSize);
    int ret = dfs(0);
    free_map();
    return ret;
}
