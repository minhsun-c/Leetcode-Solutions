/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define ARRSIZE 50

struct TreeNode *q[ARRSIZE];
int front, end, size;

void init() {
    front = 0; end = 0; size = 0;
}

void push(struct TreeNode *node) {
    q[front] = node;
    front = (front + 1) % ARRSIZE;
    size ++;
}

struct TreeNode *top() {
    return q[end];
}

void pop() {
    end = (end + 1) % ARRSIZE;
    size --;
}

int level_order(int *arr, struct TreeNode *root) {
    int level = 0;
    int num;
    init();
    if (root) push(root);
    while (size) {
        num = size;
        for (int i=0; i<num; i++) {
            struct TreeNode *node = top();
            pop();
            if (i == num - 1) arr[level ++] = node -> val;
            if (node -> left) push(node -> left);
            if (node -> right) push(node -> right);
        }
    }
    return level;
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int *arr = (int *)malloc(sizeof(int) * 100);
    *returnSize = level_order(arr, root);
    return arr;
}