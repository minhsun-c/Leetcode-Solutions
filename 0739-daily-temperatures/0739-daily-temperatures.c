/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *arr = (int *)malloc(sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize;

    int stack[100005];
    int top = -1;

    for (int i=0; i<temperaturesSize; i++) {
        arr[i] = 0;
        while (top >= 0 && temperatures[stack[top]] < temperatures[i]) {
            arr[stack[top]] = i - stack[top];
            top --;
        }
        stack[++ top] = i;
    }
    arr[temperaturesSize - 1] = 0;

    return arr;
}