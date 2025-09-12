#define ARRSIZE 4096

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

int maxLevelSum(struct TreeNode* root) {
    int max = INT_MIN; 
    int max_level = 0;
    int level = 0;
    int sum = 0; 
    int num = 0; 
    init();
    push(root);
    while (size) {
        level ++;
        num = size;
        for (int i=0; i<num; i++) {
            struct TreeNode *node = top();
            pop();
            sum += node -> val;
            if (node->left) push(node->left);
            if (node->right) push(node->right);
        }
        if (sum > max) { max = sum; max_level = level; }
        sum = 0;
    }
    return max_level;

}