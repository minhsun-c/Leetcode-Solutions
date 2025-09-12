/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *preorder(struct TreeNode *root) {
    if (!root) return NULL;

    struct TreeNode *ptr = root;
    struct TreeNode *left = root -> left;
    struct TreeNode *right = root -> right;
    root -> left = root -> right = NULL;
    if (left) root -> right = preorder(left);
    while (ptr -> right) ptr = ptr -> right;
    ptr -> right = preorder(right);
    return root;
}

void flatten(struct TreeNode* root) {
    root = preorder(root);
}