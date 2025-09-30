/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(a, b) (a > b ? a : b)

#define DIR_L 0
#define DIR_R 1

void dfs(struct TreeNode *root, bool dir, int cur, int *best) {
    if (!root) return;

    *best = MAX(*best, cur);
    if (dir == DIR_L) {
        dfs(root->left, DIR_R, cur + 1, best);
        dfs(root->right, DIR_L, 1, best);
    } else {
        dfs(root->left, DIR_R, 1, best);
        dfs(root->right, DIR_L, cur + 1, best);
    }
}

int longestZigZag(struct TreeNode* root) {
    int best = 0;
    dfs(root, DIR_L, 0, &best);
    dfs(root, DIR_R, 0, &best);
    return best;
}