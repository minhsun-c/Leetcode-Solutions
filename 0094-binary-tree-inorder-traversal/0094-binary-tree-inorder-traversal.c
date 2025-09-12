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

void rec(struct TreeNode *root, int *arr, int *idx) {
    if (!root) return;
    rec(root -> left, arr, idx);
    arr[*idx] = root -> val;
    (*idx) ++;
    rec(root -> right, arr, idx);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    rec(root, ret, returnSize);
    return ret;
}