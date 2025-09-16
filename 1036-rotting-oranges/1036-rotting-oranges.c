#define isSafe(x, y) (x >= 0 && y >= 0 && x < row && y < col)
#define EMPTY 0
#define FRESH 1
#define ROT 2

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int qx[100];
int qy[100];
int front, end, size;

void push(int x, int y) {
    qx[end] = x;
    qy[end] = y;
    end ++; size ++;
}

int pop() {
    front ++;
    size --;
    return front - 1;
}

void init() {
    front = end = size = 0;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int round = 0, cnt = 0;
    int row = gridSize;
    int col = gridColSize[0];
    int tmp;
    init();
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (grid[i][j] == FRESH) cnt ++;
            else if (grid[i][j] == ROT) push(i, j);
        }
    }
    if (cnt == 0) return 0;
    while (size) {
        tmp = size;
        bool flag = false;
        int top, x, y;
        for (int i=0; i<tmp; i++) {
            top = pop();
            for (int j=0; j<4; j++) {
                x = qx[top] + dir[j][0];
                y = qy[top] + dir[j][1];
                if (isSafe(x, y) && grid[x][y] == FRESH) {
                    push(x, y);
                    grid[x][y] = ROT;
                    flag = true;
                    cnt --;
                }
            }
        }
        round ++;
    }
    return (cnt) ? -1 : round - 1;
}