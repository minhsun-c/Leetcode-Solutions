bool uniqueOccurrences(int* arr, int arrSize) {
    int hash1[2001] = {0};
    int hash2[2001] = {0};
    for (int i=0; i<arrSize; i++) hash1[arr[i] + 1000] ++;
    for (int i=0; i<2001; i++) {
        hash2[hash1[i]] ++;
        if (hash1[i] && hash2[hash1[i]] >= 2) return false;
    }
    return true;
}