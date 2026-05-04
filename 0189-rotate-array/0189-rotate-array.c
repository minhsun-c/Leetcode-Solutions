static inline void swap(int *a, int *b) {
    *a ^= *b; // a = a ^ b
    *b ^= *a; // b = b ^ (a ^ b)
    *a ^= *b; // a = (a ^ b) ^ a
}

void reverse(int *nums, int size) {
    int mid = size / 2;
    for (int i=0; i<mid; i++) 
        swap(&nums[i], &nums[size - 1 - i]);
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    if (!k) return;

    reverse(nums, numsSize);
    reverse(nums, k);
    reverse(nums + k, numsSize - k);
}