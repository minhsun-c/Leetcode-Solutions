/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void inorder(struct TreeNode *root, int *arr, int *size, int *max, int *prev, int *count) {
    if (!root) return;
    inorder(root->left, arr, size, max, prev, count);
    int cur = root->val;
    if (*prev == cur) {
        (*count) ++;
    } else {
        (*count) = 1;
        *prev = cur;
    }

    if ((*count) == *max) {
        arr[*size] = cur;
        (*size) ++;
    } else if ((*count) > *max) {
        *max = (*count);
        arr[0] = cur;
        (*size) = 1;
    }
    inorder(root->right, arr, size, max, prev, count);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    int *arr = (int *) malloc(sizeof(int) * 1e4);
    *returnSize = 0;
    int max = 0;
    int count = 0;
    int prev = INT_MIN;
    inorder(root, arr, returnSize, &max, &prev, &count);
    return arr;
}