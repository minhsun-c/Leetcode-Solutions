int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int dp[100][100];
    int row = obstacleGridSize;
    int col = obstacleGridColSize[0];
    memset(dp, 0, sizeof(dp));

    if (obstacleGrid[0][0] || obstacleGrid[row-1][col-1]) 
        return 0;

    dp[0][0] = 1;

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (i-1 >= 0) { // N --> S
                if (!obstacleGrid[i-1][j]) 
                    dp[i][j] += dp[i-1][j];
            }
            if (j-1 >= 0) { // W --> E
                if (!obstacleGrid[i][j-1]) 
                    dp[i][j] += dp[i][j-1];
            }
        }
    }
    return dp[row-1][col-1];
}