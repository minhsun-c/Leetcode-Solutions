/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
static inline int min(int a, int b) {
    return a < b ? a : b; 
}

int minDepth(struct TreeNode* root) {
    if (!root) 
        return 0;
    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    if (lh == 0 && rh == 0)
        return 1;
    if (lh == 0) 
        return rh + 1;
    if (rh == 0)
        return lh + 1;
    return min(lh, rh) + 1;
}