/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int bs(int spell, int *potion, int size, long long success) {
    int left = 0, right = size - 1, mid;
    while (left < right) {
        mid = (left + right) / 2;
        long long cur = potion[mid] * (long long) spell;
        if (cur < success) left = mid + 1;
        else right = mid - 1;
    }
    return right;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    int *arr = (int *)malloc(sizeof(int) * spellsSize);
    *returnSize = spellsSize;
    qsort(potions, potionsSize, sizeof(int), cmp);
    for (int i=0; i<spellsSize; i++) {
        long long tmp = spells[i] * (long long) potions[potionsSize - 1];
        if (tmp < success) {
            arr[i] = 0;
            continue;
        }
        int idx = bs(spells[i], potions, potionsSize, success);
        while (idx < potionsSize) {
            if (idx == -1) {
                arr[i] = potionsSize;
                break;
            }
            else if ((long long) potions[idx] * spells[i] < success) 
                idx ++;
            else {
                arr[i] = potionsSize - idx;
                break;
            }
        }
    }
    return arr;
}