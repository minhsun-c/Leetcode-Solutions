/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

char **alloc(int row, int col) {
    char **ret = malloc(sizeof(char *) * col);
    for (int i=0; i<col; i++)
        ret[i] = malloc(row);
    return ret;
}

char** rotateTheBox(char** boxGrid, int boxGridSize, int* boxGridColSize, int* returnSize, int** returnColumnSizes) {
    int row = boxGridSize;
    int col = boxGridColSize[0];
    char **ret = alloc(row, col);
    for (int i=0; i<row; i++) {
        int idx = col-1;
        for (int j=col-1; j>=0; j--) {
            if (boxGrid[i][j] == '*') {
                ret[j][row-i-1] = '*';
                while (idx > j) {
                    ret[idx][row-i-1] = '.';
                    idx --;
                }
                idx --;
            } else if (boxGrid[i][j] == '#') {
                ret[idx][row-i-1] = '#';
                idx --;
            } 
        }
        while (idx >= 0) {
            ret[idx][row-i-1] = '.';
            idx --;
        }
    }
    *returnSize = col;
    *returnColumnSizes = malloc(sizeof(int) * col);
    for (int i=0; i<col; i++) (*returnColumnSizes)[i] = row;
    return ret;
}