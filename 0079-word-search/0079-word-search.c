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

bool precheck(char **board, int row, int col, char *word) {
    unsigned char get[64], need[64];
    memset(get, 0, sizeof(get));
    memset(need, 0, sizeof(need));
    for (int i=0; i<row; i++) 
        for (int j=0; j<col; j++)
            get[board[i][j] - 'A'] ++;
    for (char *c = word; *c; c++) 
        need[*c - 'A'] ++;
    return memcmp(get, need, sizeof(get));
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int row = boardSize;
    int col = boardColSize[0];
    if (precheck(board, row, col, word) < 0)
        return false;
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (dfs(board, i, j, row, col, word))
                return true;
        }
    }
    return false;
}