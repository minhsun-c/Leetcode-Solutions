/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int hash[51];

int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int *arr = malloc(sizeof(int) * ASize);
    *returnSize = ASize;
    arr[0] = 0;

    memset(hash, 0, sizeof(hash));
    if (A[0] == B[0]) arr[0] = 1;
    else {
        hash[A[0]] = 1;
        hash[B[0]] = 1;
    }
    for (int i=1; i<ASize; i++) {
        arr[i] = arr[i-1];
        if (hash[A[i]] == 1) arr[i] += 1;
        else hash[A[i]] = 1;
        if (hash[B[i]] == 1) arr[i] += 1;
        else hash[B[i]] = 1;
    }

    return arr;
}