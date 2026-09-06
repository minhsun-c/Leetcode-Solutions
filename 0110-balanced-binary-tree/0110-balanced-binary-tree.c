/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
static inline int max(int a, int b) {
    return a > b ? a : b;
}

static inline int diff(int a, int b) {
    if (a > b) return a - b;
    return b - a;
}

bool __helper(struct TreeNode *a, int *h) {
    if (!a) {
        *h = 0;
        return true;
    }
    int lh, rh;
    if (__helper(a->left, &lh) == false) return false;
    if (__helper(a->right, &rh) == false) return false;
    if (diff(lh, rh) <= 1) {
        *h = max(lh, rh) + 1;
        return true;
    }
    return false;
}

bool isBalanced(struct TreeNode* root) {
    int h;
    return __helper(root, &h);
}