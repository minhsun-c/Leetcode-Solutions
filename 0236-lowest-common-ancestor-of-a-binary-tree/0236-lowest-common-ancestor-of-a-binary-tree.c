/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool find(struct TreeNode* root, struct TreeNode* p) {
    if (!root) return false;
    if (root -> val == p -> val) return true;
    return find(root -> left, p) || find(root -> right, p);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root -> val == p-> val || root -> val == q -> val)
        return root;
    int left = find(root -> left, p) || find(root -> left, q);
    int right = find(root -> right, p) || find(root -> right, q);
    if (left && right) return root;
    else if (left) return lowestCommonAncestor(root -> left, p, q);
    else return lowestCommonAncestor(root -> right, p, q);
}