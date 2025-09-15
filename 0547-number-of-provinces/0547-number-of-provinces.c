int used[200];
int count;

void rec(int **map, int n, int cur) {
    if (used[cur]) return;
    used[cur] = 1;
    for (int i=0; i<n; i++) {
        if (!used[i] && map[cur][i])
            rec(map, n, i);
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    memset(used, 0, sizeof(used));
    count = 0;    
    for (int i=0; i<isConnectedSize; i++)
        if (!used[i]) {
            count ++;
            rec(isConnected, isConnectedSize, i);
        }
    return count;
}