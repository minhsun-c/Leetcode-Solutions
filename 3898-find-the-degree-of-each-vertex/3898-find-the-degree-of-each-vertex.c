/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDegrees(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int *arr = calloc(matrixSize, sizeof(int));
    *returnSize = matrixSize;
    for (int i=0; i<matrixSize; i++) {
        for (int j=i; j<matrixSize; j++) {
            if (matrix[i][j]) {
                arr[i] ++;
                arr[j] ++;
            }
        }
    }
    return arr;
}