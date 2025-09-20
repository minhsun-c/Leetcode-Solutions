#define SWAP(a, b) {a = a ^ b; b = a ^ b; a = a ^ b;}
void sortColors(int* nums, int numsSize) {
    int a[3] = {0, 0, 0};
    for (int i=0; i<numsSize; i++) a[nums[i]] ++;
    for (int i=0; i<numsSize; i++) {
        if (a[0]) {nums[i] = 0; a[0] --;}
        else if (a[1]) {nums[i] = 1; a[1] --;}
        else if (a[2]) {nums[i] = 2; a[2] --;}
    }
}