#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int max = 0, cur;
    while (left < right) {
        cur = (right - left) * MIN(height[right], height[left]);
        max = MAX(max, cur);
        if (height[left] > height[right]) right --;
        else left ++;
    }
    return max;
}