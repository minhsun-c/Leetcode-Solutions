#define isPath(x, y) (x >= 0 && x < row && y >= 0 && y < col && maze[x][y] == '.')
#define Mark(x, y) (maze[x][y] = '#')

#define isBorder(x, y) \
    (x == 0 || x == row - 1 || y == 0 || y == col - 1)

#define isExit(x, y) isBorder(x, y)

typedef struct {
    int x, y;
} coord_t;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int queue_x[10000];
int queue_y[10000];
int front, end, size;

void push(int x, int y) {
    queue_x[end] = x;
    queue_y[end] = y;
    end ++;
    size ++;
}

coord_t *pop() {
    static coord_t top;
    top.x = queue_x[front];
    top.y = queue_y[front];
    front ++;
    size --;
    return &top;
}

int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize) {
    int row = mazeSize;
    int col = mazeColSize[0];
    front = end = size = 0;
    coord_t *cur;
    int cur_x = entrance[0];
    int cur_y = entrance[1];
    int dist = 0; int qs;
    push(cur_x, cur_y);
    Mark(cur_x, cur_y);
    while (size) {
        qs = size;
        for (int i=0; i<qs; i ++) {
            cur = pop();
            cur_x = cur -> x;
            cur_y = cur -> y;
            if (dist > 0 && isExit(cur_x, cur_y)) return dist;
            for (int j=0; j<4; j++) {
                
                if (isPath(cur_x + dir[j][0], cur_y + dir[j][1])) {
                    Mark(cur_x + dir[j][0], cur_y + dir[j][1]);
                    push(cur_x + dir[j][0], cur_y + dir[j][1]);
                }
            }
        }
        dist ++;
    }
    return -1;
}