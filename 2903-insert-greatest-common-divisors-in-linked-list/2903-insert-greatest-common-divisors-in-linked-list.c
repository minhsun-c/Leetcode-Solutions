/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct ListNode *create_node(int a, int b) {
    int _gcd = gcd(a, b);
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node -> val = _gcd;
    node -> next = NULL;
    return node; 
} 

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    struct ListNode *ptr = head; 
    int prev = head->val, next;
    while (ptr->next) {
        next = ptr->next->val;
        struct ListNode *node = create_node(prev, next);
        node->next = ptr->next;
        ptr->next = node;
        prev = next;
        ptr = ptr->next->next;
    }
    return head;
}