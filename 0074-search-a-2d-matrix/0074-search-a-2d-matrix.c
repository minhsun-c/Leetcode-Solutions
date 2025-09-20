bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int row = matrixSize;
    int col = matrixColSize[0];
    for (int i=0; i<row; i++) {
        if (matrix[i][0] <= target || target <= matrix[i][col - 1]) {
            for (int j=0; j<col; j++) if (matrix[i][j] == target) return true;
        }
    }
    return false;
}