#define OLD 0
#define NEW 1
#define GET(n, op) !!(n &   (1 << op))
#define SET(n, op)   (n |=  (1 << op))
#define CLR(n, op)   (n &= ~(1 << op))

int row, col;
int dir[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, 
    {0, 1}, {1, -1}, {1, 0}, {1, 1}
};

static inline bool bound(int x, int y) {
    return (x >= 0 && x < row && y >= 0 && y < col);
} 

void gameOfLife(int** board, int boardSize, int* boardColSize) {
    row = boardSize; col = boardColSize[0];
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            int live = 0, dead = 0;
            int cur = GET(board[i][j], OLD);
            for (int k=0; k<8; k++) {
                int x = i+dir[k][0];
                int y = j+dir[k][1];
                if (bound(x, y)) {
                    int status = GET(board[x][y], OLD);
                    live += (status == 1);
                    dead += (status == 0);
                }
            }
            if (cur == 1 && live < 2) CLR(board[i][j], NEW);
            else if (cur == 1 && (live == 2 || live == 3)) SET(board[i][j], NEW);
            else if (cur == 1 && dead > 3) CLR(board[i][j], NEW);
            else if (cur == 0 && live == 3) SET(board[i][j], NEW);
        }
    }
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            int status = GET(board[i][j], NEW);
            CLR(board[i][j], NEW);
            if (status) SET(board[i][j], OLD);
            else CLR(board[i][j], OLD);
        }
    }
}