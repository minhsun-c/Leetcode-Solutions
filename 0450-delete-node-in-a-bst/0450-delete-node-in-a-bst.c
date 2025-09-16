/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *leftmost(struct TreeNode *root) {
    struct TreeNode *cur = root;
    while (cur && cur -> left) {
        cur = cur -> left;
    }
    return cur;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (!root) return root;
    if (root->val == key) {
        if (!root->left) return root->right;
        else if (!root->right) return root->left;
        struct TreeNode *leftm = leftmost(root->right);
        root->right = deleteNode(root->right, leftm->val);
        leftm->left = root->left;
        leftm->right = root->right;
        return leftm;
    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    } else {
        root->left = deleteNode(root->left, key);
    }
    return root;
}