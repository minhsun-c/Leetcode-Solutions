int equalPairs(int** grid, int gridSize, int* gridColSize) {
    int cnt = 0, flag;
    for (int row=0; row<gridSize; row ++) {
        for (int col=0; col<gridSize; col ++) {
            flag = 1;
            for (int i=0; i<gridSize; i ++) {
                if (grid[row][i] != grid[i][col]) {
                    flag = 0;
                    break;
                }
            }
            cnt += flag;
        }
    }
    return cnt;
}