#define MAX(a, b) (a > b ? a : b)
int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    if (!root -> left && !root -> right) return 1;
    int l = maxDepth(root -> left);
    int r = maxDepth(root -> right);
    return MAX(l, r) + 1;
}