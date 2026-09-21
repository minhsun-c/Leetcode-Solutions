bool dfs(char **map, int x, int y, int row, int col, char *str) {
    if (*str == '\0')
        return true;
    if (x < 0 || x >= row || y < 0 || y >= col || map[x][y] == '\0' || map[x][y] != *str) 
        return false;
    char cur = map[x][y];
    map[x][y] = '\0';
    bool rst = dfs(map, x+1, y, row, col, str+1) || dfs(map, x-1, y, row, col, str+1) || dfs(map, x, y+1, row, col, str+1) || dfs(map, x, y-1, row, col, str+1);
    map[x][y] = cur;
    return rst;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int row = boardSize;
    int col = boardColSize[0];
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (dfs(board, i, j, row, col, word))
                return true;
        }
    }
    return false;
}