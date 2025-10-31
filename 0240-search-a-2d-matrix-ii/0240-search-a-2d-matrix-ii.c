

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int n = matrixColSize[0], m = matrixSize;
    int x = 0, y = n-1;
    while (1) {
        if (x < 0 || x >= m || y < 0 || y >= n) return false;
        if (target == matrix[x][y]) return true;
        else if (target > matrix[x][y]) x ++;
        else y --;
    }
    return false;
}