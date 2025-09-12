/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(a, b) (a > b ? a : b)

int rec(struct TreeNode *root, int max) {
    if (!root) return 0;
    int cnt = 0;
    if (root -> val >= max) cnt ++;
    max = MAX(max, root -> val);
    cnt += rec(root -> left, max);
    cnt += rec(root -> right, max);
    return cnt;
}

int goodNodes(struct TreeNode* root){
    return rec(root, INT_MIN);
}