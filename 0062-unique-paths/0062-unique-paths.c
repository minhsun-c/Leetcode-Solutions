#define isPath(x, y) (x >= 0 && x < m && y >= 0 && y < n)

int uniquePaths(int m, int n) {
    int maze[m][n];
    memset(maze, 0, sizeof(maze));
    maze[0][0] = 1;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (isPath(i-1, j)) maze[i][j] += maze[i-1][j];
            if (isPath(i, j-1)) maze[i][j] += maze[i][j-1];
        }
    }
    return maze[m-1][n-1];
}