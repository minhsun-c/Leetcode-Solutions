typedef struct {
    int *pf;
    int cap;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = (NumArray *)malloc(sizeof(NumArray));
    obj->cap = numsSize;
    obj->pf = (int *)malloc(sizeof(int) * numsSize);
    obj->pf[0] = 0;
    for (int i=0; i<numsSize; i++) obj->pf[0] += nums[i];
    for (int i=1; i<numsSize; i++) obj->pf[i] = obj->pf[i-1] - nums[i-1];
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int r;
    if (right == obj->cap-1) r = 0;
    else r = obj->pf[right+1];
    return obj->pf[left] - r;
}

void numArrayFree(NumArray* obj) {
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/