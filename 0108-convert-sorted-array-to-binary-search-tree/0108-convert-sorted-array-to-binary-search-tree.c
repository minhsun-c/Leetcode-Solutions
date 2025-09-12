/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *newNode(int num) {
    struct TreeNode *node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    node -> val = num;
    node -> left = node -> right = NULL;
    return node;
}

struct TreeNode *addNode(struct TreeNode *root, int num) {
    struct TreeNode *node = newNode(num);
    struct TreeNode **ptr = &root;
    while (*ptr) {
        if ((*ptr) -> val < num) 
            ptr = &((*ptr)->right);
        else
            ptr = &((*ptr)->left);
    }
    *ptr = node;
    return root;
}

struct TreeNode *toBst(struct TreeNode *root, int *nums, int left, int right) {
    if (left > right) return root;
    if (left == right) return addNode(root, nums[left]);
    int mid = (left + right) / 2;
    root = addNode(root, nums[mid]);
    root = toBst(root, nums, left, mid - 1);
    root = toBst(root, nums, mid + 1, right);
    return root;
} 

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode *root = NULL;
    return toBst(root, nums, 0, numsSize - 1);
}