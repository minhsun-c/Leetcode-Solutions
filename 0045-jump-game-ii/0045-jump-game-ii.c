int jump(int* nums, int numsSize) {
    int cur_end = 0;
    int farthest = 0;
    int jump = 0;
    for (int i=0; i<numsSize-1; i++) {
        if (i + nums[i] > farthest)
            farthest = i + nums[i];

        if (i == cur_end){
            jump ++; 
            cur_end = farthest;
        }
    }
    return jump;
}