/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define UL(x, y) (x == u && y == l)
#define UR(x, y) (x == u && y == r)
#define DL(x, y) (x == d && y == l)
#define DR(x, y) (x == d && y == r)

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int row = matrixSize, col = matrixColSize[0];
    int size = row * col;
    int *arr = (int *)malloc(sizeof(int) * size);
    int idx = 0;
    int l = 0, r = col - 1, u = 0, d = row - 1;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int cur_dir = 0;

    int x = 0, y = 0;
    while (idx != size) {
        arr[idx ++] = matrix[x][y];
        if (cur_dir == 0 && UR(x, y)) {
            u ++;
            cur_dir = (cur_dir + 1) & 3;
        } 
        else if (cur_dir == 1 && DR(x, y)) {
            r --;
            cur_dir = (cur_dir + 1) & 3;
        } 
        else if (cur_dir == 2 && DL(x, y)) {
            d --;
            cur_dir = (cur_dir + 1) & 3;
        } 
        else if (cur_dir == 3 && UL(x, y)) {
            l ++;
            cur_dir = (cur_dir + 1) & 3;
        } 
        x += dir[cur_dir][0];
        y += dir[cur_dir][1];
    }

    *returnSize = size;
    return arr;
}