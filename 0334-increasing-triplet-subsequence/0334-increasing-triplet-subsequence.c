bool increasingTriplet(int* nums, int numsSize) {
    int m1 = INT_MAX, m2 = INT_MAX, m3 = INT_MAX;
    for (int i=0; i<numsSize; i++) {
        if (m1 > nums[i]) m1 = nums[i];
        else continue;
        for (int j=i+1; j<numsSize; j++) {
            if (m2 > nums[j] && m1 < nums[j]) m2 = nums[j];
            else continue;
            for (int k=j+1; k<numsSize; k++) {
                if ((m3 == INT_MAX || m3 > nums[k]) && m2 < nums[k]) m3 = nums[k];
                else continue;
                return true;
            }
        }
    }
    return false;
}