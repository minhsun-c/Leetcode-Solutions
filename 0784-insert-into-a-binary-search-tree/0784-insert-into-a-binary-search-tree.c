/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    struct TreeNode **p = &root;
    while (*p) {
        if ((*p)->val > val) p = &((*p)->left);
        else if ((*p)->val < val) p = &((*p)->right);
    }
    *p = node;
    return root;
}