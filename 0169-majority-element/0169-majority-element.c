int majorityElement(int* nums, int numsSize) {
    int maj, cnt = 0;
    // if cnt == 0, maj = nums[i]

    for (int i=0; i<numsSize; i++) {
        if (cnt == 0) {
            maj = nums[i];
            cnt ++;
        } else if (nums[i] != maj) cnt --;
        else cnt ++;
    }
    return maj;
}