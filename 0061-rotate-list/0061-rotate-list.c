/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int size_of(struct ListNode *head) {
    int s = 0;
    while (head) {
        s++;
        head = head -> next;
    }
    return s;
}

struct ListNode *split(struct ListNode *head, int idx) {
    struct ListNode *prev = NULL, *ptr = head;
    while (idx --) {
        prev = ptr;
        ptr = ptr -> next;
    }
    if (prev) prev -> next = NULL;
    return ptr;
}

struct ListNode *concat(struct ListNode *dst, struct ListNode *src) {
    struct ListNode **ptr = &dst;
    while (*ptr) {
        ptr = &((*ptr)->next);
    }
    *ptr = src;
    return dst;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !k) return head;
    int size = size_of(head);
    int idx = k % size;
    if (idx == 0) return head;
    struct ListNode *head2 = split(head, size - idx);
    
    return concat(head2, head);
}