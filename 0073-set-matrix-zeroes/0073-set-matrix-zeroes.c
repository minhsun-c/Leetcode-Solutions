void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int row = matrixSize;
    int col = matrixColSize[0];
    int rarr[row], carr[col];
    memset(rarr, 0, sizeof(rarr));
    memset(carr, 0, sizeof(carr));
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (matrix[i][j] == 0) {
                rarr[i] = carr[j] = 1;
            }
        }
    }
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (rarr[i] || carr[j]) 
                matrix[i][j] = 0;
        }
    }
}