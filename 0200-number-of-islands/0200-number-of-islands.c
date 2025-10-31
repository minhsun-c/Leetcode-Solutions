void dfs(char **grid, int x, int y, int row, int col) {
    if (x >= 0 && x <= row && y >= 0 && y <= col && grid[x][y] == '1') grid[x][y] = '0';
    else return;
    dfs(grid, x+1, y, row, col);
    dfs(grid, x, y+1, row, col);
    dfs(grid, x-1, y, row, col);
    dfs(grid, x, y-1, row, col);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int cnt = 0;
    int row = gridSize-1;
    int col = gridColSize[0]-1;
    for (int i=0; i<=row; i++) {
        for (int j=0; j<=col; j++) {
            if (grid[i][j] == '1') {
                cnt ++;
                dfs(grid, i, j, row, col);
            }
        }
    }
    return cnt;
}