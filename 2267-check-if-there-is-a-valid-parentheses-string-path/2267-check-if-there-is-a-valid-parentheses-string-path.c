bool dp[100][100][100];
// dp[i][j][k] -> k means the stack depth

int min(int a, int b) {
    return a < b ? a : b;
}

bool hasValidPath(char** grid, int gridSize, int* gridColSize) {
    int row = gridSize;
    int col = gridColSize[0];

    if ((row + col - 1) % 2 != 0 || grid[0][0] == ')' || grid[row-1][col-1] == '(') 
        return false;

    memset(dp, 0, sizeof(dp));
    dp[0][0][1] = 1;

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (i == 0 && j == 0) continue;
            int step = grid[i][j] == '(' ? 1 : -1;
            int kmax = min(i + j + 1 /* walk */, (row - 1 - i) + (col - 1 - j) /* remain */);
            for (int k=0; k<=kmax; k++) {
                if (0 > k - step || k - step >= 100)
                    continue;
                if ((i > 0 && dp[i-1][j][k-step]) || (j > 0 && dp[i][j-1][k-step])) 
                    dp[i][j][k] = 1;
            }
        }
    }
    return dp[row-1][col-1][0];
}