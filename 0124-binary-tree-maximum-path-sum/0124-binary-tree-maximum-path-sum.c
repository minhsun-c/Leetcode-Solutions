/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static inline int max(const int a, const int b) {
    return a > b ? a : b;
} 

int helper(struct TreeNode *root, int *best) {
    if (!root)
        return 0;
    int l = helper(root->left, best);
    if (l < 0) l = 0;
    int r = helper(root->right, best);
    if (r < 0) r = 0;
    int through = l + r + root->val;
    if (through > *best)
        *best = through;
    return root->val + max(l, r);
}

int maxPathSum(struct TreeNode* root) {
    int best = INT_MIN;
    helper(root, &best);
    return best;
}