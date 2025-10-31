#define ISSET(n, idx) (!!(n & (1 << (idx-1))))
#define SET(n, idx) (n |= (1 << (idx-1)))
#define ISNUM(n) (n >= 0 && n <= 9)

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int mask;

    for (int i=0; i<9; i++) {
        mask = 0;
        for (int j=0; j<9; j++) {
            int x = board[i][j] - '0';
            if (!ISNUM(x)) continue;
            if (ISSET(mask, x)) return false;
            SET(mask, x);
        }
    }

    for (int i=0; i<9; i++) {
        mask = 0;
        for (int j=0; j<9; j++) {
            int x = board[j][i] - '0';
            if (!ISNUM(x)) continue;
            if (ISSET(mask, x)) return false;
            SET(mask, x);
        }
    }

    for (int i=0; i<9; i+=3) {
        for (int j=0; j<9; j+=3) {
            mask = 0;
            for (int k=0; k<9; k++) {
                int x = board[i+k/3][j+k%3] - '0';
                if (!ISNUM(x)) continue;
                if (ISSET(mask, x)) return false;
                SET(mask, x);
            }
        }
    }
    return true;
}