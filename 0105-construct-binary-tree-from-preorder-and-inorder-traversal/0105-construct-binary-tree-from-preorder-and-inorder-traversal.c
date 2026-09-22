/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *alloc(int n) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = n;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    // hash table
    int in_hash[6001];
    for (int i=0; i<inorderSize; i++) 
        in_hash[inorder[i] + 3000] = i;

    // build tree
    struct TreeNode *root = NULL;
    struct TreeNode **ptr;
    for (int i=0; i<preorderSize; i++) {
        int target = preorder[i];
        struct TreeNode *node = alloc(target);
        ptr = &root;
        while (*ptr) {
            int rst = in_hash[target + 3000] - in_hash[(*ptr)->val + 3000];
            if (rst < 0)  // target < root
                ptr = &((*ptr)->left);
            else 
                ptr = &((*ptr)->right);
        }
        *ptr = node;
    }
    return root;
}