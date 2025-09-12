/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (!root) return false;
    int rem = targetSum - root->val;
    if (!root->left && !root->right && !rem) return true;
    return hasPathSum(root->left, rem) || hasPathSum(root->right, rem);
}