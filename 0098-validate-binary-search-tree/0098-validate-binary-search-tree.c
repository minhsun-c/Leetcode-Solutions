/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool rec(struct TreeNode *root, long long min, long long max) {
    if (!root) return true;
    if (root -> val <= min || root -> val >= max) {
        return false;
    }
    return rec(root -> left, min, root -> val) && rec(root ->right, root->val, max);
}

bool isValidBST(struct TreeNode* root) {
    return rec(root->left, LLONG_MIN, root->val) && rec(root->right, root->val, LLONG_MAX);
}