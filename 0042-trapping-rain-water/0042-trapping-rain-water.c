static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

static inline int min(int a, int b) {
    return (a < b) ? a : b;
}

int lmax[100000];
int rmax[100000];


int trap(int* height, int heightSize) {
    lmax[0] = height[0];
    for (int i=1; i<heightSize; i++) lmax[i] = max(lmax[i-1], height[i-1]);

    rmax[heightSize - 1] = height[heightSize - 1];
    for (int i=heightSize-2; i>=0; i--) rmax[i] = max(rmax[i+1], height[i+1]);

    int cnt = 0;
    for (int i=0; i<heightSize; i++) {
        int mini = min(lmax[i], rmax[i]);
        if (height[i] < mini) cnt += mini - height[i];
    }

    return cnt;
}