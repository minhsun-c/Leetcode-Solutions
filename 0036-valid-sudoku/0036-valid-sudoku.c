bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int tmp[10];
    int dir[9][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
    for (int i=0; i<9; i++) {
        memset(tmp, 0, sizeof(tmp));
        for (int j=0; j<9; j++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '0';
                if (tmp[num]) return false;
                tmp[num] = 1;
            }
        }
    }
    for (int i=0; i<9; i++) {
        memset(tmp, 0, sizeof(tmp));
        for (int j=0; j<9; j++) {
            if (board[j][i] != '.') {
                int num = board[j][i] - '0';
                if (tmp[num]) return false;
                tmp[num] = 1;
            }
        }
    }
    for (int i=0; i<9; i+=3) {
        for (int j=0; j<9; j+=3) {
            memset(tmp, 0, sizeof(tmp));
            for (int k=0; k<9; k++) {
                if (board[i + dir[k][0]][j + dir[k][1]] != '.') {
                    int num = board[i + dir[k][0]][j + dir[k][1]] - '0';
                    if (tmp[num]) return false;
                    tmp[num] = 1;
                }
            }
        }
    }
    return true;
}