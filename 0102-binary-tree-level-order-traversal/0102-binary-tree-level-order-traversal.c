/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct TreeNode *queue[2005];
int head, tail, size;

void insert(struct TreeNode *node) {
    queue[tail] = node;
    tail ++;
    size ++;
}

struct TreeNode *pop() {
    struct TreeNode *cur = queue[head];
    head ++;
    size --;
    return cur;
}

int *sublist(int start, int end) {
    int *arr = malloc(sizeof(int) * (end - start));
    for (int i=start; i<end; i++) 
        arr[i - start] = queue[i] -> val;
    return arr;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int **arr = malloc(sizeof(int *) * 2000);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    head = tail = size = 0;
    
    if (root)
        insert(root);

    while (size) {
        int count = size;
        (*returnColumnSizes)[*returnSize] = size;
        arr[*returnSize] = sublist(head, tail);
        (*returnSize) ++;
        for (int i=0; i<count; i++) {
            struct TreeNode *cur = pop();
            if (cur->left)  insert(cur->left);
            if (cur->right) insert(cur->right);
        }
    }
    return arr;
}