/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct ctx {
    int *preorder;
    int pid; // preorder index
    int in_hash[6001];
};

struct TreeNode *alloc(int n) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = n;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode *build(struct ctx *ctx, int lo, int hi) {
    if (lo > hi) return NULL;

    int val = ctx->preorder[ctx->pid];
    ctx->pid ++;
    int idx = ctx->in_hash[val + 3000];
    struct TreeNode *root = alloc(val);

    root->left = build(ctx, lo, idx-1);
    root->right = build(ctx, idx+1, hi);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    // build struct ctx
    struct ctx ctx;
    ctx.preorder = preorder;
    ctx.pid = 0;
    for (int i=0; i<inorderSize; i++) ctx.in_hash[inorder[i] + 3000] = i;

    return build(&ctx, 0, inorderSize-1);
}