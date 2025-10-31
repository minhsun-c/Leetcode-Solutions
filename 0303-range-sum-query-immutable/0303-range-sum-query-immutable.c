typedef struct {
    int *arr;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = (NumArray *)malloc(sizeof(NumArray));
    obj->arr = nums;
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int cnt = 0;
    for (int i=left; i<=right; i++) cnt += obj->arr[i];
    return cnt;
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