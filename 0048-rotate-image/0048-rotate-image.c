/*
(0, 0)   .. (0, n-1)

(n-1, 0) .. (n-1, n-1)
*/

#define DIR1(i, j) matrix[i][j]
#define DIR2(i, j) matrix[j][n-1-i]
#define DIR3(i, j) matrix[n-1-i][n-1-j]
#define DIR4(i, j) matrix[n-1-j][i]
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    for (int i=0; i<(n+1)/2; i++) {
        for (int j=i; j<n-i-1; j++) {
            int next, prev;
            // 1 --> 2
            next = DIR2(i, j);
            DIR2(i, j) = DIR1(i, j);
            prev = next;
            // 2 --> 3
            next = DIR3(i, j);
            DIR3(i, j) = prev;
            prev = next;
            // 3 --> 4
            next = DIR4(i, j);
            DIR4(i, j) = prev;
            prev = next;
            // 4 --> 1
            DIR1(i, j) = prev;
        }
    }
}
/*
1 1 1 1 0 
0 1 1 0 0 
0 0 1 0 0 
0 0 0 0 0
0 0 0 0 0 
*/