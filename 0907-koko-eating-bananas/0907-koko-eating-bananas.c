#define MAX(a, b) (a > b ? a : b)
 
int minEatingSpeed(int* piles, int pilesSize, int h) {
    int right = 0, left = 1, mid;
    long long acc;
    for (int i=0; i<pilesSize; i++) right = MAX(right, piles[i]);

    while (left <= right) {
        mid = (left + right) / 2;
        acc = 0;
        for (int i=0; i<pilesSize; i++)
            acc += (piles[i] + mid - 1) / mid;
        if (acc > h) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}