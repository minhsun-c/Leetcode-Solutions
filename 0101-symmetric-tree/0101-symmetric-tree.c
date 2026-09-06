/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isMirror(struct TreeNode *a, struct TreeNode *b) {
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;
    return (a->val == b->val) && isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (!root)
        return true;
    return isMirror(root->left, root->right);
}