#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestOnes(int* nums, int numsSize, int k) {
    int front = 0, end = -1, tmp = k;
    int max = 0;
    for (int i=0; i<numsSize; i++) {
        if (nums[i] == 0 && !tmp) break;
        else if (nums[i] == 0) tmp --;
        end ++;
    }
    max = MAX(max, end - front + 1);
    for (int i=end+1; i<numsSize; i++) {
        if (nums[i] == 0) {
            while (front < numsSize){
                if (!nums[front]) {
                    front ++; break;
                }
                front ++;
            }
        }
        end ++;
        max = MAX(max, end - front + 1);
    }
    return max;
}