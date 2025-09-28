/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int *stack = (int *)malloc(sizeof(int) * asteroidsSize);
    int top = -1;
    int bot = -1;
    for (int i=0; i<asteroidsSize; i++) {
        if (asteroids[i] & 0x8000000) {
            int kill = 0;
            while (top > bot && stack[top] > 0) {
                if (-asteroids[i] > stack[top]) {
                    top --;
                } else if (-asteroids[i] == stack[top]) {
                    top --;
                    kill = 1;
                    break;
                } else {
                    kill = 1;
                    break;
                }
            }
            if (!kill) stack[++ top] = asteroids[i];
        } else stack[++ top] = asteroids[i];
    }
    *returnSize = top + 1;
    return stack;
}