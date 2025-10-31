/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define OK(x, y) (x >= u && x <= b && y >= l && y <= r)

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void fill(int **mat, int n) {
    int l = 0, r = n-1, u = 0, b = n-1;
    int op = 0;
    int x = 0, y = 0;
    for (int cnt = 1; cnt <= n*n; cnt ++) {
        mat[x][y] = cnt;
        int new_x = x + dir[op][0];
        int new_y = y + dir[op][1];
        if (OK(new_x, new_y)) {
            x = new_x; y = new_y;
        } else {
            switch (op) {
            case 0: u ++; break;
            case 1: r --; break;
            case 2: b --; break;
            case 3: l ++; break;
            }
            op = (op + 1) & 3;
            x += dir[op][0];
            y += dir[op][1];
        }
    }
}

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int **ret = (int **)malloc(sizeof(int *) * n);
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    for (int i=0; i<n; i++) {
        ret[i] = (int *)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    fill(ret, n);
    return ret;
}