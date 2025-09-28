/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode *root, long long sum, int *ans) {
    if (!root) return;
    if (sum == root->val) (*ans) ++;
    dfs(root->left, sum - root->val, ans);
    dfs(root->right, sum - root->val, ans);
}

void wrapper(struct TreeNode* root, long long sum, int *ans) {
    if (!root) return;
    dfs(root, sum, ans);
    wrapper(root->left, sum, ans);
    wrapper(root->right, sum, ans);
}

int pathSum(struct TreeNode* root, int targetSum) {
    int ans = 0;
    wrapper(root, targetSum, &ans);
    
    return ans;
}