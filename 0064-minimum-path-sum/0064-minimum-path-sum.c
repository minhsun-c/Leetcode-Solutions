int min(int a, int b) {
    return a < b ? a : b;
}

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int dp[200][200];
    int row = gridSize;
    int col = gridColSize[0];

    dp[0][0] = grid[0][0];

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            int ver = INT_MAX, hor = INT_MAX;
            if (i-1 >= 0) {
                ver = dp[i-1][j];
            }
            if (j-1 >= 0) {
                hor = dp[i][j-1];
            }
            if (i != 0 || j != 0)
                dp[i][j] = grid[i][j] + min(ver, hor);
        }
    }
    return dp[row-1][col-1];
}