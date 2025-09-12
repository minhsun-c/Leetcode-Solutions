/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    *returnSize = candiesSize;
    bool *ret = (bool *)malloc(sizeof(bool) * candiesSize);
    int max = -1;
    for (int i=0; i<candiesSize; i++) max = (candies[i] > max) ? candies[i] : max;
    for (int i=0; i<candiesSize; i++) ret[i] = (candies[i] + extraCandies >= max);
    return ret;
}