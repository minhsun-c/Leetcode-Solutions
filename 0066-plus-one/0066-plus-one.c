/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int sum = 0, cin = 1;
    for (int i=digitsSize-1; i>=0; i--) {
        sum = digits[i] + cin;
        cin = sum / 10;
        digits[i] = sum % 10;
    }
    *returnSize = digitsSize + (!!cin);
    int *ret = (int *)malloc(sizeof(int) * *returnSize);
    ret[0] = cin;
    memcpy(ret+cin, digits, sizeof(int) * digitsSize);
    return ret;
}