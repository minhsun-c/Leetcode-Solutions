/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **ret = (int **)malloc(sizeof(int *) * numRows);
    *returnColumnSizes = (int *) malloc(sizeof(int) * numRows);
    *returnSize = numRows;

    ret[0] = (int *) malloc(sizeof(int));
    ret[0][0] = 1;
    (*returnColumnSizes)[0] = 1;

    for (int i=1; i<numRows; i++) {
        ret[i] = (int *) malloc(sizeof(int) * (i+1));
        ret[i][0] = ret[i][i] = 1;
        (*returnColumnSizes)[i] = i+1;
        for (int j=1; j<i; j++) {
            ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        }
    }
    return ret;
}