/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char* seq, int* returnSize) {
    ssize_t sl = strlen(seq);
    int *arr = malloc(sizeof(int) * sl);
    *returnSize = (int) sl;

    int d = 0;
    for (int i=0; i<(int)sl; i++) {
        if (seq[i] == '(') {
            d ++;
            arr[i] = d & 1;
        } else {
            arr[i] = d & 1;
            d --;
        }
    }

    return arr;
}