/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int size(struct ListNode *head) {
    int s = 0;
    while (head) {
        s ++;
        head = head -> next;
    }
    return s;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int moves = size(head) - n;
    struct ListNode *l = NULL;
    struct ListNode **ptr = &l;
    while (moves --) {
        *ptr = head;
        head = head -> next;
        (*ptr) -> next = NULL;
        ptr = &((*ptr)->next);
    }
    if (head && head -> next) *ptr = head -> next;
    return l;
}